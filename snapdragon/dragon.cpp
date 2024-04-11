#include <iostream>

using namespace std;

int main()
{
    freopen("snapin.txt", "r", stdin);
    freopen("snapout.txt", "w", stdout);


    int r, s;

    cin >> r;

    cin >> s;
    
    int rlist[100000];
    int slist[100000];
    
    int idk[100000];

    for (int i = 0; i < r; i++)
    {
        cin >> rlist[i];
    }

    for (int i = 0; i < s; i++)
    {
        cin >> slist[i];

        idk[slist[i]] += 1;
    }
    
    int ans = 0;

    for (int i = 0; i < r; i++)
    {
        ans += idk[rlist[i]];
    }

    cout << ans;
}
