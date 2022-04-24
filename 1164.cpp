#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> arr;

    for(ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, 0, i});
        arr.push_back({b, 1, i});
    }

    sort(arr.begin(), arr.end());

    ll c = 0;
    vector<ll> av, ans(n);

    for(auto [x, y, i] : arr)
        if(y == 0)
        {
            c++;

            if(av.empty())
                ans[i] = c;
            else
            {
                ans[i] = av.back();
                av.pop_back();
            }
        }
        else
        {
            c--;
            av.push_back(ans[i]);
        }

    cout << *max_element(ans.begin(), ans.begin() + n) << "\n";

    for(ll i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;
}