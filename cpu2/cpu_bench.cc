#include "cpu_bench.h"

#include <iostream>
#include <sys/time.h>

void runner(int num)
{
    int current_num = 0;
    unsigned long val = 2;
    while(current_num != num)
    {
        long i = 2;
        for (; i < val; ++i)
        {
            if( val%i==0 )
            {
                break;
            }
        }
        if(i == val)
        {
            ++current_num;
        }
        val++;
    }
}

int main(int argc,char **argv)
{
    long numb = strtol(*(argv+1), (char**)NULL, 10);
    struct timeval starttime, endtime;
    gettimeofday(&starttime, 0);
    runner(numb);
    gettimeofday(&endtime, 0);
    double te=((double)(endtime.tv_sec*1000000-starttime.tv_sec*1000000+endtime.tv_usec-starttime.tv_usec))/1000000;
    printf("Runtime: %.5f\t", te);
    printf("Primenumber: %ld\t",numb);
    printf("Calculatespeed: %.5f Prime/s\n",numb/te);
    return 0;
}
