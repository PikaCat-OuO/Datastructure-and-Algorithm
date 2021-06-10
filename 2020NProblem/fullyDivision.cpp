#include <iostream>
#include <cmath>
using namespace std;
int main() {
    while (true) {
        int num;
        bool flag = false;
        scanf("%d", &num);
        if (num == 1 or num == 2){
            printf("YES\n");
            continue;
        }
        if (num == 0) break;
        for (int i = 2; i <= int(sqrt(num)); ++i) {
            for (int j = 0; j <= 100; ++j) {
                if (int(pow(i, j)) == num) {
                    printf("YES\n");
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if (flag) continue;
        printf("NO\n");
    }
    return 0;
}
