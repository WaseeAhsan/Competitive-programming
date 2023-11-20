#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long

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
                        vector<ll>v(n) ; 

                        for(ll i = 0 ; i < n ;i++)
                        {
                                cin >> v[i] ; 
                        }

                        ll sum =  0 ; 
                        ll maxi = INT_MIN ; 
                        for(ll i = 0 ;i < n ;i++)
                        {       
                                sum = sum + v[i] ; 
                                maxi = max(maxi,sum) ; 

                                if(sum < 0)
                                {
                                        sum = 0 ; 
                                }


                        }

                        cout << maxi << endl ; 
              }
                
              

 return 0;
}