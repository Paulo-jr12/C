/*      Aluno : 
		Paulo Cesar Garcia Junior - 11811BCC003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//tempo do pc para uso na funcao srand() para gerar sementes aleatorio
#define max 10//tamanho matriz
//numero max de navios vai ser de 3 por jogador

typedef struct tab{
	char mat[max][max]; // tabuleiro
	int  tab[max][max]; // tabuleiro de controle
	int  jogadas[max][max]; //para verificar se a jogada pode ser efetuada
	int  x_navios[11],y_navios[11]; // coordenadas dos navios onde comecara a ser 'desenhado' na matriz
	int  tipo_navio[11]; //armazena o tipo de cada navio para poder desenha-lo pode ser [0,1,2,3,4]
	int  navios_escolhidos[5]; //armazena se ja foi sorteado o navio na posicao escolhida
	int  tam_navio[5];//tamanho dos navios
	int  orientacao;//0 vertical 1 horizontal
}Tabuleiro;

//prototipos das funcoes
void        menu();
void        delay(int n);
Tabuleiro  *inicia_tab();//retorna um ponteiro para a struct Tabuleiro
int         tabuleiro_existe(Tabuleiro *t);
void        printar_tabuleiro(Tabuleiro *t, Tabuleiro *m);
int         executar_jogada(Tabuleiro *t, int x, int y);
void        sortear_jogada(int *x, int*y);//sorteia jogada da maquina
int         alguem_ganhou(Tabuleiro *t, Tabuleiro *m);
int         conv_char(char c);
void        extrair_jogada(int *x, int *y, char *str);


int main(){
	menu();//as demais funcoes sao chamadas a partir da funcao menu
	return 0;
}

int alguem_ganhou(Tabuleiro *t, Tabuleiro *m){
//retorna 1 se o user ganhar, 2 se a maquina ganhar e 0\
se nem um dos dois ganhar
	int i,j,retorno[2]={1,1};
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			if(t->tab[i][j]) retorno[1] = 0;//verifica se a maquina ganhou
			//se a matriz tab da struct t tiver na posicao i,j o valor 1 significa q ainda pode jogar nesta posicao
		}
	}
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			if(m->tab[i][j]) retorno[0] = 0;// verifica se o jogador ganhou
			//se a matriz tab da struct m tiver na posicao i,j o valor 1 significa q ainda pode jogar nesta posicao
		}
	}
	if(retorno[0]==0 && retorno[1]==0) return 0;//ninguem ganhou
	else if(retorno[0]==0 && retorno[1]==1) return 2;//maquina ganhou
	return 1;//jogador ganhou
}
void delay(int n){//atrasa o programa por um determinado tempo n medido em milessegundos
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<1000;j++);
	}
}
void menu(){//funcao principal do jogo
    printf("Iniciando o jogo...\n");
	Tabuleiro *t= inicia_tab();//tabuleiro do jogador
      delay(10);//aguarda para que os navios fiquem dispostos diferentes em cada tabuleiro
	Tabuleiro *m= inicia_tab();//tabuleiro da maquina

	int x=0,y=0;
	char str[4];
	enquanto://para o uso do goto
	while(1){// inicia um loop infinito
		//jogadas do usuario
		x=y=0;
		printar_tabuleiro(m,t);
		printf("\nLegenda:\n");
		printf(" \'~\' = posicao ainda nao utilizada\n");
		printf(" \'o\' = navio nesta posicao\n");
		printf(" \'x\' = posicao tentada mas nao tem navio\n");
		printf("\ncoordenadas da sua jogada ex [ 1 a ]: ");
		setbuf(stdin,NULL); //limpar buffer do teclado
		scanf("%3[^\n]s",&str);
		extrair_jogada(&x,&y,str);
		x--;
		if(!executar_jogada(m,x,y)) {
			printf("Jogada Invalida!!\n");
			delay(10);//atrazar o programa
			system("cls");//limpar tela
			goto enquanto;//desvia o fluxo do prog para o ponto denominado enquanto
		}

		//jogadas da maquina
		sortear_jogada(&x,&y);//sorteia proxima jogada da maquina
		while(!executar_jogada(t,x,y)){//repete ate que a jogada da maquina seja valida
			sortear_jogada(&x,&y);
		}

		if(alguem_ganhou(t,m)) break;
		system("cls"); //limpar a tela
	}
	if(alguem_ganhou(t,m)==1) printf("Parabens Voce Ganhou!!\n");
	else printf("A maquina te venceu!\n");
}
void extrair_jogada(int *x, int *y, char *str){
	char c=' ';
	char string[5]="";
	int i=0,j=0;
	while(str[i]){//percorre toda string ate o \0
		c = str[i];
		if(c>=65&&c<=74 || c>=97&&c<=106){//com base na tabela ascii 65 = A, 74 = J, 97 = a, 106 = j
			*y = conv_char(c);// converte de char para int
		}
		else if(c>=48 && c<=57){//com base na tabela ascii 48 = 0, 57 = 9
			string[j++]=c;
			string[j]=0;
			*x = atoi(string);//converte string em int
		}
		i++;
	}
}
int conv_char(char c){
	switch(c){
		case 'A': return 0; break;
		case 'a': return 0; break;
		case 'B': return 1; break;
		case 'b': return 1; break;
		case 'C': return 2; break;
		case 'c': return 2; break;
		case 'D': return 3; break;
		case 'd': return 3; break;
		case 'E': return 4; break;
		case 'e': return 4; break;
		case 'F': return 5; break;
		case 'f': return 5; break;
		case 'G': return 6; break;
		case 'g': return 6; break;
		case 'H': return 7; break;
		case 'h': return 7; break;
		case 'I': return 8; break;
		case 'i': return 8; break;
		case 'J': return 9; break;
		case 'j': return 9; break;
		default: return -1; break;
	}
}
Tabuleiro * inicia_tab(){
	Tabuleiro *t = (Tabuleiro *) malloc(sizeof(struct tab));
	int i,j,k;
	int navios_escolhidos[5]={1,4,3,2,1};
	int  tam_navio[5]={5,1,2,3,4};
	time_t tim;
	if(t!=NULL){ //verifica se t foi alocado
		for(i=0;i<5;i++) t->navios_escolhidos[i]=navios_escolhidos[i];
		for(i=0;i<5;i++) t->tam_navio[i]=tam_navio[i];

		for(i=0;i<max;i++) for(j=0;j<max;j++) t->jogadas[i][j]=1; //define que o tabuleiro esta vazio
		for(i=0;i<max;i++) for(j=0;j<max;j++) t->mat[i][j]='~',t->tab[i][j]=0; //inicia em 0 td a matriz

		srand((unsigned) time(&tim));//sorteia um numero aleatorio para ser semente nos sorteios da rand()
		for(i=0;i<11;i++) {
			t->x_navios[i] = rand()%10;//sorteia um numero entre 0 e 10
			delay(10);
			srand((unsigned) time(&tim));
			t->y_navios[i] = rand()%10;
			if(t->tab[t->x_navios[i]][t->y_navios[i]]==1)i--; //posicao ja tem navio comeca de novo
			else t->tab[t->x_navios[i]][t->y_navios[i]]=1; //seta a posicao inicial do navio
		}
  //   delay(100);
		srand((unsigned) time(&tim));
		t->orientacao = rand()%2;

		//tipo de navio
     //delay(37);
		srand((unsigned) time(&tim));
		for(i=0;i<11;i++) {
			t->tipo_navio[i] = rand()%5;
			for(j=0;j<5;j++){
				if(t->tipo_navio[i]==t->navios_escolhidos[j]){
					if(t->navios_escolhidos[j])	t->navios_escolhidos[j]--; //tipo do navio definido
					else i--;//tipo de navio nao definido
				}
			}
		}

		//setar os navios em suas devidas posicoes
		for(k=0;k<11;k++){
			if(t->orientacao){
				i=t->x_navios[k];
				for(j=t->y_navios[k];j<t->y_navios[k]+t->tipo_navio[k];j++){
					t->tab[i][j] = 1;
				}
			}
			else{
				j=t->y_navios[k];
				for(i=t->x_navios[k];i<t->x_navios[k]+t->tipo_navio[k];i++){
					t->tab[i][j] = 1;
				}
			}
			t->orientacao = rand()%2;
		}
	}
	return t;
}

int tabuleiro_existe(Tabuleiro *t){
	if(t==NULL) return 0;
	return 1;
}
void printar_tabuleiro(Tabuleiro *t, Tabuleiro *m){
	if(!tabuleiro_existe(t)) return;

	system("cls");

	printf("  SEU TABULEIRO       TABULEIRO DA MAQUINA\n\n");
	printf("   ABCDEFGHIJ           ABCDEFGHIJ\n");
	printf("   ----------           ----------\n");
	int i,j;
	for(i=0;i<max;i++){
		if(i<max-1) printf("%d  ",i+1);
		else printf("%d ",i+1);
		for(j=0;j<max;j++){
			printf("%c",t->mat[i][j]);
		}

		printf("           ");
		if(i<max-1) printf("%d  ",i+1);
		else printf("%d ",i+1);
		for(j=0;j<max;j++){
			printf("%c",m->mat[i][j]);
		}
		printf("\n");
	}
}
int executar_jogada(Tabuleiro *t, int x, int y){
	if(x>10 || x<0 || y>10 || y<0) return 0;
	if(t->jogadas[x][y]==1){
		if(t->tab[x][y]) {
			t->mat[x][y] = 'O';//tem navio nesta posicao
			t->tab[x][y] = 0;
			t->jogadas[x][y] = 0;
		}
		else {
			t->mat[x][y] ='X';//nao tem navio nesta posicao
			t->jogadas[x][y] = 0;
		}
		return 1;
	}
	return 0;//jogada impossivel
}
void sortear_jogada(int *x, int*y){//sorteia a jogada da maquina
	time_t t;
	srand((unsigned) time(&t));
	*x = rand()%10;
	*y = rand()%10;
}
