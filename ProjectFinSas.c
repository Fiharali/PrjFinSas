#include <stdio.h>
#include <string.h>
#include <time.h>

int choix, count = 0, Id = 1, choix2, numTacheAjouter, status, idMoSu, foundId = 0, foundIdD = 0, foundIdT = 0, comp = 0, incomp = 0, localtime1, localtime2, resultt;
;
char cherT[33];
FILE *fptr;
// typedef struct
// {
//     int jour;
//     int mois;
//     int annee;

// } Collaborateur;
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
    int create_atJour;
    int create_atMois;
    int create_atAnnee;
} Tache;

Tache taches[50];
Tache tmodif;
// Collaborateur collaborateurs[50];

void Menu()
{
    printf("*************************************************************************\n");
    printf("**********   [1]--->Ajouter une or plusieurs  nouvelle tache   ********\n");
    printf("**********   [2]--->afficher tout le taches                    ********\n");
    printf("**********   [3]--->Modifier une tache                         ********\n");
    printf("**********   [4]--->Supprimer une tache par identifiant.       ********\n");
    printf("**********   [5]--->Recherch  une tache.                       ********\n");
    printf("**********   [6]--->Afficher les statiques                     ********\n");
    printf("**********   [7]--->Enregistrer dans fichier                   ********\n");
    printf("**********   [8]--->click 8 pour quitter                       ********\n");
    printf("*************************************************************************\n");
    printf("  Entre votre choix est doit etre entier et entre 1 et 8 !!   \n");
    resultt = scanf("%d", &choix);
}
void Ajouter()
{

    time_t current_time;
    struct tm *time_info;
    char time_string[100];
    time(&current_time);
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;
    // localtime1 = year * 365 + month * 30 + day;
    do

    {
        printf("*****************************************************************************\n");
        printf("**************[1]--->Ajouter une nouvelle tache                ************\n");
        printf("**************[2]--->Ajouter plusieurs nouvelles taches        ************\n");
        printf("**************[0]--->click pour quitter                        ************\n");
        printf("*****************************************************************************\n");
        scanf("%d", &choix2);
    } while (choix2 < 0 || choix2 > 2);

    if (choix2 == 1)
    {
        taches[count].id = Id;
        printf("entre le titre  ::  ");
        scanf("%s", &taches[count].titre);
        printf("entre le description  ::  ");
        // scanf("%d", 0);
        scanf(" %[^\n]", &taches[count].description);
        // gets(taches[count].description);

        do
        {
            printf("********************************************************************\n");
            printf("**************[1]--->a realiser                       ************\n");
            printf("**************[2]--->en cours de realisation          ************\n");
            printf("**************[3]--->finalisee                        ************\n");
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
        do
        {
            printf("entre le deadline comme jj/mm/aa  ::  ");
            scanf("%d/%d/%d", &taches[count].deadline.jour, &taches[count].deadline.mois, &taches[count].deadline.annee);
            if (taches[count].deadline.jour < 0 || taches[count].deadline.jour > 31 || taches[count].deadline.mois < 0 || taches[count].deadline.mois > 12 || taches[count].deadline.annee < 2000 || taches[count].deadline.annee > 2030)
            {
                printf("      la date ne pas valide   \n");
            }

        } while (taches[count].deadline.jour < 0 || taches[count].deadline.jour > 31 || taches[count].deadline.mois < 0 || taches[count].deadline.mois > 12 || taches[count].deadline.annee < 2000 || taches[count].deadline.annee > 2030);
        taches[count].create_atJour = day;
        taches[count].create_atMois = month;
        taches[count].create_atAnnee = year;
        Id++;
        count++;
        printf("***********************************************************************************************\n");
        printf("************************************ajouter avec succes****************************************\n ");
        printf("***********************************************************************************************\n");
    }
    else if (choix2 == 2)
    {
        printf("enter le nombre des taches pour ajouter  ");
        scanf("%d", &numTacheAjouter);
        for (int i = 0; i < numTacheAjouter; i++)
        {
            taches[count].id = Id;
            printf("entre le titre  ::  ");
            scanf("%s", &taches[count].titre);
            printf("entre le description  ::  ");
            scanf(" %[^\n]", &taches[count].description);
            do
            {
                printf("********************************************************************\n");
                printf("**************[1]--->a realiser                       ************\n");
                printf("**************[2]--->en cours de realisation          ************\n");
                printf("**************[3]--->finalisee                        ************\n");
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
                printf("choix error repeat please \n");
            }

            do
            {
                printf("entre le deadline comme jj/mm/aa  ::  ");
                scanf("%d/%d/%d", &taches[count].deadline.jour, &taches[count].deadline.mois, &taches[count].deadline.annee);
                if (taches[count].deadline.jour < 0 || taches[count].deadline.jour > 31 || taches[count].deadline.mois < 0 || taches[count].deadline.mois > 12 || taches[count].deadline.annee < 2000 || taches[count].deadline.annee > 2030)
                {
                    printf("      la date ne pas valide   \n");
                }
            } while (taches[count].deadline.jour < 0 || taches[count].deadline.jour > 31 || taches[count].deadline.mois < 0 || taches[count].deadline.mois > 12 || taches[count].deadline.annee < 2000 || taches[count].deadline.annee > 2030);
            taches[count].create_atJour = day;
            taches[count].create_atMois = month;
            taches[count].create_atAnnee = year;
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
        printf("choix ne pas valide \n");
    }
}
void Afficher()
{

    if (count > 0)
    {
        do
        {
            printf("*******************************************************************************************\n");
            printf("*********[1]--->Trier les taches par ordre alphabetique                           *******\n");
            printf("*********[2]--->Trier les taches par deadline                                     *******\n");
            printf("*********[3]--->Afficher les taches dont le deadline est dans 3 jours ou moins    ******.\n");
            printf("*********[0]--->click pour quitter                                                *******.\n");
            printf("*******************************************************************************************\n");
            scanf("%d", &choix2);
        } while (choix2 < 0 || choix2 > 3);

        if (choix2 == 1)
        {
            char cmp1[50], cmp2[50];
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    // strcpy(cmp1,);
                    // cmp1=strlwr(taches[i].titre);
                    strcpy(cmp1, taches[i].titre);
                    strcpy(cmp2, taches[j].titre);
                    strlwr(cmp1);
                    strlwr(cmp2);
                    if (strcmp(cmp1, cmp2) > 0)
                    {
                        tmodif = taches[i];
                        taches[i] = taches[j];
                        taches[j] = tmodif;
                    }
                }
            }
            printf("***************************************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          | create_at    | \n");
            printf("***************************************************************************************************************************************************|\n");
            for (int i = 0; i < count; i++)
            {

                // printf("***********************************************************************************************************************************|\n");
                printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |   %d/%d/%d  |\n",
                       taches[i].id,
                       taches[i].titre,
                       taches[i].description,
                       taches[i].status, taches[i].deadline.jour,
                       taches[i].deadline.mois, taches[i].deadline.annee, taches[i].create_atJour, taches[i].create_atMois, taches[i].create_atAnnee);
                printf("***********************************************************************************************************************************|\n");
            }
        }
        else if (choix2 == 2)
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
            printf("***************************************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          | create_at    | \n");
            printf("***************************************************************************************************************************************************|\n");
            for (int i = 0; i < count; i++)
            {

                // printf("***********************************************************************************************************************************|\n");
                printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |  %d/%d/%d  |\n",
                       taches[i].id,
                       taches[i].titre,
                       taches[i].description,
                       taches[i].status, taches[i].deadline.jour,
                       taches[i].deadline.mois, taches[i].deadline.annee, taches[i].create_atJour, taches[i].create_atMois, taches[i].create_atAnnee);
                printf("***********************************************************************************************************************************|\n");
            }
        }
        else if (choix2 == 3)
        {

            time_t current_time;
            struct tm *time_info;
            char time_string[100];
            time(&current_time);
            time_info = localtime(&current_time);
            int day = time_info->tm_mday;
            int month = time_info->tm_mon + 1;
            int year = time_info->tm_year + 1900;
            localtime1 = year * 365 + month * 30 + day;

            // Print the current date
            // printf("Current date: %02d-%02d-%04d\n", day, month, year);
            printf("***************************************************************************************************************************************************|\n");
            printf("|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          | create_at    | \n");
            printf("***************************************************************************************************************************************************|\n");
            for (int i = 0; i < count; i++)
            {
                // if ((taches[i].deadline.annee == year && taches[i].deadline.mois == month) && (taches[i].deadline.jour == day || taches[i].deadline.jour == day + 1 || taches[i].deadline.jour == day + 2))
                // {
                //     printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |\n",
                //            taches[i].id,
                //            taches[i].titre,
                //            taches[i].description,
                //            taches[i].status, taches[i].deadline.jour,
                //            taches[i].deadline.mois, taches[i].deadline.annee);
                //     printf("***********************************************************************************************************************************|\n");
                // }
                localtime2 = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
                if (localtime2 == localtime1 || localtime2 == localtime1 + 1 || localtime2 == localtime1 + 2 || localtime2 == localtime1 + 3)
                {
                    printf("|     %d     |            %s            |      %s     |           %s          |       %02d/%02d/%04d      |   %d/%d/%d    |\n",
                           taches[i].id,
                           taches[i].titre,
                           taches[i].description,
                           taches[i].status, taches[i].deadline.jour,
                           taches[i].deadline.mois, taches[i].deadline.annee, taches[i].create_atJour, taches[i].create_atMois, taches[i].create_atAnnee);
                    printf("***********************************************************************************************************************************|\n");
                }
            }
        }
        else if (choix2 == 0)
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
    scanf("%d", &idMoSu);
    for (int i = 0; i < count; i++)
    {
        if (taches[i].id == idMoSu)
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
            printf("**************[1]--->Modifier  la description d'une tache.        ************\n");
            printf("**************[2]--->Modifier  le statut d'une tache.             ************\n");
            printf("**************[3]--->Modifier  le deadline d'une tache            ************\n");
            printf("**************[0]--->click pour quitter                           ************\n");
            printf("********************************************************************************\n");
            scanf("%d", &choix2);
        } while (choix2 < 0 || choix2 > 3);

        if (choix2 == 1)
        {

            printf("************************Entre  la nouvelle description **************************************\n ");
            scanf(" %[^\n]", &taches[foundId].description);
            printf("***********************************************************************************************\n");
            printf("************************************ajouter avec succes****************************************\n ");
            printf("***********************************************************************************************\n");
        }
        else if (choix2 == 2)
        {
            do
            {
                printf("********************************************************************\n");
                printf("**************[1]--->a realiser                       ************\n");
                printf("**************[2]--->en cours de realisation          ************\n");
                printf("**************[3]--->finalisee                        ************\n");
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
            printf("***********************************************************************************************\n");
            printf("************************************ajouter avec succes****************************************\n ");
            printf("***********************************************************************************************\n");
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
    printf("******************************************* Entre l'id pour supreme *************************************************\n");
    scanf("%d", &idMoSu);
    for (int i = 0; i < count; i++)
    {
        if (taches[i].id == idMoSu)
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
        printf("************************************************************************************************************\n");
        printf("**********************************************suppreme avec sucsses*****************************************\n");
        printf("************************************************************************************************************\n");
    }
    else
    {
        printf("id ne exsit pas !!!\n");
    }
}
void Recherch()
{

    do

    {
        printf("*********************************************************************************************\n");
        printf("*********[1]--->Rechercher une tache par son Identifiant.                           *******\n");
        printf("*********[2]--->Rechercher une tache par son Titre                                  *******\n");
        printf("*********[0]--->click pour quitter                                                  *******\n");
        printf("**********************************************************************************************\n");
        scanf("%d", &choix2);

    } while (choix2 < 0 || choix2 > 2);

    if (choix2 == 1)
    {
        printf("******************************************* Entre l'id pour Recherch *************************************************\n");
        scanf("%d", &idMoSu);

        for (int i = 0; i < count; i++)
        {
            if (taches[i].id == idMoSu)
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
    else if (choix2 == 2)
    {
        printf("******************************************* Entre le titre  pour Recherch *************************************************\n");
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
    else if (choix2 == 0)
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
        printf("*********[1]--->Afficher le nombre total des tâches.                                         *******\n");
        printf("*********[2]--->Afficher le nombre de tâches complètes et incomplètes.                       *******\n");
        printf("*********[3]--->Afficher le nombre de jours restants jusqu'au dlai de chaque tâche.         *******\n");
        printf("*********[0]--->click pour quitter                                                           *******\n");
        printf("******************************************************************************************************\n");
        scanf("%d", &choix2);

    } while (choix2 < 0 || choix2 > 3);
    if (count > 0)
    {
        if (choix2 == 1)
        {
            printf("******************************************************************************************************\n\n");
            printf("                         le nombre des taches  est  ====   %d\n\n ", count);
            printf("******************************************************************************************************\n\n");
        }
        else if (choix2 == 2)
        {
            comp = 0;
            incomp = 0;
            for (int i = 0; i < count; i++)
            {
                if (strcmp(taches[i].status, "finalisee") == 0)
                {
                    comp++;
                }
                if ((strcmp(taches[i].status, "a realiser") == 0) || (strcmp(taches[i].status, "en cours de realisation")))
                {
                    incomp++;
                }
            }
            printf("***********************************************************************************************************************\n ");
            printf("                                        complet    =====    %d\n ", comp);
            printf("                                        incomplet  =====    %d\n ", incomp);
            printf("***********************************************************************************************************************\n ");
        }
        else if (choix2 == 3)
        {
            time_t current_time;
            struct tm *time_info;
            char time_string[100];
            time(&current_time);
            time_info = localtime(&current_time);
            int day = time_info->tm_mday;
            int month = time_info->tm_mon + 1;
            int year = time_info->tm_year + 1900;
            localtime1 = year * 365 + month * 30 + day;
            for (int i = 0; i < count; i++)
            {
                // printf("******************************************************************************************************\n\n");
                // printf("           la tache numero %d il rest     ======     %d             jour            \n \n ", taches[i].id, localtime2 - localtime1);
                // printf("******************************************************************************************************\n\n");
                localtime2 = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
                if (localtime2 - localtime1 < 0)
                {
                    printf("******************************************************************************************************\n\n");
                    printf("           la tache numero %d il termini a     ======     %d             jour            \n \n ", taches[i].id, localtime1 - localtime2);
                    printf("******************************************************************************************************\n\n");
                }
                else if (localtime2 - localtime1 > 0)
                {
                    printf("******************************************************************************************************\n\n");
                    printf("           la tache numero %d il rest     ======     %d             jour            \n \n ", taches[i].id, localtime2 - localtime1);
                    printf("******************************************************************************************************\n\n");
                }
                else
                {
                    printf("******************************************************************************************************\n\n");
                    printf("           la tache numero %d il rest     ======     termini ce  jour            \n \n ", taches[i].id);
                    printf("******************************************************************************************************\n\n");
                }
            }
        }
        else if (choix2 == 0)
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
void Enregistrer()
{
    fptr = fopen("file.txt", "w");
    // fprintf(fptr, "Some text");
    fprintf(fptr, "***************************************************************************************************************************************************|\n");
    fprintf(fptr, "|     ID     |           TITRE          |              DESCRIPTION            |           STATUS         |           DATE          |  create_at    | \n");
    fprintf(fptr, "***************************************************************************************************************************************************|\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(fptr, "|      ");
        fprintf(fptr, "%d", taches[i].id);
        fprintf(fptr, "     |      ");
        fprintf(fptr, "%s", taches[i].titre);
        fprintf(fptr, "      |       ");
        fprintf(fptr, "%s", taches[i].description);
        fprintf(fptr, "      |      ");
        fprintf(fptr, "%s", taches[i].status);
        fprintf(fptr, "     |      ");
        fprintf(fptr, "%d", taches[i].deadline.jour);
        fprintf(fptr, "/");
        fprintf(fptr, "%d", taches[i].deadline.mois);
        fprintf(fptr, "/");
        fprintf(fptr, "%d", taches[i].deadline.annee);
        fprintf(fptr, "      |      ");
        fprintf(fptr, "%d", taches[i].create_atJour);
        fprintf(fptr, "/");
        fprintf(fptr, "%d", taches[i].create_atMois);
        fprintf(fptr, "/");
        fprintf(fptr, "%d", taches[i].create_atAnnee);
        fprintf(fptr, "      |");
        fprintf(fptr, "\n");
        fprintf(fptr, "***************************************************************************************************************************************************|\n");
    }
    fclose(fptr);
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
            Recherch();
            break;
        case 6:
            Statics();
            break;
        case 7:
            Enregistrer();
            break;
        case 8:
            printf("au revoir \n \n \n ");
            break;
        default:
            printf("choix ne pas valide \n ");
            break;
        }
        if (resultt != 1)
        {
            // printf("\n");
            break;
        }
    } while (choix != 8);

    return 0;
}