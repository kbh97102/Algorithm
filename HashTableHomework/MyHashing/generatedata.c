//
//  generatedata.c
//  MyHashing
//
//  Created by Jae Moon Lee on 19/11/2019.
//  Copyright © 2019 Jae Moon Lee. All rights reserved.
//
#include "stdlib.h"
#include "generatedata.h"

char *generateKey(char *buffer, int maxSize){
    
    int size = rand() % (maxSize-1) + 1;
    for(int i=0;i<size;i++){
        buffer[i] = 'a' + rand()%26;
    }
    buffer[size] = 0;
    return buffer;
}

char *generateString(char *buffer, int size){

    for(int i=0;i<size;i++){
        buffer[i] = 'a' + rand()%26;
    }
    return buffer;
}

int geterateInt(int maxValue){
    return rand() % maxValue;
}
