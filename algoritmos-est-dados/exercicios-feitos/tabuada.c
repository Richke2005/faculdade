#include <stdio.h>

int main(void) {
    int tab;
    printf("Digite o numero x da tabuada: ");
    scanf("%d", &tab);
    int i;
    for(i = 1; i <= 10; i++){
        printf("%d X %d = %d\n", tab, i, tab * i);
    }

    return 0;
}