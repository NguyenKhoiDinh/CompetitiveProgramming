#include <iostream> 
#include <string>
#include <cstring>  
#include <math.h> 
int f[200005][2][2];
std::string s[2];
int n, numTest;   
void update(int &a, int b) {
  a += b;
  a = std::min(a, 10); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::memset(f, 0, sizeof(f)); 
    for (int i = 0; i < 2; i++) {
      std::cin >> s[i]; 
    }
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int state0 = 0; state0 <= 1; state0++) {
        for (int state1 = 0; state1 <= 1; state1++) {
          if (f[i][state0][state1] == 0) {
            continue; 
          }
          if (state0 == 1 && s[0][i] == '#') {
            continue; 
          }
          if (state1 == 1 && s[1][i] == '#') {
            continue; 
          }
          if (state0 == 0 && state1 == 0 && s[0][i] == '.' && s[1][i] == '.') {
            update(f[i + 1][1][1], f[i][state0][state1]);
            update(f[i + 1][0][0], f[i][state0][state1]);  
          }
          if (state0 == 1 && state1 == 1) {
            update(f[i + 1][0][0], f[i][state0][state1]); 
          }
          if (state0 == 1 && s[1][i] == '#') {
            update(f[i + 1][0][0], f[i][state0][state1]); 
          }
          if (state0 == 0 && s[0][i] == '.' && s[1][i] == '#') {
            update(f[i + 1][1][0], f[i][state0][state1]); 
          }
          if (state0 == 0 && s[0][i] == '.' && state1 == 1) {
            update(f[i + 1][1][0], f[i][state0][state1]); 
          }                                    
          if (s[0][i] == '#' && state1 == 1) {
            update(f[i + 1][0][0], f[i][state0][state1]); 
          }
          if (s[0][i] == '#' && state1 == 0 && s[1][i] == '.') {
            update(f[i + 1][0][1], f[i][state0][state1]); 
          }
          if (state0 == 1 && state1 == 0 && s[1][i] == '.') {
            update(f[i + 1][0][1], f[i][state0][state1]); 
          }
          if (s[0][i] == '#' && s[1][i] == '#') {
            update(f[i + 1][0][0], f[i][state0][state1]); 
          }
          if (state0 == 1 && s[1][i] == '.') {
            update(f[i + 1][0][1], f[i][state0][state1]); 
          }
          if (s[0][i] == '.' && state1 == 1) {
            update(f[i + 1][1][0], f[i][state0][state1]); 
          }
        }
      }
    }
    int ans = f[n][0][0]; 
    if (ans == 0) {
      std::cout << "None";
    }
    else if (ans == 1) {
      std::cout << "Unique"; 
    }
    else {
      std::cout << "Multiple";
    }
    std::cout << std::endl;
  }
  return 0; 
}