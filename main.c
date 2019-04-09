#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_SIZE 1024
int main(void)
{
    int fd;
    char buf[MAX_SIZE],get[MAX_SIZE];
    char devName[20], dir[49] = "/dev/";
    system("ls /dev/");    //获取驱动名
    printf("Device name:");
    gets(devName);
    strcat(dir, devName);
    fd = open(dir, O_RDWR | O_NONBLOCK);
    if (fd != -1)
    {
        read(fd, buf, sizeof(buf));
//        printf("The device was inited with a string : %s\n", buf);
        printf("Input string:");
        gets(get);
//        printf("Write string to device: %s\n", get);
        //读写操作
        write(fd, get, sizeof(get));
        read(fd, buf, sizeof(buf));
//        system("dmesg");//输出错误信息
//        printf("The string in the device: %s\n", buf);
        close(fd);
        return 0;
    }
    else
    {
        printf("Device open failed.\n");
        return -1;
    }
}
