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

void adicionarAulaAoAluno(Aluno *aluno, const Aula *aula) {
    if (aluno->numAulas < 5) {
        aluno->aulas[aluno->numAulas] = *aula;
        aluno->numAulas++;
    } else {
        printf("O aluno já possui o número máximo de aulas.\n");
    }
}

int main() {
    Aluno alunos[2];

    Aula aulaFutebol = {"futebol", "R$ 40,00", 0};
    Aula aulaVolei = {"volei", "R$ 100,00", 1};

    // Adicionando aulas aos alunos
    adicionarAulaAoAluno(&alunos[0], &aulaFutebol);
    adicionarAulaAoAluno(&alunos[1], &aulaVolei);

    // Acessando informações dos alunos e suas aulas
    for (int i = 0; i < 2; i++) {
        printf("Aluno %d: %s\n", i + 1, alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Aulas:\n");
        for (int j = 0; j < alunos[i].numAulas; j++) {
            printf("Aula %d: %s\n", j + 1, alunos[i].aulas[j].tipo);
            printf("Preço: %s\n", alunos[i].aulas[j].preco);
            printf("Boolean: %d\n", alunos[i].aulas[j].boolean);
        }
        printf("\n");
    }

    return 0;
}