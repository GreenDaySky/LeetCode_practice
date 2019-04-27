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
		//	//���ַ���
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

	//ǳ��������
	/*�������ṩ�Ŀ�������
	String(const String& s)
	:_str(s._str)
	{}
	�������ṩ�ĸ�ֵ���������
	String& operator=(const String& s)
	{
	_str = s._str;
	return *this;
	}
	��������������������ʹ��ͬһ��ռ䣬������������ͬһ�ռ���������*/

	//����Ϊ�����ʽ
	
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
//��ͨ��
class String
{
public:
	String(const char* pStr = "")
	{
		//if (nullptr == pStr)
		//{
		//	//���ַ���
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

	//ǳ��������
	/*�������ṩ�Ŀ�������
	String(const String& s)
		:_str(s._str)
	{}
	�������ṩ�ĸ�ֵ���������
	String& operator=(const String& s)
	{
	_str = s._str;
	return *this;
	}
	��������������������ʹ��ͬһ��ռ䣬������������ͬһ�ռ���������*/

	//����Ϊ�����ʽ
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