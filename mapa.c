#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int main(int argc, char** argv){	
	
	
	srand(time(0));
	int i, j;
	int condicao = 0;
	int jogador = rand()%(99);
	int obstaculo[25];
	char campo [100];
	for(j = 0; j <= 24; j++){
		obstaculo[j] = rand()%(100);
	}
	
	printf("Jogador %d", jogador);
	for (i = 0; i <= 99; i++){
		campo[i] = '1';
		condicao = 0;
		
		if (i%10 == 0){
			printf("\n");	
		}
		if (jogador == i){
			printf("x");
			continue;
		}
		for(j = 0; j <= 24; j++){
			if (obstaculo[j] == i){
			printf("#");
			condicao = 1;
	  	    }
		}
		
		if(condicao == 1){
			continue;
		}
		printf("%c",campo[i]);
		
		
	
	}
	
	return 0;
}
