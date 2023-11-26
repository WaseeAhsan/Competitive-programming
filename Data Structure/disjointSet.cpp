#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// initial value should be -1
int p[30002];

int findPar(int u)
{
    if(p[u] == -1) return p[u] = u;
    if(u == p[u]) return u;
    return p[u] = findPar(p[u]);
}

void unionSet(int u, int v)
{
    int pu = findPar(u);
    int pv = findPar(v);
    p[pv] = pu;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    int n, m, i, k, u, v, pu, cnt;
    
    memset(p,-1,sizeof(p));

    return 0;
}
