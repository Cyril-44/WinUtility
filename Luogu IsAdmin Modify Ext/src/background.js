// background.js - Modified with more logging for debugging

chrome.webRequest.onBeforeRequest.addListener(
    function(details) {
        console.log("[Extension Debug] onBeforeRequest triggered for URL:", details.url);

        const userPagePattern = /^https:\/\/(www\.)?luogu\.com\.cn\/user\/\d+$/;
        if (userPagePattern.test(details.url)) {
            console.log("[Extension Debug] Matched user page pattern for URL:", details.url);

            return new Promise((resolve, reject) => {
                console.log("[Extension Debug] Starting fetch for original content...");
                fetch(details.url, {
                    method: details.method,
                    headers: details.requestHeaders.reduce((acc, header) => {
                        acc[header.name] = header.value;
                        return acc;
                    }, {}),
                    // 如果原始请求有 body，需要转发 (例如 POST 请求)
                    // body: details.requestBody ? details.requestBody.raw : undefined
                })
                .then(response => {
                    console.log("[Extension Debug] Fetch response received, status:", response.status);
                    return response.text();
                })
                .then(htmlText => {
                    console.log("[Extension Debug] Original HTML text received (length):", htmlText.length);

                    // 查找并修改 <script id="lentille-context"> 标签内的 JSON
                    const scriptTagRegex = /(<script id="lentille-context" type="application\/json">)([\s\S]*?)(<\/script>)/;
                    const match = htmlText.match(scriptTagRegex);

                    if (match) {
                        console.log("[Extension Debug] Found #lentille-context script tag.");
                        const fullScriptTag = match[0];
                        const openingTag = match[1];
                        const closingTag = match[3];
                        let jsonString = match[2];

                        try {
                            // 解析原始 JSON
                            let jsonObj = JSON.parse(jsonString);
                            console.log("[Extension Debug] Original JSON parsed successfully.");

                            // 修改 data.user.isAdmin 为 true
                            // 确保路径存在
                            if (jsonObj && jsonObj.data && jsonObj.data.user && jsonObj.data.user.hasOwnProperty('isAdmin')) {
                                console.log(`[Extension Debug] Original isAdmin value: ${jsonObj.data.user.isAdmin}`);
                                jsonObj.data.user.isAdmin = true;
                                console.log(`[Extension Debug] Modified isAdmin value: ${jsonObj.data.user.isAdmin}`);

                                // 序列化回 JSON 字符串
                                jsonString = JSON.stringify(jsonObj, null, 0);

                                // 构建修改后的 script 标签
                                const modifiedScriptTag = openingTag + jsonString + closingTag;

                                // 将修改应用到 HTML
                                const modifiedHtml = htmlText.replace(fullScriptTag, modifiedScriptTag);

                                console.log("[Extension Debug] HTML modified successfully, creating Blob URL.");
                                // 在 Manifest V2 中，创建 Blob URL 并返回 redirectUrl
                                const blobUrl = URL.createObjectURL(new Blob([modifiedHtml], { type: 'text/html' }));
                                console.log("[Extension Debug] Blob URL created:", blobUrl);
                                resolve({
                                    redirectUrl: blobUrl
                                });
                            } else {
                                console.warn("[Extension Debug] isAdmin field not found in the JSON data structure.");
                                resolve({}); // 不修改，继续原始请求
                            }
                        } catch (e) {
                            console.error("[Extension Debug] Error parsing or modifying JSON in script tag:", e);
                            console.error("[Extension Debug] Problematic JSON string snippet:", jsonString.substring(0, 200) + "..."); // 打印前200字符
                            resolve({}); // 出错时发送原始内容
                        }
                    } else {
                        console.warn("[Extension Debug] Script tag #lentille-context not found in the fetched HTML.");
                        resolve({}); // 没找到标签，发送原始内容
                    }
                })
                .catch(error => {
                    console.error("[Extension Debug] Error fetching original HTML:", error);
                    console.error("[Extension Debug] Error details:", error.message, error.stack);
                    resolve({}); // 出错时发送原始内容
                });
            });
        } else {
             console.log("[Extension Debug] URL does not match user page pattern, skipping:", details.url);
             return {};
        }
    },
    // 请求过滤器：指定要拦截的 URL
    {
        urls: ["https://www.luogu.com.cn/user/*", "https://luogu.com.cn/user/*"],
        types: ["main_frame"] // 拦截主页面加载请求
    },
    ["blocking"] // 重要：使请求阻断，以便可以修改响应
);
