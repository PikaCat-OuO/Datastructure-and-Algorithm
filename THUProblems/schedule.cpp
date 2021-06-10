#include <iostream>
#include <cmath>
using namespace std;
struct Task{
    size_t priotity;
    string name;
    bool operator>(const Task& rhs){
        if(this->priotity<rhs.priotity) return true;
        else if(this->priotity==rhs.priotity&&this->name<rhs.name) return true;
        return false;
    }
};
Task* tasks;
int totalTask;
//下滤
void siftDown(int index){
    int lchild=index*2+1;
    int rchild=index*2+2;
    int max=index;
    if(lchild<totalTask && tasks[lchild]>tasks[index]){
        max=lchild;
    }
    if(rchild<totalTask && tasks[rchild]>tasks[max]){
        max=rchild;
    }
    if(max != index){
        swap(tasks[max],tasks[index]);
        siftDown(max);
    }
}
//堆化
void heapify(){
    for(int i=totalTask/2-1;i>=0;i--){
        siftDown(i);
    }
}
int main(){
    int estimatedNum;
    scanf("%d %d",&totalTask,&estimatedNum);
    if(totalTask==0||estimatedNum==0) return 0;
    tasks=new Task[totalTask];
    char arr[9];
    for(int i=0;i<totalTask;++i){
        scanf("%llu %s",&tasks[i].priotity,arr);
        tasks[i].name=arr;
    }
    //首先堆化
    heapify();
    for(int i=0;i<estimatedNum;++i){
        if(tasks[0].priotity>=pow(2,32)) return 0;
        printf("%s\n",tasks[0].name.c_str());
        tasks[0].priotity*=2;
        siftDown(0);
    }
    return 0;
}
