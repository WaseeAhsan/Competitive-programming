
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k; 
        cin >> k >> n; 
        vector<ll> ar(n + 1, 0); 

        for (int i = 1; i <= n; i++)
            cin >> ar[i]; 

        ll ans = 0;
        map<int, int> mp;
        mp[0] = 1;

        for (int i = 1; i <= n; i++) {
            ar[i] = (ar[i] + ar[i - 1]) % k;
            ans += mp[ar[i]];
            mp[ar[i]]++;
        }

        cout << ans << endl;
    }
    return 0;
}