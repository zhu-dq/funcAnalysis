/*
 * tips:
 *      1.sizeof工作与编译期
 *      2.  char ss[100] = "0123456789";
 *          sizeof(ss) 结果是100 ＝＝＝》ss表示在内存中的大小 100×1
 *          strlen(ss) 结果是10 ＝＝＝》strlen是个函数内部实现是用一个循环计算到\0为止之前
 * sizeof class 的情况
 * 1. 空类:大小为1
 * 2. 简单类：使用sizeof求这种简单类，
 *    结果和求结构体的sizeof是一样的，需要考虑偏移和对齐.
 * 3. 简单类含static的情况：static变量不属于类的一部分
 *    ，如果类中定义了static变量，求sizeof时可以忽略它们   
 * 4. 带虚函数的类:虚函数放在虚表中，类中定义了虚函数，需要存放一个指向虚表的指针。
 * 5. 继承相关
 *      参考文章：http://www.cnblogs.com/kekec/archive/2013/01/27/2822872.html
 *         
 */
#include <iostream>
using namespace std;

// case 1
class test1{

};//assert 1

// case 2
class test2{
    public:
        int a;
    private:
        char b;
};//assert 8

//case 3
class test3{
    public:
        static int a;
    private:
        char b;
};//assert 1
int test3::a;

//case 4
class test4{
    public:
        int a;
        virtual void func(){}
};// assert 16   //PS:64位系统 int是4 int*是8

class test4_1{
    public:
        virtual void func(){}
        int a;
};
//通过sizeof test4 == sizeof  test4_1  ==> 虚表指针应该在尾部

class test4_2{//多个虚函数
    public:
        int a;
        virtual void func1(){}
        virtual void func2(){}
        virtual void func3(){}
};//assert 16
//通过sizeof test4 == sizeof  test4_2  ==> 只与虚表指针代大小有关，与虚函数个数无关
/*
//简单继承
    class A  
    {  
    public:  
        int a;  
    private:  
        char b;  
    };  //size A : 8
    class B : public A  
    {  
    public:  
        char c;// 交换c d 位置 sizeof（B）由12变成16 ==>> B的结构类似struct{int a;char b;char c;int d;}
        int d;
    }; //size B: 12 
*/
/*
//父类含虚函数继承
    class A  
    {  
    public:  
        char a;  
        virtual void func(){}
    };  //size A : 16
    class B : public A  
    {  
    public:  
        char c;//由sizeof（B）== 16 ==>> B的结构类似struct{int * virtualTable;char a;char c;int d;}
        int d;
    }; //size B:  16
*/
/*
//父类和子类都含虚函数继承
//这个要注意的一点是，虽然子类和父类都包含虚函数， 
//但它们存放于同一个虚表中，因此只需要一个指针
    class A  
    {  
    public:  
        char a;  
        virtual void func(){}
    };  //size A : 16
    class B : public A  
    {  
    public:  
        char c;//由sizeof（B）== 16 ==>> B的结构类似struct{int * virtualTable;char a;char c;int d;}
        int d;
        virtual void func1(){}
    }; //size B:  16
*/
/*
//子类虚继承父类:普通虚继承，不带虚函数
    class A  
    {  
    public:  
        char a;  
        int b;
    };  //size A : 8
    class B : virtual public A  
    {  
    public:  
        char c;
        int d;
    }; //size B:  24  B的结构类似struct{int * vbptr;char a;int b;char c;int d;}
*/

/*
//子类虚继承父类:普通虚继承，父类带虚函数
    class A  
    {  
    public:  
        char a;  
        virtual void func(){}
    };  //size A : 16
    class B : virtual public A  
    {  
    public:  
        char c;
        int d;
    }; //size B:  32  B的结构类似struct{int * vfptr;int * vbptr;char a;int b;char c;int d;}
*/
///*
//子类虚继承父类:普通虚继承，子类带虚函数
    class A  
    {  
    public:  
        int a;  
    };  //size A : 4
    class B :virtual public A  
    {  
    public:  
        char c;
        int d;
        virtual void func1(){}
    }; //size B: 24  B的结构类似struct{int * vbptr;int a;int b;char c;int d;}
//*/
int main()
{
    cout<<"test1 : "<<sizeof(test1)<<endl;
    cout<<"test2 : "<<sizeof(test2)<<endl;
    cout<<"test3 : "<<sizeof(test3)<<endl;
    cout<<"test4 : "<<sizeof(test4)<<endl;
    cout<<"test4_1 : "<<sizeof(test4_1)<<endl;
    cout<<"test4_2 : "<<sizeof(test4_2)<<endl;
    //(gdb) p b //set p obj on
    //$2 = (B) {<A> = {a = -8400}, _vptr.B = 0x400ce0 <vtable for B+24>, c = -32 '\340', d = 0}//
    //$1 = (B) {<A> = {a = 4196576}, _vptr.B = 0x400cd8 <vtable for B+16>, c = 0 '\000', d = -8400}//去掉虚继承
    //$1 = (B) {<A> = {a = -8400}, _vptr.B = 0x400cd0 <VTT for B>, c = -32 '\340', d = 0}//去掉func1的虚函数
    B b;
    cout<<"A : "<<sizeof(A)<<endl;
    cout<<"B : "<<sizeof(B)<<endl;
    return 0;
}
