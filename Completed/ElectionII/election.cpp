#include <iostream>

using namespace std;

int main()
{
    freopen("elecin.txt", "r", stdin);
    freopen("elecout.txt", "w", stdout);

    int a = 0;
    int b = 0;
    int c = 0;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char uhh;
        cin >> uhh;

        switch (uhh)
        {
            case 'A':
                a++;
                break;
            case 'B':
                b++;
                break;
            case 'C':
                c++;
                break;
        }
    }
    
    if (a > b && a > c)
        cout << "A";
    else if (b > a && b > c)
        cout << "B";
    else if (c > a && c > b)
        cout << "C";
    else
        cout << "T";
    return 0;

}