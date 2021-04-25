#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100; 
int numTest;
int id[MAX_N][MAX_N];
int RA, PA, RB, PB, C, S; 
long long block;
vector <pair <int, int> > save; 
map <pair <pair <long long, int>, pair <long long, int> >, int> dp; 

vector <pair <int, int> > findNext(long long &maskA, int &ID, long long &maskB) {
  pair <int, int> curPos = save[ID];
  long long inValid = block; 
  inValid |= maskA; 
  inValid |= maskB;
  int x = curPos.first; 
  int y = curPos.second; 
  vector <pair <int, int> > nextPos;
  pair <int, int> nxtPos;
  if (y > 1) {
    nxtPos.first = x; 
    nxtPos.second = y - 1; 
    int nextID = id[nxtPos.first][nxtPos.second];
    if ((inValid & (1LL << nextID)) == 0) {
      nextPos.push_back(make_pair(nxtPos.first, nxtPos.second));
    }
  }
  if (y < 2 * x - 1) {
    nxtPos.first = x; 
    nxtPos.second = y + 1; 
    int nextID = id[nxtPos.first][nxtPos.second];
    if ((inValid & (1LL << nextID)) == 0) {
      nextPos.push_back(make_pair(nxtPos.first, nxtPos.second));
    }
  }
  if (x > 1 && y % 2 == 0) {
    nxtPos.first = x - 1; 
    nxtPos.second = y - 1; 
    int nextID = id[nxtPos.first][nxtPos.second];
    if ((inValid & (1LL << nextID)) == 0) {
      nextPos.push_back(make_pair(nxtPos.first, nxtPos.second));
    }
  }
  if (x < S && y % 2 == 1) {
    nxtPos.first = x + 1; 
    nxtPos.second = y + 1; 
    int nextID = id[nxtPos.first][nxtPos.second];
    if ((inValid & (1LL << nextID)) == 0) {
      nextPos.push_back(make_pair(nxtPos.first, nxtPos.second));
    }
  }
  return nextPos;
}

int dfs(pair <long long, int> A, pair <long long, int> B) {
  if (dp.count(make_pair(A, B)) > 0) {
    return dp[make_pair(A, B)];
  }
  vector <pair <int, int> > nextPos = findNext(A.first, A.second, B.first);
  if (nextPos.empty() == false) {
    int value = -100; 
    for (int i = 0; i < (int) nextPos.size(); i++) {
      pair <int, int> position = nextPos[i];
      int ID = id[position.first][position.second];
      long long nxtMask = A.first | (1LL << ID);
      value = max(value, -dfs(B, make_pair(nxtMask, ID)));
    }
    dp[make_pair(A, B)] = value; 
    return value;
  }
  vector <pair <int, int> > nextPos2 = findNext(B.first, B.second, A.first);
  if (nextPos2.empty() == true) {
    int res = __builtin_popcountll(A.first) - __builtin_popcountll(B.first);
    return dp[make_pair(A, B)] = res;
  }
  return -dfs(B, A);
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int ID = 0; 
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 2 * i - 1; j++) {
      save.push_back(make_pair(i, j));
      id[i][j] = ID;
      ID++;
    }
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    dp.clear();
    cin >> S >> RA >> PA >> RB >> PB >> C;
    block = 0LL; 
    for (int i = 1; i <= C; i++) {
      int x, y;
      cin >> x >> y;
      block |= (1LL << id[x][y]);
    }
    int res = dfs(make_pair(1LL << id[RA][PA], id[RA][PA]), make_pair(1LL << id[RB][PB], id[RB][PB]));
    cout << res << endl; 
  }
  return 0;
}