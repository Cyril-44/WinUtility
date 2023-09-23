#include <stdio.h>
wchar_t buf[1 << 16];
int main()
{
	FILE *f = fopen("marked.txt", "w");
	while (_getws(buf))
		fwprintf(f, L"\"%s\",\n", buf);
	fclose(f);
	return 0;
}