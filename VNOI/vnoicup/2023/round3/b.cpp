#include <iostream>
#include <math.h> 
#include <string> 
int numTest; 
int n, a, b;
std::string s; 
bool visited[105][105]; 

void dfs(int x, int y) {
  if (visited[0][n] == true) {
    return; 
  }
  visited[x][y] = true; 
  for (int i = a; i <= b; i++) {
    for (int numb = std::min(i, x); numb >= 0; numb--) {
      int numbZero = numb; 
      int numbOne = i - numb; 
      if (numbOne > y) {
        continue; 
      }
      int newZero = x - numbZero + numbOne; 
      int newOne = y - numbOne + numbZero; 
      if (visited[newZero][newOne] == true) {
        continue; 
      }
      if (newZero == 0 && newOne == n) {
        visited[0][n] = true;
        return;   
      }
      visited[newZero][newOne] = true; 
      dfs(newZero, newOne); 
    }
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> a >> b;
    std::cin >> s; 
    int cntZero = 0; 
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cntZero++;
      } 
    }
    int cntOne = n - cntZero; 
    for (int i = 0; i <= n; i++) {
      visited[i][n - i] = false; 
    }
    dfs(cntZero, cntOne); 
    if (visited[0][n] == true) {
      std::cout << "YES";
    }
    else {
      std::cout << "NO"; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}