#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

char inst[100000];

int main()
{
    freopen("telein.txt", "r", stdin);
    freopen("teleout.txt", "w", stdout);

    int n;
    
    cin >> n;

    // Both pos and neg
    int infiniteValley[400000];

    int counter = 200000;
    int home = 200000;

    memset(&infiniteValley, 0, sizeof(infiniteValley));
    infiniteValley[home] = 1;

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> inst[i];

        if (inst[i] == 'L')
        {
            counter--;
        } else if (inst[i] == 'R')
        {
            counter++;
        } else {
            counter = home;
        }

        // cout << counter << "\n";

        if (infiniteValley[counter] == 0)
        {
            // cout << "BEW\n";
            ans++;
            infiniteValley[counter] = 1;
        }
    }


    cout << ans;
}