#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 10

void start();
void read(int row ,int col,float arr[max][max]);
void display(float arr[max][max],int row);
void addAndSub(float arr1[max][max],float arr2[max][max],int row,int col,char sign);
void multi(float arr1[max][max],float arr2[max][max],int row1,int row2,int col2);
void transpose(float arr[max][max],int row ,int col);
float determinate(float arr[max][max],int row);
void inverse(float arr[max][max],int row);
void scalarproduct(float arr[max][max],int row,int col);



#endif // MATRIX_H_INCLUDED
