//
// Created by luobo on 18-9-4.
//

#include <stdio.h>

struct weapon {
    int price; //价格
    int atk;  //攻击力
    struct weapon * next; //struct weapon类型的指针变量，用于存放下一个节点的地址
};


int link_main_test() {

    //定义三个节点的结构体变量
    struct weapon a,b,c ,*head;

    //赋值初始值
    a.price = 100;
    a.atk = 100;
    b.price = 200;
    b.atk = 200;
    c.price = 300;
    c.atk = 300;

    //链接成一个链表
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;


    //打印链表中的值
    struct weapon *p;
    p = head;
    while (p!=NULL){
        printf("%d,%d\n",p->atk,p->price);
        p = p->next;
    }

    return 0;




}