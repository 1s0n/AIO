#include <iostream>

using namespace std;

int A[100000];

int main()
{
    freopen("groundin.txt", "r", stdin);
    freopen("groundout.txt", "w", stdout);

    int n;

    cin >> n;

    int last = -1;
    int best = 0;
    int current = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

        if (A[i] == last)
        {
            current += A[i];
        } else
        {
            current = A[i];
        }

        if (current > best)
        {
            best = current;
        }

        last = A[i];
    }

    cout << best;
}