#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1000005;
long long f[MAX_N];
long long a, b;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> a >> b;
  for (int divisor = 1; divisor < MAX_N; divisor++) {
    for (long long i = a + (divisor - a % divisor) % divisor; i <= b; i += divisor) {
      if (divisor <= i / divisor) {
        f[i - a] += divisor;
        if (divisor < i / divisor) {
          f[i - a] += i / divisor;
        }
      }
    }
  }
  long long ans = 0;
  for (long long i = a; i <= b; i++) {
    ans += f[i - a];
  }
  cout << ans;
  return 0;
}