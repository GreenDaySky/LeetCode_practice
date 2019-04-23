#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	string a, b;
	int len1, len2;
	while (cin >> a >> b >> len1 >> len2) {
		int count = 0;
		a.append(len2 - a.size(), 'a');
		b.append(len2 - b.size(), 'a');
		vector<int> tmp(len2);
		for (int i = 0; i < len2; i++)
			tmp.push_back(b[i] - a[i]);
		for (int i = len1; i <= len2; i++)
			for (int j = 0; j < i; j++)
				count += tmp[j] * pow(26, i - j - 1);
		cout << count - 1<< endl;
		}
	return 0;
}