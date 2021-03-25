#include <iostream>

using namespace std;
const int MAX_N = 14;
int h[MAX_N];
int n, k;
long long res = 0;
int changed[MAX_N];
long long sum[MAX_N];

void update() {
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + changed[i];
  }

}

void backTrack(int pos, int add) {
  if (pos == n) {
    changed[pos] = h[pos] + add;
    update();
    return;
  }
  for (int numAdd = 0; numAdd <= add; numAdd++) {
    changed[pos] = h[pos] + numAdd;
    backTrack(pos + 1, add - numAdd);
  }
}

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  backTrack(1, k);
  return 0;
}