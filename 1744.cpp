#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7, mL = 1e9;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll dp [505][505];

    if(a > b)
        swap(a, b);

    for(ll i = 0; i <= max(a, b) + 1; i++)
        dp[i][i] = 0;

    for(ll i = 1; i <= a; i++) 
    {
        for(ll j = i + 1; j <= b; j++)
        {
            dp[i][j] = mL;

            for(ll k = 1; k < j; k++)   
            {          
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }

            for(ll k = 1; k < i; k++)
            {             
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }

            dp[j][i] = dp[i][j]; 
        }
    }

    cout << dp[a][b] << "\n";

    return 0;
}