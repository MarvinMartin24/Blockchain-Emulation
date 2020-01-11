#include "blockchain.h"

//Fonction : Initialise et renvoie la blockchain
blockChain_t* initBlockchain(char** addresses, unsigned int amount){
    blockChain_t* blockchain = (blockChain_t*) malloc(sizeof(blockChain_t));
    blockchain->genesisBlock = initBlock(" ", addresses[0], amount, " ", NULL);
    strcpy(blockchain->genesisBlock->hash, getHash(blockchain->genesisBlock));
    blockchain->lastBlock=blockchain->genesisBlock;
    blockchain->countBlock=1;
    blockchain->countAddresses=10;
    blockchain->addresses=addresses;
    return blockchain;
}

// Fonction : Genere et renvoie une matrice d'addresses char**
char** createAdresses(){

    char** addresses;
    // Caractere possible
    char list[62]="abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int random;

    //Allocation Dynamique 2D
    addresses = (char**)malloc(10*sizeof(char*));
    for(int i=0 ; i<10 ; i++){
        addresses[i] = (char*) malloc(17*sizeof(char));
        for(int j=0 ; j<16 ; j++){
            // Aléatoire
            random=rand()%(61);
            addresses[i][j] = list[random];
        }
        addresses[i][16]='\0';
    }
    return addresses;
}

// Procedure: Afficher les addresses
void displayAdresses(blockChain_t* blockchain){
    printf ("\n\nListes d'addresses:\n");
    for(int i=0 ; i<blockchain->countAddresses ; i++){
         printf("Adresse %d : %s\n",i+1,blockchain->addresses[i]);
    }
}

// Procedure: Afficher les montants de toute les addresses
void displayAdressesCount(blockChain_t* blockchain){
    printf ("\n\nBalance de la blockchain: %d\n",blockchain->countAddresses);
    for(int i=0 ; i<blockchain->countAddresses ; i++){
            printf("Balance adresse %d : %d ETH\n",i+1,getBalanceOf(blockchain, blockchain->addresses[i]));
    }
    if (isChainValid(blockchain)==0){ printf("La Blockchain n'est pas valide, la balance n'a pas eu lieu\n");}
}

// Fonction: Verifier la validite de la Blockchain, renvoie un int, 1 si valide, 0 sinon
int isChainValid(blockChain_t* blockchain){

    block_t* tmp = blockchain->genesisBlock;
    tmp=blockchain->genesisBlock->nextBlock;

    if (strcmp(getHash(blockchain->genesisBlock),blockchain->genesisBlock->hash)!=0){
        return 0;
    }
    //Balaye toute la Blockchain jusqu'au dernier block
    while (tmp != NULL){
        if((strcmp(tmp->hash, getHash(tmp))!=0) || (strcmp(tmp->prevHash, tmp->prevBlock->hash)!=0) ){
                return 0;
        }
        // Passe au Block suivant
        else tmp=tmp->nextBlock;
    }
    return 1;
}

// Fonction : Obtention des balances de l'address donnée en parametre, retourne un entier
unsigned int getBalanceOf(blockChain_t* blockchain, char address[17]){
    unsigned int nb=0;
    block_t* tmp;
    tmp=blockchain->genesisBlock;

    for(int i=0; i<strlen(address); i++){
        //Balaye toute la Blockchain jusqu'au dernier block
        while (tmp != NULL){
            // Gagne amount
            if (strcmp(address,tmp->toAddress)==0){
                nb+=tmp->amount;
            }
            // Perd amount
            if (strcmp(address,tmp->fromAddress)==0){
                nb-=tmp->amount;
            }
            // Passe au Block suivant
            tmp=tmp->nextBlock;
        }
    }
    return nb;
}

// Fonction : Verifier si l'addresse donnée en parametre dispose d'assez de fond pour une transaction de valeur amout. Renvoie 1 si oui, 0 sinon
int canSend(blockChain_t* blockchain, char address[17], unsigned int amount){
    if(getBalanceOf(blockchain,address)< amount){
        printf("\nTransfert de %d ETH par %s refuse, Fond insuffissant : %d ETH seulement\n", amount, address, getBalanceOf(blockchain,address));
        return 0;
    }
    else {
        printf("\nTransfert de %d ETH par %s accepte\n", amount, address);
        return 1;
    }
}

// Procedure : Ajoute un block en derniere position dans la blockchain
void addNewBlock(blockChain_t* blockchain, block_t* block){

    blockchain->lastBlock->nextBlock=block;
    block->prevBlock=blockchain->lastBlock;
    blockchain->lastBlock=block;
    blockchain->countBlock++;
}

// Fonction : renvoie un int correspondant à l'indice de l'addresse (cas fromAddress)
int indexFromAdress(blockChain_t* blockchain, char fromAddress[17]){
    int res=0;
    for(int i=0 ; i<10 ; i++){
        if (strcmp(fromAddress,blockchain->addresses[i])==0){
            res=i+1;
        }
    }
    return res;
}
// Fonction : renvoie un int correspondant à l'indice de l'addresse (cas toAddress)
int indexToAdress(blockChain_t* blockchain,char toAddress[17]){
    int res=0;
    for(int i=0 ; i<10 ; i++){
        if (strcmp(toAddress,blockchain->addresses[i])==0){
            res=i+1;
        }
    }
    return res;
}

// Procedure : creation d'une nouvelle transaction dans la blockchain de valeur amount entre deux addresses.
void createNewTransaction(blockChain_t* blockchain, char fromAddress[17], char toAddress[17], unsigned int amount){

    printf("\n\n\nL'addresse %d veut envoyer %d ETH a l'adresse %d\n", indexFromAdress(blockchain,fromAddress), amount, indexToAdress(blockchain,toAddress));
    // Creation du Nouveau Block
    block_t* newBlock = initBlock(fromAddress,toAddress , amount, blockchain->lastBlock->hash, blockchain->lastBlock);
    // Blindage
    if (canSend(blockchain,fromAddress, amount)==1){
        // Ajout du Nouveau Block dans la Blockchain
        addNewBlock(blockchain, newBlock);

        //Affichage des données
        printf("\nNew Block %d :\n",blockchain->countBlock);
        displayBlock(newBlock);
        printf("\nChaine valide : %d\n", isChainValid(blockchain));
        printf("Nombre de blocs : %d\n", blockchain->countBlock);
        displayAdressesCount(blockchain);
    }
}
