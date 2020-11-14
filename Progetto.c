#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int main(){
  char codice_scelto[128];
  char stringa[128];
  time_t t;
  printf("\nInserire codice da cifrare minore o uguale di 128\n");              //Chiedo di inserire un codice a scelta da cifrare
  fgets(codice_scelto, 128, stdin);
  while(getchar()!='\n');


  printf("\nScegliere l'opzione: \n");
  printf("\n1. Stringa scelta dall'utente \n");                                 //Do la scelta all'utente se inserire una stringa di cifratura
  printf("\n2. Stringa scelta casualmente \n");                                 //O usarne una random
  printf("Scelta: ");
  int a;
  scanf("%d", &a);
  while(getchar()!='\n');
  switch (a){
    case 1:
      printf("\nSceglierai tu la stringa.\n");                                  //Qui si sceglie la stringa
      printf("Inserisci chiave da cifratura:\n");
      fgets(stringa, 128, stdin);
      break;

    case 2:
      printf("\nLa stringa sarà casuale.\n");                                   //Qui viene data in modo casuale
      srand((unsigned)time(&t));
      for(int i=0; i<strlen(codice_scelto); i++){
         stringa[i]=rand()%(127+1-32)+32;
      }
      printf("%s\n", stringa);
      break;

    default:
      printf("\nNon hai usato nessuna stringa.\n");                             // Qui vengono negate altre scelte oltre le 2 proposte
      return -1;
      break;
  }

  printf("\nStringa cifrata:\n");                                               //Viene cifrato il proprio codice e mostrato
  char cifrato[128];
  for(int i=0; i<strlen(codice_scelto); i++){
     cifrato[i]=codice_scelto[i]^stringa[i];
  }
  printf("%s", cifrato);

  printf("\nCodice originario:\n");                                             //Si ritorna a mostrare il codice originario
  char originario[128];
  for(int i=0; i<strlen(cifrato); i++){
     originario[i]=cifrato[i]^stringa[i];
  }
  printf("%s", originario);
}
