#include <iostream>

using namespace std;

int P[100000];

// Idk what sweep was i just felt like this looked like it
int SWEEP[100000];

// Loop through the loop both sides

int main()
{
    // freopen("compin.txt", "r", stdin);
    // freopen("compout.txt", "w", stdout);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    int l = 0;
    int r = n - 1;

    int consec;

    while (l <= r)
    {
        if (l == r)
        {
            int lVal = P[l];
            if (SWEEP[lVal] < 2)
            {
                SWEEP[lVal]++;
            }
            break;
        }

        int lVal = P[l];
        if (SWEEP[lVal] < 2)
        {
            SWEEP[lVal]++;
        }

        int rVal = P[r];
        if (SWEEP[rVal] < 2)
        {
            SWEEP[rVal]++;
        }
        
        if (l == 0)
        {
            continue;
        }

        int lastLVal = P[l - 1];
        

        l++;
        r--;
    }
}