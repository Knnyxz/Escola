#include<stdio.h>
#include<locale.h>
int n1, a1, a2, b10, b11, c10, c11, qv, qi, qt;
int c, vlr1, vlr2, resto, soma1, soma2;	
char resp;
float por_valid, por_invalid;

main(){
setlocale(LC_ALL,"portuguese");
printf("\n=================================================================\n");
printf("\nNesse programa verificaremos se um cpf é válido ou inválido.\n");
printf("\n=================================================================\n\n");

do{
vlr1 = 10;
vlr2 = 11;
soma1 = 0;
soma2 = 0;	
	for (c = 1; c <= 9; c++){
		printf("\nDigite o seu %d° digito do cpf: ",c);
		scanf("%d", &n1);
		while (n1 < 0 || n1 > 9){
			printf("Digite apenas um numero ou numero positivos\n");
			printf("Digite o seu %d° digito do cpf: ", c);
			scanf("%d", &n1);		
		}
		a1 = n1 * vlr1;
		a2 = n1 * vlr2;

		soma1 = soma1 + a1;
		soma2 = soma2 + a2;
		vlr1--;
		vlr2--;
		

		resto = soma1 % 11;

		if (c == 9){
			if (resto < 2){
				b10 = 0;
			}else{
				b10 = 11 - resto;
			}

			soma2 = soma2 + b10 * 2;
		}
	}
	
	resto = soma2 % 11;
	
	if (resto < 2){
		b11 = 0;
	}else{	
		b11 = 11 - resto;
	}
	
	for (c = 10; c <= 11; c++){
		printf("\nDigite o seu %d° digito do cpf: ", c);
		if (c == 10){
			scanf("%d", &c10);
			while (c10 < 0 || c10 > 9){
				printf("Digite apenas um numero ou numero positivos\n");
				printf("Digite o seu %d° digito do cpf: ", c);
				scanf("%d", &c10);
			}
		}else{
			scanf("%d", &c11);
			while (c11 < 0 || c11 > 9){
				printf("Digite apenas um numero ou numero positivos\n");
				printf("Digite o seu %d° digito do cpf: ", c);
				scanf("%d", &c11);
			}
		}
	}				

	if  (c10 == b10 && c11 == b11){
		printf("\nSeu cpf é válido !!!\n");
		qv++;
	}else{
		printf("\nSeu cpf é inválido !!!\n");
		qi++;
	}
	
	printf("\nSe quiser parar de testar cpf's digite 'N', se quiser continuar digite 'S' ");
	printf("\nDeseja testar mais cpf's?: ");
	scanf("%s", &resp);
	while ((resp != 'S') && (resp != 's') && (resp != 'N') && (resp != 'n')){
		printf("\nVocê deve digitar S ou N!");
		printf("\nDigite um valor valido: ");
		scanf("%s", &resp);
	}
		
	qt++;	
	
}while (resp != 'n' && resp != 'N');			

printf("Quantidade de cpf's testados foram de: %d\n", qt);
printf("Quantidade de cpf's válidos foram de: %d\n", qv);
printf("Quantidade de cpf's inválidos foram de: %d\n", qi);
  
por_valid = (qv * 100) / qt;
por_invalid = (qi * 100) / qt;
    
printf("Porcentagem de cpf's válidos: %.2f%%\n", por_valid);
printf("Porcentagem de cpf's inválidos: %.2f%%\n", por_invalid);	
	
}
