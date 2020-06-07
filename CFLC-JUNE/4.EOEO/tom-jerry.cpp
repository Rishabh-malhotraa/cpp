#include <bits/stdc++.h>
#include <string>

using namespace std;

int gameplayed(long long js, long long ts)
{

	if (ts % 2 == 1)
	{
		if (js % 2 == 0)
			return 1;
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	//* for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//* for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int16_t t;
	cin >> t;
	while (t--)
	{
		long long ts, counter = 0;
		cin >> ts;

		//* If both TS and JS are even,dived 2.
		//* If both TS and JS are odd, a tie is declared and the game ends.
		//* If TS is even and JS is odd, Tom wins the game.
		//! If TS is odd and JS is even, Jerry wins the game.

		long long nts, njs;
		for (long long js = 2; js <= ts; js += 2)
		{
			njs = js;
			nts = ts;
			while (nts % 2 == 0 && njs % 2 == 0)
			{
				nts = nts / 2;
				njs = njs / 2;
			}

			counter += gameplayed(njs, nts);
		}
		cout << counter << endl;
	}
	return 0;
}
