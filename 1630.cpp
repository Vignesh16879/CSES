#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());
    ll m = 0, c = 0;

    for(auto x : arr)
    {
        c += x.first;
        m += x.second - c;
    }

    cout << m << "\n";

    return 0;
}