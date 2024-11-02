#include "utils.h"
#include <stdlib.h>

int strLen(char* src) {
  int len = 0;
  while (src[len] != NULL)
  {
    len++;
  }
  return len;
}

char* strDup(char* src) { //fijarse si agregar eso de que no hay espacio disponible que me mande por whatsapp

  int length = strLen(src);
  char* dup = (char*)malloc(sizeof(char)*(length)+1);

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
    if (kt == NULL || word == NULL) {
        // Manejar el error
        return;
    }

    // Si kt está vacío, inicializar el primer nodo
    if (kt->first == NULL) {
        kt->first = nodeNew(word[0]); // Inicializar el primer nodo con la primera letra
        kt->totalKeys += 1; // Actualizar el total de teclas
    }

    // Si la nueva palabra comienza con una letra que va antes que el primer nodo
    if (word[0] < kt->first->character) {
        struct node* newFirstNode = nodeNew(word[0]); // Crear nuevo nodo
        newFirstNode->next = kt->first; // Apuntar al antiguo primer nodo
        kt->first = newFirstNode; // Actualizar el primer nodo
        kt->totalKeys++; // Actualizar total de teclas
    }

    struct node* curr = kt->first;

    for (int i = 0; word[i] != NULL; i++) {
        struct node* next = findNodeInLevel(&curr, word[i]);

        if (next == NULL) {
            // Si no encontramos la letra en el nivel actual, la agregamos en la lista ordenada
            kt->totalKeys++;
            next = addSortedNewNodeInLevel(&(curr->next), word[i]);
        }

        if (i == strLen(word) - 1) {
            // Marcar el final de la palabra y guardar la palabra completa
            next->end = 1;
            if (next->word == NULL) { // Solo asignar si no ha sido asignado antes
                next->word = strDup(word);
            }
        } else {
            // Pasar al nivel descendente (down)
            if (next->down == NULL) {
                next->down = nodeNew(word[i + 1]);
                kt->totalKeys++;
            }
            curr = next->down; // Avanzar al siguiente nivel
        }
    }

    // Incrementar el contador de palabras únicas
    kt->totalWords++;
}


void keysPredictRemoveWord(struct keysPredict* kt, char* word) {
  struct node* curr = kt->first;
  if(kt->first == 0 || word == NULL){
    return;  
  }
  
  for(int i = 0; i < strLen(word); i++)
  {

    struct node* found = findNodeInLevel(&curr, word[i]);
    printf("1");

    if (found != NULL ) //si se encontro...
    {
      printf("2");
      printf("%c", found->character);
      curr = found->down; // avanzar al nodo encontrado
      if (i < strLen(word) - 1 ) // si no es la última letra
      { 
        printf("3");
        if (found->down != NULL) // si hay nivel inferior
        { 
          printf("4");
          found = findNodeInLevel(&(found->down), word[i+1]);
        } 
      }
      else // si es la última letra
      { 
        printf("5");
        if (found->word != NULL)
        {
          printf("6");
          free(found->word);
          printf("%s\n", found->word);
          //found->word = NULL;
          found->end = 0;
          kt->totalWords--;
        }
      
      }
      //printf("la palabra enocntrada es: %s\n", found->word);
      //free(found->word);
    } 
    else //si no se encontro
    {
      printf("\nno se encontro");
      printf("%c",found->character);
    }
  }
}


struct node* keysPredictFind(struct keysPredict* kt, char* word) {
  struct node* curr = kt->first;

  for(int i = 0; i < strLen(word); i++)
  {
    printf("\n1");
    struct node* found = findNodeInLevel(&curr, word[i]);
    printf("--%c", word[i]);
    if (found != NULL) //si se encontro...
    {
      printf("2");
      curr = found; // avanzar al nodo encontrado
      printf("@@@@@%c", curr->character);
      if (i < strLen(word) - 1) // si no es la última letra
      { 
        printf("3");
        if (curr->down != NULL) // si hay nivel inferior
        { 
          printf("4");
          curr = findNodeInLevel(&(curr->down), word[i+1]);
          printf("****%c", word[i+1]);
        }
        else //no hay nivel inferior, entonces, palabra no encontrada
        {
          printf("5");
          return 0;
        }
      } 
      else // si es la última letra
      { 
        printf("6");
        if (strcmp(curr->word, word) == 0 && curr->end == 1) 
        {
          printf("7");
          return curr;
        }
        else //si no hay palabra en word, entonces, palabra no encontrada
        {
          printf("8");
          return 0;
        }
      }
    } 
    else //no se encuentra la letra, entonces palabra no encontrada
    {
      printf("9");
      return 0;
    }
  }
  printf("10");
  return 0; //salio del bucle y no encontro la palabra
}


char** keysPredictRun(struct keysPredict* kt, char* partialWord, int* wordsCount) {

  struct node* curr = kt->first;
  char** = (char**)malloc(sizeof(char*(*char)*wordsCount*strLen())) //cual seria el size que tendriamos que pedir?
  
  for(int i = 0; i < strLen(partialWord); i++)
  {
    struct node* found = findNodeInLevel(&curr, word[i]);
    if (found != 0) //si se encontro...
    {
      curr = found; // avanzar al nodo encontrado
      if (i < strLen(word) - 1) // si no es la última letra
      { 
        if (curr->down != NULL) // si hay nivel inferior
        { 
          curr = findNodeInLevel(&curr->down, word[i+1]);
        }
        else //no hay nivel inferior, entonces, palabra no encontrada
        {
          return 0;
        }
      } 
      else // si es la última letra
      { 
        curr = curr->down;
        if(curr->end == 1) //si no hay una palabra completa...
        {
          struct node* currLevel = curr; //mantenemos el nivel original para poder ver todos sus down
          foundWords += curr->word; 
          curr = curr->next;
        }
        else //si no hay una palabra completa...
        {
          
        }
            
      }
      }
    } 
    else //no se encuentra la letra, entonces palabra no encontrada
    {
      return 0;
    }
  
  return 0; //salio del bucle y no encontro la palabra
}

int keyPredictListAllCountWords(struct node* node){
  struct node* curr = node;
  int wordsCount = 0;

  if(!node){
    return wordsCount;
  }

  while(curr){
    if(curr->end == 1){
      wordsCount++;
    }
    wordsCount += keyPredictListAllCountWords(curr->down);
    curr = curr->next;
  }

  return wordsCount;
}

void keyPredictListAllAux(struct node* node, char** res, int* i){
  struct node* curr = node;

  if(!node) return;

  while(curr){
    if(curr->end == 1){
      res[*i] = strDup(curr->word);
      (*i)++;
    }
    keyPredictListAllAux(curr->down, res, i);
    curr = curr->next;
  }
}

char** keysPredictListAll(struct keysPredict* kt, int* wordsCount) {
    *wordsCount = keyPredictListAllCountWords(kt->first);
    
    // Cambia aquí el tamaño de la memoria asignada a res
    char** res = (char**)malloc(sizeof(char*) * (*wordsCount));

    if (!res) return NULL; // Verificamos asignación de memoria

    int i = 0;
    keyPredictListAllAux(kt->first, res, &i);

    return res;
}


void keysPredictDeleteAux(struct node* node)
{
  if(!node) return;
   keysPredictDeleteAux(node->down);
   keysPredictDeleteAux(node->next);

   if (node->word != NULL){
     free(node->word);
   }
   free(node);
}


void keysPredictDelete(struct keysPredict* kt)
{
  if(!kt) return;

  keysPredictDeleteAux(kt->first);
  kt->first = NULL;
  kt->totalKeys = 0;
  kt->totalWords = 0;
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

void keysPredictPrint(struct keysPredict* kt) {
    printf("--- Predict --- Keys: %i Words: %i\n", kt->totalKeys, kt->totalWords);
    keysPredictPrintAux(kt->first, 0);
    printf("---\n");
}


// Auxiliar functions


struct node* findNodeInLevel(struct node** list, char character) {
    if (*list == NULL){ //verificamos si la lista esta vacia
      return NULL;
    }
    else{
      struct node* curr = *list;
      while (curr != NULL){
        if(curr->character == character){
          return curr;
        }
        curr = curr->next; //como nuestra nueva froma de hacer i++;
      }
      return NULL;
    }
}


// Definir la función addSortedNewNodeInLevel que agrega un nuevo nodo en orden alfabetico a la lista
struct node* addSortedNewNodeInLevel(struct node** list, char character) {
    struct node* curr = *list;
    
    // Verificar si el carácter ya está en la lista
    while (curr != NULL) {
        if (curr->character == character) {
            // Carácter ya existe, no se agrega
            return *list;
        }
        curr = curr->next;
    }

    // Crear el nuevo nodo ya que el carácter no está duplicado
    struct node* newNode = nodeNew(character);

    // Si la lista está vacía o el nuevo carácter debería estar al principio
    if (*list == NULL || (*list)->character > character) {
        newNode->next = *list;
        *list = newNode;
    } 
    else {
        curr = *list;
        // Buscar la posición correcta para el nuevo nodo
        while (curr->next != NULL && curr->next->character < character) {
            curr = curr->next;
        }
        
        // Insertar el nuevo nodo en su posición ordenada
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

