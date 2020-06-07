#include <bits/stdc++.h>
#include <string>

using namespace std;

void print(int n, vector<int> arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " -> " << arr[i] << endl;
	}
}

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
		int n, temp;
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i += 1)
		{
			cin >> temp;
			v.push_back(temp);
		}
		int bank = 0;
		int price = 5;
		vector<int>::iterator i;
		bool res = true;
		int change = 0;
		int coin5 = 0, coin10 = 0, coin15 = 0;
		for (i = v.begin(); i < v.end(); i++)
		{
			change = *i - price;
			if (bank - change >= 0)
			{

				if (change == 0)
				{
					bank = bank + price;
					coin5++;
				}
				else if (change == 5)
				{
					if (coin5)
					{
						bank += price;
						coin10++;
						coin5--;
					}
					else
					{
						res = false;
						break;
					}
				}
				else if (change == 10)
				{
					if (coin10)
					{
						bank += price;
						coin15++;
						coin10--;
						// bank = bank - 15;
					}
					else if (coin5 > 2)
					{
						bank += price;
						coin15++;
						coin5 -= 2;
						// bank = bank - 15;
					}
					else
					{
						res = false;
						break;
					}
				}
			}
			else
			{
				res = false;
				break;
			}
		}
		if (res)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}