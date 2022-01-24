#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll x, n, p; 
    set<ll> pos; 
    multiset<ll> dist;
    cin >> x >> n;
	pos.insert(0); 
    pos.insert(x);
	dist.insert(x);
	
    for (ll i = 1; i <= n; i++)
    {
		cin >> p;
		auto it1 = pos.upper_bound(p),it2 = it1; --it2;
		dist.erase(dist.find(*it1-*it2));
		dist.insert(p-*it2); 
        dist.insert(*it1-p);
		pos.insert(p);
		auto ans = dist.end(); 
        --ans;
		
        cout << *ans << " ";
	}

    cout << "\n";

    return 0;
}