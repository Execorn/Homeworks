#include <stdio.h>
#include <stdlib.h>
#include <time.h>

size_t skipRows(size_t row) {
    return (row + 1) / 2 * row;
}

int main() {
    size_t numberOfTeams = 0;

    while (scanf("%zu", &numberOfTeams) != 1) {
        printf("Please enter valid number of teams. \n");
        fflush(stdin);
    }

    int* table = calloc(skipRows(numberOfTeams), sizeof(table[0]));
    if (table == NULL) {
        printf("Malloc fault. Please try again. \n");
        return 0;
    }

    srand(time(NULL));
    for (size_t x = 0; x < numberOfTeams; ++x) {
        for (size_t y = 0; y <= x; ++y) {
            *(table + skipRows(x) + y) = rand();
            printf("%d ", *(table + skipRows(x) + y));
        }
        printf("\n");
    }

    return 0;
}
