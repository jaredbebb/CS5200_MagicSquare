//
//  DoublySinglyEvenSquare.hpp
//  CS5200_MagicSquare
//
//  Created by Jared Bebb on 3/20/17.
//  Copyright © 2017 Jared Bebb LLC. All rights reserved.
//

#ifndef DoublySinglyEvenSquare_hpp
#define DoublySinglyEvenSquare_hpp

#include <stdio.h>

class Even{
public:
    int** magic;    
    int ** setZero(int n);
    void doublyEven(int n);
    void singlyEven(int n);
    
    void print(int n);
    
    
    Even(){};
    ~Even(){};
};

#endif /* DoublySinglyEvenSquare_hpp */
