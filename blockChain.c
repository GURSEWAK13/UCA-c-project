#include "openssl/crypto.h"
#include "openssl/sha.h"
struct block{
    // <hash>
    unsigned char prevHash[SHA256_DIGEST_LENGTH];
    // data to be in the hash
    int blockData ;
    // link to the next node of the block chain
    struct block *link;
}*head;

//SHA256(src , size , dest); ----> for Block Hash

//src and dest sre of type unsigned char pointer (*)

void addBlock(int data){
    if (head==NULL)
    {
        head=malloc(sizeof(struct block));
        SHA256("",sizeof(""),head->prevHash);
        head->blockData = data;
    }
    struct block *currentBlock = head;
    while(currentBlock->link)
        currentBlock = currentBlock->link;
    struct block *newBlock = malloc(sizeof(struct block));
    currentBlock->link = newBlock;
    newBlock->blockData = data;
    SHA256(toString(*currentBlock),sizeof(*currentBlock),newBlock->prevHash);
}

void verifyChain(){
    if(head == NULL){
        printf("Hey Idiot if you want to verify chain make sure you created atleast single block\n");
        return;
    }
    struct block *curr = head->link , *prev = head;
    int count = 1;
    while (curr)
    {
        printf("%d\t[%d]\t",count++,curr->blockData);
        hashPrinter(SHA256)
    }
    
}