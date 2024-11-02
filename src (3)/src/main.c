#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void predictAndPrintAll(struct keysPredict* kt, char* partialWord ) {
    char** words;
    int wordsCount;
    words = keysPredictRun(kt, partialWord, &wordsCount);
    printf("Predicts: %s = ", partialWord);
    for(int i=0; i<wordsCount; i++) {
        printf("%s,", words[i]);
    }
    printf("\n");
    deleteArrayOfWords(words, wordsCount);
}

void findAndPrintAll(struct keysPredict* kt, char* word ) {
    struct node* result = keysPredictFind(kt, word);
    printf("Find: %s = %i\n", word, result==0);
}

int main() {
    // ---------strLen
    int len = strLen("hola");
    printf("strDup(\"hola\") -> \"%i\"\n", len);
    printf("\n");

    // strDup
    char* dup = strDup("hola");
    printf("strDup(\"hola\") -> \"%s\"\n", dup);
    free(dup);
    printf("\n");

    // keysPredict
    struct keysPredict* kt = keysPredictNew();
    
    // keysPredict - crear un diccionario
    keysPredictAddWord(kt, "papanatas");
    keysPredictAddWord(kt, "zanahoria");
    keysPredictAddWord(kt, "oreja");
    keysPredictAddWord(kt, "ricardo");
    keysPredictAddWord(kt, "zaz");
    keysPredictAddWord(kt, "a");
    keysPredictAddWord(kt, "");
    keysPredictAddWord(kt, "b");
    keysPredictAddWord(kt, "ab");
    keysPredictAddWord(kt, "abfff");
    keysPredictAddWord(kt, "abfgato");
    keysPredictAddWord(kt, "bebe");
    keysPredictAddWord(kt, "pata");
    keysPredictPrint(kt);

    // keysPredict - listar todas las palabras
    char** words;
    int wordsCount;
    words = keysPredictListAll(kt, &wordsCount);
    for(int i=0; i<wordsCount; i++) {
        printf("%s\n", words[i]);
    }
    deleteArrayOfWords(words, wordsCount);

    // keysPredict - encontrar palabras
    findAndPrintAll(kt, "papa");
    findAndPrintAll(kt, "pata");
    findAndPrintAll(kt, "a");
    findAndPrintAll(kt, "zazz");

    // keysPredict - predecir palabras
    predictAndPrintAll(kt,"or");
    predictAndPrintAll(kt,"ab");
    predictAndPrintAll(kt,"pa");
    predictAndPrintAll(kt,"pap");
    predictAndPrintAll(kt,"q");
    predictAndPrintAll(kt,"zap");

    // keysPredict - predecir palabras
    keysPredictRemoveWord(kt,"");
    keysPredictRemoveWord(kt,"zaz");
    keysPredictRemoveWord(kt,"aaa");
    keysPredictRemoveWord(kt,"papa");
    keysPredictRemoveWord(kt,"pata");
    keysPredictPrint(kt);

    // keysPredict - borrar diccionario
    keysPredictDelete(kt);

    return 0;
}

int main(){

//-----------------------------strLen (ANDA)
    // strLen vacio (ANDA)
    int len = strLen("");
    printf("strLen(\"\") -> \"%i\"\n", len);
    printf("\n");

    // strLen de un solo caracter (ANDA)
    int len = strLen("h");
    printf("strLen(\"h\") -> \"%i\"\n", len);
    printf("\n");

    // strLen de todos los caracteres alfanuméricos (ANDA)
    int len = strLen("qwertyuiopasdfghjklzxcvbnm1234567890");
    printf("strLen(\"qwertyuiopasdfghjklzxcvbnm1234567890\") -> \"%i\"\n", len);
    printf("\n");

//-----------------------------strDup (ANDA)
    // strDup vacio (ANDA)
    char* dup = strDup("");
    printf("strDup(\"\") -> \"%s\"\n", dup);
    free(dup);
    printf("\n");

    // strDup de solo un caracter (ANDA)
    char* dup2 = strDup("h");
    printf("strDup(\"h\") -> \"%s\"\n", dup2);
    free(dup2);
    printf("\n");

    // strDup de todos los caracteres alfanumericos (ANDA)
    char* dup3 = strDup("qwertyuiopasdfghjklzxcvbnm1234567890");
    printf("strDup(\"qwertyuiopasdfghjklzxcvbnm1234567890\") -> \"%s\"\n", dup3);
    free(dup3);
    printf("\n");


// -----------------------------keysPredict / casos chicos
    struct keysPredict* kt = keysPredictNew();
    
    // keysPredict - crear un diccionario chico, borrar y agregar palabras, predecir
    //creamos y printeamos (ANDA)
    keysPredictAddWord(kt, "tal");
    keysPredictAddWord(kt, "hola");
    keysPredictAddWord(kt, "holis");
    keysPredictAddWord(kt, "tales");
    keysPredictAddWord(kt, "talento");
    keysPredictAddWord(kt, "holitas");
    keysPredictAddWord(kt, "cerro");

    // keysPredict - listar todas las palabras
    char** words;
    int wordsCount;
    words = keysPredictListAll(kt, &wordsCount);
    for(int i=0; i<wordsCount; i++) {
        printf("%s\n", words[i]);
    }
    deleteArrayOfWords(words, wordsCount);

    // keysPredict - encontrar palabras
    findAndPrintAll(kt, "tal");
    findAndPrintAll(kt, "tales");
    findAndPrintAll(kt, "cerro");

    // keysPredict - predecir palabras
    predictAndPrintAll(kt,"ho");
    predictAndPrintAll(kt,"ta");

    //borramos algunas palabras (ANDA)
    keysPredictRemoveWord(kt, "hola");
    keysPredictRemoveWord(kt, "holis");
    keysPredictPrint(kt);

    // keysPredict - borrar diccionario
    keysPredictDelete(kt);

// -----------------------------keysPredict / casos grandes

    struct keysPredict* kt2 = keysPredictNew();
    
    // keysPredict - crear un diccionario con 100 palabras, borrar la mitad, predecir todas las combinaciones posibles de prefijos dos letras
    keysPredictAddWord(kt2, "alfajor");
    keysPredictAddWord(kt2, "canoa");
    keysPredictAddWord(kt2, "rinoceronte");
    keysPredictAddWord(kt2, "casa");
    keysPredictAddWord(kt2, "rino");
    keysPredictAddWord(kt2, "perro");
    keysPredictAddWord(kt2, "gato");
    keysPredictAddWord(kt2, "mesa");
    keysPredictAddWord(kt2, "silla");
    keysPredictAddWord(kt2, "arbol");
    keysPredictAddWord(kt2, "casa");
    keysPredictAddWord(kt2, "pelota");
    keysPredictAddWord(kt2, "auto");
    keysPredictAddWord(kt2, "luna");
    keysPredictAddWord(kt2, "sol");
    keysPredictAddWord(kt2, "estrella");
    keysPredictAddWord(kt2, "flor");
    keysPredictAddWord(kt2, "rio");
    keysPredictAddWord(kt2, "montana");
    keysPredictAddWord(kt2, "nube");
    keysPredictAddWord(kt2, "puerta");
    keysPredictAddWord(kt2, "ventana");
    keysPredictAddWord(kt2, "lapiz");
    keysPredictAddWord(kt2, "libro");
    keysPredictAddWord(kt2, "telefono");
    keysPredictAddWord(kt2, "computadora");
    keysPredictAddWord(kt2, "zapato");
    keysPredictAddWord(kt2, "camisa");
    keysPredictAddWord(kt2, "pantalon");
    keysPredictAddWord(kt2, "chaqueta");
    keysPredictAddWord(kt2, "calcetin");
    keysPredictAddWord(kt2, "jardin");
    keysPredictAddWord(kt2, "ciudad");
    keysPredictAddWord(kt2, "pueblo");
    keysPredictAddWord(kt2, "playa");
    keysPredictAddWord(kt2, "mar");
    keysPredictAddWord(kt2, "cielo");
    keysPredictAddWord(kt2, "coche");
    keysPredictAddWord(kt2, "moto");
    keysPredictAddWord(kt2, "bicicleta");
    keysPredictAddWord(kt2, "tren");
    keysPredictAddWord(kt2, "avion");
    keysPredictAddWord(kt2, "barco");
    keysPredictAddWord(kt2, "caminata");
    keysPredictAddWord(kt2, "juego");
    keysPredictAddWord(kt2, "diversion");
    keysPredictAddWord(kt2, "vacaciones");
    keysPredictAddWord(kt2, "fiesta");
    keysPredictAddWord(kt2, "familia");
    keysPredictAddWord(kt2, "amigos");
    keysPredictAddWord(kt2, "cultura");
    keysPredictAddWord(kt2, "arte");
    keysPredictAddWord(kt2, "musica");
    keysPredictAddWord(kt2, "danza");
    keysPredictAddWord(kt2, "teatro");
    keysPredictAddWord(kt2, "pelicula");
    keysPredictAddWord(kt2, "serie");
    keysPredictAddWord(kt2, "documental");
    keysPredictAddWord(kt2, "foto");
    keysPredictAddWord(kt2, "video");
    keysPredictAddWord(kt2, "espectaculo");
    keysPredictAddWord(kt2, "evento");
    keysPredictAddWord(kt2, "reunion");
    keysPredictAddWord(kt2, "concierto");
    keysPredictAddWord(kt2, "taller");
    keysPredictAddWord(kt2, "curso");
    keysPredictAddWord(kt2, "clase");
    keysPredictAddWord(kt2, "charla");
    keysPredictAddWord(kt2, "seminario");
    keysPredictAddWord(kt2, "conferencia");
    keysPredictAddWord(kt2, "universidad");
    keysPredictAddWord(kt2, "escuela");
    keysPredictAddWord(kt2, "colegio");
    keysPredictAddWord(kt2, "educacion");
    keysPredictAddWord(kt2, "conocimiento");
    keysPredictAddWord(kt2, "sabiduria");
    keysPredictAddWord(kt2, "esfuerzo");
    keysPredictAddWord(kt2, "trabajo");
    keysPredictAddWord(kt2, "exito");
    keysPredictAddWord(kt2, "meta");
    keysPredictAddWord(kt2, "objetivo");
    keysPredictAddWord(kt2, "sueno");
    keysPredictAddWord(kt2, "esperanza");
    keysPredictAddWord(kt2, "felicidad");
    keysPredictAddWord(kt2, "amor");
    keysPredictAddWord(kt2, "paz");
    keysPredictAddWord(kt2, "libertad");
    keysPredictAddWord(kt2, "justicia");
    keysPredictAddWord(kt2, "solidaridad");
    keysPredictAddWord(kt2, "respeto");
    keysPredictAddWord(kt2, "honor");
    keysPredictAddWord(kt2, "valores");
    keysPredictAddWord(kt2, "compasion");
    keysPredictAddWord(kt2, "generosidad");
    keysPredictAddWord(kt2, "amistad");
    keysPredictAddWord(kt2, "ditella");
    keysPredictAddWord(kt2, "control");
    keysPredictAddWord(kt2, "almohadon");
    keysPredictAddWord(kt2, "reloj");
    keysPredictAddWord(kt2, "reposera");
    keysPredictAddWord(kt2, "mochila");

    //borrar 50 palabras keysPredictDeleteWord(kt2, "palabra"); 50 veces
    keysPredictRemoveWord(kt2, "alfajor");
    keysPredictRemoveWord(kt2, "rinoceronte");
    keysPredictRemoveWord(kt2, "rino");
    keysPredictRemoveWord(kt2, "gato");
    keysPredictRemoveWord(kt2, "silla");
    keysPredictRemoveWord(kt2, "casa");
    keysPredictRemoveWord(kt2, "auto");
    keysPredictRemoveWord(kt2, "sol");
    keysPredictRemoveWord(kt2, "flor");
    keysPredictRemoveWord(kt2, "montaña");
    keysPredictRemoveWord(kt2, "puerta");
    keysPredictRemoveWord(kt2, "lapiz");
    keysPredictRemoveWord(kt2, "telefono");
    keysPredictRemoveWord(kt2, "zapato");
    keysPredictRemoveWord(kt2, "pantalon");
    keysPredictRemoveWord(kt2, "calcetin");
    keysPredictRemoveWord(kt2, "ciudad");
    keysPredictRemoveWord(kt2, "playa");
    keysPredictRemoveWord(kt2, "cielo");
    keysPredictRemoveWord(kt2, "moto");
    keysPredictRemoveWord(kt2, "tren");
    keysPredictRemoveWord(kt2, "barco");
    keysPredictRemoveWord(kt2, "juego");
    keysPredictRemoveWord(kt2, "vacaciones");
    keysPredictRemoveWord(kt2, "familia");
    keysPredictRemoveWord(kt2, "cultura");
    keysPredictRemoveWord(kt2, "musica");
    keysPredictRemoveWord(kt2, "teatro");
    keysPredictRemoveWord(kt2, "serie");
    keysPredictRemoveWord(kt2, "foto");
    keysPredictRemoveWord(kt2, "espectaculo");
    keysPredictRemoveWord(kt2, "reunion");
    keysPredictRemoveWord(kt2, "taller");
    keysPredictRemoveWord(kt2, "clase");
    keysPredictRemoveWord(kt2, "seminario");
    keysPredictRemoveWord(kt2, "universidad");
    keysPredictRemoveWord(kt2, "colegio");
    keysPredictRemoveWord(kt2, "conocimiento");
    keysPredictRemoveWord(kt2, "esfuerzo");
    keysPredictRemoveWord(kt2, "exito");
    keysPredictRemoveWord(kt2, "objetivo");
    keysPredictRemoveWord(kt2, "esperanza");
    keysPredictRemoveWord(kt2, "amor");
    keysPredictRemoveWord(kt2, "libertad");
    keysPredictRemoveWord(kt2, "solidaridad");
    keysPredictRemoveWord(kt2, "honor");
    keysPredictRemoveWord(kt2, "compasión");
    keysPredictRemoveWord(kt2, "amistad");
    keysPredictRemoveWord(kt2, "control");
    keysPredictRemoveWord(kt2, "reloj");
    keysPredictRemoveWord(kt2, "mochila");

    //contador 
    char s[2] = "aa";
    int puntero=0;
    for (i=0;i<26;i++){
        s[1]="a";
        for (j=0;j<26;j++){
            predictAndPrintAll(kt2, s, &puntero);
            s[1]++;
        }
        s[0]++;
    }

    keysPredictPrint(kt2);

    return 0;
}
