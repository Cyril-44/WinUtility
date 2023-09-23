#include <iostream>
#include <stdlib.h>
#define _ENABLE_OVERFLOW
#include "bignum.h"
int main()
{
	// Testing Input and Output
	bigNum n1;
	n1 = 3902193;
	printf("3902193=%s\n", n1.opStr());

	printf("Input a number: ");
	// n1.input();
	std::cin >> n1;
	printf("Your num is: %s\n", n1.opStr());
	bigNum n2;
	printf("Input a number: ");
	// n2.input();
	std::cin >> n2;
	printf("Your num is: %s\n", n2.opStr());

	// Testing compare
	printf("%s=%s?:%s\n", n1.opStr(), n2.opStr(), n1 == n2 ? "true" : "false");
	printf("%s<%s?:%s\n", n1.opStr(), n2.opStr(), n1 < n2 ? "true" : "false");
	printf("%s>%s?:%s\n", n1.opStr(), n2.opStr(), n1 > n2 ? "true" : "false");

	// Testing calculation

	// "+""+="(add) operation (ok)
	bigNum n3 = n1 + n2;
	printf("%s+%s=%s\n", n1.opStr(), n2.opStr(), n3.opStr());
	n3 += n1, n3 += n2;
	printf("(%s+%s)*2=%s\n", n1.opStr(), n2.opStr(), n3.opStr());

	// "-""-="(sub) operation (yes)
	bigNum n4 = n1 - n2;
	printf("%s-%s=%s\n", n1.opStr(), n2.opStr(), n4.opStr());
	n4 -= n2;
	printf("%s\n", n4.opStr());

	// "*""*="(mul) operation (no)
	bigNum n5 = n1 * n2;
	printf("%s*%s=%s\n", n1.opStr(), n2.opStr(), n5.opStr());
	n5 *= n1, n5 *= n2;
	printf("(%s*%s)^2=%s\n", n1.opStr(), n2.opStr(), n5.opStr());
	// n5.print("\n");
	// end
	system("pause");
	return 0;
}