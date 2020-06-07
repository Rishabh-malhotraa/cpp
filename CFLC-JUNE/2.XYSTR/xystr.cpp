#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		// so  for cin string space is the terminating
		// character so we use getlin for multi worded inputs
		string s;
		cin >> s;
		int count = 0;
		int len = s.length();
		char str[len];
		strcpy(str, s.c_str());

		bool flag[len];
		for (int i = 0; i < len; i++)
		{
			flag[i] == false;
		}

		for (int i = 1; i < len; i++)
		{
			if (str[i] == 'x' && flag[i] == false)
			{
				if (str[i - 1] == 'y' && flag[i - 1] == false)
				{
					count++;
					flag[i] = true;
					flag[i - 1] = true;
				}
			}
			else if (str[i] == 'y' && flag[i] == false)
			{
				if (str[i - 1] == 'x' && flag[i - 1] == false)
				{
					count++;
					flag[i] = true;
					flag[i - 1] = true;
				}
			}
		}

		cout << count << endl;
	}
	return 0;
}