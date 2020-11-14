#include <stdio.h>
#include <stdlib.h>   // rand() / srand()
#include <time.h>     // time()
#include <string.h>   // libreria stringhe

#define MAXCHAR 128  // costante pari a 128

int main() {

    FILE *f;
    f = fopen("file.txt" , "w");  // Apertura file (w = write)
    printf("Apertura del file effettuata.");
    if(f == NULL) {
       perror("Errore nell'apertura del file");
       return(-1);
     }

     int i = 0;    // index

     time_t t;                    // seed random
     srand((unsigned)time(&t));   // generatore numero random

     char M[MAXCHAR] = "";   // array contenente la stringa
     int dim_M = 0;          // dimensione della stringa


     printf("\n----------------------");
     printf("\nInserire la stringa di testo da cifrare. (max 128 caratteri):");
     printf("\nScelta:");
     fgets(M, MAXCHAR+2, stdin); // ne aggiungo 2 per lo '\0' di fine stringa
     fputs(M, f);
     printf("----------------------");
     dim_M = strlen(M)-1;       // cancello il carattere '\0' di fine stringa
     printf("\nLa stringa inserita è di lunghezza: %d", dim_M);

     printf("\n----------------------");
     //menù
     printf("\nScegliere cosa fare:");
     printf("\n----------------------");
     printf("\n1 - Prima scelta");
     printf("\n2 - Seconda scelta");
     printf("\n----------------------");
     printf("\nScelta: ");

     int s = 0;            // variabile scelta
     scanf("%d", &s );    // input scelta
     printf("----------------------");

     char key[MAXCHAR] = "";  // array contenente la seconda stringa

     int dim_key = 0;            // dimensione della seconda stringa

     // Scelta con else if
     if(s==1){   // Punto 1: Scelta manuale
             fflush(stdin);
           do{
             printf("\nInserire una seconda stringa di lunghezza uguale o superiore alla prima (max 128 caratteri): ");
             printf("\nScelta: ");
             fgets(key, MAXCHAR+2, stdin);   // fgets
             printf("----------------------");
             dim_key = strlen(key)-1;        // cancello il carattere '/0' di fine stringa
             printf("\nLa stringa inserita è di lunghezza: %d", dim_key);

             if(dim_key > MAXCHAR || dim_key < dim_M)
                 printf("\nErrore. Deve contenere un massimo di 128 caratteri o essere più grande della prima.\n");
             else
                 printf("\nDimensione accettata.");

          } while(dim_key > MAXCHAR || dim_key < dim_M);
     } else if (s==2){      //Punto 2: Scelta random
             srand((unsigned)time(NULL));
             for ( i = 0; i < dim_M; ++i)
                 key[i] = rand() %128; // genero un numero fra 0 e 127
             printf("\nLa chiave generata è: %s", key);
     } else {
           printf("Errore di input\n");
           fclose(f);
           system("PAUSE");
           return 0;
     }

     //Calcolo XOR
     printf("\n----------------------");
     char output[MAXCHAR] = "";       // array che otterrà l'output finale

     for(i=0; i<dim_M; i++) {
         char xor = M[i] ^ key[i];   // calcolo lo xor dello i-esimo elemento
         output[i] = xor;           // salvo il carattere codificato nell'array di output
     }

     printf("\nLa stringa codificata è : %s", output);
     printf("\n----------------------");

     //Procedimento inverso per ottenere la stringa finale
     char ver[MAXCHAR] = "";   // array che conterrà l'output di verifica

     for(i=0; i<dim_M; i++) {
         char xor = output[i] ^ key[i];
         ver[i] = xor;
     }

     printf("\nLa stringa iniziale è : %s", ver);

     //Controllo che la verifica sia corretta e quindi sia uguale ad M
     printf("\n----------------------");
     int check = memcmp(M, ver, dim_M);
     if(!check)
        printf("\nVerifica esatta");
     else
        printf("\nVerifica sbagliata");

     printf("\n----------------------");
     fclose(f);
     printf("\nFile chiuso con successo\n");
     system("PAUSE");
     return 0;

}
