#include <iostream>
#include <vector>
#include <algorithm>
#include <complex> 
#include <string> 
#include <math.h> 
const double PI = std::acos(-1);  
int n, m; 
std::string player; 
std::string machine;
int MAX_LENGTH = 1; 
std::vector <long long> score; 
int revBit(int mask) {
  int i = 0;
  int cnt = 0;
  int len = 1;
  while (len < MAX_LENGTH) {
    len *= 2;
    cnt++; 
  } 
  int j = cnt - 1; 
  while (i < j) {
    if (((mask & (1 << i)) > 0) != ((mask & (1 << j)) > 0)) {
      mask ^= 1 << i;
      mask ^= 1 << j; 
    }
    i++;
    j--; 
  }
  return mask; 
}
void FFT(std::vector <std::complex <double> > &a, const bool &invert) {
  int n = MAX_LENGTH; 
  for (int i = 0; i < n; i++) {
    int j = revBit(i);
    if (i < j) {
      std::swap(a[i], a[j]); 
    }                    
  }
  std::vector <std::complex <double> > next_P(n); 
  for (int step = 1; step < n; step *= 2) {
    double angle = PI / step;
    if (invert == true) {
      angle = -angle; 
    }  
    std::complex <double> w(1.0), wn(std::cos(angle), std::sin(angle));
    std::vector <std::complex <double> > W(step);
    for (int i = 0; i < step; i++) {
      W[i] = w; 
      w *= wn; 
    }
    int posEven = 0;
    int posOdd = step;
    while (posEven < n) {
      for (int i = 0; i < step; i++) {
        next_P[posEven + i] = a[posEven + i] + W[i] * a[posOdd + i];
        next_P[posEven + i + step] = a[posEven + i] - W[i] * a[posOdd + i]; 
      }
      posEven += 2 * step; 
      posOdd = posEven + step; 
    }                    
    for (int i = 0; i < n; i++) {
      a[i] = next_P[i];
    } 
  }
  if (invert == true) {
    for (int i = 0; i < n; i++) {
      a[i] /= n;
    }
  }         
}
void solve(char choiceP, char choiceM, const int &add, std::vector <long long> &score) {
  std::vector <std::complex <double> > P(MAX_LENGTH), M(MAX_LENGTH), H(MAX_LENGTH); 
  for (int i = 0; i < n; i++) {
    if (choiceP == player[i]) {
      P[i] += 1.0; 
    }
  }
  for (int i = 0; i < m; i++) {
    if (choiceM == machine[i]) {
      M[m - i] += 1.0; 
    }
  }
  FFT(P, false);
  FFT(M, false); 
  for (int i = 0; i < MAX_LENGTH; i++) {
    H[i] = P[i] * M[i]; 
  }  
  FFT(H, true); 
  for (int i = 0; i < MAX_LENGTH; i++) {
    score[i] += (long long) add * (llround(H[i].real())); 
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m; 
  while (MAX_LENGTH <= n + m) {
    MAX_LENGTH *= 2; 
  }
  std::cin >> player >> machine;
  score.resize(MAX_LENGTH, 0); 
  solve('P', 'S', 1, score);
  solve('R', 'P', 1, score);
  solve('S', 'R', 1, score);
  long long ans = -1000000007;
  for (int i = 0; i <= n; i++) {
    ans = std::max(ans, score[i + m]); 
  }   
  std::cout << ans;
  return 0; 
}