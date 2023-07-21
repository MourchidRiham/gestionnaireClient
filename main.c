#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define MAX_FLEURS 100

typedef struct {
    int id;
    char nom[50];
    char couleur[20];
    float prix;
    int disponibilite;
} Fleur;

typedef struct {
    char nom[50];
    char adresse[100];
    char telephone[15];
} Client;

int nbClients = 0;
Client listeClients[MAX_CLIENTS];

int nbFleurs = 0;
Fleur listeFleurs[MAX_FLEURS];

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

    nbClients++;

    printf("Le client a été ajouté avec succès.\n");
}

void afficherClients() {
    printf("Liste des clients :\n");

    for (int i = 0; i < nbClients; i++) {
        printf("Client %d :\n", i + 1);
        printf("Nom : %s\n", listeClients[i].nom);
        printf("Adresse : %s\n", listeClients[i].adresse);
        printf("Téléphone : %s\n\n", listeClients[i].telephone);
    }
}

void modifierClient() {
    int numeroClient;

    printf("Entrez le numéro du client à modifier : ");
    scanf("%d", &numeroClient);
    numeroClient--;

    if (numeroClient < 0 || numeroClient >= nbClients) {
        printf("Numéro de client invalide.\n");
        return;
    }

    char nouveauTelephone[15];
    char nouvelleAdresse[100];

    printf("Nouveau numéro de téléphone du client : ");
    scanf("%s", nouveauTelephone);
    strcpy(listeClients[numeroClient].telephone, nouveauTelephone);

    printf("Nouvelle adresse du client : ");
    scanf("%s", nouvelleAdresse);
    strcpy(listeClients[numeroClient].adresse, nouvelleAdresse);

    printf("Le client a été modifié avec succès.\n");
}

void supprimerClient() {
    int numeroClient;

    printf("Entrez le numéro du client à supprimer : ");
    scanf("%d", &numeroClient);
    numeroClient--;

    if (numeroClient < 0 || numeroClient >= nbClients) {
        printf("Numéro de client invalide.\n");
        return;
    }

    for (int i = numeroClient; i < nbClients - 1; i++) {
        listeClients[i] = listeClients[i + 1];
    }

    nbClients--;

    printf("Le client a été supprimé avec succès.\n");
}

void ajouterFleur() {
    if (nbFleurs >= MAX_FLEURS) {
        printf("La liste des fleurs est pleine. Impossible d'ajouter une nouvelle fleur.\n");
        return;
    }

    printf("ID de la fleur : ");
    scanf("%d", &listeFleurs[nbFleurs].id);

    printf("Nom de la fleur : ");
    scanf("%s", listeFleurs[nbFleurs].nom);

    printf("Couleur de la fleur : ");
    scanf("%s", listeFleurs[nbFleurs].couleur);

    printf("Prix de la fleur : ");
    scanf("%f", &listeFleurs[nbFleurs].prix);

    printf("Disponibilité de la fleur en magasin (0 - Indisponible, 1 - Disponible) : ");
    scanf("%d", &listeFleurs[nbFleurs].disponibilite);

    nbFleurs++;

    printf("La fleur a été ajoutée avec succès.\n");
}

void afficherFleurs() {
    printf("Liste des fleurs :\n");

    for (int i = 0; i < nbFleurs; i++) {
        printf("Fleur %d :\n", i + 1);
        printf("ID : %d\n", listeFleurs[i].id);
        printf("Nom : %s\n", listeFleurs[i].nom);
        printf("Couleur : %s\n", listeFleurs[i].couleur);
        printf("Prix : %.2f\n", listeFleurs[i].prix);
        printf("Disponibilité : %s\n\n", listeFleurs[i].disponibilite ? "Disponible" : "Indisponible");
    }
}

void modifierFleur() {
    int numeroFleur;

    printf("Entrez le numéro de la fleur à modifier : ");
    scanf("%d", &numeroFleur);
    numeroFleur--;

    if (numeroFleur < 0 || numeroFleur >= nbFleurs) {
        printf("Numéro de fleur invalide.\n");
        return;
    }

    int choix;
    printf("Que voulez-vous modifier ?\n");
    printf("1. Nom\n");
    printf("2. Couleur\n");
    printf("3. Prix\n");
    printf("4. Disponibilité\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        printf("Nouveau nom de la fleur : ");
        scanf("%s", listeFleurs[numeroFleur].nom);
        break;
    case 2:
        printf("Nouvelle couleur de la fleur : ");
        scanf("%s", listeFleurs[numeroFleur].couleur);
        break;
    case 3:
        printf("Nouveau prix de la fleur : ");
        scanf("%f", &listeFleurs[numeroFleur].prix);
        break;
    case 4:
        printf("Nouvelle disponibilité de la fleur (0 - Indisponible, 1 - Disponible) : ");
        scanf("%d", &listeFleurs[numeroFleur].disponibilite);
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }

    printf("La fleur a été modifiée avec succès.\n");
}

int main() {
    int choix;

    do {
        printf("Gestionnaire de clients et de fleurs - Menu :\n");
        printf("1. Ajouter un client\n");
        printf("2. Afficher tous les clients\n");
        printf("3. Modifier un client\n");
        printf("4. Supprimer un client\n");
        printf("5. Ajouter une fleur\n");
        printf("6. Afficher toutes les fleurs\n");
        printf("7. Modifier une fleur\n");
        printf("8. Quitter\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
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
            ajouterFleur();
            break;
        case 6:
            afficherFleurs();
            break;
        case 7:
            modifierFleur();
            break;
        case 8:
            printf("Merci d'avoir utilisé le gestionnaire de clients et de fleurs.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }

        printf("\n");
    } while (choix != 8);

    return 0;
}
