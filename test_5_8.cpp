#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void help(int n, int m, vector<int>& v, int beg) 
{    // m == 0 为递归结束条件. 此时 v 中可能已经包含了若干个元素了. 并且 v 中的内容就是一组结果.     
	if (m == 0) {        
		for (int i = 0; i<v.size(); i++) 
		{            
			// 这个 ? : 只是为了让结果的格式能够和要求一样.             
			i == 0 ? cout << v[i] : cout << " " << v[i];        
		} 
		cout << endl;
	}    
	for (int i = beg; i <= n&&i <= m; i++) 
	{        
		// 以下几行代码是该题目的关键. 问题的转换.         
		// 为了求 i -> n 有多少种情况和为 m, 则把问题转换为        
		// i + 1 -> n 有多少中情况和为 m - i        
		v.push_back(i);        
		help(n, m - i, v, i + 1);        
		v.pop_back();    
	} 
} 
int main() 
{    
	int n, m;    
	while (cin >> n >> m) {        
		vector<int>v;        
		help(n, m, v, 1);    
	} 
}



//int main()
//{
//	int n;
//	while (cin >> n) {
//		vector<string> accept(n);
//		for (int i = 0; i < n; i++)
//			cin >> accept[i];
//		set<string> tmp;
//		for (auto &e : accept)
//		{
//			string a = "";
//			for (int i = 0; i < e.size(); i++)
//			{
//				if (e[i] >= '0' && e[i] <= '9')
//					a += e[i];
//				else if (e[i] >= 'A' && e[i] <= 'C')
//					a += '2';
//				else if (e[i] >= 'D' && e[i] <= 'F')
//					a += '3';
//				else if (e[i] >= 'G' && e[i] <= 'I')
//					a += '4';
//				else if (e[i] >= 'J' && e[i] <= 'L')
//					a += '5';
//				else if (e[i] >= 'M' && e[i] <= 'O')
//					a += '6';
//				else if (e[i] >= 'P' && e[i] <= 'S')
//					a += '7';
//				else if (e[i] >= 'T' && e[i] <= 'V')
//					a += '8';
//				else if (e[i] >= 'W' && e[i] <= 'Z')
//					a += '9';
//			}
//			tmp.insert(a);
//		}
//		//vector<string> res;
//		//for (auto &e : tmp)
//		//	res.push_back(e);
//		//sort(res.begin(), res.end());
//
//		for (auto &e : tmp) {
//			cout << e.substr(0, 3) << '-' << e.substr(3, 4) << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	unordered_set<int> t = { 2,4,5,6,7,8,11 };
//	sort(t.begin(), t.end());
//	return 0;
//}