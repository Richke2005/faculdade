#include <stdio.h>
int mmcFunc(int n1, int n2);

int main(void){
    int n1, n2;
    printf("digite 2 numeros para calcular o mmc:\n");
    scanf("%d %d", &n1, &n2);
    printf("O MMC de %d e %d = %d", n1, n2, mmcFunc(n1, n2));
    return 0;
}

int mmcFunc(int n1, int n2){
    int mmc = 1, div = 2;
    while(n1 + n2 > (n1/n1 + n2/n2)){
        //verificar se são divisiveis igualmente
        if(n1 % div == 0 && n2 % div == 0){
            n1 = n1 / div;
            n2 = n2 / div;
            mmc *= div;
        
        }else if(n1 % div == 0 || n2 % div == 0){
            //se não forem verificar qual é divisivel e efetuar conta
            if(n1 % div == 0){
                n1 = n1 / div;
                mmc *= div;
            }else{
                n2 = n2 / div;
                mmc *= div;
            }
            //usabilidade anterior
            // if(n2 % div == 0){
            //     n2 = n2 / div;
            //     mmc *= div;
            // }
        }else{
            div++;
        }
    }
    return mmc;
}