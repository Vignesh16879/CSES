#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
    ll n;
    cin >> n;
    vector<ll> p;
    
    for(int i = 1; i <= n; i++) 
        p.push_back(i);
 
    while(p.size() > 1)
    {
        vector<ll> temp;

        for(ll i = 0; i < p.size(); i++)
            if(i%2 == 1)
                cout << p[i] << " ";
            else
                temp.push_back(p[i]);

        if(p.size() % 2 == 0)
            p = temp;
        else
        {
            ll x = temp.back();
            temp.pop_back();
            p.clear();
            p.push_back(x);

            for(ll y : temp)
                p.push_back(y);
        }
    }
 
    cout << p[0] << "\n";
 
    return 0;
}