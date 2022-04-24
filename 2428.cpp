#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    map<ll, ll> mp;
    ll l = 0, r = 0, c = 0, ans = 0;

    while(l < n) 
    {
        while(r < n && c + (mp[arr[r]] == 0) <= k) 
        {
            mp[arr[r]]++; 
            c += (mp[arr[r]] == 1);
            r++; 
        }

        ans += r - l;
        c -= (mp[arr[l]] == 1);
        mp[arr[l]]--; 
        l++;
    }

    cout << ans << "\n";

    return 0;
} 