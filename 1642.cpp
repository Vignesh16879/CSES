#include <bits/stdc++.h>
 
#define ll int
 
using namespace std;
 
class pairSum {
    public:
        ll first;
        ll sec;
        ll sum;
};
 
ll compare(const void* a, const void* b)
{
    return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
}
 
bool noCommon(pairSum a, pairSum b)
{
    if (a.first == b.first || a.first == b.sec || a.sec == b.first || a.sec == b.sec)
        return false;
    
    return true;
}
 
int main()
{
    ll n, X, arr[900000], m= 0;
    cin >> n >> X;
 
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
 
    ll i, j;
    ll size = (n * (n - 1)) / 2;
    pairSum aux[size];
    ll k = 0;
    
    for (i = 0; i < n - 1; i++) 
        for (j = i + 1; j < n; j++) 
        {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
 
    qsort(aux, size, sizeof(aux[0]), compare);
    i = 0;
    j = size - 1;
 
    while (i < size && j >= 0) 
    {
        if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j])) 
        {
            m = 1;
            cout << aux[i].first+1 << " " << aux[i].sec+1 << " " << aux[j].first+1 << " " << aux[j].sec+1 << "\n";
            break;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
 
    if(m == 0)
        cout << "IMPOSSIBLE" << "\n";
 
    return 0;
}