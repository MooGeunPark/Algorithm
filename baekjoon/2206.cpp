#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[1001][1001];
int visit[1001][1001][2];
int n, m;

int bfs() {
	q.push({{0, 0}, 1});
	visit[0][0][1] = 1;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();
		
		if (x == n - 1 && y == m - 1)
			return visit[x][y][block];
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			
			if (arr[nx][ny] == 0 && visit[nx][ny][block] == 0) {
				visit[nx][ny][block] = visit[x][y][block] + 1;
				q.push({{nx, ny}, block});
			}
			
			if (arr[nx][ny] == 1 && block == 1) {
				visit[nx][ny][0] = visit[x][y][block] + 1;
				q.push({{nx, ny}, 0});
			}
		}
	}
	
	return -1;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}
	
	cout << bfs() << "\n";
	return 0;
}
