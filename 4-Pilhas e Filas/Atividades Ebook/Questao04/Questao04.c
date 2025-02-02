#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    char *senha;
    struct no *proximo;
} No;

typedef struct {
    int contador;
    No *inicio;
    No *fim;
} Fila;

// Inicializa fila vazia:
void criar_fila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->contador = 0;
}

char *gerarSenha(int numero) {
    char *senha = (char*)malloc(sizeof(char) * 20);
    if (senha == NULL) {
        printf("\nErro ao alocar memória para a senha!\n");
        return NULL;
    } else {
        sprintf(senha, "IFET%d", numero);  // Gera a senha
        return senha;
    }
}

// Enfileirar
void inserir_na_fila(Fila *fila) {
    No *novo = (No*)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para novo nó!\n");
    } else {
        novo->senha = gerarSenha(++fila->contador);  // Incrementa o contador ao gerar a senha
        novo->proximo = NULL;

        if (fila->inicio == NULL) {
            fila->inicio = novo;
            fila->fim = novo;
        } else {
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
    }
}

No *remover_da_fila(Fila *fila) {
    No *remover = NULL;
    if (fila->inicio == NULL) {
        printf("\nNão há elementos para remover!\n");
    } else {
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        if (fila->inicio == NULL) {  // Se a fila ficou vazia, também precisamos zerar o fim.
            fila->fim = NULL;
        }

        // Decrementa o contador após remover uma senha
        fila->contador--;
    }
    if (remover != NULL) {
        printf("Senha %s, favor comparecer ao balcão de atendimento!\n", remover->senha);
    }
    return remover;
}

void imprimir_fila(Fila *fila) {
    No *temp = fila->inicio;
    printf("-------FILA-------\n");

    if (temp == NULL) {
        printf("Fila vazia.\n");
    } else {
        while (temp != NULL) {
            printf("%s ", temp->senha);
            temp = temp->proximo;
        }
    }
    printf("\n-------FIM FILA-------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila fila;
    criar_fila(&fila);

    int opcao;

    do {
        printf("*****************************************\n");
        printf("SISTEMA DE GERENCIAMENTO DE SENHAS\n");
        printf("*****************************************\n");
        printf("\n1 - Gerar senha\n2 - Atender ao usuário\n3 - Imprimir Senhas\n4 - Sair do sistema\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            inserir_na_fila(&fila);
            break;
        case 2:
            {
                No *removido = remover_da_fila(&fila);
                if (removido != NULL) {
                    free(removido->senha);  // Libera a memória da senha alocada
                    free(removido);  // Libera a memória do nó removido
                }
            }
            break;
        case 3:
            imprimir_fila(&fila);
            break;
        case 4:
            printf("Encerrando atendimento!");
        default:
            if (opcao != 4) {
                printf("\nOpção Inválida!\n");
            }
        }

    } while (opcao != 4);

    return 0;
}
