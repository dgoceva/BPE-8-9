#include "pet.h"
#include <string.h>

void writeToBin(char *fname,TPet pets[],unsigned len)
{
    FILE *f = fopen(fname,"wb");
    unsigned size;

    if (f==NULL){
        perror(NULL);
        exit(2);
    }
    for(int i=0;i<len;++i){
        size = strlen(pets[i].name);
        fwrite(&size,sizeof(unsigned),1,f);
        fwrite(pets[i].name,sizeof(char),size,f);
        fwrite(pets[i].chip,sizeof(char),CH_LEN-1,f);
        fwrite(&(pets[i].price),sizeof(float),1,f);
    }
    fclose(f);
}
int main()
{
    TPet pets[LEN];
    const unsigned SIZE=5;
/*
    for(int i=0;i<SIZE;++i)
        pets[i] = inputPet();

    writeToBin(IN_BIN_NAME,pets,SIZE);
    printPetsByPrice(pets,SIZE,22.22);
*/
    readPrintPets(10);

    printf("Hello world!\n");
    return 0;
}
