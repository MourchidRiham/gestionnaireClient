#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100

typedef struct {
    char nom[50];
    char adresse[100];
    char telephone[15];
    char ville[50];
    char codePostal[20];
    char pays[50];
} Client;

int nbClients = 0;
Client listeClients[MAX_CLIENTS];

int nombreClients = 0;
int choixMenu = 0;
int numeroClient = 0;
char nouveauNom[50];
char nouvelleAdresse[100];
char nouveauTelephone[15];
char nouvelleVille[50];
char nouveauCodePostal[20];
char nouveauPays[50];

void ajouterClient() {
    if (nbClients >= MAX_CLIENTS) {
        printf("La liste des clients est pleine. Impossible d'ajouter un nouveau client.\n");
        return;
    }

    printf("Nom du client : ");
    scanf("%s", listeClients[nbClients].nom);

    printf("Adresse du client : ");
    scanf("%s", listeClients[nbClients].adresse);

    printf("Numéro de téléphone du client : ");
    scanf("%s", listeClients[nbClients].telephone);

    printf("Ville du client : ");
    scanf("%s", listeClients[nbClients].ville);

    printf("Code postal du client : ");
    scanf("%s", listeClients[nbClients].codePostal);

    printf("Pays du client : ");
    scanf("%s", listeClients[nbClients].pays);

    nbClients++;

    printf("Le client a été ajouté avec succès.\n");
}

void afficherClients() {
    printf("Liste des clients :\n");

    for (int i = 0; i < nbClients; i++) {
        printf("Client %d :\n", i + 1);
        printf("Nom : %s\n", listeClients[i].nom);
        printf("Adresse : %s\n", listeClients[i].adresse);
        printf("Téléphone : %s\n", listeClients[i].telephone);
        printf("Ville : %s\n", listeClients[i].ville);
        printf("Code postal : %s\n", listeClients[i].codePostal);
        printf("Pays : %s\n", listeClients[i].pays);
        printf("\n");
    }
}

void modifierClient() {
    printf("Entrez le numéro du client à modifier : ");
    scanf("%d", &numeroClient);
    numeroClient--;

    if (numeroClient < 0 || numeroClient >= nbClients) {
        printf("Numéro de client invalide.\n");
        return;
    }

    int choixModification;

    printf("Qu'est-ce que vous voulez modifier pour ce client ?\n");
    printf("1. Numéro de téléphone\n");
    printf("2. Adresse\n");
    printf("3. Code postal\n");
    printf("4. Ville\n");
    printf("5. Modifier tous les éléments\n");
    printf("Votre choix : ");
    scanf("%d", &choixModification);

    switch (choixModification) {
    case 1:
        printf("Nouveau numéro de téléphone du client : ");
        scanf("%s", nouveauTelephone);
        strcpy(listeClients[numeroClient].telephone, nouveauTelephone);
        break;
    case 2:
        printf("Nouvelle adresse du client : ");
        scanf("%s", nouvelleAdresse);
        strcpy(listeClients[numeroClient].adresse, nouvelleAdresse);
        break;
    case 3:
        printf("Nouveau code postal du client : ");
        scanf("%s", nouveauCodePostal);
        strcpy(listeClients[numeroClient].codePostal, nouveauCodePostal);
        break;
    case 4:
        printf("Nouvelle ville du client : ");
        scanf("%s", nouvelleVille);
        strcpy(listeClients[numeroClient].ville, nouvelleVille);
        break;
    case 5:
        printf("Nouveau numéro de téléphone du client : ");
        scanf("%s", nouveauTelephone);
        strcpy(listeClients[numeroClient].telephone, nouveauTelephone);

        printf("Nouvelle adresse du client : ");
        scanf("%s", nouvelleAdresse);
        strcpy(listeClients[numeroClient].adresse, nouvelleAdresse);

        printf("Nouveau code postal du client : ");
        scanf("%s", nouveauCodePostal);
        strcpy(listeClients[numeroClient].codePostal, nouveauCodePostal);

        printf("Nouvelle ville du client : ");
        scanf("%s", nouvelleVille);
        strcpy(listeClients[numeroClient].ville, nouvelleVille);
        break;
    default:
        printf("Choix invalide.\n");
        return;
    }

    printf("Le client a été modifié avec succès.\n");
}


void supprimerClient() {
    printf("Entrez le numéro du client à supprimer : ");
    scanf("%d", &numeroClient);
    numeroClient--;

    if (numeroClient < 0 || numeroClient >= nbClients) {
        printf("Numéro de client invalide.\n");
        return;
    }

    for (int i = numeroClient; i < nbClients - 1; i++) {
        strcpy(listeClients[i].nom, listeClients[i + 1].nom);
        strcpy(listeClients[i].adresse, listeClients[i + 1].adresse);
        strcpy(listeClients[i].telephone, listeClients[i + 1].telephone);
        strcpy(listeClients[i].ville, listeClients[i + 1].ville);
        strcpy(listeClients[i].codePostal, listeClients[i + 1].codePostal);
        strcpy(listeClients[i].pays, listeClients[i + 1].pays);
    }

    nbClients--;

    printf("Le client a été supprimé avec succès.\n");
}

int main() {

    do {
        printf("Gestionnaire de clients - Menu :\n");
        printf("1. Ajouter un client\n");
        printf("2. Afficher tous les clients\n");
        printf("3. Modifier un client\n");
        printf("4. Supprimer un client\n");
        printf("5. Quitter\n");

        printf("Votre choix : ");
        scanf("%d", &choixMenu);

        switch (choixMenu) {
        case 1:
            ajouterClient();
            break;
        case 2:
            afficherClients();
            break;
        case 3:
            modifierClient();
            break;
        case 4:
            supprimerClient();
            break;
        case 5:
            printf("Merci d'avoir utilisé le gestionnaire de clients.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }

        printf("\n");
    } while (choixMenu != 5);

    return 0;
}
