#include <bits/stdc++.h>
#define ll long long 
#define vi vector
using namespace std; 

int valid( ll mid , vector<ll> &v , ll k )
{
    int blocks = 1 ; 
    ll sum = 0 ; 

    for(int i  = 0 ; i < v.size() ;i++)
    {
        if( sum + v[i] > mid)
        {
            sum  = 0 ; 
            blocks++ ;
        }
        sum  += v[i] ; 
    }

    if(blocks > k )
    {
        return true ; 
    }
    else

    return false ; 

}


int main() {
    int t = 1 ;
   // cin >> t;

    while (t--) {
        long long n , k ;
        cin >> n >> k ;
vi<ll>v(n) ; 
ll maxValue  = 0 ; 
        for(int i = 0 ; i < n ;i++)
        {
            cin >> v[i]; 
            maxValue = max( v[i] , maxValue )  ;
        }


        ll lo = maxValue  , hi = 1e18 ; 
        ll maxiSum = 1e18 ;
        while ( lo <= hi)
        {
              ll  mid = (hi + lo) / 2 ; 
              

             if( valid(mid , v , k ) )
             {
                lo = mid + 1 ; 
             }
             else
             {
                if( mid < maxiSum)
                {
                    maxiSum  = mid  ;
                }
                hi = mid - 1 ; 
             }
        }
        

        cout << maxiSum << endl; 
       
    }

    return 0;
}
