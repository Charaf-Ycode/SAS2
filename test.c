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
    {4, "Souris", "Accessoire", 25.0, 20, "Souris 1000dpi"},
    {1, "Ordinateur Portable", "electronique", 799.0, 5, "pc gamer"},
    {3, "Casque Audio", "Accessoire", 89.0, 15, "Casque sans fil "},
    {2, "Smartphone", "electronique", 499.0, 10, "Telephone fiable "},
    {5, "Clavier", "Accessoire", 45.0, 12, "Clavier brown switch"}};
int profcree = 0;
int total_achat = 0;
float mt_depense = 0;
int aucun_profil()
{
    if (!profcree)
    {
        printf("Aucun profil est cree\n");
        return 1;
    }
    return 0;
}
void creer_un_profil()
{
    if (aucun_profil())
        return;
    clients.ClientID = 1;
    printf("Saisie Votre Nom:");
    fgets(clients.nom, MX, stdin);
    clients.nom[strcspn(clients.nom, "\n")] = '\0';
    printf("Saisie Votre Prenom:");
    fgets(clients.prenom, MX, stdin);
    clients.prenom[strcspn(clients.prenom, "\n")] = '\0';

    sprintf(clients.email, "%s.%s@client.com", clients.nom, clients.prenom);
    clients.solde = 0;
    profcree = 1;
}
void consuter_profil()
{
    if (aucun_profil())
        return;
    printf("\n==========Votre Profil===========\n");
    printf("Votre Id:%d\n", clients.ClientID);
    printf("Le Nom:%s\n", clients.nom);
    printf("Le Prenom:%s\n", clients.prenom);
    printf("L'email:%s\n", clients.email);
    printf("Le Solde:%fMAD\n", clients.solde);
}
void modifier_un_profil()
{
    if (aucun_profil())
        return;
    printf("Modifier Le Nom:");
    fgets(clients.nom, MX, stdin);
    clients.nom[strcspn(clients.nom, "\n")] = '\0';
    printf("Modifier Le Prenom:");
    fgets(clients.prenom, MX, stdin);
    clients.prenom[strcspn(clients.prenom, "\n")] = '\0';
    sprintf(clients.email, "%s.%s@client.com", clients.nom, clients.prenom);
    printf("Profil est Modifier\n");
}
void generer_email()
{
    if (aucun_profil())
        return;
    sprintf(clients.email, "%s.%s@client.com", clients.nom, clients.prenom);
}
void consulter_le_solde()
{
    if (aucun_profil())
        return;
    printf("Votre Solde:%.2f", clients.solde);
}
void deposer_le_solde()
{
    if (aucun_profil())
        return;
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
        printf("======>IdProduit:%d-%s-%s-%.2fMAD-%d Description:%s.\n", produits[i].produitID, produits[i].nomp, produits[i].categorie, produits[i].prix, produits[i].stock, produits[i].description);
    }
}
void tri_les_prd()
{
    for (int i = 0; i < MXP - 1; i++)
    {
        for (int j = 0; j < MXP - i - 1; j++)
        {
            if (produits[j].prix < produits[j + 1].prix)
            {
                produit cmp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = cmp;
            }
        }
    }
    printf("Les produits trie par Decroissant\n");
}
void achat_prd()
{
    if (aucun_profil())
        return;
    char choix[MX];
    afficher_les_prd();
    printf("Saisie un produit nom:");
    fgets(choix, MX, stdin);
    choix[strcspn(choix, "\n")] = '\0';
    int trouve = 0;
    for (int i = 0; i < MXP; i++)
    {
        if (strcasecmp(produits[i].nomp, choix) == 0)
        {
            trouve = 1;
            if (produits[i].stock <= 0)
            {
                printf("le produit %s rupture de stock\n", produits[i].nomp);
                return;
            }
            if (clients.solde < produits[i].prix)
            {
                printf("solde insuffisant pour acheter %s votre sold est: %.2fMAD\n", produits[i].nomp, clients.solde);
                return;
            }
            clients.solde -= produits[i].prix;
            produits[i].stock--;
            total_achat++;
            mt_depense += produits[i].prix;
            printf("Achat Reussi Votre Nouveau Solde est:%.2f\n", clients.solde);
            return;
        }
    }
    if (!trouve)
    {
        printf("Produit %s introuvable\n", choix);
    }
}
void recherche_par_nom()
{
    if (aucun_profil())
        return;
    char choix[MX];
    afficher_les_prd();
    printf("Saisie un produit nom:");
    fgets(choix, MX, stdin);
    choix[strcspn(choix, "\n")] = '\0';
    int trouve = 0;
    for (int i = 0; i < MXP; i++)
    {
        if (strcasecmp(produits[i].nomp, choix) == 0)
        {
            trouve = 1;
            printf("======>IdProduit:%d-%s-%s-%.2fMAD-%d Description:%s.\n", produits[i].produitID, produits[i].nomp, produits[i].categorie, produits[i].prix, produits[i].stock, produits[i].description);
            break;
        }
    }
    if (!trouve)
    {
        printf("Produit Introuvable\n");
    }
}
void statistique()
{
    if (aucun_profil())
        return;
    printf("\n=========Statstiques du client=======\n");
    printf("Nombre d'achats:%d\n", total_achat);
    printf("Montant total depense:%.2fMAD", mt_depense);
    printf("Solde Restant:%.2f", clients.solde);
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
            do
            {
                printf("\n=========Gestion de Client==========\n");
                printf("1. creer un Profil\n");
                printf("2. Consulter le Profil\n");
                printf("3. Modifier le Profil\n");
                printf("4. Generer Un Email\n");
                printf("0. Menu General\n");
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
                case 0:
                    break;
                default:
                    printf("Choix Invalide\n");
                }
            } while (choix2 != 0);
        }
        break;

        case 2:
        {
            int choix3;
            do
            {
                printf("\n==========Gestion du Solde=========\n");
                printf("1. Consulter Votre Solde\n");
                printf("2. Deposer Votre Argents\n");
                printf("0. Retour Au Menu principal\n");
                scanf("%d", &choix3);
                getchar();
                switch (choix3)
                {
                case 1:
                    consulter_le_solde();
                    break;
                case 2:
                    deposer_le_solde();
                    break;
                case 0:
                    break;

                default:
                    printf("Choix Invalide\n");
                }
            } while (choix3 != 0);
        }
        break;
        case 3:
        {
            int choix4;
            do
            {

                printf("1. afficher les produits\n");
                printf("2. trier les produits par prix decroissant\n");
                printf("3. chercher un produit\n");
                printf("0. Retour au Menu Principal\n");
                scanf("%d", &choix4);
                getchar();
                switch (choix4)
                {
                case 1:
                    afficher_les_prd();
                    break;
                case 2:
                    tri_les_prd();
                    afficher_les_prd();
                    break;
                case 3:
                    recherche_par_nom();
                    break;
                case 0:
                    break;

                default:
                    break;
                }

            } while (choix4 != 0);
        }
        break;
        case 4:
            achat_prd();
            break;
        case 5:
            statistique();
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
