//
//  main.c
//  MyHashing
//
//  Created by Jae Moon Lee on 19/11/2019.
//  Copyright © 2019 Jae Moon Lee. All rights reserved.
//

#include <stdio.h>
#include "generatedata.h"
#include "myhashing.h"


char key[1000000][12];

int main(int argc, const char * argv[]) {
    // insert code here...

    int n= 10;
    MyHash  *myHash = createHash(0.75, 0.05);
    
    printf("number of keys =%d\n", n);
    for(int i=0;i<n;i++){
        generateKey(key[i], 10);
        putString(myHash, key[i], "jmlee");
        if(getString(myHash, key[i]) == NULL){
            printf("error = %d\n", i);
        }
    }
    printf("end of put/get\n");
    printHash(myHash);
    
	//주석시작
    for(int i=0;i<n;i++){
        char *p = getString(myHash, key[i]);
        if(p == NULL){
            printf("error=%d\n", i);
            exit(0);
        }
    }
    printf("end of matching\n");
    
    for(int i=0;i<n;i++){
        int len = strlen(key[i]);
        key[i][len]='0';
        key[i][len+1]=0;

        char *p = getString(myHash, key[i]);
        if(p != NULL){
            printf("error=%d\n", i);
            exit(0);
        }
    }
    
    printf("end of unmatching\n");


	for (int i = 0; i < n; i++) {
		int len = strlen(key[i]);
		key[i][len-1] = 0;

		deleteKey(myHash, key[i]);
	}

	printf("end of delete\n");
	printHash(myHash);

    //destroyHash(myHash);
	//printf("%d", myHash->count);
    printf("end\n");


	getchar();
    return 0;
}
