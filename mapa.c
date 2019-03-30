#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv[]) {
	
	// Inicialização

	srand(time(0));
	int x, y, v, a, g;
	int jogadorx = rand()%(9);//Posição do jogador no eixo x
	int jogadory = rand()%(19);//Posição do jogador no eixo y
	int obs = rand()%(25);
	int obstaculox[obs];//Criar lista dos obstáculos x 
	int obstaculoy[obs];//Criar lista dos obstáculos y  
	char campo [10][20];//Criar campo
	g = 0;
	// Criação do mapa

	for(x = 0; x <= obs; x++){ // FOR OBSTACULOS 1 - Definição dos obstaculos no eixo X
		obstaculox[x] = rand()%(9);
	}
	for (y = 0; y <= obs; y++) { // FOR OBSTACULOS 2 - Definição dos obstaculos no eixo Y
		obstaculoy[y] = rand()%(19);
	}
	
	while (g == 0) { // While responsável por manter o jogo rodando
		system("cls");
		for (x = 0; x < 10; x++) { // FOR 3 - Responsável pela impressão do mapa
			
			for (y = 0; y < 20;y++) { // FOR 4 - Definição da malha do mapa
				campo[x][y] = '0';
				
				for (v = 0; v <= obs; v++) { // FOR 5 - Geração da indicação de obstáculos no mapa
					if (obstaculox[v] == x && obstaculoy[v] == y) { // IF 1
						campo[x][y] = '#';
					}
				}
				if (jogadorx == y && jogadory == x) { // IF 2 - Indicação do jogador no mapa
					campo[x][y] = 'x';
				}
				printf("%c",campo[x][y]); // IF 3
				if (y == 19 ) {
					printf("\n");
				}
			}
		}
		Sleep(1000);
		for (a = 0; a == 0;) { // Controle de erros durante a inserção das coordenadas
			char dir;
			int n;
			printf("Insira as coordenadas.\tEx: [N 2]\n\n");
			scanf("[%c%d]", &dir, &n);
			if (n > 0) {
				switch (dir) {
					case 'N':
						jogadory -= n;
						a++;
						break;
					case 'n':
						jogadory -= n;
						a++;
						break;
					case 'S':
						jogadory += n;
						a++;
						break;
					case 's':
						jogadory += n;
						a++;
						break;
					case 'L':
						jogadorx += n;
						a++;
						break;
					case 'l':
						jogadorx += n;
						a++;
						break;
					case 'O':
						jogadorx -= n;
						a++;
						break;
					case 'o':
						jogadorx -= n;
						a++;
						break;
					default:
						printf("Valor invalido, nao estou surpreso\n\n");
						break;
				}
			}
		}
	}
	return 0;
}