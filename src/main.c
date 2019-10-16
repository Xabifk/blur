#include <stdio.h>
#include <stdlib.h>
#include "memory_map/memory_map.h"

int main(int argc, char * argv[])
{
    unsigned pid = atoi(argv[1]);

    FILE* memory_map = open_memory_map(pid);
    read_memory_map(memory_map);

    return 0;
}