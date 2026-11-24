/* unit_0885128C: 0x0885128C-0x0885148C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_0880BFF0(void *, void *, s32);

void func_0885128C(char *arg0, s32 arg1)
{
    char *base;
    char *q;
    s32 i;
    char *p;
    s32 j;
    s32 lv;
    s32 f;

    base = arg0 + arg1 * 0x1078 + 0x4A58;
    if (*(u16 *)base == 0) {
        return;
    }
    q = base + 0xB90;
    for (i = 0; i < 13; i++, q += 0x40) {
        if (*(s8 *)q == 0) {
            continue;
        }
        if (func_0880BFF0(arg0 + 0x679A0, q + 0x2A, 8) != 0) {
            continue;
        }
        p = arg0 + 0x69BEC;
        j = 0;
        do {
            if (*(s8 *)p != 0 && func_0880BFF0(p + 0x60, q + 0x2A, 0x10) == 0) {
                lv = *(u8 *)(q + 0xB);
                if (lv >= 50 && !((f = *(u16 *)(p + 0x20)) & 0x40)) {
                    *(u16 *)(p + 0x20) = f | 0x80;
                    *(u16 *)(p + 0x20) &= 0xFFD5;
                    break;
                }
                if (lv >= 30 && !((f = *(u16 *)(p + 0x20)) & 0x10)) {
                    if (!(f & 0x80)) {
                        *(u16 *)(p + 0x20) = f | 0x20;
                        *(u16 *)(p + 0x20) &= 0xFFF5;
                    }
                    break;
                }
                if (lv >= 15 && !((f = *(u16 *)(p + 0x20)) & 0x4)) {
                    if (!(f & 0x80) && !(f & 0x20)) {
                        *(u16 *)(p + 0x20) = f | 0x8;
                        *(u16 *)(p + 0x20) &= 0xFFFD;
                    }
                    break;
                }
                if (lv >= 5) {
                    f = *(u16 *)(p + 0x20);
                    if (!(f & 1) && !(f & 0x80) && !(f & 0x20) && !(f & 0x8)) {
                        *(u16 *)(p + 0x20) = f | 0x2;
                    }
                }
                break;
            }
            j++;
            p += 0x70;
        } while (j < 13);
    }
}
