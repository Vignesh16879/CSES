#include<bits/stdc++.h>

#define ll long long ll

using namespace std;


const ll mod = 1e9 + 7;
const ll n = 7;
bool visited[n][n];
ll reserved[49];

void move(ll r, ll c, ll &ans, ll &steps)
{
    if (r == n - 1 && c == 0)
    {
        ans += (steps == n * n - 1);

        return;
    }

    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;

    if (reserved[steps] != -1)
    {
        switch (reserved[steps])
        {
        case 0:
            if (r - 1 >= 0)
            {
                if (!visited[r - 1][c])
                {
                    steps++;
                    move(r - 1, c, ans, steps);
                    steps--;
                }
            }

            break;

        case 1:
            if (c + 1 < n)
            {
                if (!visited[r][c + 1])
                {
                    steps++;
                    move(r, c + 1, ans, steps);
                    steps--;
                }
            }

            break;

        case 2:
            if (r + 1 < n)
            {
                if (!visited[r + 1][c])
                {
                    steps++;
                    move(r + 1, c, ans, steps);
                    steps--;
                }
            }

            break;

        case 3:
            if (c - 1 >= 0)
            {
                if (!visited[r][c - 1])
                {
                    steps++;
                    move(r, c - 1, ans, steps);
                    steps--;
                }
            }

            break;
        }

        visited[r][c] = false;
        
        return;
    }

    if (r + 1 < n)
    {
        if (!visited[r + 1][c])
        {
            steps++;
            move(r + 1, c, ans, steps);
            steps--;
        }
    }

    if (c + 1 < n)
    {
        if (!visited[r][c + 1])
        {
            steps++;
            move(r, c + 1, ans, steps);
            steps--;
        }
    }

    if (r - 1 >= 0)
    {
        if (!visited[r - 1][c])
        {
            steps++;
            move(r - 1, c, ans, steps);
            steps--;
        }
    }

    if (c - 1 >= 0)
    {
        if (!visited[r][c - 1])
        {
            steps++;
            move(r, c - 1, ans, steps);
            steps--;
        }
    }

    visited[r][c] = false;
}


ll main()
{
    string str;
    cin >> str;

    for(ll i = 0; i < str.length(); i++)
    {
        if (str[i] == '?')
        {
            reserved[i] = -1;
        }
        else if (str[i] == 'U')
        {
            reserved[i] = 0;
        }
        else if (str[i] == 'R')
        {
            reserved[i] = 1;
        }
        else if (str[i] == 'D')
        {
            reserved[i] = 2;
        }
        else if (str[i] == 'L')
        {
            reserved[i] = 3;
        }
    }

    ll ans = 0, steps = 0;
    move(0, 0, ans, steps);

    cout << ans << "\n";

    return 0;
}