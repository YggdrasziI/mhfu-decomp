/* unit_08871B34: 0x08871B34-0x08871BC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, s32);

void func_08871B34(s32 arg0, char *arg1) {
    s32 j;
    s32 i;
    char *p;
    u8 flag;

    j = 0;
    if (*(u8 *)(arg1 + 0x1E8) != 0x12) {
        return;
    }
    for (i = 0; i < 4; i++, j++) {
        p = func_088DCEBC(D_09A4F0C4, j);
        if (p == 0) {
            continue;
        }
        flag = (*(u32 *)(p + 4) & 1) != 0;
        if (flag) {
            if (*(char **)(p + 0x560) == arg1) {
                *(char **)(p + 0x560) = 0;
            }
        }
    }
}
