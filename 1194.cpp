#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;

ll n, m, x, y, nex[1000][1000], fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', 'L'};
queue<pair<ll,ll>> q;
vector<string> grid;

void in()
{
    cin >> n >> m;
    
    for(ll i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        grid.push_back(x);
    }
        
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                q.push({i,j});
            else if (grid[i][j] == 'A')
                x = i, y = j;
    
    q.push({x,y});
    nex[x][y] = -1;
}

void out()
{
    ll temp = 0;

    while(!q.empty()) 
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1)) 
        {
            cout << "YES" << "\n";
            string ans;
            ll d = nex[x][y];
            temp = 1;
            
            while(d != -1) 
            {
                ans += go[d];
                x -= fx[d];
                y -= fy[d];
                d = nex[x][y];
            }
            
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n" << ans << "\n";
            
            return;
        }

        for (ll i = 0; i < 4; i++) 
        {
            ll xx = x + fx[i], 
            yy = y + fy[i];
            
            if (xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy] != '.' ) 
                continue;
            else 
            {
                grid[xx][yy] = grid[x][y];
            
                if (grid[xx][yy] == 'A') 
                    nex[xx][yy] = i;

                q.push({xx,yy});
            }
        }
    }

    if(!temp)
        cout << "NO" << "\n";
}
 
int main()
{
    in();
    out();

    cout << "\n";

    return 0;
}