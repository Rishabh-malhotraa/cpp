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
        int n, price, temp, org = 0, newP = 0;
        cin >> n >> price;
        vector<int> v;
        while (n--)
        {
            cin >> temp;
            v.push_back(temp);
            if (temp >= price)
            {
                org += temp;
                newP += price;
            }
            else
            {
                org += price;
                newP += price;
            }
        }
        int loss = org - newP;
        cout << loss << endl;
    }
    return 0;
}