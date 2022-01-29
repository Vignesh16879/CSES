#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
 
ll n, m, sx, sy, ex, ey;
vector<vector<pair<ll,ll>>> path;
vector<vector<bool>> vis;
vector<pair<ll,ll>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
 
bool isValid(ll x, ll y)
{
	if(x < 0 or x >= n or y < 0 or y >= m)
		return false;
	if(vis[x][y])
		return false;
	
    return true;
}
 
void bfs()
{
	queue<pair<ll,ll>> q;
	q.push({sx,sy});
	
    while(!q.empty())
	{
		ll cx = q.front().first;
		ll cy = q.front().second;
		q.pop();
		
        for(auto x: moves)
		{
			ll mvx = x.first;
			ll mvy = x.second;
			
            if(isValid(cx+mvx, cy+mvy))
			{
				q.push({cx+mvx, cy+mvy});
				vis[cx+mvx][cy+mvy] = true;
				path[cx+mvx][cy+mvy] = {mvx,mvy};
			}
		}
	}
}
 
void in()
{
    cin >> n >> m;
	path.resize(n);
	vis.resize(n);
	
    for(ll i = 0; i < n; ++i)
	{
		path[i].resize(m);
		vis[i].resize(m);
	}
	
    for (ll i = 0; i < n; ++i)
		for (ll j = 0; j < m; ++j)
		{
			path[i][j] = {-1,-1};
			char x; 
            cin >> x;
			
            if(x == '#')
				vis[i][j] = true;
			if(x == 'A')
			{	
                sx = i; 
                sy = j;
            }
			if(x == 'B')
			{	
                ex = i; 
                ey = j;
            }
		}
}
 
void out()
{
    bfs();
 
	if(!vis[ex][ey])
		cout << "NO" << "\n";
	else
    {	
        cout << "YES" << "\n";
    
        vector<pair<ll,ll>> ans;
        pair<ll,ll> end = {ex,ey};
    
        while(end.first != sx or end.second != sy)
        {
            ans.push_back(path[end.first][end.second]);
            end.first -= ans.back().first;
            end.second -= ans.back().second;	
        }
    
        reverse(ans.begin(), ans.end());
        
        cout << ans.size() << "\n";
        
        for(auto c: ans)
            if(c.first == 1 and c.second ==0)
                cout << 'D';
            else if(c.first == -1 and c.second ==0)
                cout << 'U';
            else if(c.first == 0 and c.second == 1)
                cout << 'R';
            else if(c.first == 0 and c.second == -1)
                cout << 'L';
    }
}
 
int main()
{
    in();
    out();
 
    return 0;
}