#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int oo=1e9;
const double pi=acos(-1.0);
#define el '\n'
#define x first
#define y second
#define pb push_back
#define insert ins

#define TEN "buggyrobot"
#define boost ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define fIO freopen(TEN".inp","r",stdin);freopen(TEN".out","w",stdout);
#define fI freopen(TEN".inp","r",stdin);

int n,m;
string cmd;
const int maxN=55;
int a[maxN][maxN];
int dist[maxN][maxN][maxN];

struct node{
	int x,y,pos;
	bool operator < (const node &next) const{
		if (pos < next.pos)
			return true;
		return false;
	}
};

typedef pair<int,node> inode;

priority_queue <inode, vector<inode>, greater<inode> > pq;

void movingByCmd(int i, int j, int pos){
	//left
	if (cmd[pos+1]=='L' && j-1 > 0 && a[i][j-1]!=2){
		if (dist[i][j-1][pos+1] > dist[i][j][pos]){
			dist[i][j-1][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j-1;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='L' && j-1 > 0 && a[i][j-1]==2){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='L' && j-1 == 0){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	//right
	if (cmd[pos+1]=='R' && j+1 <= m && a[i][j+1]!=2){
		if (dist[i][j+1][pos+1] > dist[i][j][pos]){
			dist[i][j+1][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j+1;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='R' && j+1 <= m && a[i][j+1]==2){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='R' && j+1 > m ){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	//up
	if (cmd[pos+1]=='U' && i-1 > 0 && a[i-1][j]!=2){
		if (dist[i-1][j][pos+1] > dist[i][j][pos]){
			dist[i-1][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i-1;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='U' && i-1 > 0 && a[i-1][j]==2){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='U' && i-1 == 0){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	//down
	if (cmd[pos+1]=='D' && i+1 <= n && a[i+1][j]!=2){
		if (dist[i+1][j][pos+1] > dist[i][j][pos]){
			dist[i+1][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i+1;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='D' && i+1 <= n && a[i+1][j]==2){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
	if (cmd[pos+1]=='D' && i+1 > n){
		if (dist[i][j][pos+1] > dist[i][j][pos]){
			dist[i][j][pos+1]=dist[i][j][pos];
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos],l));
		}
	}
}

void fixCmd(int i, int j, int pos){
	//delete
	if (pos == cmd.length()-1){
		if (dist[i][j][pos+1] > dist[i][j][pos]+1){
			dist[i][j][pos+1]=dist[i][j][pos]+1;
			node l;
			l.x=i;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos]+1,l));
		}
	}
	//left
	if (j-1 > 0 && a[i][j-1]!=2){
		if (dist[i][j-1][pos] > dist[i][j][pos]+1){
			dist[i][j-1][pos]=dist[i][j][pos]+1;
			node l;
			l.x=i;
			l.y=j-1;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos]+1,l));
		}
	}
	//right
	if (j+1 <= m && a[i][j+1]!=2){
		if (dist[i][j+1][pos] > dist[i][j][pos]+1){
			dist[i][j+1][pos]=dist[i][j][pos]+1;
			node l;
			l.x=i;
			l.y=j+1;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos]+1,l));
		}
	}
	//up
	if (i-1 > 0 && a[i-1][j]!=2){
		if (dist[i-1][j][pos] > dist[i][j][pos]+1){
			dist[i-1][j][pos]=dist[i][j][pos]+1;
			node l;
			l.x=i-1;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos]+1,l));
		}
	}
	//down
	if (i+1 <= n && a[i+1][j]!=2){
		if (dist[i+1][j][pos] > dist[i][j][pos]+1){
			dist[i+1][j][pos]=dist[i][j][pos]+1;
			node l;
			l.x=i+1;
			l.y=j;
			l.pos=pos+1;
			pq.push(inode(dist[i][j][pos]+1,l));
		}
	}
}

int main()
{
	boost
	// fI

	cin >> n >> m;
	ii s,e;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=0;
			char t;
			cin >> t;
			if (t=='R'){
				a[i][j]=1;
				s.x=i;
				s.y=j;
			}
			if (t=='E'){
				a[i][j]=3;
				e.x=i;
				e.y=j;
			}
			if (t=='#'){
				a[i][j]=2;
			}
			cout << a[i][j];
		}
		cout << el;
	}

	cout << el;

	cin >> cmd;
	//int l=cmd.length();
	cmd=' '+cmd;

	// memset(dist,oo,sizeof(dist));

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<=cmd.length();k++){
				dist[i][j][k]=oo;
			}
		}
	}

	dist[s.x][s.y][0]=0;

	node l;
	l.x=s.x;
	l.y=s.y;
	l.pos=0;

	pq.push(inode(0,l));

	while(pq.size()){
		int dxy=pq.top().x;
		int ux=pq.top().y.x;
		int uy=pq.top().y.y;
		int pos=pq.top().y.pos;
		cout << dxy <<' '<< ux <<' '<< uy <<' '<< pos << el;
		pq.pop();
		if (ux==e.x && uy==e.y){
			cout << dist[e.x][e.y][pos] << el;
			return 0;
		}
		if (dxy!=dist[ux][uy][pos]) continue;
		movingByCmd(ux,uy,pos);
		fixCmd(ux,uy,pos);
	}

	return 0;
}