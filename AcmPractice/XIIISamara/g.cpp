#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005;
int n;
vector <int> nuts, bolts; 
int ans[MAX_N];

void solve(const vector <int> &A, const vector <int> &B) {
  if (A.empty() == true || B.empty() == true) {
    return;
  }
  int sz = (int) A.size();
  int position = rand() % sz;
  vector <int> BL, BR;
  int found = -1;
  for (int i = 0; i < (int) B.size(); i++) {
    cout << "? " << A[position] << ' ' << B[i] << endl;
    fflush(stdout);
    char c;
    cin >> c;
    if (c == '<') {
      BL.push_back(B[i]);
    }
    else if (c == '>') {
      BR.push_back(B[i]);
    }
    else {
      found = B[i];
    }
  }
  ans[A[position]] = found;
  vector <int> AL, AR;
  for (int i = 0; i < (int) A.size(); i++) {
    cout << "? " << A[i] << ' ' << found << endl;
    fflush(stdout);
    char c;
    cin >> c;
    if (c == '<') {
      AR.push_back(A[i]);
    }
    else if (c == '>') {
      AL.push_back(A[i]);
    }
  }
  solve(AR, BR);
  solve(AL, BL);
}

int main () {
  srand(time(NULL));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    nuts.push_back(i);
    bolts.push_back(i);
  }
  solve(nuts, bolts);
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  fflush(stdout);
  return 0;
}