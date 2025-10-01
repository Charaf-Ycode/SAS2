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
    clients.nom[strcspn(clients.nom, "\n")] = '\0';
    printf("Saisie Votre Prenom:");
    fgets(clients.prenom, MX, stdin);
    clients.prenom[strcspn(clients.prenom, "\n")] = '\0';

    sprintf(clients.email, "%s.%s@gmail.com", clients.nom, clients.prenom);
    clients.solde = 0;
    profcree = 1;
}
void consuter_profil()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    printf("\n==========Votre Profil===========\n");
    printf("Votre Id:%d\n", clients.ClientID);
    printf("Le Nom:%s\n", clients.nom);
    printf("Le Prenom:%s\n", clients.prenom);
    printf("L'email:%s\n", clients.email);
    printf("Le Solde:%fMAD\n", clients.solde);
}
void modifier_un_profil()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    printf("Modifier Le Nom:");
    fgets(clients.nom, MX, stdin);
    printf("Modifier Le Prenom");
    fgets(clients.prenom, MX, stdin);
    sprintf(clients.email, "%s.%s@email.com", clients.nom, clients.prenom);
    printf("Profil est Modifier\n");
}
void generer_email()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    sprintf(clients.email, "%s.%s@email.com", clients.nom, clients.prenom);
}
void consulter_le_solde()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    printf("Votre Solde:%.2f", clients.solde);
}
void deposer_le_solde()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    float argent;
    printf("Saisie Le Montant A deposer:");
    scanf("%f", &argent);
    getchar();
    clients.solde += argent;
    printf("Votre Nouveau Solde:%.2fMAD\n", clients.solde);
}
void afficher_les_prd()
{
    printf("\n==========Catalogue=========\n");
    for (int i = 0; i < MXP; i++)
    {
        printf("======>IdProduit:%d-%s-%s-%.2f-%dDescription:%s.\n", produits[i].produitID, produits[i].nomp, produits[i].categorie, produits[i].prix, produits[i].stock, produits[i].description);
    }
}
void tri_les_prd()
{
    for (int i = 0; i < MXP - 1; i++)
    {
        for (int j = 0; j < MXP - i - 1; j++)
        {
            if (produits[j].prix > produits[j + 1].prix)
            {
                produit cmp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = cmp;
            }
        }
    }
    printf("Les produits trie par croissant\n");
}
void achat_prd()
{
    if (!profcree)
    {
        printf("Aucun Profil est cree");
        return;
    }
    int choix;
    afficher_les_prd();
    printf("Saisie un produit nom:");
    scanf("%d", &choix);
    getchar();
    int trouve;
    for (int i; i < MXP; i++)
    {
        if (produits[i].produitID == choix)
        {
            trouve = 1;
            if (produits[i].stock <= 0)
            {
                printf("le produit %s rupture de stock\n", produits[i].nomp);
                return;
            }
            if (clients.solde < produits[i].prix)
            {
                printf("solde insuffisant pour acheter %s votre sold est: %.2f", produits[i].nomp, produits[i].prix);
                return;
            }
            clients.solde -= produits[i].prix;
            produits[i].stock--;
            printf("Achat Reussi Votre Nouveau Solde est:%.2f", clients.solde);
            return;
        }
    }
    if (!trouve)
    {
        printf("Produit %d introuvable", &choix);
    }
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
            case 4:
                generer_email();
                printf("Email:%s\n", clients.email);
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
