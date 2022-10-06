#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
    struct Term *next;
};

struct Term *allocTerms()
{
    int cof, exp;
    printf("\nEnter Coefficient :");
    scanf("%d", &cof);
    printf("\nEnter Exponent :");
    scanf("%d", &exp);
    struct Term *tmpTerm = (struct Term *)malloc(sizeof(struct Term));
    tmpTerm->coeff = cof;
    tmpTerm->exp = exp;
    tmpTerm->next = NULL; // without this addterm() wouldn't works => (while(tmpTerm->next = NULL))
    return tmpTerm;
}
struct Term *allocTermsDef(int cof)
{
    struct Term *tmpTerm = (struct Term *)malloc(sizeof(struct Term));
    tmpTerm->coeff = cof;
    tmpTerm->exp = 0;
    tmpTerm->next = NULL; // imp...
    // printf("\nresultant poly term\n");
    return tmpTerm;
}
void deallocate(struct Term **head)
{
    struct Term *tmp;
    while ((*head))
    {
        tmp = (*head)->next;
        free((*head));
        printf("*");
        (*head) = tmp;
    }
}
void displayPolyn(struct Term *tmpHead)
{
    printf("\n  Polynomial ::>  ");
    while (tmpHead)
    {
        printf(" ( %dx^%d ) +", tmpHead->coeff, tmpHead->exp);
        tmpHead = tmpHead->next;
    }
    // printf( "\nDone..\n");
}
struct Term *addition(struct Term *p1_head, struct Term *p2_head)
{
    static struct Term *p3_head;
    struct Term *p3_tmp_trvs = allocTermsDef(0);
    p3_head = p3_tmp_trvs;
    while (p1_head || p2_head)
    {
        if (p1_head->next || p2_head->next)
            p3_tmp_trvs->next = allocTermsDef(0);
        if (p1_head->exp == p2_head->exp)
        {
            p3_tmp_trvs->coeff = p1_head->coeff + p2_head->coeff;
            p3_tmp_trvs->exp = p1_head->exp;
            p1_head = p1_head->next;
            p2_head = p2_head->next;
        }
        else
        {
            if (p1_head->exp > p2_head->exp)
            {
                p3_tmp_trvs->coeff = p1_head->coeff;
                p3_tmp_trvs->exp = p1_head->exp;
                p1_head = p1_head->next;
            }
            else
            {
                p3_tmp_trvs->coeff = p2_head->coeff;
                p3_tmp_trvs->exp = p2_head->exp;
                p2_head = p2_head->next;
            }
        }
        p3_tmp_trvs = p3_tmp_trvs->next;
    }
    return p3_head;
}

struct Term *subtraction(struct Term *p1_head, struct Term *p2_head)
{
    static struct Term *p4_head;
    struct Term *p3_tmp_trvs = allocTermsDef(0);
    p4_head = p3_tmp_trvs;
    while (p1_head || p2_head)
    {
        if (p1_head->next || p2_head->next)
            p3_tmp_trvs->next = allocTermsDef(0);
        if (p1_head->exp == p2_head->exp)
        {
            p3_tmp_trvs->coeff = p1_head->coeff - p2_head->coeff;
            p3_tmp_trvs->exp = p1_head->exp;
            p1_head = p1_head->next;
            p2_head = p2_head->next;
        }
        else
        {
            if (p1_head->exp > p2_head->exp)
            {
                p3_tmp_trvs->coeff = p1_head->coeff;
                p3_tmp_trvs->exp = p1_head->exp;
                p1_head = p1_head->next;
            }
            else
            {
                p3_tmp_trvs->coeff = -p2_head->coeff;
                p3_tmp_trvs->exp = p2_head->exp;
                p2_head = p2_head->next;
            }
        }
        p3_tmp_trvs = p3_tmp_trvs->next;
    }
    return p4_head;
}

void addTerm(struct Term **p_tmpHead, struct Term *newTerm)
{
    if (!(*p_tmpHead))
    {
        (*p_tmpHead) = (newTerm);
    }
    else
    {
        struct Term *tmpHead = *p_tmpHead; // to avoid modification in real head pointer,creating tmp
        while (tmpHead->next)
        {
            tmpHead = tmpHead->next;
        }
        tmpHead->next = newTerm;
    }
}
/*
//static variable needs to be reinialize twice for second polynomial creation
// , but that can't possible,
struct Term *creatPoly()
{
    int ch = 1;
    static struct Term *newPolyn;
    struct Term *tmpTail;
    struct Term *newTerm = NULL;
    do
    {
        newTerm = allocTerms();
        if (!newPolyn)
        {
            newPolyn = newTerm;
            tmpTail = newPolyn;
        }
        else // alternative
        {
            tmpTail->next = newTerm;
            tmpTail = newTerm;
        }
        printf("\nWant to add more terms(0/1) : ");
        scanf("%d", &ch);

    } while (ch != 0);
    return newPolyn;
}
 */
void creatPoly(struct Term **newPolyn)
{
    int ch = 1;
    struct Term *tmpTail;
    struct Term *newTerm = NULL;
    do
    {
        newTerm = allocTerms();
        if (!(*newPolyn))
        {
            (*newPolyn) = newTerm;
            tmpTail = (*newPolyn);
        }
        else // alternative
        {
            tmpTail->next = newTerm;
            tmpTail = newTerm;
        }
        printf("\nWant to add more terms(0/1) : ");
        scanf("%d", &ch);

    } while (ch != 0);
}

int main(int argc, char const *argv[])
{

    struct Term t1, t2, t3;
    struct Term r1, r2, r3;
    struct Term *p1 = NULL, *p2 = NULL;

    t1.coeff = 4;
    t1.exp = 3;
    t1.next = NULL;
    t2.coeff = 3;
    t2.exp = 2;
    t2.next = NULL;
    t3.coeff = 2;
    t3.exp = 1;
    t3.next = NULL;

    addTerm(&p1, &t1);
    addTerm(&p1, &t2);
    addTerm(&p1, &t3);
    // printf("done");

    r1.coeff = 5;
    r1.exp = 3;
    r1.next = NULL;
    r2.coeff = 6;
    r2.exp = 2;
    r2.next = NULL;
    r3.coeff = 5;
    r3.exp = 1;
    r3.next = NULL;

    addTerm(&p2, &r1);
    addTerm(&p2, &r2);
    addTerm(&p2, &r3);

    // comment these 4lines, and uncomment above for defalut polynomial..

    // printf("\nEnter p1:\n");
    // creatPoly(&p1);
    // printf("\nEnter p2:\n");
    // creatPoly(&p2);
    printf("\nP1 : ");
    displayPolyn(p1);
    printf("\nP2 : ");
    displayPolyn(p2);

    printf("\nAddition..");
    struct Term *p3 = addition(p1, p2);
    displayPolyn(p3);

    printf("\nSubtraction..");
    struct Term *p4 = subtraction(p1, p2);
    displayPolyn(p4);

    // deallocate..
    printf("\n\nDeAllocat...");
    deallocate(&p1);
    deallocate(&p2);
    deallocate(&p3);
    printf("Done\n");
    return 0;
}