#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TABLE_SIZE 65536
#define MAX_CHARS 500
#define N 370105

struct hashlist{
    char *word;
    struct hashlist *next;
};

typedef struct hashlist List;

struct Head{
    List* head;
};

typedef struct Head Table;

uint16_t DJB2_hash(const uint8_t *str);
uint8_t sum_hash(const uint8_t *str);
void InsertTable(Table* table, char* word);
void PercentOfCollsions(Table* Table, int* percent, double* quality);


