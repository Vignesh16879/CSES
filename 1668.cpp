#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;

ll n, m;
vectorg<ll> par[200000];
bool p, vis[200000], team[200000];

void dfs(ll u, ll k = 0)
{
    for(ll x : par[u])
        if(x != k)
            if(!vis[x])
            {
                team[x] = !team[u];
                vis[x] = true;
                dfs(x, u);
            } 
            else
                if(team[x] == team[u])
                    p = false;
}

void deleteElement(ll x)
{
    ll i;
    for (i = 0; i < n; i++)
        if (par[i] == par[x])
            break;
    
    if (i < n)
    {
        n--;
        for (ll j = i; j < n; j++)
            par[j] = par[j+1];
    }
}

void in()
{
    cin >> n >> m;

	for(ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		par[u].push_back(v);
	    par[v].push_back(u);
	}
}

void out()
{
    p = true;

    for(ll i = 1; i <= n; i++)
        if(!vis[i])
        {
            vis[i] = true;
            dfs(i);
        }

    if(!p)
        cout << "Imp" << "\n";
    else
    {    
        for(ll i = 1; i <= n; i++)
            if(!team[i])
                cout << "1 ";
            else
                cout << "2 ";

        cout << "\n";
    }
}

ll main()
{
    in();
    out();

    return 0;
}