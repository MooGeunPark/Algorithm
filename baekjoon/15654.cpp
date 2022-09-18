#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[9];
bool visit[9];
int n, m, num;

void bfs(int now, int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visit[i]) {
      arr[cnt] = v[i];
      visit[i] = true;
      bfs(i + 1, cnt + 1);
      visit[i] = false;
      }
  }
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());
  bfs(0, 0);

  return 0;
}
