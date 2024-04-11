#include <iostream>

using namespace std;

int main()
{

    // freopen("streetin.txt", "r", stdin);
    // freopen("streetout.txt", "w", stdout);

    int N, K;

    cin >> N;
    cin >> K;

    int result = ceil((N-K) / (K+1));
    cout << N/(K+1);
}