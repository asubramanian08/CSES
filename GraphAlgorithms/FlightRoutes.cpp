// 9:32 - 9:57
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<long long, long long>;

int main(void)
{
    int n, m, k, n1, n2, cost;
    cin >> n >> m >> k;
    vector<pii> *graph = new vector<pii>[n];
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2 >> cost;
        graph[n1 - 1].push_back({cost, n2 - 1});
    }
    vector<long long> *paths = new vector<long long>[n];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (paths[node].size() == k)
            continue;
        paths[node].push_back(cost);
        for (pii next : graph[node])
            if (paths[next.second].size() < k)
                pq.push({cost + next.first, next.second});
    }
    for (int i = 0; i < k; i++)
        cout << paths[n - 1][i] << ' ';
    cout << endl;
    return 0;
}