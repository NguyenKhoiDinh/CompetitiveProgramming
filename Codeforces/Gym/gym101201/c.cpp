#include <iostream>

using namespace std;

const int MAX_N = 100005;
int camera[MAX_N];
int n, numbHouse, consecutive;

int main () {
  scanf("%d %d %d", &n, &numbHouse, &consecutive);
  for (int i = 1; i <= numbHouse; i++) {
    int house;
    scanf("%d", &house);
    camera[house] = 1;
  }
  int l = 1;
  int r = consecutive;
  int numbCamera = 0;
  for (int i = l; i <= r; i++) {
    if (camera[i] == 1) {
      numbCamera++;
    }
  }
  int res = 0;
  if (numbCamera < 2) {
    if (numbCamera == 1) {
      if (camera[r] == 1) {
        camera[r - 1] = 1; 
        numbCamera = 2; 
        res++; 
      }
      else {
        camera[r] = 1; 
        numbCamera = 2; 
        res++; 
      }
    }
    else {
      camera[r] = 1; 
      camera[r - 1] = 1; 
      numbCamera = 2; 
      res += 2; 
    }
  }
  for (int i = r + 1; i <= n; i++) {
    if (camera[i] == 1) {
      numbCamera++;
    }
    if (camera[l] == 1) {
      numbCamera--;
    }
    l++;
    if (numbCamera < 2) {
      camera[i] = 1;
      res++;
      numbCamera = 2;
    }
  }
  cout << res;
  return 0;
}