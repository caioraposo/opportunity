#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>


int main(int argc, char** argv[]) {

	// Inicialização
	srand(time(0));
	int x, y, p, game, parar;
	int jogadory = rand()%(9); // Posição do jogador no eixo x
	int jogadorx = rand()%(19); // Posição do jogador no eixo y
	int obs = 50;
	int obstaculox[obs]; // Criar lista dos obstáculos x
	int obstaculoy[obs]; // Criar lista dos obstáculos y
	char campo [10][20]; // Criar campo
	game = 0;
	parar = 0;

	// Criação do mapa
	for(x = 0; x < obs; x++){ // Definição dos obstaculos no eixo X
		obstaculox[x] = rand()%(9);
	}
	for (y = 0; y < obs; y++) { // Definição dos obstaculos no eixo Y
		obstaculoy[y] = rand()%(19);
	}

	while (game == 0) { // Execução continua do jogo
		//system("clear");
		printf("%d %d\n",jogadorx, jogadory );
		for (x = 0; x < 10; x++) { // Impressão do mapa

			for (y = 0; y < 20;y++) { // Definição da malha do mapa
				if (!(campo[x][y] == '1' || campo[x][y] == '#')) {
					campo[x][y] = '0';
				}
				if (jogadorx == y && jogadory == x) { // Indicação do jogador no mapa
					campo[x][y] = 'x';
				}
				printf("%c",campo[x][y]);
				if (y == 19 ) {
					printf("\n");
				}
			}
		}

		char direcao;
		int passos;
		printf("Insira as coordenadas.\tEx: [N 2]\n\n");
		scanf(" [%c%d]", &direcao, &passos);
		direcao = toupper(direcao);
		if (passos < 0) {
			printf("Insira apenas valores positivos!\n");
			continue;
		}
		switch (direcao) {
			case 'N':
				for (p = 0; p < passos; p++) {

					campo[jogadory][jogadorx] = '1';
					jogadory--;
					printf("subtraind y\n");
					printf("%d\n",passos);

					for(x = 0; x < obs; x++){
						printf("Jogadorx %d\nJogadory %d\nObstaculox %d\nObstaculoy %d\n\n",jogadorx, jogadory, obstaculox[x], obstaculoy[x] );
						if (jogadory == obstaculox[x] && jogadorx == obstaculoy[x]) {
							printf("1234");
							parar = 1;
							campo[obstaculox[x]][obstaculoy[x]] = '#';
							jogadory++;
							break;
						}
					}
					if (jogadory < 0) {
						jogadory = 0;
					}
					if (parar == 1){
						parar = 0;
						break;
					}
				}

				break;
			case 'S':
			for (p = 0; p < passos; p++) {
					campo[jogadory][jogadorx] = '1';
					jogadory++;
					if (jogadory > 9) {
						jogadory = 9;
					}
				}

				break;
			case 'L':
				for (p = 0; p < passos; p++) {
					campo[jogadory][jogadorx] = '1';
					jogadorx++;
				}

				break;
			case 'O':
				for (p = 0; p < passos; p++) {
					campo[jogadory][jogadorx] = '1';
					jogadorx--;
				}

				break;
			default:
				printf("Valor invalido, insira apenas direcoes cardiais.\n\n");
		}

	}
	return 0;
}
