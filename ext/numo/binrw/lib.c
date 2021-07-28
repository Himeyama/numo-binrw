#include <sys/stat.h>

long fsize(const char* filename){
    struct stat s;
    if(stat(filename, &s) == 0)
        return s.st_size;
    return -1;
}
