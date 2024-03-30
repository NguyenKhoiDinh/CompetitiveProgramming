#include <iostream>
#include <vector>
int numTest; 
std::vector <int> binary = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000,
10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000}; 
bool check[100005]; 

void backTrack(int numb) {
  check[numb] = true; 
  for (int i = 0; i < (int) binary.size(); i++) {
    if (numb <= 100000 / binary[i] && check[numb * binary[i]] == false) {
      backTrack(numb * binary[i]);   
    }
  }  
}

int main () {
  backTrack(1); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    std::cout << (check[n] == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}