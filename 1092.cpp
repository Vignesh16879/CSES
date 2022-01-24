#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;

    if(s % 2 == 0 && s > 2)
    {
        cout << "YES\n";
        vector<ll> set1, set2;
        ll m = s / 2;

        for(ll i = n; i > 0; i--)
        {
            if(m >= i)
            {
                set1.push_back(i);
                m -= i;
            }
            else
            {
                set2.push_back(i);
            }
        }

        cout << set1.size() << "\n";

        for(ll i = 0; i < set1.size(); i++)
        {
            cout << set1[i] << " ";
        }

        cout << "\n";
        cout << set2.size() << "\n";

        for(ll i = 0; i < set2.size(); i++)
        {
            cout << set2[i] << " ";
        }
    }
    else
    {
        cout << "nO";
    }

    cout << "\n";

    return 0;
}