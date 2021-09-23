#include <stdio.h>
#include <stdlib.h>
struct node {
    int element; struct node *left; struct node *right;
};
/* n の指す木を traverse */
void traverse (struct node *n) {
    if (n == NULL)
        return;
    /* # */
    traverse (n->right);
    /* EDF & traverse */
    
    traverse (n->left);
    printf ("%d\n", n->element);
    /* #07ť traverse */
    
}
int main() {
    struct node *n1, *n2, *n3, *n4, *n5;
    n1 = malloc(sizeof (struct node));
    n1->element = 1;
    n1->left = NULL;
    n1->right = NULL;
    n2 = malloc(sizeof (struct node));
    n2->element = 2; n2->left = NULL;
    n2->right = NULL;
    n3 = malloc(sizeof (struct node));
    n3->element = 3; n3->left = n1;
    n3->right = n2;
    n4 = malloc(sizeof(struct node));
    n4->element = 4; n4->left = NULL;
    n4->right = NULL;
    n5 = malloc(sizeof (struct node));
    n5->element = 5;
    n5->left = n3;
    n5->right = n4;
    traverse (n5);
    free (n5);
    free (n4);
    free (n3);
    free (n2);
    free (n1);
    printf ("tree kadai finished\n");
    return 0;
}
