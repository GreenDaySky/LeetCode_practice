#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#if 0
int main()
{
	string str;
	int k;
	while (cin >> str >> k) {
		if (k == 1)
			cout << str << endl;
		else {
			vector<string> tmp;
			int i;
			int j = 0;
			for (i = 1; i < str.size(); i++) {
				if (str[i] >= '0' && str[i] <= '9') {
					j++;
				}
				else {
					tmp.push_back(str.substr(i - j, j));
					j = 0;
				}
			}
			for (int i = 0; i + k - 1 < tmp.size(); i = i + k)
			{
				reverse(tmp.begin() + i, tmp.begin() + i + k);
			}
			cout << '[' << tmp[0];
			for (int a = 1; a < tmp.size(); a++) {
				cout << ',' << tmp[a];
			}
			cout << ']' << endl;
		}
	}

	//string str = "asdfghjkl";
	//reverse(str.begin(), str.begin() + 2);
	//vector<string> t = { "adb", "a", "cc" };
	//reverse(t.begin(), t.begin() + 2);
	//cout << str << endl;
	//for (auto &e : t)
	//	cout << e << ' ';
	system("pause");
	return 0;
}





int main()
{
	string str;	
		while (cin >> str) {
		for (int i = 0; i < str.size(); i++) {
			int j = i + 1;
			int tmp;
			while (j < str.size())
			{
				while (str[j] != str[j] && j < str.size())
					j++;
				if (j == str.size())
					continue;
				while (str[i] == str[j] && j < str.size()) {
					i++;
					j++;
					if (j == str.size()) {
						cout << "true" << endl;
					}
				}
			}
			
		}
		cout << false << endl;
	}
		system("pausue");
		return 0;
}


void Func(const vector<int> arr, vector<int> &res)
{
	int size = arr.size();
	for (int i = 1; i <= pow(2, size) - 1; i++)
	{
		int tmp = 0;
		int num = i;
		for (int j = 0; j < size; j++)
		{
			if (num & 1 == 1)
				tmp += arr[j];
			num = num >> 1;
		}
		res.push_back(tmp);
	}
}


int main()
{
	vector<int> arr = { 1, 2, 3 };
	vector<int> res;
	Func(arr, res);
	for (auto &e : res)
		cout << e << ' ';
	cout << endl;
	system("pause");
	return 0;
}


vector<int> leap = { 31,29,31,30,31,30,31,31,30,31,30,31 };
vector<int> nor = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//判断闰年
bool isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

//判断那一年一月一号据2000年一月一号的天数
int oneDay(int year)
{
	int days = (year - 2000) / 4 * (365 * 3 + 366);
	if ((year - 2000) % 4 == 0)
		return days;
	else
		days += 366 + 365 * ((year - 2000) % 4 - 1);
	return days;
}
//判断几年几月几号是周几
int judge(int year, int mon, int day)
{
	int days = oneDay(year);
	if (isLeap(year)) 
		for (int i = 0; i < mon - 1; i++)
			days = days + leap[i];
	else
		for (int i = 0; i < mon - 1; i++)
			days = days + nor[i];
	days += day - 1;
	
	int tmp = days % 7;
	tmp += 6;
	if (tmp > 7)
		return tmp - 7;
	else
		return tmp;
}
void print(int year, int mon, int day)
{
	cout << year << '-';
	if (mon >= 10)
		cout << mon << '-';
	else
		cout << '0' << mon << '-';
	if (day >= 10)
		cout << day << endl;
	else
		cout << '0' << day << endl;
}

void Year(int year)
{
	//元旦
	print(year, 1, 1);
	//马丁
	int t = judge(year, 1, 1);
	if (t == 1)
		print(year, 1, 15);
	else {
		int tmp = 7 - t + 2;
		tmp += 14;
		print(year, 1, tmp);
	}
	//总统
	t = judge(year, 2, 1);
	if (t == 1)
		print(year, 2, 15);
	else {
		int tmp = 7 - t + 2;
		tmp += 14;
		print(year, 2, tmp);
	}
	//阵亡
	t = judge(year, 5, 31);
	if (t == 1)
		print(year, 5, 31);
	else
		print(year, 5, 31 - t + 1);
	//国庆
	print(year, 7, 4);
	//劳动
	t = judge(year, 9, 1);
	if (t == 1)
		print(year, 9, 1);
	else
		print(year, 9, 7 - t + 2);
	//感恩
	t = judge(year, 11, 1);
	if (t <= 4)
		print(year, 11, 21 + 5 - t);
	else
		print(year, 11, 7 - t + 1 + 21 + 3 + 1);
	//圣诞
	print(year, 12, 25);
}

int main()
{
	int year;
	while (cin >> year) {
		Year(year);
	}
	system("pause");
	return 0;
}



int main()
{
	vector<int> arr(100001);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 100001; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 1000000;
	}
	int n;
	while(cin >> n) {
		cout << arr[n] << endl;
	}

	system("pause");
	return 0;
}


int main()
{
	string str, s;
	while (cin >> str >> s) {
		size_t pos = 0;
		int res = 0;
		while ((pos = str.find(s, pos)) != string::npos)
		{
			res++;
			pos += s.size();
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}


#include<list>

struct TimeSegment {
	uint64_t btime;
	uint64_t etime;
	TimeSegment() : btime(0), etime(0) {
	}
	TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {
	}
};

inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment>& lstTimeSegment) {
	//to do
	auto first = lstTimeSegment.front();
	auto end = lstTimeSegment.back();
		if (first.btime > nEndTime) {
			TimeSegment tmp = TimeSegment(nBeginTime, nEndTime);
			lstTimeSegment.push_front(tmp);
		
		if (end.etime < nBeginTime) {
			TimeSegment tmp = TimeSegment(nBeginTime, nEndTime);
			lstTimeSegment.push_front(tmp);
		}
		for (auto i = lstTimeSegment.begin(); i != lstTimeSegment.end(); i++)
		{
		}
		first = first->next;
	}


}

#endif


#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n) {
		string res;
		for (int i = 0; i < n; i++) {
			cout << i << endl;
			string tmp;
			getline(cin, tmp);
			if (string::npos != tmp.find(',') || string::npos != tmp.find(' '))
				res = res + '"' + tmp + '"';
			else
				res += tmp;
			if (i != n - 1)
				res += ', ';
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}


//int main()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		string str;
//		getline(cin, str);
//		cout << str << endl;
//	}
//	system("pause");
//	return 0;
//}