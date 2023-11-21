#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define sort0(v) sort(all(v))

#define N 1000007
using namespace std;

vector<int> generate(const vector<int>& arr, int win_sz, int rettyp = 1) {
    deque<pair<int, int>> dq;
    int sz = arr.size();
    vector<int> val, ind;

    if (sz <= win_sz || sz < 2) {
        if (rettyp == 1) {
            return arr;
        } else {
            for (int i = 0; i < sz; ++i) {
                ind.push_back(i);
            }
            return ind;
        }
    }

    for (int i = 0; i < sz; ++i) {
        while (!dq.empty() && dq.front().first >= arr[i]) {
            dq.pop_front();
        }

        dq.push_front({arr[i], i});

        while (!dq.empty() && dq.back().second <= i - win_sz) {
            dq.pop_back();
        }

        if (i >= win_sz - 1) {
            val.push_back(dq.back().first);
            ind.push_back(dq.back().second);
        }
    }

    if (rettyp == 1) {
        return val;
    } else {
        return ind;
    }
}

vector<int> getValue(const vector<int>& arr, int win_sz) {
    return generate(arr, win_sz);
}

vector<int> getIndex(const vector<int>& arr, int win_sz) {
    return generate(arr, win_sz, 0);
}

int main() {
    vector<int> arr = {10, 2, 3, 7, 34, 9, 6, 11, 4, 5, 18, 44, 36, 32, 21};
    vector<int> ans = getValue(arr, 4);
    
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}