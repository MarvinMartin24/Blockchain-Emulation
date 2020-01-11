# Blockchain-Emulation
Double linked List in C to create un basic encrypted (sha256) - blockchain


## Run

On Mac use the following cmd :
```bash
gcc *.c -o myprog -lstdc++
```
```bash
./myprog
```

## Structure

The two main structures are blockChain_t and block_t :
```c
typedef struct blockChain_t {
    unsigned int countBlock;
    unsigned int countAddresses;
    block_t* genesisBlock;
    block_t* lastBlock;
    char** addresses;
} blockChain_t;

typedef struct block_t {
    char fromAddress[17];
    char toAddress[17];
    unsigned int amount;
    char prevHash[65];
    char hash[65];
    struct block_t* prevBlock;
    struct block_t* nextBlock;
} block_t;
```

## Results - Output

```

Listes d'addresses:
Adresse 1 : ezYDDfgHJ7Qvm76k
Adresse 2 : 5Tb2EvSYtsPHmqJW
Adresse 3 : 7GtspHo3IqyXeQWK
Adresse 4 : 5ZSDRCjZ1yD5tPqV
Adresse 5 : DZqQiegkoVfDeuAH
Adresse 6 : kNCnqBPhNbv3DzNW
Adresse 7 : 7kRB0kjpDTUm6g2l
Adresse 8 : 8yDa6PLda0iYG3Sk
Adresse 9 : SUPUpumv35wSH2uH
Adresse 10 : NHY3LmaYqiO24csi
-------------------------------------------------------------------------------
Block Genesis:
From address  
To address ezYDDfgHJ7Qvm76k
Amount 100 ETH
Prev Hash  
Hash bab8e7130942c6fe7ab9aa8612e6bbe07b68e7e23d099c96d4dbe6252d8f48d6

Chaine valide : 1
Nombre de blocs : 1


Balance de la blockchain: 10
Balance adresse 1 : 100 ETH
Balance adresse 2 : 0 ETH
Balance adresse 3 : 0 ETH
Balance adresse 4 : 0 ETH
Balance adresse 5 : 0 ETH
Balance adresse 6 : 0 ETH
Balance adresse 7 : 0 ETH
Balance adresse 8 : 0 ETH
Balance adresse 9 : 0 ETH
Balance adresse 10 : 0 ETH
-------------------------------------------------------------------------------


L'addresse 1 veut envoyer 25 ETH a l'adresse 4

Transfert de 25 ETH par ezYDDfgHJ7Qvm76k accepte

New Block 2 :
From address ezYDDfgHJ7Qvm76k
To address 5ZSDRCjZ1yD5tPqV
Amount 25 ETH
Prev Hash bab8e7130942c6fe7ab9aa8612e6bbe07b68e7e23d099c96d4dbe6252d8f48d6
Hash c3960442e8ed66ffd85eea8231ec53c92dcb479f8c5a290113ca1b6d08ab57c5

Chaine valide : 1
Nombre de blocs : 2


Balance de la blockchain: 10
Balance adresse 1 : 75 ETH
Balance adresse 2 : 0 ETH
Balance adresse 3 : 0 ETH
Balance adresse 4 : 25 ETH
Balance adresse 5 : 0 ETH
Balance adresse 6 : 0 ETH
Balance adresse 7 : 0 ETH
Balance adresse 8 : 0 ETH
Balance adresse 9 : 0 ETH
Balance adresse 10 : 0 ETH
-------------------------------------------------------------------------------



L'addresse 4 veut envoyer 71 ETH a l'adresse 5

Transfert de 71 ETH par 5ZSDRCjZ1yD5tPqV refuse, Fond insuffissant : 25 ETH seulement
-------------------------------------------------------------------------------



L'addresse 5 veut envoyer 0 ETH a l'adresse 8

Transfert de 0 ETH par DZqQiegkoVfDeuAH accepte

New Block 3 :
From address DZqQiegkoVfDeuAH
To address 8yDa6PLda0iYG3Sk
Amount 0 ETH
Prev Hash c3960442e8ed66ffd85eea8231ec53c92dcb479f8c5a290113ca1b6d08ab57c5
Hash a8b2440828b984940ad7cf3d9be51ec4a2f4fd572df7c2fab4570aea111d5879

Chaine valide : 1
Nombre de blocs : 3


Balance de la blockchain: 10
Balance adresse 1 : 75 ETH
Balance adresse 2 : 0 ETH
Balance adresse 3 : 0 ETH
Balance adresse 4 : 25 ETH
Balance adresse 5 : 0 ETH
Balance adresse 6 : 0 ETH
Balance adresse 7 : 0 ETH
Balance adresse 8 : 0 ETH
Balance adresse 9 : 0 ETH
Balance adresse 10 : 0 ETH
-------------------------------------------------------------------------------



L'addresse 8 veut envoyer 57 ETH a l'adresse 2

Transfert de 57 ETH par 8yDa6PLda0iYG3Sk refuse, Fond insuffissant : 0 ETH seulement
-------------------------------------------------------------------------------

Essayions de modifier un montant : ajoutons 10 ETH au Block 2

Chaine valide : 0
Nombre de blocs : 3


Balance de la blockchain: 10
Balance adresse 1 : 65 ETH
Balance adresse 2 : 0 ETH
Balance adresse 3 : 0 ETH
Balance adresse 4 : 35 ETH
Balance adresse 5 : 0 ETH
Balance adresse 6 : 0 ETH
Balance adresse 7 : 0 ETH
Balance adresse 8 : 0 ETH
Balance adresse 9 : 0 ETH
Balance adresse 10 : 0 ETH
La Blockchain n'est pas valide, la balance n'a pas eu lieu
```
