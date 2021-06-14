#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>







int main(int argc, char **argv)
{
    char *paddr;
    int fd; //file descriptor;
    struct stat sb;
    int size;

    printf("START \n");



    fd = open("textfile.txt", O_RDONLY);
    fstat(fd, &sb);
    size = sb.st_size;

    paddr = mmap(NULL, 5, PROT_READ,MAP_PRIVATE,fd,0);
    printf("%p\n",&paddr);

    
    for (int i = 0; i < size; i++) {
        char c;
        c = paddr[i];
        putchar(c);
        getchar();
    }
    putchar('\n');


    munmap(paddr, 5);
    close(fd);


    printf("STOP\n");
}

