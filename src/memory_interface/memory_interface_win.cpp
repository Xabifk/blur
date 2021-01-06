#ifdef OS_WIN
#include "memory_interface.h"

MemoryInterface::MemoryInterface(uint64_t pid) 
{
    this->pid = pid;
}
    
std::vector<MemorySegment> MemoryInterface::get_memory_segments() 
{


}

uint64_t MemoryInterface::write_memory(MemorySegment memory_segment, uint64_t offset, std::vector<uint8_t> &buffer)
{

}

uint64_t MemoryInterface::read_memory(MemorySegment memory_segment, uint64_t offset, std::vector<uint8_t> &buffer)
{

}




// FILE* open_process_memory(unsigned pid)
// {
//     char file_name[40];

//     sprintf(file_name, "/proc/%u/mem", pid);

//     FILE* process_memory = fopen(file_name, "rb");

//     return process_memory;
// }

// void get_process_memory_segment(FILE* process_memory, short* output, long long unsigned offset, long long unsigned length)
// {
//     fseek(process_memory, offset, SEEK_SET);

//     fread(output, sizeof(short), length, process_memory);
// }
#endif