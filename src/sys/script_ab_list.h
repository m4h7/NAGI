struct script_struct
{
	u8 action;
	u8 data;
};
typedef struct script_struct SCRIPT;
	
//extern u8 *script_head;
extern int mem_script;


extern void script_block(void);
extern void script_allow(void);
extern void script_new(void);
extern void script_write(u16 action, u16 data);
extern void script_first(void);
extern SCRIPT *script_get_next(void);
extern u8 *cmd_script_size(u8 *c);
extern u8 *cmd_unknown_171(u8 *c);
extern u8 *cmd_unknown_172(u8 *c);

