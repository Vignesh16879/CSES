#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7;

ll n, m, ans = 0, arr[100001];
vector<vector<ll> > dp(100001, vector<ll>(101, 0));    

int main()
{ 
    cin >> n >> m;

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    if(arr[0] == 0) 
        fill(dp[0].begin(), dp[0].end(), 1);
    else
        dp[0][arr[0]] = 1;

    for(ll i = 1; i < n; i++) 
    {
        if(arr[i] == 0) 
            for(ll j = 1; j <= m; j++) 
            {
                dp[i][j] += dp[i-1][j];
                
                if(j - 1 > 0) 
                    dp[i][j] += dp[i-1][j-1];
                
                if(j + 1 <= m) 
                    dp[i][j] += dp[i-1][j+1];
                
                dp[i][j] %= f;
            }
        else 
        {
            dp[i][arr[i]] += dp[i-1][arr[i]];

            if(arr[i] - 1 > 0) 
                dp[i][arr[i]] += dp[i-1][arr[i]-1];
            
            if(arr[i] + 1 <= m) 
                dp[i][arr[i]] += dp[i-1][arr[i]+1];
            
            dp[i][arr[i]] %= f;
        }
	}    
    
    for (ll i = 1; i <= m; i++)
    {
        ans += dp[n-1][i] % f;
        ans %= f;
    }
 
    cout << ans << "\n";
 
    return 0;
}