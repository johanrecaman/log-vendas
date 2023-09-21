#include <stdio.h>
#include <stdlib.h>

struct Product{
    int id;
    float price;
    char name[50];
};

struct Sales{
    int seller_id;
    int product_id;
    int quantity;
};

struct Product* readProducts(){
    int num;
    FILE *fptr;
    fptr = fopen("./log/produtos.txt", "r");

    fscanf(fptr, "%d", &num);

     struct Product* produtos = malloc(num * sizeof(struct Product));

    for (int i = 0; i < num; i++){
        fscanf(fptr, "%d %f %s", &produtos[i].id, &produtos[i].price, &produtos[i].name);
    }

    fclose(fptr);

    return produtos;
}

int main() {
    readProducts();
    return 0;
}
