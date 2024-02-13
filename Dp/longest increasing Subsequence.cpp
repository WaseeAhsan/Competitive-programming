#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e5 + 10 ; 


int dp[N] ; 
vector<int>a(N) ; 

int func(int i )
{
    if(dp[i] != -1 ) return dp[i] ; 

    int ans = 1 ; 

    for(int j = 0 ; j <  i ;j++)
    {
        if(a[i] > a[j])
        {
            ans = max(ans , func(j) + 1 ) ; 
        }
    }

    return dp[i] = ans ; 
}


int main(){

    int n ; cin >> n ; 
    
    memset(dp , -1 , sizeof(dp)) ; 

    for(int i = 0 ; i < n ;i++) cin >> a[i] ; 

int ans = 0 ; 
    for(int i = 0 ; i < n ;i++)
    {
        ans = max(ans , func(i)) ; 
    }


cout << ans << endl ; 


}