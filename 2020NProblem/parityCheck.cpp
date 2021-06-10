#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    int sum = 0;
    string s;
    getline(cin, s);
    for(const auto& i : s){
        bitset<8> bits = i;
        sum += bits.count();
        sum %= 2;
    }
    printf("%d", sum);
    return 0;
}
