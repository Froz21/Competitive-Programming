//South America South Finals - 2015-2016 // Problem F - Fence the vegetables fail
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back((x))
#define REP(i,x,y) for(long long (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp(mp((x),(y)),z)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); 
//#define NDEBUG 1
#define fst first
#define snd second
#define sz(v) ((int)v.size())
#define oo 200000000
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd 
#define MAXN 2000000002
#define EPS 1e-9
#define D9 1000000009
#define MOD 1000000007
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;
 
ll bit[100009];
ll n;
ll p,v;
tri vec[200002];
map<ll,ll>m;
 
struct point{
  double x,y;
  point(){
    x=y=0.0;
  }
  point(double _x, double _y) : x(_x), y (_y){}
  bool operator < (point other) const{
    if(fabs(x-other.x)>EPS) return x <other.x;
    return y<other.y;
  }
  bool operator == (point other) const{
    return (fabs(x-other.x)<EPS && fabs(y-other.y) < EPS);
  }
  point operator +(const point &p) const{
    return point(x+p.x, y+p.y);
  }
  point operator -(const point &p) const{
    return point(x-p.x,y-p.y);
  }
  point operator *(double c) const{
    return point(x*c,y*c);
  }
  point operator /(double c) const{
    return point(x/c,y/c);
  }
};
 
double cross(point p, point q){ return p.x*q.y - p.y*q.x;}
 
void update(ll id, ll val){
  while(id <=100004){
    bit[id]+=val;
    id+=(id & -id);
  }
}
 
int getVal(ll id){
  ll sum = 0;
  while(id > 1){
    sum+=bit[id];
    id-=(id & -id);
  }
  return sum;
}
 
bool ord1(tri u, tri w){
  if(u.itm2!=w.itm2){
    return u.itm2 < w.itm2;
  }
  else{
    return u.itm1 > w.itm1;
  }
}
 
bool ord2(tri u, tri w){
  if(u.itm1 != w.itm1){
    return u.itm1 < w.itm1;
  }
  else{
    return u.itm2 > w.itm2;
  }
}
 
void checkCollinear(){
  point a = point(vec[p].itm1,vec[p].itm2);
  point b = point(vec[p+1].itm1,vec[p+1].itm2);
  point c = point(vec[p+v-1].itm1,vec[p+v-1].itm2);
  if(fabs(cross(b-a,c-a)) < EPS){
    REP(i,p+1,p+v){
      vec[i-1] = vec[i];
    }
    v--;
  }
}
 
int main(){
  fastio;
  while(cin >> p >> v){
    memset(bit,0,sizeof(bit));
    memset(vec,0,sizeof(vec));
    m.clear();
    REP(i,0,p){
      ll x,y; cin >> x >> y;
      vec[i] = mt(x,y,i+1);
    }
    REP(i,0,v){
      ll x,y; cin >> x >> y;
      vec[i+p] = mt(x,y,0);
    }
    if(vec[v+p-1].itm1!=vec[p].itm1 && vec[v+p-1].itm2!=vec[p].itm2){
      cout << p*(p+1)/2 << endl;
      continue;
    }
    checkCollinear();
    sort(vec,vec+p+v,ord1);
    ll id = 1;
    REP(i,0,p+v){
      if(m[vec[i].itm2]==0) m[vec[i].itm2]= id++;
    }
    sort(vec,vec+p+v,ord2);
    ll cnt = 0;
    REP(i,0,p+v){
      tri fr = vec[i];
      ll u = fr.itm1; ll w= fr.itm2; ll op= fr.itm3;
      ll id = m[w];
      if(op == 0){
        ll k = getVal(id)-getVal(id-1);
        if(k==0){
          update(id,1);
        }
        else update(id,-1);
      }
      else if (op>0){
        ll tot = getVal(100002);
        ll res = getVal(id);
        cnt+= ((tot-res)%2!=1) *op;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
