#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(long long (i)=(x);(i)<(y);(i)++)
#define RREP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp(x,mp(y,z))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second
#define itm1 fst
#define itm2 snd.fst
#define itm3 snd.snd
#define sz(v) ((int)v.size())
#define oo 2000000000
#define pi acos(-1)
#define MAXN 1000000
#define EPS 1e-9
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef pair<int,ii> tri;
typedef vector<ll> vll;

ll n,m,s,t;
ll dist[20002];
vii adj[20002];

ll dijkstra(){
	REP(i,0,n) dist[i] = oo;
	dist[s] = 0;
	priority_queue<ii> pq;
	pq.push(mp(0,s));
	while(!pq.empty()){
		ii fr = pq.top(); pq.pop();
		ll d = -fr.fst;
		ll u = fr.snd;
		if(d > dist[u]) continue;
		REP(i,0,adj[u].size()){
			ii v = adj[u][i];
			if(dist[u]+ v.snd < dist[v.fst]){
				dist[v.fst] = dist[u] + v.snd;
				pq.push(mp(-dist[v.fst],v.fst));
			}
		}
	}
	return dist[t];
}

int main(){
	int te; cin >> te;
	REP(tc,1,te+1){
		cout << "Case #" << tc <<": ";
		memset(adj,0,sizeof(adj));
		cin >> n >> m >> s >> t;
		REP(i,0,m){
			ll u,v,w;
			cin >> u >> v >> w;
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
		}
		ll ans = dijkstra();
		if(ans == oo) cout << "unreachable" << endl;
		else cout << ans << endl;
	}
	return 0;
}
