#include <iostream>
#include <string>
int n;
int a[105], b[105]; 
int f[105][105][105]; 
int trace[105][105][105]; 
std::string ans = ""; 
void print(int i, int pA, int pB) {
  if (i == 0) {
    return; 
  }
  int pos = trace[i][pA][pB]; 
  if (pos == -1) {
    ans += 'S'; 
    ans += 'C'; 
    print(i - 1, pA + 1, pB + 1); 
  }
  else if (pos == -2) {
    ans += 'S'; 
    print(i - 1, pA + 1, pB); 
    ans += 'C'; 
  }
  else {
    print(pos, pA, pB); 
    print(i - pos, pA + pos, pB + pos); 
  }
}

int main () {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i]; 
  }
  for (int pA = 0; pA <= n; pA++) {
    for (int pB = 0; pB <= n; pB++) {
      f[0][pA][pB] = 1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int pA = 0; pA + i <= n; pA++) {
      for (int pB = 0; pB <= pA; pB++) {
        if (a[pA] == b[pB] && f[i - 1][pA + 1][pB + 1] != 0) {
          f[i][pA][pB] = 1; 
          trace[i][pA][pB] = -1; 
        }
        else if (a[pA] == b[pB + i - 1] && f[i - 1][pA + 1][pB] != 0) {
          f[i][pA][pB] = 1;
          trace[i][pA][pB] = -2; 
        }
        for (int x = 1; x < i; x++) {
          if (f[x][pA][pB] != 0 && f[i - x][pA + x][pB + x] != 0) {
            f[i][pA][pB] = 1; 
            trace[i][pA][pB] = x; 
          }
        }
      }    
    }
  }
  if (f[n][0][0] == 1) {
    std::cout << "YES" << std::endl;
    print(n, 0, 0);
    std::cout << ans;   
  }
  else {
    std::cout << "NO" << std::endl; 
  }
  return 0; 
}