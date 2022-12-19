#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a, b; cin >> a >> b;
    string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (a; a <= b; a++) {
        if (a > 9) {
            if (a % 2 == 0) cout << "even" << endl;
            else cout << "odd" << endl;
        }
        else {
            cout << arr[a-1] << endl;
        }
    }
    
    return 0;
}