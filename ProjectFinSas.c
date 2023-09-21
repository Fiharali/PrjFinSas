#include <stdio.h>
#include <string.h>
#include <time.h>

int choix, count = 0, Id = 1, choix2, numAjo, walo, status, triPar, IdM, foundId = 0, foundIdD = 0, foundIdT = 0, comp = 0, incomp = 0;
char cherT[33];
// choix  === hada howa l'tikhtar luser f lawel
// count  === hada howa l'count dyal struct
// Id     === hada howa l'id dyal kola struct
// choix2 === hada hoxwa l' choix dyal ajouter bach ikhtar   ajouter  wa7da ola bzaf
// numAjo === hada hoxwa dyal ch7al b4a izid
// walo   === hadi bach tan3amer scanf li khawya
// status === had dyal bach i5tar status li b4a f latach
// triPar === hadi tikhtar bach idir tri
// IdM  === hadi bach n9aleb 3la l id bach ndir Modifier
// foundId  === hadi natija dyal search 3la Id
// foundIdD = hada natija f recherch dyal id
// foundIdD = hada natija f recherch dyal titre
// cherT[]=hada ntija f recherch dyal titre
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
Tache tmodif;
void Menu()
{
    printf("*************************************************************************\n");
    printf("**********   [1]--->Ajouter une or plusieurs  nouvelle tache   **********\n");
    printf("**********   [2]--->afficher tout le taches                    **********\n");
    printf("**********   [3]--->Modifier une tache                         **********\n");
    printf("**********   [4]--->Supprimer une tache par identifiant.       **********\n");
    printf("**********   [5]--->Recherch  une tache.                       **********\n");
    printf("**********   [6]--->Afficher les statiques                     **********\n");
    printf("**********   [7]--->click 8 pour quitter                       **********\n");
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
        printf("**************[2]--->Ajouter plusieurs nouvelles taches        **************\n");
        printf("**************[0]--->click pour quitter                        **************\n");
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
            strcpy(taches[count].status, "finalisee");
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
    else if (choix2 == 0)
    {
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
            printf("*********[3]--->Afficher les taches dont le deadline est dans 3 jours ou moins    ********.\n");
            printf("*********[0]--->click pour quitter                                                *********.\n");
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
                        tmodif = taches[i];
                        taches[i] = taches[j];
                        taches[j] = tmodif;
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
        else if (triPar == 2)
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

                        tmodif = taches[i];
                        taches[i] = taches[j];
                        taches[j] = tmodif;
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

            time_t current_time;
            struct tm *time_info;
            char time_string[100];
            time(&current_time);
            time_info = localtime(&current_time);
            int day = time_info->tm_mday;
            int month = time_info->tm_mon + 1;
            int year = time_info->tm_year + 1900;

            // Print the current date
            printf("Current date: %02d-%02d-%04d\n", day, month, year);

            for (int i = 0; i < count; i++)
            {
                if (taches[i].deadline.annee == year && taches[i].deadline.mois == month && taches[i].deadline.jour = day)
                {
                    printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                           taches[i].id,
                           taches[i].titre,
                           taches[i].description,
                           taches[i].status, taches[i].deadline.jour,
                           taches[i].deadline.mois, taches[i].deadline.annee);
                    printf("***********************************************************************************************************************************|\n");
                }
            }
        }
        else if (triPar == 0)
        {
            // break;
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
void Modifier()
{
    printf("******************************************* Entre l'id pour modifier***************************************************\n");
    scanf("%d", &IdM);
    for (int i = 0; i < count; i++)
    {
        if (taches[i].id == IdM)
        {
            foundId = i;
            break;
        }
    }

    if (foundId != 0)
    {
        do
        {
            printf("********************************************************************************\n");
            printf("**************[1]--->Modifier  la description d'une tache.        **************\n");
            printf("**************[2]--->Modifier  le statut d'une tache.             **************\n");
            printf("**************[3]--->Modifier  le deadline d'une tache            **************\n");
            printf("**************[0]--->click pour quitter                           **************\n");
            printf("********************************************************************************\n");
            scanf("%d", &choix2);
        } while (choix2 < 0 || choix2 > 3);

        if (choix2 == 1)
        {

            printf("************************Entre  la nouvelle description ****************************************\n ");
            scanf("%d", walo);
            scanf("%[^\n]", &taches[foundId].description);
            printf("***********************************************************************************************\n");
            printf("************************************ajouter avec succes****************************************\n ");
            printf("***********************************************************************************************\n");
        }
        else if (choix2 == 2)
        {
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
                strcpy(taches[foundId].status, "a realiser");
            }
            else if (status == 2)
            {
                strcpy(taches[foundId].status, "en cours de realisation");
            }
            else if (status == 3)
            {
                strcpy(taches[foundId].status, "finalisee");
            }
            else
            {
                printf("choix error repeat please");
            }
        }
        else if (choix2 == 3)
        {
            printf("entre le deadline comme jj/mm/aa  ::  ");
            scanf("%d/%d/%d", &taches[foundId].deadline.jour, &taches[foundId].deadline.mois, &taches[foundId].deadline.annee);
        }
        else if (choix2 == 0)
        {
            /* code */
        }
        else
        {
            printf("choix ne pas valide !!\n");
        }
    }
    else
    {
        printf("id ne exist pas !!! \n\n");
    }
}
void Supremme()
{
    printf("******************************************* Entre l'id pour supreme ***************************************************\n");
    scanf("%d", &IdM);
    for (int i = 0; i < count; i++)
    {
        if (taches[i].id == IdM)
        {
            foundId = i;
            break;
        }
    }

    if (foundId != 0)
    {
        for (int i = foundId; i < count; i++)
        {
            taches[i] = taches[i + 1];
        }
        count--;
        Id--;
    }
    else
    {
        printf("id ne exsit pas !!!");
    }
}
void recherch()
{

    do

    {
        printf("*********************************************************************************************\n");
        printf("*********[1]--->Rechercher une tache par son Identifiant.                           *********\n");
        printf("*********[2]--->Rechercher une tache par son Titre                                  *********\n");
        printf("*********[0]--->click pour quitter                                                  *********\n");
        printf("**********************************************************************************************\n");
        scanf("%d", &triPar);

    } while (triPar < 0 || triPar > 2);

    if (triPar == 1)
    {
        printf("******************************************* Entre l'id pour Recherch ***************************************************\n");
        scanf("%d", &IdM);

        for (int i = 0; i < count; i++)
        {
            if (taches[i].id == IdM)
            {
                foundIdD = i;
                break;
            }
        }

        if (foundIdD != 0)
        {
            printf("***********************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |\n");
            printf("***********************************************************************************************************************************|\n");

            printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                   taches[foundIdD].id,
                   taches[foundIdD].titre,
                   taches[foundIdD].description,
                   taches[foundIdD].status, taches[foundIdD].deadline.jour,
                   taches[foundIdD].deadline.mois, taches[foundIdD].deadline.annee);
            printf("***********************************************************************************************************************************|\n");
        }
        else
        {
            printf("id ne pas exist \n\n");
        }
    }
    else if (triPar == 2)
    {
        printf("******************************************* Entre l'id pour Recherch ***************************************************\n");
        scanf("%s", &cherT);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(taches[i].titre, cherT) == 0)
            {
                foundIdT = i;
                break;
            }
        }

        if (foundIdT != 0)
        {
            printf("***********************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |\n");
            printf("***********************************************************************************************************************************|\n");

            printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                   taches[foundIdT].id,
                   taches[foundIdT].titre,
                   taches[foundIdT].description,
                   taches[foundIdT].status, taches[foundIdT].deadline.jour,
                   taches[foundIdT].deadline.mois, taches[foundIdT].deadline.annee);
            printf("***********************************************************************************************************************************|\n");
        }
        else
        {
            printf("id ne pas exist \n\n");
        }
    }
    else if (triPar == 0)
    {
    }
    else
    {
        /* code */
    }
}
void Statics()
{
    do

    {
        printf("******************************************************************************************************\n");
        printf("*********[1]--->Afficher le nombre total des tâches.                                         *********\n");
        printf("*********[2]--->Afficher le nombre de tâches complètes et incomplètes.                       *********\n");
        printf("*********[3]--->Afficher le nombre de jours restants jusqu'au dlai de chaque tâche.         *********\n");
        printf("*********[0]--->click pour quitter                                                           *********\n");
        printf("******************************************************************************************************\n");
        scanf("%d", &triPar);

    } while (triPar < 0 || triPar > 3);
    if (count > 0)
    {
        if (triPar == 1)
        {
            printf("******************************************************************************************************\n\n");
            printf("                         le nombre des taches  est  ====   %d\n\n ", count);
            printf("******************************************************************************************************\n\n");
        }
        else if (triPar == 2)
        {
            for (int i = 0; i < count; i++)
            {
                if (strcmp(taches[i].status, "finalisee") == 0)
                {
                    comp++;
                }
                else
                {
                    incomp++;
                }
            }
            printf("complet    =====    %d\n ", comp);
            printf("incomplet  =====    %d\n ", incomp);
        }
        else if (triPar == 3)
        {
        }
        else if (triPar == 0)
        {
        }
        else
        {
            printf("ne pas valid !!\n\n");
        }
    }
    else
    {
        printf("\n  ne taches a le moment !! \n\n ");
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
            Modifier();
            break;
        case 4:
            Supremme();
            break;
        case 5:
            recherch();
            break;
        case 6:
            Statics();
            break;
        case 7:
            printf("au revoir \n \n \n ");
            break;
        default:
            printf("choix ne pas valide \n ");
            break;
        }

    } while (choix != 7);

    return 0;
}