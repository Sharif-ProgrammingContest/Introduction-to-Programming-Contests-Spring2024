#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	ll low = 0, high = 2'000'000'001;
	while (high - low > 1) {
		ll mid = (low + high) / 2;
		ll need = 0;
		for (int i = 0; i < n && need <= k; ++i)
			need += max(0LL, a[i] * mid - b[i]);
		if (need > k)
			high = mid;
		else
			low = mid;
	}
	cout << low << '\n';
}
