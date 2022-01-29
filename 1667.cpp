#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll n, m, k, d[200000], p[200000];
vector<ll> par[200000];
vector<bool> vis;
vector<ll> ans;
 
void bfs()
{
    vis[1] = true;
	queue<ll> q;
	q.push(1);
	
    while(!q.empty())
	{
		int u = q.front();
		q.pop();
	
    	for(auto x: par[u])
			if(!vis[x])
			{
				d[x] = d[u]+1;
                vis[x] = true;
                p[x] = u;
                q.push(x);
			}
	} 
}
 
void in()
{
    cin >> n >> m;
	vis.resize(n);
 
    for(ll i = 0; i < n; i++)
        vis[i] = false;
 
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
    bfs();
 
    if(!vis[n])
        cout << "IMPOSSIBLE" << "\n";
    else
    {
        ll u = n;
        k = d[n];
        ans.resize(k+1);
 
        for(ll i = k; i >= 0; i--)
        {
            ans[i] = u;
            u = p[u];
        }
 
        cout << k+1 << "\n";
 
        for(ll i = 0; i <= k; i++)
            cout << ans[i] << " ";
 
        cout << "\n";
    }    
}
 
int main()
{
    in();
    out();
 
    return 0;
}