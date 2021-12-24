#include<stdio.h>
#include<cstring>
#define MAX_PRODUCT_NAME_LEN 20
int readSalesFile(FILE* fp, struct ProductSalesList* prodList, struct DailySalesList* dailySales){
    int numberSalesRead = 0, valuesRead;
    struct SingleSaleRecord* saleRec = { 0 };
    char productName[MAX_PRODUCT_NAME_LEN];

    while(!feof(fp)){
        valuesRead = fscanf(fp,"%[^/]/%d/%1f/%d/%d/%d%*c",
        productName,&saleRec.numberSold,&saleRec.salePrice,
        &saleRec.saleDate.month,&saleRec.saleDate.day,
        &saleRec.saleDate.year);
        if(valuesRead > 0){
            addSale(prodList, dailySales, productName, &salesRec);
            numberSalesRead++;
        }
    }
    return numberSalesRead;
}
int main(){
    int option;
    printf("******Seneca******\n");
    printf("\n Select one of the following options: ");
    printf("1 - View All Sales \n");
    printf("2 - View Sales By Product \n");
    printf("3 - View Sales by Date sorted by revenue \n");
    printf("0 - Exit \n");
    scanf("%d",&option);
    struct ProductSalesList
    {
        char productName[20];
        int numberOfSales;
        float salePrice;
        char day[20];
        char month[20];
        char year[20];
        float revenue;
    }Sales;
    
    //struct DailySalesList{ 0 };
    
    //Create a file named 'sales.txt' and input sales information
    //Using the readSalesFiles appears redundant
    //One would rather open the file and read from the file directly
    FILE *fp;
    fp = fopen("sales.txt","r");
    switch (option)
    {
    case 1:
        printf("DAY     MONTH       YEAR        PRODUCT     #SOLD       PRICE\n");
        for(int i=0;i<5;i++){
            fread(&Sales,sizeof(struct ProductSalesList), 1, fp);
            printf("%c     %c       %c      %c      %d      %2lf",Sales.day,Sales.month,Sales.year,Sales.productName,Sales.numberOfSales,Sales.salePrice);

        }

        break;
    case 2:
        printf("PRODUCT     #SOLD       REVENUE\n");
        for(int i=0;i<5;i++){
             fread(&Sales,sizeof(struct ProductSalesList), 1, fp);
            printf("%c      %d      %2lf",Sales.productName,Sales.numberOfSales,Sales.revenue);
        }
        break;
    case 3:
        printf("REVENUE     DAY     MONTH       YEAR\n");
        for(int i=0;i<5;i++){
            fread(&Sales,sizeof(struct ProductSalesList), 1, fp);
            printf("%2lf     %c       %c      %c",Sales.revenue,Sales.day,Sales.month,Sales.year);
        }
    case 0:
        printf("You exited the program\n");
    
    default:
        printf("Option selected does not exist.\n");
        break;
    }


}