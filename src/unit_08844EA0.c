/* unit_08844EA0: 0x08844EA0-0x08844FC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08844EA0 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s32 func_09D296A8(char *);
extern s32 func_09B31FB0(char *);
extern s32 func_09D1E6E0(char *);

s32 func_08844EA0(char *arg0, char *arg1) {
    u8 k = *(u8 *)(arg1 + 0x1E8);

    if ((s32)(k == 0x3B) == 1) {
        return 1;
    }
    if (*(u8 *)(arg0 + 0x5E7) >= 4) {
        return 0;
    }
    if (*(u8 *)(arg1 + 0x613) != 0) {
        return 1;
    }
    switch (k) {
    case 0xF:
    case 0x2D:
        return *(s8 *)(arg1 + 0x529) != 0;
    case 0x16:
        return func_09D1E6E0(arg1);
    case 0x1A:
    case 0x2C:
    case 0xE:
    case 0x2B:
        return *(u8 *)(arg1 + 0x280) == 4;
    case 0x33:
    case 0x54:
    case 0x3D:
        return func_09B31FB0(arg1);
    case 0x53:
        return func_09D296A8(arg1);
    }
    return 0;
}
