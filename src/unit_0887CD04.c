/* unit_0887CD04: 0x0887CD04-0x0887CDFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_08A62D8C;

extern u16 func_0884FB6C(char *p);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_0887CD04(char *arg0) {
    if (*(s16 *)(arg0 + 0xAA) > 0) {
        (*(s16 *)(arg0 + 0xAA))--;
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 0:
        if (--(*(s16 *)(arg0 + 0xA8)) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
        }
        break;
    case 1:
        if (*(s16 *)(arg0 + 0xAA) > 0) {
            if (!(func_0884FB6C(D_089CC438) & 0x4000)) {
                break;
            }
            if (*(s16 *)(arg0 + 0xAA) >= 0x32B) {
                break;
            }
        }
        if (*(s8 *)(arg0 + 0xC1) != 0) {
            break;
        }
        (*(s16 *)(arg0 + 0xA4))++;
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
