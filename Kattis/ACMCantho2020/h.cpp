#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
const int MAX_N = 7;
int a[MAX_N + 3][MAX_N + 3];
long long dp[MAX_N + 3][(1 << (2 * MAX_N)) + 5];
int n;
vector <int> nextState;

vector <int> convertToArray(int row, int mask) {
  int numBit = 2 * n;
  vector <int> res;
  for (int i = 0; i < numBit; i++) {
    res.push_back(mask & 1);
    mask >>= 1;
  }
  return res;
}

bool isGood(int row, const vector <int> &curState, const vector <int> &nextState) {
  vector <int> val;
  if (row % 2 == 0) {
    val.resize(n - 1, 0);
  }
  else {
    val.resize(n, 0);
  }
  if (row % 2 == 0) {
    for (int i = 1; i < 2 * n - 1; i++) {
      if (curState[i] == 1) {
        val[(i - 1) / 2]++;
      }
      if (nextState[i] == 1) {
        val[(i - 1) / 2]++;
      }
    }
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        if (curState[i] == 1 && curState[i + 1] == 0) {
          val[i / 2]++;
          if (i > 0) {
            val[i / 2 - 1]++;
          }
        }
      }
      else {
        if (curState[i] == 1 && curState[i - 1] == 0) {
          if (i < 2 * n - 1) {
            val[i / 2]++;
          }
          if (i > 1) {
            val[i / 2 - 1]++;
          }
        }
      }
    }
  }
  else {
    for (int i = 0; i < 2 * n; i++) {
      if (curState[i] == 1) {
        val[i / 2]++;
      }
      if (nextState[i] == 1) {
        val[i / 2]++;
      }
      if (i % 2 == 0) {
        if (curState[i] == 1 && (i == 0 || curState[i - 1] == 0)) {
          val[i / 2]++;
          if (i > 0) {
            val[i / 2 - 1]++;
          }
        }
      }
      else {
        if (curState[i] == 1 && (i == n - 1 || curState[i + 1] == 0)) {
          val[i / 2]++;
          if (i < 2 * n - 1) {
            val[i / 2 + 1]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < (int) val.size(); i++) {
    if (a[row][i] != -1 && a[row][i] != val[i]) {
      return false;
    }
  }
  return true;
}

vector <int> buildColumn(int row, const vector <int> &curState) {
  vector <int> res;
  if (row % 2 == 1) {
    res.resize(n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        if (curState[i] == 1 && (i == 0 || curState[i - 1] == 0)) {
          res[i / 2] = 1;
        }
      }
      else {
        if (curState[i] == 1 && (i == 2 * n - 1 || curState[i + 1] == 0)) {
          res[i / 2 + 1] = 1;
        }
      }
    }
  }
  else {
    res.resize(n, 0);
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        if (curState[i] == 1 && curState[i + 1] == 0) {
          res[i / 2] = 1;
        }
      }
      else {
        if (curState[i] == 1 && curState[i - 1] == 0) {
          res[i / 2] = 1;
        }
      }
    }
  }
  return res;
}

void backTrack(int row, int curPosition, const vector <pair <int, int> > &nextEdge, const vector <int> &curState, const vector <int> &listColumn, long long &curVal) {
  if (curPosition == (int) nextEdge.size()) {
    if (isGood(row, curState, nextState) == true) {
      int nextMask = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (nextState[i] == 1) {
          nextMask += (1 << i);
        }
      }
      dp[row + 1][nextMask] += curVal;
    }
    return;
  }
  if (listColumn[curPosition] == 0) {
    backTrack(row, curPosition + 1, nextEdge, curState, listColumn, curVal);
    if (nextEdge[curPosition].first != -1 && nextEdge[curPosition].second != -1) {
      nextState[nextEdge[curPosition].first] = 1;
      nextState[nextEdge[curPosition].second] = 1;
      backTrack(row, curPosition + 1, nextEdge, curState, listColumn, curVal);
      nextState[nextEdge[curPosition].first] = 0;
      nextState[nextEdge[curPosition].second] = 0;
    }
  }
  else {
    if (nextEdge[curPosition].first != -1) {
      nextState[nextEdge[curPosition].first] = 1;
      backTrack(row, curPosition + 1, nextEdge, curState, listColumn, curVal);
      nextState[nextEdge[curPosition].first] = 0;
    }
    if (nextEdge[curPosition].second != -1) {
      nextState[nextEdge[curPosition].second] = 1;
      backTrack(row, curPosition + 1, nextEdge, curState, listColumn, curVal);
      nextState[nextEdge[curPosition].second] = 0;
    }
  }
}

void update(int row, int mask, long long &curVal) {
  vector <int> curState = convertToArray(row, mask);
  int nextRow = row + 1;
  int numCol = 2 * n;
  nextState.resize(2 * n, 0);
  vector <int> listColumn = buildColumn(row, curState);
  vector <pair <int, int> > nextEdge;
  nextEdge.resize((int) listColumn.size());
  for (int i = 0; i < (int) nextEdge.size(); i++) {
    nextEdge[i].first = nextEdge[i].second = -1;
  }
  if (row % 2 == 0) {
    for (int i = 0; i < (int) nextEdge.size(); i++) {
      nextEdge[i].first = 2 * i;
      nextEdge[i].second = 2 * i + 1;
    }
  }
  else {
    for (int i = 0; i < (int) nextEdge.size(); i++) {
      if (i < (int) nextEdge.size() - 1) {
        nextEdge[i].second = 2 * i;
      }
      if (i > 0) {
        nextEdge[i].first = 2 * i - 1;
      }
    }
  }
  backTrack(row, 0, nextEdge, curState, listColumn, curVal);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (i % 2 == 1 ? n : n - 1); j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < n - 1; j++) {
    a[0][j] = -1;
  }
  for (int j = 0; j < ((n + 1) % 2 == 1 ? n : n - 1); j++) {
    a[n + 1][j] = -1;
  }
  dp[0][0] = 1;
  for (int row = 0; row <= n + 1; row++) {
    for (int mask = 0; mask < (1 << (2 * n)); mask++) {
      if (dp[row][mask] == 0) {
        continue;
      }
      long long curVal = dp[row][mask];
      update(row, mask, curVal);
    }
  }
  long long ans = dp[n + 2][0];
  cout << ans;
  return 0;
}