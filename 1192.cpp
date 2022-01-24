#include <bits/stdc++.h>
 
#define ll ll
 
using namespace std;
 
 
vectorg<vectorg<bool>> vis;
vectorg<pair<ll, ll>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll n, m, c = 0;
 
bool isvalid(ll x, ll y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(vis[x][y])
        return false;
 
    return true;
}
 
void dfs(ll i, ll j)
{
    vis[i][j] = true;
 
    for(auto x: moves)
        if(isvalid(i+x.first, j+x.second))
            dfs(i+x.first, j+x.second);
}
 
void in()
{
    cin >> n >> m;
    vis.resize(n);
 
    for(ll i = 0; i < n; i++)
        vis[i].resize(m);
 
    for(ll i = 0; i < n; i++)         
        for(ll j = 0; j < m; j++)
        {
            char x;
            cin >> x;
 
            if(x == '#')
                vis[i][j] = true;
        }
}
 
void out()
{
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(!vis[i][j])
            {
                dfs(i, j);
                ++c;
            }
 
    cout << c << "\n";
}
 
ll main()
{
    in();
    out();
    
    return 0;
}