#include "src/cpu2/cpu_bench.cc"
#include "src/mem2/memory_bench.cc"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    /* number of prime, default:20000 */
    long prime_numb = 20000;

    /* size of memory, default:1024*1024*1024 */
    size_t memory_size = 1024*1024*1024;
    /* repeat times, default:10 */
    int repeat = 10;

    /* options */
    int options = 0;

    int op_code;
    while ((op_code = getopt(argc, argv, "hcn:ms:r:")) != EOF )
    {
        switch (op_code)
        {
        case 'h':
            printf("Usage: memben [options]\n");
            printf("Options: \n     -a :number of objects\n     -b :repeat_times\n");
            return 0;
        case 'c':
            options |= 0b100;
            break;
        case 'm':
            options |= 0b010;
            break;
        case 's':
            memory_size = strtoul(optarg, (char **)NULL, 10);
            break;
        case 'n':
            prime_numb = strtoul(optarg, (char **)NULL, 10);
            break;
        case 'r':
            repeat = strtoul(optarg,(char **)NULL, 10);
             default:
            break;
        }
    }

    if (options & 0b100)
    {
        printf("CPU------------------------->\n");
        for (size_t i = 0; i < repeat; ++i)
        {
            cpu_bench::print_result(cpu_bench::run_time(prime_numb), prime_numb);
        }
    }
    if (options & 0b010)
    {
        printf("MEM------------------------->\n");
        for (size_t i = 0; i < repeat; ++i)
        {
            memory_bench::print_result(memory_bench::run_time(memory_size), memory_size);
        }
    }
    return 0;
}
