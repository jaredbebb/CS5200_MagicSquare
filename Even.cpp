//
//  DoublySinglyEvenSquare.cpp
//  CS5200_MagicSquare
//
//  Created by Jared Bebb on 3/20/17./Users/jaredbebb/Documents/MST/CS5200/Code/CS5200HW6/CS5200_MagicSquare
//  Copyright © 2017 Jared Bebb LLC. All rights reserved.
//

#include "Even.hpp"
#include <iostream>

void Even::print(int n){
    std::cout << "Print Magic Squares Board" << std::endl <<std::endl;
    int magicSquares[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            magicSquares[i][j] = j;
            std::cout << magicSquares[i][j]  << "  ";
        }
        std::cout << std::endl;
    }
}
int ** Even::setZero(int n){
    int** magicSquare = 0;
    magicSquare = new int*[n];
    for(int i=0; i<n; i++)
    {
        magicSquare[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            magicSquare[i][j] = 0;
        }
    }
    return magicSquare;
}
void Even::doublyEven(int n){
    magic = setZero(n);
    int sqrNum = n/4;
    int count = 1;
    int invCnt = n*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=sqrNum && j<n-sqrNum){
                if(i>=sqrNum && i<n-sqrNum)
                    magic[i][j] = count;
                else
                    magic[i][j] = invCnt;
            }
            else if(i<sqrNum || i>=n-sqrNum){
                magic[i][j]=count;
            }
            else
                magic[i][j] = invCnt;
            count++;
            invCnt--;
        }
    }
    std::cout << "Doubly Even Magic Square"<< std::endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%3d ", magic[i][j]);
        printf("\n");
    }
}
void Even::singlyEven(int n){
    int** magicSquare = 0;
    magicSquare = new int*[n];
    int halfN = n/2;
    int k = (n-2)/4;
    int temp;
    int swapCol [n];
    int index=0;
    int  miniMagic [halfN][halfN];
    int N = halfN*halfN;
    int row = N-1;
    int col = N/2;
    magic[row][col] = 1;
    for(int i = 2; i<=N*N; i++){
        if(magic[(row+1)%N][(col+1)%N]== 0){
            row = (row+1)%N;
            col = (col+1)%N;
        }else{
            row = (row-1+N)%N;
        }
        magic[row][col] = i;
    }
    for (int i=0; i<halfN; i++)
    	   for (int j=0; j<halfN; j++){
               magicSquare[i][j] = miniMagic[i][j];
               magicSquare[i+halfN][j+halfN] = miniMagic[i][j]+halfN*halfN;
               magicSquare[i][j+halfN] = miniMagic[i][j]+2*halfN*halfN;
               magicSquare[i+halfN][j] = miniMagic[i][j]+3*halfN*halfN;
           }
    for (int i=1; i<=k; i++)
        swapCol[index++] = i;
    for (int i=n-k+2; i<=n; i++)
        swapCol[index++] = i;
    for (int i=1; i<=halfN; i++)
        for (int j=1; j<=index; j++){
            temp=magicSquare[i-1][swapCol[j-1]-1];
            magicSquare[i-1][swapCol[j-1]-1]=magicSquare[i+halfN-1][swapCol[j-1]-1];
            magicSquare[i+halfN-1][swapCol[j-1]-1]=temp;
        }
    temp=magicSquare[k][0];
    magicSquare[k][0]=magicSquare[k+halfN][0];
    magicSquare[k+halfN][0]=temp;
    temp=magicSquare[k+halfN][k];
    magicSquare[k+halfN][k]=magicSquare[k][k];
    magicSquare[k][k]=temp;
    std::cout << "Doubly Even Magic Square"<< std::endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

