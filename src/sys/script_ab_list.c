/*
_ScriptBlock                     cseg     00006F97 0000000F
_ScriptAllow                     cseg     00006FA6 0000000F
_ScriptNew                       cseg     00006FB5 00000035
_ScriptWrite                     cseg     00006FEA 0000007E
_ScriptFirst                     cseg     00007068 0000001D
_ScriptNext                      cseg     00007085 0000001E
CmdScriptSize                    cseg     000070A3 00000021
CmdUnknown171                    cseg     000070C4 00000012
CmdUnknown172                    cseg     000070D6 00000020
*/

#include <stdlib.h>

#include "../agi.h"
#include "../flags.h"

#include "../view/obj_update.h"
#include <setjmp.h>
#include "error.h"
#include "script.h"
#include "../list.h"
#include "../sys/mem_wrap.h"

#include <assert.h>


	
LIST *list_script = 0;
int write_ok = 0;
int mem_script = 0;

void script_block(void)
{
	write_ok = 0;
}

void script_allow(void)
{	write_ok = 1;
}

void script_new(void)
{
	if (list_script)
		list_clear(list_script);
	else
	{
		list_script = list_new(sizeof(SCRIPT));
		//set_mem_rm0();
	}
	
}

void script_write(u16 action, u16 data)
{
	SCRIPT *scr;
	
	if (!flag_test(7))
	{
		if (write_ok)
		{
			scr = list_add(list_script);
			scr->action = action;
			scr->data = data;
		}
		if (list_length(list_script) > state.script_size)
			printf("script_write(): original interpreter would have run out of script space.\n");
		
		if (list_length(list_script) > mem_script)
			mem_script = list_length(list_script);
	}
}

SCRIPT *script_cur = 0;

// init some search?
void script_first()
{
	script_cur = list_element_head(list_script);
}

// return a ptr?  so the returning function can change it instead??
// get next script item
SCRIPT *script_get_next()
{
	SCRIPT *ret;
	
	ret = script_cur;
	
	script_cur = node_next(script_cur);
	return ret;
}

u8 *cmd_script_size(u8 *c)
{
	int new_size;
	
	new_size = *(c++);
	
	// if a list exists and trying to set a different size.. warn
	if ( (list_script) && (new_size != state.script_size) )
		printf("cmd_script_size(): new size. original interpreter would not reallocate script.\n");
	if ( (list_script) && (list_length(list_script) != 0) )
		printf("cmd_script_size(): discarding available script data and may corrupt save/reload process.\n");
	state.script_size = new_size;
	
	blists_erase();
	script_new();
	blists_draw();
	
	return c;
}

SCRIPT *saved=0;

u8 *cmd_unknown_171(u8 *c)
{
	saved = list_element_tail(list_script);
	return c;
}

u8 *cmd_unknown_172(u8 *c)
{
	assert(saved);
	list_clear_past(list_script, saved);
	return c;
}




