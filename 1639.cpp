#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7;

int main()
{ 
    string str1, str2;
    getline(cin, str1); 
    getline(cin, str2);
    ll l1 = str1.length(), l2 = str2.length();
    ll dp[l1 + 1][l2 + 1];

    for(ll i = 0; i <= l1; i++)
        for(ll j = 0; j <= l2; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }

    cout << dp[l1][l2]  << "\n";
 
    return 0;
}