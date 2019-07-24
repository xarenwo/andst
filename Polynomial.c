#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// p(x) = 3x^5 2x^4+5x^2+2x+7
// polynomial has coefficient and power for the variable, let's see how we can represent it.
// we can make a structure with as many cols as coefficients and a row for the exponent.

struct Term
{
    int coefficient;
    int exponent;
};

struct Polynomial
{
    int NumOFNZero;
    struct Term *term;
};

void CreatePolynomial(struct Polynomial *p)
{
    printf("Number of non-zero terms : ");
    scanf("%d",&p->NumOFNZero);
    p->term = (struct Term *)malloc(p->NumOFNZero*sizeof(struct Term));
    printf("Enter coefficient and exponent one by one: (ex 2x^2 = 2 2) :");
    for(int i=0;i<p->NumOFNZero;i++){
        scanf("%d%d",&p->term[i].coefficient,&p->term[i].exponent);
    }
    printf("You inserted polynomial as : ");
    for(int i=0;i<p->NumOFNZero;i++){
        if(i==p->NumOFNZero-1) {
            if(p->term[i].exponent == 0){
                printf("%d \n",p->term[i].coefficient);
            } else {
                printf("%d*x^%d \n",p->term[i].coefficient,p->term[i].exponent);
            }
        } else {
            printf("%d*x^%d + ",p->term[i].coefficient,p->term[i].exponent);
        }

    }
}

void SolvePolynomialForX(struct Polynomial *p, int x) {
    int solution = 1;
    for(int i=0;i<p->NumOFNZero;i++){
        solution += (((p->term[i].coefficient)*pow(x,p->term[i].exponent)));
        printf("Adding %d \n",solution);
    }
    printf("The solution for your polynomial is : %d\n",solution);
}

void SolvePolynomialSecondDegree(struct Polynomial *p) {
    float sol1,sol2;
    sol1 = (((-1*((int)p->term[1].coefficient)) + (float)sqrt( (float)((int)pow((p->term[1].coefficient),2))\
                                                               - 4*((int)p->term[0].coefficient*(int)p->term[2].coefficient) ))\
                                                                / (2*(int)p->term[0].coefficient));
    sol2 = (((-1*((int)p->term[1].coefficient)) - (float)sqrt( (float)((int)pow((p->term[1].coefficient),2))\
                                                               - 4*((int)p->term[0].coefficient*(int)p->term[2].coefficient) ))\
                                                                / (2*(int)p->term[0].coefficient));
    printf("Solutions are %f | %f \n",(float)sol1,(float)sol2);
}
int main(){
    struct Polynomial p;
    CreatePolynomial(&p);
    SolvePolynomialForX(&p,5);
    SolvePolynomialSecondDegree(&p);
    printf("Hi there \n");
    return 0;
}
