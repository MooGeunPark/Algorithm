#include <iostream>
#define INF 1000000000
using namespace std;

int graph[101][101], dis[101][101];
int n, m, a, b, c;

void floyd() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j)
        dis[i][j] = 0;
      else
        dis[i][j] = graph[i][j];
      }

  for (int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dis[i][j] > dis[i][k] + dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      graph[i][j] = INF;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (graph[a][b] == INF)
      graph[a][b] = c;
    else 
      if (graph[a][b] > c)
        graph[a][b] = c;
    }

  floyd();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis[i][j] == INF)
        cout << "0 ";
      else
        cout << dis[i][j] << " ";
      }
    cout << "\n";
    }
  
  return 0;
}
