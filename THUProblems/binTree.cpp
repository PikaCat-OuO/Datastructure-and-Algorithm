#include <iostream>
using namespace std;
void inOrder(int* pre,int* post,
             int startPre,int endPre,
             int startPost,int endPost){
    if(startPre>=endPre||startPost>=endPost) return;
    int i=startPre+1;
    for(;i<endPre;++i){
        if(pre[i]==post[endPost-2]) break;
    }
    int j=startPost;
    for(;j<endPost-1;++j){
        if(post[j]==pre[startPre+1]) break;
    }
    inOrder(pre,post,startPre+1,i,startPost,j+1);
    printf("%d ",pre[startPre]);
    inOrder(pre,post,i,endPre,j+1,endPost-1);
}
int binTree(){
    int totalNum;cin>>totalNum;
    int* preOrder=new int[totalNum],*postOrder=new int[totalNum];
    for(int i=0;i<totalNum;++i){
        scanf("%d",&preOrder[i]);
    }
    for(int i=0;i<totalNum;++i){
        scanf("%d",&postOrder[i]);
    }
    inOrder(preOrder,postOrder,0,totalNum,0,totalNum);
    return 0;
}
