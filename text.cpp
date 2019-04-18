#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
//#include<math.h>
using namespace std;

//int distancePow(pair<int, int> x, pair<int, int> y)
//{
//	return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
//}
//
//int Count(int a)
//{
//	if (a == 2)
//		return 2;
//	return a * (a - 1);
//}
//
//int numberOfBoomerangs(vector<pair<int, int>>& points)
//{
//	int res = 0;
//	vector<vector<int>> tmp(points.size());
//	for (int i = 0; i < points.size(); i++)
//		for (int j = 0; j < points.size(); j++)
//			tmp[i].push_back(distancePow(points[i], points[j]));
//	for (auto & h : tmp) {
//		unordered_map<int, int> mymap;
//		for (auto & e : h)
//			mymap[e]++;
//		for (auto it = mymap.begin(); it != mymap.end(); it++)
//			res += Count(it->second);
//	}
//	return res;
//}


struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

//pair<double, double> slope(Point a, Point b)
//{
//	double m = (b.y - a.y) * 1.0 / (b.x - a.x);
//	double n = b.y - (1.0 * b.x) * m;
//	return{ m, n };
//}
//
//int maxPoints(vector<Point>& points)
//{
//	int res = 0;
//	unordered_map<pair<double, double>, int> mymap;
//	for (int i = 0; i < points.size(); i++)
//		for (int j = i + 1; j < points.size(); j++)
//			mymap[slope(points[i], points[j])]++;
//	for (auto it = mymap.begin(); it != mymap.end(); it++)
//	{
//		res = max(res, it->second);
//	}
//	return res;
//}

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int maxPoints(vector<Point>& points) {
	int res = 0;
	for (int i = 0; i < points.size(); ++i) {
		map<pair<int, int>, int> m;
		int duplicate = 1;
		for (int j = i + 1; j < points.size(); ++j) {
			if (points[i].x == points[j].x && points[i].y == points[j].y) {
				++duplicate; continue;
			}
			int dx = points[j].x - points[i].x;
			int dy = points[j].y - points[i].y;
			int d = gcd(dx, dy);
			++m[{dx / d, dy / d}];
		}
		res = max(res, duplicate);
		for (auto it = m.begin(); it != m.end(); ++it) {
			res = max(res, it->second + duplicate);
		}
	}
	return res;
}

int main()
{
	vector<Point> arr = { {1, 1}, {2, 2}, {3, 3} };
	cout << maxPoints(arr) << endl;
	system("pause");
	return 0;
}