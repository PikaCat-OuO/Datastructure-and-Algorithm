#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int totalNum, length{0};
    scanf("%d", &totalNum);
    int x1, x2, y1, y2;
    scanf("%d %d", &x2, &y2);
    for (int i = 1; i < totalNum; ++i) {
        x1 = x2;
        y1 = y2;
        scanf("%d %d", &x2, &y2);
        length += max(abs(x2 - x1), abs(y2 - y1));
    }
    printf("%d", length);
    return 0;
}
