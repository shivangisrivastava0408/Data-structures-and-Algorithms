#include <bits/stdc++.h>
using namespace std;

void compute(string txt, int Z[]){
    int n=txt.length();
    int L,R,k;
    L=R=0;
    for(int i=1;i<n;i++){
        if(i>R){
            L=R=i;
            while(R<n && txt[R-L]==txt[R])
                R++;
            Z[i]=R-L;
            R--;
        }
        else{
            k=i-L;
            if(Z[k]<R-i+1)
                Z[i]=Z[k];
            else{
                L=i;
                while(R<n && txt[R-L]==txt[R])
                    R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
}

int main() {
	string text,pattern;
	cin>>text;
	cin>>pattern;
	string txt;
	txt=pattern+"$"+text;
	int n=txt.length();
	int Z[n];
	compute(txt, Z);
	for(int i=0;i<n;i++){
	    if(Z[i]==pattern.length())
	       cout<<"Pattern occurs at "<<i-pattern.length()-1<<endl;
	}
	return 0;
}
