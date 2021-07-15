#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
const int MAX_N = 2005;
const double inf = -1.000;
const double PI = atan(-1);

struct coordinate {
  double x, y;
};

double sqr(double x) {
  return x * x;
}

double distance(coordinate &A, coordinate &B) {
  return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

vector <coordinate> listPoints, curPoints;
int n;
double dp[10][MAX_N];

void DivideAndConquer(int i, int uleft, int uright, int vleft, int vright) {
  if (uleft > uright) {
    return;
  }
  double best = inf;
  int umid = (uleft + uright) / 2;
  dp[i][umid] = inf;
  int pos = -1;
  for (int v = vleft; v <= umid && v <= vright; v++) {
    if (best < dp[i - 1][v] + distance(curPoints[umid], curPoints[v])) {
      best = dp[i - 1][v] + distance(curPoints[umid], curPoints[v]);
      pos = v;
    }
  }
  dp[i][umid] = best;
  DivideAndConquer(i, uleft, umid - 1, vleft, pos);
  DivideAndConquer(i, umid + 1, uright, pos, vright);
}

void DynamicProgramming() {
  double ans = inf;
  for (int i = 0; i <= 6; i++) {
    for (int u = 0; u < n; u++) {
      dp[i][u] = inf;
    }
  }
  dp[1][0] = 0.0000;
  for (int i = 2; i <= 6; i++) {
    DivideAndConquer(i, 0, n - 1, 0, n - 1);
  }
  double res = inf;
  for (int u = 5; u < n; u++) {
    res = max(res, dp[6][u] + distance(curPoints[u], curPoints[0]));
  }
  cout << fixed << setprecision(15) << res << endl;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    coordinate A;
    cin >> A.x >> A.y;
    listPoints.push_back(A);
  }
  for (int i = 0; i < n; i++) {
    curPoints.clear();
    for (int j = i; j <= i + n - 1; j++) {
      curPoints.push_back(listPoints[j % n]);
    }
    DynamicProgramming();
  }
  return 0;
}