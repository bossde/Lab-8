#include "hash.h"

uint16_t DJB2_hash(const uint8_t *str)
{
    uint16_t hash = 5381;
    uint8_t c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

uint8_t sum_hash(const uint8_t *str)
{
    uint8_t c;
    uint8_t hash = 0;
    while ((c = *str++))
        hash += c;
    hash = hash % 256;
    return hash;
}


void InsertTable(Table *Table, char *word) {
    uint8_t hash = sum_hash(word);

    List *newNode = malloc(sizeof(List));
    newNode->word = malloc(strlen(word) + 1);
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (Table[hash].head == NULL) {
        Table[hash].head = newNode;
    } else {
        List *current = Table[hash].head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void PercentOfCollsions(Table *Table, int *procent, double *score) {
    *score = 0;
    double bj;
    int numberOfElem = 0;
    float numberOfCollisions = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        bj = 0;
        List *current = Table[i].head;
        while (current != NULL) {
            bj++;
            numberOfElem++;
            if(current->next != NULL) {
                numberOfCollisions++;
            }
            current = current->next;
        }
        *score += (bj * (bj + 1) / 2) / ((N / (2 * TABLE_SIZE))*(N + 2 * TABLE_SIZE - 1));
    }
    *procent = numberOfCollisions / numberOfElem * 100;
}
