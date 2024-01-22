#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
scanf("%d", &matrix[i][j]);
}
}
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d\t", matrix[i][j]);
}
printf("\n");
}
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
result[i][j] = matrix1[i][j] + matrix2[i][j];
}
}
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int matrix2[MAX_SIZE][MAX_SIZE], int cols2, int result[MAX_SIZE][MAX_SIZE]) {
for (int i = 0; i < rows1; i++) {
for (int j = 0; j < cols2; j++) {
result[i][j] = 0;
for (int k = 0; k < cols1; k++) {
result[i][j] += matrix1[i][k] * matrix2[k][j];
}
}
}
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
result[j][i] = matrix[i][j];
}
}
}

int main() {
int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
int rows1, cols1, rows2, cols2;

printf("Enter the number of rows and columns for matrix 1: ");
scanf("%d %d", &rows1, &cols1);
printf("Enter the number of rows and columns for matrix 2: ");
scanf("%d %d", &rows2, &cols2);
if (rows1 != rows2||cols1 != cols2) {
printf("Matrix addition and multiplication are not possible due to size mismatch.\n");
return 1;
}

printf("enter the matrix1 elements");
inputMatrix(matrix1, rows1, cols1);

printf("enter the matrix2 elements");
inputMatrix(matrix2, rows2, cols2);
int transposeResult[MAX_SIZE][MAX_SIZE];
int ch;
do
{
printf("\n 1)addition \n 2) multiplication \n 3)transpose \n exit \n");
printf("\n enter the choise");
scanf("%d",&ch);
switch(ch)
{
case 1:
addMatrices(matrix1, matrix2, result, rows1, cols1);
printf("\nMatrix Addition:\n");
displayMatrix(result, rows1, cols1);
break;
case 2:
multiplyMatrices(matrix1, rows1, cols1, matrix2, cols2, result);
printf("\nMatrix Multiplication:\n");
displayMatrix(result, rows1, cols2);
break;
case 3:

transposeMatrix(matrix1, rows1, cols1, transposeResult);
printf("\nTranspose of Matrix 1:\n");
displayMatrix(transposeResult, cols1, rows1);
break;
case 4:exit(0);
break;
default:printf("wrong input");
}
}while(1);
return 0;
}
