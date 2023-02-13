#include "simple_vector.cc"
#include <memory>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <iostream>

#define DEFAULT_MEM_SIZE 1024*1024*1024    // 1GiB

using namespace std;
class Elem {
public:
    Elem () : Elem("this is a test object", 0){};
    Elem (const char *name,int id): name_(name), id_(id){};
    ~Elem () {};
    int get_id() { return id_; };
private:
    const char *name_;
    int id_;
};


// allocator a memory pool of type T which number is  n
// construct T's object on the pool and destroy
template <typename T>
void mem_bench(size_t n)
{
    allocator<T> alloc;
    for (size_t j = 0; j < n; ++j)
    {
        auto p = alloc.allocate(n);
        for (size_t i = 0; i < n; ++i)
        {
            alloc.construct(p, " ");
            alloc.destroy(p);
            p++;
        }
    }
}
// version 1.0
// int main()
// {
//
//     clock_t begin = clock();
//     size_t number = 1024*16;
//     std::cout<<number<<std::endl;
//     mem_bench<Elem>(number);
//     clock_t end = clock();
//     auto mem_size = [number] { return sizeof(Elem)*number*number; };
//     auto run_time = [end, begin] { return end-begin; };
//     cout<<"time cost is "<<run_time()<<endl;
//     cout<<"launch speed is "<<mem_size()/run_time()*CLOCKS_PER_SEC /1024/1024<<"Mbytes/s"<<endl;
//     return 0;
// }
void print_result(double time, double memory_size)
{
    printf("Time_cost: %.5f\t",time);
    printf("Memory_size: %.5f\t", memory_size);
    printf("WR_speed: %.3f MiB/s\n" , memory_size/time);
    return;
}
int main()
{

    SimpleVector<Elem> mvector;
    size_t number = 1024*1024*512;
    struct timeval starttime , endtime;
    gettimeofday(&starttime, NULL);
    // clock_t begin = clock();
    // Elem e("hello", 1234);
    // std::cout<<e.get_id()<<std::endl;
    // mvector.push_back(e);
    // auto e_p = mvector.end();
    // e_p--;
    // std::cout<<e_p->get_id()<<std::endl;
    for (size_t i = 0; i < number; ++i)
    {
        Elem e("hello", i);
        mvector.push_back(e);
    }
    // for (size_t i = 0; i < number; ++i)
    // {
    //     auto last = mvector.end();
    //     last--;
    //     mvector.pop_back();
    // }
    // clock_t end = clock();
    gettimeofday(&endtime, NULL);
    double te=((double)(endtime.tv_sec*1000000-starttime.tv_sec*1000000+endtime.tv_usec-starttime.tv_usec))/1000000;
    auto mem_size = [number] { return sizeof(Elem)*number/1024/1024; }; // MiB
    // auto run_time = [end, begin] { return end-begin; };
    // cout<<"time cost is "<<run_time()<<endl;
    // cout<<"launch speed is "<<mem_size()/run_time()*CLOCKS_PER_SEC /1024/1024<<"Mbytes/s"<<endl;
    print_result(te, mem_size());
    return 0;
}
