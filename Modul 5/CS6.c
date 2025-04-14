#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Product {
    char* name;
    char* category;
} Product;

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower((unsigned char)str[i]);
    }
}

void create(int n,Product products[]) {
    for (int i = 0; i < n; i++) {
        products[i].name = (char*)malloc(64 * sizeof(char));
        products[i].category = (char*)malloc(64 * sizeof(char));

        printf("\nMasukkan nama produk %d: ", i + 1);
        fgets(products[i].name, 64, stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0'; 

        printf("Masukkan kategori produk %d: ", i + 1);
        fgets(products[i].category, 64, stdin);
        products[i].category[strcspn(products[i].category, "\n")] = '\0'; 
    }
}

Product* searchName(char* name, int n, Product products[], int* resultCount) {
    Product* result = (Product*)malloc(n * sizeof(Product));
    *resultCount = 0;

    char nameLower[64];
    strncpy(nameLower, name, 64);
    toLowerCase(nameLower);

    for (int i = 0; i < n; i++) {
        char productNameLower[64];
        strncpy(productNameLower,products[i].name,64);
        toLowerCase(productNameLower);

        if (strstr(productNameLower, nameLower) != NULL) {
            result[*resultCount] = products[i];
            (*resultCount)++;
        }
    }
    return result;
}

Product* searchByCategory(char* category, int n, Product products[], int* resultCount) {
    Product* result = (Product*)malloc(n * sizeof(Product));
    *resultCount = 0;

    char categoryLower[64];
    strncpy(categoryLower, category, 64);
    toLowerCase(categoryLower);

    for (int i = 0; i < n; i++) {
        char productCategoryLower[64];
        strncpy(productCategoryLower,products[i].category,64);
        toLowerCase(productCategoryLower);

        if (strcmp(productCategoryLower, categoryLower) == 0) {
            result[*resultCount] = products[i];
            (*resultCount)++;
        }
    }
    return result;
}

int main(){
    int numberOfProducts;
    char keyword[64],category[64];

    printf("Masukkan jumlah produk: ");
    scanf("%d", &numberOfProducts);
    while (getchar() != '\n'); 

    Product* products = (Product*)malloc(numberOfProducts * sizeof(Product));
    create(numberOfProducts, products);

    printf("\nMasukkan kata kunci: ");
    fgets(keyword, 64, stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; 

    printf("Masukkan kategori: ");
    fgets(category, 64, stdin);
    category[strcspn(category, "\n")] = '\0'; 

    int resultCount;
    Product* searchResults = searchName(keyword, numberOfProducts, products, &resultCount);

    if (resultCount > 0) {
        printf("\n Produk yang mengandung kata kunci \"%s\":\n", keyword);
        for (int i = 0; i < resultCount; i++) {
            printf("%d. %s\n",i+1, searchResults[i].name);
        }
    } else {
        printf("\nTidak ada produk yang mengandung kata kunci \"%s\".\n", keyword);
        printf("\nMencari produk dengan kategori yang sama...\n");

        free(searchResults);
        searchResults = searchByCategory(category,numberOfProducts,products,&resultCount);

        if (resultCount > 0) {
            for (int i = 0; i < resultCount; i++) {
                printf("%d. %s\n",i+1, searchResults[i].name);    
            }
        } else {
            printf("Tidak ada produk yang ditemukan dalam kategori \"%s\".\n", category);
        }
    }

    free(searchResults);

    for (int i = 0; i < numberOfProducts; i++) {
        free(products[i].name);
        free(products[i].category);
    }
    free(products);

    return 0;
}