/* unit_088134E8: 0x088134E8-0x08813558 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

void func_088134E8(char *arg0, float *arg1, float *arg2, float *arg3, s32 arg4) {
    char *b = arg0 + 0x7E0;
    float *p;

    p = (float *)(b + 0x10);
    asm {
        lv.q C000, 0(arg1)
        sv.q C000, 0(p)
    }
    p = (float *)(b + 0x20);
    asm {
        lv.q C000, 0(arg2)
        sv.q C000, 0(p)
    }
    *(float *)(arg0 + 0x830) = *arg3;
    if ((u8)arg4 == 1) {
        b[0] = 0;
        b[0x30] = 2;
        *(s16 *)(b + 0x36) = 15;
    } else {
        b[0x30] = 1;
    }
    ((s32 *)(b + 4))[*(s32 *)(b + 0x54)] = 0;
    (*(s32 *)(b + 0x54) + b)[0x31] = 2;
}
