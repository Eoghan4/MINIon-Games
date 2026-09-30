#include <PA_BgStruct.h>

extern const char sort_top_oops_Tiles[];
extern const char sort_top_oops_Map[];
extern const char sort_top_oops_Pal[];

const PA_BgStruct sort_top_oops = {
	PA_BgNormal,
	256, 192,

	sort_top_oops_Tiles,
	sort_top_oops_Map,
	{sort_top_oops_Pal},

	25152,
	{1536}
};
