#include <iostream>
#include <string>
using namespace std;
bool contains(string left,string right){
    if(left.length()!=right.length()) return false;
    size_t sum=0;
    size_t sum2=0;
    for(const auto& i:left) sum+=i;
    for(const auto& i:right) sum2+=i;
    return sum==sum2;
}
int Cycle(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    string left,right;
    while(cin>>left){
        bool flag=false;
        cin>>right;
        if(!contains(left,right)){
            cout<<"NO"<<endl;
            continue;
        }
        for(size_t i=0;i<right.length();++i){
            size_t j=0,k=i;
            //Æ¥Åä¼ì²é
            for(;j<left.length();++j){
                if(right[k++%left.length()]!=left[j]) break;
            }
            if(j==left.length()){
                flag=true;
                break;
            }
            if(flag) break;
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}
