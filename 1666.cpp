#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll n, m;
vector<ll> par[200000];
vector<bool> vis;
 
void dfs(ll i)
{
    if(!vis[i])
    {    
        vis[i] = true;    
        
        for(auto x: par[i])
            dfs(x);
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
    vector<ll> ans;
    ll k = 0;
    dfs(k);
 
    for(ll i = 1; i <= n; i++)
        if(!vis[i])
        {
            ans.push_back(i);
            dfs(i);
        }
 
    cout << ans.size()-1 << "\n";
 
    for(int i = 1; i < ans.size(); i++)
        cout << ans[i-1] << " " << ans[i] << "\n";
    
}
 
int main()
{
    in();
    out();
 
    return 0;
}