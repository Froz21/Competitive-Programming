#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define trace(x) cerr << #x << ": " << x << '\n'
#define trace2(x,y) cerr << #x << ": " << x << " | " << #y << ": " << y << '\n';
#define trace3(x,y,z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << '\n';
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz(v) ((int)v.size())
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define RREP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> ii;

const int MOD = 1e9 + 7;
const int oo = 1e9;
const ll INF = 1e18;
const long double EPS = 1e-11;

const int N = 1e3 + 2;

vector<ii> adj[N];
int ans[N][N], aux[N][N], ret[N][N];

int n;

void solve(int u){
	REP(i,0,sz(adj[u])){
		int v = adj[u][i].fst, w = adj[u][i].snd;
		REP(j, 1, n+1){
			ret[v][j] += aux[u][j] * w; 
		}
	}
}

void expand(int u){
	REP(i,0,sz(adj[u])){
		aux[u][adj[u][i].fst] += adj[u][i].snd;
	}
}


int main(){
	fastio; 
	while(cin >> n && n != 0){
	int gg = 0;
	memset(ans,0,sizeof(ans)); memset(ret,0,sizeof(ret));
	memset(aux,0,sizeof(aux));
	REP(i,1, n+1) adj[i].clear();
	REP(i,1, n+1) REP(j, 1, n + 1){
		int x; cin >> x;
		adj[i].pb(mp(j,x));
	}
	REP(i,1,n+1) expand(i);
	REP(i,1,n+1) solve(i);
	REP(i,1,n+1){
		REP(j,1,n+1){
			cin >> ans[i][j];
			cout << ans[i][j] << endl;
		}
	}

	REP(i,1,n+1) REP(j, 1, n+1){
		if(ans[i][j] != ret[i][j]){
			cout << "NO" << endl;
			gg ++; break;
		}
	}
	if(!gg) cout << "YES" << endl;
	}
	return 0;
}
