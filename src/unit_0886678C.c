/* unit_0886678C: 0x0886678C-0x08866864 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886678C: copies 48 (type, value) entries into tables at +0x800A8. */

typedef int s32;
typedef unsigned char u8;

typedef struct Entry {
    u8 type;
    s32 val;
} Entry;

extern s32 func_08866B5C(char *, s32);

void func_0886678C(char *arg0, Entry *e) {
    s32 i;
    char *p4;
    char *p8;

    for (i = 0, p4 = arg0, p8 = arg0; i < 48; i++, p4 += 4, p8 += 8, e++) {
        switch (e->type) {
        case 0:
            break;
        case 1:
            if (e->val != -1) {
                *(s32 *)(p4 + 0x80258) = func_08866B5C(arg0, e->val);
                *(s32 *)(p4 + 0x80318) = e->val;
            }
            *(u8 *)(p8 + 0x800A8) = e->type;
            *(s32 *)(p8 + 0x800AC) = e->val;
            break;
        }
    }
}
