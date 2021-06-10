#include <iostream>
#include <string>
using namespace std;
struct Node{
    string name;
    bool flag=false;
    Node* next=nullptr;
    Node(string str,Node* node):name(str),next(node){}
};
Node* hashTable[600001];
unsigned nameHash(string name){
    unsigned res=0;
    //�η�hash
    for(unsigned i=0;i<name.length();++i){
        res+=i%2?name[i]:name[i]*name[i]*name[i];
    }
    return res%600001;
}
int Deduplicate(){
    int num;
    scanf("%d",&num);
    char name[100];
    for(int i=0;i<num;++i){
        scanf("%s",name);
        Node*& head=hashTable[nameHash(name)];
        //�鿴��û��
        Node* p=head;
        for(;p;p=p->next){
            if(p->name==name){
                //�ҵ���ͬ�����û�������
                if(!p->flag){
                    //û������������һ��
                    printf("%s\n",name);
                    //���һ�κ�Ͳ����ٴ������
                    p->flag=true;
                }
                break;
            }
        }
        //û���ҵ��Ų���
        if(!p) head=new Node(name,head);
    }
    return 0;
}
