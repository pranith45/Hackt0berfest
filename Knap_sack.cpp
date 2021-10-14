#include <bits/stdc++.h>
using namespace std;
 int knapsack(int w,int i, vector<int> weights, vector<int> values, vector<vector<int>>dp){
     //base condition
     if(w==0 || i==wights.length()-1){
         return 0;
     }
     if(dp[i][w]!=-1){
         return dp[i][w];
     }
     else{
    //  case-1: If weight of the element is lessthan w , now i will be having tw0 possibilites weather i can pick the element or i can skip the elemnt, so i will be choosing according to the max return value
        if(weights[n]<w){
            dp[i][w]=return (values[n]+knapsack(w-weights[n],i+1,weights,values))>(knapsack(w,i+1,weights,values))?(values[n]+knapsack(w-weights[n],n+1,weights,values)):(knapsack(w,n+1,weights,values));

        }
    // case-2: If weight of the element is greaterthan w, in this case we are left with only one case ,i.e skip the element and proceed further
        else{
            dp[i][w]=return (knapsack(w,i+1,weights,values));
        }
     }
 }
 int main(){
     int n,w;
     cout<<"Enter n : "<<endl;
     cin>>n;
     cout<<"Enter w : "<<endl;
     cin>>w;
     vector<int>weights(n),values(n);
     vector<vector<int>(n+1)>dp(n+1);
     for (int i = 0; i < n+1; i++)
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
     cout<<"Enter the values array in one row with a space between : "<<endl;
     for(int i=0;i<n;i++){
         cin>>values[i];
     }
     cout<<"Enter the weights array in one row with a space between : "<<endl;
     for(int i=0;i<n;i++){
         cin>>weights[i];
     }
     cout<<knapsack(w,0,weights,values)<<endl;
     return 0;
 }
