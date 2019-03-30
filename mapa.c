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
	int x, y, v, a, g, p;
	int jogadory = rand()%(9);//Posição do jogador no eixo x
	int jogadorx = rand()%(19);//Posição do jogador no eixo y
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
				if (campo[x][y] == '1') {
				}
				else {
					campo[x][y] = '0';
				}
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
			scanf(" [%c%d]", &dir, &n);
			if (n > 0) {
				switch (dir) {
					case 'N':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadory--;
						}
						a++;
						break;
					case 'n':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadory--;
						}
						a++;
						break;
					case 'S':
					for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadory++;
						}
						a++;
						break;
					case 's':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadory++;
						}
						a++;
						break;
					case 'L':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadorx++;
						}
						a++;
						break;
					case 'l':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadorx++;
						}
						a++;
						break;
					case 'O':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadorx--;
						}
						a++;
						break;
					case 'o':
						for (p = 0; p < n; p++) {
							campo[jogadory][jogadorx] = '1';
							jogadorx--;
						}
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