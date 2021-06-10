#include <iostream>
#include <string>
using namespace std;
int train(){
    int totalTrain,maxCapacity,index=-1,inTrain=0;
    string procedure;
    scanf("%d %d",&totalTrain,&maxCapacity);
    if(maxCapacity==0){printf("No");return 0;}
    //列车出列序列和中转站
    int outTrain[totalTrain],station[maxCapacity];
    for(int i=0;i<totalTrain;++i){
        scanf("%d",&outTrain[i]);
    }
    for(int i=0;i<totalTrain;++i){
        //push到有
        while(index<0||station[index]!=outTrain[i]){
            //如果栈满了或者列车入列序列空了，则输出No
            if(index+1==maxCapacity||inTrain==totalTrain){
                printf("No");
                return 0;
            }
            procedure+="push\n";
            station[++index]=++inTrain;
        }
        //现在栈顶已经是所需要的元素了，可以进行下一轮循环
        procedure+="pop\n";
        --index;
    }
    procedure[procedure.length()-1]='\0';
    printf("%s",procedure.c_str());
    return 0;
}
