#include <PA_BgStruct.h>

extern const char sort_top_purple_Tiles[];
extern const char sort_top_purple_Map[];
extern const char sort_top_purple_Pal[];

const PA_BgStruct sort_top_purple = {
	PA_BgNormal,
	256, 192,

	sort_top_purple_Tiles,
	sort_top_purple_Map,
	{sort_top_purple_Pal},

	19776,
	{1536}
};
