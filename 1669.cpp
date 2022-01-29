#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll n, m;
ll sv, ev;
vector<vector<ll>> g;
vector<ll> vis;
vector<ll> par;
 
 
bool dfs(ll u, ll p)
{
	vis[u] = true;
	par[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(vis[v]) 
		{
			sv = v; 
			ev = u; 
			return true;
		} 
		if(!vis[v]) 
			if(dfs(v,u)) 
				return true;
	}
	return false;
}
 
bool visit_all()
{
	for(ll i = 1; i <= n; ++i)
		if(!vis[i])
			if(dfs(i,-1)) 
            return true;
	
    return false;
}
 
void in()
{
    cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);
	
    for(ll i =0 ; i < m; ++i)
	{
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
 
void out()
{
    if(!visit_all())
		cout << "IMPOSSIBLE" << "\n";
    else
    {       
        ll tv = ev;
        vector<ll> ans;
        ans.push_back(ev);
        
        while(tv != sv)
        {
            ans.push_back(par[tv]);
            tv = par[tv];
        }
        
        ans.push_back(ev);
        cout << ans.size() << "\n";
        
        for(auto c: ans)
            cout << c << " ";
    }
}
 
int main()
{
    in();
    out();
 
    return 0;
}