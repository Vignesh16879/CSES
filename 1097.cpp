#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7, mL = 5000;

ll n, x[mL + 1], p[mL + 1], dp[mL + 1][mL + 1];

ll sl(ll l, ll r)
{
    if(dp[l][r])
        return dp[l][r];

    if(l == r)
        return x[l];

    return dp[l][r] = max(x[l] + p[r] - p[l] - sl(l + 1, r), x[r] + p[r - 1] - p[l - 1] - sl(l, r - 1));
}

int main()
{
    cin >> n;

    for(ll i = 1; i <= n; i++)
    {
        cin >> x[i];
        p[i] = p[i-1] + x[i];;
    }
 
    cout << sl(1, n) << "\n";
 
    return 0;
}