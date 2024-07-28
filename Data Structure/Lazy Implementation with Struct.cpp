#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int a[N];
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1 ) + 1)
    int t[4 * N] , lazy[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
        memset( lazy , 0 , sizeof lazy ) ; 
    }
    
    inline void push(int n , int b , int e)
    {
        if(lazy[n] == 0 ) return ; 
        
        t[n] = t[n] + lazy[n] * ( e - b + 1 ) ; 

        if(b != e)
        {
            lazy[lc] = lazy[lc] + lazy[n] ; 
            lazy[rc] = lazy[rc] + lazy[n] ; 
        }
        lazy[n] = 0 ; 

    }

    inline void pull(int n )
    {
        t[n] = t[lc] + t[rc] ; 
    }

    void build(int n, int b, int e) {
        lazy[n] = 0 ; 
        if (b == e) {
            t[n] = a[b];
            return;
        }

        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = t[l] + t[r];
    }

    void upd(int n, int b , int e, int i, int x , int v) {
        push(n , b , e) ; 
        if (i < b || i > e) {
            return;
        }

        if (b == e) {
            lazy[n] = v ; 
            t[n] = x;
            return;
        }

        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x , v );
        upd(r, mid + 1, e, i, x , v );
        t[n] = t[l] + t[r];
    }

    int query(int n, int b, int e, int i, int j) {
        push( n , b , e  ) ;
        if (i > e || j < b) return 0;

        if (b >= i && e <= j) {
            return t[n];
        }

        int mid = (b + e) >> 1, l = n << 1, r = l | 1;

        int p1 = query(lc, b, mid, i, j);
        int p2 = query(rc, mid + 1, e, i, j);
        return p1 + p2;
    }
} t;

int main() {
    int ts = 1;  // cin >> t;

    while (ts--) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }

        t.build(1, 1, n);
        t.upd(1, 1, n, 2, 3, 10 )  ;
        cout << t.query(1, 1, n, 2, 4) << endl;
        cout << t.query(1, 1, n, 2, 3) << endl;
    }
    return 0;
}
