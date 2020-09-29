#include <bits/stdc++.h>
using namespace std;

#define d 256

void rabin(string txt,string pat,int q){
    int N=txt.length();
    int M=pat.length();
    int t=0;
    int p=0;
    int h=1;
    int i,j;
    for(i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<M;i++){
        t=(t*d+txt[i])%q;
        p=(p*d+pat[i])%q;
    }
    for(i=0;i<=(N-M);i++){
        if(t==p){
            for(j=0;j<M;j++){
                if(pat[j]!=txt[i+j]){
                    break;
                }
            }
            if(j==M)
                cout<<"Found at index "<<i<<endl;
        }
        if(i<N-M){
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if(t<0)
                t=t+q;
        }
    }
}

int main() {
	string text;
	string pattern;
	getline(cin,text);
	getline(cin,pattern);
	rabin(text,pattern,101);
	return 0;
}
