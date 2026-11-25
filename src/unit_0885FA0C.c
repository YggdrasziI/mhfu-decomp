/* unit_0885FA0C: 0x0885FA0C-0x0885FB54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_08863198(char *arg0, char *arg1, u32 arg2, char *arg3);
extern void func_088632D8(char *arg0, char *arg1, char *arg2);

void func_0885FA0C(char *node, f32 t, s32 id, s32 flag) {
    char *s;
    s32 i;

    if ((u8)flag == 0) {
        s = node + 0x150;
    } else {
        s = node + 0x1D0;
    }
    if (*(u16 *)(node + 0x114) == id || id == -1) {
        for (i = 0; i < 9; i++) {
            ((f32 *)s)[i + 0x10] = ((f32 *)node)[i + 0x48];
        }
        if (*(s32 *)(s + 0x64) != 0) {
            func_08863198(s, s + 0x40, (u32)t, s + 0x6C);
        }
        func_088632D8(s, s, s + 0x40);
        if (*(char **)(node + 0x14C) != 0) {
            func_0885FA0C(*(char **)(node + 0x14C), t, id, flag);
        }
    }
    if (*(char **)(node + 0x148) != 0) {
        func_0885FA0C(*(char **)(node + 0x148), t, id, flag);
    }
}
