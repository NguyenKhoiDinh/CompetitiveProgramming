#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin>> n >> m;
	vector<int>a(n+1,0);
	vector<int>b(m+1,0);
	for(int i =1;i<=n;i++) cin>> a[i];
	for(int i =1;i<=m;i++) cin>> b[i];
	vector<vector<int>> f(n+1, vector<int>(m+1,0));
	for(int i =0;i<n;i++){
		for(int j =0;j< m;j++){
			f[i+1][j] = max(f[i+1][j], f[i][j]);
			f[i][j+1] = max(f[i][j+1],f[i][j]);
			if(a[i+1]==b[j+1]){
				f[i+1][j+1] = max(f[i+1][j+1],max(f[max(i-1,0)][max(j-1,0)]+1, max(f[i+1][j], f[i][j+1])));
			}
		}
	}
	cout<< f[n][m]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
