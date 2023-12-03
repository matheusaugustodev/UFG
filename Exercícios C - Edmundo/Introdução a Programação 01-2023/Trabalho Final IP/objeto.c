#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo[20];
    char preco[10];
    int boolean;
} Aula;

typedef struct {
    char nome[50];
    int idade;
    Aula aulas[5];
    int numAulas;
} Aluno;

void adicionarAula(Aluno *aluno, const char *tipo, const char *preco, int boolean) {
    if (aluno->numAulas < 5) {
        strcpy(aluno->aulas[aluno->numAulas].tipo, tipo);
        strcpy(aluno->aulas[aluno->numAulas].preco, preco);
        aluno->aulas[aluno->numAulas].boolean = boolean;
        aluno->numAulas++;
    } else {
        printf("O aluno já possui o número máximo de aulas.\n");
    }
}

void adicionarAluno(Aluno *alunos, int *numAlunos, const char *nome, int idade) {
    if (*numAlunos < 2) {
        strcpy(alunos[*numAlunos].nome, nome);
        alunos[*numAlunos].idade = idade;
        alunos[*numAlunos].numAulas = 0;
        (*numAlunos)++;
    } else {
        printf("O limite de alunos foi atingido.\n");
    }
}

int main() {
    Aluno alunos[2];
    int numAlunos = 0;

    adicionarAluno(alunos, &numAlunos, "João", 20);
    adicionarAula(&alunos[0], "futebol", "R$ 40,00", 0);

    adicionarAluno(alunos, &numAlunos, "Maria", 22);
    adicionarAula(&alunos[1], "volei", "R$ 100,00", 1);

    // Acessando informações dos alunos e suas aulas
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %s\n", i + 1, alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        for (int j = 0; j < alunos[i].numAulas; j++) {
            printf("Aula %d: %s\n", j + 1, alunos[i].aulas[j].tipo);
            printf("Preço: %s\n", alunos[i].aulas[j].preco);
            printf("Boolean: %d\n", alunos[i].aulas[j].boolean);
        }
        printf("\n");
    }

    return 0;
}
