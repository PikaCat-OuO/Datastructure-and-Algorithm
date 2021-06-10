#include <iostream>
#include <vector>
using namespace std;

bool flag = false;
int nowIndex, target, nowNum[101];
vector<int> validNums;

bool fullyDivide() {
    int res = 0;
    for (int i = nowIndex; i >= 0; --i) {
        res = (res * 10 + nowNum[i]) % target;
    }
    return !res;
}

bool dfs(int depth){
    //首先检查能否被整除
    if (depth < 0) return fullyDivide();
    //将这个位置上面的数字逐个尝试
    for (const auto& i : validNums) {
        if(i == 0 and depth == nowIndex) continue;
        nowNum[depth] = i;
        if (dfs(depth - 1)) return true;
    }
    return false;
}

int main() {
    int totalNum;
    scanf("%d", &totalNum);
    for (int i = 0; i < totalNum; ++i) {
        //有效数字归零
        validNums.clear();
        string numbers;
        numbers.resize(10);
        scanf("%s %d", &numbers[0], &target);
        //分离可以使用的数字
        for (int j = 0; j < 10; ++j) {
            if(numbers[j] == '1') validNums.emplace_back(j);
        }
        //开始暴力搜索，从最低位到最高位
        for (flag = false, nowIndex = 0; nowIndex < 100; ++nowIndex) {
            if (dfs(nowIndex)) {
                //搜索成功，输出
                for (int k = nowIndex; k >= 0; --k) {
                    printf("%d", nowNum[k]);
                }
                printf("\n");
                flag = true;
                break;
            }
        }
        //数组归零
        for (auto& num : nowNum) num = 0;
        if (flag) continue;
        //所有的可能都遍历完了,还有一种情况没有检查
        if (numbers[0] != '1' or numbers[1] != '1'){
            printf("-1\n");
            continue;
        }
        nowNum[100] = 1;
        if(fullyDivide()){
            printf("1");
            for(int i = 0; i < 100; ++i) printf("0");;
            printf("\n");
            continue;
        }
        nowNum[100] = 0;
        printf("-1\n");
    }
    return 0;
}
