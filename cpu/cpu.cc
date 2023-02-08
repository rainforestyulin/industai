#include <time.h>
#include <iostream>
#include <climits>
#include <math.h>

#define FLOAT_MOD 100000.0

void IntAdder(int *a,int *b)
{
    *a = (*a + *b) % INT32_MAX;
};

void FloatAdder(float *a,float *b)
{
    *a = fmod(*a + *b,FLOAT_MOD);
};

int main()
{
    uint32_t RUN_TIMES;
    std::cin>>RUN_TIMES;
    clock_t first_start = clock();
    for (int i = 0; i < RUN_TIMES; i++)
    {
        /* code */
        int a = 0;
        int b = 1;
        IntAdder(&a,&b);
    }
    clock_t first_end = clock();
    std::cout<<"int run time is:"<<(first_end - first_start)/CLOCKS_PER_SEC<<" s"<<std::endl;
    for (int i = 0; i < RUN_TIMES; i++)
    {
        /* code */
        float a = 1.123456;
        float b = 1.123456;
        FloatAdder(&a,&b);
    }
    clock_t second_end = clock();
    std::cout<<"float run time is:"<<(second_end - first_start)/CLOCKS_PER_SEC<<" s"<<std::endl;
    getchar();
    return 0;
        
}