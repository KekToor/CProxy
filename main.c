#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VSTUP "datalog.csv"
#define VYSTUP "pclog.html"
#define DELKA 100

typedef struct{
        char cislo [DELKA];
        char casStart [DELKA];
        char casKonec [DELKA];
        int data;
    }PC;

    void vypisSoubor(PC *pole, int pocetPC){
        int i;
        for(i = 0; i < pocetPC; i++){
            printf("%10s %10s %10s %10d b\n", pole[i].cislo, pole[i].casStart, 
                    pole[i].casKonec, pole[i].data);
        }
    }
    
    PC *nactiSoubor(PC *pole, int *pocetPC){
        *pocetPC = 0;
        FILE *fp;
        fp = fopen(VSTUP, "r");
        if(fp == NULL){
        printf("Soubor %s nebyl otevren.\n", VSTUP);
        }
        
        pole = (PC*)realloc(pole, sizeof(PC));
        while(fscanf(fp, "%s %s %s %d", pole[*pocetPC].cislo, pole[*pocetPC].casStart,
                pole[*pocetPC].casKonec, &pole[*pocetPC].data) != EOF){
            (*pocetPC)++;
            pole = (PC*)realloc(pole, sizeof(PC)*((*pocetPC)+1)); 
        }
        vypisSoubor(pole, *pocetPC);
        
        
        if(fclose(fp)==EOF){
            printf("Soubor %s nebyl uzavren.\n", VSTUP);
        }
        return pole;
    }

int main(int argc, char** argv) {
    PC *polePC = NULL;
    int pocetPC;
    polePC = nactiSoubor(polePC, &pocetPC);
    return (EXIT_SUCCESS);
}

