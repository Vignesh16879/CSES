#include <bits/stdc++.h>

using namespace std;
 
#define ll long long

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
    vector<bool> cs(n), cn(n);

    for(ll i = 0; i < n; i++)
    {
        cin >> ran[i].l;
        cin >> ran[i].r;
        ran[i].index = i;
    }

    sort(ran.begin(), ran.end());

    for(ll i = 0; i < n; i++)
    {
        if(ran[i].r <= maxr)
            cn[ran[i].index] = true;

        maxr = max(maxr, ran[i].r);
    }

    for(ll i = n-1; i >= 0; i--)
    {
        if(ran[i].r >= minr)
            cs[ran[i].index] = true;

        minr = min(minr, ran[i].r);
    }

    for(ll i = 0; i < n; i++)
        cout << cs[i] << " ";

    cout << "\n";

    for(ll i = 0; i < n; i++)
        cout << cn[i] << " ";
 
    cout << "\n";
 
    return 0;
}