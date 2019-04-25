#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n) {
//		string res;
//		for (int i = 0; i < n; i++) {
//			string tmp;
//			getline(cin, tmp);
//			res = res + tmp;
//		}
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	for (int i = 0; i < 3; i++) {
//		string str;
//		getline(cin, str);
//		cout << str << endl;
//	}
//	system("pause");
//	return 0;
//	
//}

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//{
//	unordered_set<int> tmp;
//	for (auto & e : nums1) {
//		if (find(nums2.begin(), nums2.end(), e) != nums2.end())
//			tmp.insert(e);
//		}
//}



unordered_set<int> arr;
bool isHappy(int n) 
{
	if (n == 1)
		return true;
	if (arr.find(n) == arr.end())
		arr.insert(n);
	else
		return false;
	int tmp = 0;
	while (n) {
		tmp = tmp + pow(n % 10, 2);
		n = n / 10;
	}
	isHappy(tmp);
}
bool ishappy(int n)
{
	unordered_set<int> list;
	while (n != 1) {
		int t = 0;
		while (n) {
			t =  t +(n % 10) * (n % 10);
			n = n / 10;
		}
		if (t == 1)
			return true;
		else if (list.find(t) == list.end())
			list.insert(t);
		else
			return false;
		n = t;
	}
}


#include<algorithm>

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	auto s1 = nums1;
	auto s2 = nums2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	vector<int> res;
	int gap = 0;
	for (auto & e : s1) {
		if (gap = find(s2.begin() + gap, s2.end(), e) != s2.end())
		{
			gap = gap + 1;
			res.push_back(e);
		}
	}
	return res;
}

int main()
{

}
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool isIsomorphic(string s, string t) {
	unordered_map<char, char> tmp;
	int i = 0;
	for (auto & e : s) {
		if (tmp.find(e) == tmp.end())
		{
			tmp[e] = t[i];
		}
		else {
			if (tmp[e] != t[i])
				return false;
		}
		i++;
	}
	unordered_set<char> arr;
	for (auto & e : s)
		arr.insert(tmp[e]);
	if (arr.size() == tmp.size())
		return true;
	return false;
}

#include<algorithm>
string frequencySort(string s) {
	string res;
	unordered_map<char, int> arr;
	unordered_set<char> single;
	for (auto & e : s) {
		arr[e]++;
		single.insert(e);
	}
	vector<int> path;
	for (auto & e : single)
		path.push_back(arr[e]);
	sort(path.begin(), path.end());
	for (int i = path.size() - 1; i >= 0; i--) {
		for (auto & e : single) {
			if (arr[e] == path[i]) {
				for (int j = 0; j < path[i]; j++)
					res = res + e;
			}
			single.erase(e);
			break;
		}
	}
	return res;
}

int main()
{
	string str = frequencySort("aaaaaaaadddddsssssss");
	cout << str << endl;
	system("pause");
	return 0;
}


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
//bool compare(pair<char, int> a, pair<char, int> b)
//{
//	return a.second > b.second;
//}
//string frequencySort(string s)
//{
//	string res;
//	unordered_map<char, int> arr;
//	for (auto & e : s) {
//		arr[e]++;
//	}
//	vector<pair<char, int>> tmp;
//	for (auto it = arr.begin(); it != arr.end(); it++) {
//		tmp.push_back(make_pair(it->first, it->second));
//	}
//	sort(tmp.begin(), tmp.end(), compare);
//	for (auto & e : tmp) {
//		for (int i = 0; i < e.second; i++)
//			res += e.first;
//	}
//	return res;
//}
struct node {
	char flag;
	int num;
	friend bool operator<(const node a, const node b)
	{
		return a.num < b.num;
	}
	node(char a, int b):flag(a), num(b){}
};

string frequencySort(string s)
{
	string res;
	unordered_map<char, int> arr;
	priority_queue<node> tmp;
	for (auto & e : s) 
		arr[e]++;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		tmp.push(node(it->first, it->second));
	}
	while (!tmp.empty()) {
		node t = tmp.top();
		for (int i = 0; i < t.num; i++)
			res += t.flag;
		tmp.pop();
	}
	return res;
}

int main()
{
	string str = frequencySort("aaaaaaaadddddsssssss");
	cout << str << endl;
	system("pause");
	return 0;
}


#endif

//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<unordered_set>
//using namespace std;
//
//int res = 0;
//
//struct node {
//	int left;
//	int right;
//	node(int x, int y):left(x), right(y){}
//};
//
//bool compare(node a, node b)
//{
//	return (a.right - a.left) < (b.right < b.left);
//}
//
//bool isOK(node a, unordered_set<int> &range)
//{
//	for (int i = a.left; i <= a.right; i++)
//	{
//		if (range.find(i) != range.end())
//			return false;
//	}
//	for (int i = a.left; i <= a.right; i++)
//	{
//		range.insert(i);
//	}
//	return true;
//}
//int value(vector<node> arr)
//{
//	int tmp;
//	unordered_set<int> range;
//	sort(arr.begin(), arr.end(), compare);
//	for(int i = 0; i < arr.size(); i++)
//	{
//		if (isOK(arr[i], range))
//			tmp++;
//	}
//	return tmp;
//}
//
//void Func(vector<string> s, string str, int n, vector<node> &arr)
//{
//	int num;
//	if (n == s.size())
//	{
//		num = value(arr);
//		if (num > res)
//			res = num;
//	}
//	int pos = 0;
//	while (pos = find(str.begin() + pos, str.end(), s[n]) != str.end())
//	{
//		arr.push_back(node(pos, pos + s[n].size()));
//		Func(s, str, n + 1, arr);
//	}
//}
//
//int main()
//{
//	int m;
//	while (cin >> m) {
//		cin.ignore();
//		vector<string> s(m);
//		string str;
//		vector<node> arr;
//		for (int i = 0; i < m; i++)
//			getline(cin, s[i]);
//		getline(cin, str);
//		Func(s, str, 0, arr);
//	}
//	system("pause");
//	return 0;
//}

//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
//void cal_next(string str, vector<int> &next)
//{
//	int k = -1;
//	next[0] = -1;
//	for (int i = 0; i < str.size(); i++)
//	{
//		while (k > -1 && str[k + 1] != str[i])
//			k = next[k];
//		if (str[k + 1] == str[i])
//			k++;
//		next[i] = k;
//	}
//}
//int KMP(string str, string ptr)
//{
//	vector<int> next(ptr.size());
//	cal_next(ptr, next);
//	int k = -1;
//	for (int i = 0; i < str.size(); i++)
//	{
//		while (k > -1 && ptr[k + 1] != str[i])
//			k = next[k];
//		if (ptr[k + 1] == str[i])
//			k++;
//		if (k == ptr.size() - 1)
//			return (i - ptr.size() + 1);
//	}
//}
//
//int main()
//{
//	cout << KMP("abcdef", "d") << endl;
//	system("pause");
//	return 0;
//}



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//vector<int> twoSum(vector<int>& nums, int target) 
//{
//	vector<int> res(2);
//	for (int i = 0; i < nums.size(); i++) {
//		for (int j = 0; j < nums.size(); j++) {
//			if (nums[i] + nums[j] == target && i != j) {
//				res[0] = i;
//				res[1] = j;
//				return res;
//			}
//		}
//	}
//}

#if 0

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res(2);
	for(int i = 0; i < nums.size(); i++)
	{
		auto pos = nums.begin();
		while (find(pos, nums.end(), target - nums[i]) != nums.end()) {
			pos = find(pos, nums.end(), target - nums[i]) + 1;
			if ((pos - 1) != nums.begin() + i) {
				res[0] = i;
				res[1] = pos - 1 - nums.begin();
				return res;
			}
		}
	}
}

int main()
{
	vector<int> tmp = { 2, 7 ,11, 15 };
	vector<int> res = twoSum(tmp, 18);
	for (auto & e : res)
		cout << e << endl;
	system("pause");
	return 0;
}
#endif

//vector<vector<int>> threeSum(vector<int>& nums) 
//{
//	vector<vector<int>> res;
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size() - 2; i++) {
//		int j = i + 1;
//		int k = nums.size() - 1;
//		while (j < k) {
//			if (nums[i] + nums[j] + nums[k] < 0)
//				j++;
//			else if (nums[i] + nums[j] + nums[k] > 0)
//				k--;
//			else {
//				res.push_back( {nums[i], nums[j], nums[k]} );
//				while (nums[j] == nums[j + 1])
//					j++;
//				j++;
//			}
//		}
//		while (nums[i] == nums[i + 1])
//			i++;
//	}
//	return res;
//}

//vector< vector<int> > threeSum(vector<int> &num) {
//	vector<int> numSet(3);
//	vector< vector<int> > r;
//	// 1.排序
//	sort(num.begin(), num.end());
//	int sum;
//	int len = num.size();
//	// 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
//	for (int i = 0; i < len - 2; i++) {
//		sum = 0 - num[i];
//		numSet[0] = num[i];
//		// 3.两数和问题
//		for (int j = i + 1, k = len - 1; j < k;) {
//			if (num[j] + num[k] == sum) {
//				numSet[1] = num[j++];
//				numSet[2] = num[k--];
//				r.push_back(numSet);
//				// 根据题目要求，跳过重复元素
//				while (j < k && num[j] == num[j - 1])
//					j++;
//				while (j < k && num[k] == num[k + 1])
//					k--;
//			}
//			else if (num[j] + num[k] < sum)
//				j++;
//			else
//				k--;
//		}
//		while (i < len - 2 && num[i + 1] == num[i])
//			i++;
//	}
//	return r;
//}


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	vector<int> tmp(4);
	sort(nums.begin(), nums.end());
	size_t n = nums.size();
	if (nums.size() == 0)
		return res;
	for (int i = 0; i < n - 3; i++)
	{
		tmp[0] = i;
		for (int j = i + 1; j < n - 2; j++)
		{
			tmp[1] = j;
			int gap = target - nums[i] - nums[j];
			int t = j + 1;
			int k = n - 1;
			while (t < k) {
				if (gap = nums[k] + nums[t]) {
					tmp[2] = t;
					tmp[3] = k;
					res.push_back(tmp);
					while (k > 2 && nums[k] == nums[k - 1])
						k--;
					while (t + 1 < n - 1 && nums[t] == nums[t + 1])
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
	vector<int> tmp = { -1,0,1,2,-2 };
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
