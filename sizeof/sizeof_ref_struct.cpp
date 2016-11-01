/*
 * 测试sizeof
 * 1.偏移量必须是成员大小的整数倍
 * 2.结构体大小必须是所有成员大小的整数倍
 * 3.对于嵌套的结构体：
 *      1)展开后的结构体的第一个成员的偏移量应当是被展开的结构体中最大的成员的整数倍
 *      2)结构体大小必须是所有成员大小的整数倍，这里所有成员计算的是展开后的成员，
 *        而不是将嵌套的结构体当做一个整体
 * 4.other
 *      &reinterpret_cast<test2*>(0)->elem   //获取偏移量
 */
#include <iostream>
#include <stdio.h>
using namespace std;

struct test0{
    int i;//pyl:0 size:4
    char c;//pyl:4 size:1
};//尾部补3(int 整数倍) 
struct test0_0{
    char c;//pyl:4 size:1
    int i;//pyl:0 size:4
};//尾部补3(int 整数倍) 
struct test1{
    int i;//pyl:0 size:4
    char c;//pyl:4 size : 1
    int j;//pyl: 5+3 size:4
};

struct test2{
    char c1;
    int i;
    char c2;
};

struct test2_2{
    char c1;
    char c2;
    int i;
};

struct test3{
    short i;
    struct
    {
        char c;//pyl:4
        int j;
    }ss;//ss size : 8
    int k;
};// test3 size : 16(2,4（而不是8）,4的倍数)

struct test4{
    char i;
    struct
    {
        char c;
        int j;
    }ss;
    char a;
    char b;
    char d;
    char e;
    char f;//注释掉这行 sizeof 是16 ,加上这行时20;推出是4的倍数 而不是8的倍数
};

struct test4_4{
    char i;
    struct
    {
        char c;
        int j;
    }ss;
    char a;
    char b;
    char d;
    char e;
   // char f;//注释掉这行 sizeof 是16 ,加上这行时20;推出是4的倍数 而不是8的倍数
};

//针对数组的情况
struct test5{
    float f;
    char p;
    int adf[3];
};//test5 size:20(4的倍数 而非12的倍数)

struct temp{
    int k;
    short t;
};


int main()
{
    cout<<"test0 : "<<sizeof(test0)<<endl;//8
    cout<<"test0_0 : "<<sizeof(test0_0)<<endl;//8
    cout<<"test1 : "<<sizeof(test1)<<endl;//12
    cout<<"temp : "<<sizeof(temp)<<endl;
    cout<<"test2 : "<<sizeof(test2)<<endl;//12
    cout<<"test2_2 : "<<sizeof(test2_2)<<endl;//8
    cout<<"test3 : "<<sizeof(test3)<<endl;//16
    cout<<"test4 : "<<sizeof(test4)<<endl;//20
    cout<<"test4_4 : "<<sizeof(test4_4)<<endl;//16
    cout<<"test5 : "<<sizeof(test5)<<endl;//16
    return 0;
}
