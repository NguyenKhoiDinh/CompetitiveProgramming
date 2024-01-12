#include <iostream>
#include <vector>
int numTest; 
std::vector <int> fw1, fw2; 
int n;
int a[300005]; 

void update(int index, int value, std::vector <int> &fw) {
  for (; index <= n; index += index & -index) {
    fw[index] += value; 
  }
}

int get(int index, std::vector <int> &fw) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    fw1.clear();
    fw2.clear();
    fw1.resize(n + 1, 0);
    fw2.resize(n + 1, 0);
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int numb = get(a[i] - 1, fw2); 
      int numbSmaller = get(a[i] - 1, fw1); 
      if (numbSmaller > 0 && numb == 0) {
        ans++; 
      }
      int value = (numbSmaller > 0);
      update(a[i], value, fw2);
      update(a[i], 1, fw1); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}