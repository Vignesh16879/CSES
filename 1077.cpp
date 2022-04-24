#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll mn = (ll) 2e5+5;

ll n, k, l, r;
ll arr[200001];
multiset<ll> up, low;

void insert_value(ll val)
{
	ll a = *low.rbegin();

	if(a < val)
    {
		up.insert(val); 
        r += val;
		
        if(up.size() > k/2)
        {
			ll mv = *up.begin();
			low.insert(mv); 
            l += mv;
			up.erase(up.find(mv)); 
            r -= mv;
		}
	}
	else
    {
		low.insert(val); 
        l += val;
		
        if(low.size() > (k + 1)/2)
        {
			ll mv = *low.rbegin();
			up.insert(*low.rbegin()); 
            r += mv;
			low.erase(low.find(*low.rbegin())); 
            l -= mv;
		}
	}
}

void erase_value(ll val)
{
	if(up.find(val) != up.end())
    { 
        up.erase(up.find(val)); 
        r -= val;
    }
	else 
    {
        low.erase(low.find(val)); 
        l -= val;
    }
	
    if(low.empty())
    {
		ll mv = *up.begin();
		low.insert(*up.begin()); 
        l += mv;
		up.erase(up.find(*up.begin())); 
        r -= mv;
	}
}

ll med()
{ 
    return (k % 2 == 0) ? 0 : (*low.rbegin()); 
}

int main() 
{
	cin >> n >> k;
	
    for(ll i = 0; i < n; i++) 
        cin >> arr[i];
	
    low.insert(arr[0]); 
    l += arr[0];
	
    for(ll i = 1; i < k; i++) 
        insert_value(arr[i]);
	
    cout << r - l + med(); if(n!=1) cout << " ";
	
    for(ll i = k; i < n; i++)
    {
		if(k == 1)
        {
			insert_value(arr[i]);
			erase_value(arr[i - k]);
		}
		else
        {
			erase_value(arr[i - k]);
			insert_value(arr[i]);
		}
		
        cout << r - l + med(); 
        
        if(i != n -1) 
            cout << " ";
	}

	cout << "\n";

    return 0;
}