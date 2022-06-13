//TEM QUE CRIAR UM ARQUIVO DE TEXTO REPRESENTANDO UMA MATRIZ POR LETRAS E LER O ARQUIVO, SENDO Q CADA LETRA REPRESENTA ALGO. EX :A=AGUA B=NARIVO PEQUENO, ETC...//
//QUANDO O USUÁRIO ACERTAR UMA POSIÇÃO QUE O NAVIO SE ENCONTRA O VALOR DO NAVIO DESTRUIDO IRA RECEBER UM VALOR GERAL... QUE CASO REPITA A JOGADA IRÁ APARECER: "NAVIO JÁ DESTRUIDO"//
//A PESSOA PODERÁ ATRIBUIR O TAMANHO DO JOGO QUE QUISER, SENDO O MINIMO 10X10, ESSE TAMANHO SERÁ ATRIBUIDO PELO ARQUIVO DE TEXTO//





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Registro de Pontos de Localização//
typedef struct{
	int Linha;
	int Coluna;
	int BootLinha;
	int BootColuna;
}Numero_Jogada_t;

//Registra os Valores para Gerar a Matriz//
typedef struct{
	int TAMLinha;
	int TAMColuna;
	int TAMCaracteres;
	int TAMLinha2;
	int TAMColuna2;
	int TAMCaracteres2;
}TAMMatriz_t;

//Registra os Valores para Gerar a Matriz//
typedef struct{
	char Matriz1[100][100];
	char Matriz2[100][100];
}Matriz_t;

//Jogadas--Jogador[1]//
int Jogador1(Numero_Jogada_t *Numero_Jogada){
	int Condicao=0;
	
	//Sistema que Impede Jogadas Inválidas//
	while(Condicao=1){
		system("color 4");
		
		//Vez do Jogador 1//
		printf("\nJogador[1]\n");
		printf("-Linha:");
		scanf("%d", &Numero_Jogada->Linha);
		printf("-Coluna:");
		scanf("%d", &Numero_Jogada->Coluna);
		
		//Caso os Valores Atribuídos a Linha e Coluna Sejam Aceitos//
		if((Numero_Jogada->Linha>=0) && (Numero_Jogada->Linha<10) && (Numero_Jogada->Coluna>=0) && (Numero_Jogada->Coluna<10)){
			Condicao++;
			return;
		}
		
		//Caso os Valores Atribuídos a Linha e Coluna Sejam Rejeitados//
		else{
		printf("\n[X]Jogada Invalida[X]\n");
		system("color 4F");
		system("color 0F");
		} 
	}
}

//Jogadas--Jogador[2]//
int Jogador2(Numero_Jogada_t *Numero_Jogada){
	int Condicao=0;
	system("color 9");
	
	//Sistema que Impede Jogadas Inválidas//
	while(Condicao=1){
		system("color 9");
		
		//Vez do Jogador 2//
		printf("\nJogador[2]\n");
		printf("-Linha:");
		scanf("%d", &Numero_Jogada->Linha);
		printf("-Coluna:");
		scanf("%d", &Numero_Jogada->Coluna);
		
		//Caso os Valores Atribuídos a Linha e Coluna Sejam Aceitos//
		if((Numero_Jogada->Linha>=0) && (Numero_Jogada->Linha<10) && (Numero_Jogada->Coluna>=0) && (Numero_Jogada->Coluna<10)){
			Condicao++;
			return;
		}
		
		//Caso os Valores Atribuídos a Linha e Coluna Sejam Rejeitados//
		else{
		printf("\n[X]Jogada Invalida[X]\n");
		system("color 4F");
		system("color 0F");
		} 
	}
}

//Gerar HTML//
char AtualizaHTML(FILE *p, TAMMatriz_t TamMatriz){
	int i, j;
	p=fopen("Arquivo.html","w");
	if(p==NULL){
		printf("Erro na abertura do HTML");
		return -1;
	}
	
	fprintf(p, "\n<!DOCTYPE html>");
	fprintf(p, "\n<html>");
	fprintf(p, "\n<head>");
	fprintf(p, "\n<link href=\"Formatacao.css\" type= \"text/CSS\" rel=\"stylesheet\"/>");
	fprintf(p, "\n<meta charset=\"unicode\">");
	fprintf(p, "\n<meta http-equiv=\"refresh\" content=\"1\">");
	fprintf(p, "\n<title>Titulo da pagina</title>");
	fprintf(p, "\n</head>");
	//Conteúdo Da Página//
	fprintf(p, "\n<body background=\"Imagens/mar 9.jpg\" class=\"body\">");
	fprintf(p, "\n<h1 strong class=\"titulo\">BATALHA NAVAL</h1>");
	fprintf(p, "\n<section class=\"tabela_1\">");
	fprintf(p, "\n<table border=\"5\" width=550 height=500 bordercolor=#00008B background=\"Imagens/mar 3.jpeg\">");
	fprintf(p, "\n<th colspan=\"11\" strong>Jogador 1</th>");
	for(i=0;i<TamMatriz.TAMLinha; i++){
		fprintf(p, "\n<tr>");
		for(j=0;j<TamMatriz.TAMColuna; j++){
		fprintf(p, "\n<td>");
		fprintf(p, "</td>");
		}
		fprintf(p, "\n</tr>");
	}
	fprintf(p, "\n</table></p>");
	fprintf(p, "\n</section>");
	fprintf(p, "\n<p>");
	fprintf(p, "\n</p>");
	fprintf(p, "\n<p>");
	fprintf(p, "\n</p>");
	fprintf(p, "\n<section class=\"tabela_2\">");
	fprintf(p, "\n<table border=\"5\" width=550 height=500 bordercolor=#00008B background=\"Imagens/mar 3.jpeg\">");
	fprintf(p, "\n<th colspan=\"11\" strong>Jogador 2</th>");
	for(i=0;i<TamMatriz.TAMLinha2; i++){
		fprintf(p, "\n<tr>");
		for(j=0;j<TamMatriz.TAMColuna2; j++){
		fprintf(p, "\n<td>");
		fprintf(p, "</td>");
		}
		fprintf(p, "\n</tr>");
	}
	fprintf(p, "\n</table></p>");
	fprintf(p, "\n</section>");
	
	fprintf(p,"\n</body>\n");
	fprintf(p,"\n</html>\n");
	
	fclose(p);
}

//Lê o Arquivo e Dimênciona a Matriz1//
void DimencaoMatriz1(FILE *ARQMatriz, TAMMatriz_t *TamMatriz){
	char linha[100];
	int TAM=0, cont, aux=0, aux2=0, aux3=0, i=0, col;
	ARQMatriz=fopen("Matriz1.txt","r");
	if(ARQMatriz==NULL){
		printf("Erro na abertura do Tabuleiro 1");
	}
	while(fgets(linha, sizeof(linha),ARQMatriz)!=NULL){
	cont++;
	aux+=strlen(linha);
		for(i=0; i<aux; i++){
			if(linha[i]=='\n'){
				aux2++;
			}
		}
	}
	//Cont ref. Linha// aux3 ref. Caracteres// Col ref. Colunas// 
	aux3=aux-aux2;
	col=aux3/cont;
	fclose(ARQMatriz);
	
	TamMatriz->TAMLinha=cont;
	TamMatriz->TAMColuna=col;
	TamMatriz->TAMCaracteres=aux3;
	printf("\nJOGO: %d X %d", TamMatriz->TAMLinha, TamMatriz->TAMColuna);																				
}

//Lê o Arquivo e Dimênciona a Matriz2//
void DimencaoMatriz2(FILE *ARQMatriz, TAMMatriz_t *TamMatriz){
	char linha[100];
	int TAM=0, cont=0, aux=0, aux2=0, aux3=0, i=0, col=0;
	ARQMatriz=fopen("Matriz2.txt","r");
	if(ARQMatriz==NULL){
		printf("Erro na abertura do Tabuleiro 2");
	}
	while(fgets(linha, sizeof(linha),ARQMatriz)!=NULL){
	cont++;
	aux+=strlen(linha);
		for(i=0; i<aux; i++){
			if(linha[i]=='\n'){
				aux2++;
			}
		}
	}
	//Cont ref. Linha// aux3 ref. Caracteres// Col ref. Colunas// 
	aux3=aux-aux2;
	col=aux3/cont;
	fclose(ARQMatriz);
	TamMatriz->TAMLinha2=cont;
	TamMatriz->TAMColuna2=col;
	TamMatriz->TAMCaracteres2=aux3;
	printf(" - %d X %d\n", TamMatriz->TAMLinha2, TamMatriz->TAMColuna2);																				
}

//Escreve a Matriz 1 Copiando do Arquivo//
void EscreverMatriz1(FILE *ARQMatriz, TAMMatriz_t TamMatriz, Matriz_t *Matriz){
	char linha[100];
	int i=0, j=0;
	ARQMatriz=fopen("Matriz1.txt","r");
	if(ARQMatriz==NULL){
		printf("Erro na abertura do Tabuleiro 1");
	}
	while(fgets(linha, sizeof(linha),ARQMatriz)!=NULL){
		//REGISTRAR OS VALORES DO ARQUIVO NA MATRIZ//
		for(j=0; j<TamMatriz.TAMColuna; j++){				
			if(linha[j]!='\n'){
				Matriz->Matriz1[i][j]=linha[j];
			}
		}
		i++;	
	}
	fclose(ARQMatriz);
}

//Escreve a Matriz 2 Copiando do Arquivo//
void EscreverMatriz2(FILE *ARQMatriz, TAMMatriz_t TamMatriz, Matriz_t *Matriz){
	char linha[100];
	int i=0, j=0;
	ARQMatriz=fopen("Matriz2.txt","r");
	if(ARQMatriz==NULL){
		printf("Erro na abertura do Tabuleiro 1");
	}
	while(fgets(linha, sizeof(linha),ARQMatriz)!=NULL){
		//REGISTRAR OS VALORES DO ARQUIVO NA MATRIZ//
		for(j=0; j<TamMatriz.TAMColuna; j++){				
			if(linha[j]!='\n'){
				Matriz->Matriz2[i][j]=linha[j];
			}
		}
		i++;	
	}
	fclose(ARQMatriz);
}

//ANALISA SE O JOGADOR 1 VENCEU :) 
int VitoriaJog1(Matriz_t *Matriz, TAMMatriz_t TamMatriz){
	int i, j;
	for(i=0; i<TamMatriz.TAMLinha2; i++){
		for(j=0; j< TamMatriz.TAMColuna2; j++){
				if((Matriz->Matriz2[i][j]=='A') || (Matriz->Matriz2[i][j]=='X') || (Matriz->Matriz2[i][j]=='\n') || (Matriz->Matriz2[i][j]=='\0')|| (Matriz->Matriz2[i][j]==' ')){
				
				}
				else{
					return 20;
				}
			}	
		}		
	printf("\n--VITORIA DO JOGADOR 1--\n");
	return(1);
}
		
//ANALISA SE O JOGADOR 2 ou o Boot VENCEU :) 
int VitoriaJog2(Matriz_t *Matriz, TAMMatriz_t TamMatriz){
	int i, j;
	for(i=0; i<TamMatriz.TAMLinha2; i++){
		for(j=0; j< TamMatriz.TAMColuna2; j++){
				if((Matriz->Matriz2[i][j]=='A') || (Matriz->Matriz2[i][j]=='X') || (Matriz->Matriz2[i][j]=='\n') || (Matriz->Matriz2[i][j]=='\0') || (Matriz->Matriz2[i][j]==' ')){
				}
				else{
					return 20;
				}
			}	
		}	
	printf("\n--VITORIA DO JOGADOR 2--\n");
	return(1);
}

//ANALIZA A JOGADA DO BOOT
void AnalizaJogadaBoot(Matriz_t *Matriz,Numero_Jogada_t Numero_Jogada, TAMMatriz_t TamMatriz){
	int j=0, i=0;
	srand((unsigned)time(NULL));
	Numero_Jogada.BootLinha=rand()%TamMatriz.TAMLinha2;
   	Numero_Jogada.BootColuna=rand()%TamMatriz.TAMColuna2;
	
	printf("\n-Boot-Linha:%d", Numero_Jogada.BootLinha);
	printf("\n-Boot-Coluna:%d\n", Numero_Jogada.BootColuna);
	
	if(Matriz->Matriz1[Numero_Jogada.BootLinha][Numero_Jogada.BootColuna]=='X'){
		printf("\n--NAVIO JÁ DESTRUIDO--\n");
		return;
	}
	else if(Matriz->Matriz1[Numero_Jogada.BootLinha][Numero_Jogada.BootColuna]=='S'){
		printf("\n--ACERTOU SUBMARINO--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz1[Numero_Jogada.BootLinha][j]=='S'){
					Matriz->Matriz1[Numero_Jogada.BootLinha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz1[i][Numero_Jogada.BootColuna]=='S'){
					Matriz->Matriz1[i][Numero_Jogada.BootColuna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.BootLinha][Numero_Jogada.BootColuna]=='C'){
		printf("\n--ACERTOU CONTRATORPEDEIROS--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz1[Numero_Jogada.BootLinha][j]=='C'){
					Matriz->Matriz1[Numero_Jogada.BootLinha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz1[i][Numero_Jogada.BootColuna]=='C'){
					Matriz->Matriz1[i][Numero_Jogada.BootColuna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.BootLinha][Numero_Jogada.BootColuna]=='T'){
		printf("\n--ACERTOU NAVIOS-TANQUE--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz1[Numero_Jogada.BootLinha][j]=='T'){
					Matriz->Matriz1[Numero_Jogada.BootLinha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz1[i][Numero_Jogada.BootColuna]=='T'){
					Matriz->Matriz1[i][Numero_Jogada.BootColuna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.BootLinha][Numero_Jogada.BootColuna]=='P'){
		printf("\n--ACERTOU PORTA-AVIOES--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz1[Numero_Jogada.BootLinha][j]=='P'){
					Matriz->Matriz1[Numero_Jogada.BootLinha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz1[i][Numero_Jogada.BootColuna]=='P'){
					Matriz->Matriz1[i][Numero_Jogada.BootColuna]='X';
				}
			}
	}
	else{
		printf("\n--ERROU--\n");
		return;
	}	
}

/*ANALIZA AS JOGADAS DO JOGADORES 1*/
void AnalizaJogadaJogador1(Matriz_t *Matriz,Numero_Jogada_t Numero_Jogada, TAMMatriz_t TamMatriz){
	int j=0, i=0;
	if(Matriz->Matriz2[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='X'){
		printf("\n--NAVIO JÁ DESTRUIDO--\n");
		return;
	}
	else if(Matriz->Matriz2[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='S'){
		printf("\n--ACERTOU SUBMARINO--\n");
			for(j=0;j<TamMatriz.TAMColuna2; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='S'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha2; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='S'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz2[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='C'){
		printf("\n--ACERTOU CONTRATORPEDEIROS--\n");
			for(j=0;j<TamMatriz.TAMColuna2; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='C'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha2; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='C'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz2[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='T'){
		printf("\n--ACERTOU NAVIOS-TANQUE--\n");
			for(j=0;j<TamMatriz.TAMColuna2; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='T'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha2; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='T'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz2[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='P'){
		printf("\n--ACERTOU PORTA-AVIOES--\n");
			for(j=0;j<TamMatriz.TAMColuna2; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='P'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha2; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='P'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else{
		printf("\n--ERROU--\n");
		return;
	}	
}

/*ANALIZA AS JOGADAS DO JOGADORES 2*/
void AnalizaJogadaJogador2(Matriz_t *Matriz,Numero_Jogada_t Numero_Jogada, TAMMatriz_t TamMatriz){
	int j=0, i=0;
	if(Matriz->Matriz1[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='X'){
		printf("\n--NAVIO JÁ DESTRUIDO--\n");
		return;
	}
	else if(Matriz->Matriz1[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='S'){
		printf("\n--ACERTOU SUBMARINO--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='S'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='S'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='C'){
		printf("\n--ACERTOU CONTRATORPEDEIROS--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='C'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='C'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='T'){
		printf("\n--ACERTOU NAVIOS-TANQUE--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='T'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='T'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else if(Matriz->Matriz1[Numero_Jogada.Linha][Numero_Jogada.Coluna]=='P'){
		printf("\n--ACERTOU PORTA-AVIOES--\n");
			for(j=0;j<TamMatriz.TAMColuna; j++){
				if(Matriz->Matriz2[Numero_Jogada.Linha][j]=='P'){
					Matriz->Matriz2[Numero_Jogada.Linha][j]='X';
				}
			}
			for(i=0;i<TamMatriz.TAMLinha; i++){
				if(Matriz->Matriz2[i][Numero_Jogada.Coluna]=='P'){
					Matriz->Matriz2[i][Numero_Jogada.Coluna]='X';
				}
			}
	}
	else{
		printf("\n--ERROU--\n");
		return;
	}	
}

//MODIFICA O HTML//
ModificaHtml(FILE *p, Matriz_t *Matriz, Numero_Jogada_t Numero_Jogada, TAMMatriz_t TamMatriz){
	int i, j;
	p=fopen("Arquivo.html","w");
	if(p==NULL){
		printf("Erro na abertura do HTML");
		return -1;
	}
	
	fprintf(p, "\n<!DOCTYPE html>");
	fprintf(p, "\n<html>");
	fprintf(p, "\n<head>");
	fprintf(p, "\n<link href=\"Formatacao.css\" type= \"text/CSS\" rel=\"stylesheet\"/>");
	fprintf(p, "\n<meta charset=\"unicode\">");
	fprintf(p, "\n<meta http-equiv=\"refresh\" content=\"1\">");
	fprintf(p, "\n<title>Titulo da pagina</title>");
	fprintf(p, "\n</head>");
	//Conteúdo Da Página//
	fprintf(p, "\n<body background=\"Imagens/mar 9.jpg\" class=\"body\">");
	fprintf(p, "\n<h1 strong class=\"titulo\">BATALHA NAVAL</h1>");
	fprintf(p, "\n<section class=\"tabela_1\">");
	fprintf(p, "\n<table border=\"5\" width=550 height=500 bordercolor=#00008B background=\"Imagens/mar 3.jpeg\">");
	fprintf(p, "\n<th colspan=\"11\" strong>Jogador 1</th>");
	
	for(i=0;i<TamMatriz.TAMLinha; i++){
		fprintf(p, "\n<tr>");
		for(j=0;j<TamMatriz.TAMColuna; j++){		
			if(Matriz->Matriz1[i][j]=='X'){
				fprintf(p, "\n<td>X");
				fprintf(p, "</td>");
			}
			else{
				fprintf(p, "\n<td>");
				fprintf(p, "</td>");
			}
		}
		fprintf(p, "\n</tr>");
	}
	fprintf(p, "\n</table></p>");
	fprintf(p, "\n</section>");
	fprintf(p, "\n<p>");
	fprintf(p, "\n</p>");
	fprintf(p, "\n<p>");
	fprintf(p, "\n</p>");
	fprintf(p, "\n<section class=\"tabela_2\">");
	fprintf(p, "\n<table border=\"5\" width=550 height=500 bordercolor=#00008B background=\"Imagens/mar 3.jpeg\">");
	fprintf(p, "\n<th colspan=\"11\" strong>Jogador 2</th>");
	
	for(i=0;i<TamMatriz.TAMLinha2; i++){
		fprintf(p, "\n<tr>");
		for(j=0;j<TamMatriz.TAMColuna2; j++){		
			if(Matriz->Matriz2[i][j]=='X'){
				fprintf(p, "\n<td>X");
				fprintf(p, "</td>");
			}
			else{
				fprintf(p, "\n<td>");
				fprintf(p, "</td>");
			}
		}
		fprintf(p, "\n</tr>");
	}
	fprintf(p, "\n</table></p>");
	fprintf(p, "\n</section>");
	
	fprintf(p,"\n</body>\n");
	fprintf(p,"\n</html>\n");
	
	fclose(p);
}
	
//Main//
int main(){
	int jog1, jog2,Condicaomenu=0, opmenu=0;
	int CondicaoNG=0, Condicao=0,i,j, mat;
	Numero_Jogada_t Numero_Jogada;
	TAMMatriz_t TamMatriz;
	FILE *p, *ARQMatriz;
	Matriz_t Matriz;
   	
    while(opmenu=1){
    printf("\n--BATALHA NAVAL--\n");
    printf("\n[1]COMECAR JOGO");
    printf("\n[2]REGRAS");
    printf("\n[3]SAIR");
    printf("\nOP: ");
    scanf("%d", &Condicaomenu);
    	//MENU JOGAR//
		if(Condicaomenu==1){
			printf("\n--NOVO JOGO--\n");
			printf("\n[1]UM JOGADOR\n");
			printf("[2]DOIS JOGADORES\n");
			printf("[3]VOLTAR");
			printf("\nOP: ");
   			scanf("%d", &CondicaoNG);
				//UM JOGADOR//   			
			    if(CondicaoNG==1){
				opmenu++;
				break;
				}
				//DOIS JOGADORES//
				else if(CondicaoNG==2){
				opmenu++;
				break;
				}
				//VOLTAR//	
				else if(CondicaoNG==3){
				}
				else{
					printf("\n--OPCAO INVALIDA--\n");
				}
		}   
		//REGRAS DO JOGO//
		else if(Condicaomenu==2){
			printf("\n--REGRAS--\n");
			printf("\n-O JOGO E VIZUALIZADO E APRESENTADO NO ARQUIVO HTML;\n");
			printf("-PODE-SE JOGAR EM UM JOGADOR, CONTRA BOOT, OU EM 2 JOGADORES;\n");
			printf("-O ARQUIVO DE TEXTO DEVE CONTER O NUMERO DE LINHAS E COLUNAS PARES;\n");
			printf("-O ARQUVIO E COMPOSTO POR CARACTERES MAIUSCULOS;\n");
			printf("-OS CARACTERES PODEM SER COLOCADOS EMPARELHADOS EM LINHAS OU COLUNAS;\n");
			printf("-QUANDO UM CARACTERE ESPECIFICO E COLOCADO EM DETERMINADA LINHA, OU COLUNA, NAO DEVE-SE COLOCAR UM CARACTERE DO MESMO TIPO, NAS LINHAS E COLUNAS DIRECIONADAS AO MESMO;\n");
			printf("-OS CARACTERES DEVEM SER REPRESENTADOS PELAS SEGUINTES LETRAS:\n");
			printf("\n[A]=AGUA(1 POSICAO);\n");
			printf("[S]=SUBMARINO(2 POSICAO);\n");
			printf("[C]=CONTRATORPEDEIROS(3 POSICAO);\n");
			printf("[T]=NAVIO-TANQUE(4 POSICAO);\n");
			printf("[P]=PORTA-AVIÕES(5 POSICAO);\n\n");
			} 
		//SAIR DO JOGO//
		else if(Condicaomenu==3){
			printf("\n--JOGO ENCERRADO--");
			opmenu++;
			return 0;
		} 
		//CASO OP INVÁLIDA//
		else{
			printf("\n--OPCAO INVALIDA--\n");
		}
	}
   	//Dimencionar Matriz1//
	DimencaoMatriz1(ARQMatriz, &TamMatriz);	
	
	//Dimencionar Matriz2//
	DimencaoMatriz2(ARQMatriz, &TamMatriz);	
	
	//Escreve a Matriz1//
	EscreverMatriz1(ARQMatriz,TamMatriz,&Matriz);

	//Escreve a Matriz2//	
	EscreverMatriz2(ARQMatriz,TamMatriz,&Matriz);
	
    //Gerar HTML//
    AtualizaHTML(p,TamMatriz);	
	
	//Repete as jogadas// Caso o jogo acabe, Atribui-se 1 a Condicao//
	while(Condicao=1){
		
		//UM-JOGADOR//
		if(CondicaoNG==1){
		//Vez do Jogador//
		Jogador1(&Numero_Jogada);
			AnalizaJogadaJogador1(&Matriz,Numero_Jogada,TamMatriz);
			ModificaHtml(p,&Matriz,Numero_Jogada,TamMatriz);
			Condicao=VitoriaJog1(&Matriz,TamMatriz);
			if(Condicao==1){
				break;
			}
		//Vez do Boot//
			AnalizaJogadaBoot(&Matriz,Numero_Jogada,TamMatriz);
			Condicao=VitoriaJog2(&Matriz,TamMatriz);
			ModificaHtml(p,&Matriz,Numero_Jogada,TamMatriz);
			if(Condicao==1){
				break;
			}
		}
	
		//MULTIJOGADOR//
		else if(CondicaoNG==2){
		//Vez do Jogador 1//
		Jogador1(&Numero_Jogada);
			AnalizaJogadaJogador1(&Matriz,Numero_Jogada,TamMatriz);
			ModificaHtml(p,&Matriz,Numero_Jogada,TamMatriz);
			Condicao=VitoriaJog1(&Matriz,TamMatriz);
			if(Condicao==1){
				break;
			}
		
		//Vez do Jogador 2//
		Jogador2(&Numero_Jogada);
			AnalizaJogadaJogador2(&Matriz,Numero_Jogada,TamMatriz);
			ModificaHtml(p,&Matriz,Numero_Jogada,TamMatriz);
			Condicao=VitoriaJog2(&Matriz,TamMatriz);
			if(Condicao==1){
				break;
			}
		}
	}
	printf("\n--JOGO ACABOU--\n");
	return 0;
}




/*for(i=0;i<TamMatriz.TAMLinha;i++){
		for(j=0;j<TamMatriz.TAMColuna;j++){
			printf("%c", Matriz.Matriz1[i][j]);
		}
			printf("\n");
	}		
	for(i=0;i<TamMatriz.TAMLinha2;i++){
		for(j=0;j<TamMatriz.TAMColuna2;j++){
			printf("%c", Matriz.Matriz2[i][j]);
		}
		printf("\n");}
	 																			//SPRINTAR MATRIZES APAGAR DEPOIS/*/
