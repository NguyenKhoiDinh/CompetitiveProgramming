#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 250005;

long long K[MAX_N];
bool check[MAX_N];

class LunchLine {
  public: 
  long long simulate(int N, int M, int A, int B, int C, int D, int E) {
    vector <int> kids;
    K[1] = A;
    K[2] = B;
    if (A != 0) {
      check[A] = true;
    }
    if (B != 0) {
      check[B] = true;
    }
    for (int i = 3; i <= M; i++) {
      K[i] = ((long long) C * K[i - 1] + (long long) D * K[i - 2] + E) % N;
      check[K[i]] = true;
    }
    for (int i = 0; i < N; i++) {
      if (check[i] == false) {
        kids.push_back(i);
      }
    }
    stack <long long> myStack;
    for (int i = M; i >= 1; i--) {
      if (check[K[i]] == true) {
        myStack.push(K[i]);
        check[K[i]] = false;
      }
    }
    while (!myStack.empty()) {
      int t = myStack.top();
      myStack.pop();
      kids.push_back(t);
    }
    long long ans = 0LL;
    for (int i = 0; i < kids.size(); i++) {
      ans += (long long) i * kids[i];
    }
    return ans;
  }
};

LunchLine L;

int main () {
  cout << L.simulate(250000,
0,
0,
0,
0,
0,
0);
  return 0;
}