#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char graph[26][26];
int visited[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result = 0;
int N;
vector<int> size;

int dfs(int x, int y) {
    visited[x][y] = 1;
    int answer = 1;
    for(int i = 0; i < 4; i++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X < 0 || X == N || Y < 0 || Y == N) continue;
        if(!visited[X][Y] && graph[X][Y] == '1') 
            answer += dfs(X, Y);
    }
    return answer;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int X = p.first + dx[i], Y = p.second + dy[i];
            if(X < 0 || X == N || Y < 0 || Y == N) continue;
            if(!visited[X][Y] && graph[X][Y] == '1') {
                visited[X][Y] = 1;
                q.push({X, Y});
            }
        }
    }
}

int main() {
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%c", &graph[i][j]);              
        }
        getchar();
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == '1' && !visited[i][j]) {
                size.push_back(dfs(i, j));     
            }
        }
    }

    cout << size.size() << '\n';
    sort(size.begin(), size.end());
    for(int s : size) cout << s << '\n';
}