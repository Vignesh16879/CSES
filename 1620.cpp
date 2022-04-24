#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    ll ans, m = *max_element(arr.begin(), arr.end());    
    ll l = 0, r = t* m + 1, mid, c;

    while(l <= r)   
    {
        mid = l + (r-l) / 2;
        c = 0;

        for(auto x : arr)
            c += mid / x;

        if(c >= t)
        {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }

    cout << ans << "\n";

    return 0;
}