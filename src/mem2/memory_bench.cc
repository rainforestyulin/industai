#include "simple_vector.cc"

#include <memory>
#include <string>
#include "../platform.h"
#include <unistd.h>

namespace memory_bench{
void print_result(double te, size_t mem_size)
{
    printf("Time_cost: %.5fs\t",te);
    printf("Memory_size: %.5fMiB\t",static_cast<double>(mem_size/1024/1024));
    printf("WR_speed: %.3f MiB/s\n" , mem_size/1024/1024/te);
    return;
}
double run_time(size_t mem_size)
{
    SimpleVector<int> mvector;
    struct timeval starttime, endtime;
    gettimeofday(&starttime, 0);
    for (size_t i = 0; i < mem_size/sizeof(int); ++i)
    {
        mvector.push_back(i);
    }
    for (size_t i = 0; i < mem_size/sizeof(int); ++i)
    {
        mvector.pop_back();
    }
    gettimeofday(&endtime, 0);
    double te = (static_cast<double>(endtime.tv_sec*1000000 - starttime.tv_sec*1000000 + endtime.tv_usec - starttime.tv_usec))/1000000;
    return te;
}
}

