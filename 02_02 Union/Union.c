//
// Created by luobo on 18-9-3.
//

/********************************
 *                              *
 * 文件夹: ▲02 线性表\02 Union *
 *                              *
 * 文件名: Union.c              *
 *                              *
 * 算  法: 2.1                  *
 *                              *
 ********************************/

/**
 * 求并集的思路很简单，大致可分为三步：
 *      第一：找到A的链表尾部；
 *      第二：开始遍历B，判断B的每个元素是否在A中存在；
 *      第三：如果B中元素不在A中，则将其插入到A中，并继续向前探索，直至遍历完B中全部元素。
 */

#ifndef CDSEXAMPLES_UNION_C
#define CDSEXAMPLES_UNION_C

#include "Union.h"          //**▲02 线性表**//

/*════╗
║ 算法2.1║
╚════*/
void Union(SqList *La, SqList Lb) {
    int La_len, Lb_len;
    int i;
    LElemType_Sq e;

    La_len = ListLength_Sq(*La);       //求顺序表长度
    Lb_len = ListLength_Sq(Lb);

    for (int i = 1; i <= Lb_len; i++) {
        GetElem_Sq(Lb, i, &e);                  //取Lb中第i个元素赋给e
        if (!LocateElem_Sq(*La, e, equal))   //若e不在La中则插入
            ListInsert_Sq(La, ++La_len, e);
    }
}

Status equal(LElemType_Sq e1, LElemType_Sq e2) {

    return e1==e2 ? TRUE : FALSE;
}


#endif