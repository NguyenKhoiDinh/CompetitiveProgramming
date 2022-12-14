#include <bits/stdc++.h> 

using namespace std;
const long long MOD = 1000000007LL;
int row, col; 
int t; 
string a[105];
vector <char> v;   

struct matrix {
  int row, col; 
  vector <vector <long long> > data; 
  matrix(int _row, int _col) {
    row = _row;
    col = _col; 
    data.resize(row); 
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0LL);
    }
  }
  matrix operator * (const matrix &other) {
    matrix ret(row, other.col);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < other.col; j++) {
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += (data[i][k] * other.data[k][j]) % MOD) %= MOD; 
        }
      }
    }
    return ret; 
  }
};

int getId(int x, int y) {
  return x * col + y; 
}

void create(int x, int y, int i, char direction, matrix &M) {
  if (x < 0 || x >= row || y < 0 || y >= col || a[x][y] == '#') {
    return; 
  }
  if (a[x][y] == '+' || a[x][y] == direction) {
    M.data[i][x * col + y] = 1; 
  }
}

matrix POW(const matrix &M, int n) {
  if (n == 1) {
    return M; 
  }
  matrix ret = POW(M, n >> 1); 
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * M; 
  }
  return ret; 
}

int main () {
  cin >> row >> col >> t; 
  int dim = row * col; 
  for (int i = 0; i < row; i++) {
    cin >> a[i]; 
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      v.push_back(a[i][j]); 
    }
  }                         
  matrix base(dim, 1); 
  for (int i = 0; i < dim; i++) {
    if (v[i] != '#') {
      base.data[i][0] = 1; 
    }
  }
  matrix M(dim, dim);
  for (int i = 0; i < dim; i++) {
    if (v[i] != '#') {
      int x = i / col;
      int y = i % col;
      create(x - 1, y, i, 'D', M);
      create(x + 1, y, i, 'U', M);
      create(x, y - 1, i, 'R', M);
      create(x, y + 1, i, 'L', M);   
    }
  }
  matrix ans = POW(M, t);  
  ans = ans * base;
  long long res = 0LL;
  for (int i = 0; i < dim; i++) {
    (res += ans.data[i][0]) %= MOD; 
  }
  cout << res; 
  return 0; 
}