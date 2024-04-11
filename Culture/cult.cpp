#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int i = 0;

    while (n % 2 == 0)
    {
        n /= 2;
        i++;
    }

    cout << n;
    cout << i;
}
