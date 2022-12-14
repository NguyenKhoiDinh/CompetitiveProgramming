#include <bits/stdc++.h> 

using namespace std; 
int p[9]; 
int C; 
struct element {
  int pA, pB, pC, pD; 
  int lock; 
  int numStep; 
};
vector <element> save; 

void process(int pA, int pB, int pC, int pD, int start, int des) {
  int mask = 0; 
  if (pA == 1) {
    mask |= 1; 
    mask |= 2;
    mask |= 8;
    mask |= 16; 
  }
  if (pB == 1) {
    mask |= 2; 
    mask |= 4; 
    mask |= 16;
    mask |= 32;
  }
  if (pC == 1) {
    mask |= 8; 
    mask |= 16; 
    mask |= 64;
    mask |= 128;
  }
  if (pD == 1) {
    mask |= 16; 
    mask |= 32; 
    mask |= 128;
    mask |= 256;
  }
  int numStep = 0; 
  while (p[4] != p[des]) {
    numStep++; 
    for (int i = 0; i < 9; i++) {
      if ((mask & (1 << i)) > 0) {
        p[i]++; 
        p[i] %= C;
      }
    }
  }
  if (numStep > 0) {
    element e = (element) {pA, pB, pC, pD, start + 1, numStep};
    save.push_back(e); 
  }
}

void rotateOnly(int start) {
  int numStep = 0;                                                                                      
  while (p[start] != p[4]) {
    numStep++; 
    p[start]++; 
    p[start] %= C; 
  }
  if (numStep > 0) {
    save.push_back((element) {0, 0, 0, 0, start + 1, numStep}); 
  }
}

void solve() {
  cout << "YES" << endl; 
  process(1, 1, 0, 0, 0, 7);
  process(0, 1, 0, 1, 2, 3);
  process(0, 0, 1, 1, 8, 1);
  process(1, 0, 1, 0, 6, 5);
  rotateOnly(0); 
  rotateOnly(2);
  rotateOnly(6);
  rotateOnly(8);
  int numStep = 0; 
  while (p[0] != 0) {
    numStep++; 
    p[0]++;
    p[0] %= C; 
  }
  if (numStep > 0) {
    save.push_back((element) {1, 1, 1, 1, 1, numStep}); 
  }
  cout << (int) save.size() << endl; 
  for (int i = 0; i < (int) save.size(); i++) {
    cout << save[i].pA << ' ' << save[i].pB << ' ' << save[i].pC << ' ' << save[i].pD << ' ' << save[i].lock << ' ' << save[i].numStep << endl;
  }
}

int main () {
  cin >> C; 
  for (int i = 0; i < 9; i++) {
    cin >> p[i]; 
  }
  solve(); 
  return 0; 
}