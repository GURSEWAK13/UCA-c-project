#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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


void addBlock(int);
void verifyChain();
void alterNthBlock(int, int);
void hackChain();
int hashCompare(unsigned char*,unsigned char*);
void hashPrinter(unsigned char[],int );
unsigned char* toString(struct block);
void printBlock(struct block*);
void printAllBlocks();

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
        hashPrinter(SHA256(toString(*prev),sizeof(*prev),NULL),SHA256_192_DIGEST_LENGTH);
        printf(" - ");
        hashPrinter(curr->prevHash,SHA256_192_DIGEST_LENGTH);
        if(hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
            printf("Chain is valid\n");
        else
            printf("Imposter");
		prev=curr;
		curr=curr->link;
    }
    
}

void alterNthBlock(int n, int newData)
{
	struct block *curr=head;
	int count=1;
	if(curr==NULL)
	{
		printf("Nth Block does not exists!\n");
		return;
	}
	while(count!=n)
	{
		if(curr->link==NULL && count!=n)
		{
			printf("Nth Block does not exist!\n");
			return;
		}
		else if(count==n)
			break;
		curr == curr->link;
		count++;
		printf("Before: ");
			printBlock(curr);
		curr->blockData=newData;
		printf("\nAfter: ");
			printBlock(curr);
		printf("\n");
	}
}

void hackChain()
{
	struct block *curr=head,*prev;
	if(curr==NULL)
	{
		printf("BlockChain is empty");
		return;
	}
	while(1)
	{	prev = curr;
		curr = curr->link;
		if(curr==NULL)
			return;
		if(!hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
		{
			hashPrinter(
				SHA256(toString(*prev),sizeof(*prev),curr->prevHash),
				SHA256_DIGEST_LENGTH
			);
			printf("\n");
		}
	}
}

unsigned char* toString(struct block b)
{
	unsigned char *str = malloc(sizeof(unsigned char)*sizeof(b));
	memcpy(str,&b,sizeof(b));
	return str;
}

void hashPrinter(unsigned char hash[],int length)
{
	for(int i=0 ; i<length ; i++)
		printf("%02x",hash[i]);
}

int hashCompare(unsigned char *str1,unsigned char *str2)
{
	for(int i=0 ; i<SHA256_DIGEST_LENGTH ; i++)
	{
		if(str1[i]!=str2[i])
			return 0;
	}
	return 1;
}

void printBlock(struct block *b)
{
	printf("%p]t" , b);
	hashPrinter(b->prevHash,sizeof(b->prevHash));
	printf("\t[%d]\t",b->blockData);
	printf("%p\n",b->link);
}

void printAllBlocks()
{
	struct block *curr = head;
	int count = 0;
	while(curr)
	{
		printBlock(curr);
		curr = curr->link;
	}
}

void main()
{
	int c,n,r;
	printf("1)addBlock\n2)add n random Blocks\n3)alterNthBlock\n4)print All Block\n5)verifyChain\n6)hackChain\n7)exit\n");
	while(1)
	{
		printf("Choice: ");
		scanf("%d",&c);
		if (c == 1) {
    printf("Enter data: ");
    scanf("%d", &n);
    addBlock(n);
} else if (c == 2) {
    printf("How many blocks to enter? : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        r = rand() % (n * 10);
        printf("Entering: %d\n", r);
        addBlock(r);
    }
} else if (c == 3) {
    printf("Which block to alter? : ");
    scanf("%d", &n);
    printf("Enter Value: ");
    scanf("%d", &r);
    alterNthBlock(n, r);
} else if (c == 4) {
    printAllBlocks();
} else if (c == 5) {
    verifyChain();
} else if (c == 6) {
    hackChain();
}else if(c==7){
	exit(1);
}else {
    printf("Wrong Choice\n");
}
	}
	// return 0;
}
