#define _CRT_SECURE_NO_WARNINGS 1

//����m������ǰ������ͺ������
//��������Ĳ����������ж�����

//����    abejkcfghid     jkebfghicda 
//�ҵ��������еĵ�һ���ڵ�ͺ������е����һ���ڵ㣬����ڵ���ǵ�ǰ�ĸ��ڵ� 
//��ǰ�ĸ���a bejk  cfghi  d         jkeb  fghic  d a                                                    
//�ҵ�3�����䣬˵����һ������������
//
//#include<vector>
//#include<iostream>
//#include<unordered_map>
//#include<math.h>
//#include<string>
//using namespace std;
//
//
////��C��k�� m����ֵ
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

