#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int main(int argc, char** argv){	
	
	
	srand(time(0));
	int x, y, v;
	int condicao = 0;
	int jogadorx = rand()%(9);//Posição do jogador no eixo x
	int jogadory = rand()%(19);//Posição do jogador no eixo y
	int obs = rand()%(25);
	int obstaculox[obs];//Criar lista dos obstáculos x
	int obstaculoy[obs];//Criar lista dos obstáculos y
	char campo [10][20];//Criar campo
	
	
	for(x = 0; x <= obs; x++){
		obstaculox[x] = rand()%(9);
	}
	for(y = 0; y <= obs; y++){
		obstaculoy[y] = rand()%(19);
	}
	
	
	for (x = 0; x < 10; x++){
		
		for(y = 0; y < 20;y++){
			   campo[x][y] = '0';
			   
			   for(v = 0; v <= obs; v++){
					if(obstaculox[v] == x && obstaculoy[v] == y){
						campo[x][y] = '#';
						
					}
				}
			   
			   if (jogadorx == x && jogadory == y){
				campo[x][y] = 'x';
				}
			   printf("%c",campo[x][y]);
			   if(y == 19 ){
				   printf("\n");
			   }
	   	   	   
			   	
		}
		
		
		

		
		

		
		
	
	}
	
	return 0;
}
