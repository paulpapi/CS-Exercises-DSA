#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
struct Items{
    double value;
    double weight;
};
bool compare(Items A,Items B){
    return (A.value/A.weight)>(B.value/B.weight);
}
double fractionalKnapsack(int W,vector<Items>Item){
    sort(Item.begin(),Item.end(),compare);
    double totalValue=0.0;
    for(const Items items:Item){
        if(W==0) break;
        if(items.weight<W){
            totalValue=
        }
    }
}
int main(){

    return 0;
}