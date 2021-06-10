#include <iostream>
#include <cstring>
using namespace std;
char bubbles[20001];
int sizeOfBubbles;
void insert(int pos,char bubble){
    //�ƶ�
    for(int i=sizeOfBubbles;i>pos;--i){
        bubbles[i]=bubbles[i-1];
    }
    //����
    bubbles[pos]=bubble;
    ++sizeOfBubbles;
    bubbles[sizeOfBubbles]='\0';
}
int removeDup(){
    //ɾ���ظ�Ԫ�أ��������һ��ɾ����λ��
    int index=sizeOfBubbles;
    for(int i=0;i<sizeOfBubbles-2;++i){
        //�ҵ����һ����
        int j=i+1;
        for(;bubbles[j]==bubbles[i];++j);
        //������ɾ��������¼��һ��ɾ����λ��
        if(j-i>2){
            if(index>i) index=i;
            for(int k=i;k<j;++k) bubbles[k]=' ';
            //i����ƶ�����һ��λ��
            i+=j-i-1;
        }
    }
    return index;
}
//�������ʾ�ƶ����
bool shiftElement(int index){
    //���ɾ���˾��ƶ�Ԫ��
    if(index==sizeOfBubbles) return true;
    for(int i=index+3;i<sizeOfBubbles;++i){
        if(bubbles[i]!=' '){
            bubbles[index++]=bubbles[i];
        }
    }
    bubbles[index]='\0';
    sizeOfBubbles=index;
    return false;
}
void process(){
    while(!shiftElement(removeDup()));
    if(sizeOfBubbles==0){
        bubbles[0]='-';
        bubbles[1]='\0';
    }
}
int zuma(){
    cin.getline(bubbles,20001);
    sizeOfBubbles=strlen(bubbles);
    process();
    int totalAction;scanf("%d",&totalAction);
    for(int i=0;i<totalAction;++i){
        int pos;char bubble;scanf("%d %c",&pos,&bubble);
        insert(pos,bubble);
        process();
        printf("%s\n",bubbles);
    }
    return 0;
}
