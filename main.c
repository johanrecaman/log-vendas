#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int totalSold;
    int id;
    float price;
    char name[50];
}Product;

typedef struct{
    int size;
    int seller_id;
    int product_id;
    int quantity;
}Sale;

typedef struct{
    int size;
    int id;
    char name[50];
    int totalSold;
}Seller;

Product* readProducts(){
    int num;
    FILE *fptr;
    fptr = fopen("./log/produtos.txt", "r");

    fscanf(fptr, "%d", &num);

    Product* produtos = malloc(num * sizeof(Product));

    for (int i = 0; i < num; i++){
        fscanf(fptr, "%d %f %s", &produtos[i].id, &produtos[i].price, &produtos[i].name);
        produtos[i].size = num;
        produtos[i].totalSold = 0;
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
        sales[i].size = num;
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
        sellers[i].size = num;
        sellers[i].totalSold = 0;
    }

    fclose(fptr);

    return sellers;
}

int totalSold(){
    int total = 0;
    Sale* sales = readSales();
    Product* products = readProducts();

    for (int i = 0; i < sales[0].size; i++){

        int quantity = sales[i].quantity;

        for(int j = 0; j < products[0].size; j++){
            if (products[j].id == sales[i].product_id){
                total += products[j].price * quantity;
            }
        }
    }

    return total;
}

Product* totalByProduct(){
    Sale* sales = readSales();
    Product* products = readProducts();

    for (int i = 0; i < sales[0].size; i++){

        int quantity = sales[i].quantity;

        for(int j = 0; j < products[0].size; j++){
            if (products[j].id == sales[i].product_id){
                products[j].totalSold += products[j].price * quantity;
            }
        }
    }

    return products;
}

Seller* totalBySeller(){
    Sale* sales = readSales();
    Product* products = readProducts();
    Seller* sellers = readSellers();

    for (int i = 0; i < sales[0].size; i++){

        int quantity = sales[i].quantity;

        for(int j = 0; j < products[0].size; j++){
            if (products[j].id == sales[i].product_id){

                for(int k = 0; k < sellers[0].size; k++){
                    if (sellers[k].id == sales[i].seller_id){
                        sellers[k].totalSold += products[j].price * quantity;
                    }
                }
            }
        }
    }

    return sellers;
}

int main() { 
    return 0;
}
