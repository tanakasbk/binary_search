#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int i, work = 0, cnt = 0;
printf("最大労働量%dでは、", x);//debug
    for(i = 0; i < n; i++){
        work += A[i];
        if(work > x){
          ++cnt;
          work = A[i];
        }
printf("%d時間目までに%d人必要\n", i+1, cnt);//debug
    }
    ++cnt;
printf("結果%d人必要\n", cnt);
    return cnt <= k;
}


int main(){
    int i, lb, ub, workSum = 0, workMax = 0;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        workSum += A[i];
        if(A[i] > workMax)workMax = A[i];
    }
    
    lb = workMax - 1;
    ub = workSum + 1;
    while(ub - lb > 1){
printf("%d〜%d\n", lb, ub);
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
