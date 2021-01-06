#include <stdio.h>
#include <vector>
#include <fstream>
#include "../common.h"

class MemorySegment
{
    private:

    uint64_t start_address;
    uint64_t end_address;
    uint8_t permissions;
    std::string name;

    public:

    MemorySegment(uint64_t start_address, uint64_t end_address, std::string name);

}

class MemoryInterface
{
    private:
        uint64_t pid;
        #ifdef OS_WIN

        #endif

        #ifdef OS_UNIX
            std::string file_name;
            fstream file_stream;

        #endif

    public:

    MemoryInterface(uint64_t pid);
    
    std::vector<MemorySegment> get_memory_segments();

    uint64_t write_memory(MemorySegment memory_segment, uint64_t offset, std::vector<uint8_t> &buffer);

    uint64_t read_memory(MemorySegment memory_segment, uint64_t offset, std::vector<uint8_t> &buffer);

};
FILE* open_process_memory(unsigned pid);

void get_process_memory_segment(FILE* process_memory, short* output, long long unsigned offset, long long unsigned length);