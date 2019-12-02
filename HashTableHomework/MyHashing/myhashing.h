//
//  myhashing.h
//  MyHashing
//
//  Created by Jae Moon Lee on 19/11/2019.
//  Copyright © 2019 Jae Moon Lee. All rights reserved.
//

#ifndef myhashing_h
#define myhashing_h

#include <stdio.h>

#define MAX_KEY_SIZE    100

typedef struct MyBucket{
    char        key[MAX_KEY_SIZE];
    void        *value;
    struct MyBucket    *next;
} MyBucket;

typedef struct MyHash{
    float   ratio;
	float	deltaRatio;
    int     tableSize;
    int     count;
    MyBucket **hashTable;
} MyHash;

void    printHash(MyHash *myHash);
MyHash  *createHash(float ratio, float deltaRatio);
void    destroyHash(MyHash *myHash);
void    deleteKey(MyHash *myHash, char *key);

void    putString(MyHash *myHash, char *key, char *value);
char    *getString(MyHash *myHash, char *key);

void    putInt(MyHash *myHash, char *key, int value);
int     getInt(MyHash *myHash, char *key);

void    putFloat(MyHash *myHash, char *key, float value);
float   getFloat(MyHash *myHash, char *key);
#endif /* myhashing_h */
