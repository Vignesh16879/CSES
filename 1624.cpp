#include<bits/stdc++.h>

#define ll long long

using namespace std;


bool ld[15], rd[15], row[7];
int c = 0;
char a[8][8];


void chess(int j)
{
    if(j == 8)
    {
        c++;
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        if(a[i][j] == '.' && ld[i-j+7] == 0 && rd[i+j] == 0 && row[i] == 0)
        {
            ld[i-j+7] = 1, rd[i+j] = 1, row[i] = 1;
            chess(j + 1);
            ld[i-j+7] = 0, rd[i+j] = 0, row[i] = 0;
        }
    }
}


int main()
{
    int g = 8;

    for(int i = 0; i < g; i++)
    {
        for(int j = 0; j < g; j++)
        {
            cin >> a[i][j];
        }
    }

    chess(0);

    cout << c << "\n";

    return 0;
}