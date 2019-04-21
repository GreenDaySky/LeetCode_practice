//#define _CRT_SECURE_NO_WARNINGS 1
//
////https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_set>
//using namespace std;
//int mian()
//{
//	int n;
//	while (cin >> n) {
//		vector<string> accept(n);
//		unordered_set<char> tmp;
//		int res = 0;
//		int t = 0;
//		for (int i = 0; i < n; i++) 
//			getline(cin, accept[i]);
//		for (auto & e : accept) {
//			if (e[2] == 'c') {
//				tmp.insert(e[0]);
//				t++;
//				res = max(t, res);
//			}
//			else if (e[2] == 'd') {
//				tmp.erase(e[0]);
//				t--;
//			}
//		}
//		cout << res << endl;
//	}
//}