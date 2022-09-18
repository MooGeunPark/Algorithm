#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[100001];
bool visit[100001];
int v, maxDis, maxNode;

void dfs(int now, int dis) {
  if (dis > maxDis) {
    maxDis = dis;
    maxNode = now;
  }

  visit[now] = true;
  for (int i = 0; i < graph[now].size(); i++) {
    int nextNode = graph[now][i].first;
    int nextDis = graph[now][i].second;
    
    if (!visit[nextNode])
      dfs(nextNode, dis + nextDis);
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v;
  for (int i = 0; i < v; i++) {
    int a, b, c;
    cin >> a;

    while (true) {
      cin >> b;
      if (b == -1)
        break;
      cin >> c;
      graph[a].push_back({b, c});
    }
  }

  dfs(1, 0);
  for (int i = 1; i <= v; i++)
    visit[i] = false;
  maxDis = 0;
  dfs(maxNode, 0);
  
  cout << maxDis << "\n";
  return 0;
}
