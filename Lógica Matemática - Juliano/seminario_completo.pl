% declarar cliente() como dinâmico para criar novos clientes durante o código
:-dynamic cliente/8.

% BASE DE CLIENTES
% modelo:  cliente(Nome, Plano, Duracao, Altura_Antiga, Altura_Atual, Peso_Antigo, Peso_Atual).
/*
cliente(joana, básico, semestral, definição, 1.89, 1.95, 65, 76.2).
cliente(maria, básico, mensal, emagrecimento, 1.60, 1.61, 68, 65).
cliente(nicole, básico, trimestral, ganho, 1.70, 1.80, 72, 75).
cliente(julio, básico, mensal, ganho, 1.75, 1.65,  80, 78).
cliente(ana, vip, mensal, emagrecimento, 1.55, 1.55 , 65, 60).
cliente(carlos, vip, semestral, ganho, 1.80, 1.80, 85, 82).
cliente(pedro, vip, mensal, emagrecimento, 1.75, 1.70, 78, 75).
cliente(fernanda, vip, trimestral, definição, 1.65, 1.80, 70, 68).
cliente(joao, premium, semestral, ganho, 1.85, 1.85, 90, 88).
cliente(patricia, premium, mensal, definição, 1.70, 1.70, 72, 70).
*/

% Fatos sobre os planos e descontos
plano(básico, 70).
plano(vip, 90).
plano(premium, 120).

% Descontos trimestrais
desconto_trimestral(básico, 10).
desconto_trimestral(vip, 10).
desconto_trimestral(premium, 10).

% Descontos semestrais
desconto_semestral(básico, 20).
desconto_semestral(vip, 20).
desconto_semestral(premium, 20).

% Verifica se o valor pago está dentro de uma margem aceitável
verificar_pagamento(X, Valor) :-
	Valor >= X.

% Calcula o valor com desconto trimestral
calcular_desconto_trimestral(ValorOriginal, Desconto, ValorFinal) :-
	ValorDescontado is ValorOriginal - (ValorOriginal * (Desconto / 100)),
	ValorFinal is max(ValorDescontado, 0). % Garante que o valor final não seja negativo.

% Calcula o valor com desconto semestral
calcular_desconto_semestral(ValorOriginal, Desconto, ValorFinal) :-
	ValorDescontado is ValorOriginal - (ValorOriginal * (Desconto / 100)),
	ValorFinal is max(ValorDescontado, 0). % Garante que o valor final não seja negativo.

pagamento(Plano, Duracao) :-
	plano(Plano, ValorOriginal),
	(
    	Duracao = trimestral ->
    	desconto_trimestral(Plano, Desconto),
    	calcular_desconto_trimestral(ValorOriginal, Desconto, ValorFinal);
    	Duracao = semestral ->
    	desconto_semestral(Plano, Desconto),
    	calcular_desconto_semestral(ValorOriginal, Desconto, ValorFinal);
    	ValorFinal = ValorOriginal
	),
	write('O valor do plano escolhido é: '), write(ValorOriginal), nl,
	write('O valor com desconto é: '), write(ValorFinal), nl,
	repeat,
	write('Digite o valor a ser pago: '),
	read(Valor),
	(
    	verificar_pagamento(ValorFinal, Valor) ->
    	Troco is Valor - ValorFinal,
    	(
        	Troco >= 0 ->
        	write('Pagamento realizado. Troco: '), write(Troco), nl;
        	write('Pagamento realizado. Sem troco.'), nl
    	);
    	write('Pagamento irregular! Tente novamente.'), nl, fail
	).

plano_valido(Plano) :-
	member(Plano, [básico, vip, premium]).

definir_perfilDeTreino(Objetivo) :-
	write('Seja bem vindo!'), nl,
	write('Qual o seu objetivo na academia?:'), nl,
	write('1 - Emagrecer'), nl,
	write('2 - Definição'), nl,
	write('3 - Ganho de massa muscular'), nl,
	read(Objetivo), write('Plano '), write(Objetivo), write(' escolhido com sucesso!'), nl.


consultar_frequenciaMensal(_) :-
    write('Dias Presentes esse Mês (0 - 30): '), read(Presenca),
    write('Sua frequência nesse mês foi de: %'), Freq is ((Presenca / 30) * 100), format('~2f', [Freq]).

definir_peso(Antigo, Atual) :-
	nl, write('Qual era o seu Peso antes da academia (em kg)? '), read(Antigo),
	write('Qual é o seu Peso Atual (em kg)? '), read(Atual).

definir_altura(Antiga, Atual) :-
	nl, write('Qual era a sua Altura antes da academia (em metros)? '), read(Antiga),
	write('Qual é a sua Altura Atual (em metros)? '), read(Atual).

matricula :-
	write('Digite seu nome para realizar matrícula: '),
	read(Nome),
	repeat,
	write('Escolha seu plano'), nl,
	write('Plano básico, R$70: acesso à academia'), nl,
	write('Plano vip, R$90: acesso às cadeiras de massagem'), nl,
	write('Plano premium R$120: direito a um instrutor particular'), nl,
	read(Plano),
	(
    	plano_valido(Plano) ->
    	repeat,
    	write('Escolha a duração do plano (mensal, trimestral, semestral): '), nl,
    	read(Duracao),
    	(
        	member(Duracao, [mensal, trimestral, semestral]) ->
        	(
            	plano(Plano, _) ->
            	pagamento(Plano, Duracao), !;
            	write('Plano inválido. Tente novamente.'), nl, fail
        	);
        	write('Duração inválida. Tente novamente.'), nl, fail
    	);
    	write('Plano inválido. Tente novamente.'), nl, fail
	),
		
definir_perfilDeTreino(Objetivo_Cliente),
	%- Caso seja necessário consultar a frequencia : consultar_frequenciaMensal(Nome),
	

   nl, nl, write('Suponha que tenha se passado 1 ano desde a matrícula...'), nl,
	definir_peso(Peso_Antigo, Peso_Atual),
	definir_altura(Altura_Antiga, Altura_Atual),
	
	% adicionar cliente
	assert(cliente(Nome, Plano, Duracao, Objetivo_Cliente, Altura_Antiga, Altura_Atual, Peso_Antigo, Peso_Atual)),
    progresso(Nome).



% Para rodar, digite matricula e pressione Enter.


% Início da função PROGRESSO
% essa função tem como parâmetro Nome_Cliente, portanto, use a função da seguinte forma: progresso(matheus)
% essa função avalia o Índice de Massa Corporal (IMC) da pessoa antes e depois da academia, classificando-o como abaixo do peso, normal, sobrepeso, etc. Também compara as medidas de peso e altura da pessoa.


% Calcular o IMC
calcular_imc(Altura, Peso, IMC) :- IMC is Peso / (Altura * Altura).

% Classificar o IMC
classificar_imc(IMC, 'Abaixo do peso') :- IMC < 18.5.
classificar_imc(IMC, 'Peso normal') :- IMC >= 18.5, IMC < 25.
classificar_imc(IMC, 'Sobrepeso') :- IMC >= 25, IMC < 30.
classificar_imc(IMC, 'Obesidade grau I') :- IMC >= 30, IMC < 35.
classificar_imc(IMC, 'Obesidade grau II') :- IMC >= 35, IMC < 40.
classificar_imc(IMC, 'Obesidade grau III') :- IMC >= 40.

% Classificar o progresso da altura
classificar_progresso_altura(Antiga, Atual) :-
    Antiga < Atual,
    Porcentagem is ((Atual / Antiga) - 1) * 100,
    Diferenca is Atual - Antiga,
    write(' cresceu '), format('~2f', Diferenca), write(' metros, totalizando uma diferença de altura de '),
    format('~2f', Porcentagem), write('%.').

classificar_progresso_altura(Antiga, Atual) :-
    Antiga > Atual,
    Porcentagem is ((Antiga / Atual) - 1) * 100,
    Diferenca is Antiga - Atual,
    write(' diminuiu '), format('~2f', Diferenca), write(' metros, totalizando uma diferença de altura de '),
    format('~2f', Porcentagem), write('%.').

classificar_progresso_altura(Antiga, Atual) :-
    Antiga == Atual,
    write(' não cresceu nem diminuiu.').

% Classificar o progresso do peso
classificar_progresso_peso(Antigo, Atual) :-
    Antigo > Atual,
    Porcentagem is ((Antigo / Atual) - 1) * 100,
    Diferenca is Antigo - Atual,
    write(' emagreceu '), format('~2f', Diferenca), write(' kg, totalizando uma diferença de peso de '),
    format('~2f', Porcentagem), write('%.').

classificar_progresso_peso(Antigo, Atual) :-
    Antigo < Atual,
    Porcentagem is ((Atual / Antigo) - 1) * 100,
    Diferenca is Atual - Antigo,
    write(' engordou '), format('~2f', Diferenca), write(' kg, totalizando uma diferença de peso de '),
    format('~2f', Porcentagem), write('%.').

classificar_progresso_peso(Antigo, Atual) :-
    Antigo == Atual,
    write(' não engordou nem emagreceu.').


% Buscar o progresso físico da pessoa pelo NOME
progresso(Nome_Cliente) :-
    (   
      cliente(Nome_Cliente, _, _, _, Altura_Anterior, Altura_Atual, Peso_Anterior, Peso_Atual) ->

		calcular_imc(Altura_Anterior, Peso_Anterior, IMC_Antigo),
		classificar_imc(IMC_Antigo, Classificacao_Antiga),

		calcular_imc(Altura_Atual, Peso_Atual, IMC_Atual),
		classificar_imc(IMC_Atual, Classificacao_Atual),

		nl, write('PROGRESSO FÍSICO - '), write(Nome_Cliente), nl, nl,

		write('- O IMC antigo de '), write(Nome_Cliente), write(' era igual a '), format('~2f', IMC_Antigo), write(' - Classificação: '), write(Classificacao_Antiga), nl,
		write('- Atualmente, o IMC de '), write(Nome_Cliente), write(' é igual a '), format('~2f', IMC_Atual), write(' - Classificação: '), write(Classificacao_Atual), nl,nl,

		write('- A altura antiga de '), write(Nome_Cliente), write(' era igual a '), format('~2f', Altura_Anterior), write(' metros e a altura atual é igual a '), format('~2f', Altura_Atual), write(' metros.'), nl,
		write(' - '), write(Nome_Cliente), classificar_progresso_altura(Altura_Anterior, Altura_Atual), nl, nl,

		write('- O peso antigo de '), write(Nome_Cliente), write(' era igual a '), write(Peso_Anterior), write(' kg e o peso atual é igual a '), write(Peso_Atual), write(' kg.'), nl,
		write(' - '), write(Nome_Cliente), classificar_progresso_peso(Peso_Anterior, Peso_Atual), nl
    ;
      write('Cliente não encontrado. Verifique o nome e tente novamente.'), nl
   ).