#include <stdio.h>


typedef struct memory_space
{
    long long unsigned start_address;
    long long unsigned end_address;
    short permissions;
    char* name;
    
} memory_space;

FILE* open_memory_map(unsigned pid);

memory_space read_memory_map_line(FILE* memory_map);

memory_space* read_memory_map(FILE* memory_map, memory_space* memory_locations, unsigned size);
