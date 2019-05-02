#define _CRT_SECURE_NO_WARNINGS 1

//Îå×ÓÆåÅÐ¶Ï
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool checkRow(vector<string> table, int i, int j)
//{
//	if (j < 2 || j > 17)
//		return false;
//	else if (table[i][j - 2] == table[i][j - 1] && table[i][j + 1] == table[i][j + 2]\
//		&& table[i][j] == table[i][j - 1] && table[i][j] == table[i][j + 1]\
//		&& (table[i][j] == '+' || table[i][j] == '*'))
//		return true;
//	else
//		return false;
//}
//bool checkCol(vector<string> table, int i, int j)
//{
//	if (i < 2 || i > 17)
//		return false;
//	else if (table[i - 2][j] == table[i - 1][j] && table[i + 1][j] == table[i + 2][j]\
//		&& table[i][j] == table[i + 1][j] && table[i][j] == table[i - 1][j]\
//		&& (table[i][j] == '+' || table[i][j] == '*'))
//		return true;
//	else
//		return false;
//}
//
//bool checkLeft(vector<string> table, int i, int j)
//{
//	if (i < 2 || i > 17 || j < 2 || j > 17)
//		return false;
//	else if (table[i - 2][j - 2] == table[i - 1][j - 1] && table[i + 1][j + 1] == table[i + 2][j + 2]\
//		&& table[i][j] == table[i + 1][j + 1] && table[i][j] == table[i - 1][j - 1]\
//		&& (table[i][j] == '+' || table[i][j] == '*'))
//		return true;
//	else
//		return false;
//}
//
//bool checkRight(vector<string> table, int i, int j)
//{
//	if (i < 2 || i > 17 || j < 2 || j > 17)
//		return false;
//	else if (table[i - 2][j + 2] == table[i - 1][j + 1] && table[i + 1][j - 1] == table[i + 2][j - 2]\
//		&& table[i][j] == table[i + 1][j - 1] && table[i][j] == table[i - 1][j + 1]\
//		&& (table[i][j] == '+' || table[i][j] == '*'))
//		return true;
//	else
//		return false;
//}
//
//bool check(vector<string> table)
//{
//	for(int i = 0; i < 20; i++)
//		for (int j = 0; j < 20; j++)
//		{
//			if (checkRow(table, i, j) || checkCol(table, i, j)\
//				|| checkLeft(table, i, j) || checkRight(table, i, j))
//				return true;
//		}
//	return false;
//}
//int main()
//{
//	vector<string> chess(20);
//	while (cin >> chess[0]) {
//		for(int i = 1; i < 20; i++)
//			cin >> chess[i];
//		cout << ((check(chess) == true) ? "Yes" : "No") << endl;
//	}
//	system("pause");
//	return 0;
//}


//Emacs¼ÆËãÆ÷ 
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		vector<string> tmp(n);
		stack<int> num;
		for (int i = 0; i < n; i++)
			cin >> tmp[i];
		for (int i = 0; i < n; i++) {
			if (tmp[i][0] >= '0' && tmp[i][0] <= '9')
				num.push(atoi(tmp[i].data()));
			else {
				int a = num.top();
				num.pop();
				int b = num.top();
				num.pop();
				switch (tmp[i][0]) {
					case '+': a += b; break;
					case '-': a -= b; break;
					case '*': a *= b; break;
					case '/':
						if (a == 0)
							return 0;
						else
							a = b / a; break;
				}
				num.push(a);
			}
		}
		cout << num.top() << endl;
	}
	system("pause");
	return 0;
}