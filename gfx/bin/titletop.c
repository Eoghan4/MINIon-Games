#include <PA_BgStruct.h>

extern const char titletop_Tiles[];
extern const char titletop_Map[];
extern const char titletop_Pal[];

const PA_BgStruct titletop = {
	PA_BgNormal,
	256, 192,

	titletop_Tiles,
	titletop_Map,
	{titletop_Pal},

	20992,
	{1536}
};
