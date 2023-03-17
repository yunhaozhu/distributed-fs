#include <stdio.h>
#include "udp.h"
#include "mfs.h"

// client code
int main(int argc, char *argv[]) {
    MFS_Init("localhost", 12169);
    MFS_Creat(0, MFS_REGULAR_FILE, "test");
    int inum = MFS_Lookup(0, "test");
    char buffer[4096] = "hello";
    MFS_Write(inum, buffer, 0, 4096);
    char buffer2[4096];
    MFS_Read(inum, buffer2, 0, 4096);
    printf("read-result: %s\n", buffer2);
    MFS_Shutdown();
    return 0;
}