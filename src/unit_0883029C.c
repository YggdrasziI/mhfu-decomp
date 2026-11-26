/* unit_0883029C: 0x0883029C-0x08830354 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0883029C */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A62C54;
extern u16 D_0893AE80[][11];
extern u8 D_0893AEAC[][5];
extern u8 func_0885CD18(char *arg0, u8 arg1, u16 arg2);

s32 func_0883029C(char *arg0, u8 *arg1, s32 arg2) {
    u16 id = *(u16 *)(arg1 + 2);
    u8 kind;

    if (id > 0x5DC) {
        return (u8)arg2 == 0 ? 0x71 : 0xE1;
    }
    kind = arg1[1];
    if ((u32)(kind - 5) < 2) {
        return D_0893AE80[(u8)arg2][func_0885CD18(D_08A62C54, kind, id)];
    }
    return D_0893AEAC[(u8)arg2][kind];
}
