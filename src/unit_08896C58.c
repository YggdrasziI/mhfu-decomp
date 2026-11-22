/* unit_08896C58: 0x08896C58-0x08896CA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_08896C58: picks a byte from the
 * row arg1 of the D_089B1630 pointer table (2-byte entries, column arg2),
 * maps it through the u16 table D_089B0F70 and tail-calls func_09A63188
 * with D_09A44C5C and that id. arg0 is unused.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_09A44C5C;
extern u8 *D_089B1630[];
extern u16 D_089B0F70[];

extern char *func_09A63188(s32 arg0, u16 arg1);

char *func_08896C58(s32 arg0, u8 arg1, u8 arg2) {
    u8 *p;
    s32 i;

    /* The index is computed before the row is loaded, then added in its
     * own statement: that puts the index in a0 and the row in a1. */
    i = arg2 * 2;
    p = D_089B1630[arg1];
    p += i;
    return func_09A63188(D_09A44C5C, D_089B0F70[*p]);
}
