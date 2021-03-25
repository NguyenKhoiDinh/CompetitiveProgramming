#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500005;

vector <int> listDivisor[MAX_N];

void init() {
  for (int i = 1; i < MAX_N; i++) {
    for (int j = i; j < MAX_N; j += i) {
      listDivisor[j].push_back(i);
    }
  }
}

long long solve(int N, int C) {
  for (int i = 1; i <= N; i++) {
    if (N / i != C) {
      continue;
    }
    int sz = (int) listDivisor[i].size();
  }
}

class CatAndMice {
  public:
  long long countDirections(int N, int C) {
    init();
    long long ans = solve(N, C);
    ans *= 4LL;
    return ans;
  }
};

CatAndMice C;

int main () {
  cout << C.countDirections(2, 1);
  return 0;
}