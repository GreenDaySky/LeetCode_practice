#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

//数组中出现次数超过一半的数字
//int main()
//{
//	int n;
//	while (cin >> n) {
//		vector<int> accept(n);
//		for (int i = 0; i < n; i++)
//			cin >> accept[i];
//		int count = 0;
//		int num;
//		for (auto & e : accept)
//		{
//			if (count == 0)
//			{
//				num = e;
//				count = 1;
//				continue;
//			}
//			else if (e == num)
//				count++;
//			else
//				count--;
//		}
//		int size = 0;
//		for (auto & e : accept) {
//			if (e == num)
//				size++;
//		}
//		if (size >= (n + 1) / 2.0)
//			cout << num << endl;
//		else
//			cout << 0 << endl;
//	}
//	return 0;
//}


//顺时针打印矩阵
//int main()
//{
//	vector<vector<int> > a = { {1, 3, 5} };
//	int col = 3;
//	int row = 1;
//
//	int maxCol = col - 1;
//	int minCol = 0;
//	int maxRow = row - 1;
//	int minRow = 0;
//
//	while (maxCol >= minCol && maxRow >= minRow)
//	{
//		for (int i = minCol; i <= maxCol; i++)
//			cout << a[minRow][i] << endl;
//		minRow++;
//		if (minRow > maxRow)
//			break;
//		for (int i = minRow; i <= maxRow; i++)
//			cout << a[i][maxCol] << endl;
//		maxCol--;
//		if (maxCol < minCol)
//			break;
//		for (int i = maxCol; i >= minCol; i--)
//			cout << a[maxRow][i] << endl;
//		maxRow--;
//		for (int i = maxRow; i >= minRow; i--)
//			cout << a[i][minCol] << endl;
//		minCol++;
//	}
//	system("pause");
//	return 0;
//}



//左右最值最大差
//int main()
//{
//	vector<int> a = { 2, 1, 6, 7, 1, 1, 2 };
//	int max = 0;
//	for (int i = 0; i <= a.size() - 2; i++)
//	{
//		vector<int> left(a.begin(), a.begin() + i + 1);
//		vector<int> right(a.begin() + i + 1, a.end());
//		vector<int>::iterator left_max = max_element(left.begin(), left.end());
//		vector<int>::iterator right_max = max_element(right.begin(), right.end());
//		if (abs(*left_max - *right_max) > max)
//			max = abs(*left_max - *right_max);
//	}
//	cout << max << endl;
//	system("pause");
//	return 0;
//}



//合唱团
//int main()
//{
//	int n;
//	while (cin >> n) {
//		vector<int> capacity(n + 1);
//		for (int i = 1; i <= n; i++)
//			cin >> capacity[i];
//		int k, d;
//		cin >> k >> d;
//
//
//		//NK[n][k]表示寻找在n个里面找k个数时以第n个为结尾的乘积
//		long long NKzheng[51][11];
//		long long NKfu[51][11];
//
//
//		//初始化无效值
//		for (int i = 1; i <= 50; i++)
//			for (int j = 1; j <= 10; j++)
//			{
//				NKzheng[i][j] = LLONG_MIN;
//				NKfu[i][j] = LLONG_MAX;
//			}
//
//
//		//初始化选取一个数的时候的值
//		for (int i = 1; i <= n; i++)
//		{
//			if (capacity[i] > 0)
//				NKzheng[i][1] = capacity[i];
//			else
//				NKfu[i][1] = capacity[i];
//		}
//
//
//		//核心主体思想
//		for (int i = 2; i <= n; i++)
//			for (int j = 2; j <= n && j <= k; j++)
//			{
//				long long max = LLONG_MIN;
//				long long min = LLONG_MAX;
//
//				for (int tmp = (j - 1) > (i - d) ? (j - 1) : (i - d); tmp <= i - 1; tmp++) {
//					if (max < NKzheng[tmp][j - 1])
//						max = NKzheng[tmp][j - 1];
//					if (min > NKfu[tmp][j - 1])
//						min = NKfu[tmp][j - 1];
//				}
//
//				if (max != LLONG_MIN) {
//					if (capacity[i] >= 0)
//						NKzheng[i][j] = max * capacity[i];
//					else
//						NKfu[i][j] = max * capacity[i];
//				}
//
//				if (min != LLONG_MAX) {
//					if (capacity[i] < 0 && NKzheng[i][j] < capacity[i] * min)
//						NKzheng[i][j] = min * capacity[i];
//					else if (NKfu[i][j] > min * capacity[i])
//						NKfu[i][j] = min * capacity[i];
//				}
//			}
//
//		long long max1 = LLONG_MIN;
//		long long max2 = LLONG_MIN;
//
//		for (int i = k; i <= n; i++)
//		{
//			if (max1 < NKzheng[i][k])
//				max1 = NKzheng[i][k];
//			if (max2 < NKfu[i][k] && NKfu[i][k] != LLONG_MAX)
//				max2 = NKfu[i][k];
//		}
//
//		long long max = max1 > max2 ? max1 : max2;
//		cout << max << endl;
//	}
//	system("pause");
//	return 0;
//}


class em {
public:
	em(int _id, int _hight, int _weight):
		id(_id), hight(_hight), weight(_weight)
	{}
	bool cmp(em a, em b)
	{
		if (a.weight != b.weight)
			return a.weight < b.weight;
		else return a.hight > b.hight;
	}
	int id;
	int hight;
	int weight;
};


int main()
{
	int n;
	while (cin >> n) {
		vector<em> table;
		for (int i = 0; i < n; i++)
		{
			int id, h, w;
			cin >> id >> w >> h;
			table.push_back(em(id, h, w));
		}
		sort(table.begin(), table.end(), em::cmp);

		vector<int> dp(n, 1);
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] + 1 > dp[i] && table[i].hight >= table[j].hight)
					dp[i] = dp[j] + 1;
			}
			if (dp[i] > max)
				max = dp[i];
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}