#ifndef vstring_h_file
#define vstring_h_file

/* STRUCTURES	---	---	---	---	---	---	--- */

	
/* VARIABLES	---	---	---	---	---	---	--- */
/* FUNCTIONS	---	---	---	---	---	---	--- */
extern VSTRING *vstring_new(u8 *str, u32 min_size);
extern void vstring_free(VSTRING *vs);
extern void vstring_shrink(VSTRING *vs);
extern void vstring_set_text(VSTRING *vs, u8 *str);
extern void vstring_set_size(VSTRING *vs, u32 new_size);
extern void vstring_shift(VSTRING *vs, u32 shift_size);

#endif
