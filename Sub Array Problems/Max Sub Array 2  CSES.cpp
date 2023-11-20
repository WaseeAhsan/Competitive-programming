#include <bits/stdc++.h>
#define ll long long

using namespace std;
// solve using prefix sum 

int main()
{
        int n,  x ; cin>> n >> x ; 
        vector<ll>valu(n) ; 

        for(int i = 0 ; i < n ;i++)
        {
            cin >> valu[i] ;
        }

        ll sum = 0 ; 

        map<ll,int>seen ; 
        seen[0] = 1  ; 
        ll cnt = 0 ; 
        for(int i = 0 ;i < n ;i++ )
        {
            sum += valu[i] ;
            cnt += seen[sum - x] ; 
          //  cout<<sum <<" " <<seen[sum - x] << endl ; 
            seen[sum]++; 

        }

        cout << cnt << endl ; 


}