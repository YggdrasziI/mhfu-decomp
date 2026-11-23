/* unit_0886AD58: 0x0886AD58-0x0886AEEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;

extern char *func_0886DD3C(char *, char *);
extern void func_0886AEEC(char *, char *);
extern u8 func_0886D644(char *, u8);
extern void func_0886E5BC(char *, u8);
extern void func_08870A80(char *, char *, char *);
extern void func_0886BA50(char *, char *);

void func_0886AD58(char *arg0, char *arg1) {
    char *e;
    u16 *p;
    u16 v;

    if ((e = func_0886DD3C(arg0, arg1)) == 0) {
        return;
    }
    if (*(s16 *)(e + 0x2E) & 8) {
        func_0886AEEC(arg0, arg1);
        return;
    }
    ((u16 *)(arg0 + 0x350))[*(u8 *)(arg1 + 0x1E8)]++;
    p = &((u16 *)(arg0 + 0x350))[*(u8 *)(arg1 + 0x1E8)];
    if (*p > 9999) {
        *p = 9999;
    }
    if (func_0886D644(arg0, *(u8 *)(arg1 + 0x1E8)) == 1) {
        p = &((u16 *)(arg0 + 0x134))[*(u8 *)(arg1 + 0x1E8)];
        if (*p < *(u16 *)(arg1 + 0x274)) {
            *p = *(u16 *)(arg1 + 0x274);
        }
        p = &((u16 *)(arg0 + 0x1E8))[*(u8 *)(arg1 + 0x1E8)];
        v = *p;
        if (v == 0 || *(u16 *)(arg1 + 0x274) < v) {
            *p = *(u16 *)(arg1 + 0x274);
        }
    }
    func_0886AEEC(arg0, arg1);
    func_0886E5BC(arg0, *(u8 *)(arg1 + 0x1E8));
    if ((*(s16 *)(e + 0x2E) & 5) == 0) {
        func_08870A80(arg0, e, arg1);
        (*(s8 *)(e + 4))--;
        func_0886BA50(arg0, arg1);
        if (*(s8 *)(e + 4) > 0) {
            *(s16 *)(e + 0x2E) = 4;
        } else {
            *(s8 *)(e + 0x34) = -1;
            *(s16 *)(e + 0x2E) = 1;
        }
    }
    *(s16 *)(e + 0x2E) |= 8;
}
