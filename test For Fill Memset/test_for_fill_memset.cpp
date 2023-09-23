#include <stdio.h>
#include <stdlib.h>  // for rand()
#include <string.h>  // for memset()
#include <algorithm> // for std::fill()
#include <chrono>
#include <thread>
#pragma GCC optimize(2)
/// @brief Get current local time stamp
/// @return Time stamp
int64_t getCurrentLocalTimeStamp()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
int main()
{
    srand((unsigned)time(NULL));
    int *a;
    unsigned cases, range, range_base;
    int64_t start, end;
    printf("Please input testcases: ");
    scanf("%u", &cases);
    printf("Please input array size(<2^31): ");
    scanf("%u", &range_base);
    if (range_base >= (1u << 31))
    {
        puts("Error while checking array size, exiting...");
        std::this_thread::sleep_for(std::chrono::seconds(1000));
        return 0;
    }
    printf("We will alloc new array 3 times in each cases, and each of their sizes is [%u, %u).\n", range_base, range_base << 1);
    puts("Now wait and see the result in csv file after the program ended.");
    FILE *csv = fopen("Test for 'For Fill Memset Time' result.csv", "w");
    fputs("Testcase No.,Size,For,Memset,Fill\n", csv);
    unsigned long long forSum = 0, memsetSum = 0, fillSum = 0;
    for (register unsigned i = 1; i <= cases; i++)
    {
        // printf("Testcase %d) ", i);
        fprintf(csv, "%d,", i);
        range = (int)range_base + rand() * rand() % range_base;
        fprintf(csv, "%d,", range);
        // for
        a = new int[range];
        start = getCurrentLocalTimeStamp();
        for (register unsigned j = 0; j < range; j++)
            a[j] = 0;
        end = getCurrentLocalTimeStamp();
        forSum += end - start + 1;
        // printf("for:%ldms ", end - start + 1);
        fprintf(csv, "%ldms,", end - start + 1);
        delete[] a;
        // memset
        a = new int[range];
        start = getCurrentLocalTimeStamp();
        memset(a, 0, sizeof(int) * range);
        end = getCurrentLocalTimeStamp();
        memsetSum += end - start + 1;
        // printf("memset:%ldms ", end - start + 1);
        fprintf(csv, "%ldms,", end - start + 1);
        delete[] a;
        // std::fill
        a = new int[range];
        start = getCurrentLocalTimeStamp();
        std::fill(a, a + range, 0);
        end = getCurrentLocalTimeStamp();
        fillSum += end - start + 1;
        // printf("fill:%ldms\n", end - start + 1);
        fprintf(csv, "%ldms\n", end - start + 1);
        delete[] a;
        if (i % 100 == 0 || i == cases)
            printf("Testcases No.%d Finished\n", i);
    }
    double forAvg = forSum * 1. / cases, memsetAvg = memsetSum * 1. / cases, fillAvg = fillSum * 1. / cases;
    // printf("for avg: %lgms\nmemset avg: %lgms\nfill avg: %lgms\n", forAvg, memsetAvg, fillAvg);
    fprintf(csv, "Avg,,%lgms,%lgms,%lgms", forAvg, memsetAvg, fillAvg);
    fclose(csv);
    puts("Done.");
    return 0;
}