#include <stdio.h>
#define SIZE 5
void primeiroTriangulo();
void segundoTriangulo();
void terceiroTriangulo();
void quartoTriangulo();

int main(void) {
  primeiroTriangulo();
  printf("\n");
  segundoTriangulo();
  printf("\n");
  terceiroTriangulo();
  printf("\n");
  quartoTriangulo();
  return 0;
}
void primeiroTriangulo(){
  int i, j;
  for (i = SIZE; i > 0; i--) {
    for (j = 0; j > i; j++) {
      printf("\n");
    }
    printf("*");
  }
}
void segundoTriangulo() {
  int i, j;
  for (i = SIZE; i > 0; i--) {
    for (j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
}
void terceiroTriangulo() {
  int i, j;
  for (i = 1; i <= SIZE; i++) {
    for (j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void quartoTriangulo(){
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
        if(j > i){
            printf("*");
        }else{
            printf(" ");
        }
    }
    printf("\n");
  }
}
