#ifndef FONCTION_BESSALA_H
#define FONCTION_BESSALA_H
//***-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//***-----------------------------------------------------------------------------
#define MAX_LENBE  26
#define MAX_WORDSBE  100 
//***-----------------------------------------------------------------------------
typedef struct dictionnaireBE {
    char langue_nationaleBE[15];
    char francaisBE[15];
    struct dictionnaireBE *nextBE;
} dictionnaireBE;

typedef dictionnaireBE* Manguissa_BE;
//***-----------------------------------------------------------------------------
Manguissa_BE create_manguissaBE(char *wordLangueBE, char* translateFrenchBE);
void init_hachageBE(Manguissa_BE* TManguissaBE);
unsigned int function_hachageBE(char *wordLangueBE);
void input_wordLangueBE(Manguissa_BE* TManguissaBE, char *wordLangueBE, char *translateFrenchBE);
void print_DictionnaireBE(Manguissa_BE *TManguissaBE);
void collect_and_sort_wordsBE(Manguissa_BE *TManguissaBE, dictionnaireBE *sortedWordsBE[], int *countBE);
void rechercheLangueNationaleBE(Manguissa_BE *TManguissaBE, char *wordLangueBE);
void rechercheTraductionBE(Manguissa_BE *TManguissaBE, char *translateFrenchBE);
//***-----------------------------------------------------------------------------
#endif // FONCTION_BESSALA_H