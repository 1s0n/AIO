// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int H[100000];
int MPos[100000];
int MPrice[100000];

int HOUSES[1000000000];

int calcBad(int house, int pos, int price) 
{
    return price + abs(pos - house);
}

int main()
{
    // freopen("shopin.txt", "r", stdin);
    // freopen("shopout.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
        HOUSES[H[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> MPos[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> MPrice[i];
    }

    int output[n];

    // Go to every store and binary search the best house

    for (int i = 0; i < m; i++)
    {
        int shop = MPos[i];
        int shopPrice = MPrice[i];

        int l = 0;
        int r = n;
        int mid = (l + r) / 2;

        while (r - l > 1)
        {
            if (MPos[mid])
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
}