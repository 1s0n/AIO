#include <iostream>

using namespace std;

int main()
{
    freopen("artin.txt", "r", stdin);
    freopen("artout.txt", "w", stdout);

    int n;
    cin >> n;

    int x, y;

    int xlargest = 0;
    int ylargest = 0;
    int xsmall = 100001;
    int ysmall = 100001;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        if (x > xlargest)
        {
            xlargest = x;
        }

        if (x < xsmall)
        {
            xsmall = x;
        }

        if (y > ylargest)
        {
            ylargest = y;
        }
        if (y < ysmall)
        {
            ysmall = y;
        }
    }

    // cout << xlargest << "  " << xsmall << "  " << ylargest << "  " << ysmall << endl;

    cout << (xlargest - xsmall) * (ylargest - ysmall);
}