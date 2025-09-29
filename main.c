#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Contatto {
    char nome[30];
    char cognome[30];
    char telefono[15];
};

struct Contatto rubrica[100];
int indice = 0;

int AggiungiContatto() {
    if (indice >= 100) {
        printf("\nSpazio esaurito, non posso più aggiungere contatti.");
    } else {
        printf("\nInserisci il nome del contatto da salvare:\n");
        scanf("%29s", rubrica[indice].nome);
        printf("\nOra inserisci il cognome del contatto da salvare:\n");
        scanf("%29s", rubrica[indice].cognome);
        printf("\nInfine inserisci il numero di telefono del contatto da salvare:\n");
        scanf("%14s", rubrica[indice].telefono);
        printf("Contatto aggiunto correttamente.");
        indice++;
    }
    printf("\n\nPremi Invio per tornare al menù principale...");
    getchar();
    return indice;
}

void VisualizzaContatti() {
    for (int i = 0; i < indice; i++) {
        printf("Nome: %s\n", rubrica[i].nome);
        printf("Cognome: %s\n", rubrica[i].cognome);
        printf("Telefono: %s\n", rubrica[i].telefono);
        printf("\n");
    }
}

int main(void) {
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
                indice = AggiungiContatto();
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
                printf("Scelta non presente nell'elenco, premi Invio per riprovare...");
                getchar();
        }
    } while (exit);
    system("clear");
    printf("\nArrivederci!");
}