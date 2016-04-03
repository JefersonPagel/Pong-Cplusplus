//Jeferson Pagel(60047) - Computer Science - Unisc - 2008
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#define VIDEO 0x10
#define px 5
class campo{
	private:
	public:
		int erro,aux3;
		void desenha();
		//void erros();
		struct time t;
		long int t0, t1;
		campo();
		void tempoin();
		void tempoout();
};
campo::campo(){
		 textcolor(2);gotoxy(32,21); cprintf("Erro(s): ");
		 textcolor(2);gotoxy(34,23);cprintf(" 0 ");
		 textcolor(2);gotoxy(10,21);cprintf("Acerto(s):");
		 textcolor(2);gotoxy(50,21);cprintf("Tempo:");
		 textcolor(2);gotoxy(50,23); cprintf("          ");
		 textcolor(2);gotoxy(26,27);cprintf("Velocidade: 5 ");
		 t0=0;
		 t1=0;
		 aux3=5;
		 erro=0;
}
void campo::desenha(){
				int lar=60,alt=25,aux=2,aux1=2;
				while(aux<lar){
					aux++;
					gotoxy(aux,aux1);
					textcolor(13);
					cprintf("\xDB\xDB");

				}
				while(aux1<29){
					aux1++;
					gotoxy(aux,aux1);
					textcolor(13);
					cprintf("\xDB\xDB");
				}
				aux=2;
				aux1=20;
				lar=lar;
				while(aux<lar){
					aux++;
					gotoxy(aux,aux1);
					textcolor(13);
					cprintf("\xDB\xDB");
				}
				aux=2;
				aux1=1;
				while(aux1<29){
					aux1++;
					gotoxy(aux,aux1);
					textcolor(13);
					cprintf("\xDB\xDB");

				}
				aux=2;
				aux1=alt;
				while(aux<lar){
					aux++;
					gotoxy(aux,aux1);
					textcolor(13);
					cprintf("\xDB\xDB");
				}
				aux=45;
				aux1=20;
				while(aux1<alt){
				       aux1++;
				       gotoxy(aux,aux1);
				       textcolor(13);
				       cprintf("\xDB\xDB");
				}
				aux=25;
				aux1=20;
				while(aux1<alt){
				       aux1++;
				       gotoxy(aux,aux1);
				       textcolor(13);
				       cprintf("\xDB\xDB");
				}
				aux=1;
				aux1=30;
				while(aux<lar){
				       aux++;
				       gotoxy(aux,aux1);
				       textcolor(13);
				       cprintf("\xDB\xDB");
				}

}

/*void campo::erros(){

	if(aux3>7){
		erro=erro+1;
		gotoxy(31,21);
		printf(" %i",erro);
	}
}  */

void campo::tempoout(){
	long int min=0, t2;
	gettime(&t);
	t1=1;
	t1=t1*t.ti_hour*3600+t.ti_min*60+t.ti_sec;
	t2=t1-t0;
	min=t2/60;
	t2=t2%60;
	if(t2<10){
	gotoxy(50,23); printf("%2ld:0%ld", min,t2);
	}
	else{
	gotoxy(50,23); printf("%2ld:%2ld", min,t2);
	}
}

void campo::tempoin()
{
	gettime(&t);
	t0=1;
	t0=t0*t.ti_hour*3600+t.ti_min*60+t.ti_sec;
}

class padel{
	private:

	public:
	 int k,n1,n2, l, x, y, movp, ant,cont,erro, cont2,acer, mov,p1,p2,p3,p4,p5;
	 char ch1;

	 padel();
	 void ball();
	 void velocidade(char ch1);
	 void rebatida();
	 void posicao1();
	 void posicao2();
	 void erros();
};


padel::padel(){
int f=0;
x=9;
y=13;
ant=0;
n1=10;
n2=n1+4;
k=59;
l=19;
cont=0;
cont2=0;
mov=100;
erro=0;
acer=0;
movp=5;
gotoxy(5,3);printf (" Pressione  'ESC' para terminar");
gotoxy(5,4);printf(" Precione as setas up e down para movimentar o jogador ");
gotoxy(5,5);printf(" Precione as teclas + e - para alterar a velocidade da bola");
gotoxy(5,6);printf(" OBS: PARA MELHOR APROVEITAMENTO GRAFICO USAR EM FULL SCREEN");


while(f!=1){
	gotoxy(5,8);printf("                                        ");delay(10);
	gotoxy(5,9);printf("                                        ");delay(10);
	gotoxy(5,10);printf("                                          ");delay(10);
	gotoxy(5,11);printf("                                        ");delay(10);
	gotoxy(5,12);printf("                                             ");delay(10);
	gotoxy(5,8);printf("///////     //     ////////  //////  // ");delay(10);
	gotoxy(5,9);printf("//   //   //  //   //     // //      // ");delay(10);
	gotoxy(5,10);printf("///////  //    //  //     // //////  //   ");delay(10);
	gotoxy(5,11);printf("//      ////////// //     // //      // ");delay(10);
	gotoxy(5,12);printf("//     //        // ///////  ////// /////// ");delay(10);
	gotoxy(5,15);printf("                                   ");delay(10);
	gotoxy(5,15);printf(" Precione uma tecla para continuar.");delay(10);

	if (kbhit()){
		   f=1;
		   }
 }
getch();
clrscr();
}



void padel::ball()
{
	       if(x==k){
						cont=1;
					}

		if(cont==0){
		if(x<k){
					if(cont2==0){
							if(y<l){
								gotoxy(x,y);
								printf("O");
								delay(mov);
								gotoxy(x,y);
								printf(" ");
								x++;
								ant=y;
								y++;
								if(y==l){
									cont2=1;
								}
						}
					}
					if(cont2==1){
							if(y>3){
								gotoxy(x,y);
								printf("O");
								delay(mov);
								gotoxy(x,y);
								printf(" ");
								if(x==k){
									cont=1;
								}
								if(x<k){
								x++;
								}
								ant=y;
								y--;
								if(y==3){
									cont2=0;
								}
							}
						}
					if(x==k){
						cont=1;
					}
			 }
		 }
		 if(cont==1){
				if(cont2==0){
					if(x==4){
					cont=0;
					}
					if(y<l){
						gotoxy(x,y);
						printf("O");
						delay(mov);
						gotoxy(x,y);
						printf(" ");
						x--;
						ant=y;
						y++;
						if(y==l){
							cont2=1;
						}
					}
				}
				if(cont2==1){
					if(x==4){
					cont=0;
					}
					if(y>3){
						gotoxy(x,y);
						printf("O");
						delay(mov);
						gotoxy(x,y);
						printf(" ");
						if(x>4){
						x--;
						}
						ant=y;
						y--;
						if(y==3){
							cont2=0;
						}
					}




	}        }
}
void padel::velocidade(char ch1){
			if(ch1==43){
				if(mov>50){
				mov=mov-10;
				movp++;
			}
		}
			if(ch1==45){
			 if(mov<140){
				mov=mov+10;
				movp--;
			}
		}
  gotoxy(38,27);printf("%i ",movp);
}

void padel::rebatida(){
	if(x==6){
		if(y==p1||y==p2){
			cont=0;
			cont2=1;
			gotoxy(px,y);
			printf("\xDB");
			acer++;
		}
		if(y==p3){
			acer++;
			if(ant>y){
				cont=0;
				cont2=1;
			}
			if(ant<y){
				cont=0;
				cont2=0;
			}
			gotoxy(px,y);
			printf("\xDB");
		}
		if(y==p4||y==p5){
			cont=0;
			cont2=0;
			gotoxy(px,y);
			printf("\xDB");
			acer++;
		}
	}
       gotoxy(15,23);printf("%i",acer);
}

void padel::posicao1(){
	int b=19;
	n2=n1+5;
	if(n1<b){

	if(n2<=b){

	n1++;

	p1=n1;
	p2=n2-3;
	p3=n2-2;
	p4=n2-1;
	p5=n2;



      }
  }
}
void padel::posicao2(){
	int  c=3;
	n2=n1+3;
       if(n1>c){
	if(n2>=c){

	n1--;
	p1=n1;
	p2=n1+1;
	p3=n1+2;
	p4=n1+3;
	p5=n2;

      }
   }
}
void padel::erros(){
	if(x==4){
		erro++;
		gotoxy(34,23);printf("%i",erro);
		x=9;
		y=13;
		cont=0;
		cont2=0;
		mov=100;
		movp=5;
		gotoxy(x,y);printf("O");
		gotoxy(8,29);printf("Voce errou!!!Precione uma tecla para continuar.");
		getch();
		gotoxy(8,29);printf("                                               ");
		gotoxy(38,27);printf("%i ",movp);
	  }
}
class player{
	private:
	public:
		int z, aux,r1,r2,r3,r4,r5;
		player();
		void gamer1(char ch1);
		void gamer2(char ch1);
		void pos();
};

void player::player(){
	z=10;
	r1=10;
	r2=11;
	r3=12;
	r4=13;
	r5=14;
       aux=z+4;
	while(aux>z){
	     aux--;
	     gotoxy(px,aux);
	     printf("\xDB");
	}
}
void player::gamer1(char ch1)
{
	int  c=3;
	aux=z+3;

		 if (ch1 == 72)
			 {
				if(z>c){
				       if(aux>=c){
					gotoxy(px,r1);printf("  ");
					gotoxy(px,r2);printf("  ");
					gotoxy(px,r3);printf("  ");
					gotoxy(px,r4);printf("  ");
					gotoxy(px,r5);printf("  ");
					z--;
					r1=z;
					r2=z+1;
					r3=z+2;
					r4=z+3;
					r5=aux;
					gotoxy(px,r1);printf("\xDB");
					gotoxy(px,r2);printf("\xDB");
					gotoxy(px,r3);printf("\xDB");
					gotoxy(px,r4);printf("\xDB");
					gotoxy(px,r5);printf("\xDB");
				       }
				    }
			 }
}
void player::gamer2(char ch1){
       int   b=19;

       aux=z+5;
		 if (ch1 == 80)
			{
				if(z<b){
				       if(aux<=b){
					gotoxy(px,r1);printf("  ");
					gotoxy(px,r2);printf("  ");
					gotoxy(px,r3);printf("  ");
					gotoxy(px,r4);printf("  ");
					gotoxy(px,r5);printf("  ");


					z++;
					r1=z;
					r2=z+1;
					r3=z+2;
					r4=z+3;
					r5=aux;
					gotoxy(px,r1);printf("\xDB");
					gotoxy(px,r2);printf("\xDB");
					gotoxy(px,r3);printf("\xDB");
					gotoxy(px,r4);printf("\xDB");
					gotoxy(px,r5);printf("\xDB");

				       }
				      }
	 }
}
/*void player::pos(){
	 p1=z;
	 p2=z+1;
	 p3=z+2;
	 p4=aux-1;
	 p5=aux;
}   */
void DeletaCursor()
{
	REGS regs;
	regs.h.ah=0x01;
	regs.h.ch=0x20;
	int86(VIDEO, &regs,&regs);
}
void main()
{
	char ch1;
	clrscr();
	DeletaCursor();
	padel p;
	player b;
	campo c;
	c.desenha();
	//p.posicao();

	c.tempoin();
	b.gamer1(ch1);
	while(ch1!=27){

		p.ball();
		p.rebatida();
		//c.erros();
		p.erros();
		if (kbhit())
			{
				 ch1=getch();
				 if(ch1==72){
					b.gamer1(ch1);
					p.posicao2();
				 }
				 if(ch1==80){
					b.gamer2(ch1);
					p.posicao1();
				 }
				 //b.pos();
				 if (ch1==27){
						 exit(0);
				 }
				 if(ch1==43){
					       p.velocidade(ch1);

					}
				 if(ch1==45){
					       p.velocidade(ch1);
					}
			}

		c.tempoout();
	 }
}