#include <iostream>

using namespace std;

int L[100000];
int R[100000];

int main()
{
    // freopen("tspin.txt", "r", stdin);
    // freopen("tspout.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }

    int bad = 0;

    int high = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> R[i];

        if (L[i - 1] > high)
        {
            high = L[i - 1];
        }

        if (R[i] < high && i > 0)
        {
            bad = 1;
            break;
        }
    }

    if (bad)
    {
        cout << "NO";
    } else
    {
        cout << "YES";
    }
    
    return 0;
}