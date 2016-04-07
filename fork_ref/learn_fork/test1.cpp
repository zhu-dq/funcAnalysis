/*
 * 程序：关于的fork输出值的讨论
 * 思路：http://coolshell.cn/articles/7965.html  （膜拜耗神）
 */
#include <iostream>
#include <unistd.h>//fork 头文件
using namespace std;
//
void testfork()
{
    cout<<"testfork id :"<<getpid()<<endl;
    pid_t  id = fork();
    if(id<0)
        cout<<"id is error !"<<endl;
    if(id ==0)
        cout<<" from son : "<<id<<" 当前进程ID： "<<getpid()<<endl;
    else
        cout<<"from father : "<<id<<"当前进程ID： "<<getpid()<<endl;
}


 //结论：
 //     1.  main：：pid == testfork::pid
 //     2.  fork 返回两个id:  father_id   son_id
 //     3.  father_id != son_id
 //     4.  father_id != testfork::pid
/*
int main()
{
    //父进程：getppid()   当前进程:getpid()
    cout<<"main id : "<<getpid()<<endl;
    testfork();
    return 0;
}
*/