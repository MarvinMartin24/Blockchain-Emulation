#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sha256.h"


typedef struct block_t {
    char fromAddress[17];
    char toAddress[17];
    unsigned int amount;
    char prevHash[65];
    char hash[65];
    struct block_t* prevBlock;
    struct block_t* nextBlock;
} block_t;




block_t* initBlock(char fromAddress[16], char toAddress[16], unsigned int amount, char prevHash[65], block_t* prevBlock);
char* getHash(block_t* block);
void displayBlock(block_t* block);





#endif /* end of include guard: BLOCK_H */
