#include <stdio.h>
float abs(float x);

int main(void){
    printf("%.2f", abs(-30.00));
}

float abs(float x){
    if(x<0) 
        x = (-1) * x;
    return x;
}