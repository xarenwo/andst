#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i; //row
    int j; //col
    int x; //value
};


struct Sparse
{
    int m; //rows
    int n; //cols
    int num; //num of non zero elements
    struct Element *e; //pointer to array of elements (Element)
};

void CreateSMatrix(struct Sparse *s)
{
    int i;
    printf("Enter n of rows and columns : \n");
    scanf("%d%d",&s->m,&s->n); // scan rows and col, dimension of matrix into the structure s (Sparse matrix created and passed as parameter)
    printf("Enter number of non-zero elements : \n");
    scanf("%d",&s->num); // scan num of non zero elements
    //create array of elements in heap
    s->e = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter non-zero elements : \n");
    for(i=0;i<s->num;i++) {
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x); // scan the values to insert as Row , Column and Element (row,col position for element)
    }
}

void DisplaySMatrix(struct Sparse s)
{
    int i,j,k=0;
    printf("\n Your matrix is \n");
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if((i==s.e[k].i) && (j==s.e[k].j)) // if element exists and is not 0 at row i and col j, then display it.
            {
                printf("%d ",s.e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

void AddSMatrices(struct Sparse *s1, struct Sparse *s2)
{
    // check if matrices can be added n,m same
    if(s1->m != s2->m || s1->n != s2->n){
        return 0;
    }
    else
    {
        // they can be added, let's create a third matrix
        struct Sparse *sum;
        // create an object of sparse matrix and assign an array of elements.
        sum = (struct Sparse *)malloc(((s->num)*4)*sizeof(struct Sparse))
        sum->m = s1->m;
        sum->n = s1->n;
        //max size is s1 + s2 num
        sum->num = s1->num + s2->num;
        sum->e = (struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));

        int i,j,k=0;
        while(i<s1->num && j<s2->num)
        {
            if(s1->e[i].i < s2->e[j].i)
            {
                sum->e[k++] =s1->e[i++]; // if row of first is smaller than row of second copy row of first
            }
            else if(s1->e[i].i > s2->e[j].i)
            {
                sum->e[k++] = s2->e[j++]; // if row of first is bigger than row of second copy row of second
            }
            else if(s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++]; // if column of first ... copy column of first
            }
            else if(s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++]; // if column of first is bigger ... copy column of second.
            }
            else
            {
                sum->e[k++] = s1->e[i++]; // if they are equal then copy row of first 
                sum->e[k++].x = s2->e[j++].x; // also copy the element in that position
            }
        }
        for(;i<s1->num;i++) {
            sum->e[k++]= s1->e[i]; // copy remaining matrix from first
        }
        for(;j<s2->num;j++) {
            sum->e[k++]= s2->e[j]; // copy remaining matrix from second
        }
    }
}
int main()
{
    struct Sparse s;
    CreateSMatrix(&s);
    DisplaySMatrix(s);
    return 0;
}
