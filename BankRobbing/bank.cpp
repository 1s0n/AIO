#include <iostream>

using namespace std;

int main()
{
//    freopen("wherein.txt", "r", stdin);
//    freopen("whereout.txt", "w", stdout);
    
    int n, c;

    cin >> n;
    cin >> c;

    int co[100000];
    int b[100000];
    
    int costs[100000];

    int lowestB = 1000000000;
    int highestB = 0;

    for (int i = 0; i < c; i++)
    {
        cin >> b[i];
        
        if (b[i] < lowestB)
        {
            lowestB = b[i];
        }

        if (b[i] > highestB)
        {
            highestB = b[i];
        }
    }
    
    int sum = 0;

    for (int i = 0; i < n-1; i++)
    {
        cin >> co[i];

        sum += co[i];

        costs[i] = sum;
    }
    
    int loc = 0;
    
    int ans = 0;

    for (int i = 0; i < c; i++)
    {
        loc = b[i];

        int lowestBDist = loc - lowestB;
        int lowestBTime = costs[loc] - costs[lowestB];

        if (lowestBDist > lowestBTime)
        {
            continue;
        }
        
        int highestBDist = highestB - loc;
        int highestBTime = costs[highestB] - costs[lowestB];

        if (highestBDist > highestBTime)
        {
            continue;
        }

        ans++;
    }

    cout << ans;

}
