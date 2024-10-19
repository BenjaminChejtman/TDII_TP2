#include "utils.h"


int strLen(char* src) {
   while (src[len] != 0)
   {
       len++;
   }
   return len;
}


char* strDup(char* src) {
    int length = strLen(src) * 2;
    char* duplicado = (char*)malloc(sizeof(char)*(length+1));
    duplicado = src;
    for (int j=0; i<length; i++)
    {
        int lengthWord = strLen(src[i])
        for (int k=0; i<lengthWord; i++)
        {
            duplicado[lengthWord] = src[j][k]
            lengthWord++;
        }
    }
    duplicado[lengthWord] = 0; //ponemos el caracter nulo en el ultimo caracter para indicar que finalizo el string

    return duplicado;
}


// Keys Predict


struct keysPredict* keysPredictNew() {
    struct keysPredict* kt = (struct keysPredict*)malloc(sizeof(struct keysPredict));
    kt->first = 0;
    kt->totalKeys = 0;
    kt->totalWords = 0;
    return kt;
}


void keysPredictAddWord(struct keysPredict* kt, char* word) {


    // COMPLETAR


}


void keysPredictRemoveWord(struct keysPredict* kt, char* word) {


    // COMPLETAR
}


struct node* keysPredictFind(struct keysPredict* kt, char* word) {


    // COMPLETAR


    return 0;
}


char** keysPredictRun(struct keysPredict* kt, char* partialWord, int* wordsCount) {


    // COMPLETAR


    return 0;
}


int keysPredictCountWordAux(struct node* n) {


    // COMPLETAR
}


char** keysPredictListAll(struct keysPredict* kt, int* wordsCount) {


    // COMPLETAR


    return 0;
}


void keysPredictDelete(struct keysPredict* kt) {


    // COMPLETAR


}


void keysPredictPrint(struct keysPredict* kt) {
    printf("--- Predict --- Keys: %i Words: %i\n", kt->totalKeys, kt->totalWords);
    keysPredictPrintAux(kt->first, 0);
    printf("---\n");
}


void keysPredictPrintAux(struct node* n, int level) {
    if(!n) return;
    struct node* current = n;
    while(current) {
        for(int i=0; i<level;i++) printf(" |   ");
        if(current->end) {
            printf("[%c]\n",current->character);
        } else  {
            printf(" %c \n",current->character);
        }
        keysPredictPrintAux(current->down, level+1);
        current = current->next;
    }
}


// Auxiliar functions


struct node* findNodeInLevel(struct node** list, char character) {
   struct node* findNodeInLevel(struct node** list, char character){
   
   }
}


struct node* addSortedNewNodeInLevel(struct node** list, char character) {


    // COMPLETAR


    return 0;
}


void deleteArrayOfWords(char** words, int wordsCount) {


    // COMPLETAR
}
