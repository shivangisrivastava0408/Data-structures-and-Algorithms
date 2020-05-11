#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <char> st;
    string s="[()]{}{[()()]()";
    int flag=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()=='(') st.pop();
            else {
                cout<<"Invalid";
                flag=1;
                break;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{') st.pop();
            else {
                cout<<"Invalid";
                flag=1;
                break;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='[') st.pop();
            else {
                cout<<"Invalid";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        if(st.empty()){
           cout<<"Valid";
        }
        else cout<<"Invalid";
    }
    
    
    return 0;
    
}
