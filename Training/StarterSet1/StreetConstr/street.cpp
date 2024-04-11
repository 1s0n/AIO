#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    // freopen("streetin.txt", "r", stdin);
    // freopen("streetout.txt", "w", stdout);

    int N, K;

    cin >> N >> K;

    int ans = (N / K) + (N%K > 0);

    cout << ans;
}
