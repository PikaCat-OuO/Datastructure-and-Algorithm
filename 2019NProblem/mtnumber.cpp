#include <iostream>
using namespace std;
int main(){
    int mtNum[7] = {3, 7, 127, 8191, 131071, 524287, 2147483647};
    int totalNum;
    scanf("%d", &totalNum);
    for (int i = 0; i < totalNum; ++i) {
        int nowNum;
        scanf("%d", &nowNum);
        for(const auto& num : mtNum){
            if(num >= nowNum){
                printf("%d\n", num);
                break;
            }
        }
    }
    return 0;
}
