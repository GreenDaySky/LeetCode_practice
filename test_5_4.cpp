#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode {
public:
	TreeNode(int _val)
		:left(nullptr)
		,right(nullptr)
		,val(_val)
	{}
	TreeNode* left; 
	TreeNode* right;
	int val;
};

void printTreeMid(TreeNode* root)
{
	if (root == nullptr)
		return;
	printTreeMid(root->left);
	cout << root->val << endl;
	printTreeMid(root->right);

}

TreeNode* createTree(vector<int> arr, size_t n,int start)
{
	TreeNode *cur = new TreeNode(arr[start]);
	if ((2 * start + 1) < n)
		cur->left = createTree(arr, n, 2 * start + 1);
	else
		cur->left = nullptr;
	if ((2 * start + 2) < n)
		cur->right = createTree(arr, n, 2 * start + 2);
	else
		cur->right = nullptr;
	return cur;
}

int main()
{
	vector<int> a = { 5, 3, 7, 2, 4, 6, 8 };
	size_t size = a.size();
	TreeNode *root = createTree(a, size, 0);
	printTreeMid(root);
	system("pause");
	return 0;
}





#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool* flag = new bool[rows*cols];
		for (int i = 0; i<rows*cols; i++)
			flag[i] = false;
		int count = moving(threshold, rows, cols, 0, 0, flag);//从（0,0）坐标开始访问;
		delete[] flag;
		return count;
	}
	//计算最大移动位置
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		int count = 0;
		if (check(threshold, rows, cols, i, j, flag))
		{
			flag[i*cols + j] = true;
			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
			//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
			count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag)
				+ moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}
	//检查当前位置是否可以访问
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i<rows && j >= 0 && j<cols
			&& getSum(i) + getSum(j) <= threshold
			&& flag[i*cols + j] == false)
			return true;
		return false;
	}
	//计算位置的数值
	int getSum(int number)
	{
		int sum = 0;
		while (number>0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};

class Func {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<bool> flag;
		for (int i = 0; i < rows * cols; i++)
			flag.push_back(false);
		int num = Count(threshold, rows, cols, 0, 0, flag);
		return num;
	}
	 int Count(int threshold, int rows, int cols, int i, int j, vector<bool>& flag)
	{
		int count = 0;
		if (isOK(threshold, rows, cols, i, j, flag))
		{
			flag[i * cols + j] = true;
			count = 1 + Count(threshold, rows, cols, i + 1, j, flag)
				+ Count(threshold, rows, cols, i - 1, j, flag)
				+ Count(threshold, rows, cols, i, j + 1, flag)
				+ Count(threshold, rows, cols, i, j - 1, flag);
		}
		return count;
	}

	bool isOK(int threshold, int rows, int cols, int i, int j, vector<bool> flag)
	{
		if (i < rows && i >= 0 && j < cols && j >= 0
			&&flag[i * cols + j] == false 
			&& getNum(i) + getNum(j) <= threshold)
			return true;
		return false;
	}
	int getNum(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}
};


int main()
{
	Func a;
	Solution b;
	cout << b.movingCount(7, 3, 3) << endl;
	cout << a.movingCount(7, 3, 3) <<endl;
	system("pause");
	return 0;
}



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getValue(vector<int> gifts, int n) {
	int num;
	sort(gifts.begin(), gifts.end());
	num = gifts[(n + 1) / 2];
	vector<int>::iterator it = find(gifts.begin(), gifts.end(), num);

}


int main()
{
	vector<int> arr = { 1 ,2, 2, 2, 2, 2, 4, 5 };
	cout << getValue(arr, arr.size()) << endl;
	system("pause");
	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int num = gifts[(n + 1) / 2];
		int count = 0;
		for (auto &e : gifts) {
			if (e == num)
				count++;
		}
		if (count > (n / 2))
			return num;
		else
			return 0;
	}
};

int main()
{
	vector<int> array = { 45, 33, 11, 32, 32, 32 };
	Gift a;
	cout << a.getValue(array, array.size()) << endl;
	system("pause");
	return 0;
}



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int calStringDistance(string a, string b)
{
	int row = a.size();
	int col = b.size();
	int **dp = new int*[row + 1];
	for (int i = 0; i < row + 1; i++)
		dp[i] = new int[col + 1]();
	dp[0][0] = 0;
	for (int i = 1; i < row + 1; i++)
		dp[i][0] = i;
	for (int i = 1; i < col + 1; i++)
		dp[0][i] = i;
	for(int i = 1; i < row + 1; i++)
		for (int j = 1; j < col + 1; j++) {
			if (a[i - 1] == b[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + 1;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
	return dp[row][col];
}

int main()
{
	string a, b;
	while (getline(cin, a) && getline(cin, b))
		cout << calStringDistance(a, b) << endl;
	return 0;
}




#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N, M;
vector<vector<int> > best_path;
vector<vector<int> > tmp_path;
vector<vector<int> > maze;

void MazeTrack(int m, int n)
{
	maze[m][n] = 1;
	tmp_path.push_back({m, n});
	if (m == N - 1 && n == M - 1)
		if (best_path.empty()||tmp_path.size() < best_path.size())
			best_path = tmp_path;

	if (m - 1 >= 0 && maze[m - 1][n] == 0)
		MazeTrack(m - 1, n);
	if (m + 1 < N && maze[m + 1][n] == 0)
		MazeTrack(m + 1, n);
	if (n + 1 < M && maze[m][n + 1] == 0)
		MazeTrack(m, n + 1);
	if (n - 1 >= 0 && maze[m][n - 1] == 0)
		MazeTrack(m, n - 1);

	maze[m][n] = 0;
	tmp_path.pop_back();
}



int main()
{
	while (cin >> N >> M) {
		maze = vector<vector<int> >(N, vector<int>(M,0));
		for (auto &i : maze)
			for (auto &j : i)
				cin >> j;
		best_path.clear();
		tmp_path.clear();
		MazeTrack(0, 0);
		for (auto &e : best_path)
			cout << "(" << e[0] << "," << e[1] << ")" << endl;
	}
	return 0;
}





#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n = 0;
	vector<vector<int> > arr;
	arr = vector<vector<int> >(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
		Func(arr[i]);
}

#include<iostream>
#include<vector>
using namespace std;
void Func(vector<int> arr)
{
	int tmp;
	int D = arr[3];
	int C = arr[2];
	int B = arr[1];
	int A = arr[0];
	if (C < A) 
	{
		tmp = A - C;
		if (B % 2 == 0)
			cout << (D + C + B / 2 + tmp / 4) << endl;
		if (tmp >= 2)
			cout << (D + C + B / 2 + 1 + (tmp - 2) / 4);
		else
			cout << (D + C + B / 2) << endl;
	}
	else 
		cout << (D + A + B / 2) << endl;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int> > arr;
	arr = vector<vector<int> >(n, vector<int>(4));
	for (auto &i : arr)
		for (auto &j : i)
			cin >> j;
	for(auto &e:arr)
		Func(e);
	system("pause");
	return 0;
}

#endif

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void Func(vector<int> &s, vector<int> handle)
{
	if (handle[0] == 0) {
		sort(s[0], s[handle[2] - 1]);
	}
	else {
		sort(s[0], s[handle[2] - 1]);
		reverse(s[0], s[handle[2] - 1]);
	}
}


int main()
{
	int m, n;
	cin >> n >> m;
	vector<int> s;
	vector<vector<int> > arr;
	arr = vector<vector<int> >(m, vector<int>(2));
	for (auto &e : arr)
		Func(s, e);

}



