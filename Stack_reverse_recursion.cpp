#include <bits/stdc++.h>
using namespace std;

stack <int> s;

void make(int a){
    if(s.empty()){
        s.push(a);
    }
    else{
        int x = s.top();
        s.pop();
        make(a);
        s.push(x);
    }
}

void reverse(){
    if(!s.empty()){
        int a = s.top();
        s.pop();
        reverse();
        make(a);
    }
}

int main() {
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reverse();
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	return 0;
}
