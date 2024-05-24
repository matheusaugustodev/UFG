import pandas as pd
from datetime import datetime

dados = pd.read_excel('dados.xlsx')

# 4 primeiras colunas
dados = dados.iloc[:, :4]

# converter para dataframe
dados = pd.DataFrame(dados)

#    chapa   nome data_admissao data_demissao
# 0   3543   joao    2020-04-02    2023-12-12
# 1   3546   jose    2019-12-08           NaT
# 2   5665  pedro    2021-06-14    2021-06-28

nomesMeses = ['Janeiro', 'Fevereiro', 'Março', 'Abril', 'Maio', 'Junho', 'Julho', 'Agosto', 'Setembro', 'Outubro', 'Novembro', 'Dezembro']

for index, row in dados.iterrows():
    informacoes = row.values
    
    chapa = informacoes[0]
    nome = informacoes[1]
    data_admissao = informacoes[2]
    data_demissao = informacoes[3]

    for i in range(2020, 2024):
        for j in range(1, 13):

            data_inicio_formatada = datetime(i, j, 1)
            data_final_formatada = datetime(i, j, 1)
            data_admissao_formatada = data_admissao
            data_demissao_formatada = data_demissao

            data_referencia = datetime(i, j, 1)

            valor_coluna = ''

            if data_referencia < data_admissao_formatada:
                valor_coluna = 'Não Trabalhou'
            elif data_referencia >= data_admissao_formatada and data_referencia <= data_demissao_formatada:
                valor_coluna = 'Trabalhou'
            elif data_referencia > data_demissao_formatada:
                valor_coluna = 'Ativo'
                
            nome_ano = i           
            nome_mes = nomesMeses[j - 1]
            
            dados.loc[index, f'{nome_mes} {nome_ano}'] = valor_coluna        
            
print(dados)

#  gerar excel

dados.to_excel('dados_tratados.xlsx', index=False)
