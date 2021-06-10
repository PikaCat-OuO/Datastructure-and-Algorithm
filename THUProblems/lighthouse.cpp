#include <iostream>
#include <cstring>
struct LightHouse{
    int x;
    int y;
};
long long totalPair=0;
int temp[4000000];
//快速输入挂
inline char myGetChar() {
    static char buf[1024], *p1 = buf, *p2 = buf;
    return (p1 == p2) &&
                   (p2 = (p1 = buf) + fread(buf, 1, 1024, stdin), p1 == p2) ? EOF : *p1++;
}
inline void readChar(int& x) {
    x = 0;
    static char ch = 0;
    while (!isdigit(ch)) {ch = myGetChar();}
    while (isdigit(ch)) {x = x * 10 + (ch ^ 48); ch = myGetChar();}
}
//二分查找
int binSearch(int* seq,int lo,int hi,int target){
    int mi=(lo+hi)>>1;
    while(hi>lo){
        if(seq[mi]<=target) lo=mi+1;
        else hi=mi;
        mi=(lo+hi)>>1;
    }
    return lo;
}
//快速排序
void quickSort(LightHouse arr[],int start,int end){
    if(start>=end) return;
    int i=start,j=end;
    LightHouse pivot=arr[start];
    while(i<j){
        while(i<j && pivot.x<=arr[j].x) j--;
        if(i<j) arr[i++]=arr[j];
        while(i<j && pivot.x>=arr[i].x) i++;
        if(i<j) arr[j--]=arr[i];
    }
    arr[i]=pivot;
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}
//归并排序
void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    for(int i=mid+1;i<=end;++i){
        totalPair+=binSearch(arr,start,mid+1,arr[i])-start;
    }
    int length=0,i_start=start,i_end=mid,j_start=mid+1,j_end=end;
    while(i_start<=i_end && j_start<=j_end){
        if(arr[i_start]<arr[j_start]){
            temp[length++]=arr[i_start++];
        }else{
            temp[length++]=arr[j_start++];
        }
    }
    while(i_start<=i_end){
        temp[length++]=arr[i_start++];
    }
    while(j_start<=j_end){
        temp[length++]=arr[j_start++];
    }
    memmove(&arr[start],&temp[0],length*4);
}
int main(){
    int totalNum;
    scanf("%d",&totalNum);
    LightHouse* lightHouses=new LightHouse[totalNum];
    int* arr=new int[totalNum];
    for(int i=0;i<totalNum;++i){
        readChar(lightHouses[i].x);
        readChar(lightHouses[i].y);
    }
    quickSort(lightHouses,0,totalNum-1);
    for(int i=0;i<totalNum;++i){
        arr[i]=lightHouses[i].y;
    }
    mergeSort(arr,0,totalNum-1);
    printf("%lld",totalPair);
    return 0;
}
