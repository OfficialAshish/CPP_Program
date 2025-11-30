#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// Defines the size of the company series (2 characters + 1 for null terminator)
#define COMPANY_SER_SZ (2 + 1)

// Uncomment this line to set a maximum serial number for products
// #define MAX_SERIALNUM (26*26)

// Defines the size of the product series (company series + 4 characters)
#define PROD_SER_SZ (COMPANY_SER_SZ + 4)

// Defines the maximum number of companies
#define TOT_COMP (670)

// Defines the maximum number of unique products
#define TOT_PROD_UNQ (67500)

// Defines the default and maximum quantity for each unique product
#define TOT_PROD_QUANT (300)

// structures

// Structure representing a company
typedef struct company
{
    char companyName[20];               // Name of the company
    char companySeries[COMPANY_SER_SZ]; // Company series (e.g., AA)
    short int companyRating;            // Rating of the company
} s_company;

// Structure representing a date
typedef struct date
{
    short unsigned int dd; // Day
    short unsigned int mm; // Month
    short unsigned int yy; // Year
} s_date;

typedef struct uniqueProductInfo
{
    char productName[30];
    s_company productCompany; // its caste & series it belongs

    char productSeries[PROD_SER_SZ]; // 6bytes total(AA)(BD89)

    unsigned int productQuantity;

    // struct quantity productQuantity; // total num of quantity present for each unique product

    // char productSeries[TOT_PROD_QUANT][PROD_SER_SZ];

    unsigned int productPrice;

    short int productRating;

    s_date manufactureDate;
    s_date expiryDate;

} s_productInfo;

// Global Declaration..

s_productInfo productInfo[TOT_PROD_UNQ]; // Each unique company
s_company companyInfo[TOT_COMP];

static int productIndex = 1; // total unique prod present until, for respective company
static int companyIndex = 1; // total num of company present until

// Prototypes!..

char *uniqueCompanySerialAssign(int); // step1, Assign a unique serial number to a company
char *uniqueProductSerialAssign(int); // step2, ,step1 required before this func. to give expected result

int searchProduct_Linear(char *);                                     // Search for a product by its serial number, returns index
int getUniqueProductDetail();                                         // Get details of a specific product
int getAllProductDetail();                                            // Get details of all products
int getAllProductSerial();                                            // Get serial numbers of all products
int getCompanyNProduct();                                             // Get details of companies and their products
int addProduct_auto();                                                // Automatically add a product (test mode)
int addproduct();                                                     // Manually add a product
int removeProduct();                                                  // Remove a specific product
int removeAllProd();                                                  // Remove all products
int removeAllComp();                                                  // Remove all companies
int exitPrgm();                                                       // Exit the program
void updateDate_autoProd(short unsigned int &, short unsigned int &); // Update product dates for random prod's date

// main function..
int main()
{
    // default example products..

    // strcpy(productInfo[productIndex].productName, "LG Laptop");

    // strcpy(productInfo[productIndex].productCompany.companyName, "Pvt. LG Limited");

    // strcpy(productInfo[productIndex].productCompany.companySeries, uniqueCompanySerialAssign(productIndex));

    // strcpy(productInfo[productIndex].productSeries, uniqueProductSerialAssign(productIndex));

    // productInfo[productIndex].productCompany.companyRating = 7;

    // productInfo[productIndex].productPrice = 34000;
    // // productInfo[0].productQuantity.quantityIndex ;
    // productInfo[productIndex].productRating = 6;

    // productInfo[productIndex].manufactureDate.dd = 2;
    // productInfo[productIndex].manufactureDate.mm = 4;
    // productInfo[productIndex].manufactureDate.yy = 2022;

    // productIndex++;

    short int option;
    do
    {
        cout << "\nWelcome Sir, Have a Great Day!...\n";
    restart:
        cout << "\n\t1 : Add Product.\n";
        cout << "\n\t2 : Create Product Auto (TEST MODE!).\n";
        cout << "\n\t3 : Get Single Product Info.\n";
        cout << "\n\t4 : Print All Product\'s Serial Number.\n";
        cout << "\n\t5 : Print All Companies and their Products.\n";
        cout << "\n\t6 : Print All Products Details.\n";
        cout << "\n\t7 : Remove Product.\n";
        cout << "\n\t8 : Remove ALL Products.\n";
        cout << "\n\t9 : Remove ALL Companies.\n";
        cout << "\n\t11 : Exit Program!.\n";
        // cout << "\n\t0 : Force Stop!.\n";
        cout << "\nSelect Option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            option = addproduct();
            break;
        case 2:
            option = addProduct_auto();
            break;
        case 3:
            option = getUniqueProductDetail();
            break;
        case 4:
            option = getAllProductSerial();
            break;
        case 5:
            option = getCompanyNProduct();
            break;
        case 6:
            option = getAllProductDetail();
            break;
        case 7:
            option = removeProduct();
            break;
        case 8:
            option = removeAllProd();
            break;
        case 9:
            option = removeAllComp();
            break;
        case 11:
            exitPrgm();
            break;
        default:
        {
            printf("%d, Wrong Option Selected! \n", option);
            goto restart;
            // break;//for option 0
        }
        }

    } while (option != '\0');

    return 0;
}

// Functions

char *uniqueCompanySerialAssign(int index)
{
    static char v01 = 'A', v02 = 'A';
    static char tempSer[3];

    if ((companyIndex <= TOT_COMP))
    {

        // for (int i = 1; i <= companyIndex; ++i)
        // {
        //     if (strcmp(productInfo[i].productCompany.companyName, productInfo[productIndex].productCompany.companyName) == 0)
        //     {
        //         return (productInfo[i].productCompany.companySeries);
        //     }
        // }

        for (int i = 1; i < companyIndex; ++i)
        {
            if (strcmp(companyInfo[i].companyName, productInfo[productIndex].productCompany.companyName) == 0)
            {
                return (companyInfo[i].companySeries);
            }
        }
        strcpy(companyInfo[companyIndex].companyName, productInfo[productIndex].productCompany.companyName);
        companyInfo[companyIndex].companyRating = productInfo[productIndex].productCompany.companyRating;

        sprintf(tempSer, "%c%c", v02, v01);
        strcpy(companyInfo[companyIndex].companySeries, tempSer);

        // Requirements for next serial assignments...UPDATING!

        companyIndex++;

        if (v01 < 90)
        {
            v01++;
        }
        else if (v01 == 90 && v02 < 90)
        {
            v02++;
            v01 = 'A';
        }
        else if (v01 == 90 && v02 == 90)
        {
            cout << "\nCompany Series Assignment is Full, Cannot Assign more!...Aborting\n";
            // return NULL;
            exit(2);
        }
        else
        {
            cout << "\nSomething wrong in company serial assignment... Aborting!...\n";
            // return NULL;
            exit(2);
        }
    }
    return tempSer;
}

char *uniqueProductSerialAssign(int index)
{
    static char tempSerial[7];
    static char v4 = 'A', v3 = 'A';
    static int v2, v1;

    if (productIndex <= TOT_PROD_UNQ)
    {
        sprintf(tempSerial, "%s%c%c%d%d", productInfo[productIndex].productCompany.companySeries, v4, v3, v2, v1);

        // cout << "\nproduct_serires: " << tempSerial << endl;
        // Requirements for next serial assignments...UPDATING!

        productInfo[productIndex].productQuantity += 1;

        if (v1 < 9)
            v1++;
        else
        {
            if ((v1 == 9) && (v2 < 9))
            {
                v2++;
                v1 = 0;
            }
            else if ((v2 == 9) && (v3 < 90))
            {
                v3++;
                v2 = 0;
                v1 = 0;
            }
            else if ((v3 == 90) && (v4 < 90))
            {
                v4++;
                v3 = 'A';
                v2 = 0;
                v1 = 0;
            }
            else if ((v1 == 9) && (v2 == 9) && (v3 == 90) && (v4 == 90))
            {
                cout << "\nSeries Assignment is Full, Cannot Assign more!...Aborting\n";
                // return NULL;
                exit(1);
            }
            else
            {
                cout << "\nSomething wrong in company serial assignment... Aborting!...\n";
                // return NULL;
                exit(1);
            }
        }
    }

    return tempSerial;
}

int addproduct()
{
    cout << ("\n\t\tAdding Product... \n");
    short int condition = 0, subCondition_1 = 0;
    unsigned int tempNum = 0;
    char cond_yn, f_ch;
    char tempCompName[15], tempProdName[25];

    do
    {

        // printf("\n1: Add Product by Company...\n2: Add Product Individually...\n3: Exit!\nSelect Option : ");
        // company details related to product
        // cout << ("\n1: Add Product Individually...\n2: Exit!\nSelect Option : ");

        // cin >> condition;
        // if (condition == 1)
        {
        again:
            printf(("\nWant to ...\n\t1: Enter Company Name,\n\t2: Select Company Name?\nSelect Option : "));
            cin >> subCondition_1;
            int i = 0;
        addsome:
            if (subCondition_1 == 1)
            {
                printf("\n\tEnter Company Name : ");
                f_ch = getchar();
                cin.getline(tempCompName, 15);
                strcpy(productInfo[productIndex].productCompany.companyName, tempCompName);
            }
            else if (subCondition_1 == 2)
            {
                if (productIndex > 1)
                {
                compAg:
                    short int option;
                    cout << ("\n\t\tCompanies Names Are: ");

                    for (i = 1; i < companyIndex; i++)
                    {
                        printf("\n\t\t\t%d : %s ,\n", i, companyInfo[i].companyName);
                    }
                    cout << ("\nSelect Company Name :");
                    cin >> option;
                    if (option > 0 && option < i)
                    {
                        strcpy(productInfo[productIndex].productCompany.companyName, companyInfo[option].companyName);
                        cout << ("\nComp._Done\n");
                    }
                    else
                    {
                        cout << "\n"
                             << option << ", Wrong index of company! Try Again...\n";
                        goto compAg;
                    }
                }
                else
                {
                    cout << ("\n\tNo Company to Show!...Add some.\n");
                    subCondition_1 = 1;
                    goto addsome;
                }
            }
            else
            {
                // company name for each product
                cout << ("\nWARNING!...Company Name Required For Expected Product Serial No.\n");

                cout << ("\nWant to still Skip...Y/N or Enter to skip...");
                // cin >> cond_yn;
                f_ch = getchar();
                cond_yn = getchar();
                if (cond_yn == 110 || cond_yn == 78)
                {
                    goto again;
                }
                else
                {
                    cout << ("\n\tOkay!\n");
                }
            }

            // rating company
            if (i > 0)
            {
                cout << "\nCompany Rated from already one...\n";
            }
            else if (subCondition_1 == 1)
            {
                cout << ("\nWant to give Rating to Company? ...Y/N or Press Enter to Skip!: ");

                // cond_yn = getchar();
                // cin >> cond_yn;
                // f_ch = getchar();
                cond_yn = getchar();

                if ((cond_yn == 89) || (cond_yn == 121))
                {
                    cout << "\nRate your Company : ";
                    cin >> tempNum;
                    productInfo[productIndex].productCompany.companyRating = tempNum;
                }
                else
                {
                    productInfo[productIndex].productCompany.companyRating = 7;
                    cout << ("\nDefault set to 7 out of 10..\n");
                }
            }

            // product name
            cout << ("\nEnter Product Name : ");
            f_ch = getchar();
            cin.getline(tempProdName, 25);
            strcpy(productInfo[productIndex].productName, tempProdName);

            strcpy(productInfo[productIndex].productCompany.companySeries, uniqueCompanySerialAssign(productIndex));

            strcpy(productInfo[productIndex].productSeries, uniqueProductSerialAssign(productIndex));

            // rating product
            cout << ("\nWant to give Rating to product? ...Y/N or Press Enter to Skip!: ");

            // cin >> cond_yn;
            // f_ch = getchar();
            cond_yn = getchar();

            if ((cond_yn == 89) || (cond_yn == 121))
            {
                cout << ("\nEnter Rating out of 10 : ");
                cin >> tempNum;
                productInfo[productIndex].productRating = tempNum;
            }
            else
            {
                productInfo[productIndex].productRating = 7;
                printf("\nDefault set to 7 out of 10..\n");
            }

            // set price
            cout << ("\nEnter Price : ");
            cin >> tempNum;
            productInfo[productIndex].productPrice = tempNum;

            // Manufactured date
            cout << ("\nWant to give Manufactured date to product? ...Y/N or Press Enter to Skip!: ");
            // cin >> cond_yn;
            f_ch = getchar();
            cond_yn = getchar();
            short unsigned int td = 0, tm = 0, ty = 0;
            if ((cond_yn == 89) || (cond_yn == 121))
            {
                cout << ("\nEnter Manufactured Date (dd mm yy) : ");
                cin >> td >> tm >> ty;
                productInfo[productIndex].manufactureDate.dd = td;
                productInfo[productIndex].manufactureDate.mm = tm;
                productInfo[productIndex].manufactureDate.yy = ty;
            }
            else
            {
                productInfo[productIndex].manufactureDate.dd = td;
                productInfo[productIndex].manufactureDate.mm = tm;
                productInfo[productIndex].manufactureDate.yy = ty;
                cout << ("\nDefault set to 0 0 0...\n");
            }

            // expiry date
            cout << ("\nWant to give Expiry date to product? ...Y/N or Press Enter to Skip!: ");
            // cin >> cond_yn;
            f_ch = getchar();
            cond_yn = getchar();
            td = 0;
            tm = 0;
            ty = 0;
            if ((cond_yn == 89) || (cond_yn == 121))
            {
                cout << ("\nEnter Expiry Date (dd mm yy) : ");
                cin >> td >> tm >> ty;
                productInfo[productIndex].expiryDate.dd = td;
                productInfo[productIndex].expiryDate.mm = tm;
                productInfo[productIndex].expiryDate.yy = ty;
            }
            else
            {
                productInfo[productIndex].expiryDate.dd = td;
                productInfo[productIndex].expiryDate.mm = tm;
                productInfo[productIndex].expiryDate.yy = ty;
                cout << ("\nDefault set to 0 0 0...\n");
            }

            printf("\n\tSir, %d\'th Product Added Successfully! .\n", productIndex);

            cout << ("\n\tPrinting Added Product...\n");
            printf("\nComp_name: %s,  Prod_name: %s,\nPrice: %d,  Quantity: %d,  Expiry_D: %d,%d,%d,\nCompany_serial: %s,  Product_serial: %s \n", productInfo[productIndex].productCompany.companyName, productInfo[productIndex].productName, productInfo[productIndex].productPrice, productInfo[productIndex].productQuantity, productInfo[productIndex].expiryDate.dd, productInfo[productIndex].expiryDate.mm, productInfo[productIndex].expiryDate.yy, productInfo[productIndex].productCompany.companySeries, productInfo[productIndex].productSeries);
            cout << "\n\t-------+----------+---------+---------+---------+----------+---------+--------\n";

            productIndex++;

            cout << "\nPress Enter To Continue...";
            getchar();
            getchar();

            // cout << "\nprindex: " << productIndex;
        }
        /*
        else if (condition == 2)
        {
            cout << ("\nExiting! Product Not Added...\n");
            return 20;
        }
        else
        {
            printf("\n%d ,Wrong Option Selected! Try Again...\n", condition);
        }
        */
    } while (0);

    return 20;
}

int getAllProductDetail()
{
    cout << "\n\tPrinting All Products...\n";

    for (int i = 1; i < productIndex; ++i)
    {
        cout << "\nCompany\'s Name is:         " << productInfo[i].productCompany.companyName << endl;

        cout << "\nCompany\'s Rating is:       " << productInfo[i].productCompany.companyRating << endl;

        cout << "\nCompany\'s Series is:       " << productInfo[i].productCompany.companySeries << endl;

        cout << "\nProduct\'s Name is:         " << productInfo[i].productName << endl;

        cout << "\nProduct\'s Price is:        " << productInfo[i].productPrice << endl;

        cout << "\nProduct\'s Serial Num. is:  " << productInfo[i].productSeries << endl;

        cout << "\nProduct\'s Quantity is:     " << productInfo[i].productQuantity << endl;

        cout << "\nProduct\'s Rating is:       " << productInfo[i].productRating << endl;

        cout << "\nProduct\'s ManufC. Date is: " << productInfo[i].manufactureDate.dd;
        cout << " / " << productInfo[i].manufactureDate.mm;
        cout << " / " << productInfo[i].manufactureDate.yy << endl;

        cout << "\nProduct\'s Expiry Date is:  " << productInfo[i].expiryDate.dd;
        cout << " / " << productInfo[i].expiryDate.mm;
        cout << " / " << productInfo[i].expiryDate.yy << endl;
        cout << "\n\t-------+----------+---------+---------+---------+----------+---------+--------\n";
    }
    cout << "\n\t\tAll Printed!..." << endl;
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int searchProduct_Linear(char serialNum[7])
{
    for (int i = 1; i < productIndex; ++i)
    {
        if (strcmp(productInfo[i].productSeries, serialNum) == 0)
        {
            return i;
        }
    }
    cout << endl
         << serialNum << " is not in the Database! Try Again\n";
    return -1;
}

int getUniqueProductDetail()
{
    char serialNum[7];
    cout << "\nEnter Serial no. of the Product : ";
    cin >> serialNum;
    int index = searchProduct_Linear(serialNum);

    if (index > 0)
    {

        cout << "\n\t\tPrinting Detail... @" << serialNum << endl;

        cout << "\nCompany\'s Name is:          " << productInfo[index].productCompany.companyName << endl;

        cout << "\nCompany\'s Rating is:        " << productInfo[index].productCompany.companyRating << endl;

        cout << "\nCompany\'s Series is:        " << productInfo[index].productCompany.companySeries << endl;

        cout << "\nProduct\'s Name is:          " << productInfo[index].productName << endl;

        cout << "\nProduct\'s Price is:         " << productInfo[index].productPrice << endl;

        cout << "\nProduct\'s Serial Num. is:   " << productInfo[index].productSeries << endl;

        cout << "\nProduct\'s Quantity is:      " << productInfo[index].productQuantity << endl;

        cout << "\nProduct\'s Rating is:        " << productInfo[index].productRating << endl;

        cout << "\nProduct\'s ManufC. Date is:  " << productInfo[index].manufactureDate.dd;
        cout << " / " << productInfo[index].manufactureDate.mm;
        cout << " / " << productInfo[index].manufactureDate.yy << endl;

        cout << "\nProduct\'s Expiry Date is:   " << productInfo[index].expiryDate.dd;
        cout << " / " << productInfo[index].expiryDate.mm;
        cout << " / " << productInfo[index].expiryDate.yy << endl;
        cout << "\n\t-------+----------+---------+---------+---------+----------+---------+--------\n";

        cout << "\n\t\tAll Printed!..." << endl;
    }
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int getAllProductSerial()
{
    cout << "Product\'s Name are{::} "
         << "\t\tProduct\'s Serial No. are{::} " << endl;

    for (int i = 1; i < productIndex; ++i)
    {
        // cout << i << "  : " << productInfo[i].productName << "\t\t\t\t" << productInfo[i].productSeries;
        printf(" %d : %s \t\t\t %s", i, productInfo[i].productName, productInfo[i].productSeries);
        cout << endl;
    }
    cout << "\n\t\tAll Printed!..";
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int removeProduct()
{
    char serialnum[7];
    cout << "\n\tRemove Product...\n";
    cout << "\nEnter Product\'s Serial No. : ";
    cin >> serialnum;
    int index = searchProduct_Linear(serialnum);
    if (index > 0)
    {
        productInfo[index].productCompany.companyRating = 0;
        strcpy(productInfo[index].productCompany.companyName, "\0");
        strcpy(productInfo[index].productCompany.companySeries, "\0");
        productInfo[index].expiryDate = {0, 0, 0};
        productInfo[index].manufactureDate = {0, 0, 0};
        strcpy(productInfo[index].productSeries, "\0");
        strcpy(productInfo[index].productName, "\0");
        productInfo[index].productPrice = 0;
        productInfo[index].productQuantity = 0;
        productInfo[index].productRating = 0;

        cout << "\n\t\tProduct Removed Successfully!\n";
    }
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int exitPrgm()
{
    printf("Are you Sure, Want to Exit (y/n)? ...");
    char exitop;
    cin >> exitop;
    if (exitop == 'y' or exitop == 'Y')
    {
        printf("\n\t\tGood-Bye!\n\tThank-You For Using Our System Sir!\n\t\tSee-You-Soon!\n\n");
        cout << "\n\t-------+----------+---------+---------+---------+----------+---------+--------\n";

        exit(0);
    }
    else
        return 20;
}

int getCompanyNProduct()
{
    for (int i = 1; i < companyIndex; ++i)
    {
        cout << endl;
        cout << "C_" << i << " . Company Name :->\t" << companyInfo[i].companyName << endl;
        cout << " \nIt\'s Products Names are :-> \t\t Serial No.:->" << endl;
        for (int j = 1, k = 1; j < productIndex; ++j, ++k)
        {
            if (strcmp(productInfo[j].productCompany.companyName, companyInfo[i].companyName) == 0)
            {
                cout << "\tP_" << k << ".: \t" << productInfo[j].productName << "\t\t" << productInfo[j].productSeries << endl;
            }
        }
        cout << "\n\t\t-------+----------+---------+---------+---------+---------\n";
    }

    cout << "\n\tFetched Done...!";
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

void updateDate_autoProd(short unsigned int &dd, short unsigned int &mm)
{
    if (dd < 28)
    {
        dd++;
    }
    else if (dd == 28 && mm < 13)
    {
        mm++;
        dd = 1;
    }
    else
    {
        dd = 1;
        mm = 1;
    }
}

int addProduct_auto()
{
    cout << "\n\tAdding Random Products for Testing...\n";
    unsigned int prodNum;
    char tempComp[12];
    char tempProd[13];
    static int r1 = 1, r2 = 0, r3 = 0, r4 = 0, c1 = 1, c2 = 0, c3 = 0;
    static short unsigned int dd = 1, mm = 1;
    unsigned int currProdIndex = productIndex;

    if (productIndex == 1)
    {
        r1 = 1;
        r2 = 0;
        r3 = 0;
        r4 = 0;
        dd = 1;
        mm = 1;
    }
    if (companyIndex == 1)
    {
        c1 = 1;
        c2 = 0;
        c3 = 0;
    }

prAg:
    cout << "\nEnter Num. of Random Products to be Generated [min:10-max:7000] : ";
    cin >> prodNum;
    cout << endl
         << prodNum << endl;

    if (prodNum < 10)
    {
        cout << "\nMinimum Num. is 10. TRY AGAIN!\n";
        goto prAg;
    }

    for (int j = 1, i, price = 50000L, m = (prodNum / 10); j <= m; ++j)
    {
        sprintf(tempComp, "%s%d%d%d", "Company", c3, c2, c1);

        for (i = currProdIndex; i <= (currProdIndex + (prodNum / m) - 1); i++)
        {
            sprintf(tempProd, "%s%d%d%d%d", "Product", r4, r3, r2, r1);

            productInfo[i].productCompany.companyRating = 7;
            strcpy(productInfo[i].productCompany.companyName, tempComp);
            strcpy(productInfo[i].productCompany.companySeries, uniqueCompanySerialAssign(i));
            updateDate_autoProd(dd, mm);
            productInfo[i].manufactureDate = {dd, mm, 2022};
            productInfo[i].expiryDate = {dd, mm, 2026};
            strcpy(productInfo[i].productSeries, uniqueProductSerialAssign(i));
            strcpy(productInfo[i].productName, tempProd);
            productInfo[i].productPrice = price++;
            productInfo[i].productQuantity = 3;
            productInfo[i].productRating = 8;

            productIndex++;

            // updating for products name
            if (r1 < 9)
                r1++;
            else
            {
                if ((r1 == 9) && (r2 < 9))
                {
                    r2++;
                    r1 = 0;
                }
                else if ((r2 == 9) && (r3 < 9))
                {
                    r3++;
                    r2 = 0;
                    r1 = 0;
                }
                else if ((r3 == 9) && (r4 < 9))
                {
                    r4++;
                    r3 = 0;
                    r2 = 0;
                    r1 = 0;
                }
                else
                {
                    cout << "\nProduct Generation EXCEEDED!!!...\n";
                    return 20;
                }
            }
        }
        currProdIndex = productIndex;

        // updating for company names
        if (c1 < 9)
            c1++;
        else
        {
            if ((c1 == 9) && (c2 < 9))
            {
                c2++;
                c1 = 0;
            }
            else if ((c2 == 9) && (c3 < 9))
            {
                c3++;
                c2 = 0;
                c1 = 0;
            }
        }
    }
    cout << prodNum;
    cout << " , Products Generated...!" << endl;
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int removeAllProd()
{
    char option;
    cout << "\n\tWARNING!!!, Sure?(Y/N) Want to Remove All Product...";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
        for (int i = productIndex - 1; i > 0; --i)
        {
            productInfo[i].productCompany.companyRating = 0;
            strcpy(productInfo[i].productCompany.companyName, "\0");
            strcpy(productInfo[i].productCompany.companySeries, "\0");
            productInfo[i].expiryDate = {0, 0, 0};
            productInfo[i].manufactureDate = {0, 0, 0};
            strcpy(productInfo[i].productSeries, "\0");
            strcpy(productInfo[i].productName, "\0");
            productInfo[i].productPrice = 0;
            productInfo[i].productQuantity = 0;
            productInfo[i].productRating = 0;
            cout << "*";
        }
        cout << "\n\t\tAll Product Removed Successfully!\n";
        productIndex = 1;
    }
    else
        cout << "\nAborted!...\n";
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}

int removeAllComp()
{
    char option;
    cout << "\n\tWARNING!!!, Sure? (Y/N) Want to Remove All Companies...";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
        for (int i = companyIndex - 1; i > 0; --i)
        {
            strcpy(companyInfo[i].companyName, "\0");
            strcpy(companyInfo[i].companySeries, "\0");
            companyInfo[i].companyRating = 0;
            cout << "*";
        }
        cout << "\n\t\tAll Companies Data Removed Successfully!\n";
        companyIndex = 1;
    }
    else
        cout << "\nAborted!...\n";
    cout << "\nPress Enter To Continue...";
    getchar();
    getchar();
    return 20;
}