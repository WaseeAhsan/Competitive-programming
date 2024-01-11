#include<bits/stdc++.h>

using namespace std ;

#define N 20
#define MAX (1 + (1 << 6) )
#define inf 0x7fffffff

int arr[N] ; 
int tree[MAX] ; 
int lazy[MAX] ; 

void build_tree( int node , int b , int e)
{
    if(b > e ) return ; // বাইরে চলে গিয়েছে 

    if(b == e) 
    {  // লিফ নোড 
        tree[node]  = arr[b]  ; 
        return ; 
    }
    int left  = 2 * node ; 
    int right = left + 1 ; 
    int mid = (b + e ) /2 ; 

    build_tree( left , b , mid ) ; 
    build_tree( right , mid + 1 , e  ) ; 

    tree[node] = max( tree[left] , tree[right] ) ; 
}

void update_tree( int node , int b , int e , int i , int j , int value )
{   
     int left = node * 2 ; 
       int right = left + 1 ;
       int mid = (b + e ) / 2 ; 
    if( lazy[node] != 0  )
    {
        tree[node] += lazy[node] ; 
      
       
        if( b !=   e )
        {
            lazy[left ] += lazy[node] ; 
            lazy[right] += lazy[node] ;  
        }
        lazy[node] = 0 ; 
    }

    if( b > e || b > j || e < i)
    return ; //  বাইরে চলে গিয়েছে 
    
    if( b >= i and e <= j )
    {
        // রেঞ্জের ভিতরেই আছে 

        tree[node] += value ; 

        if( b != e)
        {
            // লিফ নোড না 
            lazy[left] += value ; 
            lazy[right] += value ; 
        }
        return ; 
    }

    update_tree( left , b, mid , i , j , value ) ; 
    update_tree(right , mid + 1 , e ,  i , j , value) ; 

    tree[node] = max( tree[left] ,  tree[right] ) ; 

}

int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}



int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	build_tree(1, 0, N-1);

	memset(lazy, 0, sizeof lazy);

	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}

