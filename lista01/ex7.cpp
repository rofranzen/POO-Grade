
#include <iostream>
#include <stdio.h>

using namespace std;

int seq(int n, int k, int *ini){
    int soma = 0;
    int resp[n+1];
    int fim;
    
    if (n >= k){
        for(int i = 0; i<k;i++){
            resp[i] = ini[i];}

        
        for(int i = k; i <= n; i++){
            soma = 0;
            for(int j =i-k; j<i; j++){
                soma = soma + (resp[j]*resp[j]);
            }
            resp[i] = soma;
        }
        fim = resp[n];
        return fim;
    }
    else{
        soma = ini[n];
    }
    return soma;
}



int main()
{
    int a, b;

    cin >>a >> b;
    int t[a];
    for(int i = 0; i<b;i++){
        cin>>t[i];}
    
    cout << seq(a,b,t) << endl;
    return 0;
}
