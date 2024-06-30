function soma(a, b) {
    return a + b;
}

console.log(soma(2, 3));  // Saída: 5

function exibirMensagem(mensagem) {
    console.log(mensagem);
}

exibirMensagem('Olá, mundo!');  // Saída: Olá, mundo!


function incrementar() {
    // Variável pilha-dinâmica: local à função e redefinida a cada chamada
    let contador = 0;

    // Variável "estática": valor mantido entre chamadas
    if (typeof incrementar.valorEstático === 'undefined') {
        incrementar.valorEstático = 0;
    }

    contador++;
    incrementar.valorEstático++;

    console.log("Contador (local): " + contador);
    console.log("Valor Estático: " + incrementar.valorEstático);
}

incrementar(); // Contador (local): 1, Valor Estático: 1
incrementar(); // Contador (local): 1, Valor Estático: 2
incrementar(); // Contador (local): 1, Valor Estático: 3

const cumprimentar = function(nome) {
    console.log("Olá, " + nome + "!");
};

const nomeDaFuncao = (parametro1, parametro2) => {
    // Código a ser executado
};



function somar(...numeros) {
    let total = 0;
    for (let numero of numeros) {
        total += numero;
    }
    return total;
}

console.log(somar(1, 2, 3)); // 6
console.log(somar(10, 20, 30, 40)); // 100
console.log(somar(5)); // 5


function calcularArea(lado, altura) {
    return lado * altura;
}

let area = calcularArea(4.5, 10.6);
console.log(area); // 47.7


function dividir(a, b) {
    try {
        if (b === 0) {
            throw new Error("Divisão por zero não é permitida.");
        }
        return a / b;
    } catch (erro) {
        console.error("Ocorreu um erro: " + erro.message);
    } finally {
        console.log("Operação de divisão finalizada.");
    }
}

let resultado = dividir(10, 2);
console.log("Resultado: " + resultado); // Resultado: 5

resultado = dividir(10, 0);
// Saída: Ocorreu um erro: Divisão por zero não é permitida.
// Operação de divisão finalizada.


function alterarValor(x) {
    x = 10;
    console.log("Dentro da função: " + x); // 10
}

let a = 5;
alterarValor(a);
console.log("Fora da função: " + a); // 5



function alterarObjeto(obj) {
    obj.valor = 10;
}

let meuObjeto = { valor: 5 };
alterarObjeto(meuObjeto);
console.log("Depois da função: " + meuObjeto.valor); // 10


console.log(typeof 42); // "number"
console.log(typeof "hello"); // "string"
console.log(typeof true); // "boolean"
console.log(typeof undefined); // "undefined"
console.log(typeof { name: "Alice" }); // "object"
console.log(typeof null); // "object" (isto é considerado um bug em JavaScript)
console.log(typeof function() {}); // "function"
console.log(typeof Symbol("id")); // "symbol"


let arr = [1, 2, 3];
console.log(arr instanceof Array); // true
console.log(arr instanceof Object); // true

let date = new Date();
console.log(date instanceof Date); // true
console.log(date instanceof Object); // true






