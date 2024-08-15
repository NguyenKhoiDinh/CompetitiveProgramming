#include <iostream> 
#include <math.h> 
const long long inf = 1000000000000000007LL; 
long long cost[2005][2005]; 
long long sum[2005], sum2[2005]; 
long long a[2005]; 
long long f[2005][2005];
int n, g, k; 

long long getSum(const int &l, const int &r) {
  return sum[r] - sum[l - 1]; 
}

long long getSum2(const int &l, const int &r) {
  return sum2[r] - sum2[l - 1]; 
}

void init() {
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i]; 
  }  
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int mid = (l + r) / 2; 
      cost[l][r] = a[mid] * (mid - l + 1LL) - getSum(l, mid) + getSum(mid, r) - a[mid] * (r - mid + 1); 
    }
  }
}

void init2() {
  for (int i = 1; i <= n; i++) {
    sum2[i] = sum2[i - 1] + a[i] * a[i]; 
    sum[i] = sum[i - 1] + a[i];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      long long A = r - l + 1; 
      long long B = -2LL * getSum(l, r); 
      long long value = -B / (2LL * A); 
      cost[l][r] = inf; 
      for (long long v = value - 2; v <= value + 2; v++) {
        long long currentValue = getSum2(l, r) + A * v * v - 2LL * getSum(l, r) * v;
        cost[l][r] = std::min(cost[l][r], currentValue); 
      }
    }
  }
}

void compute(const int &l, const int &r, const int &group, const int &optl, const int &optr) {
  if (l > r) {
    return; 
  }
  int mid = (l + r) / 2; 
  long long best = inf; 
  int opt = optl; 
  for (int x = optl; x <= std::min(mid, optr); x++) {
    if (best > f[x - 1][group - 1] + cost[x][mid]) {
      best = f[x - 1][group - 1] + cost[x][mid]; 
      opt = x; 
    }
  }
  f[mid][group] = best; 
  compute(l, mid - 1, group, optl, opt);
  compute(mid + 1, r, group, opt, optr); 
}

int main () {
  std::cin >> n >> g >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  if (k == 1) {
    init(); 
  }
  else {
    init2(); 
  }
  for (int i = 1; i <= n; i++) {
    f[i][1] = cost[1][i]; 
  }     
  for (int j = 2; j <= g; j++) {
    compute(2, n, j, 2, n); 
  }
  std::cout << f[n][g]; 
  return 0; 
}