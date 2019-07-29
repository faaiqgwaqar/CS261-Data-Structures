#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"
#include <string.h>
/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.

 when there are no more words in the input file this function will return NULL.

 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file); /* prototype */

/****************************************/

int main (int argc, const char * argv[]) {
    /*Write this function*/
    const char * filename = argv[1];
    struct hashMap ht;
    char * entWord;
    int * oldAt;
    int repAt;

    FILE * fp = fopen(filename, "r");

    initMap(&ht, 100);
    while(!feof(fp)){
          entWord = getWord(fp);
        /* printf("%s \n", entWord);  */
        /*  printf("%s \n", entWord); */
          if(containsKey(&ht,entWord) == 0)
            insertMap(&ht, entWord, 1);

          else{
            oldAt = atMap(&ht, entWord);
            repAt = *oldAt;
            removeKey(&ht, entWord);
            insertMap(&ht, entWord, repAt+1);
          }

          free(entWord);
    }

    printTable(&ht);

    fclose(fp);
    freeMap(&ht);
	  return 0;
}

char* getWord(FILE * file){
  char * word = (char *) malloc(sizeof(char) * 20);
  if(file == NULL)
    return 0;
  fscanf(file,"%s",word);
  return word;
}
