#include <iostream>

using namespace std;

int p[1000];

int main()
{
//    freopen("balancein.txt", "r", stdin);
//    freopen("balanceout.txt", "w", stdout);
    
    int n;

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int l = 0;
    int r = n - 1;
    
    int ans = 0;
    
    while (l < r)
    {
        while (p[l] != p[r])
        {
            int lVal = p[l];
            int rVal = p[r];
            
            ans += 1;

            if (lVal < rVal)
            {
                l++;
                p[l] = lVal + p[l];
            }

            if (rVal < lVal)
            {
                r--;
                p[r] = rVal + p[r];
            }
        }
        l++;
        r--;
    }

    cout << ans;
}
