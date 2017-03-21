//
//  SquareController.cpp
//  CS5200_MagicSquare
//
//  Created by Jared Bebb on 3/20/17.
//  Copyright © 2017 Jared Bebb LLC. All rights reserved.
//

#include "SquareController.hpp"
#include "Odd.hpp"
#include "Even.hpp"
#include <iostream>



void SquareController::Controller(){
    
    int n;
    std::cout << "Enter square side length in integer format:"<<std::endl;
    std::cin >> n;
    std::cout << "Your side length is:" << n << std::endl <<std::endl;
    if(n == 2){
        std::cout << "Did you really  enter 2????" << std::endl;
        return;
    }
    if (n%2 != 0) {
        Odd mainMS;
        mainMS.oddSquare(n);
        return;
    }
    if(n%4 != 0 && n%2 == 0){
        Even mainDoublySinglyEvenSquare1;
        mainDoublySinglyEvenSquare1.doublyEven(n);
        return;
    }
    if(n%4 == 0){
        Even mainDoublySinglyEvenSquare;
        mainDoublySinglyEvenSquare.doublyEven(n);
        return;
    }
    else{
        std::cout << "IDK what's wrong here"<< std::endl;
        return;
    }
}

