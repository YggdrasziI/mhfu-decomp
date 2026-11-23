/* unit_08868498: 0x08868498-0x08868678 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_08859C40(void *, s32);
extern void memset(void *, s32, s32);

static inline char *func_A(char *p, u8 i)
{
    if (i == 0) {
        return p + 0x50;
    }
    return p + 0x830 + (i - 1) * 0x20;
}

static inline char *func_B(char *p, u8 i)
{
    if (i == 0) {
        return p + 0x80;
    }
    return p + 0x8D0 + (i - 1) * 0x140;
}

static inline char *func_C(char *p, u8 i)
{
    if (i == 0) {
        return p + 0x70;
    }
    return p + 0xF10 + (i - 1) * 0x10;
}

void func_08868498(char *a0, char *a1)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        u8 k = i;
        if (*(s32 *)(func_A(a1, k) + 0x8) != 0) {
            func_08859C40(a0 + 0x80000, *(s32 *)(func_A(a1, k) + 0x8));
        }
        memset(func_A(a1, k), 0, 0x20);
        if (*(s32 *)(func_B(a1, k) + 0x110) != 0) {
            func_08859C40(a0 + 0x80000, *(s32 *)(func_B(a1, k) + 0x110));
        }
        memset(func_B(a1, k), 0, 0x140);
        if (*(s32 *)(func_C(a1, k) + 0x4) != 0) {
            func_08859C40(a0 + 0x80000, *(s32 *)(func_C(a1, k) + 0x4));
        }
        memset(func_C(a1, k), 0, 0x10);
    }
}
