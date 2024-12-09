#include "Fonction_bessala.h"
//***-----------------------------------------------------------------------------
Manguissa_BE create_manguissaBE(char *wordLangueBE, char* translateFrenchBE) {
    Manguissa_BE courantBE = (Manguissa_BE)malloc(sizeof(dictionnaireBE));
    if (courantBE != NULL) {
        strcpy(courantBE->langue_nationaleBE, wordLangueBE);
        strcpy(courantBE->francaisBE, translateFrenchBE);
        courantBE->nextBE = NULL;
    }
    return courantBE;
}
//***-----------------------------------------------------------------------------
void init_hachageBE(Manguissa_BE* TManguissaBE) {
    for (int iBE = 0; iBE < MAX_LENBE; iBE++) {
        TManguissaBE[iBE] = NULL;
    }

    // Remplissons les mots dans le dict
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Aban", "Nom_arbre");
    input_wordLangueBE(TManguissaBE, "Akom", "Nom_arbre");
    input_wordLangueBE(TManguissaBE, "Amos", "Jour");
    input_wordLangueBE(TManguissaBE, "Akuk", "Abre_medical");
    input_wordLangueBE(TManguissaBE, "Bidi", "La_nourriture");
    input_wordLangueBE(TManguissaBE, "Bivue", "Les_jeux");
    input_wordLangueBE(TManguissaBE, "Bomgo", "Les_enfants");

//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Biga", "Les_femmes");
    input_wordLangueBE(TManguissaBE, "Gok", "La_pierre");
    input_wordLangueBE(TManguissaBE, "Gahmon", "Belle_fille/Beau_fils");
    input_wordLangueBE(TManguissaBE, "Gos", "Abre_medical");
    input_wordLangueBE(TManguissaBE, "Isani", "Dance_tradictionnelle");
    input_wordLangueBE(TManguissaBE, "Isa", "Le_travail");
    input_wordLangueBE(TManguissaBE, "Ivu", "La_sorcenerie");
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Keka", "Cacao");
    input_wordLangueBE(TManguissaBE, "Megisa", "Manguissa");
    input_wordLangueBE(TManguissaBE, "Mebanga", "Macabo");
    input_wordLangueBE(TManguissaBE, "Medim", "L_eau");
    input_wordLangueBE(TManguissaBE, "Mbebekeri", "Bonjour");
    input_wordLangueBE(TManguissaBE, "Mbebealu", "Bonne_nuit");
    input_wordLangueBE(TManguissaBE, "Nda", "La_maison");
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Lal", "trois");
    input_wordLangueBE(TManguissaBE, "Nkol", "La_coline");
    input_wordLangueBE(TManguissaBE, "Nkada", "Petite_culote");
    input_wordLangueBE(TManguissaBE, "Ovuvu", "couscous");
    input_wordLangueBE(TManguissaBE, "Oles", "Le_riz");
    input_wordLangueBE(TManguissaBE, "Odjo", "La_banane");
    input_wordLangueBE(TManguissaBE, "Pa", "La_machette");
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Popo", "Papaye");
    input_wordLangueBE(TManguissaBE, "Pos", "Verre_blanc");
    input_wordLangueBE(TManguissaBE, "Pie", "Avocat");
    input_wordLangueBE(TManguissaBE, "Si", "La_terre");
    input_wordLangueBE(TManguissaBE, "Sil", "Termitte");
    input_wordLangueBE(TManguissaBE, "Sa'a", "Prune");
    input_wordLangueBE(TManguissaBE, "Tate", "Pere");
    input_wordLangueBE(TManguissaBE, "Tock", "cuilliere");
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Va", "Ici");
    input_wordLangueBE(TManguissaBE, "Vom", "Nul_par");
    input_wordLangueBE(TManguissaBE, "Wude", "Fenetre");
    input_wordLangueBE(TManguissaBE, "Wa", "Toi");
    input_wordLangueBE(TManguissaBE, "Yen", "Voir");
    input_wordLangueBE(TManguissaBE, "Zok", "Elephant");
    input_wordLangueBE(TManguissaBE, "Zezan", "Djacent");
    input_wordLangueBE(TManguissaBE, "Zel", "Barbe");
//***-----------------------------------------------------------------------------
    input_wordLangueBE(TManguissaBE, "Za", "Qui?");
    input_wordLangueBE(TManguissaBE, "Zon", "Obergine");
    input_wordLangueBE(TManguissaBE, "Zak", "demande");
    input_wordLangueBE(TManguissaBE, "Zeh", "Panthere");
    input_wordLangueBE(TManguissaBE, "bo'o", "Eux");
    input_wordLangueBE(TManguissaBE, "Utukek", "Variate_de_plantain");
    input_wordLangueBE(TManguissaBE, "Zan", "Querelle");
    input_wordLangueBE(TManguissaBE, "Abugan", "Merci");
//***-----------------------------------------------------------------------------
    
}
//***-----------------------------------------------------------------------------
unsigned int function_hachageBE(char *wordLangueBE) {
    unsigned int sBE = 0;
    for (int iBE = 0; iBE < strlen(wordLangueBE); iBE++) {
        sBE += wordLangueBE[iBE];
    }
    return sBE % MAX_LENBE; 
}
//***-----------------------------------------------------------------------------
void input_wordLangueBE(Manguissa_BE* TManguissaBE, char *wordLangueBE, char *translateFrenchBE) {
    Manguissa_BE newBE = create_manguissaBE(wordLangueBE, translateFrenchBE);
    unsigned int indiceBE = function_hachageBE(wordLangueBE);

    if (TManguissaBE[indiceBE] == NULL) {
        TManguissaBE[indiceBE] = newBE;
    } else {
        Manguissa_BE tmpBE = TManguissaBE[indiceBE];
        while (tmpBE->nextBE != NULL) {
            tmpBE = tmpBE->nextBE;
        }
        tmpBE->nextBE = newBE; 
    }
}
//***-----------------------------------------------------------------------------
void collect_and_sort_wordsBE(Manguissa_BE *TManguissaBE, dictionnaireBE *sortedWordsBE[], int *countBE) {
    *countBE = 0;

    for (int iBE = 0; iBE < MAX_LENBE; iBE++) {
        Manguissa_BE tmpBE = TManguissaBE[iBE];
        while (tmpBE != NULL) {
            sortedWordsBE[*countBE] = tmpBE;
            (*countBE)++;
            tmpBE = tmpBE->nextBE;
        }
    }

    
    for (int iBE = 1; iBE < *countBE; iBE++) {
        dictionnaireBE *keyBE = sortedWordsBE[iBE];
        int jBE = iBE - 1;

        while (jBE >= 0 && strcmp(sortedWordsBE[jBE]->langue_nationaleBE, keyBE->langue_nationaleBE) > 0) {
            sortedWordsBE[jBE + 1] = sortedWordsBE[jBE];
            jBE = jBE - 1;
        }
        sortedWordsBE[jBE + 1] = keyBE;
    }
}
//***-----------------------------------------------------------------------------
void print_DictionnaireBE(Manguissa_BE *TManguissaBE) {
    dictionnaireBE *sortedWordsBE[MAX_WORDSBE];
    int countBE;

    collect_and_sort_wordsBE(TManguissaBE, sortedWordsBE, &countBE);

    
    for (int iBE = 0; iBE < countBE; iBE++) {
       
        printf("%s -> %s\n", sortedWordsBE[iBE]->langue_nationaleBE, sortedWordsBE[iBE]->francaisBE);
         printf("***-----------------------------------------------------------------------------\n");
    }
}
//***-----------------------------------------------------------------------------

void rechercheLangueNationaleBE(Manguissa_BE *TManguissaBE, char *wordLangueBE) {
    unsigned int indiceBE = function_hachageBE(wordLangueBE);
    Manguissa_BE tmpBE = TManguissaBE[indiceBE];

    while (tmpBE != NULL) {
        if (strcmp(tmpBE->langue_nationaleBE, wordLangueBE) == 0) {
            printf("Mot trouvé : %s -> %s\n", tmpBE->langue_nationaleBE, tmpBE->francaisBE);
            return;
        }
        tmpBE = tmpBE->nextBE;
    }
    printf("Le mot '%s' n'a pas été trouvé.\n", wordLangueBE);
}
//***-----------------------------------------------------------------------------
void rechercheTraductionBE(Manguissa_BE *TManguissaBE, char *translateFrenchBE) {
    for (int iBE = 0; iBE < MAX_LENBE; iBE++) {
        Manguissa_BE tmpBE = TManguissaBE[iBE];
        while (tmpBE != NULL) {
            if (strcmp(tmpBE->francaisBE, translateFrenchBE) == 0) {
                printf("Traduction trouvée : %s -> %s\n", tmpBE->francaisBE, tmpBE->langue_nationaleBE);
                return;
            }
            tmpBE = tmpBE->nextBE;
        }
    }
    printf("La traduction '%s' n'a pas été trouvée.\n", translateFrenchBE);
}
//***-----------------------------------------------------------------------------