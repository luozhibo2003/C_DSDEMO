//
// Created by luobo on 18-9-4.
//

//typedef与宏没有任何关系，但是容易与宏产生混淆

//typedef 作用：给一个变量类型起别名,必须以分号结尾
typedef int tni; //给int类型变量起别名tni
int *p; //定义一个指针变量
typedef int * q; //给 int * 类型，起了一个别名，别名叫q
//q = NULL;
//int * q = NULL;  //与q = NULL 等价  因为 q 就是 int *




