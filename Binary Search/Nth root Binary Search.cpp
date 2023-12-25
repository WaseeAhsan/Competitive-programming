#include<bits/stdc++.h>
using namespace std; 

double eps = 1e-6  ; 

// square root 
/*
int main()
{                     double x;
    cin >> x;

    if (x <= 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    double lo = 1, hi = x;
    double mid;

    while (hi - lo > eps) {
        mid = lo + (hi - lo) / 2;

        if (mid * mid < x) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << setprecision(10) << lo << endl << hi << endl;
    cout << pow( x , 1.0/ 2 ) << endl ; 

    return 0;



}

*/

//nth root 



double multiply(double mid , int  n){

    double ans = 1 ; 

    for(int i =  0 ; i< n ;i++)
    {
        ans *=mid ; 
    }
        return ans  ;
}



int main()
{   double x ,  n ;
    cin >> x >> n ;

    if (x <= 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    double lo = 1, hi = x;
    double mid;

    while (hi - lo > eps) {
        mid = lo + (hi - lo) / 2;

        if (multiply(mid,n) < x) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << setprecision(10) << lo << endl << hi << endl;
    cout << pow( x , 1.0/ 2 ) << endl ; 

    return 0;



}


