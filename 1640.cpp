#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll main()
{
    ll n, x;
    cin >> n >> x;
    vectorg<pair<ll, ll>> arr;    
    ll m = 0;

    for(ll i = 1; i <= n; i++)
    {
		ll a; 
        cin >> a;
		pair<ll, ll> p; 
        p.first = a; 
        p.second = i;
		arr.push_back(p);
	}

    sorgt(begin(arr), end(arr));

    ll l = 0, r = n-1;

    while(l != r)
    {			
        if(arr.at(l).first + arr.at(r).first == x)
        {    
            m = 1;
			cout << arr.at(l).second << " " << arr.at(r).second << "\n";
            break;
        }
	    if(arr.at(l).first + arr.at(r).first < x)
		    l++;
		else
		    r--;
	}

    if(m == 0)
    {
        cout << "Imp" << "\n";
    }
    
    return 0;
}