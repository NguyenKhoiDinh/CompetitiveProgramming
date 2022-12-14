// using Minimum Enclosing Circle - Welzl's algorithm
// with average complexity of O(N)
// Source: https://www.geeksforgeeks.org/minimum-enclosing-circle-set-2-welzls-algorithm/

#include<bits/stdc++.h>
using namespace std;
const int MAX=125255;
const double eps=1e-14;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Point{
    double x,y;
    Point operator + (const Point &o){return {x+o.x,y+o.y};}
    Point operator - (const Point &o){return {x-o.x,y-o.y};}
    Point operator / (int cf){return {x/cf,y/cf};}
    double dist(){return sqrt(x*x+y*y);}
} a[MAX];
struct Circle{
    Point I;
    double R;
    Circle(Point _I, double _R): I(_I), R(_R){}
    bool inside(Point A){
        return (I-A).dist()<R+eps;
    }
};
struct Welzl{
private:
    Point get_circle_center(double bx, double by,
                            double cx, double cy){
        double B=bx*bx+by*by, C=cx*cx+cy*cy, D=(bx*cy-by*cx)*2;
        return {(cy*B-by*C)/D,(bx*C-cx*B)/D};
    }
    // Function to return a unique circle that intersects three points
    Circle circumCircle(Point A, Point B, Point C){
        Point I=get_circle_center(B.x-A.x, B.y-A.y, C.x-A.x, C.y-A.y);
        return {I+A, I.dist()};
    }
public:
    Circle getMEC(int n){
        shuffle(a+1,a+n+1,rng); // with randomness, average complexity will decrease a ton.
        Circle O(a[1],0);
        for(int i=2;i<=n;i++) if(!O.inside(a[i])){
            O=Circle(a[i],0);
            for(int j=1;j<i;j++) if(!O.inside(a[j])){
                O=Circle((a[i]+a[j])/2,(a[i]-a[j]).dist()/2);
                for(int k=1;k<j;k++)
                    if(!O.inside(a[k])) O=circumCircle(a[i],a[j],a[k]);
            }
        }
        return O;
    }
} OMG;
int n;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    cout<<fixed<<setprecision(15);
    for(int i=1,id=0;i<=n;i++){
        for(int j=id+1;j<=id+i;j++) cin>>a[j].x>>a[j].y;
        id+=i;
        Circle ans=OMG.getMEC(id);
        cout<<ans.I.x<<' '<<ans.I.y<<' '<<ans.R<<'\n';
    }
    return 0;
}