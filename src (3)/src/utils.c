#include "utils.h"

int strLen(char* src) {
    int len = 0;
    while (src[len] != 0)
    {
        len++;
    }
    return len;
}

char* strDup(char* src) { //fijarse si agregar eso de que no hay espacio disponible que me mande por whatsapp

  int length = strLen(src)*2+1; //sumamos uno por el caracter nulo
  char* srcDup = (char*)malloc(sizeof(char)*(length+1));
  
  int indexDup = 0;
  
  for (int i = 0; i<2; i++){
    int currLen = strLen(src);
    for (int j = 0; j<currLen; j++){
      srcDup[indexDup] = src[j];
      indexDup++;  
    }
  }

  srcDup[indexDup] = 0; //agregamos el caracter nulo para indicar la finalizacion de nuestro srcDup
  return srcDup;
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
    if (*list == NULL){ //verificamos si la lista esta vacia
      return 0;
    }
    else{
      struct node* curr = *list;
      while (curr != NULL){
        if(curr->character == character){
          return curr;
        }
        curr = curr->next; //como nuestra nueva froma de hacer i++;
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

//#####################################################################################

int main() {
  /*
  1)1)
  int len = strLen("hola");
  printf("strLen devuelve %i", len);
  printf("\n");
  
  1)2)
  char* dup = strDup("hola");
  printf("strDup devuelve %s", dup);
  
  free(dup);
  return 0;
  
  
  2)1)
  struct keysPredict* kt = keysPredictNew();
  kt->first = nodeNew('a');
  kt->first->next = nodeNew('b');
  kt->first->next->next = nodeNew('c');

  // Caso 1: Nodo existe en la lista
  struct node* nodoEncontrado = findNodeInLevel(&(kt->first), 'a');
  if (nodoEncontrado != NULL) {
      printf("Nodo encontrado con caracter '%c'\n", nodoEncontrado->character);
  } else {
      printf("Nodo no encontrado\n");
  }

  // Caso 2: Nodo no existe en la lista
  nodoEncontrado = findNodeInLevel(&(kt->first), 'd');
  if (nodoEncontrado != NULL) {
      printf("Nodo encontrado con caracter '%c'\n", nodoEncontrado->character);
  } else {
      printf("Nodo no encontrado\n");
  }

  // Caso 3: Lista vacía
  struct node* listaVacia = NULL;
  nodoEncontrado = findNodeInLevel(&listaVacia, 'a');
  if (nodoEncontrado != NULL) {
      printf("Nodo encontrado con caracter '%c'\n", nodoEncontrado->character);
  } else {
      printf("Nodo no encontrado\n");
  }

  return 0;
  */
}
