#include <iostream>
#include <cmath>
using namespace std;
auto happy = new int[1000000][3];
auto dp = new int[1000000][3];
int doDP(int totalDay) {
    dp[0][0] = happy[0][0];
    dp[0][1] = happy[0][1];
    dp[0][2] = happy[0][2];
    for(int i = 1; i < totalDay; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + happy[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + happy[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + happy[i][2];
    }
    return max(dp[totalDay - 1][0], max(dp[totalDay - 1][1], dp[totalDay - 1][2]));
}
int main(){
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; ++i) {
        int totalDay;
        scanf("%d", &totalDay);
        for(int j = 0; j < totalDay; ++j) scanf("%d %d %d", &happy[j][0], &happy[j][1], &happy[j][2]);
        printf("%d\n",doDP(totalDay));
    }
    return 0;
}
