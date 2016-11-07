//South America South Finals - 2015-2016 // Problem E - Exposing Corruption
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
#define D9 1000000000
#define MOD 1000000007
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii,ull> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;
typedef vector<ll> vll;

int d,p,r,b;
vi adj[202];
int prc[202];
int vis[202];
int dp1[202][10002];
int dp2[202][10002];
int tot,ap1,ap2;
vi we,val1,val2;

int ks2(int id,int remW){
    if(dp2[id][remW]!=-1) return dp2[id][remW];
    if(remW==0) return dp2[id][remW]=0;
    if(id==sz(we)) return dp2[id][remW]=0;
    if(we[id]>remW) return dp2[id][remW]=ks2(id+1,remW);
    if(we[id]<=remW) return dp2[id][remW]=max(ks2(id+1,remW),val2[id]+ks2(id+1,remW-we[id]));
}

int ks1(int id,int remW){
    if(dp1[id][remW]!=-1) return dp1[id][remW];
    if(remW==0) return dp1[id][remW]=0;
    if(id==sz(we)) return dp1[id][remW]=0;
    if(we[id]>remW) return dp1[id][remW]=ks1(id+1,remW);
    if(we[id]<=remW) return dp1[id][remW]=max(ks1(id+1,remW),val1[id]+ks1(id+1,remW-we[id]));
}

void solve(){
    cout << d +ks1(0,b) << " ";
    cout << p +ks2(0,b) << endl;
}

void dfs(int u){
    vis[u]++;
    if(u<=100) ap1++;
    else if(u>100) ap2++; 
    tot+= prc[u];
    REP(i,0,sz(adj[u])){
        int w=adj[u][i];
        if(!vis[w]){
            dfs(w);
        }
    }
}

void findcc(){
    REP(i,1,d+1){
        if(!vis[i]){
            ap1 = ap2 = tot = 0 ;
            dfs(i);
            we.pb(tot); val1.pb(ap2-ap1); val2.pb(ap1-ap2);
        }
    }
    REP(i,101,p+101){
        if(!vis[i]){
            ap1 = ap2 = tot = 0 ;
            dfs(i);
            we.pb(tot); val1.pb(ap2-ap1); val2.pb(ap1-ap2);
        }
    }
}

int main(){
    fastio;
    while(cin >> d){
        cin >> p >> r >> b;
        //Inicializacion
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        memset(vis,0,sizeof(vis));
        memset(prc,0,sizeof(prc));
        REP(i,0,202) adj[i].clear();
        we.clear(); val1.clear(); val2.clear();
        
        REP(i,1,d+1){
            int a; cin >> a;
            prc[i]=a;
        }   
        REP(i,1,p+1){
            int a; cin >> a;
            prc[i+100]=a;
        }
        REP(i,0,r){
            int x,y; cin >> x >> y; y+=100;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        findcc();
        solve();
    }
    return 0;
}
