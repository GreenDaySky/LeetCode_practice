#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;


//构造PCB结构体存储
class PCB
{
public:
	PCB(){}
	PCB(string _name, int _rtime, int _priority)
		: name(_name) ,rtime(_rtime), priority(_priority), status('R'), next(NULL)
	{}
	string name;
	PCB* next;
	int rtime;
	int priority;
	char status;
};

bool cmp(PCB a, PCB b)
{
	return a.priority > b.priority;
}

void print(vector<PCB> arr)
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i].name << ' ' << arr[i].rtime << ' ' << arr[i].priority << ' ' << arr[i].status << endl;
	}
	cout << endl;
}

int main()
{
	int isE = 0;
	vector<PCB> pcbvector(5);
	pcbvector[0] = PCB("PCB1", 3, 22);
	pcbvector[1] = PCB("PCB2", 4, 20);
	pcbvector[2] = PCB("PCB3", 2, 22);
	pcbvector[3] = PCB("PCB4", 7, 25);
	pcbvector[4] = PCB("PCB5", 9, 10);

	//先根据优先级进行排序
	sort(pcbvector.begin(), pcbvector.end(), cmp);

	while (1) {
		//打印
		print(pcbvector);

		//模拟运行一次
		pcbvector[0].rtime--;
		pcbvector[0].priority--;

		//如果运行完后该PCB已经不需要运行了,将该PCB放在最后 
		if (pcbvector[0].rtime == 0) {
			pcbvector[0].status = 'E';
			isE++;
			swap(pcbvector[5 - isE], pcbvector[0]);
		}
		//结束运行的条件是5个进程全都不需要运行
		if (isE == 5)
			break;
		//将未运行完成的进程进行排序
		sort(pcbvector.begin(), pcbvector.end() - isE, cmp);
	}
	print(pcbvector);

	system("pause");
	return 0;
}