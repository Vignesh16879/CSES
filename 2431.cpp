#include<bits/stdc++.h>

#define ll long long

using namespace std;


ll xpow(ll x, unsigned ll y)
{
    ll res = 1;

    while(y > 0)
    {
        if (y&1) res = (res * x); y = y >> 1; x = (x * x);
    }

    return res;
}


int main()
{
    ll q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        ll c = 1;

        for (ll p = 9;; a -= p, c++, p = 9*xpow(10, c-1)*c) 
        {
            if (a - p <= 0) 
                break;
        }

        a--;
        ll x = a / c;
        ll y = a % c;
        ll ans = xpow(10, c - 1) + x;
        string s = to_string(ans);

        cout << s[y] << "\n";
    }

    return 0;
}