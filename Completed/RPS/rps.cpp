#include <iostream>

using namespace std;

int main()
{
    freopen("rpsin.txt", "r", stdin);
    freopen("rpsout.txt", "w", stdout);

    int n;

    cin >> n;


    int R1, P1, S1;

    cin >> R1 >> P1 >> S1;


    int R, P, S;

    cin >> R >> P >> S;

    
    int spareR = 0;
    int spareP = 0;
    int spareS = 0;

    int ans = 0;

    if (R >= S1)
    {
        spareR += R - S1;
        ans += S1;
    }

    // cout << ans << "\n";

    if (P >= R1)
    {
        spareP += P - R1;
        ans += R1;
    }

    // cout << R1 << "\n";

    if (S >= P1)
    {
        spareS += S - P1;
        ans += P1;
    }

    // cout << ans << "\n";

    if (R < S1)
    {
        if (spareS < S1)
        {
            ans -= S1 - spareS - R;
        }

        ans += R;
    }

    if (P < R1)
    {
        if (spareR < R1)
        {
            ans -= R1 - spareR - P;
        }

        ans += P;
    }

    if (S < P1)
    {
        // cout << spareP;
        if (spareP < P1)
        {
            ans -= P1 - spareP - S;
        }

        ans += S;
    }

    cout << ans;
}