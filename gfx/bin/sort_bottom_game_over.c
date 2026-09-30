#include <PA_BgStruct.h>

extern const char sort_bottom_game_over_Tiles[];
extern const char sort_bottom_game_over_Map[];
extern const char sort_bottom_game_over_Pal[];

const PA_BgStruct sort_bottom_game_over = {
	PA_BgNormal,
	256, 192,

	sort_bottom_game_over_Tiles,
	sort_bottom_game_over_Map,
	{sort_bottom_game_over_Pal},

	49152,
	{1536}
};
