#include <iostream>
#include "temperature.h"
using namespace std;
struct Station{
    int x;
    int y;
    int temperature;
};
Station* stations;
//二分查找返回第一个不大于dest的下标
int binSearch(int hi,int dest){
    int lo=0,mid=(lo+hi)>>1;
    while(lo<hi){
        if(stations[mid].x<=dest){
            lo=mid+1;
        }else{
            hi=mid;
        }
        mid=(lo+hi)>>1;
    }
    return lo;
}
//快速排序
void quickSort(Station arr[],int start,int end){
    if(start>=end) return;
    int i=start,j=end;
    Station pivot=arr[start];
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
int main(){
    int totalNum=GetNumOfStation();
    stations=new Station[totalNum];
    for(int i=0;i<totalNum;++i){
        GetStationInfo(i,&stations[i].x,&stations[i].y,&stations[i].temperature);
    }
    //排序
    quickSort(stations,0,totalNum-1);
    int x1,x2,y1,y2;
    while(GetQuery(&x1,&y1,&x2,&y2)){
        //用于记录所有观测站温度的总变量
        ssize_t total=0;
        //二分查找确定x的范围
        int start=binSearch(totalNum,x1-1);
        int end=binSearch(totalNum,x2);
        int count=0;
        //线性扫描找对应的y
        while(start!=end){
            if(stations[start].y>=y1&&stations[start].y<=y2){
                //如果在范围内
                ++count;
                total+=stations[start].temperature;
            }
            ++start;
        }
        total/=count?count:1;
        Response(total);
    }
}
