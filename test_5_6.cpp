#define _CRT_SECURE_NO_WARNINGS 1t
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


//ʵ��һ �򵥳������
void printPrimeNum()
{
	for (int i = 2; i <= 100; i++) {
		int j = 0;
		for (j = i - 1; j > 0; j--) {
			if (i % j == 0) {
				break;
			}
		}
		if (j == 1) {
			cout << i << endl;
		}
	}
}


//ʵ��� ����ָ�뼰Ӧ��
void bubbleSort(int *arr, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = count - 1; j > 1; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

bool higher(vector<int> a, vector<int> b)
{
	return a[0] > b[0];
}


void nameGrade()
{
	int m = 4, n = 3;
	vector<vector<int>> grade(m, vector<int>(n));
	grade[0] = { 99, 80, 80 };
	grade[1] = { 80, 70, 60 };
	grade[2] = { 70, 60, 75 };
	grade[3] = { 90, 80, 65 };

	for (auto &e : grade)
	{
		for (auto &h : e)
			cout << h << ' ';
		cout << endl;
	}
	cout << endl;

	//�Ե�һ���γ̵ĳɼ���������
	sort(grade.begin(), grade.end(), higher);

	for (auto &e : grade)
	{
		for (auto &h : e)
			cout << h << ' ';
		cout << endl;
	}
}

//ʵ���� �̳��Ժ�������



//Building��
class Building {
public:
	Building(string _address, int num)
		:address(_address), BuildNum(num)
	{}
	string getAddress();
	int getBuildNum();

private:
	string address;
	int BuildNum;
};
string Building::getAddress()
{
	return Building::address;
}
int Building::getBuildNum()
{
	return BuildNum;
}


//House��
class House :public Building {
public:
	House(string _address, int BuildNum, int _HouseNum, double area)
		:Building(_address, BuildNum), HouseNum(_HouseNum), HouseArea(area)
	{}

	int getHouseNum();
	double getHouseArea();
private:
	int HouseNum;
	double HouseArea;
};

int House::getHouseNum()
{
	return HouseNum;
}

double House::getHouseArea()
{
	return HouseArea;
}

//Office��
class Office :public Building {
public:
	Office(string _address, int BuildNum, string _OfficeName, string _Tel)
		:Building(_address, BuildNum), OfficeName(_OfficeName), Tel(_Tel)
	{}

	string getOfficeName();
	string getTel();

private:
	string OfficeName;
	string Tel;
};

string Office::getOfficeName()
{
	return OfficeName;
}
string Office::getTel()
{
	return Tel;
}


int main()
{
	//printPrimeNum();


	/*int arr[] = { 1, 5, 4, 9, 7, 54, 8, 34, 67, 22 };
	bubbleSort(arr, sizeof(arr)/4);
	for (auto&e : arr)
		cout << e << endl;*/

	//nameGrade();
	Building b1("��԰С��" ,5);
	Building b2("������Է", 12);

	House h1("��԰С��", 5, 11, 108.46);
	House h2("������Է", 12, 8, 76.90);

	Office o1("��԰С��", 5, "������Ƥ", "13992644466");
	Office o2("������Է", 12, "����ը��", "13098217966");


	cout << o1.getAddress() << ' ' << o1.getBuildNum() << ' ' << o1.getOfficeName() << ' ' << o1.getTel() << endl;
	cout << h2.getAddress() << ' ' << h2.getBuildNum() << ' ' << h2.getHouseArea() << ' ' << h2.getHouseNum() <<endl;
	system("pause");
	return 0;
}

