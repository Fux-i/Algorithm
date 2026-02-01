#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] > s[r]) {
            cout << "left" << endl;
            return 0;
        }
        if (s[l] < s[r]) {
            cout << "right" << endl;
            return 0;
        }
        ++l;--r;
    }
    cout << "equal" << endl;
}
