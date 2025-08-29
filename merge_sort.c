#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;  // Total de elementos a procesar
    int *arr = (int *)malloc(total * sizeof(int)); // Arreglo dinámico para todos los elementos

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calcular punto medio 
        int mid = left + (right - left) / 2;

        // Ordenar recursivamente la mitad izquierda
        mergeSort(arr, left, mid);
        
        // Ordenar recursivamente la mitad derecha
        mergeSort(arr, mid + 1, right);
        
        // Combinar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    // Calcular tamaños de los subarreglos
    int nL = mid - left + 1;  // Tamaño del subarreglo izquierdo
    int nR = right - mid;     // Tamaño del subarreglo derecho

    // Crear arreglos temporales para cada mitad
    int *L = (int*)malloc(nL * sizeof(int)); // Arreglo temporal izquierdo
    int *R = (int*)malloc(nR * sizeof(int)); // Arreglo temporal derecho

    // Copiar datos al arreglo temporal izquierdo
    for (int i = 0; i < nL; i++) {
        L[i] = arr[left + i];
    }

    // Copiar datos al arreglo temporal derecho
    for (int j = 0; j < nR; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Índices para recorrer los arreglos temporales y el arreglo original
    int i = 0;      
    int j = 0;      
    int k = left;   

    // Combinar los arreglos temporales de vuelta en arr
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar elementos restantes de L[], si los hay
    while (i < nL) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar elementos restantes de R[], si los hay
    while (j < nR) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria de los arreglos temporales
    free(L);
    free(R);
}
