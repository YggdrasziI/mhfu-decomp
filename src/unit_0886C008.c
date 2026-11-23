/* unit_0886C008: 0x0886C008-0x0886C1E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886C008 */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s8 count;
    u8 pad;
} Slot;

typedef struct {
    char pad0[0x6C];
    Slot slot[5];
    s8 next;
} Box;

extern char D_0899D19B[];
extern s16 func_0886BFBC(Box *, s32);

u16 func_0886C008(Box *arg0, s32 arg1, s16 arg2) {
    s16 i;
    u16 ret;
    s8 max;

    if ((i = func_0886BFBC(arg0, arg1)) == 0) {
        ret = 5;
        for (i = 0; i < 5; i++) {
            if (arg0->slot[i].id == 0 && arg2 > 0) {
                arg0->slot[i].id = arg1;
                arg0->slot[i].count = arg2;
                ret = 0;
                break;
            }
        }
        if (ret == 5) {
            arg0->slot[arg0->next].id = arg1;
            arg0->slot[arg0->next].count = arg2;
            arg0->next++;
            if (arg0->next >= 5) {
                arg0->next = 0;
            }
        }
    } else {
        for (i = 0; i < 5; i++) {
            if (arg0->slot[i].id == (u16)arg1) {
                max = D_0899D19B[(arg1 & 0xFFFF) * 24];
                if (arg2 > 0 && arg0->slot[i].count >= max) {
                    arg0->slot[i].count = max;
                    ret = 3;
                } else {
                    arg0->slot[i].count += (s8)arg2;
                    if (arg0->slot[i].count <= 0) {
                        arg0->slot[i].id = 0;
                        arg0->slot[i].count = 0;
                        ret = 4;
                    } else if (arg0->slot[i].count > max) {
                        arg0->slot[i].count = max;
                        ret = 2;
                    } else {
                        ret = 1;
                    }
                }
                break;
            }
        }
    }
    return ret;
}
