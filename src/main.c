#include <stdio.h>
#include <stdlib.h>
#include "memory_map/memory_map.h"
#include "memory_interface/memory_interface.h"


int main(int argc, char * argv[])
{
    unsigned pid = atoi(argv[1]);

    FILE* memory_map = open_memory_map(pid);
    memory_space* memory_locations = malloc(sizeof(memory_space) * 100);

    read_memory_map(memory_map, memory_locations, 100);

    short* output = malloc(sizeof(short) * 0x10000); 

    FILE* process_memory = open_process_memory(pid);

    get_process_memory_segment(process_memory, output, memory_locations[19].start_address, 0x10000);

    for(int i = 0; i < 0x10000; i++)
    {
        if(i % 100 == 0)
            printf("\n");
        if(output[i] == 0)
            printf(".");
        else
            printf("%x", output[i]);
        
    }
    printf("\n");

    return 0;
}