/* unit_08826EF4: 0x08826EF4-0x08826F80 (ULES01213)
 *
 * Bounds (hypothesis): 1 flag test on a looked-up record, between unrelated code.
 */

typedef unsigned char u8;

extern char *D_089CC438;
extern char *D_08A62C54;
extern char *func_0885CA50(char *, char *);

int func_08826EF4(char *arg0, char *arg1, char *arg2) {
    char *s = D_089CC438 + 0x4A0;
    char *e = func_0885CA50(D_08A62C54, arg2);
    u8 f;

    if (*(u8 *)(s + 0x13) == 0) {
        f = 1;
    } else {
        f = 2;
    }
    if (*(u8 *)(arg1 + 0x4E9) == 5) {
        f |= 4;
    } else {
        f |= 8;
    }
    if ((f & *(u8 *)(e + 4)) == f) {
        return 1;
    }
    return 0;
}
