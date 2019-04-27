#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class String
{
public:
	String(const char* pStr = "")
	{
		//if (nullptr == pStr)
		//{
		//	//空字符串
		//	_str = new char[1];
		//	*_str = '\0';
		//}
		//else
		//{
		//	_str = new char[strlen(pStr) + 1];
		//	strcpy(_str, pStr);
		//}
		if (nullptr == pStr)
			pStr = "";
		_str = new char[strlen(pStr) + 1];
		strcpy(_str, pStr);

	}

	//浅拷贝问题
	/*编译器提供的拷贝构造
	String(const String& s)
	:_str(s._str)
	{}
	编译器提供的赋值运算的重载
	String& operator=(const String& s)
	{
	_str = s._str;
	return *this;
	}
	带来的问题是两个对象使用同一块空间，导致析构两次同一空间会带来问题*/

	//以下为深拷贝方式
	
	String(const String& s)
		:_str(nullptr)
	{
		String strTemp(s._str);
		swap(_str,strTemp._str);
	}

	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String strTemp(s);
	//		swap(_str, strTemp._str);
	//	}
	//}

	//String& operator=(const String& s)
	//{
	//	String strTemp(s);
	//	swap(_str, strTemp._str);
	//	return *this;
	//}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
		}
	}
private:
	char* _str;
};

#if 0
//普通版
class String
{
public:
	String(const char* pStr = "")
	{
		//if (nullptr == pStr)
		//{
		//	//空字符串
		//	_str = new char[1];
		//	*_str = '\0';
		//}
		//else
		//{
		//	_str = new char[strlen(pStr) + 1];
		//	strcpy(_str, pStr);
		//}
		if (nullptr == pStr)
			pStr = "";
		_str = new char[strlen(pStr) + 1];
		strcpy(_str, pStr);

	}

	//浅拷贝问题
	/*编译器提供的拷贝构造
	String(const String& s)
		:_str(s._str)
	{}
	编译器提供的赋值运算的重载
	String& operator=(const String& s)
	{
	_str = s._str;
	return *this;
	}
	带来的问题是两个对象使用同一块空间，导致析构两次同一空间会带来问题*/

	//以下为深拷贝方式
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
	
			/*	
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			*/

			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete _str;
			_str = pStr;
		}

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
		}
	}
private:
	char* _str;
};
#endif

void TestFunc()
{
	String str1("hello");
	String str2(nullptr);
	String str3;
	String str4(str1);
}

int main()
{
	TestFunc();
	return 0;
}