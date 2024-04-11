// #include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int voter[100000];
int price[100000];

bool sortcompare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

map<int, int> canidates;


int main()
{
    // freopen("dealin.txt", "r", stdin);
    // freopen("dealout.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    pair<int, int> voters[m];
    

    for (int i = 0; i < m; i++)
    {
        cin >> voter[i];
        canidates[voter[i]] += 1;;
        voters[i].first = voter[i];
        
    }

    for (int i = 0; i < m; i++)
    {
        cin >> price[i];
        voters[i].second = price[i];
    }
    
    int ans = 0;
    sort(voters, voters + n, sortcompare);
    for (int i = 0; i < m; i++)
    {
        int large = 0;
        int largeind = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (large < canidates[i])
            {
                largeind = i;
                large = canidates[i];
            }
        }  

        if (largeind == 0)
        {
            break;
        }

        canidates[voters[i].first - 1]--;
        ans += voters[i].second;
        canidates[0]++;
    }
   

    cout << ans;

    
    
}