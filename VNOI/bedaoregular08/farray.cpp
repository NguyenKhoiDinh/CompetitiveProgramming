#include <iostream>
#include <vector>
const long long mod = 1058375681LL;
int n, numQuery;
std::vector <long long> F1, F2, sumF1, sumF2;
struct node {
  int color1, color2;
  int lazy1, lazy2;
  long long sum1, sum2;
  long long lazySum1, lazySum2;  
  node() {
    color1 = 0;
    color2 = 0;
    lazy1 = 0;
    lazy2 = 0;  
    sum1 = 0LL; 
    sum2 = 0LL;
    lazySum1 = 0LL;
    lazySum2 = 0LL;
  }
};
node it[4 * 100005];  
long long ans = 0LL; 
         
struct matrix {
  int row, col; 
  std::vector <std::vector <long long> > data; 
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
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += (data[i][k] * other.data[k][j]) % mod) %= mod; 
        }
      }
    } 
    return ret; 
  }
};

matrix A(1, 2), base(2, 2); 

void create(std::vector <long long> &F, std::vector <long long> &sum, int v1, int v2) {
  F.resize(n + 1);
  sum.resize(n + 1);
  F[0] = v1; 
  F[1] = v2; 
  sum[0] = v1;
  sum[1] = v1 + v2;
  for (int i = 2; i <= n; i++) {
    F[i] = (2LL * F[i - 2] + F[i - 1]) % mod; 
    sum[i] = (sum[i - 1] + F[i]) % mod; 
  }
} 

matrix POW(const matrix &M, int n) {
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

long long calc(int k) {
  if (k <= 1) {
    return (long long) k; 
  }  
  matrix M = POW(base, k - 1);
  M = A * M;
  return M.data[0][1]; 
}

void down(int index) {
  it[2 * index].color1 = it[index].color1;
  it[2 * index].color2 = it[index].color2;
  it[2 * index].lazy1 = it[index].color1;
  it[2 * index].lazy2 = it[index].color2;
  it[2 * index].sum1 = it[index].sum1;
  it[2 * index].sum2 = it[index].sum2;
  it[2 * index].lazySum1 = it[index].sum1;
  it[2 * index].lazySum2 = it[index].sum2;
 
  it[2 * index + 1].color1 = it[index].color1;
  it[2 * index + 1].color2 = it[index].color2;
  it[2 * index + 1].lazy1 = it[index].color1;
  it[2 * index + 1].lazy2 = it[index].color2;
  it[2 * index + 1].sum1 = it[index].sum1;
  it[2 * index + 1].sum2 = it[index].sum2;
  it[2 * index + 1].lazySum1 = it[index].sum1;
  it[2 * index + 1].lazySum2 = it[index].sum2;

  it[index].lazy1 = 0;
  it[index].lazy2 = 0;
  it[index].lazySum1 = 0LL; 
  it[index].lazySum2 = 0LL; 
}

void update(int index, int L, int R, int le, int ri, const long long &value1, const long long &value2) {
  if (le <= L && R <= ri) {
    it[index].color1 = value1;
    it[index].lazy1 = value1;
    it[index].color2 = value2;
    it[index].lazy2 = value2;
    it[index].sum1 = 1LL * (sumF1[R] - sumF1[L - 1] + mod) % mod * value1 % mod; 
    it[index].sum2 = 1LL * (sumF2[R] - sumF2[L - 1] + mod) % mod * value2 % mod; 
    return; 
  }       
  if (L > ri || le > R) {
    return; 
  }
  down(index); 
  int mid = (L + R) / 2;
  update(2 * index, L, mid, le, ri, value1, value2);
  update(2 * index + 1, mid + 1, R, le, ri, value1, value2);
  if (it[2 * index].color1 == it[2 * index + 1].color1) {
    it[index].color1 = it[2 * index].color1; 
    it[index].color2 = it[2 * index].color2; 
  }
  else {
    it[index].color1 = 0;
    it[index].color2 = 0;
  }
  it[index].sum1 = it[2 * index].sum1 + it[2 * index + 1].sum1;
  it[index].sum2 = it[2 * index].sum2 + it[2 * index + 1].sum2;
}

void solve(int index, int L, int R, int le, int ri) {
  if (le <= L && R <= ri) {
    (ans += it[index].sum1) %= mod;
    (ans += it[index].sum2) %= mod;
    return;
  }
  if (le > R || L > ri) {
    return; 
  }   
  down(index); 
  int mid = (L + R) / 2;
  solve(2 * index, L, mid, le, ri);
  solve(2 * index + 1, mid + 1, R, le, ri);
}
                          
int main () {
  std::cin >> n >> numQuery;
  create(F1, sumF1, 1, 0);
  create(F2, sumF2, 0, 1);
  A.data[0][0] = 0;
  A.data[0][1] = 1; 
  base.data[0][0] = 0;
  base.data[0][1] = 1; 
  base.data[1][0] = 2; 
  base.data[1][1] = 1;
  for (int query = 1; query <= numQuery; query++) {
    int type, l, r;
    std::cin >> type >> l >> r; 
    if (type == 1) {
      int k;
      std::cin >> k;
      long long Fk1 = calc(k - 1);
      long long Fk2 = calc(k);
      update(1, 1, n, l, r, Fk1, Fk2);                 
    }
    else {
      ans = 0LL;
      solve(1, 1, n, l, r);  
      std::cout << ans << std::endl; 
    }
  } 
  return 0; 
}                   