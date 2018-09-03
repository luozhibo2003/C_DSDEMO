//
// Created by luobo on 18-9-3.
//

/********************************
 *                              *
 * 文件夹: ▲02 线性表\02 Union *
 *                              *
 * 文件名: Union.h              *
 *                              *
 * 内  容: 求并集相关操作列表   *
 *                              *
 ********************************/

#ifndef CDSEXAMPLES_UNION_H
#define CDSEXAMPLES_UNION_H

#include "../02_01 SequenceList/SequenceList.h"   //**▲02 线性表**//

/* 并集函数列表 */
/*━━━━━━━━━━━┓
┃(01)算法2.1：A=A∪B。 ┃
┗━━━━━━━━━━━*/
void Union(SqList *La,SqList Lb);

/*━━━━━━━━━━━━┓
┃(02)判断两元素是否相等。┃
┗━━━━━━━━━━━━*/
Status equal(LElemType_Sq e1,LElemType_Sq e2);




#endif //CDSEXAMPLES_UNION_H
