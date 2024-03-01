#include<stdio.h>

#define TABLE_SIZE 10

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertValue(int hashTable[],int key)
{
    int i=0;
    int hkey=hashFunction(key);
    int index;

    do
    {
        index=(hkey+i) % TABLE_SIZE;
        if(hashTable[index]==-1)
        {
            hashTable[index]=key;
            printf("inserted key %d at index %d\n",key,index);
            return;
        }
        i++;
    }while(i<TABLE_SIZE);
    printf("unable to insert key %d,hash table is full\n",key);
}

int searchValue(int hashTable[],int key)
{
    int i=0;
    int hkey=hashFunction(key);
    int index;

    do
    {
        index=(hkey+i) % TABLE_SIZE;
        if(hashTable[index]==key)
        {
            printf("key %d found at index %d\n",key,index);
            return index;
        }
        i++;
    }while(i<TABLE_SIZE);

    printf("key % not found in the hash table\n",key);
    return -1;
}

int main()
{
    int hashTable[TABLE_SIZE];
    for(int i=0;i<TABLE_SIZE;i++)
    {
        hashTable[i]=-1;
    }

    insertValue(hashTable,1234);
    insertValue(hashTable,5678);
    insertValue(hashTable,9101);
    insertValue(hashTable,1213);
    insertValue(hashTable,1415);

    return 0;
}
