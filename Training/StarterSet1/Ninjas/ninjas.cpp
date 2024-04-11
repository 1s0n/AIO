#include <iostream>

using namespace std;

int main()
{
    freopen("ninjain.txt", "r", stdin);
    freopen("ninjaout.txt", "w", stdout);

    int N, K;

    cin >> N >> K;

    int i = 1;
    int ans = 0;
    while (i <= N)
    {
        ans++;
        i += K + 1;
    }

    cout << N - ans;
}