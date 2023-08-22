#include <iostream>

using namespace std;

int main()
{
    // freopen("baublesin.txt", "r", stdin);
    // freopen("baublesout.txt", "w", stdout);

    int Ro, Bo, S, Rp, Bp;

    cin >> Ro >> Bo >> S >> Rp >> Bp;

    int Rneeds = Ro - Rp;
    int Bneeds = Bo - Bp;

    // Biggest gap
    int lowerval = min(Rneeds, Bneeds);

    int higherval = max(Rneeds, Bneeds);

    cout << "LOWER: " << lowerval << "\n";

    int ans = 0;

    if (lowerval >= 0)
    {
        ans += lowerval + 1;
        ans += S;

    } else
    {
        ans = S - abs(lowerval) + 1;

        if (Rneeds < 0 && Bneeds < 0)
        {
            int a = abs(Rneeds) + abs(Bneeds);
            cout << Rneeds << "  " << Bneeds << "  " << a << "\n";
            ans = S - a + 1;
        }

        if (ans < 0)
        {
            ans = 0;
        }
    }

    cout << ans;
}