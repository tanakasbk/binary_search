#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int i, result = 0;
    for(i = 0; i < n; i++){
        result += A[i] / x;
    }
    return result < k;
}


int main(){
    int i, lb, ub;
    long woodSum = 0;;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        woodSum += A[i];
    }
    
    lb = 0;
    ub = woodSum / k + 1;
    while(ub - lb > 1){
        int m = (lb + ub) / 2;
        if(p(m)){
            ub = m;
        }
        else{
            lb = m;
        }
    }
    
    printf("%d\n",lb);
    
    
    return 0;
}
