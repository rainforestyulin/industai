#include "memBench.h"

#include<unistd.h>
#include<iostream>
#include<sys/timeb.h>
int main()
{
    memBench a;
    timeb s,e;
    std::cout<<sizeof(a)<<std::endl;
    ftime(&s);
    void * testP = operator new (sizeof(a));
    sleep(1);
    ftime(&e);
    operator delete(testP);
    std::cout<<e.time-s.time<<" "<<e.millitm-s.millitm<<std::endl;
    std::cout<<testP<<std::endl;
    return 0;
}
