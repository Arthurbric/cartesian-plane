#include<math.h> //Operações matemáticas
#include<stdio.h> //Inclui as funções entradas e saídas do programa
#include<windows.h> //Inclui as bibliotecas gráficas
#include <locale.h> //Possibilita o uso de caracteres de várias linguagens

//funções que estão abaixo da main
void irParaXY(int x, int y);
int setX(int x);
int setY(int y);
void planoCartesiano(void) ;
void dda(float *x1, float *y1, float *x2, float *y2);
void bresenham(float *x1, float *y1, float *x2, float *y2);
void circulo(int *raio);
int animacao();

int main(){
    setlocale(LC_ALL, "Portuguese");
    //variaveis do codigo
    int escolha = 1;
    float xi, xf, yi, yf;
    int raio;
    //loop
    while(escolha != 0 ){
    //escolha do usuário
    printf("\n\nEscolha o número referente ao desafio desejado:\n(0) - Sair\n(1) - Imprime uma reta (Algoritmo DDA)\n(2) - Imprime uma reta (Algoritmo de Bresenham)\n(3) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\nOpção escolhida:\n");
    scanf("%d", &escolha);
    switch (escolha) {
        //se quiser sair
        case 0:
            printf("\n\tVocê escolheu (0) --> Sair\n");
            break;
        //reta DDA
        case 1:
            printf("\nVocê escolheu (1) --> Imprime uma reta (Algoritmo DDA)\n");
            printf("\nEscolha o valor do x inicial:");//escolha dos pontos da reta
            scanf("%f", &xi);
            printf("Escolha o valor do y inicial:");
            scanf("%f", &yi);
            printf("Escolha o valor do x final:");
            scanf("%f", &xf);
            printf("Escolha o valor do y final:");
            scanf("%f", &yf);
            system("cls");
            animacao();
            system("cls");
            planoCartesiano(); //desenha o plano cartesiano
            dda(&xi, &yi, &xf, &yf);
            irParaXY(0,  0);//coloca a próxima escolha para o ponto 0 da tela
            //printf("(%.0f,%.0f)-->(%.0f,%.0f)\n",xi,yi,xf,yf);//mostra a escolha dos pontos
            printf("\nDeseja desenhar outro plano cartesiano? (1 = sim, 0 = não)");//escolha do usuário se quiser continuar ou não
            printf("\nDigita o valor aqui --> ");
            scanf("%d", &escolha);
            break;
        //reta bresenham
        case 2:
            printf("\nVocê escolheu (2) --> Imprime uma reta (Algoritmo de Bresenham)\n");
            printf("\nEscolha o valor do x inicial: ");//escolha dos pontos da reta
            scanf("%f", &xi);
            printf("Escolha o valor do y inicial: ");
            scanf("%f", &yi);
            printf("Escolha o valor do x final: ");
            scanf("%f", &xf);
            printf("Escolha o valor do y final: ");
            scanf("%f", &yf);
            system("cls");
            animacao();
            system("cls");
            planoCartesiano();//desenha o plano cartesiano
            bresenham(&xi, &yi, &xf, &yf);
            irParaXY(0,  0);//coloca a próxima escolha para o ponto 0 da tela
            //printf("(%.0f,%.0f)-->(%.0f,%.0f)\n",xi,yi,xf,yf);//mostra a escolha dos pontos
            printf("\nDeseja desenhar outro plano cartesiano? (1 = sim, 0 = nao)");//escolha do usuário se quiser continuar ou não
            printf("\nDigite o valor aqui --> ");
            scanf("%d", &escolha);
            break;
        //circulo bresenham
         case 3:
	       printf("Voce digitou(3) Escolheu -->  Imprime o traçado de um círculo (Algoritmo de Bresenham)\n");
            printf("qual o raio?", raio);//escolha do raio do círculo
            scanf("%d", &raio);
            system("cls");
            animacao();
            system("cls");
            planoCartesiano(); //desenha o plano cartesiano
            circulo(&raio);
            irParaXY(0,0);//coloca a próxima escolha para o ponto 0 da tela
            //printf("raio ---> (%d)\n",raio);//mostra a escolha do raio
            //printf("diâmetro ---> (%d)\n",raio*2);
            printf("\nDeseja desenhar outro plano cartesiano? (1 = sim, 0 = não)");//escolha do usuário se quiser continuar ou não
            printf("\nDigite o valor aqui --> ");
            scanf("%d", &escolha);
	       break;
             //se escolher um valor não válido
	   default:
	       printf("\((nVocê escolheu um valor que não existe))\n((Digite notamente))\n\n");
	}}
	printf("\nPrograma encerrado\n");
    return 0;
}

//Método que faz o apontamento das coordenadas X e Y
void irParaXY(int x, int y) {
    COORD coord;
    coord.X = (short) x;
    coord.Y = (short) y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Desloca X em 118 + X
int setX(int x) {
    return (x + 118);
}

//Desloca Y em 34- Y
int setY(int y) {
    return (34 - y);
}

//Método que imprime o plano cartesiano na tela
void planoCartesiano(void) {
    int vertical, horizontal;
    for (vertical = 14; vertical < 55 ; vertical++) {//Reta que separa o plano na vertical
        irParaXY(118, vertical);
        printf("|");
    }
    for (horizontal = 18; horizontal < 219; horizontal++) {//Reta que separa o plano na horizontal
        irParaXY(horizontal, 34);
        printf("-");
    }
    irParaXY(118, 34);
    printf("X");//Ponto central
}
//implementação DDA algoritmo reta
void dda(float *x1, float *y1, float *x2, float *y2) {
    if (fabs(*x2 - *x1) >= fabs(*y2 - *y1)) {
        float m = (*y2 - *y1) / (*x2 - *x1);
        float y = *y1;
        int x;
        if (*x1 > *x2) {
            float b = *x1;
            *x1 = *x2;
            *x2 = b;
            y = *y2;
        }
        for (x = *x1; x <= *x2; x++) {
            irParaXY(setX(x), setY(round(y)));
            printf("*");
            y += m;
        }
    } else {
        float m = (*x2 - *x1) / (*y2 - *y1);
        float x = *x1;
        int y;
        if (*y1 > *y2) {
            float b = *y1;
            *y1 = *y2;
            *y2 = b;
            x = *x2;
        }
        for (y = *y1; y <= *y2; y++) {
            irParaXY(setX(round(x)), setY(y));
            printf("*");
            x += m;
        }
    }
}

//implementação bresenham algoritmo circulo
void circulo(int *raio){
    int x , y,p ;
    int d;
    x = 0;
    y = *raio;
    p = 1 - *raio;

    planoCartesiano(); //desenha o plano cartesiano do círculo de bresenham

    while (x <= y) {

        irParaXY(setX(+x), setY(+y)); printf("o"); // copia para as oito partes/octantes do plano cartesiano
        irParaXY(setX(+x), setY(-y)); printf("o");
        irParaXY(setX(-x), setY(+y)); printf("o");
        irParaXY(setX(-x), setY(-y)); printf("o");
        irParaXY(setX(+y), setY(+x)); printf("o");
        irParaXY(setX(+y), setY(-x)); printf("o");
        irParaXY(setX(-y), setY(+x)); printf("o");
        irParaXY(setX(-y), setY(-x)); printf("o");

        if (p <= 0) {
            p = p+2*x+1;
        } else {
            p = p+2*x+1-2*y;
            y--;
        }
        x++;
    }
}

//implementação bresenham algoritmo reta
void bresenham(float *x1, float *y1, float *x2, float *y2){
	float d_x, d_y, p, incE, incNE, x, y;

	d_x = fabs(*x2 - *x1);
	d_y = fabs(*y2 - *y1);
	p = 2 * d_y - d_x;
	if (d_y <= d_x) {  // inclinação menor ou igual a 45 graus
    	incE = 2 * d_y;
    	incNE = 2 * d_y - 2 * d_x;

    	if (*x1 <= *x2) {
        	x = *x1;
        	y = *y1;
    	}
    	else {
        	x = *x2;
        	y = *y2;
        	*x2 = *x1;
        	*y2 = *y1;
    	}

    	while (x <= *x2) {
            irParaXY(setX(x), setY(y));
            printf("*");

        	if (p <= 0) {
            	p = p + incE;
        	} else {
            	p = p + incNE;
            	y = y + ((*y2 >= *y1) ? 1 : -1);
        	}
        	x++;
    	}

	} else {  // inclinação maior que 45 graus
    	incE = 2 * d_x;
    	incNE = 2 * d_x - 2 * d_y;

    	if (*y1 <= *y2) {
        	x = *x1;
        	y = *y1;
    	} else {
        	x = *x2;
        	y = *y2;
        	*y2 = *y1;
        	*x2 = *x1;
    	}

    	while (y <= *y2) {
            irParaXY(setX(round(x)), setY(round(y)));
            printf("°");

        	if (p <= 0) {
            	p = p + incE;
        	} else {
            	p = p + incNE;
            	x = x + ((*x2 >= *x1) ? 1 : -1);
        	}
   	     y++;
    	}
	}
}

//animação do bonequinho morrendo
int animacao(){
    int i=0;
    while (i++ < 18){
        irParaXY(i,0);
        printf(" o");
        printf("\n");
        irParaXY(i,20-i);
        printf(" X");
        printf("\n");
        if (i%2 == 0){
            irParaXY(i,1);
            printf(" |");
            irParaXY(i,2);
            printf("/ \\o");
        }else{
            irParaXY(i,1);
            printf("-|-");
            irParaXY(i,2);
            printf(" | o");
        }
        sleep(0,0001);
        system("cls");
    }

    irParaXY(18,1);
    printf("  --o");
    irParaXY(18,2);
    printf("_/ \\");
    sleep(0,5);
    system("cls");
    irParaXY(18,2);
    printf(">->o");
    sleep(1);
}