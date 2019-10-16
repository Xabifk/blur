#include <stdio.h>
#include <stdlib.h>
#include "memory_map.h"


struct memory_space
{
    long long unsigned start_address;
    long long unsigned end_address;
    short permissions;
    char* name;
};

FILE* open_memory_map(unsigned pid)
{
    char file_name[40];

    sprintf(file_name, "/proc/%u/maps", pid);

    FILE* memory_map = fopen(file_name, "r");

    return memory_map;
}


memory_space read_memory_map_line(FILE* memory_map)
{
    memory_space new_location;
    new_location.name = malloc(sizeof(char) * 100);
    new_location.permissions = 0;

    char permision_string[6];

    fscanf(memory_map, "%llx-%llx %s %*s %*s %*s%*c", 
            &new_location.start_address, &new_location.end_address, 
            permision_string);

    char chr = fgetc(memory_map); // TODO - Do it in a better way
    
    if(chr == ' ')
    {
        fscanf(memory_map, " %s ", new_location.name);
    }
    else
    {
        new_location.name = "None";
    }
    


    for(int i = 0; i < 3; i++)
    {
        if(permision_string[i] != '-')
        {
            new_location.permissions = new_location.permissions | (1 << (2 - i));
        }
    }

    return new_location;
}

memory_space* read_memory_map(FILE* memory_map)
{
    memory_space* memory_locations = malloc(sizeof(memory_space) * 100);

    for(int i = 0; i < 100 && feof(memory_map) == 0; i++)
    {
        memory_locations[i] = read_memory_map_line(memory_map);
        printf("%llx-%llx %d %s\n", memory_locations[i].start_address, memory_locations[i].end_address, memory_locations[i].permissions, memory_locations[i].name);

    }

    return memory_locations;
}