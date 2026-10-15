#include <stdio.h>
#include <stdlib.h>

int main()
//metade de cima
{printf("insira a metade da altura do losango");
int n;
scanf("%i",&n);
 int num;
 for(num=1;num<=n;num++){ for(int espaco=1; espaco<=n-num; espaco++){
    printf(" ");
 }
    for(int j=1; j<=2*num-1;j++){
        printf("*");
    }
    printf("\n");
 }
for(num=n-1;num>=1;num--){
        for(int espaco=1;espaco<=n-num; espaco++){printf(" ");}
    for(int j=1;j<=2*num-1;j++ ){
        printf("*");
    }
printf("\n");


 }


    return 0;
}
