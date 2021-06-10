#pragma once//��ֹ��ΰ���

//ͷ�ļ�����
#include <bits/stdc++.h>
#include <any>
#include <variant>

//ȫ��������
std::fstream fio;
std::wfstream wfio;
std::stringstream sio;
std::wstringstream wsio;

//һ���߾����㷨

//�߾��ȼӷ�
void add(int* a,int* b,int* sum,int len){
    for(int i=0;i<len;i++){
        sum[i]+=a[i]+b[i];
    }
    for(int i=0;i<len;i++){
        sum[i+1]+=sum[i]/10;
        sum[i]%=10;
    }
}

//�߾��ȳ˷�
void times(int* a,int *b,int* product,int lena,int lenb){
    for(int i=0;i<lenb;i++){
        for(int j=0;j<lena;j++){
            product[j+i]+=a[j]*b[i];
        }
    }
    for(int i=0;i<lena+lenb;i++){
        product[i+1]+=product[i]/10;
        product[i]%=10;
    }
}

//�߾���ȡģ
int mod(int* a,int b,int len){
    int d=0;
    for(int i=0;i<len;i++){
        d=(d*10+a[i])%b;
    }
    return d;
}


//�������ֳ����㷨����

//����ɸѡ��
auto primeSelection(size_t num)
{
    std::vector<bool> isPrime(++num,true);//�ȼ�����������������
    isPrime[0]=isPrime[1]=false;//0��1������ѧ�ų�
    for(size_t i=2;i<num;i++)//�����治�ǵ�
    {
        if(isPrime[i])//���ﲻ���жϷ���������Ϊ������һ�����Էֽ�Ϊ���С����������������һ��������ǰ������
        {
            for(size_t j=2*i;j<num;j+=i)//������ϵ�ľ��Բ�������
            {
                isPrime[j]=false;
            }
        }
    }
    return isPrime;
}

//���������ж�
bool isPrime(size_t n)
{
    if(n==1) return false;//1��������
    if(n==2 || n==3) return true;//2��3���ݿ�ѧΪ����
    if(n%6!=1 && n%6!=5) return false;//ʣ��Ĳ���6k-1��6k+1�ı������Բ�������
    for(size_t i=5;i<=sqrt(n);i+=6)//������Ҳ��һ���������ж��ܷ�С���Լ���6k-1��6k+1������������
    {
        if(n%i==0||n%(i+2)==0) return false;
    }
    return true;

}

//���������
inline char myGetChar() {
    static char buf[1024], *p1 = buf, *p2 = buf;
    return (p1 == p2) &&
                   (p2 = (p1 = buf) + fread(buf, 1, 1024, stdin), p1 == p2) ? EOF : *p1++;
}
inline void readInt(int& x) {
    x = 0;
    static char ch = 0;
    while (!isdigit(ch)) {ch = myGetChar();}
    while (isdigit(ch)) {x = x * 10 + (ch ^ 48); ch = myGetChar();}
}
inline void readString(string& str){
    str="";
    static char ch = 0;
    while (!isalpha(ch)) {ch = myGetChar();}
    while (isalpha(ch)) {str += ch; ch = myGetChar();}
}

//�������㷨
int fastPow(int base,size_t power){
    if((base==0)&&(power==0)) throw("You Can't do that!");
    int result=1;
    while(power!=0){
        if(power&1) result*=base;
        base*=base;
        power>>=1;
    }
    return result;
}

//ȡ���ظ������
void getRad(int number,int total)
{
    std::vector<int> input;
    std::vector<int> output;
    input.reserve(total);
    output.reserve(total);
    for(int i=1;i<=total;i++)
    {
        input.push_back(i);
    }
    srand((unsigned int)time(NULL));
    for(int j=0;j<number;j++)
    {
        auto iter=input.begin();
        iter=iter+rand()%total;
        output.push_back(*iter);
        input.erase(iter);
        total--;
    }
    for(auto x:output){
        std::cout<<x;
    };
}

//�������
auto snakePrint(size_t height,size_t length){
    std::vector<std::vector<size_t>> array(height,std::vector<size_t>(length));//������ά����
    size_t top=0,bottom=height-1,left=0,right=length-1;//�趨�߽�
    for(size_t i=1;i<=length*height;){
        for(size_t j=left;(j<=right)&&(i<=length*height);j++){//�������
            array[top][j]=i++;
        }top++;
        for(size_t j=top;(j<=bottom)&&(i<=length*height);j++){//�������
            array[j][right]=i++;
        }right--;
        for(int j=right;(j>=int(left))&&(i<=length*height);j--){//�������
            array[bottom][j]=i++;
        }bottom--;
        for(int j=bottom;(j>=int(top))&&(i<=length*height);j--){//�������
            array[j][left]=i++;
        }left++;
    }
    return array;
}

//�ʺ�����
size_t nQueen(int queenNum=8,int boardNum=8,int now=0){
    static std::vector<std::pair<int,int>> onBoardQueen;
    static size_t count=0;
    //�ݹ��˳�����
    if(onBoardQueen.size()==static_cast<size_t>(queenNum)){
        count++;
        onBoardQueen.pop_back();
        return count;
    }
    for(;now<boardNum*boardNum;now++){
        if(onBoardQueen.empty()){
            onBoardQueen.push_back(std::make_pair(now/boardNum,now%boardNum));
            nQueen(queenNum,boardNum,now+1);
        }else{
            bool flag=true;
            for(auto&i:onBoardQueen){
                //ͬһ�У�ͬһ��ȥ��
                if((now/boardNum==i.first)||(now%boardNum==i.second)){
                    flag=false;
                    break;
                }
                //ͬһб��Ҳȥ��
                if(abs(now/boardNum-i.first)==abs(now%boardNum-i.second)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                onBoardQueen.push_back(std::make_pair(now/boardNum,now%boardNum));
                nQueen(queenNum,boardNum,now+1);
            }
        }
    }
    onBoardQueen.pop_back();
    return count;
}

//������
void sudoku(std::array<std::array<size_t,9>,9>& grid,size_t now=0){
    if(grid[now/9][now%9]!=0){//�������в���
        sudoku(grid,now+1);return;
    }
    //������������
    if(now==81) return;
    size_t maxNum=9;
    for(;(maxNum!=0)&&!grid[8][8];maxNum--){
        bool flag=true;
        for(size_t i=0;i<9;i++){//�������
            if(grid[now/9][i]==maxNum){flag=false;break;}
            if(grid[i][now%9]==maxNum){flag=false;break;}
        }
        for(size_t i=now/9/3*3;(i<now/9/3*3+3)&&flag;i++)//���Ź���
            for(size_t j=now%9/3*3;(j<now%9/3*3+3)&&flag;j++)
                if(grid[i][j]==maxNum){flag=false;break;}
        if(flag){
            grid[now/9][now%9]=maxNum;
            sudoku(grid,now+1);
        }
    }
    if(maxNum==0&&!grid[8][8]){//��������
        grid[now/9][now%9]=0;return;
    }
}

//��ӡ����
auto printDiamond(size_t n){
    std::vector<std::string> diamond(n);
    for(size_t i=0;i<n/2+1;i++){//�����ϰ벿��
        for(size_t j=0;j<n/2-i;j++) diamond[i]+="  ";
        for(size_t j=0;j<2*i+1;j++) diamond[i]+="* ";
    }
    for(size_t i=n/2+1;i<n;i++) diamond[i]=diamond[n-1-i];
    for(size_t i=0;i<n-1;i++) diamond[i]+="\n";
    for(auto &i:diamond) std::cout<<i;
}

//��ӡ��������
auto printHollowDiamond(size_t n){
    std::vector<std::string> hollowDiamond(n);
    for(size_t i=0;i<n/2+1;i++){//�����ߵ�һС��
        for(size_t j=0;j<n/2-i;j++) hollowDiamond[i]+=" ";
        hollowDiamond[i]+="*";
    }
    for(size_t i=0;i<n/2;i++){//���ʣ�µ�һ���
        for(size_t j=0;j<2*i+1;j++) hollowDiamond[i+1]+=" ";
        hollowDiamond[i+1]+="*";
    }
    for(size_t i=n/2+1;i<n;i++) hollowDiamond[i]=hollowDiamond[n-i-1];
    for(size_t i=0;i<n-1;i++) hollowDiamond[i]+="\n";
    for(auto &i:hollowDiamond) std::cout<<i;
}

//��ӡɳ©
auto printSandGlass(size_t n,std::string sign){
    size_t row=1,left=0;
    for(;n>2*row*row-1;row++);//������
    if(n<2*row*row-1){row--;left=n-2*row*row+1;}//����ʣ�µĸ���
    std::vector<std::string> sandGlass(2*row-1);
    for(size_t i=0;i<row;i++){
        for(size_t j=0;j<row-1-i;j++) sandGlass[i]+=" ";
        for(size_t j=0;j<2*i+1;j++) sandGlass[i]+=sign;
    }
    for(size_t i=row,j=1;i<2*row-1;j++,i++) sandGlass[i]=sandGlass[j];
    std::reverse(sandGlass.begin(),sandGlass.begin()+row);
    for(auto &i:sandGlass) std::cout<<i<<std::endl;
    std::cout<<left;
}

//��ӡX��
auto printX(size_t n){
    std::vector<std::string> x(n);
    for(size_t i=0;i<n/2+1;i++){//�����ߵ�һС��
        for(size_t j=0;j<n/2-i;j++) x[i]+=" ";
        x[i]+="*";
    }
    for(size_t i=0;i<n/2;i++){//���ʣ�µ�һ���
        for(size_t j=0;j<2*i+1;j++) x[i+1]+=" ";
        x[i+1]+="*";
    }
    reverse(x.begin(),x.begin()+n/2+1);
    for(size_t i=n/2+1;i<n;i++) x[i]=x[n-i-1];
    for(size_t i=0;i<n-1;i++) x[i]+="\n";
    for(auto &i:x) std::cout<<i;
}

//���δ������
auto printBigThree(size_t n){
    if(n<3) std::cout<<"Invalid Input";
    std::map<int,int,std::greater<int>> m;
    for(size_t i=0;i<n;i++){
        int temp;std::cin>>temp;
        m.insert(std::make_pair(temp,0));
    }
    if(m.size()==1){
        std::cout<<"There is no second largest and third largest element";
        return;
    }
    if(m.size()==2){
        std::cout<<"There is no third largest element";
        return;
    }
    for(size_t i=0;i<2;i++){
        std::cout<<m.begin()->first<<" ";
        m.erase(m.begin());
    }
    std::cout<<m.begin()->first;
}

//���������㷨

// ð������ǵݹ�
void bubbleSort(vector<int> &arr) {
  for (size_t i = 0; i < size(arr) - 1; ++i) {
    for (size_t j = 0; j < size(arr) - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// ð������ݹ�
void bubbleSort(vector<int> &arr, size_t index = 0) {
  if (index == size(arr) - 1) {
    return;
  }
  for (size_t j = 0; j < size(arr) - index - 1; ++j) {
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
    }
  }
  bubbleSort(arr, index + 1);
}

//��β������
template <typename T>
void cocktailSort(std::vector<T>& input){
    while(1){
        bool flag = true;//ѭ����������
        for(size_t i=0;i<input.size()-1;i++){//��������ð��
            if(input[i]>input[i+1]){
                swap(input[i],input[i+1]);
                flag=false;
            }
        }
        if(flag) break;
        flag = true;
        for(size_t i=input.size()-1;i>0;i--){//��������ð��
            if(input[i]<input[i-1]){
                swap(input[i],input[i-1]);
                flag=false;
            }
        }
        if(flag) break;
    }
}

// ѡ������ǵݹ�
void selectionSort(vector<int> &arr) {
  for (size_t i = 0; i < size(arr) - 1; ++i) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < size(arr); ++j) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}

// ѡ������ݹ�
void selectionSort(vector<int> &arr, size_t index = 0) {
  if (index == size(arr) - 1)
    return;
  size_t minIndex = index;
  for (size_t j = index + 1; j < size(arr); ++j) {
    if (arr[minIndex] > arr[j]) {
      minIndex = j;
    }
  }
  swap(arr[minIndex], arr[index]);
  selectionSort(arr, index + 1);
}

//��������ǵݹ�
void insertionSort(vector<int> &arr) {
  for (size_t i = 1; i < size(arr); ++i) {
    int temp = arr[i], pos = i;
    while (pos-- and arr[pos] > temp) {
      arr[pos + 1] = arr[pos];
    }
    arr[pos + 1] = temp;
  }
}

//��������ݹ�
void insertionSort(vector<int> &arr, size_t index = 1) {
  if (index == size(arr)) {
    return;
  }
  int temp = arr[index], pos = index;
  while (pos-- and arr[pos] > temp) {
    arr[pos + 1] = arr[pos];
  }
  arr[pos + 1] = temp;
  insertionSort(arr, index + 1);
}

//ϣ������
void shellSort(int arr[],int len){
    int increasement=len;
    int i,j,k;
    do{
        increasement=increasement/3+1;
        for(i=0;i<increasement;i++){
            for(j=i;
                 j+increasement<len;
                 j+=increasement){
                int temp=arr[j+increasement];
                for(k=j;
                     k>=0 && temp<arr[k];
                     k-=increasement){
                    arr[k+increasement]=arr[k];
                }
                arr[k+increasement]=temp;
            }
        }
    }while(increasement > 1);
}

// ��������ݹ�
void quickSort(vector<int> &arr, int start, int end) {
  if (start >= end) return;
  int i = start - 1, j = end + 1, pivot = arr[(start + end) >> 1];
  while (i < j) {
    while (arr[++i] < pivot);
    while (arr[--j] > pivot);
    if (i < j) swap(arr[i], arr[j]);
  }
  quickSort(arr, start, j);
  quickSort(arr, j + 1, end);
}

// ��������ǵݹ�
void quickSort(vector<int> &arr, int start, int end) {
  stack<int> s;
  s.emplace(end);
  s.emplace(start);
  while (not s.empty()) {
    int start = s.top();
    s.pop();
    int end = s.top();
    s.pop();
    int i = start - 1, j = end + 1, pivot = arr[(start + end) >> 1];
    while (i < j) {
      while (arr[++i] < pivot);
      while (arr[--j] > pivot);
      if (i < j) swap(arr[i], arr[j]);
    }
    if (j > start) {
      s.emplace(j);
      s.emplace(start);
    }
    if (end > j + 1) {
      s.emplace(end);
      s.emplace(j + 1);
    }
  }
}

//�鲢����
void mergeSort(vector<int> &arr, int start, int end) {
  if (start >= end) return;
  int length = 0, mid = (start + end) >> 1;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  vector<int> temp(end - start + 1);
  int iStart = start, iEnd = mid, jStart = mid + 1, jEnd = end;
  while (iStart <= iEnd and jStart <= jEnd) {
    if (arr[iStart] < arr[jStart]) temp[length++] = arr[iStart++];
    else temp[length++] = arr[jStart++];
  }
  while (iStart <= iEnd) temp[length++] = arr[iStart++];
  while (jStart <= jEnd) temp[length++] = arr[jStart++];
  memcpy(&arr[start], &temp[0], size(temp) * 4);
}

// ������
void siftDown(vector<int> &arr, size_t index, size_t length) {
  size_t lchild = 2 * index + 1, rchild = 2 * index + 2, maxIndex = index;
  if (lchild < length and arr[lchild] > arr[maxIndex]) {
    maxIndex = lchild;
  }
  if (rchild < length and arr[rchild] > arr[maxIndex]) {
    maxIndex = rchild;
  }
  if (maxIndex != index) {
    swap(arr[maxIndex], arr[index]);
    siftDown(arr, maxIndex, length);
  }
}
void heapSort(vector<int> &arr) {
  for (int i = (size(arr) - 1) / 2; i >= 0; --i) {
    siftDown(arr, i, size(arr));
  }
  for (size_t i = size(arr) - 1; i > 0; --i) {
    swap(arr[0], arr[i]);
    siftDown(arr, 0, i);
  }
}

//��������
void countingSort(std::vector<int>& input){
    int offset=input[0],maxNum=input[0];
    for(auto &i:input){//�ҵ����ֵ��ƫ����
        if(i<offset) offset=i;
        if(i>maxNum) maxNum=i;
    }
    std::vector<int> output[maxNum-offset+1];//��������
    for(auto& i:input) output[i-offset].push_back(i);//����
    input.clear();
    for(auto& arr:output)//��������
        for(auto& i:arr)
            input.push_back(i);
}

//Ͱ����
template <typename T>
void bucketSort(std::vector<T>& input){
    T minNum=input[0],maxNum=input[0];
    for(auto &i:input){//�ҵ����ֵ��ƫ����
        if(i<minNum) minNum=i;
        if(i>maxNum) maxNum=i;
    }
    std::vector<T> buckets[input.size()];//���������Ԫ�ظ���һ����Ͱ
    double gap=double(maxNum-minNum)/(input.size()-1);//�����Ͱ֮��Ĳ��
    //��Ԫ�ط���Ͱ��
    for(auto& i:input) buckets[size_t((i-minNum)/gap)].push_back(i);
    input.clear();
    for(auto& arr:buckets){
        sort(arr.begin(),arr.end());//��Ͱ��������
        for(auto &i:arr)
            input.push_back(i);
    }
}

//�������������ͣ�
void radixSortForInt(std::vector<int>& input){
    auto getNum=[](int num,size_t index){//��ȡ������λ�ϵ�����
        std::stringstream s;std::string str;s<<num;s>>str;s.clear();
        if(index>=str.length()) return 0;
        reverse(str.begin(),str.end());
        return str[index]-48;
    };
    int maxNum=input[0];size_t count=0;
    for(auto& i:input) if(i>maxNum) maxNum=i;//�������
    for(;maxNum!=0;maxNum/=10,count++);//���������λ��
    for(size_t i=0;i<count;i++){//һ��Ҫѭ������
        int offset=getNum(input[0],i),maxNum=getNum(input[0],i);
        for(auto &j:input){//�ҵ����ֵ��ƫ����
            if(getNum(j,i)<offset) offset=getNum(j,i);
            if(getNum(j,i)>maxNum) maxNum=getNum(j,i);
        }
        std::vector<int> output[maxNum-offset+1];//��������
        for(auto& j:input) output[getNum(j,i)-offset].push_back(j);//����
        input.clear();
        for(auto& arr:output)//��������
            for(auto& j:arr)
                input.push_back(j);
    }
}

//���������ַ����ֵ�˳��
void radixSortForString(std::vector<std::string>& input){
    size_t longest=0;
    for(auto& i:input) if(i.length()>longest) longest=i.length();//����ַ���
    auto getString=[&](std::string str,size_t index){//��ȡ����λ���ϵ��ַ�
        while(str.length()<longest) str+='0';//�����ں��油0
        reverse(str.begin(),str.end());return str[index];//��ת����
    };
    for(size_t i=0;i<longest;i++){//һ��Ҫѭ������
        int offset=getString(input[0],i),maxNum=getString(input[0],i);
        for(auto &j:input){//�ҵ����ֵ��ƫ����
            if(getString(j,i)<offset) offset=getString(j,i);
            if(getString(j,i)>maxNum) maxNum=getString(j,i);
        }
        std::vector<std::string> output[maxNum-offset+1];//��������
        for(auto& j:input) output[getString(j,i)-offset].push_back(j);//����
        input.clear();
        for(auto& arr:output)//��������
            for(auto& j:arr)
                input.push_back(j);
    }
}

//���ݽṹ�㷨
//��ӡ����ջ����
void printAllSeq(vector<int>& seq,stack<int>& mid,vector<int>& last){
    //�������վ����
    if(seq.empty()&&mid.empty()){
        for(const auto& i: last) cout<<i<<" ";
        cout<<endl;
        return;
    }
    //����push
    if(!seq.empty()){
        mid.push(seq.back());
        seq.pop_back();
        printAllSeq(seq,mid,last);
        //����ʱŪ����
        seq.emplace_back(mid.top());
        mid.pop();
    }
    //��pop
    if(!mid.empty()){
        last.emplace_back(mid.top());
        mid.pop();
        printAllSeq(seq,mid,last);
        //����ʱŪ����
        mid.push(last.back());
        last.pop_back();
    }
}

// ����һ�������Ƿ��ǺϷ�ջ����
bool checkSeq(vector<int> origin, const vector<int> &target) {
  // ��תʹ��ԭʼ���б��ջ�ṹ
  reverse(begin(origin), end(origin));
  // ��תջ
  stack<int> s;
  for (const auto &i : target) {
    // ���ջ�ջ���ջ��Ԫ�ز�����target��ӦԪ�ؾ���ջ
    while ((s.empty() or s.top() not_eq i) and not origin.empty()) {
      s.emplace(origin.back());
      origin.pop_back();
    }
    // ��������˵��Ҫôջ��Ԫ�ص���target��ӦԪ�أ�Ҫôʧ����
    if (s.top() not_eq i) {
      return false;
    } else {
      s.pop();
      continue;
    }
  }
  return s.empty() and origin.empty();
}

//kmp
vector<int> buildNext(string pattern){
    vector<int> next(pattern.length());
    int t=next.at(0)=-1;
    for(size_t i=0;i<pattern.length()-1;){
        if(t<0 or pattern.at(i)==pattern.at(t)){
            ++i;++t;
            next.at(i)=pattern.at(i)==pattern.at(t)?next.at(t):t;
        }else t=next.at(t);
    }
    return next;
}

vector<int> match(string text,string pattern){
    vector<int> next=buildNext(pattern);
    vector<int> matches;
    int i=0,j=0;
    while(true){
        //��Ҫƥ��ѭ��
        while(i<int(text.length()) and j<int(pattern.length())){
            //���ƥ���Я�ֹ�������ƥ���ת����һ��λ�ü���ƥ��
            if(j<0 or text.at(i)==pattern.at(j)) (++i,++j);
            else j=next.at(j);
        }
        //���һ��ƥ�������λ��
        if(i-j<int(text.length()-pattern.length())){
            matches.emplace_back(i-j);
            //����һ��λ�ÿ�ʼƥ��
            i=i-j+1;j=0;
        }else{
            //�����ļ��
            string cutText{end(text)-pattern.length(),end(text)};
            if(cutText==pattern) matches.emplace_back(text.length()-pattern.length());
            break;
        }
    }
    return matches;
}

A*Ѱ·
struct Node{
    Node(){}
    Node(int x,int y,int cnt,int f,Node* parent):x(x),y(y),cnt(cnt),f(f),parent(parent){}
    bool operator<(const Node& rhs){return this->f<rhs.f;}
    //�����ͼ�ϵ�λ�úͶ�Ӧ��Fֵ�;��뿪ʼλ�õĲ���cnt
    int x,y,cnt{0},f{0};
    Node* parent=nullptr;
};
list<pair<int,int>> AStarPathFinding(vector<vector<int>>& map,int startX,int startY,int endX,int endY){
    //���ڴ���Ѿ��������ͻ�û�������Ľ��
    list<Node> openList,closeList;
    //��ŷ���·��������
    list<pair<int,int>> ret;
    //�Թ���СΪ0���߿�ʼλ�õ��ڽ���λ��ʱֱ�ӷ���
    if(startX==endX and startY==endY){
        if(!map.at(startX).at(startY)) ret.emplace_front(startX,startY);
        return ret;
    }
    //��������
    auto f=[&](int x,int y){return abs(endX-x)+abs(endY-y);};
    //��⺯��
    auto check=[&](Node& node){
        return !map.at(node.x).at(node.y)
               and !count_if(cbegin(closeList),cend(closeList),[&](const Node& tmp){
                       return tmp.x==node.x and tmp.y==node.y;
                   });};
    //װ�ص�һ���ڵ�
    openList.emplace_front(startX,startY,0,f(startX,startY),nullptr);
    //��ѭ��
    while(!openList.empty()){
        //ȡ��Fֵ��С�Ľڵ�
        auto it=min_element(begin(openList),end(openList));
        //��openList���Ƴ�������closeList
        closeList.emplace_front(it->x,it->y,it->cnt,it->f,it->parent);
        Node& head=closeList.front();
        openList.erase(it);
        //�˳�����
        if(head.x==endX and head.y==endY){
            const Node* node=&head;
            //�����·������������
            while(node){
                ret.emplace_front(node->x,node->y);
                node=node->parent;
            }
            break;
        }
        //�鿴���������ܷ��߶������߾���openList
        Node test(head.x-1,head.y,head.cnt+1,f(head.x-1,head.y)+head.cnt+1,&head);
        if(check(test)) openList.insert(begin(openList),test);
        test.x=head.x;
        test.y=head.y-1;
        test.f=f(head.x,head.y-1)+test.cnt;
        if(check(test)) openList.insert(begin(openList),test);
        test.x=head.x+1;
        test.y=head.y;
        test.f=f(head.x+1,head.y)+test.cnt;
        if(check(test)) openList.insert(begin(openList),test);
        test.x=head.x;
        test.y=head.y+1;
        test.f=f(head.x,head.y+1)+test.cnt;
        if(check(test)) openList.insert(begin(openList),test);
    }
    return ret;
}

// floyd��Դ��̾����㷨
struct Node {
  char mData;
  Node(char data) : mData{data} {}
};
vector<Node> vertexs;
vector<vector<uint64_t>> floydMaxshall(vector<vector<uint64_t>> adjacentMatrix) {
  vector<vector<uint64_t>> shortestPath{adjacentMatrix};
  //���������м�ڵ�
  for (uint64_t mid = 0; mid < size(adjacentMatrix); ++mid) {
    //����������ĸ��ڵ����
    for (uint64_t from = 0; from < size(adjacentMatrix); ++from) {
      //��ײ�����ĸ��ڵ����
      for (uint64_t to = 0; to < size(adjacentMatrix); ++to) {
        //������ɴ��continue
        if (shortestPath[from][mid] == numeric_limits<uint64_t>::max() or
            shortestPath[mid][to] == numeric_limits<uint64_t>::max()) {
          continue;
        }
        //����ɴ���¾���
        shortestPath[from][to] =
            min(shortestPath[from][to],
                shortestPath[from][mid] + shortestPath[mid][to]);
      }
    }
  }
  return shortestPath;
}

// dijkstra��Դ���·���㷨
// �����INF��������������ԭ���Ƿ�ֹ���ʱ�������
constexpr int INF = 0x3F3F3F3F;
vector<int> dijkstra(vector<vector<int>> &edge, int start) {
  using T = pair<int, int>;
  priority_queue<T, vector<T>, greater<>> queue;
  // lowcost��¼��δ����С�������е���С����ĵ�,parent��¼������
  vector<int> lowcost(size(edge), INF), parent(size(edge), -1);
  lowcost[start] = 0;
  // �׽ڵ�����
  queue.emplace(0, start);
  while (not queue.empty()) {
    //�ӶѶ�ȡ����СԪ
    auto now = queue.top();
    queue.pop();
    if (lowcost[now.second] < now.first) {
      continue;
    }
    // �����½ڵ����������,����Ҫ�������½ڵ����ӵĵ�ľ���
    for (size_t j = 0; j < size(edge); ++j) {
      if (lowcost[j] > lowcost[now.second] + edge[now.second][j]) {
        queue.emplace(lowcost[j] = lowcost[now.second] + edge[now.second][j], j);
        parent[j] = now.second;
      }
    }
  }
  return parent;
}

// prim��С�������㷨
// �����INF��������������ԭ���Ƿ�ֹ���ʱ�������
constexpr int INF = 0x3F3F3F3F;
vector<int> prim(vector<vector<int>> &edge, int start) {
  using T = pair<int, int>;
  priority_queue<T, vector<T>, greater<>> queue;
  // lowcost��¼��δ����С�������е���С����ĵ�,parent��¼������
  vector<int> lowcost(size(edge), INF), parent(size(edge), -1);
  lowcost[start] = 0;
  // �׽ڵ�����
  queue.emplace(0, start);
  while (not queue.empty()) {
    //�ӶѶ�ȡ����СԪ
    auto now = queue.top();
    queue.pop();
    if (lowcost[now.second] < now.first) {
      continue;
    }
    // �����½ڵ����������,����Ҫ�������½ڵ����ӵĵ�ľ���
    for (size_t j = 0; j < size(edge); ++j) {
      if (lowcost[j] > edge[now.second][j]) {
        queue.emplace(lowcost[j] = edge[now.second][j], j);
        parent[j] = now.second;
      }
    }
  }
  return parent;
}

//��������
vector<int> topSort(vector<vector<int>> &edge, vector<int> &degree) {
  vector<int> res;
  queue<int> queue;
  for (size_t i = 0; i < size(edge); ++i) if (not degree[i]) queue.emplace(i);
  while (not queue.empty()) {
    int now = queue.front();
    queue.pop();
    res.emplace_back(now);
    for (const auto& adj : edge[now]) if (--degree[adj] == 0) queue.emplace(adj);
  }
  return res;
}

//����ת�õݹ�
struct Node {
  Node *next;
};
Node *head = nullptr;
void reverseList(Node *a = nullptr, Node *&b = head, Node *c = head->next) {
  b->next = a;
  if (c == nullptr) {head = b; return;};
  reverseList(b, c, c->next);
}

//����ת�÷ǵݹ�
struct Node {
  Node *next;
};
Node *head = nullptr;
void reverseList() {
  Node *a = nullptr, *&b = head, *c = head->next;
  while (c) {
    b->next = a;
    a = b;
    b = c;
    c = c->next;
  }
  b->next = a;
}

// ������������ݹ�
vector<vector<int>> edge;
vector<char> nodes;
vector<bool> visited;
void dfs(size_t now = 0) {
  if (visited[now]) return;
  visited[now] = true;
  cout << nodes[now];
  for (const auto &i : edge[now]) dfs(i);
}

// ������������ǵݹ�
void dfs(vector<vector<int>> &edge, vector<char> &nodes) {
  vector<bool> visited(size(edge), false);
  stack<int> s;
  for (size_t i = 0; i < size(nodes); ++i) {
    if (not visited[i]) {
      visited[i] = true;
      s.emplace(i);
    }
    while (not s.empty()) {
      int now = s.top(); s.pop();
      cout << nodes[now];
      for (const auto &adj : edge[now]) {
        if (not visited[adj]) {
          visited[adj] = true;
          s.emplace(adj);
        }
      }
    }
  }
}

// ������������ǵݹ�
void bfs(vector<vector<int>> &edge, vector<char> &nodes) {
  vector<bool> visited(size(edge), false);
  queue<int> q;
  for (size_t i = 0; i < size(nodes); ++i) {
    if (not visited[i]) {
      visited[i] = true;
      q.emplace(i);
    }
    while (not q.empty()) {
      int now = q.front(); q.pop();
      cout << nodes[now];
      for (const auto &adj : edge[now]) {
        if (not visited[adj]) {
          visited[adj] = true;
          q.emplace(adj);
        }
      }
    }
  }
}

// ������������ݹ�
vector<bool> visited;
vector<vector<int>> edge;
vector<char> nodes;
queue<int> q;
void bfs(size_t now = 0) {
  if (now == size(nodes)) {
    return;
  }
  if (not visited[now]) {
    visited[now] = true;
    q.emplace(now);
  }
  while (not q.empty()) {
    int now = q.front();
    q.pop();
    cout << nodes[now];
    for (const auto &adj : edge[now]) {
      if (not visited[adj]) {
        visited[adj] = true;
        q.emplace(adj);
      }
    }
  }
  bfs(now + 1);
}

// �Թ�����
constexpr int N = 10000;
using T = pair<int, int>;
T PARENT[N][N];
bool VISITED[N][N];
int ROW, COL;
int DELTA[2] = {-1, 1};
vector<T> pathFind(T target) {
  queue<T> q;
  q.emplace(1, 1);
  while (!q.empty()) {
    T now = q.front();
    q.pop();
    if (now == target)
      break;
    VISITED[now.first][now.second] = true;
    for (const auto &delta : DELTA) {
      int newX = now.first + delta;
      int newY = now.second;
      if (newX && newX <= COL && !VISITED[newX][newY]) {
        q.emplace(newX, newY);
        PARENT[newX][newY] = {now.first, now.second};
      }
      newX = now.first;
      newY = now.second + delta;
      if (newY && newY <= ROW && !VISITED[newX][newY]) {
        q.emplace(newX, newY);
        PARENT[newX][newY] = {now.first, now.second};
      }
    }
  }
  vector<T> ret;
  while (true) {
    if (target == make_pair(1, 1)) {
      ret.emplace_back(1, 1);
      reverse(begin(ret), end(ret));
      return ret;
    }
    ret.push_back(target);
    target = PARENT[target.first][target.second];
  }
}

// �������ת��
constexpr int N = 10000;
int n;
int CNT[N];
int POS[N];
struct Tuple {
  int row, col, value;
} TABLE[N], TEMP[N];
void reverse() {
  memset(CNT, 0, N * 4);
  memset(POS, 0, N * 4);
  for (int i = 0; i < n; ++i) ++CNT[TABLE[i].col];
  POS[0] = CNT[0];
  for (int i = 1; i < n; ++i) POS[i] = POS[i - 1] + CNT[i - 1];
  for (int i = 0; i < n; ++i) TEMP[i] = TABLE[i];
  for (const auto &i : TEMP) TABLE[POS[i.col]++] = i;
}

// �����������
constexpr int N = 10000;
bool FLAG[N];
// ��Ŵ�1��ʼ����������
// ����Ĳ�������������е���������
// ��������0����û�й�������
int lca(int a, int b) {
  while (a) FLAG[a /= 2] = true;
  while (!FLAG[b /= 2]);
  return b;
}

// ���鼯����С������
constexpr int N = 1e5 + 10;
int father[N];
int find(int x) {return x != father[x] ? father[x] = find(father[x]) : x;}
void combine(int x, int y) {father[find(x)] = find(y);}
using Edge = tuple<int, int, int>;
vector<Edge> edges;
auto kruskal() {
  iota(begin(father), end(father), 0);
  sort(begin(edges), end(edges));
  vector<Edge> ret;
  for (const auto& [weight, from, to] : edges) {
    if (find(from) != find(to)) {
      combine(from, to);
      ret.emplace_back(weight, from, to);
    }
  }
  return ret;
}

// sum����������value�������ڼ������֣���0��ʼ
int josephus (int sum, int value)
{
  if (sum == 1) return (sum + value - 1) % sum ;
  else return (josephus(sum - 1, value) + value) % sum;
}

// ���޸����ȶ���
template <typename _Tp, typename _Compare = less<>>
struct MutableQueue : public priority_queue<_Tp, vector<_Tp>, _Compare> {
  MutableQueue() = default;
  MutableQueue(_Compare _cmp)
      : priority_queue<_Tp, vector<_Tp>, _Compare>(_cmp) {}
  //���������Ԫ��ʱ���ô˺���
  void update() { std::make_heap(begin(c), end(c), comp); }
};