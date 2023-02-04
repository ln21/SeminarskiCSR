#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 500000
void create(int m, int n, int mat[m][n], int procenat_min, int procenat_max) {
    srand(time(NULL));
    int brNula = 0;
    int sveuk = m * n;
    int kraj = sveuk * (procenat_min / 100.0);
    int maxNula = sveuk * (procenat_max / 100.0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int random = rand() % 2;
            if (random == 0 && brNula < maxNula) {
                mat[i][j] = 0;
                brNula++;
            } else {
                mat[i][j] = 1;
            }
        }
    }

    while (brNula < kraj) {
        int k = rand() % m;
        int l = rand() % n;
        if (mat[k][l] != 0) {
            mat[k][l] = 0;
            brNula++;
        }
    }
}

void transformToCSR(int m, int n, int mat[m][n], int A[], int IA[], int JA[]) {

    int br = 0;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (mat[i][j] == 1) {

                A[br] = mat[i][j];
                IA[br] = i;
                JA[br] = j;

                br++;
            }
        }
    }
    printf("Niz A:[ ");
    for (int i = 0; i < br; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");

    printf("Niz IA:[ ");
    for (int i = 0; i < br; i++) {
        printf("%d ", IA[i]);
    }
    printf("\n");

    printf("Niz JA:[ ");
    for (int i = 0; i < br; i++) {
        printf("%d ", JA[i]);
    }
    printf("\n");

}

void sum(int m, int n, int A[m][n], int B[m][n], int C[m][n]){

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                C[i][j] = A[i][j] + B[i][j];
                printf("%d\t", C[i][j]);
            }
        printf("\n");
        }
    }

void product(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]){
    printf("\nProizvod matrice A i matrice B je:\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                C[i][j]=0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }

}


int main() {


    int m = 50, n = 50;
    int matrixA[m][n];
    int procenat_min = 90, procenat_max = 98;
    create(m, n, matrixA, procenat_min, procenat_max);
    for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", matrixA[i][j]);
    }
    printf("\n");
}
    int A[m*n];
    int IA[m*n];
    int JA[m*n];
    transformToCSR(m, n, matrixA, A, IA, JA);
    printf("\n");
    int matrixB[m][n];
    int procenatmin2 = 90, procenatmax2 = 98;
    create(m, n, matrixB, procenatmin2, procenatmax2);
    for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", matrixB[i][j]);
    }
    printf("\n");
}
    int B[m*n];
    int IB[m*n];
    int JB[m*n];
    transformToCSR(m, n, matrixB, B, IB, JB);
    printf("\n");
    int C[m][n];
    clock_t start=clock();
    printf("\n Suma A i B je:\n");
    sum(m,n,matrixA,matrixB,C);
    clock_t end=clock();
    float vrSum=(float)(end-start)/CLOCKS_PER_SEC;
    int p=n;
    printf("Vrijeme za izvrsenje sum funkcije: %g s\n", vrSum);
    clock_t prvi=clock();
    product(m,n,p,matrixA,matrixB,C);
    clock_t zadnji=clock();
    float vrProduct=(float)(zadnji-prvi)/CLOCKS_PER_SEC;
    printf("Vrijeme za izvrsenje product funkcije: %g s\n", vrProduct);

return 0;
}
