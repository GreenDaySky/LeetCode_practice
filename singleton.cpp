#define _CRT_SECURE_NO_WARNINGS 1

//
////饿汉模式
//class Singleton {
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	Singleton() {};
//	//Singleton(Singleton const&);
//	//Singleton& operator = (Singleton const&);
//
//
//	Singleton(Singleton const&) = delete;
//	Singleton& operator = (Singleton const&) = delete;
//
//	static Singleton m_instance;
//};
//
//
////在程序入口处初始化单例对象
//Singleton Singleton::m_instance;



//懒汉模式

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance() {
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}

	//实现一个垃圾回收
	class CGarbo {
	public:
		CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数销毁单例对象

private:
	Singleton() {};
	Singleton(Singleton const&);
	Singleton& operator = (Singleton const&);

	static Singleton *m_pInstance;
	static mutex m_mtx;
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 20);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;


}