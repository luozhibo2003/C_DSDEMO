//
// Created by luobo on 18-9-4.
//

#include <stdio.h>

//数组

//结构体：不同数据类型的集合

//创建struct weapon结构体类型，没有分配内存存储空间
//第一种
struct weapon{
    char name[20];
    int atk;
    int price;
};

//第二种
struct weapon2{
    char name[20];
    int atk;
    int price;
}weapon21;

//第三种
struct{
    char name[20];
    int atk;
    int price;
}weapon3;

int struct_main_test(){


    //定义方法1 声明和定义分离，与int a 类似；
    struct weapon weapon_1 = {"ak47",100,200};

    //访问结构体成员变量
    printf("%s\n,%d\n",weapon_1.name,weapon_1.price);  //.运算符是所有运算符中优先级最高的

    //结构体数组
    int a[2];
    //struct weapon weapon_2[2] = {"weapon_name1",50,100,"weapon_name2",100,200};  //或者增加{}
    struct weapon weapon_2[2] = {{"ak47",50,100},{"冲锋枪",100,200}};
    printf("%s\n,%d\n",weapon_2[0].name,weapon_2[1].atk);

    //结构体指针，指向结构体的指针变量，访问结构体成员
    struct weapon * w; //指针变量
    w = &weapon_1; //让指针变量w指向weapon_1
    //*w 表示指向的结构体变量  (*w).name 表示指向的结构体变量的成员 括号不能省略，
    // 因为.优先级最高 ，可以使用w->name代替使用(*w).name。->:指向运算符
    printf("name=%s\n",(*w).name); //w->name , weapon_1.name 三种方法等价
    printf("name=%s\n",w->name);
    printf("name=%s\n",weapon_1.name);


    struct weapon * p;
    //p指向weapon_2数组的起始地址
    p = weapon_2;// p->name  相当于输出 weapon_2[0].name
    printf("name=%s\n",p->name);
    p++; //等价于 weapon_2 + 1 指向了weapon_2[1]
    printf("name=%s\n",p->name);


    return 0;
}

