#include <PA_BgStruct.h>

extern const char sort_bottom_Tiles[];
extern const char sort_bottom_Map[];
extern const char sort_bottom_Pal[];

const PA_BgStruct sort_bottom = {
	PA_BgNormal,
	256, 192,

	sort_bottom_Tiles,
	sort_bottom_Map,
	{sort_bottom_Pal},

	3712,
	{1536}
};
