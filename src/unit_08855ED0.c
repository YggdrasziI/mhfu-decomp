/* unit_08855ED0: 0x08855ED0-0x08855F98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;

extern char *D_089CC438;
extern u8 *func_08857D6C(char *, s32);
extern void func_08858238(char *, char *, s32);

void func_08855ED0(char *arg0) {
    char *p;
    s32 i;
    char *e;
    u8 *q;

    for (i = 0, e = arg0; i < 5; i++, e += 0x70) {
        p = e + 0x699B8;
        p[1] = i;
        p[2] = 0;
        p[3] = 1;
        p[6] = i;
        q = func_08857D6C(D_089CC438, i);
        p[7] = q[0];
        p[0xA] = ((s8 *)q)[3];
        p[8] = q[1];
        p[0xB] = ((s8 *)q)[4];
        p[9] = q[2];
        p[0xC] = ((s8 *)q)[5];
        *(s16 *)(p + 4) = 0;
        p[0] = 1;
        func_08858238(arg0, p, 1);
    }
}
