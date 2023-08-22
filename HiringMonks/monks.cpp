// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N[100000];
int S[100000];
int M[100000];

pair<int, int> whole[200000];


int main()
{
    freopen("hirein.txt", "r", stdin);
    freopen("hireout.txt", "w", stdout);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }

    sort(N, N + n);

    int s;
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        cin >> S[i];
    }

    sort(S, S + s);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> M[i];
    }

    sort(M, M + m);


    // for (int i = 0; i < wholelen; i++)
    // {
    //     cout << whole[i].first << "  "; 
    // }
    
    // cout << "\n";



    int ans = 0;


    int job_i = 0;
    for (int top_counter = 0; top_counter < n; top_counter++)
    {
        if (job_i >= s)
        {
            break;
        }

        int skill = N[top_counter];

        int jobMax = S[job_i];

        // cout << skill << ":" << jobMax << "\n";

        if (skill <= jobMax)
        {
            ans++;
            N[top_counter] = 0;
            job_i++;
        }
    }
    // cout << ans << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << N[i] << "  "; 
    // }
    
    // cout << "\n";
    job_i = 0;
    for (int top_counter = 0; top_counter < n; top_counter++)
    {
        if (job_i >= m)
        {
            break;
        }

        int skill = N[top_counter];

        if (skill == 0)
        {
            continue;
        }

        int jobMax = M[job_i];

        // cout << skill << ":" << jobMax << "\n";

        if (skill >= jobMax)
        {
            ans++;
            N[top_counter] = 0;
            job_i++;
        }
    }

    cout << ans;
}