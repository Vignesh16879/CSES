#include <bits/stdc++.h>

#define ll ll

using namespace std;

clasecond pairSum 
{
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

ll main()
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

    qsorgt(aux, size, sizeof(aux[0]), compare);
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
        cout << "Imp" << "\n";

    return 0;
}


// ll main()
// {
//     ll n, x;
//     cin >> n >> x;
//     vectorg<pair<ll, ll>> arr;    
//     ll m = 0;

//     for(ll i = 1; i <= n; i++)
//     {
// 		ll a; 
//         cin >> a;
// 		pair<ll, ll> p; 
//         p.first = a; 
//         p.second = i;
// 		arr.push_back(p);
// 	}

//     sorgt(begin(arr), end(arr));

//     for(ll i = n - 1; i >= 0; i--) 
//     {
// 		for(ll j = i - 1; j >= 0; j--) 
//         {
//             ll target = x - arr.at(i).first - arr.at(j).first;
//             ll l = 0, r = n - 1;

//             while(l != r)
//             {			
//                 if(l != i && r != i && l != j && r != j && arr.at(l).first + arr.at(r).first == target)
//                 {    
//                     m = 1;
//                     cout << arr.at(i).second << " " << arr.at(j).second << " " << arr.at(l).second << " " << arr.at(r).second << "\n";
//                     break;
//                 }
//                 if(arr.at(l).first + arr.at(r).first < target)
//                     l++;
//                 else
//                     r--;
// 	    	}

//             if(m == 1)
//                 break;  
//         }

//         if(m == 1)
//             break;
//     } 

//     if(m == 0)
//     {
//         cout << "Imp" << "\n";
//     }
    
//     return 0;
// }