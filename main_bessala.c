#include "Fonction_bessala.h"

int main(int argc, char *argv[]) {
    Manguissa_BE TManguissaBE[MAX_LENBE];
    init_hachageBE(TManguissaBE);

    int choiceBE,numberwordBE;
    char rechercheBE[15];
   printf(" Le Manguissa est une langue parlee au centre au Cameroun plus precisement dans la ville de SA'A et ces alantour,\n");
   printf(" Il est parle pas le peuple  Manguissa qui vie autour de la sanaga dans la Lieukie.\n");
   sleep(3);
   system("clear");

    do
    {
       printf("[****]-----------------------------------------------------------------------------------------[****]\n");
       printf(" ******* BIENVENUE DANS LE DICTIONNAIRE MAGUISSA ---> FRANCAIS !! *******\n");
       printf("[****]-----------------------------------------------------------------------------------------[****]\n");
       sleep(2);
       printf("Que souhaitez vous faire ?\n");
       printf("\t 0.Quitter le dictionnaire ?\n");
       printf("\t 1.Consulter le dictionnaire ?\n");
       printf("\t 2.Ajouter un mot en MAGUISSA dans le dictionnaire ?\n");
       printf("\t 3.Rechercher un mot MAGUISSA dans  le dictionnaire ?\n");
       printf("\t 4.Rechercher une traduction francaise dans le dictionnaire ?\n");
       sleep(2);
       printf("Votre choix : ");
       scanf("%d",&choiceBE);
       
       switch (choiceBE)
       {
        case 0:
            printf(" Merci pour votre visite\n");
            printf(" [****] SI VOUS SOUHAITEZ APPRENDRE DE NOUVELLE EXPRESSION EN MANGUISSA N HESITEZ PAS A FAIRE APPEL AU  DICTIONNAIRE MANGUISSA !! [****]\n");
            sleep(5);
            system("clear");
            printf("Sortie................................\n");
            sleep(2);
            system("clear");

        break;

        case 1:

          system("clear");
          printf("**|-- DICTIONNAIRE MANGUISSA--->> FRANCAIS !!--|**|\n");
          printf("|**|--......................................................................................--|**|\n");
          print_DictionnaireBE(TManguissaBE);
          printf("|**|--......................................................................................--|**|\n");
        break;

        case 2:
          printf("**|-- DICTIONNAIRE MANGUISSA--->> FRANCAIS !!--|**|\n");
          printf("Veuillez entrer le nombre de mots à ajouter : ");
          scanf("%d", &numberwordBE);
          getchar(); 

          for (int iBE = 0; iBE < numberwordBE; iBE++) {
              char wordBE[15];
              char traduitBE[15];

             printf("Mot %d : ", iBE + 1);
             scanf("%s", wordBE);
             printf("Traduction %d : ", iBE + 1);
             scanf("%s", traduitBE);

            input_wordLangueBE(TManguissaBE, wordBE, traduitBE);
          }
           
        break;

        case 3:

          system("clear");
          printf("**|-- DICTIONNAIRE MANGUISSA--->> FRANCAIS !!--|**|\n");
          printf("Entrez un mot à rechercher dans la langue nationale : ");
          scanf("%s", rechercheBE);
          rechercheLangueNationaleBE(TManguissaBE, rechercheBE);
        break;

        case 4:
           system("clear");
           printf("**|-- DICTIONNAIRE MANGUISSA--->> FRANCAIS !!--|**|\n");
           printf("Entrez une traduction à rechercher : ");
           scanf("%s", rechercheBE);
           rechercheTraductionBE(TManguissaBE, rechercheBE);
        break;
        
       default:
           printf("Choix invalide !Veuillez faire un choix valide !!\n");
        break;
       }
       
    }while(choiceBE!=0);

 return 0;
}