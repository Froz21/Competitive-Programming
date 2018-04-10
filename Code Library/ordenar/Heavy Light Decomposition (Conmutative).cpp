//Heavy-Light Decomposition Tree for Commutative Operations
//Phibrain
 
inline ll ma(ll a, ll b){return ((a-b>0)? a:b);}
inline ll mi(ll a, ll b){return ((a-b>0)? b:a);}

struct ST{
    ll n;
    ll t[2*N];
    ll Op(ll &u, ll &v){ return ma(u,v); }
    inline void build(){
        RREP(i,n-1,1) t[i]=Op(t[i<<1], t[i<<1|1]);
    }
    inline void modify(ll p, ll val){
        for(t[p+=n] = val ; p >>= 1;) t[p] = Op(t[p<<1], t[p<<1|1]);
    }
    inline ll que(ll l, ll r){
        ll ansl=min, ansr=min;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ansl = Op(ansl, t[l++]);
            if(r&1) ansr = Op(t[--r], ansr);
        }
        return Op(ansl, ansr);
    }   
};
struct HLDES{
    ll n;
    ST st;
    vi adj[N];
    ll p[N],d[N],tsz[N],id[N],rt[N];
    ll gid;
    inline ll Op(ll val1, ll val2) {return ma(val1,val2);}
    inline ll make1(ll u,ll par,ll depth){
        p[u]=par; d[u]=depth; tsz[u]=1;
        for(auto v:adj[u])if(v!=p[u]) tsz[u]+=make1(v,u,depth+1);
        return tsz[u];
    }
    inline void make(){
        ll val=make1(0,-1,0);
    }
    inline void dfs(ll u, ll root){
        id[u]=gid++; rt[u]=root;
        ll w=0 , wsz=min;
        for(auto v: adj[u]) if(v!=p[u]){
            if(tsz[v]>wsz) {w=v; wsz=tsz[v];}
        }
        if(w) dfs(w,root);
        for(auto v:adj[u]) if(v!=p[u]) if(v!=w) dfs(v,v);
    }
    inline void upd(ll u, ll val){
        ll a=id[u];
        st.modify(a,val);
    }
    ll que(ll u, ll v){
        ll ans=0;// neutro?
        while(u!=-1){
            if(rt[u]==rt[v]){
                ll a=id[u], b=id[v];
                if(a>b) swap(a,b);
                ans=Op(ans,st.que(a,b+1));
                u=-1;
            }
            else{
                if(d[rt[u]]>d[rt[v]]) swap(u,v);
                ans=Op(ans,st.que(id[rt[v]],id[v]+1));
                v=p[rt[v]];
            }
        }
        return ans;
    }
    inline void build(){
        gid=0; st.n=n;
        make(); dfs(0,0);
        REP(i,0,n) st.t[i+n]=0;//val de cada t[i]
        st.build();
    }
};
