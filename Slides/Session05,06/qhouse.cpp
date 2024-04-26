#include <bits/stdc++.h>
using namespace std;

const int MAX_C = 15;

bool ask(int x, int y) {
	cout << x << ' ' << y << endl;
	string ans;
	cin >> ans;
	return ans == "YES";
}

int calc_square_edge_length() {
	int low = 0, high = MAX_C;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (ask(mid, 0))
			low = mid;
		else
			high = mid;
	}
	return low * 2;
}

int calc_triangle_edge_length(int y) {
	int low = 0, high = MAX_C;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (ask(mid, y))
			low = mid;
		else
			high = mid;
	}
	return low * 2;
}

int calc_height() {
	int low = 0, high = MAX_C;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (ask(0, mid))
			low = mid;
		else
			high = mid;
	}
	return low;
}

int main() {
	int a = calc_square_edge_length();
	int h = calc_height();
	int t = calc_triangle_edge_length(a);
	cout << "! " << a * a + t * (h - a) / 2 << endl;
}
