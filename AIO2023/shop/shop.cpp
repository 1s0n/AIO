// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int H[100000];
int MPos[100000];
int MPrice[100000];

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

    for (int i = 0; i < n; i++)
    {
        int house = H[i];

        int mid = i;

        int l = mid - 1;
        int r = mid;

        int best = INT_MAX;

        while (l >= 0 || r < m)
        {
            int lcalc = calcBad(house, MPos[l], MPrice[l]);
            if (best > lcalc && l >= 0)
            {
                best = lcalc;
                // cout << "NEW BEST FOR " << house << " AT " << MPos[l] << " AT INDEX " << l << " FROM L\n";
            }

            int rcalc = calcBad(house, MPos[r], MPrice[r]);
            if (best > rcalc && r < m)
            {
                best = rcalc;
                // cout << "NEW BEST FOR " << house << " AT " << MPos[r] << " AT INDEX " << r << " FROM R\n";
            }

            l--;
            r++;
        }

        output[i] = best;
    }

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
}