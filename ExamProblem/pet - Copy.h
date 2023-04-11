#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 31
#define CH_LEN 8
#define IN_TXT_NAME "animalsText.txt"
#define IN_BIN_NAME "animalsBin.bin"

typedef struct {
    char name[LEN];
    char chip[CH_LEN];
    float price;
} TPet;

TPet inputPet(void);
void printPetsByPrice(TPet pets[],unsigned len,float price);
void readPrintPets(float price);

#endif // PET_H_INCLUDED
