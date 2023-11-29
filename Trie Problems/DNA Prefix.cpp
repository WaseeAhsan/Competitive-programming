#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int count;
    Node* next[4]; // A, C, G, T
    Node() {
        count = 0;
        for (int i = 0; i < 4; ++i)
            next[i] = nullptr;
    }
};

Node* root;

void insert(const string& str) {
    Node* curr = root;
    for (char ch : str) {
        int idx = (ch == 'A') ? 0 : (ch == 'C') ? 1 : (ch == 'G') ? 2 : 3;
        if (curr->next[idx] == nullptr)
            curr->next[idx] = new Node();
        curr = curr->next[idx];
        curr->count++;
    }
}

int getMaxProduct(Node* curr, int level) {
    int maxProduct = level * curr->count;
    for (int i = 0; i < 4; ++i) {
        if (curr->next[i] != nullptr) {
            int product = getMaxProduct(curr->next[i], level + 1);
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        root = new Node();

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string sample;
            cin >> sample;
            insert(sample);
        }

        vector<string> sc = { "A", "AC", "ACG", "ACGT", "C", "CG", "CGT", "G", "GT" };
        int maxResult = 0;
        for (const string& str : sc) {
            maxResult = max(maxResult, getMaxProduct(root, 0));
        }

        cout << "Case " << t << ": " << maxResult << "\n";

        delete root;
    }

    return 0;
}
