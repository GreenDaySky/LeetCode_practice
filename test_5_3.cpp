#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string accept;
//	while (getline(cin, accept)) {
//		int len = accept.size();
//		string res = "";
//		for (int i = 0; i < len; i++)
//		{
//			if (accept[i] <= '9' && accept[i] >= '0')
//				res += accept[i];
//		}
//		cout << res << endl;
//	}
//		return 0;
//}



//int min;
//void minDis(vector<string> table, int y, int x, int dis)
//{
//	if (y == 9 && x == 8) {
//		if (dis == 0 || dis < min)
//			min = dis;
//	}
//	//вС
//	if (x > 1 && table[y][x - 1] == '.')
//		minDis(table, y, x - 1, dis + 1);
//	//ср
//	if (x < 8 && table[y][x + 1] == '.')
//		minDis(table, y, x + 1, dis + 1);
//	//ио
//	if (y > 1 && table[y - 1][x] == '.')
//		minDis(table, y - 1, x, dis + 1);
//	//об
//	if (y < 8 && table[y + 1][x] == '.')
//		minDis(table, y + 1, x, dis + 1);
//
//}




#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct pos { int x, y, num; };


int bfs(vector<vector<char> > table)
{
	const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	queue<pos> que;
	int m = table.size();
	int n = table[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));

	pos start{ 0, 1, 0 };
	pos end{ 9, 8, 0 };

	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty()) {
		pos cur = que.front();
		pos next;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.num = cur.num + 1;
			if (next.x == end.x && next.y == end.y)
				return next.num;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && table[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}

int main()
{
	vector<vector<char> > table(10, vector<char>(10));
	while (cin >> table[0][0]) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else
					cin >> table[i][j];
			}
		cout << bfs(table) << endl;
	}
	return 0;
}

