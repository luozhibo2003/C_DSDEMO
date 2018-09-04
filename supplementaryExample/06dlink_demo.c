//
// Created by luobo on 18-9-4.
//

#include <malloc.h>

struct weapon{
    int price;
    int atk;
    struct weapon * next;
};

//函数返回值是链表的头指针
struct weapon * create(){

    struct weapon * head; //头指针
    struct weapon * p1,*p2;// p1 指向当前新创建的节点，p2指向上一个节点(链表的最后一个节点)

    int n=0; //记录当前节点中的个数

    p1= p2 = (struct weapon *)malloc(sizeof(struct weapon));

    scanf("%d,%d",&p1->price,&p1->atk); //键盘输入节点值

    head = NULL;

    while (p1->price!=0){
        n++;
        if(n==1){ //第一个添加到链表中的值
            head = p1; //链表头指向第一个元素
        } else{
            p2->next = p1;
        }

        p2 = p1;
        p1 = (struct weapon *)malloc(sizeof(struct weapon));
        scanf("%d,%d",&p1->price,&p1->atk); //键盘输入节点值
    }

    p2->next = NULL;
    return (head);


}


int dlink_main_test(){


    struct weapon *p;
    p = create();
    printf("%d,%d\n",p->price,p->atk);


    return 0;
}