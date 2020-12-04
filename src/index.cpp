#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pnl cout << endl
#define deb(x) cout << #x << " " << x << endl;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEMSET(x) memset(x, 0, sizeof x)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

int maxProfit(vector<int> &prices)
{
	int n = prices.size();
	pair<int, int> dp[n];

	// now do the dp trick from starting --> end
	dp[0].first = 0;
	dp[n - 1].second = 0;

	int min = prices[0];
	for (int i = 1; i < n; i++)
	{
		min = std::min(min, prices[i]);
		int profitToday = prices[i] - min;
		dp[i].first = max(dp[i].first, profitToday);
	}

	int max = prices[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		max = std::max(max, prices[i]);
		int profitToday = max - prices[i];
		dp[i].second = std::max(dp[i + 1].second, profitToday);
	}
	int sum = INT_MIN;
	for (int i = 0; i < n; i++)
		sum = std::max(sum, dp[i].first + dp[i].second);

	return sum;
}

void solve()
{
	int n;

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxProfit(arr) << endl;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}