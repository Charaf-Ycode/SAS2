#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MX 100
#define MXP 5
typedef struct
{
    int ClientID;
    char nom[MX];
    char prenom[MX];
    char email[MX];
    float solde;
} client;
typedef struct
{
    int produitID;
    char nomp[MX];
    char categorie[MX];
    float prix;
    int stock;
    char description[MX];

} produit;
client clients;
produit produits[MXP] = {
    {1, "Ordinateur Portable", "electronique", 799.0, 5, "pc avec batterie"},
    {2, "Smartphone", "electronique", 499.0, 10, "Telephone fiable "},
    {3, "Casque Audio", "Accessoire", 89.0, 15, "Casque sans fil "},
    {4, "Souris", "Accessoire", 25.0, 20, "Souris 1000dpi"},
    {5, "Clavier", "Accessoire", 45.0, 12, "Clavier brown switch"}};
int profcree = 0;
void creer_un_profil()
{
    if (profcree)
    {
        printf("Profil Deja cree.\n");
        return;
    }
    clients.ClientID = 1;
    printf("Saisie Votre Nom:");
    fgets(clients.nom, MX, stdin);

    printf("Saisie Votre Prenom:");
    fgets(clients.prenom, MX, stdin);

    sprintf(clients.email, "%s.%s@gmail.com", clients.nom, clients.prenom);
    clients.solde = 0;
    profcree = 1;
}
void consuter_profil()
{
if(!profcree){
    printf("Aucun Profil est cree");
    return;
}
printf("\n==========Votre Profil===========\n");
printf("Votre Id:%d\n",clients.ClientID);
printf("Le Nom:%s\n",clients.nom);
printf("Le Prenom:%s\n",clients.prenom);
printf("L'email:%s\n",clients.email);
printf("Le Solde:%f\n",clients.solde);

}
void modifier_un_profil()
{
}
void consulter_le_solde()
{
}
void deposer_le_solde()
{
}
void afficher_les_prd()
{
}
void tri_les_prd()
{
}
void achat_prd()
{
}
int main()
{
    int choix;
    do
    {
        printf("\n===========MENU===========\n");
        printf("1. Gestion du profil client\n");
        printf("2. Gestion du solde virtuel\n");
        printf("3. Consultation des produits\n");
        printf("4. Effectuer un achat\n");
        printf("5. Mes statistiques\n");
        printf("0. Quitter\n");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
        case 1:
        {
            int choix2;
            printf("\n=========Gestion de Client==========\n");
            printf("1. creer un Profil\n");
            printf("2. Consulter le Profil\n");
            printf("3. Modifier le Profil\n");
            printf("4. Generer Un Email\n");
            scanf("%d", &choix2);
            getchar();
            switch (choix2)
            {
            case 1:
                creer_un_profil();
                break;
            case 2:
                consuter_profil();
                break;
            case 3:
                modifier_un_profil();
                break;
            default:
                printf("Choix Invalide\n");
            }
            break;
        }
        break;
        case 2:
        {
            int choix3;
            printf("\n==========Gestion du Solde=========\n");
            printf("1. Consulter Votre Solde\n");
            printf("2. Deposer Votre Argents\n");
            scanf("%d", &choix3);
            switch (choix3)
            {
            case 1:
                consulter_le_solde();
                break;
            case 2:
                deposer_le_solde();
                break;

            default:
                printf("Choix Invalide\n");
            }
            break;
        }
        break;
        case 3:
            tri_les_prd();
            afficher_les_prd();
            break;
        case 4:
            achat_prd();
            break;
        case 0:
            printf("Au Revoir\n");
            break;

        default:
            printf("Choix Invalide\n");
            break;
        }

    } while (choix != 0);

    return 0;
}
