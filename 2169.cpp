#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class range
{
    public:
        ll l, r, index;

    bool operator < (const range &other) const
    {
        if(l == other.l)
            return r > other.r;

        return l < other.l;
    }
};

int main()
{
    ll n, maxr = 0, minr = LLONG_MAX;
    cin >> n;
    vector<range> ran(n);
    vector<ll> cs(n), cn(n);
    ordered_set rbr;

    for(ll i = 0; i < n; i++)
    {
        cin >> ran[i].l;
        cin >> ran[i].r;
        ran[i].index = i;
    }

    sort(ran.begin(), ran.end());

    for(ll i = 0; i < n; i++)
    {
        rbr.insert({ran[i].r, -1*i});
        cn[ran[i].index] = rbr.size() - rbr.order_of_key({ran[i].r, -1*i}) - 1;
    }

    rbr.clear();

    for(ll i = n-1; i >= 0; i--)
    {
        rbr.insert({ran[i].r, -1*i});
        cs[ran[i].index] = rbr.order_of_key({ran[i].r, -1*i});
    }

    for(ll i = 0; i < n; i++)
        cout << cs[i] << " ";

    cout << "\n";

    for(ll i = 0; i < n; i++)
        cout << cn[i] << " ";
 
    cout << "\n";
 
    return 0;
}