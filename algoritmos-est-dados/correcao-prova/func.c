#include <stdio.h>

int Func(int, int);

int main(void){
    int n1, n2, r;

    scanf("\n%d", &n1);
    scanf("\n%d", &n2);

    r = Func(n1, n2);
    printf("%d", r);

    return 0;
}

int Func(int n1, int n2){
    if(n1 > n2)
        return (n1 * n2);
    else{
        if(n1 == n2)
            return n1 + n2;
        else
            return (n1 - n2);
    }
}