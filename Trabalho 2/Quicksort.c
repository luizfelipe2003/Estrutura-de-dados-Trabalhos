#include <stdio.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char **arr, int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1, comparisons, swaps);
        quicksort(arr, pivotIndex + 1, high, comparisons, swaps);
        (*comparisons) += high - low;
        (*swaps) += high - low;
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparisons = 0;
    int swaps = 0;

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, arrSize - 1, &comparisons, &swaps);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("%s\n", arr[i]);
    }

    printf("\nNumero de comparacoes: %d\n", comparisons);
    printf("Numero de trocas: %d\n", swaps);

    // Calculando a mediana
    char *median = arr[arrSize / 2];
    printf("\nMediana: %s\n", median);

    // Gerando arquivo de saída
    FILE *file = fopen("saida.txt", "w");
    if (file) {
        fprintf(file, "Vetor Ordenado:\n");
        for (int i = 0; i < arrSize; i++) {
            fprintf(file, "%s\n", arr[i]);
        }
        fprintf(file, "\nNumero de comparacoes: %d\n", comparisons);
        fprintf(file, "Numero de trocas: %d\n", swaps);
        fprintf(file, "\nMediana: %s\n", median);
        fclose(file);
    } else {
        printf("Erro ao criar o arquivo de saída.\n");
    }

    return 0;
}
