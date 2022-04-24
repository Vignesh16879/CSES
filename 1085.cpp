#include <bits/stdc++.h>

#define ll unsigned long long
using namespace std;

int main()
{
    ll n, k, ans = 0, ms = 0;
    cin >> n >> k;
    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
    {    
        cin >> arr[i];
        ms += arr[i];
    }

    ll l = 0, h = ms;

	auto works = [&] (ll mid) 
    {
		ll g = 0, s = 0;
		
        for(ll i = 0; i < n; i++) 
        {
			if (arr[i] > mid) 
				return false;

			if(s + arr[i] > mid) 
            {
				g++;
				s = 0;
			}

			s += arr[i];
		}

		if(s > 0) 
			g++;
		
        return g <= k;
	};
    
	while (l <= h) 
    {
		ll mid = (l + h) / 2;
		
        if(works(mid)) 
        {
			h = mid - 1;
			ans = mid;
		}
		else 
			l = mid + 1;
	}

    cout << ans << "\n";

    return 0;
}
