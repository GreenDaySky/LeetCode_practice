#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m) {
		int k;
		cin >> k;
		vector<vector<int> > table(n + 1, vector<int>(m + 1));
		vector<vector<double> > P(n + 1, vector<double>(m + 1));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			table[x][y] = 1;
		}
		P[1][1] = 1.0;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (!(i == 1 && j == 1)) {
					P[i][j] = P[i][j - 1] * (i == n ? 1 : 0.5) \
						+ P[i - 1][j] * (j == m ? 1 : 0.5);
					if (table[i][j] == 1)
						P[i][j] = 0;
				}
			}
		}
		cout << fixed << setprecision(2) << P[n][m] << endl;
	}
	return 0;
}