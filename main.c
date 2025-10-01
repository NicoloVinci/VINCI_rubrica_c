#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contatto
{
    char nome[30];
    char cognome[30];
    char telefono[15];
};

struct Contatto rubrica[100];
int indice = 0;

int AggiungiContatto()
{
    if (indice >= 100)
    {
        printf("\nSpazio esaurito, non posso più aggiungere contatti.");
    }
    else
    {
        printf("\nInserisci il nome del contatto da salvare:\n");
        fgets(rubrica[indice].nome, 30, stdin);
        rubrica[indice].nome[strcspn(rubrica[indice].nome, "\n")] = '\0';
        printf("\nOra inserisci il cognome del contatto da salvare:\n");
        fgets(rubrica[indice].cognome, 30, stdin);
        rubrica[indice].cognome[strcspn(rubrica[indice].cognome, "\n")] = '\0';
        printf("\nInfine inserisci il numero di telefono del contatto da salvare:\n");
        fgets(rubrica[indice].telefono, 15, stdin);
        rubrica[indice].telefono[strcspn(rubrica[indice].telefono, "\n")] = '\0';
        printf("\n\nContatto aggiunto correttamente.");
        indice++;
    }
    printf("\n\nPremi Invio per tornare al menù principale...");
    getchar();
    return indice;
}

void VisualizzaContatti()
{
    for (int i = 0; i < indice; i++)
    {
        printf("Nome: %s\n", rubrica[i].nome);
        printf("Cognome: %s\n", rubrica[i].cognome);
        printf("Telefono: %s\n", rubrica[i].telefono);
        printf("\n");
    }
    printf("\n\nPremi Invio per tornare al menù principale...");
    getchar();
}

void RicercaContatto()
{
    char cognomeCerca[30];
    int trovato = 0;
    printf("\nInserisci il cognome del contatto da cercare:\n");
    fgets(cognomeCerca, 30, stdin);
    cognomeCerca[strcspn(cognomeCerca, "\n")] = '\0';
    for (int i = 0; i < indice; i++)
    {
        if (strcmp(rubrica[i].cognome, cognomeCerca) == 0)
        {
            printf("\nContatto trovato, ecco i suoi dati:\n");
            printf("Nome: %s\n", rubrica[i].nome);
            printf("Cognome: %s\n", rubrica[i].cognome);
            printf("Telefono: %s\n", rubrica[i].telefono);
            trovato++;
        }
    }
    if (trovato == 0) {
        printf("\n\nContatto non trovato, premi Invio per tornare al menù principale...");
        getchar();
    } else {
        printf("\n\nPremi Invio per tornare al menù principale...");
        getchar();
    }
}

int EliminaContatto()
{
    char cognomeCerca[30];
    printf("\nInserisci il cognome del contatto da eliminare:\n");
    fgets(cognomeCerca, 30, stdin);
    cognomeCerca[strcspn(cognomeCerca, "\n")] = '\0';
    for (int i = 0; i < indice; i++)
    {
        if (strcmp(rubrica[i].cognome, cognomeCerca) == 0)
        {
            printf("\nContatto eliminato con successo.");
            for (i; i < indice - 1; i++)
            {
                rubrica[i] = rubrica[i + 1];
            }
            indice--;
            printf("\n\nPremi Invio per tornare al menù principale...");
            getchar();
            return indice;
        }
    }
    printf("\n\nContatto non trovato, premi Invio per tornare al menù principale...");
    getchar();
    return indice;
}

int main(void)
{
    char scelta[3];
    bool exit = true;
    do
    {
        system("clear");
        printf("Benvenuto nella tua rubrica! Scegli l'opzione che più si addice alle tue esigenze:");
        printf("\n1. Aggiungi contatto");
        printf("\n2. Visualizza tutti i contatti");
        printf("\n3. Ricerca contatto per cognome");
        printf("\n4. Elimina contatto per cognome");
        printf("\n5. Esci\n\n");
        fgets(scelta, sizeof(scelta), stdin);
        switch (scelta[0])
        {
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
            indice = EliminaContatto();
            break;
        case '5':
            system("clear");
            exit = false;
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