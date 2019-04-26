#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;

#if 0
int main()
{
	vector<string> res;

	string s;
	int i = 0;
	int count = 0;
	getline(cin, s);
	while (i < s.size()) {
		string tmp;
		while (s[i] != ' ' && i < s.size()) {
			if (s[i] == '"') {
				tmp += s[i];
				i++;
				while (s[i] != '"' && i < s.size()) {
					tmp += s[i];
					i++;
				}
			}
			if (i < s.size()) {
				tmp += s[i];
				i++;
			}
		}
		res.push_back(tmp);
		count++;
		i++;
	}
	cout << count << endl;
	for (auto& e : res)
		cout << e << endl;
	system("pause");
	return 0;
}

#endif

//int main()
//{
//	int a = 1;
//	char *p = (char*)&a;
//	if (*p == 1) {
//		cout << "little";
//	}
//	else {
//		cout << "big";
//	}
//	system("pause");
//	return 0;
//}


int main()
{
	union tmp {
		char a;
		int i;
	}t;
	t.i = 1;
	if (t.a == 1) {
		cout << "little";
	}
	else {
		cout << "big";
	}
	system("pause");
	return 0;
}











