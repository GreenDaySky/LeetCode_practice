#define _CRT_SECURE_NO_WARNINGS 1

//最长公共子序列 可不连续
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	string a, b;
//	while (cin >> a >> b) {
//		vector<vector<int> > dp(a.size(), vector<int>(b.size(), 0));
//		dp[0][0] = a[0] == b[0] ? 1 : 0;
//		for (int i = 1; i < a.size(); i++) {
//			dp[i][0] = (a[i] == b[0]) ? 1 : 0;
//			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
//		}
//		for (int j = 1; j < b.size(); j++) {
//			dp[0][j] = (a[0] == b[j]) ? 1 : 0;
//			dp[0][j] = max(dp[0][j], dp[0][j - 1]);
//		}
//		for(int i = 1; i < a.size(); i++)
//			for (int j = 1; j < b.size(); j++) {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//				dp[i][j] = (a[i] == b[j]) ? max(dp[i - 1][j - 1] + 1, dp[i][j]) : dp[i][j];
//			}
//		cout << dp[a.size() - 1][b.size() - 1] << endl;
//	}
//	system("pause");
//	return 0;
//}


//错排
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<long long> tmp = {0, 0, 1};
//	int num;
//	for (int i = 3; i <= 22; i++)
//		tmp.push_back((i - 1) * (tmp[i - 1] + tmp[i - 2]));
//	while (cin >> num) {
//		cout << tmp[num] << endl;
//	}
//	system("pause");
//	return 0;
//}

//最大升序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n) {
		/*cin.ignore();*/
		vector<int> tmp(n);
		for (int i = 0; i < n; i++)
			cin >> tmp[i];
		vector<int> dp(n, 1);
		dp[0] = 1;
		int res = 1;
		for(int i = 1; i < n; i++)
			for (int j = 0; j < i; j++) {
				if (tmp[i] > tmp[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					res = max(res, dp[i]);
				}
			}
		cout << res << endl;
	}
	system("pause");
	return 0;
}