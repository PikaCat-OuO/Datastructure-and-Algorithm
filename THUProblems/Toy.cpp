#include <iostream>
#include <cstring>
using namespace std;
int hashTable[40320];
int toy[8]={1,2,3,4,8,7,6,5};
int fac[8]={1,1,2,6,24,120,720,5040};
int toyHash(int* toy){
    int hash=0;
    for(int i=0;i<8;++i){
        //找比它小的数的个数
        int count=0;
        for(int j=i+1;j<8;++j){
            if(toy[j]<toy[i]) ++count;
        }
        hash+=count*fac[7-i];
    }
    return hash;
}
//第一种方式
void updown(int* toy){
    swap(toy[0],toy[4]);
    swap(toy[1],toy[5]);
    swap(toy[2],toy[6]);
    swap(toy[3],toy[7]);
}
//第二种方式
void shiftRight(int* toy){
    swap(toy[2],toy[3]);
    swap(toy[6],toy[7]);
    swap(toy[1],toy[2]);
    swap(toy[5],toy[6]);
    swap(toy[0],toy[1]);
    swap(toy[4],toy[5]);
}
void shiftLeft(int* toy){
    swap(toy[0],toy[1]);
    swap(toy[4],toy[5]);
    swap(toy[1],toy[2]);
    swap(toy[5],toy[6]);
    swap(toy[2],toy[3]);
    swap(toy[6],toy[7]);
}
//第三种方式
void center(int* toy){
    swap(toy[1],toy[2]);
    swap(toy[1],toy[5]);
    swap(toy[5],toy[6]);
}
void unCenter(int* toy){
    swap(toy[5],toy[6]);
    swap(toy[1],toy[5]);
    swap(toy[1],toy[2]);
}
struct Node{
    int arr[8];
    Node* next=nullptr;
    Node(Node* node):next(node){}
    Node(int* toy,Node* node):next(node){
        for(int i=0;i<8;++i){
            arr[i]=toy[i];
        }
    }
};
Node* head1=new Node(toy,nullptr);
Node* head2=nullptr;
//广度优先搜索
void bfs(){
    int length=0;
    while(head1){
        while(head1){
            int& value=hashTable[toyHash(head1->arr)];
            if(value==-1){
                value=length;
                updown(head1->arr);
                //头插法
                head2=new Node(head1->arr,head2);
                updown(head1->arr);
                shiftLeft(head1->arr);
                //头插法
                head2=new Node(head1->arr,head2);
                shiftRight(head1->arr);
                unCenter(head1->arr);
                //头插法
                head2=new Node(head1->arr,head2);
                center(head1->arr);
            }
            Node* p=head1;
            head1=head1->next;
            delete p;
        }
        //head1遍历完，指针互换
        ++length;
        head1=head2;
        head2=nullptr;
    }
}
int Toy(){
    //首先打表
    for(auto& i:hashTable) i=-1;
    bfs();
    int totalToy;scanf("%d",&totalToy);
    for(int i=0;i<totalToy;++i){
        //读入玩具
        for(int j=0;j<4;++j) scanf("%d",&toy[j]);
        for(int j=0;j<4;++j) scanf("%d",&toy[7-j]);
        printf("%d\n",hashTable[toyHash(toy)]);
    }
    return 0;
}
