#include <bits/stdc++.h>
#include <random>
#include <Windows.h>
std::vector<std::string> args;
const std::string ErrorMessage[] = {"",
	"Error: Invalid argument.",
	"Error: Invalid option.",
	"Error: Unexpected End",
	"Error: Missing value for argument.",
};
enum ErrorMessageType {
	IVL_ARG,
	IVL_OPT,
	IVL_END,
	IVL_MISVAL
};
const char PassList[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_!@-|";
/*
 * 0 Black   * 8 Grey
 * 1 Blue    * 9 Light Blue
 * 2 Green   * A Light Green
 * 3 Aqua    * B Light Aqua
 * 4 Red     * C Light Red
 * 5 Purple  * D Light Purple
 * 6 Yellow  * E Light Yellow
 * 7 White   * F Light White
 */
enum COLORS {
	cBlack, cBlue, cGreen, cAqua, cRed, cPurple, cYellow, cWhite,
	cGrey, cLightBlue, cLightGreen, cLightAqua, cLightRed, cLightPurple, cLightYellow, cLightWhite
};
void SetColorAndBackground(COLORS ForgC, COLORS BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
using std::cout;
inline void help() {
	puts(
R"(Options:
	-l [length], --len=[length]    ==> Generate a password which length is [length].
	-m [xyz]                       ==> Follow the rule [xyz] to generate password.
	--spec, --use-spec              ==> Use Special Characters.
	--big, --use-big                ==> Use Upper Case Alphabets.
	--num, --use-num                ==> Use numbers.
	--help                         ==> Print this manual.
Constraints:
	[xyz] is an OCT number from 0 to 7, that represents the BIN number.
	x -> Include Special Characters.
	y -> Include Numbers.
	z -> Include Upper Case Alphabets.
	By default, [xyz] is set to 000.
Examples:
	"genpass -l 10 -m 7" generates a password long 10c with #@.?ABCD(etc.).
	"genpass --len=10 -big -spec" is same as the first example.
)");
}
inline void err(int arg, int pos, int typo) {
	help();
	size_t len = args[arg - 1].length() + 1 + pos;
	if (arg > 1) cout << "... ", len += 4;
	cout << args[arg - 1] << ' ';
	SetColorAndBackground(cLightRed, cBlack);
	cout << args[arg];
	SetColorAndBackground(cWhite, cBlack);
	if (arg + 1 < args.size()) {
		cout << ' ' << args[arg + 1];
		if (arg + 2 < args.size())
			cout << " ...";
	}
	cout << std::endl;
	for (size_t i = 0; i < len; i++)
		putchar(' ');
	SetColorAndBackground(cLightYellow, cBlack);
	cout << "^" << std::endl;
	SetColorAndBackground(cAqua, cBlack);	
	cout << ErrorMessage[typo] << std::endl;
	SetColorAndBackground(cWhite, cBlack);
	system("pause");
}
BOOL CopyToClipboard(const char* pszData, const int nDataLen)
{
    if(::OpenClipboard(NULL))
    {
        ::EmptyClipboard();
        HGLOBAL clipbuffer;
        char *buffer;
        clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen+1);
        buffer = (char *)::GlobalLock(clipbuffer);
        strcpy(buffer, pszData);
        ::GlobalUnlock(clipbuffer);
        ::SetClipboardData(CF_TEXT, clipbuffer);
        ::CloseClipboard();
        return TRUE;
    }
    return FALSE;
}
size_t xorshift(size_t x){
	x ^= x << 5;
	x ^= x >> 11;
	x ^= x << 54;
	return x;
}
size_t xorshift2(size_t x, size_t y){
	x = xorshift(x), y = xorshift(y);
	x ^= y << 13;
	y ^= x >> 7;
	x ^= y >> 5;
	y ^= x << 31;
	return x ^ y;
}
int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++)
		if (argv[i][0])
			args.push_back(argv[i]);
	argc = args.size();
	std::hash<std::string> hashString;
	size_t passLen = 8ull;
	int passMode = 0;	// (have spec chars?)(have numbers?)(have big alphas?)
	size_t passHash = time(0);
	for (int i = 1; i < argc; i++) {
		std::string cur = args[i];
		if (cur[0] == '-') {
			if (cur.length() == 1) {
				err(i, 0, IVL_END);
				return 2;
			}
			if (cur[1] != '-') {
				if (cur.length() > 2) {
					err(i, 0, IVL_OPT);
					return 2;
				}
				if (i + 1 == argc) {
					err(i, 2, IVL_MISVAL);
					return 3;
				}
				char op = cur[1];
				int mode;
				switch (op) {
				case 'l':
					cur = args[++i];
					if (cur.length() > 2) {
						err(i, 0, IVL_OPT);
						return 1;
					}
					for (char c : cur)
						if (!isdigit(c)) {
							err(i, 0, IVL_ARG);
							return 1;
						}
					passLen = atoi(cur.c_str());
					break;
				case 'm':
					cur = args[++i];
					if (cur.length() != 1 || !isdigit(cur[0])) {
						err(i, 0, IVL_ARG);
						return 1;
					}
					mode = atoi(cur.c_str());
					if (!(0 <= mode && mode < 8)) {
						err(i, 0, IVL_ARG);
						return 1;
					}
					passMode = mode;
					break;
				default:
					err(i, 0, IVL_ARG);
					return 2;
				}
			}
			else  {
				if (cur.starts_with("--len=") || cur.starts_with("--length=")) {
					int pos;
					std::string num;
					if (cur.starts_with("--len="))
						num = cur.substr(6, cur.length()), pos = 6;
					else num = cur.substr(9, cur.length()), pos = 9;
					for (char c : num)
						if (!isdigit(c)) {
							err(i, pos, IVL_ARG);
							return 1;
						}
					passLen = atoi(num.c_str());
				}
				else if (cur == "--use-spec" || cur == "--use-special-characters" || cur == "--spec") {
					passMode |= 4;
				}
				else if (cur == "--use-big" || cur == "--use-big-alphabets" || cur == "--big") {
					passMode |= 1;
				}
				else if (cur == "--use-num" || cur == "--use-numbers" || cur == "--num") {
					passMode |= 2;
				}
				else if (cur == "--help") {
					help();
					system("pause");
					return 0;
				}
				else {
					err(i, 0, IVL_OPT);
					return 2;
				}
			}
		}
		else passHash = xorshift2(passHash, hashString(cur));
	}
	std::mt19937_64 rng(passHash);
	std::string pass;
	auto check = [&] (int pos) -> bool {
		if (pos < 26) return true;
		if (passMode & 1) { // Big
			if (pos < 52) return true;
		}
		if (passMode & 2) { // Num
			if (52 <= pos && pos < 62) return true;
		}
		if (passMode & 4) { // Spec
			if (62 <= pos) return true;
		}
		return false;
	};
	for (int i = 0; i < passLen; i++) {
		int pos = 0;
		do pos = rng() % 67;
		while (!check(pos));
		pass.push_back(PassList[pos]);
	}
	cout << pass << std::endl;
	if (CopyToClipboard(pass.c_str(), pass.length())) {
		cout << "Success: Copied password to ClipBoard." << std::endl;
		Sleep(300);
	}
	else {
		cout << "Failed: Unable to copy password to ClipBoard." << std::endl
			 << "Please copy it yourself." << std::endl;
		system("pause");
	}
	return 0;
}
