#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Contatto {
    char nome[30];
    char cognome[30];
    char telefono[15];
};

int main(void) {
    struct Contatto rubrica[100];
    char scelta;
    bool exit = true;
    do {
        system("clear");
        printf("Benvenuto nella tua rubrica! Scegli l'opzione che più si addice alle tue esigenze:");
        printf("\n1. Aggiungi contatto");
        printf("\n2. Visualizza tutti i contatti");
        printf("\n3. Ricerca contatto per cognome");
        printf("\n4. Elimina contatto per cognome");
        printf("\n5. Esci");
        scanf("%1c", &scelta);
        switch (scelta) {
            case '1':
                system("clear");
                AggiungiContatto();
                break;
            case '2':
                system("clear");
                VisualizzaContatti();
                break;
            case '3':
                system("clear");
                RicercaContatto();
                break;
            case '4':
                system("clear");
                EliminaContatto();
                break;
            case '5':
                system("clear");
                !exit;
                break;
            default:
                system("clear");
                printf("Scelta non presente nell'elenco, riprova...");
                getchar();
        }
    } while (exit);
    system("clear");
    printf("\nArrivederci!");
}