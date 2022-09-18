#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
bool visit[100001] = {0, };
int n, k;
int ans = 10000000;

void bfs() {
  pq.push({0, n});

  while(!pq.empty()) {
    int time = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if (now < 0 || now > 100001)
      continue;
    
    if (!visit[now]) {
      visit[now] = true;
      
      if (now == k) {
        if (time < ans)
          ans = time;
        return;
      } else if (now < k) {
        pq.push({-(time + 1), now - 1});
        pq.push({-(time + 1), now + 1});
        pq.push({-time, now * 2});
        } else
          if (time + now - k < ans)
          ans = time + now - k;
    }
  }
} 

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  bfs();
  cout << ans << "\n";

  return 0;
}
