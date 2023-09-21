#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    float price;
    char name[50];
}Product;

typedef struct{
    int seller_id;
    int product_id;
    int quantity;
}Sale;

typedef struct{
    int id;
    char name[50];
}Seller;

Product* readProducts(){
    int num;
    FILE *fptr;
    fptr = fopen("./log/produtos.txt", "r");

    fscanf(fptr, "%d", &num);

    Product* produtos = malloc(num * sizeof(Product));

    for (int i = 0; i < num; i++){
        fscanf(fptr, "%d %f %s", &produtos[i].id, &produtos[i].price, &produtos[i].name);
    }

    fclose(fptr);

    return produtos;
}

Sale* readSales(){
    int num;
    FILE *fptr;
    fptr = fopen("./log/vendas.txt", "r");

    fscanf(fptr, "%d", &num);

    Sale* sales = malloc(num * sizeof(Sale));

    for (int i = 0; i < num; i++){
        fscanf(fptr, "%d %d %d", &sales[i].seller_id, &sales[i].product_id, &sales[i].quantity);
    }

    fclose(fptr);

    return sales;
}

Seller* readSellers(){
    int num;
    FILE *fptr;

    fptr = fopen("./log/vendedores.txt", "r");

    fscanf(fptr, "%d", &num);

    Seller* sellers = malloc(num * sizeof(Seller));

    for (int i = 0; i < num; i++){
        fscanf(fptr, "%d %s", &sellers[i].id, &sellers[i].name);
    }

    fclose(fptr);

    return sellers;
}

int main() {
    return 0;
}
