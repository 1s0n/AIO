// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N[100000];

int main()
{
    // freopen("compin.txt", "r", stdin);
    // freopen("compout.txt", "w", stdout)
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }

    int minVal = n;

    pair<int, int> alreadySolved[100000];

    for (int mid = 1; mid < n; mid++)
    {
        // cout << "MID: " << mid << "\n";
        int l = mid - 1;
        int r = mid + 1;

        int removed = 0;
        int valOfMid = N[mid];

        if (mid < 1)
        {
            continue;
        }

        // Count down l and r induvidually, and then get min and calc the removed;

        int lRes = 0;
        int rRes = 0;

        while (l >= 0 || r < n)
        {
            if (N[l] == valOfMid - lRes - 1 && l >= 0)
            {
                lRes++;
                // cout << "[LINDEX " << l << "] SUCC cus " << N[l] << " == " << valOfMid - lRes - 1 << "  MIDVAL: " << valOfMid << "  lRes: "<< lRes << "\n";
            } else if (l >= 0)
            {
                // cout << "[LINDEX " << l << "] Failed cus " << N[l] << " != " << valOfMid - lRes - 1 << "  MIDVAL: " << valOfMid << "  lRes: "<< lRes << "\n";
            }

            if (N[r] == valOfMid - rRes - 1 && r < n)
            {
                rRes++;
                // cout << "[RINDEX " << r << "] SUCC cus " << N[l] << " == " << valOfMid - rRes - 1 << "  MIDVAL: " << valOfMid << "  rRes: "<< rRes << "\n";
            } else if (r < n)
            {
                // cout << "[RINDEX " << r << "] Failed cus " << N[l] << " != " << valOfMid - rRes - 1 << "  MIDVAL: " << valOfMid << "  rRes: "<< rRes << "\n";
            }
            
            l--;
            r++;
        }

        int lowerRes = min(lRes, rRes);

        removed = n - (lowerRes * 2) - 1;
        if (minVal > removed)
        {
            minVal = removed;
        }
        // cout << "min: " << removed << "\n";
    }

    cout << minVal;
}