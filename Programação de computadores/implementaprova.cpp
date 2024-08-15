#include <stdlib.h>
#include <stdio.h>


/*prototipo*/
float fa(float, int);
int func(int*, int);
int f(int, int);
void troca(float, float);

/* numero 1  */
float fa(float A[4][4], int N) {
    int i, j;
    float t=0;
    for (i=0; i<N; i++) {
        for (j=i+1; j<N; j++){
            if (j!=i)
                t=t+A[i][j];
        }
    }
    return t;
} 

/*numero 2*/

int func(int*a, int b) {
    *a = b + 2; 
    b = b * 3; 
    return b; 
}

int main() { 
    int a = 10, b = 6, y = 2, N=4; 
    float X=3, Y=5, A[N][N]={{2,2,2,2},
                            {2,2,2,2},
                            {2,2,2,2},
                            {2,2,2,2}};
    printf("t=%f", fa(A, N));
    /*numero 2*/
    y=func(&a, b); 
    printf("a=%d, b=%d y=%d \n", a, b, y);
    /*numero 6*/
    troca(X,Y);
    printf("X=%f Y=%f", X, Y);
    return 0; 
} 

/*numero 4*/

int f(int x,int v[]){
    if (x==0) return 0;
    return v[x-1]+ f(x-1, v);
}

/*NUMERO 6*/
void troca(float A, float B) {
    float aux;
    aux=A;
    A=B;
    B=aux;
    A++;
    B--;
}
