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

int minJumpsUtil(vector<int> &arr, int pos, vector<int> memo, vector<bool> &visited)
{
	if (pos == arr.size() - 1)
		return 0;
	if (pos >= arr.size() || pos < 0)
		return 0;
	if (visited[pos] == true)
		return 0;

	visited[pos] = true;

	int el = arr[pos];

	vector<int>::iterator it = find(arr.begin() + pos, arr.end(), el);

	if (memo[pos])
		return memo[pos];

	if (it != arr.end())
	{
		memo[pos] = 1 + min(min(minJumpsUtil(arr, pos - 1, memo, visited), minJumpsUtil(arr, pos + 1, memo, visited)), minJumpsUtil(arr, distance(arr.begin(), it), memo, visited));
	}
	else
	{
		memo[pos] = 1 + min(minJumpsUtil(arr, pos - 1, memo, visited), minJumpsUtil(arr, pos + 1, memo, visited));
	}

	return memo[pos];
}

int minJumps(vector<int> &arr)
{
	// cam we use the sweep technique?
	// 100--23--23--404--100--23--23--23--3--404
	int n = arr.size();
	vector<bool> visited(n, false);
	vector<int> memo(n, 0);
	return minJumpsUtil(arr, 0, memo, visited);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << minJumps(arr) << endl;
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