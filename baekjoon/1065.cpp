#include <iostream>
using namespace std;

int n, ans;

bool check(int num) {
  int dif1 = (num / 10) % 10 - (num % 10);
  num /= 10;
  
  while (num >= 10) {
    int dif2 = -num % 10;
    num /= 10;
    dif2 += num;

    if (dif1 != dif2)
      return false;
    dif1 = dif2;
  }
  return true;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    if (check(i))
      ans++;

  cout << ans << "\n";
  return 0;
}
