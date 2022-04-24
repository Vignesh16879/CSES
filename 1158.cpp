#include <bits/stdc++.h>
 
#define ll int
using namespace std;
 
int main()
{
    ll n, x;
    cin >> n >> x;
 
    vector<ll> page(n), price(n);
 
    for(ll i = 0; i < n; i++)
        cin >> price[i];
 
    for(ll i = 0; i < n; i++)
        cin >> page[i];
 
    vector<vector<ll>> dp(n+1);
    vector<ll> temp(x + 1, 0);

    for(ll i = 0; i < n+1; i++)
        dp[i] = vector<ll> (x + 1, 0);
 
    for(ll i = 1; i <= n; i++)
        for(ll j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
 
            if (j >= price[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]); 
        }
 
    cout << dp[n][x] << "\n";
 
    return 0;
}