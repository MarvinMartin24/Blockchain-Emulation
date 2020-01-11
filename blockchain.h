#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"


typedef struct blockChain_t {
    unsigned int countBlock;
    unsigned int countAddresses;
    block_t* genesisBlock;
    block_t* lastBlock;
    char** addresses;
} blockChain_t;

blockChain_t* initBlockchain(char** addresses, unsigned int amount);

char** createAdresses();

void displayAdresses(blockChain_t* blockchain);

void displayAdressesCount(blockChain_t* blockchain);

int isChainValid(blockChain_t* blockchain);

unsigned int getBalanceOf(blockChain_t* blockchain, char address[17]);

int canSend(blockChain_t* blockchain, char address[17], unsigned int amount);

void addNewBlock(blockChain_t* blockchain, block_t* block);

int indexFromAdress(blockChain_t* blockchain, char fromAddress[17]);

int indexToAdress(blockChain_t* blockchain,char toAddress[17]);

void createNewTransaction(blockChain_t* blockchain, char fromAddress[17], char toAddress[17], unsigned int amount);

#endif /* end of include guard: BLOCKCHAIN_H */
