#include"stack_alloc.h"

#include <iostream>
#include <ctime>

#define ELEMS 10000000
#define REPS 50
class Elem
{
    public:
        int a[2];
};
int main()
{
    StackAlloc<Elem,std::allocator<int> > my_stack;
    clock_t start = clock();
    for (int i = 0; i < REPS ; i++)
    {
        assert(my_stack.empty());
        for (int  j = 0; j < ELEMS; j++) {
            Elem temp;
            my_stack.push(temp);
        }
            // my_stack.push(j);
        for (int  j = 0; j < ELEMS; j++)
            my_stack.pop();
    }
    clock_t end = clock();
    std::cout<<"time is "<< (end - start)/CLOCKS_PER_SEC<<std::endl;
    long unsigned int mbytes = ELEMS * REPS ;
    std::cout<<"read/write speed is "<<mbytes/(1024*512)/((end - start)/CLOCKS_PER_SEC)<<" MBytes/s"<<std::endl;
    return 0;
}