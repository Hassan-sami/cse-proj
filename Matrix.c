#include "Matrix.h"

float arr1[max][max], arr2[max][max],inv[max][max];
void start(){
    int row1,row2,col1,col2;
    unsigned  choice = 0;
    unsigned  cont= 0;
    do{
        printf("enter the first matrix rows and cols\n");
        scanf("%d%d",&row1,&col1);
        if(row1>0&&col1>0){
            printf("fill the first matrix\n");
            read(row1,col1,arr1);
        }
        else{
            printf("the number of rows and cols");
            printf(" must be more than 0\n");
            printf("do you want continue 1/0 \n");
            scanf("%u",&cont);
            continue;
        }
        printf("enter the second matrix rows and cols\n");
        scanf("%d%d",&row2,&col2);
        if(row2>0&&col2>0){
            printf("fill the second matrix\n");
            read(row2,col2,arr2);
        }
        else{
            printf("the number of rows and cols");
            printf(" must be more than 0\n");
            printf("do you want continue 1/0 \n");
            scanf("%u",&cont);
            continue;
        }
        printf("for add enter 1 for sub 2 for multi 3");
        printf(" for det 4 for trans 5  for inverse 6\n");
        printf("for scalar 7 for division 8\n");
        scanf("%u",&choice);
        if(choice== 1){
                if((row1==row2)&&(col1==col2)){
                        addAndSub(arr1,arr2,col1,col2,'+');

                }else{
                    printf("the matrices must have the same order\n");
                }

        }
        else if(choice== 2){
                if((row1==row2)&&(col1==col2)){
                        addAndSub(arr1,arr2,col1,col2,'-');

                }else{
                    printf("the matrices must have the same order\n");
                }


        }
        else if(choice== 3){
                if(col1==row2){
                        multi(arr1,arr2,row1,row2,col2);

                }

                else{
                    printf("error, to multiply the col of matrix 1");
                    printf(" must equal the row of matrix 2\n");
                }

        }
        else if(choice == 4){
            short arrNo=0;
            printf("do you want determinate for");
            printf(" matrix 1 or2\n");
            scanf("%hd",&arrNo);
            if(arrNo==1){
                if(row1==col1){
                        printf("%.3f\n",determinate(arr1,row1));

                }
                else{
                    printf("error,the rows of");
                    printf(" the matrix must equal the rows ");
                    printf("to find the determinate\n");
                }
            }
            else if(arrNo==2){
                if(row2==col2){
                        printf("%.3f\n",determinate(arr2,row2));

                }
                else{
                    printf("error,the rows of");
                    printf(" the matrix must equal the rows ");
                    printf("to find the determinate\n");
                }

            }
            else{
                printf("select between 1 and 2\n");
            }

        }
        else if(choice == 5){
            short arrNo=0;
            printf("do you want transpose for matrix 1 or 2\n");
            scanf("%hd",&arrNo);
            if(arrNo==1){
                transpose(arr1,row1,col1);
            }
            else if(arrNo==2){
                transpose(arr2,row2,col2);
            }
            else{
                printf("select between 1 and 2");
            }


        }
        else if(choice==6){
            short arrNo=0;
            printf("do you want inverse for matrix 1 or 2\n");
            scanf("%hd",&arrNo);
            if(arrNo==1){
                if(row1==col1){
                   if(determinate(arr1,row1)==0){
                        printf("the determinate equal zero");
                        printf(" so the inverse can not found\n");
                   }
                   else{
                    inverse(arr1,row1);
                    display(inv,row1);
                   }
                }
                else{
                    printf("error,the rows of");
                    printf(" the matrix must equal the rows ");
                    printf("to find the inverse\n");
               }
            }
            else if(arrNo==2){
                if(row2==col2){
                   if(determinate(arr2,row2)==0){
                        printf("the determinate equal zero");
                        printf(" so the inverse can not found\n");
                   }
                   else{
                    inverse(arr2,row2);
                    display(inv,row2);
                   }
                }
                else{
                    printf("error,the rows of");
                    printf(" the matrix must equal the rows ");
                    printf("to find the inverse\n");

                }

            }
            else{
                printf("select between 1 and 2");
            }
        }
        else if(choice ==7){
           short arrNo=0;
           printf("do you want the scalar prod for marix 1 or 2\n");
           scanf("%hd",&arrNo);
           if(arrNo==1){
                scalarproduct(arr1,row1,col1);
           }
           else if(arrNo==2){
               scalarproduct(arr2,row2,col2);
           }
           else{
                printf("select between 1 or 2\n");
           }
        }
        else if(choice==8){
            short type=0.0;
            printf("for (mat1)/(mat2) enter 1 for (mat2)/(mat1)");
            printf(" enter 2\n");
            scanf("%hd",&type);
            if(type==1){
                if((row2==col2)&&(col1==row2)&&(determinate(arr2,row2)!=0)){
                    inverse(arr2,row2);
                    multi(arr1,inv,row1,row2,col2);


                }
                else{
                    printf("error\n");
                }
            }
            else if(type==2){
                if((row1==col1)&&(col2==row1)&&(determinate(arr1,row1)!=0)){
                    inverse(arr1,row1);
                    multi(arr2,inv,row2,row1,col1);
                }
                else{
                    printf("error\n");
                }
            }
            else{
                printf("select between 1 or 2\n");
            }
        }

        else{
            printf("please,enter a number from 1 to 6 \n");
        }
        printf("do you want continue 1/0 \n");
        scanf("%u",&cont);


    }while(cont == 1);


}
void read(int row, int col,float arr[max][max]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%f",&arr[i][j]);
        }
    }

}

void display(float arr[max][max],int row){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            printf("%f\t\t",inv[i][j]);
        }
        printf("\n");
    }
}

void addAndSub(float arr1[max][max],float arr2[max][max],int row,int col,char sign){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
              if(sign =='+')
                printf("%.3f\t",arr1[i][j]+ arr2[i][j]);
              else if(sign == '-')
                printf("%.3f\t",arr1[i][j] - arr2[i][j]);
        }
        puts("\n");
    }



}
void multi(float arr1[max][max],float arr2[max][max],int row1,int row2,int col2){

    int i,j,k;
    float prod=0.0;
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            for(k=0;k<row2;k++){
                prod += arr1[i][k]*arr2[k][j];
            }
            printf("%.3f\t",prod);
            prod = 0;
        }
        puts("\n");
    }

}
void transpose(float arr[max][max],int row ,int col){
    int i,j;
    float TransMatrix[col][row];
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            TransMatrix[i][j]= arr[j][i];
            printf("%.3f\t",TransMatrix[i][j]);
        }
        puts("\n");
    }

}

float determinate(float arr[max][max],int row ){
    int i,j,k,m;
    m=0;
    float value=0.0;
    float det=1.0;
    float mat[row][row];
    float sumRow=0.0;
    float sumcol=0.0;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            mat[i][j]=arr[i][j];
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            sumRow +=mat[i][j];
            sumcol +=mat[j][i];
        }
        if(sumRow==0||sumcol==0){
            return 0.0;
        }
        else{
            sumRow=0;
            sumcol=0;
        }
    }
    for(i=0;i<row;i++){
        if(mat[i][i]==0.0){
            for(j=0;j<row;j++){
                if(mat[j][i] != 0){
                    for(k=0;k<row;k++){
                        mat[i][k] += mat[j][k];
                    }
                    break;
                }
            }
        }
    }
    for(k=0;k<(row -1);k++){
        for(i=0;i<(row-(k+1));i++){
            value = mat[row-(i+1)][k]/(1.0*mat[k][k]);
            for(j=0;j<(row);j++){
                    mat[row-(i+1)][j]=-value*mat[m][j]+mat[row-(i+1)][j];

            }

        }
        m+=1;

    }

    for(i=0;i<row;i++){
        det *= mat[i][i];
    }

    return det;

}




void inverse(float arr[max][max],int row){
    int i,j,k,m;
    m=0;
    float value=0.0;
    float unit[row][row];
    float mat[row][row];
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            mat[i][j]=arr[i][j];
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            if(i==j){
                unit[i][i]=1.0;
            }
            else{
                unit[i][j]=0.0;
            }
        }
    }
    for(i=0;i<row;i++){
        if(mat[i][i]==0.0){
            for(j=0;j<row;j++){
                if(mat[j][i] != 0){
                    for(k=0;k<row;k++){
                        mat[i][k] += mat[j][k];
                        unit[i][k] += unit[j][k];

                    }
                    break;
                }
            }
        }
    }
    for(k=0;k<(row -1);k++){
        for(i=0;i<(row-(k+1));i++){
            value = mat[row-(i+1)][k]/(1.0*mat[k][k]);
            for(j=0;j<(row);j++){
                    mat[row-(i+1)][j]=-value*mat[m][j]+mat[row-(i+1)][j];
                    unit[row-(i+1)][j]=-value*unit[m][j]+unit[row-(i+1)][j];


            }

        }
        m+=1;

    }
    m=row-1;
    for(k=(row-1);k>0;k--){
        for(i=0;i<k;i++){
            value= mat[i][k]/(1.0*mat[k][k]);
            for(j=0;j<row;j++){
                mat[i][j]=-value*mat[m][j]+ mat[i][j];
                unit[i][j]=-value*unit[m][j]+ unit[i][j];


            }
        }
        m-=1;

    }
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            unit[i][j]/=mat[i][i];
            inv[i][j]=unit[i][j];
        }
    }


}


void scalarproduct(float arr[max][max],int row,int col){
    float num=0.0;
    int i,j;
    printf("enter the number for the product\n");
    scanf("%f",&num);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            arr[i][j]*=num;
            printf("%.3f\t\t",arr[i][j]);
        }
        puts("\n");
    }
}










