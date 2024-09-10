#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node* PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

void ReadInput( List L1, List L2)
{
    char c;
    List p1 = L1, p2 = L2;

    printf("Enter elements for L1 (end with newline): ");
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            PtrToNode newNode = (List)malloc(sizeof(struct Node));
            newNode->Data = c;
            newNode->Next = NULL;
            p1->Next = newNode;
            p1 = newNode;
        }
    }

    printf("Enter elements for L2 (end with newline): ");
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            PtrToNode newNode = (List)malloc(sizeof(struct Node));
            newNode->Data = c;
            newNode->Next = NULL;
            p2->Next = newNode;
            p2 = newNode;
        }
    }
}

void PrintSublist( PtrToNode StartP )
{
    PtrToNode p = StartP;
    while(p != NULL)
    {
        printf("%c ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

PtrToNode Reverse(List L1)
{
    List pe = NULL, p = L1, ne;
    while (p != NULL)
    {
        ne = p->Next;
        p->Next = pe;
        pe = p;
        p = ne;
    }
    return pe;
}

PtrToNode Suffix( List L1, List L2)
{
    L1 = Reverse(L1->Next), L2 = Reverse(L2->Next);
    List pre = L1, p = L1, q = L2;
    if (p->Data != q->Data) return NULL;
    while (p != NULL && q != NULL && p->Data == q->Data) pre = p, p = p->Next, q = q->Next;
    pre->Next = NULL;
    return Reverse(L1);
}

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput(L1, L2);
    P = Suffix(L1, L2);
    PrintSublist(P);

    return 0;
}
