//
// Created by luobo on 18-8-31.
//

/**
 * C 库函数 void *malloc(size_t size) 分配所需的内存空间，并返回一个指向它的指针。
 *
 * 声明方式 ：
 *
 * void *malloc(size_t size)
 *
 * size -- 内存块的大小，以字节为单位。
 *
 * 返回：该函数返回一个指针 ，指向已分配大小的内存。如果请求失败，则返回 NULL。
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int malloc_demo_test(){

    char *str;

    //最初的内存分配
    str = (char*)malloc(15);
    strcpy(str,"luobo");
    printf("String = %s , Address = %u \n",str,str);

    //重新分配内存
    str = (char*)realloc(str,25);
    strcat(str,".com");
    printf("String = %s , Address = %u \n",str,str);

    free(str);

    return 0;
}