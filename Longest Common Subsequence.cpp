//WAP to implement longest common subsequence:
#include<bits/stdc++.h> 
using namespace std;
int max(int a, int b){
    return ((a>b)?a:b); }
int LCS(char *X, char *Y, int m, int n){
    int L[m+1][n+1];
    char A[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0){
                L[i][j]=0; }
            else if(X[i-1]==Y[j-1]){
                L[i][j]=L[i-1][j-1]+1;
                A[i][j]= '\\';  }
            else{
                L[i][j]=max(L[i-1][j], L[i][j-1]);
                if (L[i][j]==L[i-1][j]) 
                    A[i][j]= '|';
                else 
                    A[i][j]= '-'; }}
    }
    int index = L[m][n];
    char lcs[index+1];
    lcs[index]='\0';
    i=m;
    j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index-1]=X[i-1];
            i--;
            j--;
            index--; }
        else if(L[i-1][j]>L[i][j-1])
            i--;
        else
            j--; }
    cout<<"The length of LCS is "<<L[m][n]<<endl;
    cout<<"The longest common subsequence is "<<lcs<<endl;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl; }}
int main(){
    char X[]="ABBAABA";
    char Y[]="BBABA";
    int m=strlen(X);
    int n=strlen(Y);
    clock_t t;
    t=clock();
    LCS(X, Y, m, n);
    t=clock()-t;
    cout<<"The time taken is "<<(double(t))/CLOCKS_PER_SEC;
    return 0;
}
