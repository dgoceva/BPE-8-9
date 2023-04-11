#include "pet.h"

TPet inputPet(void)
{
    TPet pet;
    FILE *f;

    printf("Name: ");
    fgets(pet.name,LEN,stdin);
    pet.name[strlen(pet.name)-1]='\0';
    fflush(stdin);
    printf("Chip: ");
    fgets(pet.chip,CH_LEN,stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f",&pet.price);
    fflush(stdin);

//    if((f=fopen(IN_TXT_NAME,"w"))==NULL){
    if((f=fopen(IN_TXT_NAME,"a"))==NULL){
        perror("Open error: ");
        exit(EXIT_FAILURE);
    }
    fprintf(f,"%s,%.2f\n",pet.name,pet.price);
    fclose(f);

    return pet;
}

void printPetsByPrice(TPet pets[],unsigned len,float price)
{
    bool isFound=false;

    for(int i=0;i<len;++i){
        if(pets[i].price==price){
            printf("%s - %s\n",pets[i].name,pets[i].chip);
            isFound=true;
        }
    }
    if(!isFound){
        puts("No such data...\n");
    }
}

void readPrintPets(float price)
{
    FILE *f;
    TPet pet;
    unsigned len;
    bool isFirst=true;

    if((f=fopen(IN_BIN_NAME,"rb"))==NULL){
        perror("Bin open error: ");
        exit(EXIT_FAILURE);
    }
    while(true){
         if(fread(&len,sizeof(unsigned),1,f)!=1){
            if (feof(f))
                break;
            else {
                perror("Reading len error: ");
                fclose(f);
                exit(EXIT_FAILURE);
            }
         }
         if (len>LEN-1)
            len = LEN-1;
         if(fread(pet.name,sizeof(char),len,f)!=len){
                perror("Reading name error: ");
                fclose(f);
                exit(EXIT_FAILURE);
         }
         pet.name[len]='\0';
         if(fread(pet.chip,sizeof(char),CH_LEN-1,f)!=CH_LEN-1){
            perror("Reading chip error: ");
            fclose(f);
            exit(EXIT_FAILURE);
         }
         pet.chip[CH_LEN-1]='\0';
         if(fread(&pet.price,sizeof(float),1,f)!=1){
            perror("Reading price error: ");
            fclose(f);
            exit(EXIT_FAILURE);
         }
         if(pet.price>=price){
            if(!isFirst)
                puts("----------\n");
            else
                isFirst = false;
            printf("Bin OwnerName: %s\n",pet.name);
            printf("Bin Chip: %s\n",pet.chip);
            printf("Bin Price: %.2f\n",pet.price);
         }
    }
    fclose(f);
}
