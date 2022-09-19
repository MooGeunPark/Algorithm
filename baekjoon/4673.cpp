#include <iostream>
using namespace std;

bool visit[10001];

int d(int n) {
  int sum = n;

  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= 10000; i++) {
    int num = d(i);
    if (num < 10001)
      visit[num] = true;
  }

  for (int i = 1; i <= 10000; i++)
    if (!visit[i])
      cout << i << "\n";

  return 0;
}
