#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7, mN = (ll) 1e6;

ll t, n, dp[mN + 1];

int main()
{ 
    cin >> t;
    dp[1] = 2, dp[2] = 8;

    for(ll i = 3; i <= mN; i++)
        dp[i] = ((6 * dp[i - 1] - 7 * dp[i - 2]) % f + f) % f;

    while(t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }

    cout << "\n";
 
    return 0;
}