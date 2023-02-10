#include <memory>
#include <string>
#include <time.h>
#include <iostream>
using namespace std;
class Elem {
public:
    Elem () : Elem("this is a test object"){};
    Elem (const char *name);
private:
    const char *name;
};

Elem::Elem(const char *name)
{
    this->name = name;
}

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

int main()
{

    clock_t begin = clock();
    size_t number = 1024*16;
    std::cout<<number<<std::endl;
    mem_bench<Elem>(number);
    clock_t end = clock();
    auto mem_size = [number] { return sizeof(Elem)*number*number; };
    auto run_time = [end, begin] { return end-begin; };
    cout<<"time cost is "<<run_time()<<endl;
    cout<<"launch speed is "<<mem_size()/run_time()*CLOCKS_PER_SEC /1024/1024<<"Mbytes/s"<<endl;
    return 0;
}
