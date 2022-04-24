#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    ll n, x, c = 0, ans = 0;
    cin >> n >> x;
    vector<ll> arr(n + 1);
    map<ll, ll> psum;
    psum[0] = 1;

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    for (ll i = 0; i < n; i++)
    {
        c += arr[i];

        if (psum.find(c - x) != psum.end())
            ans += psum[c - x];

        psum[c]++;
    }

    cout << ans << "\n";

    return 0;
}