#include <bits/stdc++.h> 

using namespace std; 
long long fw[105][105][105];
long long a[105][105][105]; 
int n, numQueries;  
void update(int indexx, int indexy, int indexz, long long value) {
  for (int i = indexx; i <= 100; i += i & -i) {
    for (int j = indexy; j <= 100; j += j & -j) {
      for (int k = indexz; k <= 100; k += k & -k) {
        fw[i][j][k] += value; 
      }
    }
  }
}
long long get(int indexx, int indexy, int indexz) {
  long long ret = 0LL; 
  for (int i = indexx; i > 0; i -= i & -i) {
    for (int j = indexy; j > 0; j -= j & -j) {
      for (int k = indexz; k > 0; k -= k & -k) {
        ret += fw[i][j][k]; 
      }  
    }
  }
  return ret;
}

int main () {      
  int numTest; 
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    memset(fw, 0LL, sizeof(fw));
    memset(a, 0LL, sizeof(a)); 
    cin >> n >> numQueries; 
    for (int query = 1; query <= numQueries; query++) {
      string type; 
      cin >> type; 
      if (type == "UPDATE") {
        int x, y, z;
        long long w; 
        cin >> x >> y >> z >> w;
        long long diff = w - a[x][y][z];  
        update(x, y, z, diff);
        a[x][y][z] = w; 
      }
      else {
        int x1, y1, z1, x2, y2, z2; 
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2; 
        long long ret = get(x2, y2, z2); 
        ret -= get(x2, y2, z1 - 1); 
        ret -= get(x2, y1 - 1, z2); 
        ret -= get(x1 - 1, y2, z2);
        ret += get(x2, y1 - 1, z1 - 1);
        ret += get(x1 - 1, y1 - 1, z2);
        ret += get(x1 - 1, y2, z1 - 1);
        ret -= get(x1 - 1, y1 - 1, z1 - 1);
        cout << ret << endl;   
      }
    }
  }
  return 0; 
}