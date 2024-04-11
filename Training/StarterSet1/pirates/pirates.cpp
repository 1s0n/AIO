#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("piratein.txt", "r", stdin);
    freopen("pirateout.txt", "w", stdout);

    int L, X, Y;

    cin >> L >> X >> Y;

    int dist1 = X + Y;
    int dist2 = (L - X) + (L - Y);

    cout << min(dist1, dist2);
}