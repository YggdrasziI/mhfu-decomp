/* unit_0886691C: 0x0886691C-0x088669F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886691C: copies 0x30 (type, value) entries into arg0 and resolves
 * the value of each type-2 entry through func_08866BD4. */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 type;
    s32 val;
} Entry;

extern s32 func_08866BD4(char *, s32);

void func_0886691C(char *arg0, Entry *arg1) {
    s32 i;
    char *p4;
    char *p8;

    for (i = 0, p4 = arg0, p8 = arg0; i < 0x30; i++) {
        switch (arg1->type) {
        case 0:
            break;
        case 2:
            if (arg1->val != -1) {
                *(s32 *)(p4 + 0x80258) = func_08866BD4(arg0, arg1->val);
                *(s32 *)(p4 + 0x80318) = arg1->val;
            }
            *(u8 *)(p8 + 0x800A8) = arg1->type;
            *(s32 *)(p8 + 0x800AC) = arg1->val;
            break;
        }
        p4 += 4;
        p8 += 8;
        arg1++;
    }
}
