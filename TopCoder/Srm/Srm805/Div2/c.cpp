
#include <bits/stdc++.h> 

using namespace std; 

map <int, int> MX, MY, MZ; 
map <pair <int, int>, int> MXY, MYZ, MZX; 
map <pair <int, pair <int, int> >, int> MXYZ; 

class ThreeDChessRooks {
  public:
  long long count(int C, int R, vector <int> XP, vector <int> YP, vector <int> ZP, int seed) {
    if (R == 2) {
      return 0LL;
    }
    vector<int> X(R), Y(R), Z(R);

    int L = XP.size();
    for (int i=0; i<L; ++i) { X[i]=XP[i]; Y[i]=YP[i]; Z[i]=ZP[i]; }

    long long state = seed;
    for (int i=L; i<R; ++i) {
        state = (state * 1103515245LL + 12345LL) % (1LL << 31);
        X[i] = state % C;
        state = (state * 1103515245LL + 12345LL) % (1LL << 31);
        Y[i] = state % C;
        state = (state * 1103515245LL + 12345LL) % (1LL << 31);
        Z[i] = state % C;
    }
    for (int i = 0; i < R; i++) {
      MX[X[i]]++;
      MY[Y[i]]++;
      MZ[Z[i]]++;
      MXY[make_pair(X[i], Y[i])]++;
      MYZ[make_pair(Y[i], Z[i])]++;
      MZX[make_pair(Z[i], X[i])]++;
      MXYZ[make_pair(X[i], make_pair(Y[i], Z[i]))]++;
    }
    long long res = 0LL; 
    for (map <int, int> :: iterator it = MX.begin(); it != MX.end(); it++) {
      long long value = it->second;
      res += 1LL * value * (value - 1);
    }
    for (map <int, int> :: iterator it = MY.begin(); it != MY.end(); it++) {
      long long value = it->second;
      res += 1LL * value * (value - 1);
    }
    for (map <int, int> :: iterator it = MZ.begin(); it != MZ.end(); it++) {
      long long value = it->second;
      res += 1LL * value * (value - 1);
    }
    for (map <pair <int, int>, int> :: iterator it = MXY.begin(); it != MXY.end(); it++) {
      long long value = it->second; 
      res -= 1LL * value * (value - 1); 
    }
    for (map <pair <int, int>, int> :: iterator it = MYZ.begin(); it != MYZ.end(); it++) {
      long long value = it->second; 
      res -= 1LL * value * (value - 1); 
    }
    for (map <pair <int, int>, int> :: iterator it = MZX.begin(); it != MZX.end(); it++) {
      long long value = it->second; 
      res -= 1LL * value * (value - 1); 
    }
    return res; 
  }
};

ThreeDChessRooks T;

int main () {
  cout << T.count(10,
10,
{9, 2, 3, 4},
{5, 6, 7, 8},
{9, 0, 1, 9},
47474747);
  return 0; 
}