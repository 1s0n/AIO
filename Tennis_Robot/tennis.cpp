#include <iostream>
#include <map>

using namespace std;

int baskets[100000];

int main()
{
    // freopen("tennisin.txt", "r", stdin);
    // freopen("tennisout.txt", "w", stdout);

    int b;
    int n;

    cin >> n;
    cin >> b;
    
    map<int, int> baskets_sort;

    for (int i = 0; i < n; i++)
    {
        cin >> baskets[i];

        baskets_sort[baskets[i]] += 1;
    }
}