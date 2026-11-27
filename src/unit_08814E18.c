/* unit_08814E18: 0x08814E18-0x08815004 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;


void func_08812DB8(char *arg0, char *arg1);
void func_08815004(char *arg0, s32 arg1);

static inline void vcopy(void *src, void *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

void func_08814E18(char *arg0) {
    s32 i;
    char *e;
    char *p;

    for (i = 0, e = arg0; i < 3; i++, e += 0x20) {
        if (*(u8 *)(e + 0xAC0) != 0) {
            if (--*(s16 *)(e + 0xAC2) <= 0) {
                *(u8 *)(e + 0xAC0) = 0;
            }
        }
    }
    p = arg0 + *(u8 *)(arg0 + 0xA8D) * 0x1A0 + 0xB0;
    vcopy(p, arg0 + 0x20);
    vcopy(p + 0x10, arg0 + 0x30);
    *(f32 *)(arg0 + 0xA0) = *(f32 *)(p + 0x80);
    *(f32 *)(arg0 + 0xA8) = *(f32 *)(p + 0x88);
    *(s8 *)(arg0 + 0xDC4) = -1;
    if (*(u8 *)(arg0 + 0x961) != 0) {
        *(s8 *)(arg0 + 0xDC4) = 5;
    } else if (*(u8 *)(arg0 + 0x621) != 0) {
        *(s8 *)(arg0 + 0xDC4) = 3;
    } else if (*(u8 *)(arg0 + 0x7C1) != 0) {
        *(s8 *)(arg0 + 0xDC4) = 4;
    }
    if (*(s8 *)(arg0 + 0xDC4) > 0) {
        p = arg0 + *(s8 *)(arg0 + 0xDC4) * 0x1A0 + 0xB0;
        vcopy(p, arg0 + 0xB40);
        vcopy(p + 0x10, arg0 + 0xB50);
        if (*(s8 *)(arg0 + 0xDC4) == 5) {
            func_08812DB8(arg0, arg0 + 0xAF0);
        } else if (*(s8 *)(arg0 + 0xDC4) == 3) {
            func_08812DB8(arg0, arg0 + 0xAD0);
        } else if (*(s8 *)(arg0 + 0xDC4) == 4) {
            func_08812DB8(arg0, arg0 + 0xAB0);
        }
        *(f32 *)(arg0 + 0xB34) = *(f32 *)(p + 0x80);
        *(f32 *)(arg0 + 0xC) = *(f32 *)(p + 0x88);
        *(u8 *)(arg0 + 0xA88) = 0;
    } else {
        vcopy(arg0 + 0x20, arg0 + 0xB40);
        vcopy(arg0 + 0x30, arg0 + 0xB50);
        func_08812DB8(arg0, arg0 + 0xAB0);
        *(f32 *)(arg0 + 0xB34) = *(f32 *)(arg0 + 0xA0);
        *(f32 *)(arg0 + 0xC) = *(f32 *)(arg0 + 0xA8);
    }
    func_08815004(arg0, *(s8 *)(arg0 + 0xDC4));
}
