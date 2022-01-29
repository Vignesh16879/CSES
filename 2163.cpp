#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 
using namespace std;
 
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    ll n, k, m = 0;
    cin >> n >> k;
    ordered_set p;
    
    for(ll i = 1; i <= n; i++) 
        p.insert(i);

    while(p.size() > 0)
    {
        m %= p.size();
        ll r = (m+k) % p.size();
        m = r;
        auto t = p.find_by_order(r);
        cout << *t << " ";
        p.erase(t);    
    }
 
    cout << "\n";
 
    return 0;
}