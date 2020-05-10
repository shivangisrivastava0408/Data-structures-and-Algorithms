#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void fun(string s){
    stack <char> st;
    st.push('N');
    for(int i = 0; i < s.length(); i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) cout << s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(st.top() != 'N' && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else{
                while(st.top() != 'N' && prec(st.top()) >= prec(s[i])){
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
        }
    }
    while(st.top() != 'N'){
        cout << st.top();
        st.pop();
    }
}

int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	fun(exp);
	return 0;
}
