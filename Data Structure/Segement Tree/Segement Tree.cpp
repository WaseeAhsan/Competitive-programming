#include<bits/stdc++.h>
#define mx 100001
using namespace std ; 

int arr[mx] ; 

int tree[mx * 3 ] ; 


void init(int node, int b, int e) {
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    int left = node * 2; 
    int right = node * 2 + 1; 
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) {
    if (i > e || j < b) {
        return 0;// যেই রেঞ্জ চাইসে , সেটা প্রদত্ত আই থেকে যে এর রেঞ্জের বাইরে 
    }

    if (b >= i && e <= j)
        return tree[node];// রিলেভেন্ট সেগমেন্ট 
     // আরো ভাঙতে হবে 
    int left = node * 2; 
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);

    return p1 + p2;
}


void update( int node , int b , int e ,  int i , int newvalue )
{

    if( i > e || i< b  )
    {
        return ;  
    }

    if( b >= i and e  <= i )
    {
            // রিলেভেন্ট সেগমেন্ট 

            tree[node] =  newvalue ; 
            return ; 
    }

    int left = 2 * node ;
    int right = 2 * node + 1  ; 
    int mid = (b + e) / 2 ; 
    update( left , b , mid , i , newvalue) ; 
    update( right, mid + 1 , e , i , newvalue   ) ; 

    tree[node] = tree[left] + tree[right]  ;
}



int main()
{
    int n ; cin >> n  ;  

    for(int i  = 0 ; i <n ;i++)
    {
        cin >> arr[i] ; 
    }


    init( 1 , 0  , n  - 1 ) ; 

    cout << query(  1 , 0 , n -1 , 0 , 2 ) << endl ; 
    update( 1 , 0 ,  n -1 , 2 , 4 )  ;
    cout << query(  1 , 0 , n -1 , 0 , 2 ) << endl ; 




}