#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
int visited1[1001];
int visited2[1001];
vector<int> graph[1001];

void dfs(int node) {
	visited1[node] = 1;
	cout << node << " ";
	for(int next: graph[node]) {
		if(!visited1[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
    visited2[start] = 1;

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for(int next: graph[node]) {
			if(!visited2[next]) {
				visited2[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

    for(int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

	dfs(V);
	cout << "\n";
	
	bfs(V);

	return 0;
}