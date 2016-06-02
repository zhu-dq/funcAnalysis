/*
 	实现priority_pueue
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
template <class T,class Compare = less<class Sequence::value_type>>
class priority_queue{
private:
	vector<T> c;//底层容器
	Compare comp;//比较函数
public:
	priority_queue(){}
	priority_queue(const vector<T> & v) :c(v.begin(), v.end())
	{
		make_heap(c.begin(),c.end(),comp);
	}

	void push(const T & elem)
	{
		c.push_back(elem);
		push_heap(c.begin(),c.end(),comp);
	}

	void pop()
	{
		pop_heap(c.begin(),c.end(),comp);
		c.pop_back();
	}

	T top()const
	{
		return c.front();
	}

	unsigned int size()const
	{
		return c.size();
	}

	bool empty()const
	{
		return c.empty();
	}
};
class comp_a_b{
public:
	bool operator()(const int a,const int b)
	{
		return a > b;
	}
};
class comp_str_size_a_b{
public:
	bool operator()(const string & str1, const string & str2)
	{
		return str1.size() < str2.size();
	}
};

int main()
{
	//=======================test1=========
	cout << "test1" << endl;
	vector<int> v = {1,4,2,6,5,8};
	priority_queue<int, comp_a_b>  p_vec(v);
	while (!p_vec.empty())
	{
		cout << p_vec.top() << endl;
		p_vec.pop();
	}
	//======================test2========
	cout << "test2" << endl;
	priority_queue<string, comp_str_size_a_b> p_vec_1;
	p_vec_1.push("nihao");
	p_vec_1.push("ni");
	p_vec_1.push("hao");
	while (!p_vec_1.empty())
	{
		cout << p_vec_1.top() << endl;
		p_vec_1.pop();
	}
	system("pause");
	return 0;
}