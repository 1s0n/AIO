#include <iostream>

char days[100000];
using namespace std;

int main()
{
    freopen("bankin.txt", "r", stdin);
    freopen("bankout.txt", "w", stdout);

    int N;

    cin >> N;

    int totClass = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> days[i];

        if (days[i] == 'C')
        {
            totClass++;
        }
    }

    int skill = 1;
    int totMoney = 0;

    for (int i = 0; i < N; i++)
    {
        if (days[i] == 'C')
        {  
            int totWithout = (N - i) * skill;
            int totWith = (N - i - 1) * (skill + 1);

            // cout << totWith << "  " << totWithout << "\n";
            if (totWith > totWithout)
            {
                skill += 1;
                // cout << "Learn\n";
            } else
            {
                // cout << "work\n";
                totMoney += skill;
            }
        } else {
            totMoney += skill;
        }   
    }

    cout << totMoney;
}