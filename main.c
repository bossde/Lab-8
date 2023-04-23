#include "hash.h"

int main() {
    char words[MAX_CHARS];
    Table Table[TABLE_SIZE] = {0};

    FILE* file;
    file = fopen("words_alpha.txt","rt");
    if(file == NULL) {
        perror("Eroare deschidere fisier");
        printf("Fisierul nu s-a putut deschide! ");
        exit(1);
    }

    int percent = 0;
    double quality = 0;

    while(fgets(words,MAX_CHARS,file)){
        InsertTable(Table,words);
    }

    List* AuxNode = Table[2].head;
    int contor = 0;
    while(AuxNode != NULL && contor < 20){
        printf("%s", AuxNode->word);
        AuxNode = AuxNode->next;
        contor++;
    }

    PercentOfCollsions(Table,&percent,&quality);
    printf("\nPercent: %d\nQuality: %f\n", percent, quality);

    return 0;
}
