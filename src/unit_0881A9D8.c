/* unit_0881A9D8: 0x0881A9D8-0x0881AAA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881A9D8: builds a string of star characters (UTF-8 U+2605). */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern u16 D_089AC57A;
extern char D_08938478;
extern char *D_08A631A8;

extern char *func_088298E4(s32);
extern char *func_0885151C(char *, u16);
extern int func_0880EB4C(char *, char *);
extern int func_0889134C(char *, char *, ...);

void func_0881A9D8(s32 arg0, s32 n) {
    char buf[64];
    char *p;
    unsigned int v;

    buf[0] = 0;
    p = buf;
    v = *(u16 *)(func_088298E4(arg0) + 0x18);
    if ((v < 10000 || v > 11999) && n >= 9) {
        func_0880EB4C(p, func_0885151C(D_089CC438, D_089AC57A));
        p++;
        n -= 8;
    }
    while (n > 0) {
        p[0] = 0xE2;
        p[1] = 0x98;
        p[2] = 0x85;
        n--;
        p += 3;
    }
    *p = 0;
    func_0889134C(D_08A631A8, &D_08938478, buf);
}
