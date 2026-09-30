#include <PA_BgStruct.h>

extern const char titlebottom_Tiles[];
extern const char titlebottom_Map[];
extern const char titlebottom_Pal[];

const PA_BgStruct titlebottom = {
	PA_BgNormal,
	256, 192,

	titlebottom_Tiles,
	titlebottom_Map,
	{titlebottom_Pal},

	14016,
	{1536}
};
