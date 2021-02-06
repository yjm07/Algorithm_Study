#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int x, y;
    int is_crashed;
};

int N, M;
int visited[1001][1001][2];
int graph[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    // 0 -> 벽을 안 부숨, 1 -> 벽을 부숨
    queue<node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 0;
    
    while(!q.empty()) {
        node n = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int X = n.x, Y = n.y;

            if(X < 0 || X == N || Y < 0 || Y == M) continue;
            if(graph[X][Y] == 1) {
                if(!n.is_crashed && visited[X][Y][1] == -1) {
                    q.push({X, Y, 1});
                    visited[X][Y][1] = visited[n.x][n.y][n.is_crashed] + 1;
                }
            }
            else if (visited[X][Y][n.is_crashed] == -1) {
                q.push({X, Y, n.is_crashed});
                visited[X][Y][n.is_crashed] = visited[n.x][n.y][n.is_crashed] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> graph[i][j];
    memset(visited, -1, sizeof(visited));
    bfs();
    int answer_a = visited[N-1][M-1][0], answer_b = visited[N-1][M-1][1];
    if(answer_a == -1 && answer_b == -1) cout << -1;
    else {
        if(answer_a == -1) cout << answer_b;
        else if(answer_b == -1) cout << answer_a;
        else cout << min(answer_a, answer_b);
    }
}