#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	char ch;//ch recebe o arquivo texto
	int tam;//tam será a ordem da matriz
	int n, m;
	//n e m serão usados para determinar onde o nó começa e onde o nó termina

	int cont = 0;//meu contador começa no 0

	FILE *p;//ponteiro utilizado para apontar para o arquivo "teste.txt"

	p = fopen("teste.txt","r");//apontando o ponteiro p para o arquivo teste.txt

		if(p == NULL){//se o arquivo for nulo, não poderei abrir
			printf("Não foi possível abrir o arquivo");
		}
		else{
			while(cont < 3){//a quantidade de nós está contida no 3º caractere da matriz por padrão, então meu contador irá contar até o 3
				
				ch = fgetc(p);//capturando o 3º caractere do arquivo texto
				cont++;
			}

			tam = ch - 48;/*48 = conversão de char para int conforme a tabela ASCII, assim, será me dado um número que será 
			usado para determinar o tamanho da matriz quadrada*/

			int mat[tam][tam];//será gerada uma matriz de ordem determinada pelo usuário
			int mat1[tam][tam];//como a mat1 será modificada e eu não achei um jeito de desfazer as alterações,
			int mat2[tam][tam];//criei outras 2 matrizes que irão receber os mesmos dados, assim, uma matriz irá receber o fecho
			int i,j;//reflexivo, outra o simétrico e outra o transitivo

			for (i = 0; i < tam; i++){//aqui temos um for para dizer que todas as posições da matriz começarão tendo o número 0

				for (j = 0; j < tam; j++){
					mat[i][j] = 0;
					mat1[i][j] = 0;
					mat2[i][j] = 0;
				}

			}

			ch = fgetc(p);//variável usada para transformar o arquivo texto em uma string
			cont = 0;//contador usado para contar a posição dos caracteres

			while(ch != 'f'){//vou ler o arquivo texto até eu localizar a letra 'f' que signica "fim do arquivo" portanto, vou parar de lê-lo

				ch = fgetc(p);
				cont++;// a cada /n eu vou começar a ler a nova linha, ou seja
				if(ch != 'f'){

					if(cont == 3){
						n = ch - 48;//o nó de início é o 3º caractere, ou seja, vou ler a linha até achar o 3º caractere
					}

					if(cont == 5){//o nó final é o 5º caractere, mesmo processo, vou capturar ele e dar a coordenada para a matriz
						m = ch - 48;
					}

					if(cont == 6){/*quando o contador chegar em 6 vou gravar a informação na matriz, o contador vai pra 0 e vou começar o processo
					novamente escaneando a nova linha */
						mat[n-1][m-1] = 1; /*A MATRIZ EM C COMEÇA DO INDICE 0, entao onde no caso que vc pensou é 1 1, agora a posição é 0 0*/
						mat1[n-1][m-1] = 1;
						mat2[n-1][m-1] = 1;
						cont = 0;
					}
				}
			}

			//QUESITO 1, CALCULANDO PROPRIEDADE REFLEXIVA

			int cont1 = 0;/*esse contador vai me dizer a soma dos valores das diagonais, se o valor das diagonais for igual a ordem da 
			matriz escolhida pelo usuário, então a matriz é reflexiva*/

			printf("\nMatriz original\n");

			for (i = 0; i < tam; i++){//mostrando a matriz para o usuário de acordo com os dados que ele me forneceu

					for (j = 0; j < tam; j++){
						printf("%d ",mat[i][j]);
					}
				printf("\n");			
			}
				
			for (i = 0; i < tam; i++){//mostrando a matriz para o usuário de acordo com os dados que ele me forneceu

					for (j = 0; j < tam; j++){
						if(i == j){
							cont1 += mat[i][j];
						}
					}		
			}

			if(cont1 == tam){//se o contador tiver o mesmo valor da ordem da matriz, a matriz possui reflexibilidade
				printf("\nA matriz possui a propriedade reflexiva\n");
			}
			else{//se o contador tiver qualquer valor diferente da ordem da matriz, a matriz não é reflexiva
				printf("\nA matriz não possui a propriedade reflexiva\n");

				printf("\nCalculando fecho reflexivo...\n");

				for (i = 0; i < tam; i++){

					for (j = 0; j < tam; j++){
						if(i == j){
							if(mat[i][j] == 0){
								mat[i][j] = 1;//caso alguma das coordenadas diagonais for igual a 0, o valor será setado para 1
							}
						}
					}			
				}

				printf("\nNova matriz com a propriedade reflexiva\n");

				for (i = 0; i < tam; i++){//print da matriz com a propriedade reflexiva

					for (j = 0; j < tam; j++){
						printf("%d ",mat[i][j]);
					}
					printf("\n");			
				}

			}

			//FIM DA PRIMEIRA PARTE DO CÓDIGO

			//SEGUNDA PARTE DO CÓDIGO

			//QUESITO 2, CALCULANDO PROPRIEDADE SIMÉTRICA

			printf("\nChecando propriedade simétrica\n");

			printf("\nMatriz Original\n");

			for (i = 0; i < tam; i++){//resgatei os valores iniciais da matriz

					for (j = 0; j < tam; j++){
						printf("%d ",mat1[i][j]);//a mat1 é receberá os valores iniciais do arquivo
					}
				printf("\n");			
			}

			int ver = 0;

			for (i = 0; i < tam; i++){//mostrando a matriz para o usuário de acordo com os dados que ele me forneceu

				for (j = 0; j < tam; j++){
					if(mat1[i][j] == 1){//estou pegando cada posição da matriz e verificando se a posição inversa dela também está setada em um
						if(mat1[j][i] == 1){
							ver = 1;//se para toda posição da matriz, tivermos como 1 a posição inversa, então a matriz é simétrica
						}
						else if (mat1[j][i] == 0){
							ver = 0;//se a variável ver receber 0, a matriz não é simétrica
						}
					}
				}			
			}

			if(ver == 1){//se a variável ver receber 1 então....
				printf("\nA matriz possui a propriedade simétrica\n");
			}
			else if (ver == 0){
				printf("\nA matriz não possui a propriedade simétrica\n");

				for (i = 0; i < tam; i++){//executando a operação de alteração da posição da matriz

				for (j = 0; j < tam; j++){

					if(mat1[i][j] == 1){
						 if (mat1[j][i] == 0){
							mat1[j][i] = 1;
						}
					}
				}			
			}

			printf("\nNova matriz contendo a propriedade simétrica\n");

			for (i = 0; i < tam; i++){//print da nova matriz
					for (j = 0; j < tam; j++){
						printf("%d ",mat1[i][j]);
					}
				printf("\n");
				}
			}

			printf("\nChecando propriedade transitiva\n");

			printf("\nMatriz Original\n");

			for (int i = 0; i < tam; i++){//resgatei os valores iniciais da matriz

					for (int j = 0; j < tam; j++){
						printf("%d ",mat2[i][j]);//a mat2 receberá os valores iniciais do arquivo
					}
				printf("\n");			
			}
		}

			//FIM DA SEGUNDA PARTE DO CÓDIGO



	int resposta;

	resposta = fclose(p);

	if(resposta == 0){
		printf("\nSucesso no fechamento do arquivo\n");
	}
	else{
		printf("\nErro no fechamento do arquivo");
	}

	return (EXIT_SUCCESS);

}