
#include "block.h"

// Fonction : Initialise et renvoie un Block
block_t* initBlock(char fromAddress[16], char toAddress[16], unsigned int amount, char prevHash[65], block_t* prevBlock){

    block_t* block = (block_t*) malloc(sizeof(block_t));
    strcpy(block->fromAddress,fromAddress);
    strcpy(block->toAddress,toAddress);
    block->amount= amount;
    strcpy(block->prevHash,prevHash);
    strcpy(block->hash, getHash(block));
    block->prevBlock=prevBlock;
    block->nextBlock =NULL;
    return block;
}

// Fonction renvoie un liste de Caractere char* correspondant à l'identifiant cryté d'un Block
char* getHash(block_t* block){
    char* hash = (char*) malloc((17+17+10+65)*sizeof(char));
    char nb[10];
    strcat(hash,block->fromAddress);
    strcat(hash,block->toAddress);
    sprintf(nb, "%d",block->amount);
    strcat(hash, nb);
    strcat(hash,block->prevHash);
    return SHA256(hash);
}

// Procedure permettant l'affichage des informations d'un block donné en parametre
void displayBlock(block_t* block){
    printf("From address %s\n", block->fromAddress);
    printf("To address %s\n", block->toAddress);
    printf("Amount %d ETH\n", block->amount);
    printf("Prev Hash %s\n", block->prevHash);
    printf("Hash %s\n", block->hash);
}
