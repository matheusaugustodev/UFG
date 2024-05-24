const listaDeNumeros = [1, 2, 3]
const media = calcularMediaAritmetica(listaDeNumeros)
console.log(media)

function calcularMediaAritmetica(lista) {
    const soma = lista.reduce((soma, numero) => soma + numero, 0)
    return soma / lista.length
}


// tipos de dados javascript e exemplos

// Number
const numero = 1
const numeroNegativo = -1

// String
const texto = "Olá, mundo!"

// Boolean
const verdadeiro = true

// // Array
// const lista = [1, 2, 3]

// // Object
// const objeto = { nome: "Fulano", idade: 30 }

// Function
function somar(a, b) {
    return a + b
}

// Undefined
let variavelNaoDefinida

// Null
const valorNulo = null

// Symbol
const simbolo = Symbol()

// BigInt
const numeroGrande = 1234567890123456789012345678901234567890n


// em js Tempo de Vida
// categorias do tempo de vida das variáveis em JavaScript, com exemplos de cada uma das:
// ○ Estática
// ○ Pilha – dinâmica
// ○ Heap explícito – dinâmica
// ○ Heap implícito – dinâmica

// Estática
const constante = 1

// Pilha – dinâmica
let variavel = 1

// Heap explícito – dinâmica
const objeto = { nome: "Fulano" }

// Heap implícito – dinâmica
const lista = [1, 2, 3]



const idade = 18
var nome = 'Matheus'
let sobrenome = 'Augusto'

// const idade = Number("18")

let peso = 85.9
peso = parseInt(peso)
// resultado: 85


function maior(a, b) {
    let m;
    if (a > b) m = a;
    else m = b;
    return m;
}

console.log(maior(10, 5)); // Saída: 10

const valor = 123

function new_id() {
    let id = 1 + valor
    return id
}

console.log(new_id()) // Saída: 124


let i = new Int32Array(1);
i[0] = 42;

console.log(i[0]); // Saída: 42

i = null; // Remove a referência ao objeto, permitindo que o coletor de lixo libere a memória


// let objeto = new Object();
// objeto.nome = "Exemplo";
// objeto.idade = 25;

// console.log(objeto.nome); // Saída: Exemplo


// array de heap dinâmico

const array = new Array()
array[0] = 1
array.push(4)
console.log(array) // Saída: [1, 4]


// usando var
if (true) {
    var variavel = 50
}
console.log(variavel) // Saída: 50


if (true) {
    let variavel = 50
    const constante = 100
    console.log(variavel) // Saída: 50
    console.log(constante) // Saída: 100
}
console.log(variavel) // Saída: variavel is not defined
console.log(constante) // Saída: constante is not defined


const casa = new Object()
casa.cor = "vermelha"
casa.portas = 3
console.log(casa) // Saída: { cor: 'vermelha', portas: 3 }


const pessoa = {
    nome: "João",
    idade: 30,
    cidade: "São Paulo"
}

console.log(pessoa.nome) // Saída: João
console.log(pessoa.idade) // Saída: 30
console.log(pessoa.cidade) // Saída: São Paulo



const resultado = (10 + 5) * 2 // Primeiro a expressão dentro dos parênteses é avaliada (precedência mais alta), depois a multiplicação
console.log(resultado) // Saída: 30


let hora = 14;

if (hora < 12) {
    console.log("Bom dia!");
} else {
    console.log("Boa tarde!");
}

let nota = 75;

if (nota >= 90) {
    console.log("Aprovado com nota A");
} else if (nota >= 80) {
    console.log("Aprovado com nota B");
} else if (nota >= 70) {
    console.log("Aprovado com nota C");
} else {
    console.log("Reprovado");
}



let velocidade = 80;
let mensagem = (velocidade > 70) ? "Ultrapassou a velocidade permitida" : "Dentro da velocidade permitida";
console.log(mensagem);




let diaSemana = 3;
let mensagem;

switch (diaSemana) {
    case 1:
        mensagem = "Hoje é segunda-feira.";
        break;
    case 2:
        mensagem = "Hoje é terça-feira.";
        break;
    case 3:
        mensagem = "Hoje é quarta-feira.";
        break;
    case 4:
        mensagem = "Hoje é quinta-feira.";
        break;
    case 5:
        mensagem = "Hoje é sexta-feira.";
        break;
    case 6:
        mensagem = "Hoje é sábado.";
        break;
    case 7:
        mensagem = "Hoje é domingo.";
        break;
    default:
        mensagem = "Número inválido de dia da semana.";
}

console.log(mensagem); // Saída: "Hoje é quarta-feira."


// Loop que imprime os números de 1 a 5
for (let i = 1; i <= 5; i++) {
    console.log(i);
}


let contador = 0;

// Loop que imprime os números pares até 10
while (contador <= 10) {
    if (contador % 2 === 0) {
        console.log(contador);
    }
    contador++;
}


let continuar = true;

while (continuar) {
    let resposta = prompt("Deseja continuar? (s/n)");

    if (resposta.toLowerCase() === 'n') {
        continuar = false;
    } else if (resposta.toLowerCase() !== 's') {
        alert("Resposta inválida. Por favor, responda 's' para sim ou 'n' para não.");
    }
}

console.log("Loop encerrado.");




let numeros = [1, 2, 3, 4, 5];

numeros.forEach(function(numero) {
    console.log(numero);
});



let contador = 1;

while (true) {
    
    const continuar = prompt("Digite 'continuar' para continuar ou 'parar' para parar:")

    if (continuar === 'parar') {
        break
    }

    contador++

    if (contador > 10) {
        contador = 1
    }
}
