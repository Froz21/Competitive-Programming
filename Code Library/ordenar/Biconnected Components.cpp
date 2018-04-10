//2-vertex-connected , Puentes

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])

typedef vector< int > vi;

int n,m,fin;
int orig[N], dest[N], pila[N], top = 0;
vi E[N];
int low[N], dfsn[N], part[N], timer;
int ponte[N], bicomp[N], nbicomp;

int dfsbcc (int u, int p = -1){
	low[u] = dfsn[u] = ++timer;
	int ch = 0;
	REPIT(it, E[u]){
		int e = *it, v = VIZ (e, u);
		if (dfsn[v] == 0){
			pila[top++] = e;
			dfsbcc (v, u);
			low[u] = min (low[u], low[v]);
			ch++;
			if (low[v] >= dfsn[u]){
				part[u] = 1;
				nbicomp++;
				do{
					fin = pila[--top];
					bicomp[fin] = nbicomp;
				}while (fin != e);
			}
			if (low[v] == dfsn[v]) ponte[e] = 1;
		}else if (v!=p && dfsn[v] < dfsn[u]){
			pila[top++] = e;
			low[u] = min (low[u], dfsn[v]);
		}
	}
	return ch;
}
void bcc (){
	f(i,0,n) part[i] = dfsn[i] = 0;
	f(i,0,m) ponte[i] = 0;
	nbicomp = timer = 0;
	f(i,0,n) if (dfsn[i] == 0) part[i] = dfsbcc (i) >= 2;
}

int main(){
	cin >> n >> m;
	f(i,0,m){
		int u,v; cin >> u >> v; u--; v--;
		orig[i] = u;
		dest[i] = v;
		E[u].pb (i);
		E[v].pb (i);
	}
	bcc();
	f(i,0,n) cout << part[i]; cout << endl;
	f(i,0,m) cout << ponte[i]; cout << endl;
	f(i,0,m) cout << bicomp[i]; cout << endl;
}
