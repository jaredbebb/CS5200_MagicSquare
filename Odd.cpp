//
//  MS.cpp
//  CS5200_MagicSquare
//
//  Created by Jared Bebb on 3/18/17.
//  Copyright © 2017 Jared Bebb LLC. All rights reserved.
//
#include <iostream>
#include <vector>
#include "Odd.hpp"

void Odd::oddSquare(int n)
{
    int** magicSquare =setZero(n);
    int i = n/2;
    int j = n-1;
    for (int num=1; num <= n*n; )
    {
        if (i==-1 && j==n)
        {
            j = n-2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
 
            if (i < 0)
                i=n-1;
        }
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;
        j++;  i--;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}
int ** Odd::setZero(int n){
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



