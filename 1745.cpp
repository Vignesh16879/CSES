#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
const ll f = (ll) 1e9 + 7, mL = 1e9;
 
ll dp[100005];

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    vector<ll> ans;
 
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
 
    ll s = accumulate(arr, arr + n, 0LL);
    dp[0] = 1;
 
    for(ll i = 0; i < n; i++)
        for(ll j = s + 1; j > 0; j--)
        {
            if(arr[i] == j)
                dp[j] = 1;
            
            if(arr[i] <= j)
                dp[j] = dp[j] | dp[j-arr[i]];
        }
    
    for(ll i = 1; i < s + 1; i++)
        if(dp[i])
            ans.push_back(i);
 
    cout << ans.size() << "\n";
 
    for(auto x : ans)
        cout << x << " ";
 
    cout << "\n";
 
    return 0;
}