#include<bits/stdc++.h>

#define ll long long

using namespace std;


string gp(string str)
{
    map<char, int> h;

    for(int i = 0; i < str.length(); i++)
    {
        h[str[i]]++;
    }

    int m = 0;
    char od;

    for(auto x : h)
    {
        if(x.second % 2 != 0)
        {
            m++;
            od = x.first;
        }
    }

    if(m > 1 || m == 1 && str.length() % 2 == 0)
    {
        return "NO SOLUTION";
    }

    string a = "", b = "";

    for(auto x : h)
    {
        string s(x.second / 2, x.first);
        a += s;
        b = s + b;
    }

    return (m == 1) ? (a + od + b) : (a + b);   
}


int main()
{
    string str;
    cin >> str;
    cout << gp(str) << "\n";

    return 0;
}