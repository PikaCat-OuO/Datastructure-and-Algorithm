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
    //�ýڵ㱻���ʵı�־
    bool flag=false;
    //��ǰ�ڵ�ʹ�õ�FMƵ��
    bool fm=false;
    //�����ھӽڵ������
    Node* adjacent=nullptr;
    void insert(Vertex* vertex){
        adjacent=new Node(vertex,adjacent);
    }
};
Queue queue;
void bfs(){
    if(queue.empty()) return;
    Vertex* v=queue.popBack()->data;
    //ÿ�η��ʶ����ýڵ���ѷ��ʱ�־��Ϊ��
    v->flag=true;
    for(Node* p=v->adjacent;p;p=p->next){
        //������֮�й�����ȫ���ڵ��鲢�����
        if(p->data->flag){
            //��ͻ���˳�
            if(p->data->fm==v->fm){
                printf("-1");
                exit(0);
            }
        }else{
            //����fm
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
