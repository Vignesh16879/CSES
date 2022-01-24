#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main()
{
    ll n, m=0;
    cin >> n;
    vectorg<ll> x;

    for(ll i = 0; i < n; i++)
    {    
        ll z, lo = 0, hi = x.size(); 
        cin >> z;
		
        while(lo < hi) 
        {
			ll mid = (lo + hi) / 2;
			
            if(x[mid] > z) 
                hi = mid;
			else 
                lo = mid + 1;
		}
		
        if(lo == x.size()) 
            x.push_back(z);  
		else 
            x[lo] = z;
	}

	cout << x.size() << "\n";

    return 0;
}