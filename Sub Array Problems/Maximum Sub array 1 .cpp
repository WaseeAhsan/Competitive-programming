#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define sort0(v) sort(all(v))

#define N 1000007
using namespace std;
int main()
{
                faster;
                
              int t = 1 ; //cin >> t ; 
              while (t--)
              {
                        ll n ; cin >> n  ; 
                        ll k ; cin >> k ; 
                        vector<ll>v(n) ; 

                        for(ll i = 0 ; i < n ;i++)
                        {
                                cin >> v[i] ; 
                        }

                        ll sum =   0 ; ll count = 0 ; 
                        ll maxi = INT_MIN ; 
                        //ll left = 0 , right = 1 ;
                        // for(ll i = 0 ;i < n ;i++)

                               // sum = sum + v[right] ;

    int l = 0, r = 0;


                      while (r < n) {
        sum += v[r];

        while (sum > k && l <= r) {
            sum -= v[l];
            l++;
        }

        if (sum == k) {
            count++;
        }

        r++;
    }

                        cout << count << endl ; 
              }
                
              

 return 0;
}