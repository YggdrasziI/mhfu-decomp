/* unit_088FCF40: 0x088FCF40-0x088FCF84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Counts the entries of a three-entry table (0x1C bytes each,
 * at +0x2C of arg0) whose first halfword is 2 and second halfword is arg1.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 kind;
    u16 id;
    char pad4[0x18];
} Entry;

s32 func_088FCF40(char *arg0, s32 arg1) {
    Entry *e = (Entry *)(arg0 + 0x2C);
    s32 count = 0;
    s32 i;

    for (i = 0; i < 3; i++, e++) {
        if (e->kind == 2 && e->id == arg1) {
            count++;
        }
    }
    return count;
}
