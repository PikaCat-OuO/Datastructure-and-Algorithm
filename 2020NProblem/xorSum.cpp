#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> n1(n), n2(m);
    for(auto& num : n1){
        scanf("%d", &num);
    }
    for(auto& num : n2){
        scanf("%d", &num);
    }
    size_t sum = 0;
    for(const auto& num1 : n1){
        for(const auto& num2 : n2){
            sum += num1 ^ num2;
            sum %= int(1e9 + 7);
        }
    }
    printf("%lld", sum);
    return 0;
}
