#include "utils.h"

char* abecedario = 'abcdefghijklmnñopqrstuvwxyz';

int strLen(char* src) {
    int len = 0;
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

struct node* nodeNew(char character){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->character = character;
    n->next = NULL;
    n->end = 0;
    n->word = NULL;
    n->down = NULL;
    return n;
}

void keysPredictAddWord(struct keysPredict* kt, char* word) {
    struct node* newNode = addSortedNewNodeInLevel( , word[0])

    int i = 1; //nos salteamos el primer caracter ya que ya lo pusimo en su respectiva posicion entre los primeros nodos (osea como los del mismo nivel)

    while (i < strLen(word))
    {
        struct node* nodoDown = nodeNew(word[i]);
        newNode->down = nodoDown;
        newNode = nodoDown;
        i++;
    }

    

    kt->totalKeys += strLen(word);
    kt->totalWords += 1;
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
    char* characterPasado;
    while(list){ //no habria que poner list->next asi para que termine cuando next=0? 
        if (list->character == character){
            characterPasado = list;
        }
    }
    return 0;
}


struct node* addSortedNewNodeInLevel(struct node** list, char character) {
    struct node* nodo1 = nodeNew(character);
    
    //nodo->character = character;
    
    if (kt->first = NULL || kt->first->character > character) //nos fijamos si la lista esta vacia o si el nuevo nodo deberia ser el primero en orden alfabetico
    {
        nodo1->next = kt->first;
        kt-> fisrt = nodo1;
    }
    
    else
    {
        struct node* actualNode = keys->first;
        while (actual->next != NULL && actual->next->character < character)
        {
            actual = actual->next;
        }
        nodo1->next = actual->next;
        actualNode->next = nodo1;
    }

    return 0;
}


void deleteArrayOfWords(char** words, int wordsCount) {
    char* current = words;
    for (int i = 0; i < wordsCount; i++){
        char* tmp;
        tmp = current;
        current = current->next
        free(tmp);
    }   
}
