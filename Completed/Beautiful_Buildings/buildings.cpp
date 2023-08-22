#include <iostream>

using namespace std;

int buildings[100000];
int buildings_diff[100000];


int main()
{
    freopen("buildin.txt", "r", stdin);
    freopen("buildout.txt", "w", stdout);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> buildings[i];
    }

    int largest_diff = 0;
    int largest_uhh = 0;
    int uhh = 0;



    for (int i = 0; i < n; i += 1)
    {

        if (i == 0 || i == n - 1)
        {
            int diff = 0;
            if (i == 0)
            {
                diff = buildings[i + 1] - buildings[i];
            } else 
            {
                diff = buildings[i - 1] - buildings[i];
            }

            diff = abs(diff);

            if (diff > largest_diff)
            {
                largest_diff = diff;
                largest_uhh = uhh;
            }

            buildings_diff[uhh] = diff;

            uhh++;
            continue;
        }

        int beforediff = buildings[i - 1] - buildings[i];
        int afterdiff = buildings[i + 1] - buildings[i];

        int diff = 0;
        if (beforediff > 0 && afterdiff > 0)
        {
            
            diff = min(beforediff, afterdiff);
            diff *= 2;
        } else if (beforediff < 0 && afterdiff < 0)
        {
            beforediff *= -1;
            afterdiff *= -1;
            diff = min(beforediff, afterdiff);
            diff *= 2;
        }
        
        if (diff > largest_diff)
        {
            largest_diff = diff;
            largest_uhh = uhh;
        }

        buildings_diff[uhh] = diff;

        uhh++;
    }

    // cout << "LARGEST: " << largest_diff << " WITH UHH: " << largest_uhh << " CURRENT: " << buildings[largest_uhh] << " DESIRED: " << buildings[largest_uhh + 1] << "\n";

    if (largest_uhh == n - 1)
    {
        buildings[largest_uhh] = buildings[largest_uhh - 1];
    } else
    {
        buildings[largest_uhh] = buildings[largest_uhh + 1];
    }
    
    
    int ugly = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int dif = buildings[i] - buildings[i + 1];
        // cout << buildings[i] << " - " << buildings[i + 1] << " = " << dif;
        ugly += abs(dif);
        // cout << "\n";
    }

    cout << ugly;
}