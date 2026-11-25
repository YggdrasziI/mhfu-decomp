/* unit_088443EC: 0x088443EC-0x088444A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, s32);
extern s32 func_088DA150(char *, s32);
extern s32 func_088D6A1C(char *, s32);
s32 func_088443EC(char *arg0, char *arg1) {
    char *s1;
    char *v;
    char *p;
    if (*(u8 *)(arg1 + 0x3D0) != 0) {
        return 1;
    }
    s1 = *(char **)(arg0 + 0x530);
    v = func_088DCEBC(D_09A4F0C4, 1);
    p = *(char **)(arg0 + 0x530);
    if ((*(u16 *)(s1 + 0x10F8) | (*(u16 *)(p + 0x62A) | *(u16 *)(s1 + 0x10F6))) != 0
        || (v != 0 && *(u8 *)(v + 0x1E8) == 12 && *(u16 *)(v + 0x10F8) != 0)
        || func_088DA150(p, 6) != 0) {
        return 1;
    }
    return func_088D6A1C(*(char **)(arg0 + 0x530), 0x96);
}
