// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int posts[100000];

int main()
{
    freopen("frogin.txt", "r", stdin);
    freopen("frogout.txt", "w", stdout);

    int n;

    int low = INT_MAX;
    int indexOfLow = 0;
    cin >> n;



    for (int i = 0; i < n; i++)
    {
        cin >> posts[i];
        if (low > posts[i])
        {
            low = posts[i];
            indexOfLow = i;
        }
    }

    int maxDiff = 0;


    for (int i = 1; i < n; i++)
    {
        if (i == indexOfLow)
        {
            continue;
        }
        if (i > indexOfLow)
        {
            // I is to the right of index of low, so cycle i to n
            int index = i + 1;
            while (index < n)
            {
                int diff = abs(posts[i] - posts[index]);
                diff += abs(posts[i] - low);
                maxDiff = max(diff, maxDiff);
                index++;
            }
        } else
        {
            // I is to the left of index of low, so cycle i to 0
            int index = i - 1;
            while (index >= 0)
            {
                int diff = abs(posts[i] - posts[index]);
                diff += abs(posts[i] - low);
                maxDiff = max(diff, maxDiff);
                index--;
            }
        }
    }
    
    cout << maxDiff;
}