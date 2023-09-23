#include "randext.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    cout << randS("FHSJKDS|FLJKDSJFLKJSD") << endl;
    cout << randS("[0213]{1,20}") << endl;
    while (1)
    {
        cout << randI() << ' ' << randU() << ' ' << randL(1, 1e6) << ' ' << randF(0, 10) << ' ' << randS("[SB]{1,20}|FUCK") << endl;
        for (int i = 0; i < 1e8; i++)
            ;
    }
    return 0;
}