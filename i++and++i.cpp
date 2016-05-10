/*
	i++与++i的区别

		i++ 有个临时对象拷贝的过程

*/

/*

//i++实现代码为：   

int operator++(int)
{
	int temp = *this;//有个临时对象的拷贝过程
	++*this;
	return temp;//返回一个int型的对象本身
}

// ++i实现代码为：

int& operator++()
{
	*this += 1;
	return *this;//返回一个int型的对象引用
}

*/