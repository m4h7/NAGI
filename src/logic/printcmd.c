#include "../agi.h"

#include "../logic/cmd_table.h"


// num, name, flags

int main(int argc, char *argv[])
{
	int i, j;
	int mask;
	printf("blah");
	for (i=0; i<CMD_MAX; i++)
	{
		printf("%d, \"%s\"", i, cmd_table[i].func_name);
		
		mask = 0x80;
		
		for (j=0; j<cmd_table[i].param_total; j++)
		{
			if (cmd_table[i].param_flag & mask)
				printf(", VAR" );
			else
				printf(", NUM" );
			mask >>= 1;
		}
		
		printf("\n");
	}
	printf("\n");
}

