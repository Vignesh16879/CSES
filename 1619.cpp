#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;

ll main()
{
	ll n;
    cin >> n;
    vectorg<pair<ll,bool>> v;
    ll x, y;
 
    for(ll i = 0; i < n; i++)
    {
    	cin >> x >> y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	
    sorgt(v.begin(),v.end());
   	ll ans =0, maxx =0;
   	
    for(ll i = 0; i < n+n; i++)
   		if(v[i].second == true)
        {
   			ans++;
   			maxx = max(ans, maxx);
   		}
        else
   			ans--;
 
   	cout << maxx << "\n";
 
	return 0;
}