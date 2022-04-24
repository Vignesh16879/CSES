#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n, m, d[100000], vis[100000], dis[100000];
vector<pair<ll, ll>> par[100000];
 
void dij()
{
    for(ll i = 2; i < n+1; i++)
        dis[i] = LLONG_MAX;
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
 
    while(!q.empty())
    {
        ll u = q.top().second;
        q.pop();
 
        if(vis[u])
            continue;
 
        vis[u] = 1;
 
        for(pair<ll, ll> x : par[u])
            if(dis[x.first] > dis[u]+x.second)
            {
                dis[x.first] = dis[u]+x.second;
                q.push({dis[x.first], x.first});
            }
    }    
}
 
void sd()
{
    cin >> n >> m;
 
	for(ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		par[a].push_back({b, c});
	}

    dij();
 
    for(ll i = 1; i < n+1; i++)
        cout << dis[i] << " ";
}
 
int main()
{
    sd();
 
    cout << "\n";
 
    return 0;
}