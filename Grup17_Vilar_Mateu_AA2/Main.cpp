//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
//#include "Types.h"
//#include "Constants.h"

int main() {
	Map map;
	Player player;
	Keys key;
	bool endGame = false;
	int speed = 500;
	bool right, left, up, down;

	//Inicialitzar mapa
	map.ReadMap();
	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	//Dibuixar mapa
	map.WriteMap(player.pos);

	while (!endGame) {		//TODO: Canviar strcut Position per un vector, a més corregir la inversió que he vist de la x i la y a l'actualitzar la posició del jugador
		key.GetKeys(right, left, up, down);
		player.MovePlayer(right, left, up, down, map.map, map.totalColumns, map.totalRows);
		map.ActualizeMap(player.pos, player.initialPos, player.character);
		//printf("\n%c", map.map[player.pos.x][0]);
		Sleep(speed);
		system("cls");

		/*if () {

			endGame = true;
		}*/

	}

	return 0;
}