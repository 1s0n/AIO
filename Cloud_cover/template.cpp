#include <iostream>

using namespace std;

int spaces[100000];
int spaces_sum[100001];

int main()
{
    freopen("cloudin.txt", "r", stdin);
    freopen("cloudout.txt", "w", stdout);

    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N - 1; i++)
    {
        int s;
        cin >> s;
        spaces[i] = s;
        spaces_sum[i + 1] = spaces_sum[i] + s;
    }

    int start = 0;
    int end = K;

    int smallest = INT_MAX;

    while (end < N)
    {
        int space = spaces_sum[end] - spaces_sum[start];

        if (space < smallest)
        {
            smallest = space;
        }

        start++;
        end++;
    }

    cout << smallest;
}