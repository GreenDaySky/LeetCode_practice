#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		vector<string> accept(n);
		for (int i = 0; i < n; i++)
			cin >> accept[i];
		unordered_map<string, vector<string>> dict;
		for (auto &e : accept) {
			string t = e;
			sort(t.begin(), t.end());
			dict[t].push_back(e);
		}
		string str;
		int num;
		cin >> str >> num;
		
		string tmp = str;
		sort(tmp.begin(), tmp.end());
		sort(dict[tmp].begin(), dict[tmp].end());

		find(accept.begin(), accept.end(), str) == accept.end() ?
			cout << dict[tmp].size() << endl : cout << dict[tmp].size() - 1 << endl;
		
		int n = 0;
		for (auto &e : dict[tmp])
		{
			if (e != str)
				n++;
			if (n == num) {	
				cout << e << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}



//int main()
//{
//	int n;
//	while (cin >> n) {
//		vector<string> accept(n);
//		cin.ignore();
//		for (int i = 0; i < n; i++)
//			cin >> accept[i];
//		unordered_map<string, int> dict;
//		for (auto &e : accept) {
//			string t = e;
//			sort(t.begin(), t.end());
//			dict[t]++;
//		}
//
//		sort(dict.begin(), dict.end());
//
//		string str;
//		cin >> str;
//
//		string tmp = str;
//		sort(tmp.begin(), tmp.end());
//
//		int num;
//		cin >> num;
//
//		int n = 0;
//		for (auto &e : accept) {
//			string t = e;
//			sort(t.begin(), t.end());
//			if (e != str && t == tmp)
//				n++;
//			if (n == num)
//			{
//				cout << dict[tmp] - 1 << endl;
//				cout << e << endl;
//				break;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	string a, b;
//	while (cin >> a >> b) {
//		unordered_map<char, int> mapA;
//		unordered_map<char, int> mapB;
//		bool flag = true;
//		for (auto &e : a)
//			mapA[e]++;
//		for (auto &e : b)
//			mapB[e]++;
//		for (auto &e : b)
//			if (mapA.find(e) == mapA.end()||& mapB[e] > mapA[e])
//			{
//				cout << "No" << endl;
//				flag = false;
//				break;
//			}
//		if (flag) {
//			cout << "Yes" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string str;
//	while (getline(cin, str)) {
//		vector<string> res;
//		int b = 0;
//		while (b < str.size()) {
//			int e = b;
//			while ((str[e] >= 'a' && str[e] <= 'z') || (str[e] >= 'A' && str[e] <= 'Z') && e < str.size())
//				e++;
//			if (e - b > 0)
//				res.push_back(str.substr(b, e - b));
//			b = e + 1;
//		}
//		reverse(res.begin(), res.end());
//		for (int i = 0; i < res.size(); i++)
//		{
//			cout << res[i];
//			i == res.size() - 1 ? (cout << endl) : cout << " ";
//		}
//	}
//	system("pause");
//	return 0;
//}




//int main()
//{
//	string str;
//	while (getline(cin ,str)) {
//		reverse(str.begin(), str.end());
//		
//		int b = 0;
//		int e = 0;
//		
//		while (b < str.size())
//		{
//			e = b;
//			while ((str[e] >= 'a' && str[e] <= 'z') || (str[e] >= 'A' && str[e] <= 'Z') && e < str.size())
//				e++;
//			if (e - b > 1) {
//				reverse(str.begin() + b, str.begin() + e);
//			}
//				b = e + 1;
//		}
//		cout << str << endl;
//	}
//
//	system("pause");
//	return 0;
//}



//int main()
//{
//	string str;
//	while (cin >> str) {
//		string res = "";
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == '_')
//			{
//				str[i + 1] -= ('a' - 'A');
//				continue;
//			}
//			else
//				res += str[i];
//
//		}
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}