#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, k;
ll arr[200001];
multiset<ll> up;
multiset<ll> low;

void insert_value(ll val)
{ 
	ll a = *low.rbegin(); // current median
	if(a < val)
    {
		up.insert(val);

		if(up.size() > k/2)
        {
			low.insert(*up.begin());
			up.erase(up.find(*up.begin()));
		}
	}
	else
    {
		low.insert(val);
	
    	if(low.size() > (k + 1)/2)
        {
			up.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}

void erase_value(ll val)
{ 
	if(up.find(val) != up.end()) 
        up.erase(up.find(val));
	else 
        low.erase(low.find(val));
	
    if(low.empty())
    {
		low.insert(*up.begin());
		up.erase(up.find(*up.begin()));
	}
}

int main() 
{
	cin >> n >> k;
	
    for(ll i = 0; i < n; i++) 
        cin >> arr[i];
	
    low.insert(arr[0]); 
    
    for(ll i = 1; i < k; i++) 
        insert_value(arr[i]);
	
    cout << *low.rbegin() << " ";
	
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
		
        cout << *low.rbegin() << " ";
	}
	
    cout << "\n";

    return 0;
}

// int main()
// {
//     ll n, k;
//     cin >> n >> k;
//     vector<ll> arr(n);

//     for(ll i = 0; i < n; i++)
//         cin >> arr[i];

//     priority_queue<pair<ll, ll>> l;
//     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > r;
//     ll m = (k + 1) / 2, b = 0;

//     for(ll i = 0; i < n; i++)
//     {
//         while(!r.empty() && r.top().second <= i-k)
//             r.pop();
        
//         while(!l.empty() && l.top().second <= i-k)
//             l.pop();

//         if(b < m)
//         {
//             l.push({arr[i], i});
//             l.push(r.top());
//             r.pop();
//         }
//         else
//         {
//             l.push({arr[i], i});
//             r.push(l.top());
//             l.pop();
//         }

//         while(!r.empty() && r.top().second <= i-k)
//             r.pop();
        
//         while(!l.empty() && l.top().second <= i-k)
//             l.pop();

//         if(i < k-1) 
//             continue;
        
//         cout << l.top().first << " ";
        
//         if(arr[i - k + 1] <= l.top().first) 
//             b--;
//     }

//     cout << "\n";

//     return 0;
// } 