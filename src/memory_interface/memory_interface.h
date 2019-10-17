#include <stdio.h>

FILE* open_process_memory(unsigned pid);

void get_process_memory_segment(FILE* process_memory, short* output, long long unsigned offset, long long unsigned length);