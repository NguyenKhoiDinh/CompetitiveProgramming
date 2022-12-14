#include <bits/stdc++.h> 

using namespace std;
const int MAX_P = 1000005;

vector <int> listPos[MAX_P];

class ConstantSegment {
  public: 
  int sendSomeHome(int N, int K, int M, vector <int> Pprefix, int seed) {
    vector<int> P(N);

    int L = Pprefix.size();
    for (int i=0; i<L; ++i) P[i] = Pprefix[i];

    long long state = seed;
    for (int i=L; i<N; ++i) {
        state = (state * 1103515245 + 12345) % (1LL << 31);
        P[i] = (state / 16) % M;
    }
    for (int i = 0; i < N; i++) {
      listPos[P[i]].push_back(i);
    }
    int res = 1000000007;
    for (int type = 0; type <= 1000000; type++) {
      if ((int) listPos[type].size() < K) {
        continue;
      }
      for (int i = K - 1; i < (int) listPos[type].size(); i++) {
        int cur = i;
        int prev = i - K + 1;
        int diff = listPos[type][cur] - listPos[type][prev] + 1;
        res = min(res, diff - K);
      }
    }
    return (res == 1000000007 ? -1 : res);
  }
};

ConstantSegment C;

int main () {
  cout << C.sendSomeHome(10,
5,
10,
{1, 4, 3, 3, 3, 3, 2, 0, 3, 9},
0);
  return 0; 
}
