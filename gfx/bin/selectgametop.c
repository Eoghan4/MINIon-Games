#include <PA_BgStruct.h>

extern const char selectgametop_Tiles[];
extern const char selectgametop_Map[];
extern const char selectgametop_Pal[];

const PA_BgStruct selectgametop = {
	PA_BgNormal,
	256, 192,

	selectgametop_Tiles,
	selectgametop_Map,
	{selectgametop_Pal},

	23104,
	{1536}
};
