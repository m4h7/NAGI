#ifndef obj_picbuff_h_file
#define obj_picbuff_h_file

/* STRUCTURES	---	---	---	---	---	---	--- */
/* VARIABLES	---	---	---	---	---	---	--- */
u8 pri_table[172];

/* FUNCTIONS	---	---	---	---	---	---	--- */
extern void table_init(void);
extern u16 obj_chk_control(VIEW *v);
extern void obj_cel_update(VIEW *v);
extern void obj_add_pic_pri(VIEW *v);
extern void obj_cel_mirror(VIEW *v);
extern void obj_pos_shuffle(VIEW *v);
#endif
