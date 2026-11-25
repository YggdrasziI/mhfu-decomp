/* unit_0885ECF4: 0x0885ECF4-0x0885EE48 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    char pad[24];
} E28;

typedef struct {
    u32 w0;
    char pad[20];
} E24;

extern s32 D_08A62C54;
extern E28 D_08960BA0[];
extern E24 D_08959FD0[];

extern u8 func_0885CD18(s32 arg0, u8 arg1, u16 arg2);
extern s32 func_0885E664(s32 arg0, u8 arg1, u16 arg2, s32 arg3);
extern s32 func_0885EE48(s32 arg0, char *arg1);

s32 func_0885ECF4(s32 arg0, char *arg1) {
    u32 v;
    u16 n;
    s32 i;
    u8 t;

    if (*(u16 *)(arg1 + 2) == 0) {
        return 0;
    }
    t = func_0885CD18(D_08A62C54, *(u8 *)(arg1 + 1), *(u16 *)(arg1 + 2));
    if (t == 1 || t == 5) {
        v = D_08960BA0[*(u16 *)(arg1 + 2)].w0;
        n = *(u16 *)(arg1 + 4) & 0xF;
        if (n) {
            s32 m = n;
            for (i = 0; i < m; i++) {
                v += func_0885E664(arg0, *(u8 *)(arg1 + 1), *(u16 *)(arg1 + 2), i);
            }
        }
    } else {
        switch (*(u8 *)(arg1 + 1)) {
        case 5:
            v = D_08959FD0[*(u16 *)(arg1 + 2)].w0;
            break;
        case 6:
            v = D_08960BA0[*(u16 *)(arg1 + 2)].w0;
            break;
        default:
            v = 0;
            break;
        }
    }
    v = v >> 1;
    v += func_0885EE48(arg0, arg1);
    return v;
}
