#define _CRT_SECURE_NO_WARNINGS 1

//include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;

#if 0
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	vector<int> tmp(4);
	sort(nums.begin(), nums.end());
	size_t n = nums.size();
	if (nums.size() < 4)
		return vector<vector<int>>(res.begin(), res.end());;
	for (int i = 0; i < n - 3; i++)
	{
		tmp[0] = nums[i];
		for (int j = i + 1; j < n - 2; j++)
		{
			tmp[1] = nums[j];
			int gap = target - nums[i] - nums[j];
			int t = j + 1;
			int k = n - 1;
			while (t < k) {
				if (gap == nums[k] + nums[t]) {
					tmp[2] = nums[t];
					tmp[3] = nums[k];
					res.push_back(tmp);
					while (k > 2 && nums[k] == nums[k - 1])
						k--;
					while (t + 1 < n - 1 && nums[t] == nums[t + 1])
						t++;
					k--;
					t++;
				}
				else {
					if (gap > nums[k] + nums[t])
						t++;
					else
						k--;
				}
			}
			while (j < n - 2 && nums[j] == nums[j + 1])
				j++;
		}
		while (i < n - 3 && nums[i] == nums[i + 1])
			i++;
	}
	return res;
}



int main()
{
	vector<int> tmp = { -1,0,1,2,-2,0 };
	vector<vector<int>> res = fourSum(tmp, 0);
	for (auto & e : res)
	{
		for (auto & h : e)
			cout << h << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}



//int main()
//{
//	int n;
//	long long a[22] = { 0,0,1 };
//	long long b[22] = { 0,1,2 };
//	for (int i = 3; i < 21; i++) {
//		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
//		b[i] = i * b[i - 1];
//	}
//	while (cin >> n) {
//		printf("%.2f%%\n",a[n] * 100.0 / b[n] );
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	vector<long long> a(22,0);
//	a = { 0,0,1 };
//	vector<long long> b(22,0); 
//	b = { 0,1,2 };
//	for (int i = 3; i < 22; i++) {
//		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
//		b[i] = i * b[i - 1];
//		/*a.push_back((i - 1) * (a[i - 1] + a[i - 2]));
//		b.push_back(i * b[i - 1]);*/
//	}
//	while (cin >> n) {
//		printf("%.2f%%\n", a[n] * 100.0 / b[n]);
//	}
//	return 0;
//}


//
//#include<vector>
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string str;
//	int n;
//	getline(cin, str);
//	cin >> n;
//	int len = str.size();
//	//定义结果字符串首尾的位置
//	int rb = 0;
//	int re = 0;
//	vector<int> arr;
//	//把数值传入数组
//	for (auto & e : str)
//		arr.push_back(e - '0');
//
//	//初始化累加数值
//	for (int i = 1; i < len; i++)
//		arr[i] += arr[i - 1];
//
//	for (int i = 0; i < len - (re - rb); i++)
//	{
//		//将字符串头向后移动
//		if (i > 0) {
//			for (int k = i; k < len; k++)
//				arr[k] = arr[k] - arr[i - 1];
//		}
//
//		//定义以该头为起点的临时头尾位置
//		int b = i;
//		int e = i;
//		for (int j = i; j < len; j++)
//		{
//			if (arr[j] == n) {
//				if (j > e)
//					e = j;
//			}
//		}
//		//比较长短选择长的作为最终结果
//		if (e - b > re - rb) {
//			re = e;
//			rb = b;
//		}
//	}
//	cout << str.substr(rb, re - rb + 1) << endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
//int main()
//{
//	string a = "abcde";
//	string b = "aaaaa";
//	string c = "abcde";
//	cout << (a == b) << endl;
//	cout << (a == c) << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	string str;
	string s;
	while(1) {
		getline(cin, str);
		getline(cin, s);
		unordered_set<string> arr;
		int b = 0;
		int e = 0;
		while (b  < str.size()) {
			if (str[b] == '"') {
				e = str.find('"', b + 1);
				cout << str.substr(b + 1, e - b - 1) << endl;
				arr.insert(str.substr(b + 1, e - b - 1));
				b = e + 2;
			}
			else {
				e = str.find(',', b);
				if (e == string::npos)
				{
					cout << str.substr(b, str.size() - b) << endl;
					arr.insert(str.substr(b, str.size() - b));
					b = str.size();
				}
				else {
					cout << str.substr(b, e - b) << endl;
					arr.insert(str.substr(b, e - b));
					b = e + 1;
				}
			}
		}
		if (find(arr.begin(), arr.end(), s) != arr.end())
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	system("pause");
	return 0;
}



#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
//{
//	int res = 0;
//	unordered_map<int, int> ABmap;
//	for(int i = 0; i < A.size(); i++)
//		for (int j = 0; j < B.size(); j++)
//			ABmap[A[i] + B[j]]++;
//	for (int i = 0; i < C.size(); i++)
//		for (int j = 0; j < D.size(); j++)
//			res = res + ABmap[-(C[i] + D[j])];
//	return res;
//}



vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>> res;
	unordered_map<string, int> map;
	int index = 0;
	for (int i = 0; i < strs.size(); i++) {
		string tmp = strs[i];
		sort(tmp.begin(), tmp.end());
		if (map.find(tmp) == map.end()) {
			map[tmp] = index;
			index++;
			res.push_back(vector<string>{});
		}
		res[map[tmp]].push_back(strs[i]);
	}
	return res;
}


int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = groupAnagrams(strs);
	for (auto & e : res) {
		for (auto & h : e) {
			for (auto & r : h)
				cout << r;
			cout << ' ';
		}
		cout << endl;
	}
	/*vector<vector<string> > a = { {"abc","asd"},{"aaa","bbb"},{"bbb"} };
	for (auto & e : a) {
		for (auto & h : e) {
			for (auto & r : h)
				cout << r;
			cout << ' ';
		}
		cout << endl;
	}*/
	system("pause");
	return 0;
}
#endif

#include<vector>
#include<utility>
#include<iostream>
using namespace std;

int distancePow(int aX, int aY, int bX, int bY)
{
	return 0;
}

int numberOfBoomerangs(vector<pair<int, int>>& points) 
{
	return 0;
}