#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7, mL = 5000;

ll n, dp[500005];

int main()
{
    cin >> n;

    if(n % 4 != 0 && n % 4 != 3)
    {    
        cout << "0" << "\n"; 
        return 0;
    }

    vector<ll> v;
    ll s = (n + 1) * n / 4;
    dp[0] = 1;

    for(ll i = 1; i < n; i++)
        v.push_back(i);

    for(ll i = 0; i < n - 1; i++)
        for(ll j = s; j > 0; j--)
            if(j - v[i] >= 0)
                (dp[j] += dp[j - v[i]]) %= f;

    cout << dp[s] << "\n";
 
    return 0;
}