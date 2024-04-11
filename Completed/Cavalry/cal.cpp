#include <iostream>
#include <map>

using namespace std;

int main()
{
    freopen("cavalryin.txt", "r", stdin);
    freopen("cavalryout.txt", "w", stdout);

    int n;
    
    cin >> n;

    map<int, int> sizes;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        sizes[a] += 1;
    }

    int succ = 1;

    // Loop through map sizes
    for (auto i : sizes)
    {
        if (i.second % i.first != 0)
        {
            succ = 0;
        }
    }
    
    if (succ)
    {
        cout << "YES";
    } else
    {
        cout << "NO";
    }
}