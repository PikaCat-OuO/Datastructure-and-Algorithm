#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (auto& c : s) {
        c = islower(c) ? toupper(c) : tolower(c);
    }
    cout << s;
    return 0;
}
