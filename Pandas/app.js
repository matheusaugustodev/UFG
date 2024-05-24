const dataInicio = '01/01/2020'
const dataFinal = '01/01/2023'

const dataAdmissao = '01/05/2020'
const dataDemissao = '01/05/2021'

for (let i=2020; i<=2023; i++) {

    for (let j=1; j<=12; j++) {

        const partesDataInicio = dataInicio.split('/')
        const partesDataFinal = dataFinal.split('/')
        const partesDataAdmissao = dataAdmissao.split('/')
        const partesDataDemissao = dataDemissao.split('/')

        const dataInicioFormatada = new Date(partesDataInicio[2], partesDataInicio[1]-1, partesDataInicio[0])
        const dataFinalFormatada = new Date(partesDataFinal[2], partesDataFinal[1]-1, partesDataFinal[0])
        const dataAdmissaoFormatada = new Date(partesDataAdmissao[2], partesDataAdmissao[1]-1, partesDataAdmissao[0])
        const dataDemissaoFormatada = new Date(partesDataDemissao[2], partesDataDemissao[1]-1, partesDataDemissao[0])

        const dataReferencia = new Date(i, j-1, 1)

        let valorColuna = ''

        if (dataReferencia < dataAdmissaoFormatada) {
            valorColuna = 'Não Trabalhou'
        } else if (dataReferencia >= dataAdmissaoFormatada && dataReferencia <= dataDemissaoFormatada) {
            valorColuna = 'Trabalhou'
        } else if (dataReferencia > dataDemissaoFormatada) {
            valorColuna = 'Ativo'
        }
    }

}
