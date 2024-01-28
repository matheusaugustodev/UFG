calcular_imc(Altura, Peso, IMC) :-
    IMC is round( (Peso / (Altura * Altura)) * 10) / 10.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC < 18.5,
    Classificacao_IMC = 'Abaixo do peso'.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC >= 18.5, IMC < 25,
    Classificacao_IMC = 'Peso normal'.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC >= 25, IMC < 30,
    Classificacao_IMC = 'Sobrepeso'.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC >= 30, IMC < 35,
    Classificacao_IMC = 'Obesidade grau I'.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC >= 35, IMC < 40,
    Classificacao_IMC = 'Obesidade grau II'.

classificar_imc(IMC, Classificacao_IMC) :-
    IMC >= 40,
    Classificacao_IMC = 'Obesidade grau III'.


classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem) :-
    Altura_Antiga > Altura_Atual, Classificacao = 'cresceu', Porcentagem is round( (((Altura_Antiga / Altura_Atual) - 1) * 100) * 10) / 10.

classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem) :-
    Altura_Antiga < Altura_Atual, Classificacao = 'diminuiu', Porcentagem is round( (((Altura_Atual / Altura_Antiga) - 1) * 100) * 10) / 10.

classificar_progresso_altura(Altura_Antiga, Altura_Atual, Classificacao, Porcentagem) :-
    Altura_Antiga == Altura_Atual, Classificacao = 'não cresceu nem diminuiu', Porcentagem is 0.


classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem) :-
    Peso_Antigo > Peso_Atual, Classificacao = 'emagreceu', Porcentagem is round( (((Peso_Antigo / Peso_Atual) - 1) * 100) * 10) /10.

classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem) :-
    Peso_Antigo < Peso_Atual, Classificacao = 'engordou', Porcentagem is round( (((Peso_Atual / Peso_Antigo) - 1) * 100) * 10) /10.

classificar_progresso_peso(Peso_Antigo, Peso_Atual, Classificacao, Porcentagem) :-
    Peso_Antigo == Peso_Atual, Classificacao = 'não engordou nem emagreceu', Porcentagem is 0.


progresso :-
    write('PROGRESSO FÍSICO'), nl, nl,
    
    write('Preciso saber de algumas medidas que você tinha antes de entrar na academia.'), nl,
    write('Qual era o seu peso antigo (em kg)?'),
    read(Peso_Anterior),
    write('Qual era a sua altura antiga (em metros)?'),
    read(Altura_Anterior),
    nl,

    write('Agora preciso saber das suas medidas atuais.'), nl,
    write('Qual é o seu peso atual (em kg)?'),
    read(Peso_Atual),
    write('Qual é a sua altura atual (em metros)?'),
    read(Altura_Atual),
    
    nl, nl, write('RESUMO DO PROGRESSO FÍSICO'), nl, nl,

    calcular_imc(Altura_Anterior, Peso_Anterior, IMC_Antigo),
    classificar_imc(IMC_Antigo, Classificacao_Antiga),

    write('O seu IMC era '), write(IMC_Antigo), write(' - Classificação: '), write(Classificacao_Antiga), nl,
    
    calcular_imc(Altura_Atual, Peso_Atual, IMC_Atual),
    classificar_imc(IMC_Atual, Classificacao_Atual),
    write('Atualmente o seu IMC é '), write(IMC_Atual), write(' - Classificação: '), write(Classificacao_Atual), nl,nl,
    
    classificar_progresso_altura(Altura_Anterior, Altura_Atual, Classificao_Altura, Porcentagem_Altura),
    write('A sua altura antiga era '), write(Altura_Anterior), write(' metros e a sua altura atual é '), write(Altura_Atual), write(' metros.'), nl,
    write('Você '), write(Classificao_Altura), write(', totalizando uma diferença de altura de '), write(Porcentagem_Altura), write('%.'), nl, nl,
    
    classificar_progresso_peso(Peso_Anterior, Peso_Atual, Classificao_Peso, Porcentagem_Peso),
	write('O seu peso antigo era '), write(Peso_Anterior), write(' kg e o seu peso atual é '), write(Peso_Atual), write(' kg.'), nl,
    write('Você '), write(Classificao_Peso), write(', totalizando uma diferença de peso de '), write(Porcentagem_Peso), write('%.'), nl, nl.

% para rodar o programa Progresso Físico, digite "progresso" e pressione Enter