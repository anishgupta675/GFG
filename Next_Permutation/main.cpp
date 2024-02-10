#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    while(n) {
        a.push_back(n % 10);
        n/= 10;
    }
    next_permutation(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) n = (10 * n) + a[i];
    cout << n << endl;
}