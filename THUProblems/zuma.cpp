#include <iostream>
#include <cstring>
using namespace std;
char bubbles[20001];
int sizeOfBubbles;
void insert(int pos,char bubble){
    //移动
    for(int i=sizeOfBubbles;i>pos;--i){
        bubbles[i]=bubbles[i-1];
    }
    //插入
    bubbles[pos]=bubble;
    ++sizeOfBubbles;
    bubbles[sizeOfBubbles]='\0';
}
int removeDup(){
    //删除重复元素，并保存第一次删除的位置
    int index=sizeOfBubbles;
    for(int i=0;i<sizeOfBubbles-2;++i){
        //找到多个一样的
        int j=i+1;
        for(;bubbles[j]==bubbles[i];++j);
        //如有则删除，并记录第一次删除的位置
        if(j-i>2){
            if(index>i) index=i;
            for(int k=i;k<j;++k) bubbles[k]=' ';
            //i向后移动到下一个位置
            i+=j-i-1;
        }
    }
    return index;
}
//返回真表示移动完成
bool shiftElement(int index){
    //如果删除了就移动元素
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
