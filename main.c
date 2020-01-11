#include "block.h"
#include "blockchain.h"
#include <time.h>

int main(){


    srand(time(NULL));

    // Variables
    unsigned int initAmount= 100;
    int randomIndexAddress =0;
    int randomAmount = 0;
    int tmpIndexAddress = 0;
    char** addresses=createAdresses();

    // Création de la Blockchain
    blockChain_t* blockchain = initBlockchain(addresses,initAmount);

    // Affichage des clients / addresses de la Blockchain
    displayAdresses(blockchain);

    // Genesis Block
    printf("-------------------------------------------------------------------------------");
    printf("\nBlock Genesis:\n");
    displayBlock(blockchain->genesisBlock);
    printf("\nChaine valide : %d\n", isChainValid(blockchain));
    printf("Nombre de blocs : %d\n", blockchain->countBlock);
    displayAdressesCount(blockchain);
    printf("-------------------------------------------------------------------------------");

    // Création de 4 Blocks, choix des address et des amount aléatoire
    for (int i=0; i<4 ;i++){
        do{
            randomIndexAddress = rand() % (9);
        }while (randomIndexAddress == tmpIndexAddress);

        randomAmount = rand()% 100;

        createNewTransaction(blockchain, addresses[tmpIndexAddress], addresses[randomIndexAddress], randomAmount);
        tmpIndexAddress = randomIndexAddress;

        printf("-------------------------------------------------------------------------------\n");
    }

    // Tentative de hack de la Blockchain
    printf("\nEssayions de modifier un montant : ajoutons 10 ETH au Block 2\n");
    blockchain->genesisBlock->nextBlock->amount +=10;
    printf("\nChaine valide : %d\n", isChainValid(blockchain));
    printf("Nombre de blocs : %d\n", blockchain->countBlock);
    displayAdressesCount(blockchain);
    printf("-------------------------------------------------------------------------------\n");

    system("pause");
    return 0;
}
