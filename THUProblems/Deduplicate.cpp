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
    //次方hash
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
        //查看有没有
        Node* p=head;
        for(;p;p=p->next){
            if(p->name==name){
                //找到相同项，看有没有输出过
                if(!p->flag){
                    //没有输出过，输出一下
                    printf("%s\n",name);
                    //输出一次后就不能再次输出了
                    p->flag=true;
                }
                break;
            }
        }
        //没有找到才插入
        if(!p) head=new Node(name,head);
    }
    return 0;
}
