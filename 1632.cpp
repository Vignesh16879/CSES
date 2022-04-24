#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.second < b.second;
}

int main()
{
    ll n, k, c = 0;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), cmp);
    set<pair<ll, ll>> e;

    for(ll i = 0; i < n; i++) 
    {
        if(e.size() == 0)
            e.insert({arr[i].second*-1, i});
        else 
        {
            auto it = e.lower_bound({arr[i].first*-1, -1});

            if(it != e.end()) 
            {
                e.erase(it);
                e.insert({arr[i].second*-1,i});
            }
            else if(it == e.end() && e.size() < k)
                e.insert({arr[i].second*-1, i});
            else
                c++;
        }
    }

    cout << n-c << "\n";

    return 0;
}