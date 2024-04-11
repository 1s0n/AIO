#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

int P[1000000];

int existBefore[100000];
int existAfter[100000];
int appearedInd[100000];


int main()
{
    fill(appearedInd, appearedInd+100000, -1);

    freopen("compin.txt", "r", stdin);
    freopen("compout.txt", "w", stdout);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];

        existBefore[i] = 1;
        int ind = appearedInd[P[i] - 1];

        if (ind > -1)
        {
            existBefore[i] += existBefore[ind];
        }
        appearedInd[P[i]] = i;
    }

    fill(appearedInd, appearedInd+100000, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        existAfter[i] = 1;
        int ind = appearedInd[P[i] - 1];

        if (ind > -1)
        {
            existAfter[i] += existAfter[ind];
        }
        appearedInd[P[i]] = i;
    }
    
    // // Print the existBefore list
    // for (int i = 0; i < n; i++)
    // {
    //     cout << existBefore[i] << " ";
    // }
    // cout << endl;

    // // Print the existAfter list
    // for (int i = 0; i < n; i++)
    // {
    //     cout << existAfter[i] << " ";
    // }
    // cout << endl;

    int best = 0;

    for (int i = 0; i < n; i++)
    {
        int w = min(existBefore[i], existAfter[i]);
        if (w > best)
        {
            best = w;
        }
    }

    int songLen = best*2 - 1;
    cout << n - songLen;
}