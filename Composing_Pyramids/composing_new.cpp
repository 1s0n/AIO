#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <climits>

using namespace std;

int P[100000];
pair<int, vector<int> > pairs[100000];

pair<int, int> Chosen_Values[100000];
// Fix the fact that its out of order
// Case 1

int main()
{
    freopen("compin.txt", "r", stdin);
    freopen("compout.txt", "w", stdout);

    int n;

    cin >> n;

    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    while (l <= r)
    {
        if (l == r)
        {
            pairs[P[l]].first += 1;
            pairs[P[l]].second.push_back(l + 1);
            break;
        }


        pairs[P[l]].first += 1;
        pairs[P[l]].second.push_back(l + 1);

        pairs[P[r]].first += 1;
        pairs[P[r]].second.push_back(n - r);

        l++;
        r--;
    }

    int max = 0;
    int count = 0;

    // Find biggest consec
    // CHANGE THIS TO 100000
    for (int i = 1; i < n; i++)
    {
        if (pairs[i].first >= 2)
        {

            int failed = 0;
            int min = INT_MAX, secondMin = INT_MAX;
            pair<int, int> minToBeat = Chosen_Values[pairs[i - 1].first];

            // cout << "Comparing with pair: " << minToBeat.first << ":" << minToBeat.second << " I: " << i << "\n";

            int minRaw = INT_MAX;

            for (int j = 0; j < n; j++) {
        
                // If found new minimum
                if (pairs[i].second[j] < min && pairs[i].second[j] > minToBeat.first) {
        
                    // Minimum now becomes second minimum
                    secondMin = min;
        
                    // Update minimum
                    min = pairs[i].second[j];
                }
        
                // If current element is > min and < secondMin
                else if ((pairs[i].second[j] < secondMin) && pairs[i].second[j] != min && pairs[i].second[j] > minToBeat.second)
                {
                    // Update secondMin
                    secondMin = pairs[i].second[j];
                }

                if (pairs[i].second[j] < minRaw)
                {
                    if (pairs[i].second[j] > minToBeat.first || pairs[i].second[j] > minToBeat.second)
                    {
                        minRaw = pairs[i].second[j];
                    }
                }
            }
        
            failed = (min == INT_MAX || secondMin == INT_MAX) || (min < minToBeat.second || secondMin < minToBeat.second);
            // cout << "First test: " << failed << "\n";

            if (count < 0)
            {
                failed = false;
            }
            
            // cout << "Compare success: " << !failed << "\n";

            if (failed)
            {
                if (minRaw != INT_MAX)
                {
                    count += 1;
                }

                if (count > max)
                {
                    max = count;
                }

                count = 1;
            } else
            {
                Chosen_Values[pairs[i].first].first = min;
                Chosen_Values[pairs[i].first].second = secondMin;

                count += 1;
            }
            
        } else
        {
            // cout << "ELSE AT VAL " << i << "\n";
            if (pairs[i].first == 1)
            {
                // cout << "FIRST COUNT: " << count << endl;
                if (count == 0)
                {
                    count = 1;
                } else
                {
                    count += 1;
                }
            }

            if (count > max)
            {
                max = count;
            }

            count = 0;
        }
    }

    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "<" << pairs[i].first << ": [";
    //     for (int ele = 0; ele < pairs[i].second.size(); ele++)
    //     {
    //         cout << pairs[i].second[ele] << ", ";
    //     } 
    //     cout << "]\n";
    // } 

    // cout << "MAX: " << max << "\n";

    if (max == 0)
    {
        cout << 0;
    } else
    {
        cout << n - ((max * 2 ) - 1);
    }

}