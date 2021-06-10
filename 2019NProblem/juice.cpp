#include <iostream>
using namespace std;
int main(){
    int totalNum;
    scanf("%d", &totalNum);
    for (int i = 0; i < totalNum; ++i) {
        int price, money, amount;
        scanf("%d %d %d", &price, &money, &amount);
        int buyForce = money / price;
        printf("%d\n", buyForce > amount ? amount : buyForce);
    }
    return 0;
}
