#include <PA_BgStruct.h>

extern const char select_game_bottom_Tiles[];
extern const char select_game_bottom_Map[];
extern const char select_game_bottom_Pal[];

const PA_BgStruct select_game_bottom = {
	PA_BgNormal,
	256, 192,

	select_game_bottom_Tiles,
	select_game_bottom_Map,
	{select_game_bottom_Pal},

	4800,
	{1536}
};
