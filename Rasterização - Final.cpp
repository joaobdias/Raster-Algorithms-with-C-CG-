#include <stdio.h>
#include <windows.h>
#include <math.h>

int menu();
void reta_dda();
void reta_bresenham();
void polilinhas_dda();
void polilinhas_bresenham();
void circulo_pit();
void circulo_scp();
void circulo_bresenham();
void telaCord(int x, int y);
void plano();

int main() {

	int x = 0;
	  while(x!=8){
	  	
	  	system("cls");
	    x = menu();
	    
	    switch(x){
	      case 1:
	    	reta_dda();
		      break;
	      case 2:
	      	reta_bresenham();
		      	break;
	      case 3:
	      	polilinhas_dda();
		      break;
	      case 4:
	      	polilinhas_bresenham();
		      break;
	      case 5:
	      	circulo_pit();
		      break;
	      case 6:
	      	circulo_scp();
		      break;
	      case 7:
	      	circulo_bresenham();
		      break;
	      case 8:
		    system("cls");
		    printf("Obrigado por usar o programa\n");
		    system("pause");
		    break;
		      default:
		    system("cls");
		    printf("Selecione uma das opcoes disponiveis\n");
		    system("pause");
		    break;
	    }
  }
}

void reta_dda() { 

	int deltax, deltay, x1, y1, x2, y2;
	float xinc, yinc, xaux, yaux, step;
	
	system("cls");
	plano();
	printf("Digite as Coordenadas da reta: ");
	printf("\nx1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);
	
	xaux = x1;
	yaux = y1;
	
	deltax = x2 - x1;
	deltay = y2 - y1;

	if (abs(deltax) >= abs(deltay))
		step = abs(deltax);
	else
		step = abs(deltay);
		
	xinc = deltax/step;
	yinc = deltay/step;
	
	telaCord(round(xaux)+75,round(-yaux)+20);
    printf("%c", 254);
	
	while ((round(xaux) != x2) || (round(yaux) != y2)){
		
		xaux = xaux + xinc;
		yaux = yaux + yinc;
		telaCord(round(xaux)+75,round(-yaux)+20);
    	printf("%c", 254);
	}
	
	telaCord(0,35);
	system("pause");	
}

void reta_bresenham(){
   
   	int x1, y1, x2, y2;
	int p, deltay, deltax, x ,y, xf, yf;
	float m;
	
	system("cls");
	plano();
	printf("Digite as Coordenadas da reta: ");
	printf("\nx1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);
	
	if (y1 != y2){
	
		if (x1 < x2){
			x = x1;
			y = y1;
			xf = x2;
			yf = y2;
		} else {
			x = x2;
			y = y2;
			xf = x1;
			yf = y1;	
		}
		
		deltax = abs(xf-x);
		deltay = abs(yf-y);
		m = (deltax/deltay);
		
		if (m >= 1){
			
			p = 2*deltay - deltax;
			telaCord(x+75,-y+20);
	    	printf("%c", 254);
	    	
			while (x < xf) {
	    
	        	x++;
				if (p < 0){
	    			p = p + 2*deltay;
	
	    		} else {
	    		
	    			if (y < yf)
	    				y++;
	    			else 
	    				y--;
	    			
	   				p = p + 2*deltay - 2*deltax;
	    		}
	    		
	    		telaCord(x+75,-y+20);
	    		printf("%c", 254);
	
	  		}
	  		
		} else {
			
			p = 2*deltax - deltay;
			telaCord(x+75,-y+20);
	    	printf("%c", 254);
	        		
	    		while (y != yf){
	    			
	    			if (y < yf)
						y++;
					else
						y--;
	    			
	    			if (p < 0){
	    				p = p + 2*deltax;
	    			} else {
	    				x++;
	   					p = p + 2*deltax - 2*deltay;
	    			}
	    			
	    			telaCord(x+75,-y+20);
	    			printf("%c", 254);
				}
		}
		
	} else {
		if (x1 <= x2) {
		
			while (x1 < x2){
				telaCord(x1+75,-y1+20);
    			printf("%c", 254);
    			x1++;
			}
					
		} else {
			while (x2 <= x1){
				telaCord(x2+75,-y1+20);
    			printf("%c", 254);
    			x2++;
			}
		}
	}
	
	telaCord(0,35);
	system("pause");
}

void polilinhas_dda(){
	
	int numlinhas, deltax, deltay, aux, i;
	float xinc, yinc, xaux, yaux, step;
	system("cls");
	plano();
	printf("Quantas linhas deseja colocar? (Min 3): ");
	scanf("%d",&numlinhas);
	
	while (numlinhas < 3){
		system("cls");
		plano();
		printf(" ----- MINIMO DE 3 LINHAS ----- ");
		printf("\nDigite a quantidade de linhas: ");
		scanf("%d",&numlinhas);
	}
	
	int vetval[numlinhas*2];
	xaux = 1; yaux = 1;
	
	for(i = 0; i < numlinhas*2; i++){
		if (i%2 == 0){
			printf("\nDigite o valor de x%.0f: ", xaux);
			scanf("%d",&aux);
			vetval[i] = aux;
			xaux++;
			
		} else {
			printf("Digite o valor de y%.0f: ", yaux);
			scanf("%d",&aux);
			vetval[i] = aux;
			yaux++;
		}
	}
		xaux = 0; yaux = 0; aux = 0; i = 1; 
		
		while (i <= numlinhas) {
							
				if (i < numlinhas){
					xaux = vetval[aux];
					yaux = vetval[aux+1];
	
					deltax = vetval[aux+2] - vetval[aux];
					deltay = vetval[aux+3] - vetval[aux+1];

					if (abs(deltax) >= abs(deltay))
						step = abs(deltax);
					else
						step = abs(deltay);
			
					xinc = deltax/step;
					yinc = deltay/step;
		
					telaCord(round(xaux)+75,round(-yaux)+20);
    				printf("%c", 254);
		
					while ((round(xaux) != vetval[aux+2]) || (round(yaux) != vetval[aux+3])){
		
						xaux = xaux + xinc;
						yaux = yaux + yinc;
						telaCord(round(xaux)+75,round(-yaux)+20);
    					printf("%c", 254);
						
					}
				
				aux += 2;
					
				} else if (i == numlinhas){
					
					xaux = vetval[aux];
					yaux = vetval[aux+1];
	
					deltax = vetval[0] - vetval[aux];
					deltay = vetval[1] - vetval[aux+1];

					if (abs(deltax) >= abs(deltay))
						step = abs(deltax);
					else
						step = abs(deltay);
			
					xinc = deltax/step;
					yinc = deltay/step;
		
					telaCord(round(xaux)+75,round(-yaux)+20);
    				printf("%c", 254);
		
					while ((round(xaux) != vetval[0]) || (round(yaux) != vetval[1])){
		
						xaux = xaux + xinc;
						yaux = yaux + yinc;
						telaCord(round(xaux)+75,round(-yaux)+20);
    					printf("%c", 254);
			
					}
					
				}
				
			i++;
		}
		
	telaCord(0,35);
	system("pause");
}

void polilinhas_bresenham(){
	
	int p, deltay, deltax, x ,y, xf, yf, numlinhas, xaux, yaux, aux, i, i1, i2, aux2;
	float m;
	system("cls");
	plano();
	printf("Quantas linhas deseja colocar? (Min 2): ");
	scanf("%d",&numlinhas);
	
	while (numlinhas < 2){
		system("cls");
		plano();
		telaCord(0,0);
		printf(" ----- MINIMO DE 2 LINHAS ----- ");
		printf("\nDigite a quantidade de linhas: ");
		scanf("%d",&numlinhas);
	}
	
	int vetval[numlinhas*2];
	xaux = 1; yaux = 1;
	
	for(i = 0; i < numlinhas*2; i++){
		if (i%2 == 0){
			printf("\nDigite o valor de x%d: ", xaux);
			scanf("%d",&aux);
			vetval[i] = aux;
			xaux++;
			
		} else {
			printf("Digite o valor de y%d: ", yaux);
			scanf("%d",&aux);
			vetval[i] = aux;
			yaux++;
		}
	}
		xaux = 0; yaux = 0; aux = 0; i = 1; 
		
		while (i <= numlinhas) {
							
				if (i < numlinhas) {
					
					if (vetval[aux+1] != vetval[aux+3]) {
	
						if (vetval[aux] < vetval[aux+2]){
							x = vetval[aux];
							y = vetval[aux+1];
							xf = vetval[aux+2];
							yf = vetval[aux+3];
						} else {
							x = vetval[aux+2];
							y = vetval[aux+3];
							xf = vetval[aux];
							yf = vetval[aux+1];	
						}
						
						deltax = abs(xf-x);
						deltay = abs(yf-y);
						m = (deltax/deltay);
						
						if (m >= 1){
							
							p = 2*deltay - deltax;
							telaCord(x+75,-y+20);
					    	printf("%c", 254);
					    	
							while (x < xf) {
					    
					        	x++;
								if (p < 0){
					    			p = p + 2*deltay;
					
					    		} else {
					    		
					    			if (y < yf)
					    				y++;
					    			else 
					    				y--;
					    			
					   				p = p + 2*deltay - 2*deltax;
					    		}
					    		
					    		telaCord(x+75,-y+20);
					    		printf("%c", 254);
					
					  		}
					  		
						} else {
							
							p = 2*deltax - deltay;
							telaCord(x+75,-y+20);
					    	printf("%c", 254);
					        		
					    		while (y != yf){
					    			
					    			if (y < yf)
										y++;
									else
										y--;
					    			
					    			if (p < 0){
					    				p = p + 2*deltax;
					    			} else {
					    				x++;
					   					p = p + 2*deltax - 2*deltay;
					    			}
					    			
					    			telaCord(x+75,-y+20);
					    			printf("%c", 254);
								}
						}
						
					} else {
						
						i1 = vetval[aux];
						i2 = vetval[aux+2];
						aux2 = vetval[aux+1]; 
						
						if (i1<= i2) {
						
							while (i1 <= i2){
								telaCord(i1+75,-aux2+20);
				    			printf("%c", 254);
				    			i1++;
							}
									
						} else {
							while (i2 <= i1){
								telaCord(i2+75,-aux2+20);
				    			printf("%c", 254);
				    			i2++;
							}
						}
					}
						aux+=2;
								} else if (i == numlinhas) {
									
									if (vetval[aux+1] != vetval[1]) {
	
										if (vetval[aux] < vetval[0]){
											x = vetval[aux];
											y = vetval[aux+1];
											xf = vetval[0];
											yf = vetval[1];
										} else {
											x = vetval[0];
											y = vetval[1];
											xf = vetval[aux];
											yf = vetval[aux+1];	
										}
										
										deltax = abs(xf-x);
										deltay = abs(yf-y);
										m = (deltax/deltay);
										
										if (m >= 1){
											
											p = 2*deltay - deltax;
											telaCord(x+75,-y+20);
									    	printf("%c", 254);
									    	
											while (x < xf) {
									    
									        	x++;
												if (p < 0){
									    			p = p + 2*deltay;
									
									    		} else {
									    		
									    			if (y < yf)
									    				y++;
									    			else 
									    				y--;
									    			
									   				p = p + 2*deltay - 2*deltax;
									    		}
									    		
									    		telaCord(x+75,-y+20);
									    		printf("%c", 254);
									
									  		}
									  		
										} else {
											
											p = 2*deltax - deltay;
											telaCord(x+75,-y+20);
									    	printf("%c", 254);
									        		
									    		while (y != yf){
									    			
									    			if (y < yf)
														y++;
													else
														y--;
									    			
									    			if (p < 0){
									    				p = p + 2*deltax;
									    			} else {
									    				x++;
									   					p = p + 2*deltax - 2*deltay;
									    			}
									    			
									    			telaCord(x+75,-y+20);
									    			printf("%c", 254);
												}
										}
										
									} else {
										
										i1 = vetval[aux];
										i2 = vetval[0];
										aux2 = vetval[aux+1]; 

										if (i1<= i2) {
										
											while (i1 <= i2){
												telaCord(i1+75,-aux2+20);
								    			printf("%c", 254);
								    			i1++;
											}
													
										} else {
											while (i2 <= i1){
												telaCord(i2+75,-aux2+20);
								    			printf("%c", 254);
								    			i2++;
											}
										}
									}
								}	
						i++;
		}
		
	telaCord(0,35);
	system("pause");
}

void circulo_pit(){
	
	double x,y,O,aux;
	float Yc, Xc, r, aux2;
		
	system("cls");
	plano();
	printf("--- Digite o raio e centro do circulo ---");
	printf("\nRaio: ");
	scanf("%f", &aux2);
	r = abs(aux2);
	printf("\nCoordenadas do Centro do Circulo:");
	printf("\nx: ");
	scanf("%f", &Xc);
	printf("y: ");
	scanf("%f", &Yc);
	
	
		for(O = 0;O<91;O++){
			aux = O*3.14/180; //angulo em radianos
			x = Xc + sqrt(pow(r,2)-pow(r*sin(aux),2));
			y = Yc + sqrt(pow(r,2)-pow(r*cos(aux),2));
			x = round(x);
			y = round(y);
			telaCord(x+75, 20-y);
			printf("%c",254);
		}
		for(O = 91;O<181;O++){
			aux = O*3.14/180; //angulo em radianos
			x = Xc - sqrt(pow(r,2)-pow(r*sin(aux),2));
			y = Yc + sqrt(pow(r,2)-pow(r*cos(aux),2));
			x = round(x);
			y = round(y);
			telaCord(x+75, 20-y);
			printf("%c",254);
		}
		for(O = 181;O<271;O++){
			aux = O*3.14/180; //angulo em radianos
			x = Xc - sqrt(pow(r,2)-pow(r*sin(aux),2));
			y = Yc - sqrt(pow(r,2)-pow(r*cos(aux),2));
			x = round(x);
			y = round(y);
			telaCord(x+75, 20-y);
			printf("%c",254);
		}
		for(O = 271;O<360;O++){
			aux = O*3.14/180; //angulo em radianos
			x = Xc + sqrt(pow(r,2)-pow(r*sin(aux),2));
			y = Yc - sqrt(pow(r,2)-pow(r*cos(aux),2));
			x = round(x);
			y = round(y);
			telaCord(x+75, 20-y);
			printf("%c",254);
		}
		
	telaCord(0,35);
	system("pause");
}

void circulo_scp(){
		
	double x,y,aux,O;
	float Yc, Xc, r, aux2;
	
	system("cls");
	plano();
	printf("--- Digite o raio e centro do circulo ---");
	printf("\nRaio: ");
	scanf("%f", &aux2);
	r = abs(aux2);
	printf("\nCoordenadas do Centro do Circulo:");
	printf("\nx: ");
	scanf("%f", &Xc);
	printf("y: ");
	scanf("%f", &Yc);
	
	for(O = 0;O<=359;O++){
		aux = O*3.14/180;
		x = Xc+r*cos(aux);
		y = Yc+r*sin(aux);
		x = round(x);
		y = round(y);
		telaCord(x+75,20-y);
		printf("%c",254);
	}
	
	telaCord(0,35);
	system("pause");
}

void circulo_bresenham(){
	
	int r, xcen, ycen, p, x, y,aux;
	system("cls");
	plano();
	
	printf("--- Digite o raio e centro do circulo ---");
	printf("\nRaio: ");
	scanf("%d", &aux);
	r = abs(aux);
	printf("\nCoordenadas do centro: ");
	printf("\nx: ");
	scanf("%d",&xcen);
	x = xcen;
	printf("y: ");
	scanf("%d",&ycen);
	y = ycen + r;
	
	p = 1-r;
	telaCord(x+75+xcen,-y+20+ycen);
    printf("%c", 254);
    telaCord(y+75+xcen,-x+20+ycen);
    printf("%c", 254);
    telaCord(-y+75+xcen,x+20+ycen);
    printf("%c", 254);
    telaCord(-x+75+xcen,y+20+ycen);
    printf("%c", 254);
	
	while (x < y){
		
		x++;
		if (p < 0)
			p = p + 2*x + 1;
		else {
			y--;
			p = p + 2*x + 1 - 2*y;
		}
		
		telaCord(x+75+xcen,-y+20+ycen);
	    printf("%c", 254);
	    telaCord(y+75+xcen,-x+20+ycen);
	    printf("%c", 254);
	    telaCord(y+75+xcen,x+20+ycen);
	    printf("%c", 254);
	    telaCord(x+75+xcen,y+20+ycen);
	    printf("%c", 254);
	    telaCord(-x+75+xcen,y+20+ycen);
	    printf("%c", 254);
	    telaCord(-y+75+xcen,x+20+ycen);
	    printf("%c", 254);
	    telaCord(-y+75+xcen,-x+20+ycen);
	    printf("%c", 254);
	   	telaCord(-x+75+xcen,-y+20+ycen);
	    printf("%c", 254);
		
	}
	
	telaCord(0,35);
	system("pause");
}

void telaCord (int x, int y) { // função que determina a região que será utilizada pelas coordenadas
      COORD tela; // será o buffer de tela que iremos criar no console (começa no (0,0) no superior esquerdo)

      // aqui as coordenadas passadas pelas outras funções acharão seu lugar no plano cartesiano (no buffer "tela")
      tela.X = x; 
      tela.Y = y;

      //aqui é definido um identificador para as cordenadas x,y dentro do buffer de tela do console
      SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), tela);
      /* como está se utilizando o console padrão, pode se utilizar o STD_OUTPUT_HANDLE com o GetStdHandle
      além de referenciar de qual estrutura COORD estamos trabalhando, a "tela"*/

}

int menu(){
	int i = 0;
	  printf("1- Reta com DDA\n");
	  printf("2- Reta com Bresenham\n");
	  printf("3- Polilinhas com DDA\n");
	  printf("4- Polilinhas com Bresenham\n");
	  printf("5- Circulo com Pitagoras\n");
	  printf("6- Circulo com Coordenadas Polares\n");
	  printf("7- Circulo com Bresenham\n");
	  printf("8- Sair do programa\n");
	  scanf("%i",&i);
	return i;
}

void plano (){
	
	int hor, ver;
		
		for  (ver = 5; ver < 35; ver++){
			telaCord(75,ver);
			printf("|");
		}
		
		for (hor = 37; hor < 117; hor++){
			telaCord(hor, 20);
			printf("-");
		}
		telaCord(75,20);
		printf("0");
		telaCord(0,0);
}
