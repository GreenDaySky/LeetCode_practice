#define _CRT_SECURE_NO_WARNINGS 1

//
////����ģʽ
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
////�ڳ�����ڴ���ʼ����������
//Singleton Singleton::m_instance;



//����ģʽ

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

	//ʵ��һ����������
	class CGarbo {
	public:
		CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	//����һ����̬��Ա�������������ʱ��ϵͳ���Զ��������������������ٵ�������

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