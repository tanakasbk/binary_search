#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int i, result = 0;
    for(i = 0; i < n; i++){
        result += (A[i] + x - 1) / x;
    }
    return result <= k;
}


int main(){
    int i, lb, ub, maxApple = 0;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if(A[i] > maxApple)maxApple = A[i];
    }
    
    lb = 0;
    ub = maxApple;
    while(ub - lb > 1){
        int m = (lb + ub) / 2;
        if(p(m)){
            ub = m;
        }
        else{
            lb = m;
        }
    }
    
    printf("%d\n",ub);
    
    
    return 0;
}
