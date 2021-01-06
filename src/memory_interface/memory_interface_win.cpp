#ifdef OS_WIN
#include "memory_interface.h"


int PrintModules( DWORD processID )
{
    HMODULE hMods[1024];
    HANDLE hProcess;
    DWORD cbNeeded;
    unsigned int i;

    // Print the process identifier.

    printf( "\nProcess ID: %u\n", processID );

    // Get a handle to the process.

    hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                            PROCESS_VM_READ,
                            FALSE, processID );
    if (NULL == hProcess)
        return 1;

   // Get a list of all the modules in this process.

    if( EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
    {
        for ( i = 0; i < (cbNeeded / sizeof(HMODULE)); i++ )
        {
            TCHAR szModName[MAX_PATH];

            // Get the full path to the module's file.

            if ( GetModuleFileNameEx( hProcess, hMods[i], szModName,
                                      sizeof(szModName) / sizeof(TCHAR)))
            {
                // Print the module name and handle value.

                _tprintf( TEXT("\t%s (0x%08X)\n"), szModName, hMods[i] );
            }
        }
    }
    
    // Release the handle to the process.

    CloseHandle( hProcess );

    return 0;
}

#define MAX_MODULE_COUNT
MemoryInterface::MemoryInterface(uint64_t pid) 
{
    this->pid = pid;
}
    
std::vector<MemorySegment> MemoryInterface::get_memory_segments() 
{
    HMODULE hModules[MAX_MODULE_COUNT];
    HANDLE hProcess;
    DWORD cbNeeded;

    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, False, pid);

    if(!hProcess) 
    {
        log_error("Could not open specified procces. Donno why")
        return std::vector<MemorySegment>();
    }

    if(EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
    {
        for ( i = 0; i < (cbNeeded / sizeof(HMODULE)); i++ )
        {
            TCHAR szModName[MAX_PATH];

            if ( GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
            {

            }
        }

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