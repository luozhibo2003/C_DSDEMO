//
// Created by luobo on 18-9-4.
//

/************************************
 *						            *
 * 文件夹: ▲02 线性表\05 MergeList *
 * 						            *
 * 内  容: 单链表归并相关函数测试   *
 *                                  *
 ************************************/

#include <stdio.h>
#include "MergeList.h"

void PrintElem(LElemType_L e);			//测试函数，打印整型

//void PrintElem(LElemType_L e)
//{
//    printf("%d ", e);
//}

int MergeList_main_test()
{
    FILE *fp;
    LinkList La, Lb, Lc;
    int m;

    m = 5;

    printf("作为示例，La长度设定为 %d ，Lb设定为 %d ，创建La和Lb...\n", m, m);
    fp = fopen("../02_05 MergeList/TestData_HL.txt", "r");	//文件指针，指向数据源
    CreateList_HL(fp, &La, m);
    fclose(fp);
    fp = fopen("../02_05 MergeList/TestData_TL.txt", "r");	//文件指针，指向数据源
    CreateList_TL(fp, &Lb, m);
    fclose(fp);

    printf("La = ");
    ListTraverse_L(La, PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb, PrintElem);
    printf("\n\n");
    PressEnter;

    MergeList_L(La, &Lb, &Lc);
    printf("合并La和Lb为Lc = ");
    ListTraverse_L(Lc, PrintElem);
    printf("\n\n");
    PressEnter;

    return 0;
}
