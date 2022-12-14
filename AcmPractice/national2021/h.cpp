#include <bits/stdc++.h> 

using namespace std; 
const long long MOD = 1000000007; 
struct matrix {
  int row, col; 
  vector <vector <long long> > data; 
  matrix(int _row, int _col) {
    row = _row; 
    col = _col; 
    data.resize(row); 
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0); 
    }
  }
  matrix operator * (const matrix &other) {
    matrix ret(row, other.col); 
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < other.col; j++) {
        long long sum = 0LL; 
        for (int k = 0; k < col; k++) {
          (sum += (data[i][k] * other.data[k][j]) % MOD) %= MOD; 
        }
        ret.data[i][j] = sum; 
      }
    }
    return ret; 
  }
};
struct element {
  int x; 
  long long y; 
  bool operator < (const element &other) {
    return y < other.y; 
  }
};
int r, k;
long long n;            
vector <pair <long long, int> > listElement;
map <long long, int> M;
bool adj[64][64]; 

matrix POW(const matrix &M, long long n) {
  if (n == 1) {
    return M; 
  }
  matrix ret = POW(M, n / 2); 
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * M; 
  }
  return ret; 
}

void createState() {
  for (int mask = 0; mask < (1 << r); mask++) {
    for (int nextmask = 0; nextmask < (1 << r); nextmask++) {
      bool valid = true;
      int newMask = nextmask;
      for (int i = 0; i < r; i++) {
        if ((mask & (1 << i)) == 0) {
          if ((nextmask & (1 << i)) == 0) {
            valid = false; 
          }
          newMask ^= (1 << i); 
        }
      }
      if (valid == false) {
        continue; 
      }  
      for (int i = 0; i < r; i++) {
        if ((newMask & (1 << i)) > 0) {
          if ((newMask & (1 << (i + 1))) > 0) {
            i++; 
          }
          else {
            valid = false; 
            break; 
          }
        }
      }
      if (valid == true) {
        adj[mask][nextmask] = true; 
      }
    }
  }  
}

int main () {
  cin >> r >> n >> k; 
  createState();
  for (int i = 1; i <= k; i++) {
    long long y;
    int x; 
    cin >> x >> y;
    x--;
    y--;
    M[y] |= (1 << x); 
  }
  for (map <long long, int> :: iterator it = M.begin(); it != M.end(); it++) {
    listElement.push_back(make_pair(it->first, it->second)); 
  }
  listElement.push_back(make_pair(n, 0)); 
  matrix ans(1, 1 << r);
  ans.data[0][(1 << r) - 1] = 1; 
  matrix base(1 << r, 1 << r);
  for (int mask = 0; mask < (1 << r); mask++) {
    for (int nextmask = 0; nextmask < (1 << r); nextmask++) {
      if (adj[mask][nextmask] == true) {
        base.data[mask][nextmask] = 1; 
      }
    }
  }
  long long prev = 0LL;
  for (int i = 0; i < (int) listElement.size(); i++) {
    pair <long long, int> pr = listElement[i]; 
    long long y = pr.first; 
    int state = pr.second; 
    long long pw = y - prev; 
    prev = y + 1; 
    if (pw > 0) {
      matrix M = base; 
      M = POW(M, pw); 
      ans = ans * M; 
    }
    if (y == n) {
      break; 
    }
    matrix B(1 << r, 1 << r); 
    for (int mask = 0; mask < (1 << r); mask++) {
      for (int nextmask = 0; nextmask < (1 << r); nextmask++) {
        bool valid = true;
        int newmask = nextmask;
        for (int b = 0; b < r; b++) {
          if ((state & (1 << b)) > 0) {
            if ((mask & (1 << b)) == 0) {
              valid = false; 
            }
            if ((nextmask & (1 << b)) == 0) {
              valid = false;
            }
            newmask ^= (1 << b);
          } 
          else {
            if ((mask & (1 << b)) == 0) {
              if ((nextmask & (1 << b)) == 0) {
                valid = false;
              }
              newmask ^= (1 << b);
            }
          }
        }
        if (valid == false) {
          continue; 
        }
        for (int b = 0; b < r; b++) {
          if ((newmask & (1 << b)) > 0) {
            if ((newmask & (1 << (b + 1))) > 0) {
              b++; 
            }
            else {
              valid = false; 
              break; 
            }
          }
        }
        if (valid == true) {
          B.data[mask][nextmask] = 1; 
        }  
      }
    }
    ans = ans * B;               
  }            
  cout << ans.data[0][(1 << r) - 1]; 
  return 0; 
}