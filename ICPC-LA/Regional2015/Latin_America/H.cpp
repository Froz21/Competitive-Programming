//South America South Finals - 2015-2016 // Problem H - Height Map
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back((x))
#define REP(i,x,y) for(long long (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp((x),mp((y),(z)))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); 
#define fst first
#define snd second
#define sz(v) ((int)v.size())
#define oo 2000000000
#define itm1 fst
#define itm2 snd.fst
#define itm3 snd.snd
#define EPS 1e-9
#define D9 1000000000
#define MOD 1000000007
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;

ll mx[102][102];
ll no[102][102][3][3];
ll vis[102][102];
ll r,c;
ll ans;

bool OK(ll u, ll v){
    if(u <0 || v <0 || u>=r || v>=c) return false;
    return true;
}

void bfs(ll u, ll v){
    queue<ii> q;
    q.push(mp(u,v));
    vis[u][v]++;
    ll val = mx[u][v];
    while(!q.empty()){
        ii fr = q.front(); q.pop();
        ll x = fr.fst;
        ll y = fr.snd;
        REP(dx,-1,2){
            REP(dy,-1,2){
                if(abs(dx) + abs(dy)!=1) continue;
                ll r = x+dx;
                ll s = y+dy;
                if(!OK(r,s)) continue;
                if(!vis[r][s] && mx[r][s] == val){
                    q.push(mp(r,s));
                    vis[r][s]++;
                }
            }
        }
    }
}

void cancel(ll x, ll y, ll dx, ll dy){
    ll val = mx[x][y];
    ll u =x, v=y;
    if(dx!=0){
        while(mx[u][v] > mx[u+dx][v+dy]){
            no[u][v][dx+1][dy+1]=1;
            ll a = mx[u][v];
            ll aa = mx[u+dx][v+dy];
            v++; if(!OK(u,v)) break;
            ll b = mx[u][v];
            ll bb = mx[u+dx][v+dy];
            if(b <= bb) break;
            if(b <= aa) break;
            if(a <=bb) break;
        }
        u =x; v=y;
        while(mx[u][v] > mx[u+dx][v+dy]){
            no[u][v][dx+1][dy+1] = 1;
            ll a = mx[u][v];
            ll aa = mx[u+dx][v+dy];
            v--; if(!OK(u,v)) break;
            ll b = mx[u][v];
            ll bb = mx[u+dx][v+dy];
            if(b <= bb) break;
            if(b <= aa) break;
            if(a <=bb) break;
        }
    }
    else if(dy!=0){
        while(mx[u][v] > mx[u+dx][v+dy]){
            no[u][v][dx+1][dy+1]=1;
            ll a = mx[u][v];
            ll aa = mx[u+dx][v+dy];
            u++; if(!OK(u,v)) break;
            ll b = mx[u][v];
            ll bb = mx[u+dx][v+dy];
            if(b <= bb) break;
            if(b <= aa) break;
            if(a <=bb) break;
        }
        u =x; v=y;
        while(mx[u][v] > mx[u+dx][v+dy]){
            no[u][v][dx+1][dy+1] = 1;
            ll a = mx[u][v];
            ll aa = mx[u+dx][v+dy];
            u--; if(!OK(u,v)) break;
            ll b = mx[u][v];
            ll bb = mx[u+dx][v+dy];
            if(b <= bb) break;
            if(b <= aa) break;
            if(a <=bb) break;
        }
    }
}

int main(){
    fastio;
    while(cin >> r >> c){
        memset(mx,0,sizeof(mx));
        memset(no,0,sizeof(no));
        memset(vis,0,sizeof(vis));
        ans = 0;
        REP(i,0,r){
            REP(j,0,c){
                cin >> mx[i][j];
            }
        }
        REP(x,0,r){
            REP(y,0,c){
                int val = mx[x][y];
                REP(dx,-1,2){
                    REP(dy,-1,2){
                        if(abs(dx) + abs(dy)!=1) continue;
                        ll r = x + dx;
                        ll s = y + dy;
                        if(!OK(r,s)) continue;
                        if(no[x][y][dx+1][dy+1]) continue;
                        if(mx[r][s]<val){
                            ans++;
                            cancel(x,y,dx,dy);
                        }
                    }
                }
            }
        }

        REP(i,0,r){
            REP(j,0,c){
                if(!vis[i][j]){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        cout << ans+5 << endl;
    }
    return 0;   
}
