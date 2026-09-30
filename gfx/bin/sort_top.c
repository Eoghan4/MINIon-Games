#include <PA_BgStruct.h>

extern const char sort_top_Tiles[];
extern const char sort_top_Map[];
extern const char sort_top_Pal[];

const PA_BgStruct sort_top = {
	PA_BgNormal,
	256, 192,

	sort_top_Tiles,
	sort_top_Map,
	{sort_top_Pal},

	18624,
	{1536}
};
