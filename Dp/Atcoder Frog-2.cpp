#include<bits/stdc++.h>
#define ll long long
using namespace std;

const long long N = 1e5 + 10;

int k ; 
int  h[N] ; 
int dp[N] ; 
    int func(int i )
    {

        if(i == 0 ) return 0 ; 

        if(dp[i] != -1 ) return dp[i] ; 


        int cost = INT_MAX ; 


        for(int j = 1 ; j <= k ; j++)
        {
            if(i - j >= 0 )
            cost = min(cost , func(i-j) + abs(h[i] - h[i - j] )) ;  

        }
        

        return dp[i] = cost  ;
    }


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    int t = 1;
   // cin >> t;

    while (t--)
    {

        memset(dp, -1 , sizeof(dp)) ; 

        int n ; cin >> n >> k   ; 

        for(int i = 0 ; i < n ; i++)
        {
            cin >> h[i] ; 
        }

        cout << func(n-1) << endl ; 
        
    }
    return 0;
}
