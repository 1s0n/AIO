#include <iostream>
#include <queue>

using namespace std;

int adjMat[100000][100000];
int adjMatLength[100000];

int visited[100000];
queue<int> searchQueue;
queue<int> searchQueueLayer;

int answered[100000];

int main()
{
    searchQueue.push(1);
    searchQueue.pop();
    searchQueue.pop();
}

