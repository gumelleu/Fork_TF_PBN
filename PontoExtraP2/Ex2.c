#include <stdio.h>
#include <stdlib.h>

struct celula {
    int idade;
    float altura;
    struct celula *prox;
    struct celula *ant;
};

void inicializa_celula(struct celula *ptr, int idade, float altura) {
    ptr->idade = idade;
    ptr->altura = altura;
    ptr->prox = NULL;
    ptr->ant = NULL;
}

void imprime_lista(struct celula *head) {
    struct celula *current = head;
    int index = 0;
    while (current != NULL) {
        printf("Célula %d: Idade = %d, Altura = %.2f\n", index, current->idade, current->altura);
        current = current->prox;
        index++;
    }
}

struct celula* excluir_no(struct celula *head, int pos) {
    if (head == NULL) return head;

    struct celula *temp = head;

    if (pos == 0) {
        head = temp->prox;
        if (head != NULL) head->ant = NULL;
        free(temp);
        return head;
    }

    for (int i = 0; temp != NULL && i < pos; i++)
        temp = temp->prox;

    if (temp == NULL) return head;

    if (temp->prox != NULL) temp->prox->ant = temp->ant;
    if (temp->ant != NULL) temp->ant->prox = temp->prox;

    free(temp);

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
            prev->prox = temp;
            temp->ant = prev;
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