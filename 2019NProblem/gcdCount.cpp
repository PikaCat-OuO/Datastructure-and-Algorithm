#include <iostream>
#include <cmath>
using namespace std;
int gcd(int num1, int num2){
    return num2 ? gcd(num2, num1 % num2) : num1;
}
int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        int count = 0;
        int gcdNum = gcd(num1, num2);
        //开始计数
        for (int j = 1; j <= sqrt(gcdNum); ++j) {
            count += 2 * !(gcdNum % j);
        }
        if (int(sqrt(gcdNum)) * int(sqrt(gcdNum)) == gcdNum) count -= 1;
        printf("%d\n", count);
    }
    return 0;
}
