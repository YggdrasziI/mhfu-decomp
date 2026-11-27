/* unit_08815024: 0x08815024-0x08815108 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_08815024: searches the current block's entry list for an element
 * that func_08815108 rejects (hypothesis on the purpose). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_08815108(char *, u8 *, s32);

s32 func_08815024(char *p) {
    char *b;
    char *e;
    u8 **q;
    s32 n;

    b = *(char **)(p + 0xAAC);
    if (b == 0) {
        *(s32 *)(p + 0xA90) = 0;
        return -1;
    }
    *(s32 *)(p + 0xA90) = *(s32 *)(b + 0x28);
    if (*(u8 *)(p + 0xB14) != 0) {
        return 0;
    }
    e = *(char **)(*(char **)(p + 0xAAC) + 0x1C);
    if (e == 0) {
        return 0;
    }
    e += (*(u16 *)(p + 0xB16) + *(u16 *)(p + 0xB1C) * *(u16 *)(p + 0xB18)) * 8;
    n = *(s32 *)e;
    if (n == 0) {
        return 0;
    }
    q = *(u8 ***)(e + 4);
    for (; n > 0; n--, q++) {
        if ((u8)func_08815108(p, *q, 1) == 0) {
            *(u8 **)(p + 0xA90) = *q;
            return 1;
        }
    }
    return 0;
}
