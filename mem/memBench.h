class memBench
{
private:
    /* data */
    int a;  //4bytes
    float b; //4bytes
    double c; //8bytes
    int d[1024*1024];
public:

    memBench(
        /* args */);
 
    ~memBench();
};

memBench::memBench(/* args */)
{
}

memBench::~memBench()
{
}


