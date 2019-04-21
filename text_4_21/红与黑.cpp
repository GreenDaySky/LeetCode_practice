#define _CRT_SECURE_NO_WARNINGS 1

//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
////- 黑色 # 白色 @ 所在位置
//
//int res;
//void Func(int x, int y, vector<string> &map, int m, int n)
//{
//	if (map[x][y] == '.') {
//		res++;
//		map[x][y] = '@';
//	}
//	else
//		return;
//	if (x + 1 < m)
//		Func(x + 1, y, map, m, n);
//	if (x - 1 >= 0)
//		Func(x - 1, y, map, m, n);
//	if (y + 1 < n)
//		Func(x, y + 1, map, m, n);
//	if (y - 1 >= 0)
//		Func(x, y - 1, map, m, n);
//}
//
//int main()
//{
//	int m, n;
//	while (cin >> m >> n) {
//		cin.ignore();
//		res = 0;
//		vector<string> map(m);
//		for (int i = 0; i < m; i++)
//			getline(cin, map[i]);
//		int x, y;
//		for (int i = 0; i < m; i++)
//			if (map[i].find('@') != string::npos) {
//				x = i;
//				y = map[i].find('@');
//				map[x][y] = '.';
//				break;
//			}
//		Func(x, y, map, m, n);
//		cout << res << endl;
//	}
//}