#include <iostream>
#include <queue>
#include <utility>

// #include <bits/stdc++.h>
using namespace std;

pair<int, int[100000]> adjMat;
int adjMatLength[100000];

int visited[100000][100];
queue<int> searchQueue;
queue<int> searchQueueLayer;

int answered[100000];

int main()
{
    freopen("evadingin.txt", "r", stdin);
    freopen("evadingout.txt", "w", stdout);

    int N, E, X, K;
    
    cin >> N >> E >> X >> K;

    for (int i = 0; i < E; i++)
    {
        int a, b;

        cin >> a >> b;

        adjMat[adjMatLength[a]] = b;
        adjMatLength[a]++;
        adjMat[b][adjMatLength[b]] = a;
        adjMatLength[b]++;
    }

    // Print adjMatLength as a list
    // cout << "adjMatLength: ";
    // for (int i = 0; i < N; i++)
    // {
    //     cout << adjMatLength[i] << " ";
    // }

    // cout << endl;

    // Print adjMat in the form index:list
    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < adjMatLength[i]; j++)
    //     {
    //         cout << adjMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int layerRN = 0;

    int answer = 0;

    searchQueue.push(X);
    searchQueueLayer.push(0);

    int c = 0;

    // cout << "\nStarting loop\n";

    while (layerRN <= K)
    {
        if (searchQueue.size() < 1)
        {
            // cout << "\nProgram shat itself\n";
            break;
        }

        int parent = searchQueue.front();
        int parentLayer = searchQueueLayer.front();
        searchQueue.pop();
        searchQueueLayer.pop();

        queue<int> myQueue = searchQueue;
        for (size_t i = 0; i < myQueue.size(); i++)
        {
            // cout << myQueue.front() << " ";
            myQueue.pop();
        }
        
        // cout << "LAYERRN: " << parentLayer << "\n";

        layerRN = parentLayer;

        if (parentLayer == K)
        {
            if (!answered[parent])
            {
                answer++;
                answered[parent] = 1;
            }
        }
        
        for (int j = 0; j < adjMatLength[parent]; j++)
        {
            // cout << adjMat[parent][j] << " ";
            int adding = adjMat[parent][j];

            if (visited[adding][parentLayer] < 1)
            {
                searchQueue.push(adding);
                searchQueueLayer.push(parentLayer + 1);
                visited[adding][parentLayer]++;
            }
            
        }

        c++;
    }

    // cout << "\n" << c << "\n";
    cout << answer;
}

