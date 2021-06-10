#include <iostream>
//二分查找
int binSearch(int* seq,int size,int target){
    int lo=0,hi=size,mi=(lo+hi)>>1;
    while(hi>lo){
        if(seq[mi]<=target) lo=mi+1;
        else hi=mi;
        mi=(lo+hi)>>1;
    }
    return --lo;
}
//快速排序
void quickSort(int arr[],int start,int end){
    if(start>=end) return;
    int i=start,j=end,pivot=arr[start];
    while(i<j){
        while(i<j && pivot<=arr[j]) j--;
        if(i<j) arr[i++]=arr[j];
        while(i<j && pivot>=arr[i]) i++;
        if(i<j) arr[j--]=arr[i];
    }
    arr[i]=pivot;
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}
int range()
{
    int totalNum,totalSearch;
    scanf("%d %d",&totalNum,&totalSearch);
    int seq[totalNum];
    for(int i=0;i<totalNum;++i){
        scanf("%d",&seq[i]);
    }
    quickSort(seq,0,totalNum-1);
    for(int i=0;i<totalSearch;++i){
        int left,right;scanf("%d %d",&left,&right);
        printf("%d\n",binSearch(seq,totalNum,right)
                           -binSearch(seq,totalNum,left-1));
    }
    return 0;
}
