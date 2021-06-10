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
    //���ȼ���ܷ�����
    if (depth < 0) return fullyDivide();
    //�����λ������������������
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
        //��Ч���ֹ���
        validNums.clear();
        string numbers;
        numbers.resize(10);
        scanf("%s %d", &numbers[0], &target);
        //�������ʹ�õ�����
        for (int j = 0; j < 10; ++j) {
            if(numbers[j] == '1') validNums.emplace_back(j);
        }
        //��ʼ���������������λ�����λ
        for (flag = false, nowIndex = 0; nowIndex < 100; ++nowIndex) {
            if (dfs(nowIndex)) {
                //�����ɹ������
                for (int k = nowIndex; k >= 0; --k) {
                    printf("%d", nowNum[k]);
                }
                printf("\n");
                flag = true;
                break;
            }
        }
        //�������
        for (auto& num : nowNum) num = 0;
        if (flag) continue;
        //���еĿ��ܶ���������,����һ�����û�м��
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
