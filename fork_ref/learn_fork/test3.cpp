//
// Created by zhudanqi on 16-4-6.
//

#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <stdio.h>
using namespace std;
/*
 * 测试2：输出带\n的情况
 */
map<int,vector<int>> forkref;
void test2fork()
{
    for(int i=0;i<2;++i)
    {
        //fork();
        printf("%d",i);
        //printf("$  ref: i:%d ,pid : %d, ppid : %d ",i,getpid(),getppid());
    }
}
/*
 * 1.输出带\n:不考虑缓冲区
 * 2.当i=0时，进程：main --fork()--> (进程：main,进程:son)
 * 下面是树形结构：
 *                           pid：main
 *                              |
 *                          test2fork()
 *                              |
 *                             fork()                            //第一次fork后是两个进程
 *                              |
 *            pid : main                 pid : son
 *                |                         |
 *              fork()                     fork()                 //第二次fork后是四个进程
 *                |                          |
 *    pid:main       pid:sun1       pid:son     pid:sun2
 */
/*
int main()
{
    cout<<" main : pid "<<getpid()<<" ppid : "<<getppid()<<endl;
    test2fork();
    return 0;
}
*/