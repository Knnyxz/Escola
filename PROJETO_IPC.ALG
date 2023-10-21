Algoritmo "Projeto_IPC"

Var
n1, a1, a2, b10, b11, c10, c11, qv, qi , qt: inteiro
c, vlr1, vlr2, resto, soma1, soma2: inteiro
resp: caracter
por_valid, por_invalid: real

Inicio
escreval("=================================================================")
escreval("Nesse programa verificaremos se um cpf é válido ou inválido.")
escreval("=================================================================")

repita

vlr1 <- 10
vlr2 <- 11
soma1 <- 0
soma2 <- 0

      para c de 1 ate 9 faca
           escreval("Digite o ", c,"° digito do cpf: ")
           leia(n1)
           enquanto ((n1 < 0) ou (n1 > 9)) faca

                escreval("Digite apenas um numero ou apenas numeros positivos")
                escreval("Digite o ", c,"° digito do cpf: ")
                leia(n1)
           fimenquanto
           
           a1 <- n1 * vlr1
		     a2 <- n1 * vlr2

           soma1 <- soma1 + a1
		     soma2 <- soma2 + a2
		     vlr1 <- vlr1 - 1
		     vlr2 <- vlr2 - 1

           resto<- soma1 % 11
      
           se (c = 9) entao
              se (resto < 2) entao
                 b10 <- 0
              senao
                 b10 <- 11 - resto
              fimse
              soma2 <- soma2 + b10 * 2
           fimse
      fimpara
      
      resto <- soma2 % 11
      
      se (resto < 2) entao
         b11 <- 0
      senao
         b11 <- 11 - resto
      fimse
      
      para c de 10 ate 11 passo 1 faca
           escreval("Digite o ", c,"° digito do cpf: ")
           se (c = 10) entao
              leia(c10)
              enquanto (c10 < 0) ou (c10 > 9) faca
                   escreval("Digite apenas um numero ou numero positivos.")
                   escreval("Digite o ", c,"° digito do cpf: ")
                   leia(c10)
              fimenquanto
           senao
              leia(c11)
              enquanto (c11 < 0) ou (c11 > 9) faca
                   escreval("Digite apenas um numero ou numero positivos.")
                   escreval("Digite o ", c,"° digito do cpf: ")
                   leia(c11)
              fimenquanto
           fimse
      fimpara

      se (c10 = b10) e (c11 = b11) entao
         escreval("Seu cpf é valido !!!")
         qv <- qv + 1
      senao
         escreval("Seu cpf é invalido !!!")
         qi <- qi + 1
      fimse

      escreval("Se quiser parar de testar cpf's digite 'N', se quiser continuar digite 'S'")
      escreval("Deseja testar mais cpf's?: ")
      leia(resp)
      
      enquanto (resp <> "S") e (resp <> "N") faca
           escreval("Você deve digitar S ou N!")
           escreval("Digite um valor valido: ")
           leia(resp)
      fimenquanto
      
      qt <- qt + 1
      
ate (resp <> "s")

escreval("Quantidade de cpf's testados foram de: ", qt)
escreval("Quantidade de cpf's validos foram de: ", qv)
escreval("Quantidade de cpf's invalidos foram de: ", qi)


por_valid <- (qv * 100) / qt
por_invalid <- (qi * 100) / qt

escreval("Porcentagem de cpf's validos: ", por_valid,"%")
escreval("Porcentagem de cpf's invalidos: ", por_invalid,"%")
Fimalgoritmo