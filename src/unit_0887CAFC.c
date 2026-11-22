/* unit_0887CAFC: 0x0887CAFC-0x0887CBAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_08930BDC;
extern char *D_08A62C7C;
extern char *D_089CC438;

extern s32 func_0886D644(char *, s16);
extern u16 func_08850520(char *, u8);
extern u16 func_08850338(char *, u8, char *);

s32 func_0887CAFC(char *unused) {
    s32 i;
    char *p;
    char tmp;
    s16 n;

    i = 0;
    p = &D_08930BDC;
    do {
        if ((u8)func_0886D644(D_08A62C7C, *(u8 *)(p + 3))) {
            if (func_08850520(D_089CC438, *(u8 *)(p + 3)) == 0) {
                return 0;
            }
            n = func_08850338(D_089CC438, *(u8 *)(p + 3), &tmp);
            if (*(s16 *)(p + 8) < n) {
                return 0;
            }
        }
        i++;
        p += 0xE;
    } while (i < 0x3E);
    return 1;
}
