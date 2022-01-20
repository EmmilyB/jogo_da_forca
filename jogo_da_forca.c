/*************************************************

Atividade Avaliativa - Jogo da Forca
Curso: Ciencia de Dados e Inteligencia Artificial
Nome: Emmily Boesing

**************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define linha 50
#define coluna 10

void desenho_forca(int erro){
    switch(erro){
        case 0: printf("\n");
                printf(" x-------------x\n");
                printf(" |             |\n");
                printf(" |             |\n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" |              \n");
                printf(" x=====         \n");
            break; 
    
        case 1: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" x=====               \n");
            break;
            
        case 2: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |             |      \n");
                printf(" |             |      \n");
                printf(" |             |      \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" x=====               \n");
            break;
        
        case 3: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |           \\ |     \n");
                printf(" |            \\|     \n");
                printf(" |             |      \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" x=====               \n");
            break;
            
        case 4: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |           \\ | /   \n");
                printf(" |            \\|/    \n");
                printf(" |             |      \n");
                printf(" |                    \n");
                printf(" |                    \n");
                printf(" x=====               \n");
            break;
            
        case 5: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |           \\ | /   \n");
                printf(" |            \\|/    \n");
                printf(" |             |      \n");
                printf(" |            /       \n");
                printf(" |           /        \n");
                printf(" x=====               \n");
            break;
            
        case 6: printf("\n");
                printf(" x-------------x      \n");
                printf(" |             |      \n");
                printf(" |            _|_     \n");
                printf(" |           /   \\   \n");
                printf(" |           \\___/   \n");
                printf(" |           \\ | /   \n");
                printf(" |            \\|/    \n");
                printf(" |             |      \n");
                printf(" |            / \\    \n");
                printf(" |           /   \\   \n");
                printf(" x=====               \n");
            break;
    }
}

int main ()
{
    char banco_palavras[linha][coluna] = {"ESPANHA", "BRASIL", "CANADA", "ANGOLA", "CHILE", "JAPAO", "FRANCA", "ALEMANHA", "RUSSIA", "EGITO",
                                          "ITALIA", "AUSTRALIA", "INGLATERRA", "MEXICO", "URUGUAI", "EQUADOR", "BOLIVIA", "SURINAME", "PARAGUAI", "PORTUGAL",
                                          "JAMAICA", "VENEZUELA", "GUIANA", "ARGENTINA", "MADAGASCAR", "TAILANDIA", "INDIA", "FILIPINAS", "CHINA", "NORUEGA",
                                          "IRLANDA", "GRECIA", "PERU", "COLOMBIA", "DINAMARCA", "NIGERIA", "MARROCOS", "IRAQUE", "AFEGANISTAO", "GUATEMALA",
                                          "PANAMA", "CUBA", "SUECIA", "TURQUIA", "POLONIA", "ARGELIA", "NICARAGUA", "ISLANDIA", "BELGICA", "AUSTRIA"};
    char palavra[coluna], traco[coluna], var, erradas[6], continuar;
    int tamanho, i, j;
    int erro = 0;
    int tot = 0;
    int aux = 0;
    int num = 0;
    int final = 1;

    while(1)
    {
        srand(time(NULL));
        
        i = rand() % linha;
        
        strcpy (palavra, banco_palavras[i]);  //Armazena uma palavra por vez na variavel "palavra"
        
        tamanho = strlen (banco_palavras[i]);  //Armazena o tamanho da palavra
       
        for (j = 0; j < tamanho; j++)       //Desenha os tracos
            traco[j] = '_';
        
        while (final == 1)
	    {
	        system("clear");
	        
	        printf ("\n -----JOGO DA FORCA-----\n");
	        printf ("          Paises\n");
	        
	        desenho_forca(erro);        //Desenha a forca
	        
	        for (j = 0; j < tamanho; j++){  //Desenha as letras certas e os tracos
              printf (" %c", traco[j]);
	        }
	        
	        printf ("\n\n Erradas: ");      //Imprime as letras erradas
	        for (j = 0; j < erro; j++)
	            printf("%c ", erradas[j]);
	        
	        printf ("\n");
	        printf ("\n Letra: ");
	        scanf ("%c", &var);         //Recebe letra
	       
	        getchar();                  //Pega o ENTER, fflush nao estava funcionando
	        
	        var = toupper(var);         //Muda as letras para maiusculo
	   
	        for (int k = 0; k < tamanho; k++)
	        {
	            if (palavra[k] == var)             //Verifica se a palavra possui a letra
		        {
        	        if (palavra[k] != traco[k]){   //Para nao contar mais de uma vez caso for digitado duas vezes a letra certa
        	            traco[k] = var;            //Coloca a letra em sua posicao
        	            tot++;                     //Encerra o while ao acertar tudo
        	        }
        	        aux++;                         //Se for mais que 0 é porque nao ha erro
		        }
	        }
	        
	        if (aux == 0){                //Contabiliza os erros
        	   erro++;
        	   erradas[num] = var;       //Adiciona a letra errada ao vetor
        	   num++;
	        }
	           
	        aux = 0;
	        
	        system("clear");        //Utilizei "clear" ao inves de "cls", pois meu sistema operacional é Linux
	   	
	        if (erro >= 6){
	            printf("\n VOCE PERDEU! A resposta era: %s", palavra);
	            final = 0;
	        }
	        else if (tot >= tamanho){
	            printf("\n VOCE GANHOU! A resposta era: %s", palavra);
	            final = 0;
	        }
	    }
	   	
        tot = 0; tamanho = 0; erro = 0; num = 0;
        final = 1;

        while(1){
        printf ("\n\n Deseja jogar mais uma partida? (s)Sim / (n)Nao\n");
        continuar = getchar();
        getchar();
        
        if (continuar == 'n' || continuar == 's')
            break;
        else
            printf(" Comando nao identificado");
        }

        if (continuar == 'n')
	        break;
	    else if (continuar == 's')
	        continue;
    }
  return 0;
}
