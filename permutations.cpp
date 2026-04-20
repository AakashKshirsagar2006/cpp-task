#include<iostream>
#include<unordered_set>
using namespace std;

void permutations(string inp , string op){
    if(inp.size() == 0){
        cout<<op<<endl;
        return;
    }
    for(int i = 0;i<inp.size() ; i++){
        char ch = inp[i];
        string left = inp.substr(0,i);
        string right = inp.substr(i+1);
        string ros = left + right;
        permutations(ros , op + ch);
    }
}
void permutationsOp(string &inp , int idx){
    if(idx == inp.size() - 1){
        cout<<inp<<endl;
        return;
    }
    unordered_set<int> st;
    for(int i = idx;i<inp.size() ; i++){
        if(st.count(inp[i])) continue; // ye pruning step hai
        st.insert(inp[i]);
        swap(inp[idx] , inp[i]);
        permutationsOp(inp , idx + 1);
        swap(inp[idx] , inp[i]); // ye backtracking step hai
    }
}
void generateSubsets(string &inp, int idx, string currentPath) {
    // Base Case: We have made a "Pick/Don't Pick" decision for every single character
    if (idx == inp.size()) {
        cout << "[" << currentPath << "]" << endl;
        return;
    }

    // CHOICE 1: DON'T PICK the current character
    // We move to the next index without adding anything to our path
    generateSubsets(inp, idx + 1, currentPath);

    // CHOICE 2: PICK the current character
    // We add the character to our path and move to the next index
    generateSubsets(inp, idx + 1, currentPath + inp[idx]);
}
int main(){
    string a = "baa";
    permutationsOp(a , 0);
    cout<<endl;
    generateSubsets(a, 0, "");
    return 0;
}