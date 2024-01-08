#include<bits/stdc++.h>
using namespace std ; 


int lower_bound(vector<int> &v ,  int element  )
{

        int lo = 0  , hi = v.size() - 1 ; 
        int mid  ; 

            while (hi - lo > 1)
            {
                int mid = (hi + lo) /2  ; 
                 if(v[mid] < element  )
                 {
                    lo = mid + 1 ; 
                 }
                 else{
                    hi = mid  ;
                 }
            }

            if(v[lo] >= element  )
            {
                //cout << lo << endl ;
                return lo ;  
            }
            else if(v[hi] >= element  )
            {
                // cout << hi << endl  ;
                return hi ;  
            }
            else 
            {
                //cout << "NOT FOUND" << endl; 
                return -1; 
            }
            


}


int uper_bound( vector<int> &v , int element )
{
      int lo = 0  , hi = v.size() - 1 ; 
        int mid  ; 

            while (hi - lo > 1)
            {
                int mid = (hi + lo) /2  ; 
                 if(v[mid] <= element  )
                 {
                    lo = mid + 1 ; 
                 }
                 else{
                    hi = mid  ;
                 }
            }

            if(v[lo] > element  )
            {
                //cout << lo << endl ;
                return lo ;  
            }
            else if(v[hi] > element  )
            {
                // cout << hi << endl  ;
                return hi ;  
            }
            else 
            {
                //cout << "NOT FOUND" << endl; 
                return -1; 
            }
}



int main(){

    int n ; cin >> n  ;
    vector<int>v(n) ; 

    for(int i = 0 ; i < n ;i++)
    {
        cin >> v[i] ; 
    }

    //Your  Input must be Sorted , or you need to sort the vector if it is unsorted 

            int element ; cin >> element  ;

            int lb  = lower_bound(v,element) ;

            //cout << lb << " " << v[lb] << endl ;
         cout << lb << " " << ( (lb != -1) ? v[lb] : -1 ) << endl ;  
 


            int up = uper_bound(v,element) ; 
          //  cout << up << " " << v[up] << endl ;
            cout << lb << " " << ( (up != -1) ? v[up] : -1 ) << endl ;  



}
