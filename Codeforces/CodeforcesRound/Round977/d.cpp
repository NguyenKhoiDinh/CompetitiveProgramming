#include <bits/stdc++.h>

using namespace std;
const long long inf = 10000000000000007LL;                 
int n, m;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;   
    vector <vector <long long> > a, fL, fR, sum;
    a.resize(n);
    fL.resize(n);
    fR.resize(n); 
    sum.resize(n); 
    for (int i = 0; i < n; i++) {
      a[i].resize(m);
      fL[i].resize(m, -inf); 
      fR[i].resize(m, -inf); 
      sum[i].resize(m);
      for (int j = 0; j < m; j++) {
        cin >> a[i][j]; 
      }
    }  
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        sum[i][j] = sum[i][j - 1] + a[i][j]; 
      }
    }
    long long maxSum = -inf; 
    for (int j = m - 1; j >= 0; j--) {
      maxSum = max(maxSum, sum[0][j]); 
      fL[0][j] = a[0][j] - sum[0][j] + maxSum; 
    }
    maxSum = -inf; 
    for (int j = 0; j < m; j++) {
      maxSum = max(maxSum, a[0][j] - sum[0][j]); 
      fR[0][j] = sum[0][j] + maxSum;  
    }
    for (int i = 1; i < n; i++) {
      vector <long long> maxf(m, -inf); 
      vector <long long> maxRight(m); 
      for (int j = 1; j < m - 1; j++) {
        maxf[j] = max(fL[i - 1][j], fR[i - 1][j]);  
      }
      maxRight[m - 1] = sum[i][m - 1]; 
      for (int j = m - 2; j >= 0; j--) {
        maxRight[j] = max(maxRight[j + 1], sum[i][j]);
        fL[i][j] = fR[i - 1][j] + maxRight[j + 1] + a[i][j] - sum[i][j];  
      }
      for (int j = m - 2; j >= 0; j--) {
        maxf[j] += maxRight[j + 1]; 
      }                  
      for (int j = m - 3; j >= 0; j--) {
        maxf[j] = max(maxf[j], maxf[j + 1]); 
      }
      for (int l = 0; l < m - 2; l++) {
        fL[i][l] = max(fL[i][l], a[i][l] - sum[i][l] + maxf[l + 1]); 
      }
      for (int j = 0; j < m; j++) {
        maxRight[j] = fL[i - 1][j] + sum[i][j]; 
      }
      for (int j = m - 2; j >= 0; j--) {
        maxRight[j] = max(maxRight[j], maxRight[j + 1]); 
      }
      for (int l = 0; l < m - 1; l++) {
        fL[i][l] = max(fL[i][l], maxRight[l + 1] + a[i][l] - sum[i][l]);
      }
      vector <long long> maxLeft(m); 
      for (int j = 1; j < m - 1; j++) {
        maxf[j] = max(fL[i - 1][j], fR[i - 1][j]); 
      }
      maxLeft[0] = a[i][0] - sum[i][0]; 
      for (int j = 1; j < m; j++) {
        maxLeft[j] = max(maxLeft[j - 1], a[i][j] - sum[i][j]);
        fR[i][j] = fL[i - 1][j] + maxLeft[j - 1] + sum[i][j];  
      }
      for (int j = 1; j < m; j++) {
        maxf[j] += maxLeft[j - 1]; 
      }
      for (int j = 2; j < m; j++) {
        maxf[j] = max(maxf[j], maxf[j - 1]); 
      }
      for (int r = 2; r < m; r++) {
        fR[i][r] = max(fR[i][r], sum[i][r] + maxf[r - 1]); 
      }            
      for (int j = 0; j < m; j++) {                                   
        maxLeft[j] = fR[i - 1][j] + a[i][j] - sum[i][j]; 
      }
      for (int j = 1; j < m; j++) {
        maxLeft[j] = max(maxLeft[j], maxLeft[j - 1]); 
      }
      for (int r = 1; r < m; r++) {
        fR[i][r] = max(fR[i][r], maxLeft[r - 1] + sum[i][r]); 
      } 
    }
    long long ans = -inf; 
    for (int j = 0; j < m; j++) {
      ans = max(ans, max(fL[n - 1][j], fR[n - 1][j])); 
    }
    cout << ans << endl;
  }
  return 0; 
}