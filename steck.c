#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 1000
struct stack
{
    int size;
    int into[STACKSIZE];
};

void push(struct stack *kur, int wa)
{
    if (kur->size == STACKSIZE)
    {
        printf("HET");
    }
    else
    {
        kur->into[kur->size] = wa;
        kur->size++;
    }

}

int pop(struct stack *kur)
{
    if (kur->size == 0)
    {
        printf("Error");
        return 0;
    }
    else
    {
        kur->size--;
        return kur->into[kur->size];
    }

}

int main()
{
    struct stack kurwakulyator;
    kurwakulyator.size = 0;
    char actual[100];
    int result, size, cifra;
    int a, b;
    while (scanf("%s", actual) != EOF)
    {

        size = strlen(actual);
        if (((actual[0] <= '9') && (actual[0] >= '0')) || (size > 1))
        {
            cifra = atoi(actual);
            push(&kurwakulyator, cifra);
        }
        else
        {
            if (size == 0)
                break;
            b = pop(&kurwakulyator);
            a = pop(&kurwakulyator);
            switch(actual[0])
            {
            case '+':
                push(&kurwakulyator, a + b);
                break;
            case '-':
                push(&kurwakulyator, a - b);
                break;
            case '*':
                push(&kurwakulyator, a * b);
                break;
            case '/':
                push(&kurwakulyator, a / b);
            default:
                printf("error");
            }

        }
    }
    result = pop(&kurwakulyator);
    printf("%d", result);
    getchar();
    system("pause");
    return 0;
}
