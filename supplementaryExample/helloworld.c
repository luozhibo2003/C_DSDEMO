//
// Created by luobo on 18-9-4.
//

/**
 * 编译过程的4个步骤
 *
 * 1、.c 文件
 *   （预处理）//预处理 展开了头文件  宏替换
 * 2、.i 文件
 *    （编译）
 * 3、.s 文件
 *    （汇编）
 * 4、.o 文件
 *     （链接）
 * 5、可执行文件
 */

#include <stdio.h>

//声明宏  不以分号结尾  单纯的字符串替换
//使用场景：
// 1、反复使用的变量 ，命名一个形象的名字 ，
// 2、传递参数
#define R 20
#define N(n) n*10
//声明宏函数
//#define ADD(a,b) a+b  //错误的定义方法
#define ADD(a,b) (a+b)  //应该在宏定义的地方带上括号

//宏函数与正常定义的函数的区别与优势
// 宏定义的函数，不用考虑参数类型，
// 例如add函数必须是int，int，如果不是，类型会被强制转换，就会产生丢值的问题

//正常的求和函数
int add(int a ,int b ){
    return a + b;
}


int hello_main(){

    int a = R;
    printf("%d\n",a);

    int a1[R];  //宏使用
    int b1[R];

    //宏 ：传递参数
    int b= N(a);  // int b = a * 10;
    printf("b=%d\n",b);

    //正常函数调用
    int c = add(a,b);
    printf("c=%d\n",c);

    //使用宏函数
    int d = ADD(a,b);
    printf("d=%d\n",d);

    //使用宏函数正确性验证
    //int e = a+b * a+b  //#define ADD(a,b) a+b
    int e = ADD(a,b) * ADD(a,b); //计算结果错误  编译为：
    printf("e=%d\n",e);



    printf("hello world\n");

    return 0;
}


//$ gcc helloworld.c

//$ gcc -o helloworld.i helloworld.c -E
// -E 表示只让gcc进行预处理



