#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
      freopen("manin.txt", "r", stdin);
    freopen("manout.txt", "w", stdout);

    int loc1, dist1, loc2, dist2;

    cin >> loc1 >> loc2 >> dist1 >> dist2;

    int found = 0;
    int loc = 0;

    int i = min(loc1 - dist1, loc2 - dist2);
    // cout << i;
    while (!found)
    {
        int a = abs(loc1 - i);
        int b = abs(loc2 - i);

        if (a == dist1 && b == dist2)
        {
            found = 1;
            loc = i;
            break;
        }

        i++;
    }

    cout << i;
}