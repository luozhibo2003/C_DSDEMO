//
// Created by luobo on 18-8-21.
//

/***************************************
 *                                     *
 * 文件夹: ▲02 线性表\01 SequenceList *
 *                                     *
 * 文件名: SequenceList.c              *
 *                                     *
 * 算  法: 2.3、2.4、2.5、2.6          *
 *                                     *
 ***************************************/

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C


//**▲02 线性表**//
#include "SequenceList.h"


/*════╗
║算法2.3 ║
╚════*/
//(01)算法2.3：初始化空顺序表L。
Status InitList_Sq(SqList *L) {

    (*L).elem = (LElemType_Sq *) malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if (!(*L).elem) {
        exit(OVERFLOW);  ////分配内存失败
    }
    (*L).length = 0; ////初始化顺序表长度为0
    (*L).listsize = LIST_INIT_SIZE;  ////顺序表初始内存分配量

    return OK; //初始化成功
}

void ClearList_Sq(SqList *L) {

    (*L).length = 0;
}

void DestroyList_Sq(SqList *L) {

    free((*L).elem);

    (*L).elem = NULL; //释放内存后置空指针
    (*L).length = 0;
    (*L).listsize = 0;
}

Status ListEmpty_Sq(SqList L) {

    return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L) {

    return L.length;
}

//(06)用e接收顺序表L中第i个元素。
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e) {

    if (i < 1 || i > L.length) {
        return ERROR;  //i值不合法
    } else {
        *e = L.elem[i - 1];
    }
    return OK;
}


/*════╗
║算法2.6 ║
╚════*/
//(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序。
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq)) {

    int i = 1;
    while (i <= L.length && !Compare(e, L.elem[i - 1]))
        i++;

    if (i <= L.length)
        return i;
    else
        return 0;
}

//(08)用pre_e接收cur_e的前驱。
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e) {

    int i = 0;
    if (L.elem[0] != cur_e) { //第一个结点无前驱
        while (i < L.length && L.elem[i] != cur_e)
            ++i;

        if (i < L.length) {
            *pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

//(09)用next_e接收cur_e的后继。
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e) {

    int i = 0;

    while (i < L.length && L.elem[i] != cur_e)
        ++i;

    if (i < L.length - 1) {
        *next_e = L.elem[i + 1];
        return OK;
    }

    return ERROR;
}

/*════╗
║算法2.4 ║
╚════*/

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e) {

    LElemType_Sq *newbase;
    LElemType_Sq *p, *q;

    if (i < 1 || i > (*L).length + 1)
        return ERROR;  //i值不合法
    if ((*L).length >= (*L).listsize) {  //若存储空间已满，需开辟新空间
        newbase = (LElemType_Sq *) realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(LElemType_Sq));
        if (!newbase)
            exit(OVERFLOW);

        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }

    q = &(*L).elem[i - 1];  //q为插入位置

    for (p = &(*L).elem[(*L).length - 1]; p >= q; --p) {
        *(p + 1) = *p;  //插入位置及之后的元素右移
    }

    *q = e;  //插入e
    (*L).length++;  //表长增1

    return OK;

}

/*════╗
║算法2.5 ║
╚════*/
//(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e) {

    LElemType_Sq *p, *q;

    if (i < 1 || i > (*L).length)
        return ERROR;

    p = &(*L).elem[i - 1]; //p为被删除元素的位置
    *e = *p;
    q = (*L).elem + (*L).length - 1; //表尾元素位置

    for (++p; p <= q; ++p) {
        *(p - 1) = *p;  //被删元素之后的元素左移
    }

    (*L).length--;

    return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq)) {

    for (int i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }

    return OK;
}

#endif

