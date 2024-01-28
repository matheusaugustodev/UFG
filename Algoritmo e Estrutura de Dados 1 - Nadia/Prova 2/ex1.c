// implemente somente o metodo seguinte para deletar a ultima ocorrencia de uma lista encadeada

struct Node
{
    int numero;
    struct Node *primeiro;
};

// deletar a ultima ocorrencia de um item na lista, dado o ponteiro para o primeiro nó da na lista
// retornar o ponteiro para o primeiro nó da lista
// a lista pode estar vazia

Node deleteUltimaOcorrencia(Node primeiro, int item) {
    // complete o metodo
};


/*

    como seria um exemplo de teste:

    input: 23 12 23 6
    output: 23 12 6

*/


struct Node* deleteUltimaOcorrencia(struct Node* primeiro, int item) {
    struct Node *temp = primeiro, *prev = NULL, *ultimaOcorrencia = NULL, *ultimaPrev = NULL;
    
    // Verificar se a lista está vazia
    if (primeiro == NULL) return primeiro;

    // Percorrer a lista para encontrar a última ocorrência do item
    while (temp != NULL) {
        if (temp->numero == item) {
            ultimaOcorrencia = temp;
            ultimaPrev = prev;
        }
        prev = temp;
        temp = temp->primeiro;
    }

    // Se o item não for encontrado, retorne o primeiro nó
    if (ultimaOcorrencia == NULL) return primeiro;

    // Se o item for encontrado, ajuste os ponteiros para excluir o nó da lista
    if (ultimaPrev != NULL) {
        ultimaPrev->primeiro = ultimaOcorrencia->primeiro;
    } else {
        primeiro = primeiro->primeiro;
    }

    // Retorne o primeiro nó
    return primeiro;
}