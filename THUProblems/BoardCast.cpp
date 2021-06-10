#include <iostream>
using namespace std;
struct Vertex;
struct Node{
    Node(Vertex* dat,Node* nextNode):data(dat),next(nextNode){}
    Vertex* data=nullptr;
    Node* prev=nullptr;
    Node* next=nullptr;
};
struct Queue{
    Node* head=nullptr;
    Node* last=nullptr;
    void insert(Vertex* vertex){
        if(!head){
            last=head=new Node(vertex,head);
        }else{
            Node* p=new Node(vertex,head);
            head->prev=p;
            head=p;
        }
    }
    bool empty(){
        return !head;
    }
    Node* popBack(){
        if(head==last) head=nullptr;
        Node* p=last;
        last=last->prev;
        if(last) last->next=nullptr;
        return p;
    }
};
struct Vertex{
    //该节点被访问的标志
    bool flag=false;
    //当前节点使用的FM频段
    bool fm=false;
    //保存邻居节点的链表
    Node* adjacent=nullptr;
    void insert(Vertex* vertex){
        adjacent=new Node(vertex,adjacent);
    }
};
Queue queue;
void bfs(){
    if(queue.empty()) return;
    Vertex* v=queue.popBack()->data;
    //每次访问都将该节点的已访问标志置为真
    v->flag=true;
    for(Node* p=v->adjacent;p;p=p->next){
        //所有与之有关联的全部节点检查并入队列
        if(p->data->flag){
            //冲突，退出
            if(p->data->fm==v->fm){
                printf("-1");
                exit(0);
            }
        }else{
            //设置fm
            p->data->fm=!v->fm;
            queue.insert(p->data);
        }
    }
    bfs();
}
int BoardCast(){
    int totalV,lineNum;
    scanf("%d %d",&totalV,&lineNum);
    Vertex* v=new Vertex[totalV];
    for(int i=0;i<lineNum;++i){
        int vNow,vDest;
        scanf("%d %d",&vNow,&vDest);
        v[vNow-1].insert(&v[vDest-1]);
        v[vDest-1].insert(&v[vNow-1]);
    }
    for(int i=0;i<totalV;++i){
        if(!v[i].flag){
            queue.insert(&v[i]);
            bfs();
        }
    }
    printf("1");
    return 0;
}
