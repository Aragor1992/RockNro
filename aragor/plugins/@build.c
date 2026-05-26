#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#include "../common/HPMi.h"
#include "../map/clif.h"
#include "../map/atcommand.h"
#include "../map/script.h"
#include "../map/pc.h"
#include "../common/nullpo.h"
 
#include "../common/HPMDataCheck.h"
 
HPExport struct hplugin_info pinfo =
{
    "@resist",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "0.1",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};
 
/*=========================================
 * Check values of resistance to elements
 * [ Keitenai ]
 *-----------------------------------------*/
ACMD(resist) {
	char output[CHAT_SIZE_MAX];
	int i;
	struct {
		const char* format;
		int value;
	} output_table[] = {
		{ "   [ %d ] Neutral resist", 0 },
		{ "   [ %d ] Water resist", 0 },
		{ "   [ %d ] Earth resist", 0 },
		{ "   [ %d ] Fire resist", 0 },
		{ "   [ %d ] Wind resist", 0 },
		{ "   [ %d ] Poison resist", 0 },
		{ "   [ %d ] Holy resist", 0 },
		{ "   [ %d ] Dark resist", 0 },
		{ "   [ %d ] Ghost resist", 0 },
		{ "   [ %d ] Undead resist", 0 },
		{ NULL, 0 }
	};
	memset(output, '\0', sizeof(output));
	clif->message(fd, "========= Resistance Values =========");
	output_table[0].value = (sd->subele[ELE_NEUTRAL]);
	output_table[1].value = (sd->subele[ELE_WATER]);
	output_table[2].value = (sd->subele[ELE_EARTH]);
	output_table[3].value = (sd->subele[ELE_FIRE]);
	output_table[4].value = (sd->subele[ELE_WIND]);
	output_table[5].value = (sd->subele[ELE_POISON]);
	output_table[6].value = (sd->subele[ELE_HOLY]);
	output_table[7].value = (sd->subele[ELE_DARK]);
	output_table[8].value = (sd->subele[ELE_GHOST]);
	output_table[9].value = (sd->subele[ELE_UNDEAD]);
 
	for (i = 0; output_table[i].format != NULL; i++) {
		sprintf(output, output_table[i].format, output_table[i].value);
		clif->message(fd, output);
	}
	return 1;
}
 
 
/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("resist",resist);
}