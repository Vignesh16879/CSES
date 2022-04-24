#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7;
 
int main() 
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j <= x; j++)
            if(j - arr[i] >= 0)
            {
                dp[j] += dp[j - arr[i]];
                dp[j] %= f;
            }

    cout << dp[x] << "\n";

    return 0;
}