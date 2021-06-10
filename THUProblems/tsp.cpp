#include <iostream>
using namespace std;
struct Vertex;
struct Node{
    Node(Vertex* dat,Node* nextNode):data(dat),next(nextNode){}
    Vertex* data=nullptr;
    Node* next=nullptr;
};
struct Vertex{
    //�ýڵ㱻���ʵı�־
    bool flag=false;
    //�ӵ�ǰ�ڵ�����ܷ��ʵ����ٸ������ڵ�
    int count=0;
    //�����ھӽڵ������
    Node* adjacent=nullptr;
    void insert(Vertex* vertex){
        adjacent=new Node(vertex,adjacent);
    }
};
void dfs(Vertex* v){
    v->flag=true;
    for(Node* p=v->adjacent;p;p=p->next){
        if(!p->data->flag) dfs(p->data);
        if(v->count<p->data->count){
            v->count=p->data->count;
        }
    }
    ++v->count;
}
int tsp(){
    int totalV,lineNum;
    scanf("%d %d",&totalV,&lineNum);
    Vertex* v=new Vertex[totalV];
    for(int i=0;i<lineNum;++i){
        int vNow,vDest;
        scanf("%d %d",&vNow,&vDest);
        v[vNow-1].insert(&v[vDest-1]);
    }
    for(int i=0;i<totalV;++i){
        if(!v[i].flag) dfs(&v[i]);
    }
    int max=0;
    for(int i=0;i<totalV;++i){
        if(v[i].count>max) max=v[i].count;
    }
    printf("%d",max);
    return 0;
}
