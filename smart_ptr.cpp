/*
	smart_ptr
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <class T>
class smartptr{

private:
	T * ref;
	int  * ref_count;
public:
	smartptr(T * ptr) :ref(ptr)
	{
		ref_count = (int *)malloc(sizeof(int));
		assert(ref_count!=NULL);
		*ref_count = 1;
	}

	smartptr(smartptr<T> & s_ptr) :ref(s_ptr.ref), ref_count(s_ptr.ref_count)
	{
		++(*ref_count);
	}

	smartptr<T> & operator=(const smartptr<T> & s_ptr)
	{
		if (this == &s_ptr)
			return *this;
		assert(*ref_count>0);
		remove();
		ref = s_ptr.ref;
		ref_count = s_ptr.ref_count;
		++(*ref_count);
	}

	T* getptr()
	{
		return ref;
	}

	int & getcount()
	{
		return *ref_count;
	}

	~smartptr()
	{
		assert(*ref_count > 0);
		remove();
	}
protected:
	void remove()
	{
		--(*ref_count);
		if (*ref_count == 0)
		{
			delete ref;
			ref = NULL;
			free(ref_count);
			ref_count = NULL;
		}
	}
};
int main()
{
	smartptr<string> ptr1(new string("hello"));
	smartptr<string> ptr2 = ptr1;

	cout << (*ptr2.getptr()) << endl;
	cout << ptr1.getcount() << endl;
	cout << ptr2.getcount() << endl;

	smartptr<string> ptr3(new string("hello1"));
	
	ptr2 = ptr3;

	cout << (*ptr2.getptr()) << endl;
	cout << ptr1.getcount() << endl;
	cout << ptr2.getcount() << endl;

	system("pause");
	return 0;

}