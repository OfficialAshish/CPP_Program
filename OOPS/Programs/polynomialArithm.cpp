#include <iostream>
#include <Stack>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
    Term *next;

public:
    Term() : coeff(1), exp(0), next(NULL)
    { /*  cout << "\nconstr..\n"; */
    }
    ~Term()
    { /* cout << "\ndestrc...\n"; */
    }

    friend class Polyn;
    friend Term *allocTerms();
    friend Term *allocTerms(int); // overload
};

class Polyn
{
public:
    Term *HeadToPolyn;

public:
    Polyn() : HeadToPolyn(NULL)
    { /* cout << "\nconstr..\n"; */
    }
    ~Polyn()
    { /* cout << "\nDestruct....\n";  */
    }
    void deallocTerms();
    Polyn &addition(Polyn &p2);
    Polyn &substraction(Polyn &p2);
    void displayPolyn();

    void creatPoly();
    void addTerm(Term *);
};

void Polyn::displayPolyn()
{
    cout << "\n Polynomial ::>  ";
    Term *tmpHead = HeadToPolyn;
    while (tmpHead)
    {
        cout << " (" << tmpHead->coeff << "x^" << tmpHead->exp << ") +";
        tmpHead = tmpHead->next;
    }
    // cout << "\nDone..\n";
}
void Polyn::deallocTerms()
{
    Term *polyHead = HeadToPolyn;
    Term *tmp = NULL;
    // static int i;
    // cout << "\n " << i++;
    while (polyHead)
    {
        tmp = polyHead->next;
        delete polyHead;
        cout << "*";
        polyHead = tmp;
    }
}

Term *allocTerms(int cof)
{
    Term *tmpTerm = new Term();
    tmpTerm->coeff = cof;
    // tmpTerm->exp = 0;
    return tmpTerm;
}

Term *allocTerms()
{
    int cof, exp;
    cout << "\nEnter Coefficient :";
    cin >> cof;
    cout << "\nEnter Exponent :";
    cin >> exp;
    Term *tmpTerm = new Term();
    tmpTerm->coeff = cof;
    tmpTerm->exp = exp;
    return tmpTerm;
}

// implementation...

void Polyn::addTerm(Term *newTerm)
{
    Term *tmpHead = HeadToPolyn;
    if (!HeadToPolyn)
    {
        HeadToPolyn = newTerm;
    }
    else
    {
        while (tmpHead->next)
        {
            tmpHead = tmpHead->next;
        }
        tmpHead->next = newTerm;
    }
}

void Polyn::creatPoly()
{
    int ch = 1;
    Term *newTerm = NULL;
    Term *tailTerm = NULL;
    do
    {
        newTerm = allocTerms();
        if (!HeadToPolyn)
        {
            HeadToPolyn = newTerm;
            tailTerm = newTerm;
        }
        else
        {
            tailTerm->next = newTerm;
            tailTerm = newTerm;
        }

        cout << "\nWant to add more terms(0/1) : ";
        cin >> ch;

    } while (ch != 0);
}

Polyn &Polyn::addition(Polyn &p2)
{
    static Polyn p3;
    Term *p1_head = this->HeadToPolyn;
    Term *p2_head = p2.HeadToPolyn;
    Term *p3_tmp = allocTerms(0);
    p3.HeadToPolyn = p3_tmp;
    while (p1_head or p2_head)
    {
        if (p1_head->next or p2_head->next)
            p3_tmp->next = allocTerms(0);
        if (p1_head->exp == p2_head->exp)
        {
            p3_tmp->coeff = p1_head->coeff + p2_head->coeff;
            p3_tmp->exp = p1_head->exp;
            p1_head = p1_head->next;
            p2_head = p2_head->next;
        }
        else
        {
            if (p1_head->exp > p2_head->exp)
            {
                p3_tmp->coeff = p1_head->coeff;
                p3_tmp->exp = p1_head->exp;
                p1_head = p1_head->next;
            }
            else
            {
                p3_tmp->coeff = p2_head->coeff;
                p3_tmp->exp = p2_head->exp;
                p2_head = p2_head->next;
            }
        }
        p3_tmp = p3_tmp->next;
    }
    return p3;
}

Polyn &Polyn::substraction(Polyn &p2)
{
    static Polyn p3;
    Term *p1_head = this->HeadToPolyn;
    Term *p2_head = p2.HeadToPolyn;
    Term *p3_tmp = allocTerms(0);
    p3.HeadToPolyn = p3_tmp;
    while (p1_head or p2_head)
    {
        if (p1_head->next or p2_head->next)
            p3_tmp->next = allocTerms(0);
        if (p1_head->exp == p2_head->exp)
        {
            p3_tmp->coeff = p1_head->coeff - p2_head->coeff;
            p3_tmp->exp = p1_head->exp;
            p1_head = p1_head->next;
            p2_head = p2_head->next;
        }
        else
        {
            if (p1_head->exp > p2_head->exp)
            {
                p3_tmp->coeff = p1_head->coeff;
                p3_tmp->exp = p1_head->exp;
                p1_head = p1_head->next;
            }
            else
            {
                p3_tmp->coeff = -p2_head->coeff;
                p3_tmp->exp = p2_head->exp;
                p2_head = p2_head->next;
            }
        }
        p3_tmp = p3_tmp->next;
    }
    return p3;
}

int main(int argc, char const *argv[])
{
    Polyn p1, p2;

    /*
    Term t1, t2, t3;
    Term r1, r2, r3;

    t1.coeff = 4;
    t1.exp = 4;
    t2.coeff = 3;
    t2.exp = 3;
    t3.coeff = 2;
    t3.exp = 2;

    r1.coeff = 5;
    r1.exp = 6;
    r2.coeff = 5;
    r2.exp = 3;
    r3.coeff = 4;
    r3.exp = 2;

    p1.addTerm(&t1);
    p1.addTerm(&t2);
    p1.addTerm(&t3);

    p2.addTerm(&r1);
    p2.addTerm(&r2);
    p2.addTerm(&r3);
    */

    // comment these 4lines, and uncomment above for defalut polynomial..
    cout << "\nEnter p1:\n";
    p1.creatPoly();
    cout << "\nEnter p2:\n";
    p2.creatPoly();

    cout << "\nP1: ";
    p1.displayPolyn();
    cout << "\nP2: ";
    p2.displayPolyn();

    cout << "\nAddition..";
    Polyn p3 = p1.addition(p2);
    p3.displayPolyn();

    cout << "\nSubstraction..";
    Polyn p4 = p1.substraction(p2);
    p4.displayPolyn();

    // deallocation
    cout << "\n\ndealloc.. ";
    p1.deallocTerms();
    p2.deallocTerms();
    p3.deallocTerms();
    p4.deallocTerms();

    return 0;
}
