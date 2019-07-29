#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
/*Completion Mark*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}
/*Completion Mark*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}
/*Completion Mark*/
void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}
/*Completion Mark*/
void freeMap (struct hashMap * ht)
{  /*write this*/
	/*find a way to loop through and clear nodes*/
	int i = 0;
	struct hashLink * current;
	struct hashLink * previous;
	assert(ht);
	for(i = 0; i < ht->tableSize; i++){
		if(ht->table[i] != NULL){
			if(ht->table[i]->next == NULL)
				free(ht->table[i]);
			else{
				current = ht->table[i]->next;
				previous = ht->table[i];
				while(current != NULL){
					free(previous);
					previous = current;
					current = current->next;
				}
			}
		}
		ht->tableSize = 0;
		ht->count = 0;
	}

	free(ht->table);
}
/*Completion Mark*/
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	char * useKEY = (char *) malloc(sizeof(char) * 20);
	int idx = stringHash1(k) % ht->tableSize;
	struct hashLink * hlnk;
	struct hashLink * plink;
	assert(ht);
	strcpy(useKEY,k);

	if(ht->table[idx] == NULL){
		hlnk = (struct hashLink *) malloc(sizeof(struct hashLink));
		hlnk->value = v;
		hlnk->key = useKEY;
		hlnk->next = NULL;
		ht->table[idx] = hlnk;
		ht->count++;
	}

	else{
		plink = ht->table[idx];
		hlnk = (struct hashLink *) malloc(sizeof(struct hashLink));
		hlnk->value = v;
		hlnk->key = useKEY;
		hlnk->next = plink->next;
		plink->next = hlnk;
		ht->count++;
	}
}

/*Completion Mark*/
ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/
	int idx = stringHash1(k) % ht->tableSize;
	struct hashLink * hlnk;
	assert(ht);
	if(ht->table[idx] == NULL)
		return 0;

	if(ht->table[idx]->next == NULL){
		if(ht->table[idx]->key == k)
			return (&ht->table[idx]->value);
		return 0;
	}
	else{
		hlnk = ht->table[idx];
		while(hlnk != NULL){
			if(hlnk->key == k)
				return (&hlnk->value);
			hlnk = hlnk->next;
		}
		return 0;
	}
}
/*Completion Mark*/
int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	int idx = stringHash1(k) % ht->tableSize;
	char * useKEY = (char *) malloc(sizeof(char) * 20);
	struct hashLink * hlnk;
	assert(ht);
	strcpy(useKEY,k);
	printf("%s", k);

	if(ht->table[idx] == NULL){
		return 0;
	}

	if(ht->table[idx]->next == NULL){
		if(ht->table[idx]->key == useKEY)
			return 1;
		return 0;
	}
	else{
		hlnk = ht->table[idx];
		while(hlnk->next != NULL){
			if(hlnk->key == useKEY)
				return 1;
			hlnk = hlnk->next;
		}
		return 0;
	}
}
/*Completion Mark*/
void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
	int idx = stringHash1(k) % ht->tableSize;
	struct hashLink * hlnk;
	struct hashLink * nullifier;

	assert(ht != NULL);
	assert(ht->table[idx] != NULL);

	if(ht->table[idx]->next == NULL){
		free(ht->table[idx]);
		ht->table[idx] = NULL;
		ht->count--;
	}

	else{
		hlnk = ht->table[idx];
		while(hlnk != NULL){
			if(hlnk->key == k){
				nullifier = hlnk;
				free(hlnk);
				nullifier->next = NULL;
				ht->count--;
				return;
			}
			hlnk = hlnk->next;
		}
		return;
	}
}
/*Completion Mark*/
int sizeMap (struct hashMap *ht)
{  /*write this*/
	assert(ht);
	return ht->count;
}
/*Completion Mark*/
int capacityMap(struct hashMap *ht)
{  /*write this*/
	assert(ht);
	return ht->tableSize;
}
/*Completion Mark*/
int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int emptyCounter = 0;
	int i = 0;

	for(i = 0; i < ht->tableSize; i++){
		if(ht->table[i] == NULL)
			emptyCounter++;
	}
	return emptyCounter;
}
/*Completion Mark*/
float tableLoad(struct hashMap *ht)
{  /*write this*/
	assert(ht);
	return (ht->count/ht->tableSize);
}

void printTable(struct hashMap *ht){
	int i = 0;
	int countIdx;
	char * temp;
	struct hashLink * readLink;
	for(i = 0; i < ht->tableSize; i++){
		if(ht->table[i] != NULL){
			if(ht->table[i]->next == NULL){
				printf("%s: %d \n", ht->table[i]->key, ht->table[i]->value);
			}
			else{
				readLink = ht->table[i];
				countIdx = 0;
				temp = readLink->key;
				while(readLink->next != NULL){
					countIdx++;

					readLink = readLink->next;
				}
				printf("%s: %d \n", temp, countIdx);
			}
		}
	}
}
