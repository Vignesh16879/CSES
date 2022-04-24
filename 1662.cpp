#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    ll n, s = 0, ans = 0;
    cin >> n;
    unordered_map<ll, ll> mp;
    mp[0] = 1;

    for(ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s = (s + a) % n;

        while(s < 0)
            s += n;

        if(mp.find(s) != mp.end())
            ans += mp[s];

        mp[s]++;
    }

    cout << ans << "\n";

    return 0;
}