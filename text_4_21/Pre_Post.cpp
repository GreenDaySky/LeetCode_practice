#define _CRT_SECURE_NO_WARNINGS 1

//输入m叉树的前序遍历和后序遍历
//输出该数的层序遍历结果有多少种

//比如    abejkcfghid     jkebfghicda 
//找到先序序列的第一个节点和后序序列的最后一个节点，这个节点就是当前的根节点 
//当前的根→a bejk  cfghi  d         jkeb  fghic  d a                                                    
//找到3个区间，说明这一层有三颗子树
//
//#include<vector>
//#include<iostream>
//#include<unordered_map>
//#include<math.h>
//#include<string>
//using namespace std;
//
//
////求C（k， m）的值
//int mCk(int m, int k)
//{
//	int M = 1;
//	int K = 1;
//	for (int i = 2; i <= k; i++) 
//		K *= i;
//	for (int i = 0; i < k; m--, i++)
//		M *= m;
//	return M / K;
//}
//
//int Count(int preS, int preE, int postS, int postE, unordered_map<char, int> postMap, string pre, string post, int m, int res)
//{
//	if (preS >= preE)
//		return;
//	int i = preS + 1;
//	int cnt = 0;
//	int idex = postMap[pre[i]];
//	while (i < preE) {
//		Count(i, i + idex - postS, postS, idex, postMap, pre, post);
//		cnt++;
//		if (idex != postE - 1) {
//			i += idex - postS + 1;
//			postS = idex + 1;
//			idex = postMap[pre[i]];
//		}
//		else
//			break;
//	}
//	res *= mCk(m, cnt);
//}
//
//int main()
//{
//	int m;
//	while (cin >> m) {
//		int res = 1;
//		string pre, post;
//		unordered_map<char, int> postMap;
//		getline(cin, pre);
//		getline(cin, post);
//		for (int i = 0; i < post.size(); i++)
//			postMap[post[i]] = i;
//		Count(0, pre.size() - 1, 0, post.size() - 1, postMap, pre, post, m, res);
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}

