#include <PA_BgStruct.h>

extern const char sort_top_yellow_Tiles[];
extern const char sort_top_yellow_Map[];
extern const char sort_top_yellow_Pal[];

const PA_BgStruct sort_top_yellow = {
	PA_BgNormal,
	256, 192,

	sort_top_yellow_Tiles,
	sort_top_yellow_Map,
	{sort_top_yellow_Pal},

	22592,
	{1536}
};
