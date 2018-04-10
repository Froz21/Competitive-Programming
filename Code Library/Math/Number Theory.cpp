// Encuentra el menor positivo de la forma ax+ b , my+ n 
// ( x,y enteros no necesariamente postivos)
// Si son positivos, hallar los coeficientes y sumar lo 
// que falta para que de positivo

// d: mcd(a,b)  ( d > 0 )
// x,y enteros tales que a*x + b*y = d
// las demas soluciones son ( x + (b/d)t , y - (a/d)t )
void gcdextend(ll a, ll b, ll &x, ll &y, ll &d){
    if( b == 0){
       if(a>0) x = 1, y = 0 , d = a ;
       else x = -1 , y = 0 , d = -a ;
       return ;
    }
    gcdextend(b,a%b,x,y,d) ;
    ll x1 = y , y1 = x - (a/b)*y ;
    x = x1 , y = y1 ;
}


// menor positivo que es u modulo modPos
inline ll ADDTOPOSITIVE(ll u, ll modPOS){
    if(modPOS < 0) modPOS = -modPOS ;
    if(u >= 0) return u%modPOS;
    u = -u ;
    if(u%modPOS == 0) return 0;
    return modPOS*((u/modPOS)+1) - u ;
}

// Encuentra el menor positivo que es
// de la forma ax + b , my + n
// los demas son de la forma ans + ((a/d)*m)*t
// retorna -1 si no hay solucion ( mcd(a,m) no divide a n - b )
inline ll FINDmenorLCS(ll a,ll b,ll m,ll n){
     //Cuidado con el caso a = 0 , m = 0 , 
	   //porque es solo verificar b = n

     a = abs(a) ; m = abs(m) ;
     if( a == 0 ) {
        swap(a,m);
        swap(b,n) ;
     }
     if( m == 0 ){
        if( (n-b) % a == 0) return n ;
        else return -1 ;
     }
     ll x , y , d ;
     gcdextend(a,m,x,y,d) ;
     if((n-b)%d != 0) return -1 ;
     ll temp = a*x*((n-b)/d) + b ;
     temp = ADDTOPOSITIVE(temp,a*(m/d)) ;
     return temp ;
}

//Finds partition of n (number of ways to obtain n as a sum of positive numbers)

int partition(int n) {
  int[] dp = new int[n + 1];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1, r = 1; i - (3 * j * j - j) / 2 >= 0; j++, r *= -1) {
      dp[i] += dp[i - (3 * j * j - j) / 2] * r;
      if (i - (3 * j * j + j) / 2 >= 0) {
        dp[i] += dp[i - (3 * j * j + j) / 2] * r;
      }
    }
  }
  return dp[n];
}


