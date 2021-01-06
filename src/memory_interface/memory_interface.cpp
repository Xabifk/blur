#include <stdio.h>
#include <vector>

FILE* open_process_memory(unsigned pid)
{
    char file_name[40];

    sprintf(file_name, "/proc/%u/mem", pid);

    FILE* process_memory = fopen(file_name, "rb");

    return process_memory;
}

void get_process_memory_segment(FILE* process_memory, short* output, long long unsigned offset, long long unsigned length)
{
    fseek(process_memory, offset, SEEK_SET);

    fread(output, sizeof(short), length, process_memory);
}