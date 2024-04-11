#include <iostream>

using namespace std;

int houses[100000];

int markets[100000];
int prices[100000];

int main()
{
    // freopen("shopin.txt", "r", stdin);
    // freopen("shopout.txt", "w", stdout);

    vector<int> masterlist;

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> houses[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> markets[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> prices[i];
    }

    

}