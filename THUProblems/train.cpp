#include <iostream>
#include <string>
using namespace std;
int train(){
    int totalTrain,maxCapacity,index=-1,inTrain=0;
    string procedure;
    scanf("%d %d",&totalTrain,&maxCapacity);
    if(maxCapacity==0){printf("No");return 0;}
    //�г��������к���תվ
    int outTrain[totalTrain],station[maxCapacity];
    for(int i=0;i<totalTrain;++i){
        scanf("%d",&outTrain[i]);
    }
    for(int i=0;i<totalTrain;++i){
        //push����
        while(index<0||station[index]!=outTrain[i]){
            //���ջ���˻����г��������п��ˣ������No
            if(index+1==maxCapacity||inTrain==totalTrain){
                printf("No");
                return 0;
            }
            procedure+="push\n";
            station[++index]=++inTrain;
        }
        //����ջ���Ѿ�������Ҫ��Ԫ���ˣ����Խ�����һ��ѭ��
        procedure+="pop\n";
        --index;
    }
    procedure[procedure.length()-1]='\0';
    printf("%s",procedure.c_str());
    return 0;
}
