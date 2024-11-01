#include <stdio.h>
#include <stdlib.h>

struct celula {
    int idade;
    float altura;
    struct celula *ptr_celula;
};

void inicializa_celula(struct celula *ptr, int idade, float altura) {
    ptr->idade = idade;
    ptr->altura = altura;
    ptr->ptr_celula = NULL;
}

void imprime_lista(struct celula *head) {
    struct celula *current = head;
    int index = 0;
    while (current != NULL) {
        printf("Célula %d: Idade = %d, Altura = %.2f\n", index, current->idade, current->altura);
        current = current->ptr_celula;
        index++;
    }
}

struct celula* excluir_no(struct celula *head, int pos) {
    if (head == NULL) return head;

    struct celula *temp = head;
    if (pos == 0) {
        head = temp->ptr_celula;
        free(temp);
        return head;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->ptr_celula;

    if (temp == NULL || temp->ptr_celula == NULL) return head;

    struct celula *next = temp->ptr_celula->ptr_celula;
    free(temp->ptr_celula);
    temp->ptr_celula = next;

    return head;
}

int main() {
    struct celula *head = NULL, *temp = NULL, *prev = NULL;

    for (int i = 0; i < 10; i++) {
        temp = (struct celula*) malloc(sizeof(struct celula));
        inicializa_celula(temp, 20 + i, 1.60 + (0.05 * i));
        if (head == NULL) {
            head = temp;
        } else {
            prev->ptr_celula = temp;
        }
        prev = temp;
    }

    printf("Lista Original:\n");
    imprime_lista(head);

    int pos;
    printf("\nInforme a posição do nó a ser excluído: ");
    scanf("%d", &pos);
    head = excluir_no(head, pos);

    printf("\nLista após exclusão:\n");
    imprime_lista(head);

    return 0;
}