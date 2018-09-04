#include <stdio.h>


extern int hello_main();

extern int va_start_sum(int num_args, ...);
extern int malloc_demo_test();
extern int struct_main_test();

extern int SequenceList_main();

extern int Union_main_test();
extern int MergeSqList_main_test();
extern int SinglyLinkedList_main_test();
extern int MergeList_main_test();

int main() {
    //printf("Hello, World!\n");

    //宏测试
    //hello_main();
    //结构体测试
    struct_main_test();

    //va_start 测试
    //printf("10、20 和 30 的和 = %d \n", va_start_sum(3, 10, 20, 30));
    //printf("4、20、25 和 30 的和 = %d\n", va_start_sum(4, 4, 20, 25, 30));


    //malloc测试函数
    //malloc_demo_test();

    //SequenceList_main();

    //求并集相关函数测试
    //Union_main_test();


    //顺序表归并相关函数测试
    //MergeSqList_main_test();

    //SinglyLinkedList_main_test();

    //MergeList_main_test();

    return 0;
}