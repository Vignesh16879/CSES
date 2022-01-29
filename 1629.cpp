#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main()
{   
    vector<pair<ll,ll>> v;
    ll n;
    cin >> n;
 
    for(ll i = 0; i < n; i++)
    {
        ll a, c;
        cin >> a >> c;
        v.push_back({c,a});
    }
 
    sort(v.begin(),v.end());
    ll curr = v[0].first;
    ll ans = 1;
       
    for(ll i=1;i<n;i++)
    {           
        if(v[i].second>=curr)
        {
        curr=v[i].first;
        ans++;
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}