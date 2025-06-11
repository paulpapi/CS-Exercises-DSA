#include<iostream>
#include<climits>
using namespace std;
int topDownFibo(int n,vector<int>&memo){
    if(memo[n]!=0)
    return memo[n];
    if(n<=2)
    memo[n]=0;
    else{
        memo[n]=topDownFibo(n-1,memo)+topDownFibo(n-2,memo);
    }
    return memo[n];
}
int bottomUpFibo(int n){
    if(n<=2)
    return 0;
    vector<int>memo(n+1);
    memo[0]=0;
    memo[1]=1;
    for(int i=2;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
}
vector<int>memo;
int topDownRodcut(int price[],int n){
    if(n==0)
    return 0;
    if(memo[n]!=-1)
    return memo[n];
    int maxPro;
    for(int i=1;i<=n;i++){
        maxPro=max(maxPro,price[i]+topDownRodcut(price,n-i-1));
    }
    memo[n]=maxPro;
    return maxPro;
}
int bottomUpRodcut(int price[],int n){
    if(n==0)
    return 0;
    vector<int>memo;
    for(int i=1;i<=n;i++){
        int maxPro=INT_MIN;
        for(int j=0;j<i;j++){
            maxPro=max(maxPro,price[j]+bottomUpRodcut(price,n-j-1));
        }
        memo[i]=maxPro;
    }
    return memo[n];
}
vector<vector<int>>memory;
int knapsack(int C,vector<int>wt,vector<int>val,int n){
    if(memory[n][C]!=-1){
        return memory[n][C];
    }
    if(n==0|C==0){
        return 0;
    }
    if(C<wt[n-1])
    memory[n][C]= knapsack(C,wt,val,n-1);
    else{
        memory[n][C]=max(val[n-1]+knapsack(C-wt[n-1],wt,val,n-1),knapsack(C,wt,val,n-1));
    }
    return memory[n][C];
}
int nthUgly(int n){
    vector<int> ugly;
    ugly[0]=1;
    int i2=0,i3=0,i5=0;
    for(int i=1;i<n;i++){
        int next=min(ugly[i2]*2,ugly[i3]*3,ugly[i5]*5);
        if(next==ugly[i2]*2) i2++;
        if(next==ugly[i3]*3) i3++;
        if(next==ugly[i5]*5) i5++;
    }
    return ugly[n-1];
}
int coinChange(vector<int>&coins,int amount,vector<int>&memo){
    if(amount==0) return 0;
    if(amount<0) return -1;
    if(memo[amount]!=-2){
        return memo[amount];
    }
    int res=INT_MAX;
    for(int coin:coins){
        int sub=coinChange(coins,amount-coin,memo);
        if(sub!=-1){
            res=min(res,sub+1);
        }
    }
    return memo[amount]=(res==INT_MAX? -1:res);
}
string commonPrefix(string str1,string str2){
    int minLen=min(str1.size(),str2.size());
    for(int i=0;i<minLen;i++){
        if(str1[i]!=str2[i]){
            return str1.substr(0,i);
        }
    }
    return str1.substr(0,minLen);
}
string longestCommon(vector<string>&strs,int l,int r){
    if(l==r){
        return strs[l];
    }
    int mid=(l+r)/2;
    string leftPrefix=longestCommon(strs,l,mid);
    string rightPrefix=longestCommon(strs,mid+1,r);
    return commonPrefix(leftPrefix,rightPrefix);
}
string findLCP(vector<string>strs){
    if(strs.empty()) return "";
    return longestCommon(strs,0,strs.size());
}
int main(){
    vector<string> input1 = {"bats", "battle", "batch"};
    vector<string> input2 = {"though", "bought", "nought"};
    cout << "LCP (input1): " << findLCP(input1) << endl;  // Output: "bat"
    cout << "LCP (input2): " << findLCP(input2) << endl;  // Output: ""
    //int price[]={10,6,4,12,3};
    //cout<<"the maximum price is: "<<topDownRodcut(price,sizeof(price));
    return 0;
}