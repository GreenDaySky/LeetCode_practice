#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool Func(string in, string out)
{
	stack<int> tmp;
	int t = 0;
	for (int i = 0; i < out.size(); i++)
	{
		int n =  in.find(out[i]);
		if (n > t) {
			for (int j = t; j < n; j++)
				tmp.push(in[i]);
			t = n + 1;
		}
		else if (n <= t)
		{
			if (tmp.empty()) {
				t++;
			}
			else if (out[i] == tmp.top()) {
				tmp.pop();
			}
			else {
				return false;
			}
		}
	}
	return true;
}
int main()
{
	string a = "ABCDEF";
	string b = "ADCEFB";
	cout << Func(a, b) << endl;
	system("pause");
	return 0;
}