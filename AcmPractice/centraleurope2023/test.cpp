#include <bits/stdc++.h>
using namespace std;
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define ff(i,j,k) for(int i=(j),end_i=(k);i< end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
#define DEBUG(x) cerr<<#x<<"="<<x<<endl
#define all(x) (x).begin(),(x).end()
#define cle(x) memset(x,0,sizeof(x))
#define lowbit(x) ((x)&-(x))
#define VI vector<int>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define lb long db
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
template<class T>inline void read(T &x) {
    x=0; char ch=getchar(); bool f=0;
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch^48);
    if(f) x=-x;
}
template<class T,class... V>
inline void read(T &a,V&... b){read(a); read(b...);}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int n,q;
vector<tuple<int,int,int>> adj[N];
namespace LCA {
    int dfn[N<<1],dfn_tim,dep[N],p[N],l2[N<<1],f[N<<1][20];
    inline int cmp(int x,int y) {
        return dep[x] < dep[y] ? x : y;
    }
    ll dis[N];
    void dfs(int u,int pre) {
        dfn[++ dfn_tim] = u;
        p[u] = dfn_tim;
        dep[u] = dep[pre] + 1;
        for(auto [v,z,i]:adj[u])
            if(v != pre) {
                dis[v] = dis[u] + z;
                dfs(v,u);
                dfn[++ dfn_tim] = u;
            }
    }
    inline int lca(int x,int y) {
        x = p[x]; y = p[y];
        if(x > y)
            swap(x, y);
        int k = l2[y-x+1];
        return cmp(f[x][k],f[y-(1<<k)+1][k]);
    }
    inline ll dist(int x,int y) {
        return dis[x] + dis[y] - (dis[lca(x,y)] << 1);
    }
    void init() {
        dfs(1,0);
        fo(i,2,dfn_tim) l2[i] = l2[i >> 1] + 1;
        fo(i,1,dfn_tim) f[i][0] = dfn[i];
        fo(j,1,19)
            fo(i,1,dfn_tim) {
                f[i][j] = f[i][j-1];
                if(i + (1 << j) - 1 <= dfn_tim)
                    f[i][j] = cmp(f[i][j],f[i+(1<<(j-1))][j-1]);
            }
    }
}
using LCA::lca;
using LCA::dist;

bool vis[N];
int mx[N],siz[N],Cnt,rt;
void calc_siz(int u,int pre) {
    siz[u] = 1; mx[u] = 0;
    for(auto [v,z,i]:adj[u])
        if(v != pre && !vis[v]) {
            calc_siz(v,u);
            siz[u] += siz[v];
            mx[u] = max(mx[u],siz[v]);
        }
    mx[u] = max(mx[u],Cnt - siz[u]);
    if(mx[u] < mx[rt])
        rt = u;
}
int fa[N];
vector<vector<pair<ll,int>>> a[N];
vector<vector<int>> bit[N];
vector<tuple<int,int,int>> query[N];
map<int,int> ma[N];
int now;
void dfs(int u,int pre,ll d) {
    for(auto [v,z,i]:adj[u])
        if(v != pre && !vis[v]) {
            a[rt][now].push_back({d+z,i});
            dfs(v,u,d+z);
        }
}
void divide(int u,int si,int pre_root,int pre_addtional) {
    Cnt = si;
    rt = 0;
    calc_siz(u,0);
    vis[rt] = 1;
    //cerr<<"   "<<rt<<endl;
    fa[rt] = pre_root;
    if(pre_root)
        ma[pre_root][rt] = pre_addtional;
    vector<pair<int,int>> vec;
    for(auto [v,z,i]:adj[rt])
        if(!vis[v])
            vec.pb({v,siz[v]>siz[rt]?(si-siz[rt]):siz[v]});
    a[rt].resize(vec.size()+1);
    bit[rt].resize(vec.size()+1);
    now = 0;
    dfs(rt,0,0);
    for(auto [v,z,i]:adj[rt])
        if(!vis[v]) {
            now ++;
            a[rt][now].push_back({z,i});
            a[rt][now].push_back({0,-i});
            dfs(v,rt,z);
        }
    fo(i,0,vec.size()) {
        sort(all(a[rt][i])),bit[rt][i].resize(a[rt][i].size()+2);
        ff(k,0,a[rt][i].size())
            if(a[rt][i][k].second > 0)
                query[a[rt][i][k].second].push_back({rt,i,k});
            else
                query[-a[rt][i][k].second].push_back({-rt,i,k});
    }
    int now_root = rt;
    int x = 0;
    for(auto [v,ne_si]:vec) {
        divide(v,ne_si,now_root,++x);
    }
}
inline void add(vector<int> &b,int x,int d) {
    for(;x;x-=lowbit(x))
        b[x] += d;
}
inline int ask(vector<int> &b,int x) {
    int ans = 0;
    int n = b.size();
    for(;x<n;x+=lowbit(x))
        ans += b[x];
    return ans;
}
inline void add(int x,int son,ll d,int y) {
    int i = upper_bound(all(a[x][son]),make_pair(d,n+1))-a[x][son].begin()-1;
    //DEBUG(i);
    if(i < 0) return;
    //DEBUG(a[x][son][i].se);
    add(bit[x][son],i+1,y);
}
inline int ask(int x,int son,ll d) {
    int i = upper_bound(all(a[x][son]),make_pair(d,n+1))-a[x][son].begin()-1;
    if(i < 0) return 0;
    return ask(bit[x][son],i+1);
}
inline void add_tree(int x,ll d) {
    int y=x,z;
    add(x,0,d,1);
    for(z=y,y=fa[y];y;z=y,y=fa[y]) {
        add(y,0,d-dist(x,y),1);
        add(y,ma[y][z],d-dist(x,y),-1);
        //cerr<<y<<ma[y][z]<<' '<<d-dist(x,y)<<endl;
    }
}
inline int ask_tree(int x) {
    int ans = 0;
    for(auto [u,son,i]:query[x]) {
        if(u < 0) ans -= ask(bit[-u][son],i+1);
        else ans += ask(bit[u][son],i+1);
        //cerr<<u<<' '<<son<<endl;
    }
    return ans;
}

int main() {
    read(n);
    for(int i = 2;i <= n;i ++) {
        int x,y,z;
        read(x,y,z);
        adj[x].pb({y,z,i-1});
        adj[y].pb({x,z,i-1});
    }
    LCA::init();
    mx[0] = 1e9;
    divide(1,n,0,0);
    //fo(i,1,n) cerr<<i<<"->"<<fa[i]<<endl;
    int T; read(T);
    for(;T--;) {
        char opt[5];
        int x,y;
        scanf("%s",opt);
        read(x);
        if(opt[0] == '+') {
            read(y);
            add_tree(x,y);
        }
        else 
            printf("%d\n",ask_tree(x));
    }
    return 0;
}