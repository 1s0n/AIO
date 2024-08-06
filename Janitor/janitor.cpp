#include <iostream>

using namespace std;

int floors[10][100000];

int R, C, Q;


bool check_highest(int x, int y)
{
    int height = floors[x][y];

    // Check all adjacent cells
    if (x > 0 && floors[x - 1][y] > height) {
        return false;
    }
    if (x < R && floors[x + 1][y] > height) {
        return false;
    }
    if (y > 0 && floors[x][y - 1] > height) {
        return false;
    }
    if (y < C - 1 && floors[x][y + 1] > height) {
        return false;
    }
    
    return true;
}

int main()
{
    // freopen("janitorin.txt", "r", stdin);
    // freopen("janitorout.txt", "w", stdout);

    cin >> R;
    cin >> C;
    cin >> Q;

    

    int replacements_ans[Q];

    int ans;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> floors[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (check_highest(i, j))
            {
                ans++;
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        
    }
    
}
