//
// Created by luobo on 18-8-21.
//


/**
 * va_start()
 * C 库宏 void va_start(va_list ap, last_arg) 初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。
 * last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
 * 这个宏必须在使用 va_arg 和 va_end 之前被调用。
 *
 * void va_start(va_list ap, last_arg);
 * ap -- 这是一个 va_list 类型的对象，它用来存储通过 va_arg 获取额外参数时所必需的信息。
 * last_arg -- 最后一个传递给函数的已知的固定参数。
 *
 */

#include <stdarg.h>
#include <stdio.h>

int va_start_sum(int num_args,...){

    int val = 0;
    va_list ap;


    va_start(ap,num_args);

    for (int i = 0; i < num_args; ++i) {
        val += va_arg(ap, int);
    }

    va_end(ap);

    return val;
}

