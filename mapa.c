#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int main(int argc, char** argv[]) {
	
	// Inicialização

	srand(time(0));
	int x, y, v, n, a, g;
	char dir;
	int condicao = 0;
	int jogadorx = rand()%(9);//Posição do jogador no eixo x
	int jogadory = rand()%(19);//Posição do jogador no eixo y
	int obs = rand()%(25);
	int obstaculox[obs];//Criar lista dos obstáculos x 
	int obstaculoy[obs];//Criar lista dos obstáculos y  
	char campo [10][20];//Criar campo
	g = 0;
	// Criação do mapa

	for(x = 0; x <= obs; x++){ // FOR OBSTACULOS 1
		obstaculox[x] = rand()%(9);
	}
	for (y = 0; y <= obs; y++) { // FOR OBSTACULOS 2
		obstaculoy[y] = rand()%(19);
	}
	while (g == 0) { // Fazer rodar
		for (x = 0; x < 10; x++) { // FOR 3
			
			for (y = 0; y < 20;y++) { // FOR 4
				campo[x][y] = '0';
				
				for (v = 0; v <= obs; v++){ // FOR 5
					if (obstaculox[v] == x && obstaculoy[v] == y) { // IF 1
						campo[x][y] = '#';
					}
				}			   
				if (jogadorx == x && jogadory == y) { // IF 2
					campo[x][y] = 'x';
				}
				printf("%c",campo[x][y]); // IF 3
				if (y == 19 ) {
					printf("\n");
				}
			}
		}
		a = 0;
		while (a == 0) { // Controle de erros da inserção
			printf("Insira as coordenadas.\tEx: [N 2]\n\n");
			scanf("[%c%d]", &dir, &n);
			if (n > 0) {
				switch (dir) {
					case 'N':
						jogadory += n;
						a++;
						break;
					case 'S':
						jogadory -= n;
						a++;
						break;
					case 'L':
						jogadorx += n;
						a++;
						break;
					case 'O':
						jogadorx -= n;
						a++;
						break;
					default:
						printf("Valor inválido, nao estou surpreso");
				}
			}
		}
	}
	return 0;
}