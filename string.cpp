/*
	string
*/
#include <iostream>
#include <string.h>
//#include <utility>
#include <vector>
using namespace std;

class String{

private:
	char * data_;
public:

	String() :data_(new char[1])
	{
		data_[0] = '\0';
	}

	String(const char * str) :data_(new char[strlen(str) + 1])
	{
		strcpy_s(data_,strlen(str) + 1,str);
	}

	size_t size()const
	{
		return strlen(data_);
	}
	const char * c_str()const
	{
		return data_;
	}

	String(String & rhs) :data_(new char[rhs.size()+1])
	{
		strcpy_s(data_,rhs.size()+1,rhs.c_str());
	}

	void swap(String & rhs)
	{
		std::swap(data_,rhs.data_);
	}

	String & operator=(String & rhs)
	{
		swap(rhs);
		return *this;
	}

	~String()
	{
		delete[] data_;
	}

};
void foo(String x)
{
}

void bar(const String& x)
{
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	/*
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();

	std::vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");
	*/

	system("pause");
	return 0;
}