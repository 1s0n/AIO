#include <iostream>
#include <map>

using namespace std;

int vals[100000];

int main()
{
    freopen("melodyin.txt", "r", stdin);
    freopen("melodyout.txt", "w", stdout);

    int n, k;

    cin >> n >> k;

    map<int, int> biggest1;
    map<int, int> biggest2;
    map<int, int> biggest3;

    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
        int dig = (i) % 3;

        if (dig == 0) // Multiple of 3
        {
            biggest1[vals[i]] += 1;
        } else if (dig == 1)
        {
            biggest2[vals[i]] += 1;
        } else if (dig == 2)
        {
            biggest3[vals[i]] += 1;
        }
    }

    map<int, int>::iterator it;
    
    int biggestval1 = 0;
    int biggestnum1 = 0;
    
    for (it = biggest1.begin(); it != biggest1.end(); it++)
    {

        if (it->second > biggestval1)
        {
            biggestval1 = it->second;
            biggestnum1 = it->first;
        }
    }

    int biggestval2 = 0;
    int biggestnum2 = 0;
    
    for (it = biggest2.begin(); it != biggest2.end(); it++)
    {
        if (it->second > biggestval2)
        {
            biggestval2 = it->second;
            biggestnum2 = it->first;
        }
    }


    int biggestval3 = 0;
    int biggestnum3 = 0;
    
    for (it = biggest3.begin(); it != biggest3.end(); it++)
    {
        // std::cout << it->first    // string (key)
        //         << ':'
        //         << it->second   // string's value 
        //         << std::endl;

        if (it->second > biggestval3)
        {
            biggestval3 = it->second;
            biggestnum3 = it->first;
        }
    }

    int change = 0;

    for (int i = 0; i < n; i++)
    {
        int dig = (i) % 3;

        if (dig == 0) // Multiple of 3
        {
            if (vals[i] != biggestnum1) change++;
        } else if (dig == 1)
        {
            if (vals[i] != biggestnum2) change++;
        } else if (dig == 2)
        {
            if (vals[i] != biggestnum3) change++;
        }
    }
    cout << change;

}