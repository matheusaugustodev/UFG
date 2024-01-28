% cliente de teste
cliente('Matheus', vip, trimestral, 1.89, 1.95, 65, 76.2).


calcular_imc(Altura, Peso, IMC) :-
    IMC is round( (Peso / (Altura * Altura)) * 100) / 100.

% Classificar o IMC
classificar_imc(IMC, 'Abaixo do peso') :- IMC < 18.5.
classificar_imc(IMC, 'Peso normal') :- IMC >= 18.5, IMC < 25.
classificar_imc(IMC, 'Sobrepeso') :- IMC >= 25, IMC < 30.
classificar_imc(IMC, 'Obesidade grau I') :- IMC >= 30, IMC < 35.
classificar_imc(IMC, 'Obesidade grau II') :- IMC >= 35, IMC < 40.
classificar_imc(IMC, 'Obesidade grau III') :- IMC >= 40.

% Classificar o progresso da altura
classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem, Diferenca) :-
    Altura_Antiga < Altura_Atual, Classificacao = 'cresceu', Porcentagem is round( (((Altura_Atual / Altura_Antiga) - 1) * 100) * 10) / 10, Diferenca is round( (Altura_Atual - Altura_Antiga) * 100) / 100.

classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem, Diferenca) :-
    Altura_Antiga > Altura_Atual, Classificacao = 'diminuiu', Porcentagem is round( (((Altura_Antiga / Altura_Atual) - 1) * 100) * 10) / 10, Diferenca is round( (Altura_Antiga - Altura_Atual) * 100) / 100.

classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem, Diferenca) :-
    Altura_Antiga == Altura_Atual, Classificacao = 'não cresceu nem diminuiu', Porcentagem is 0, Diferenca is 0.

% Classificar o progresso do peso
classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem, Diferenca) :-
    Peso_Antigo > Peso_Atual, Classificacao = 'emagreceu', Porcentagem is round( (((Peso_Antigo / Peso_Atual) - 1) * 100) * 10) /10, Diferenca is round( (Peso_Antigo - Peso_Atual) * 100) / 100.

classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem, Diferenca) :-
    Peso_Antigo < Peso_Atual, Classificacao = 'engordou', Porcentagem is round( (((Peso_Atual / Peso_Antigo) - 1) * 100) * 10) /10, Diferenca is round( (Peso_Atual - Peso_Antigo) * 100) / 100.

classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem, Diferenca) :-
    Peso_Antigo == Peso_Atual, Classificacao = 'não engordou nem emagreceu', Porcentagem is 0, Diferenca is 0.

% Buscar o progresso físico da pessoa pelo NOME
progresso(Nome_Cliente) :-
    
    cliente(Nome_Cliente, Plano, Duracao, Altura_Anterior, Altura_Atual, Peso_Anterior, Peso_Atual),

    calcular_imc(Altura_Anterior, Peso_Anterior, IMC_Antigo),
    classificar_imc(IMC_Antigo, Classificacao_Antiga),
    
    calcular_imc(Altura_Atual, Peso_Atual, IMC_Atual),
    classificar_imc(IMC_Atual, Classificacao_Atual),

    classificar_progresso_altura(Altura_Anterior, Altura_Atual, Classificao_Altura, Porcentagem_Altura, Diferenca_Altura),

    classificar_progresso_peso(Peso_Anterior, Peso_Atual, Classificao_Peso, Porcentagem_Peso, Diferenca_Peso),
    
    
    nl, write('PROGRESSO FÍSICO - '), write(Nome_Cliente), nl, nl,

    write('- O IMC antigo de '), write(Nome_Cliente), write(' era igual a '), write(IMC_Antigo), write(' - Classificação: '), write(Classificacao_Antiga), nl,
    write('- Atualmente, o IMC de '), write(Nome_Cliente), write(' é igual a '), write(IMC_Atual), write(' - Classificação: '), write(Classificacao_Atual), nl,nl,
    
    write('- A altura antiga de '), write(Nome_Cliente), write(' era igual a '), write(Altura_Anterior), write(' metros e a altura atual é igual a '), write(Altura_Atual), write(' metros.'), nl,
    write(' - '), write(Nome_Cliente), write(' '), write(Classificao_Altura), write(' '), write(Diferenca_Altura), write(' metros, totalizando uma diferença de altura de '), write(Porcentagem_Altura), write('%.'), nl, nl,
    
    write('- O peso antigo de '), write(Nome_Cliente), write(' era igual a '), write(Peso_Anterior), write(' kg e o peso atual é igual a '), write(Peso_Atual), write(' kg.'), nl,
    write(' - '), write(Nome_Cliente), write(' '), write(Classificao_Peso), write(' '), write(Diferenca_Peso), write(' kg, totalizando uma diferença de peso de '), write(Porcentagem_Peso), write('%.'), nl, nl.


% para rodar o programa Progresso Físico, digite "progresso(Matheus)" e pressione Enter