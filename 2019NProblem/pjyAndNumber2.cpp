#include <iostream>
#include <vector>
using namespace std;
int main() {
    int totalNum;
    scanf("%d", &totalNum);
    vector<int> seq(totalNum);
    for(auto& num : seq) scanf("%d", &num);
    int count1 = 1, count2 = 1, count3 = 1;
    for(const auto& num : seq){
        if(num == count1){
            printf("%d", 2);
            ++count1;
            continue;
        }
        if(num == count2){
            printf("%d", 3);
            ++count2;
            continue;
        }
        if(num == count3){
            printf("%d", 5);
            ++count3;
            continue;
        }
    }
    return 0;
}
