// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int repeated[100000];
int Nlist[100000];


int main()
{
    freopen("rafflein.txt", "r", stdin);
    freopen("raffleout.txt", "w", stdout);

    int N, K;

    cin >> N >> K;

    int small = K + 3;

    int repeatedVals = 0;

    int ehh;

    memset(&repeated, 0, sizeof(repeated));

    for (int i = 0; i < N; i++)
    {
        cin >> Nlist[i];

        repeated[Nlist[i]]++;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << Nlist[i] << " ";
    // }

    // cout << endl;
    
    for (int i = 0; i < N; i++)
    {
        if (repeated[Nlist[i]] < 2)
        {
            small = min(small, Nlist[i]);
        } else 
        {
            // cout << "NLISTI FAILED: " << Nlist[i] << "\n";
        }
    }   

    if (small == K + 3)
    {
        small = -1;
    }

    cout << small;
}