#include <PA_BgStruct.h>

extern const char sort_top_game_over_Tiles[];
extern const char sort_top_game_over_Map[];
extern const char sort_top_game_over_Pal[];

const PA_BgStruct sort_top_game_over = {
	PA_BgNormal,
	256, 192,

	sort_top_game_over_Tiles,
	sort_top_game_over_Map,
	{sort_top_game_over_Pal},

	32960,
	{1536}
};
