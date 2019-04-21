#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n) {
//		cin.ignore();
//		vector<string> accept(n);
//		vector<bool> flag(n, true);
//		for (int i = 0; i < n; i++)
//			getline(cin, accept[i]);
//		sort(accept.begin(), accept.end());
//		for (int i = 0; i < accept.size() - 1; i++) {
//			if (accept[i] == accept[i + 1])
//				flag[i] = false;
//			else if (accept[i].size() < accept[i + 1].size()\
//				&& accept[i] == accept[i + 1].substr(0, accept[i].size())\
//				&& accept[i + 1][accept[i].size()] == '/')
//				flag[i] = false;
//		}
//		for (int i = 0; i < accept.size(); i++)
//			if (flag[i])
//				cout << "mkdir -p " << accept[i] << endl;
//		cout << endl;
//	}
//	return 0;
//}