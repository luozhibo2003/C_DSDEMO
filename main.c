#include <stdio.h>


extern int va_start_sum(int num_args, ...);
extern int malloc_demo_test();

extern int SequenceList_main();

int main() {
    printf("Hello, World!\n");


    //va_start 测试
    //printf("10、20 和 30 的和 = %d \n", va_start_sum(3, 10, 20, 30));
    //printf("4、20、25 和 30 的和 = %d\n", va_start_sum(4, 4, 20, 25, 30));


    //malloc测试函数
    //malloc_demo_test();

    SequenceList_main();


    return 0;
}