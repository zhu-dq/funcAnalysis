//
// Created by zhudanqi on 16-4-6.
//

#include <iostream>
#include <unistd.h>
#include <stdio.h>
/*
 * 测试1：输出不带\n的情况
 */
void test1fork()
{
    for(int i = 0;i<2;++i)
    {
        fork();
        //printf("$  ref: i:%d ,pid : %d, ppid : %d",i,getpid(),getppid());
        printf("*");
    }
}
/*
 *下面是继承关系图：
 *             -->son(**)-->sun2(***)
 * main(*) -> |
 *             -------->sun1(**)
 *
 */
/*
 *  我对缓冲区的一点理解(猜得，未验证)
 *  1.有些函数是从缓冲区读取的，有些是从键盘直接读取的
 *  2.在从缓冲区读取的函数，应该维护着一个指针。
 *  3.在读取指针指向的元素后指针会后移
 *  4.重复3直到遇到‘\n’ ,刷新缓冲区，等待输入
 *  下面做个测试
 */

void testprintf()
{
    for(int i=0;i<3;++i)
        printf("*");
}
void testgetchar()
{
    char ch = getchar();//input abc  即 ： abc\n
    printf("1 : %c",ch);//a
    ch = getchar();
    printf("  2: %c",ch);//b
    ch = getchar();
    printf("  3: %c",ch);//c
    ch = getchar();
    printf("  4: %c",ch);//\n
    ch = getchar();  //等待输入,我输入 d 即： d\n
    printf("  5: %c",ch);//d
    ch = getchar();
    printf("  6: %c",ch);//\n

}

int main()
{
    //test1fork();
    //testgetchar();
    testprintf();
    return 0;
}
