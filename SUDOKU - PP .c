#include <stdio.h>
#include <stdlib.h>

/**1. Crie uma func¸ao que recebe como par ˜ ametro um n ˆ umero inteiro e devolve o seu dobro. */

/*int dobrar(x){
return (x+x);
}

int main (){
int x,aux;
printf("DIGITE UM NUMERO:");
scanf("%d",&x);
printf("O DOBRO DO NUMERO EH %d",dobrar(x));
}*/

/**2. Fac¸a uma func¸ao que receba a data atual (dia, m ˜ es e ano em inteiro) e exiba-a na tela ˆ
no formato textual por extenso. Exemplo: Data: 01/01/2000, Imprimir: 1 de janeiro de
2000.*/

/*int retorna (int dia,char mes[20],int ano){
return printf("%d DE %s DE %d",dia,mes,ano);
}

int main (){
int dia,mes,ano,aux;
printf("\n DIGITE O DIA: \n");
scanf("%d",&dia);
printf("\n DIGITE O MES POR EXTENSO: \n");
setbuf(stdin,NULL);
gets(mes);
printf("\n DIGITE O ANO: \n");
scanf("%d",&ano);
aux = retorna(dia,mes,ano);
printf("\n A DATA NO FORMATO TEXTUAL EH %d \n",aux);
}*/

/**3. Fac¸a uma func¸ao para verificar se um n ˜ umero ´ e positivo ou negativo. Sendo que o valor ´
de retorno sera 1 se positivo, -1 se negativo e 0 se for igual a 0. ´*/

/*int verifica(x){
if(x==0){
return 0;
}
else{
if(x>0){
return 1;
}
if(x<0){
return -1;
}
}
}

int main (){
int x;
printf("DIGITE UM NUMERO:");
scanf("%d",&x);
printf("%d",verifica(x));
}
*/

/*int main (){
int *p2,x =10,*p1;

p1 = &x;
p2 = &x;
*p1 = x;
x = 50;
printf("VALOR X :%d \n ENDERECO:%d",*p1,*p2);
}*/

/**1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao.*/

/*int main (){
int x=30,*px;
char y = 'c',*py;
float z= 10 ,*pz;

px = &x;
py = &y;
pz = &z;

printf("\n VALOR ANTES DA MODIFICAÇAO :\n");
printf("\n %d \n %c \n %f \n",x,y,z);

*px = 50;
*py = 'z';
*pz = 30.2;

printf("\n  VALOR APOS MODIFICAÇAO :\n");
printf("\n %d \n %c \n %f \n",x,y,z);
}

*/

/**2. Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o.*/

/*int main (){
int x=10,*px;
int z=20,*pz,maior;

px = &x;
pz = &z;

printf("\n O ENDERECO DE X EH %d \n",px);
printf("\n O ENDERECO DE Y EH %d \n",pz);
if(px > pz){
    maior = px;
}
else{
    maior = pz;
}
printf("\n O MAIOR ENDERECO EH %d \n",maior);
}*/

/**3. Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o.*/

int main (){
int x,y,*px,*py,maior;
printf("\n DIGITE O VALOR DE X: \n");
scanf("%d",&x);
printf("\n DIGITE O VALOR DE Y: \n");
scanf("%d",&y);
px = &x;
py = &y;

printf("\n O ENDERECO DE X EH %d \n",px);
printf("\n O ENDERECO DE Y EH %d \n",py);


if(px > py){
    maior = px;
}
else{
    maior = py;
}
printf("\n O MAIOR ENDERECO EH %d \n",maior);

}
