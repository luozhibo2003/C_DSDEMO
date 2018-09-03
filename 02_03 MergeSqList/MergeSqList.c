//
// Created by luobo on 18-9-3.
//

/**************************************
 *                                    *
 * 文件夹: ▲02 线性表\03 MergeSqList *
 *                                    *
 * 文件名: MergeSqList.c              *
 *                                    *
 * 算  法: 2.2、2.7                   *
 *                                    *
 **************************************/

/**
 * 单链表（顺序表）归并算法，将两个顺序表合并到一个新的顺序表中，要求合并前后顺序表均有序排列。
 *
 * 顺序表的归并有两种方案，一种使用指针，
 * 另一种利用数组下标实现。
 * 两种方案都还是通过调用单链表顺序存储结构中封装的各个函数的来实现的，理解上并无难度。
 */

#ifndef CDSEXAMPLES_MERGESQLIST_C
#define CDSEXAMPLES_MERGESQLIST_C

#include "MergeSqList.h"

/*════╗
║ 算法2.2║
╚════*/
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)    //调用顺序表函数进行合并
{
    int La_len, Lb_len;
    int i, j, k;
    LElemType_Sq ai, bj;

    i = j = 1;
    k = 0;

    InitList_Sq(Lc);
    La_len = ListLength_Sq(La);
    Lb_len = ListLength_Sq(Lb);

    while (i <= La_len && j <= Lb_len) {    //La及Lb均未扫描完

        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &bj);

        if (ai < bj) {
            ListInsert_Sq(Lc, ++k, ai);
            i++;
        } else {
            ListInsert_Sq(Lc, ++k, bj);
            j++;
        }
    }

    while (i <= La_len) {   //表La还未扫描完
        GetElem_Sq(La, i++, &ai);
        ListInsert_Sq(Lc, ++k, ai);
    }
    while (j <= Lb_len) {   //表Lb还未扫描完
        GetElem_Sq(Lb, j++, &bj);
        ListInsert_Sq(Lc, ++k, bj);
    }
}


/*════╗
║ 算法2.7║
╚════*/
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc) {

    LElemType_Sq *pa, *pb, *pc;
    LElemType_Sq *pa_last, *pb_last;

    pa = La.elem;  //指向La第一个元素
    pb = Lb.elem;  //指向Lb第一个元素

    (*Lc).listsize = (*Lc).length = La.length + Lb.length;  //不用InitList_Sq创建Lc
    pc = (*Lc).elem = (LElemType_Sq *)malloc((*Lc).listsize* sizeof(LElemType_Sq));

    if (!pc){
        exit(OVERFLOW);
    }

    pa_last = La.elem + La.length - 1;  //指向La最后一个元素
    pb_last = Lb.elem + Lb.length - 1;  //指向Lb最后一个元素

    while (pa<=pa_last && pb <= pb_last){  //La和Lb均未扫描完

        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while (pa <= pa_last){  //表La未扫描完
        *pc++ = *pa++;    //插入La的剩余元素
    }

    while (pb <= pb_last){ //表Lb未扫描完
        *pc++ = *pb++;	   //插入Lb的剩余元素
    }



}

#endif
