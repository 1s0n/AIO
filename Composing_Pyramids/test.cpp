#include <iostream>

using namespace std;

int a[1000];

int main()
{
    memset(a, 1, sizeof(a));
    cout << a[1];
}