#include<bits/stdc++.h>
using namespace std;
vector<int> getDigits(int n){
    vector<int> ans;
    while(n>0){
        if(n%10 != 0){
            ans.push_back(n%10);
        }
        n/=10;
    }
    return ans;
}
int f(int n){
    if(n==0){
        return 0;
    }
    if(n<=9){
        return 1;
    }
    vector<int> v = getDigits(n);
    int a = INT_MAX;
    for(int i = 0;i<v.size();i++){
        a = min(a,f(n-v[i]));
    }
    return 1+a;

}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}