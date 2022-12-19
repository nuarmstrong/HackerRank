#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q; cin >> n >> q;
    
    vector< vector< int > > root;
    
    for (int i = 0; i < n; i++) {
        vector< int > v;
        int k; cin >> k;
        
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        root.push_back(v);
    }
    
    for (int i = 0; i < q; i++) {
        int j, k; cin >> j >> k;
        cout << root[j][k] << endl;
    }
     
    return 0;
}