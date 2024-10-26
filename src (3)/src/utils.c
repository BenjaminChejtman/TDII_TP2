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

  int length = strLen(src);
  char* dup = (char*)malloc(sizeof(char)*(length)+1)
  
  for(int i = 0; i < length; i++){
    dup[i] = src[i];
  }
  
  dup[length] = 0;
  return dup;
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
    struct node* curr = kt->first; //empezamos por el primer nodo
    char first = curr->character;

    for (int i = 0; i < strLen(word); i++)
    {
      struct node* found = findNodeInLevel(&curr, word[i])
      if(found != 0) //se encontro{
        curr = curr->down;
        if(i==strLen(word)-1)//si ya agregamos todas las letras de word...
        {
          new->end=1;// ponemos que este el nodo final de nuestra word
          new->word = strDup(word) //agregamos la palabra completa a word
        }
        
      }
      else //si no se encontro el caracter lo agregamos
      {
        kt->totalKeys++; //agregamos 1 del caracter nuevo que agregamos
        struct node* new = addSortedNewNodeInLevel(&curr, word[i]); //agregamos el nuevo caracter donde corresponde
        curr = curr->down; //despues de agregar la letra en su nivel correspondiente, bajamos de nivel
      
        if (i==0 && word[i] < first) //en caso de que sea la primer letra hasta ahora hacemos que el frist apunte a este nodo
        {
          kt->first = new;
        }
        
        if(i==strLen(word)-1)//si ya agregamos todas las letras de word...
        {
          new->end=1;// ponemos que este el nodo final de nuestra word
          new->word = strDup(word) //agregamos la palabra completa a word
        }
      
    }
  
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
      return 0;
    }
}


struct node* addSortedNewNodeInLevel(struct node** list, char character) {
    struct node* newNode = nodeNew(character);
    
    if (*list == NULL || (*list)->character > character) //nos fijamos si la lista esta vacia o si el nuevo nodo deberia ser el primero en orden alfabetico
    {
        newNode->next = *list;
        *list = newNode;
    }
    
    else
    {
        struct node* curr = *list; //empezamos con el primer nodo
        while (curr->next != NULL && curr->next->character < character)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    return *list;
}


void deleteArrayOfWords(char** words, int wordsCount) {
    for (int i = 0; i < wordsCount; i++){
      free(words[i]);
    }
    free(words);
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
  
  2)2)
      // Crear una lista vacía
    struct node* list = NULL;

    // Agregar nodos a la lista
    list = addSortedNewNodeInLevel(&list, 'b');
    list = addSortedNewNodeInLevel(&list, 'a');
    list = addSortedNewNodeInLevel(&list, 'c');
    list = addSortedNewNodeInLevel(&list, 'd');
    list = addSortedNewNodeInLevel(&list, 'a');
    list = addSortedNewNodeInLevel(&list, 'b');

    // Imprimir la lista para verificar que esté correcta
    while (list != NULL) {
        printf("%c ----- ", list->character);
        list = list->next;
    }
    printf("NULL\n");

    return 0;
    
    
    2)3)
    ----------

  */
}
