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
// int main(int argc, char **argv)
// {
//
//     SimpleVector<Elem> mvector;
//     size_t number = 1024*1024*512;
//     /* starttime and endtime */
//     struct timeval starttime , endtime;
//     /* option code */
//     int op_code;
//     /* show avg result per loop? */
//     int show_avg = 1;
//     int repeat_times = DEFAULT_REPEAT_TIME;
//     while ((op_code = getopt(argc, argv, "ha:b:")) != EOF )
//     {
//         switch (op_code)
//         {
//         case 'h':
//             printf("Usage: memben [options]\n");
//             printf("Options: \n     -a :number of objects\n     -b :repeat_times\n");
//             exit(0);
//         case 'a':
//             number = strtoul(optarg, (char **)NULL, 10);
//             break;
//         case 'b':
//             repeat_times = strtoul(optarg,(char **)NULL, 10);
//              default:
//             break;
//         }
//     }
//     gettimeofday(&starttime, NULL);
//     // clock_t begin = clock();
//     // Elem e("hello", 1234);
//     // std::cout<<e.get_id()<<std::endl;
//     // mvector.push_back(e);
//     // auto e_p = mvector.end();
//     // e_p--;
//     // std::cout<<e_p->get_id()<<std::endl;
//     for (size_t i = 0; i < number; ++i)
//     {
//         Elem e("hello", i);
//         mvector.push_back(e);
//     }
//     // for (size_t i = 0; i < number; ++i)
//     // {
//     //     auto last = mvector.end();
//     //     last--;
//     //     mvector.pop_back();
//     // }
//     // clock_t end = clock();
//     gettimeofday(&endtime, NULL);
//     double te=((double)(endtime.tv_sec*1000000-starttime.tv_sec*1000000+endtime.tv_usec-starttime.tv_usec))/1000000;
//     auto mem_size = [number] { return sizeof(Elem)*number/1024/1024; }; // MiB
//     // auto run_time = [end, begin] { return end-begin; };
//     // cout<<"time cost is "<<run_time()<<endl;
//     // cout<<"launch speed is "<<mem_size()/run_time()*CLOCKS_PER_SEC /1024/1024<<"Mbytes/s"<<endl;
//     print_result(te, mem_size());
//     return 0;
// }
