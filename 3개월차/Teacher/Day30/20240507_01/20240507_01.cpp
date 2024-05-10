#include <iostream>
using namespace std;
int main()
{
    clock_t start1 = clock();   // 현재시간을 정밀하게 재줍니다.
    for (int i = 0; i < 1'000'000; i++)
    {
        float x = 1.1f;
        float y = 1.2f;
        float distance = static_cast<float>(::sqrt(x * x + y * y));
    }
    clock_t end1 = clock();
    double time1 = double(end1 - start1) / CLOCKS_PER_SEC; // 초단위로 변환
    printf("경과 시간 : %0.3lf\n", time1);


    clock_t start2 = clock();   // 현재시간을 정밀하게 재줍니다.
    for (int i = 0; i < 1'000'000; i++)
    {
        float x = 1.1f;
        float y = 1.2f;
        float distance_sq = x * x + y * y;
    }
    clock_t end2 = clock();
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC; // 초단위로 변환
    printf("경과 시간 : %0.3lf\n", time2);
}
