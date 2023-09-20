#include <stdio.h>
#include <string.h>
#include <time.h>


int choix, count = 0, Id = 1, choix2, numAjo, walo, status, triPar, khawi;
char khawi1[33];

// choix  === hada howa l'tikhtar luser f lawel
// count  === hada howa l'count dyal struct
// Id     === hada howa l'id dyal kola struct
// choix2 === hada hoxwa l' choix dyal ajouter bach ikhtar   ajouter  wa7da ola bzaf
// numAjo === hada hoxwa dyal ch7al b4a izid
// walo   === hadi bach tan3amer scanf li khawya
// status === had dyal bach i5tar status li b4a f latach
// triPar === hadi tikhtar bach idir tri
// khawi  === hadi bach nbadal 3la 7sab tri par alph
// khawi1  === hadi bach nbadal 3la 7sab tri par alph
typedef struct
{
    int jour;
    int mois;
    int annee;

} Deadline;

typedef struct
{
    int id;
    char titre[30];
    char description[70];
    Deadline deadline;
    char status[20];
} Tache;

Tache taches[50];
void Menu()
{
    printf("*************************************************************************\n");
    printf("**********   [1]--->Ajouter une or plusieurs  nouvelle tache   **********\n");
    printf("**********   [2]--->afficher tout le taches                    **********\n");
    printf("**********   [3]--->Modifier une tâche                         **********\n");
    printf("**********   [4]--->Modifier une tâche                         **********\n");
    printf("**********   [5]--->Supprimer une tâche par identifiant.       **********\n");
    printf("**********   [6]--->Supprimer une tâche par identifiant.       **********\n");
    printf("**********   [7]--->affecher les Statistiques                  **********\n");
    printf("**********   [8]--->click 8 pour quitter                       **********\n");
    printf("*************************************************************************\n");
    printf("  Entre votre choix est doit etre entier et entre 1 et 8 !!   \n");
    scanf("%d", &choix);
}
void Ajouter()
{
    do

    {
        printf("*****************************************************************************\n");
        printf("**************[1]--->Ajouter une nouvelle tache                **************\n");
        printf("**************[2]--->Ajouter plusieurs nouvelles tâches        **************\n");
        printf("*****************************************************************************\n");
        scanf("%d", &choix2);
    } while (choix2 < 0 || choix2 > 2);

    if (choix2 == 1)
    {
        taches[count].id = Id;
        printf("entre le titre  ::  ");
        scanf("%s", &taches[count].titre);
        printf("entre le description  ::  ");
        scanf("%d", 0);
        scanf("%[^\n]", &taches[count].description);
        // gets(taches[count].description);

        do
        {
            printf("********************************************************************\n");
            printf("**************[1]--->a realiser                       **************\n");
            printf("**************[2]--->en cours de realisation          **************\n");
            printf("**************[3]--->finalisee                        **************\n");
            printf("********************************************************************\n");
            scanf("%d", &status);
        } while (status < 0 || status > 3);
        if (status == 1)
        {
            strcpy(taches[count].status, "a realiser");
        }
        else if (status == 2)
        {
            strcpy(taches[count].status, "en cours de realisation");
        }
        else if (status == 3)
        {
            strcpy(taches[count].status, "finalisée");
        }
        else
        {
            printf("choix error repeat please");
        }
        printf("entre le deadline comme jj/mm/aa  ::  ");
        scanf("%d/%d/%d", &taches[count].deadline.jour, &taches[count].deadline.mois, &taches[count].deadline.annee);
        Id++;
        count++;
        printf("***********************************************************************************************\n");
        printf("************************************ajouter avec succes****************************************\n ");
        printf("***********************************************************************************************\n");
    }
    else if (choix2 == 2)
    {
        printf("enter le nombre des taches pour ajouter  ");
        scanf("%d", &numAjo);
        for (int i = 0; i < numAjo; i++)
        {
            taches[count].id = Id;
            printf("entre le titre  ::  ");
            scanf("%s", &taches[count].titre);
            printf("entre le description  ::  ");
            scanf("%d", walo);
            scanf("%[^\n]", &taches[count].description);
            // gets(taches[count].description);
            do
            {
                printf("********************************************************************\n");
                printf("**************[1]--->a realiser                       **************\n");
                printf("**************[2]--->en cours de realisation          **************\n");
                printf("**************[3]--->finalisee                        **************\n");
                printf("********************************************************************\n");
                scanf("%d", &status);
            } while (status < 0 || status > 3);
            if (status == 1)
            {
                strcpy(taches[count].status, "a realiser");
            }
            else if (status == 2)
            {
                strcpy(taches[count].status, "en cours de realisation");
            }
            else if (status == 3)
            {
                strcpy(taches[count].status, "finalisee");
            }
            else
            {
                printf("choix error repeat please");
            }

            printf("entre le deadline comme jj/mm/aa  ::  ");
            scanf("%d/%d/%d", &taches[count].deadline.jour, &taches[count].deadline.mois, &taches[count].deadline.annee);
            printf("*****************************************************************************************************************************\n");
            Id++;
            count++;
            printf("***********************************************************************************************\n");
            printf("************************************ajouter avec succes****************************************\n ");
            printf("***********************************************************************************************\n");
        }
    }
    else
    {
        printf("choix ne pas valide ");
    }
}
void Afficher()
{

    if (count > 0)
    {
        // printf("***********************************************************************************************************************************|\n");
        // printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |\n");
        // printf("***********************************************************************************************************************************|\n");
        // for (int i = 0; i < count; i++)
        // {
        //     // printf("***********************************************************************************************************************************|\n");
        //     printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
        //            taches[i].id,
        //            taches[i].titre,
        //            taches[i].description,
        //            taches[i].status, taches[i].deadline.jour,
        //            taches[i].deadline.mois, taches[i].deadline.annee);
        //     printf("***********************************************************************************************************************************|\n");
        // }
   
   
        do

        {
            printf("*******************************************************************************************\n");
            printf("*********[1]--->Trier les taches par ordre alphabetique                           *********\n");
            printf("*********[2]--->Trier les taches par deadline                                     *********\n");
            printf("*********[3]--->Afficher les taches dont le deadline est dans 3 jours ou moins   *********.\n");
            printf("*******************************************************************************************\n");
            scanf("%d", &triPar);

        } while (triPar < 0 || triPar > 3);

        if (triPar == 1)
        {
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (strcmp(taches[i].titre, taches[j].titre) > 0)
                    {
                        // tri les tetre
                        strcpy(khawi1, taches[i].titre);
                        strcpy(taches[i].titre, taches[j].titre);
                        strcpy(taches[j].titre, khawi1);
                        // tri les description
                        strcpy(khawi1, taches[i].description);
                        strcpy(taches[i].description, taches[j].description);
                        strcpy(taches[j].description, khawi1);

                        strcpy(khawi1, taches[i].status);
                        strcpy(taches[i].status, taches[j].status);
                        strcpy(taches[j].status, khawi1);

                        khawi = taches[i].id;
                        taches[i].id = taches[j].id;
                        taches[j].id = khawi;

                        khawi = taches[i].deadline.jour;
                        taches[i].deadline.jour = taches[j].deadline.jour;
                        taches[j].deadline.jour = khawi;

                        khawi = taches[i].deadline.mois;
                        taches[i].deadline.mois = taches[j].deadline.mois;
                        taches[j].deadline.mois = khawi;

                        khawi = taches[i].deadline.annee;
                        taches[i].deadline.annee = taches[j].deadline.annee;
                        taches[j].deadline.annee = khawi;
                    }
                }
            }
            printf("***********************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |\n");
            printf("***********************************************************************************************************************************|\n");
            for (int i = 0; i < count; i++)
            {

                // printf("***********************************************************************************************************************************|\n");
                printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                       taches[i].id,
                       taches[i].titre,
                       taches[i].description,
                       taches[i].status, taches[i].deadline.jour,
                       taches[i].deadline.mois, taches[i].deadline.annee);
                printf("***********************************************************************************************************************************|\n");
            }
        }
        else if (triPar = 2)
        {
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (taches[i].deadline.annee > taches[j].deadline.annee ||
                        (taches[i].deadline.annee == taches[j].deadline.annee && taches[i].deadline.mois > taches[j].deadline.mois) ||
                        (taches[i].deadline.annee == taches[j].deadline.annee && taches[i].deadline.mois == taches[j].deadline.mois && taches[i].deadline.jour > taches[j].deadline.jour))
                    {
                        // tri les tetre
                        strcpy(khawi1, taches[i].titre);
                        strcpy(taches[i].titre, taches[j].titre);
                        strcpy(taches[j].titre, khawi1);
                        // tri les description
                        strcpy(khawi1, taches[i].description);
                        strcpy(taches[i].description, taches[j].description);
                        strcpy(taches[j].description, khawi1);

                        strcpy(khawi1, taches[i].status);
                        strcpy(taches[i].status, taches[j].status);
                        strcpy(taches[j].status, khawi1);

                        khawi = taches[i].id;
                        taches[i].id = taches[j].id;
                        taches[j].id = khawi;

                        khawi = taches[i].deadline.jour;
                        taches[i].deadline.jour = taches[j].deadline.jour;
                        taches[j].deadline.jour = khawi;

                        khawi = taches[i].deadline.mois;
                        taches[i].deadline.mois = taches[j].deadline.mois;
                        taches[j].deadline.mois = khawi;

                        khawi = taches[i].deadline.annee;
                        taches[i].deadline.annee = taches[j].deadline.annee;
                        taches[j].deadline.annee = khawi;
                    }
                }
            }
            printf("***********************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |\n");
            printf("***********************************************************************************************************************************|\n");
            for (int i = 0; i < count; i++)
            {

                // printf("***********************************************************************************************************************************|\n");
                printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                       taches[i].id,
                       taches[i].titre,
                       taches[i].description,
                       taches[i].status, taches[i].deadline.jour,
                       taches[i].deadline.mois, taches[i].deadline.annee);
                printf("***********************************************************************************************************************************|\n");
            }
        }
        else if (triPar == 3)
        {
            /* code */
        }
        else
        {
            printf("choix ne pas valide ");
        }
    }
    else
    {
        printf("\n\n************************************ne pas des taches actualement***********************************\n\n");
    }
}

int main()
{
    do
    {
        Menu();
        switch (choix)
        {
        case 1:
            Ajouter();
            break;
        case 2:
            Afficher();
            break;
        case 3:
            Ajouter();
            break;
        case 4:
            Ajouter();
            break;
        default:
            printf("choix ne pas valide \n ");
            break;
        }

    } while (1);

    return 0;
}