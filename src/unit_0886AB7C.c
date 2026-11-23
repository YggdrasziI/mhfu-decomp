/* unit_0886AB7C: 0x0886AB7C-0x0886AD0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *func_0886DD3C(char *, char *);
extern void func_0886AEEC(char *, char *);
extern void func_0886BA50(char *, char *);
extern void func_0886BD84(char *, u16);
extern s32 func_0886D644(char *, u16);
extern void func_0886AF2C(char *, u16);
extern void func_08870A2C(char *, char *, char *);

void func_0886AB7C(char *arg0, char *arg1) {
    char *e;
    u16 *p;
    u16 v;

    if ((e = func_0886DD3C(arg0, arg1)) != 0) {
        if (*(s16 *)(e + 0x2E) & 5) {
            func_0886AEEC(arg0, arg1);
            return;
        }
        *(s8 *)(e + 4) = *(s8 *)(e + 4) - 1;
        func_0886BA50(arg0, arg1);
        func_0886BD84(arg0, *(u8 *)(arg1 + 0x1E8));
        ((u16 *)(arg0 + 0x29C))[*(u8 *)(arg1 + 0x1E8)] += 1;
        p = &((u16 *)(arg0 + 0x29C))[*(u8 *)(arg1 + 0x1E8)];
        if (*p > 9999) {
            *p = 9999;
        }
        if ((u8)func_0886D644(arg0, *(u8 *)(arg1 + 0x1E8)) == 1) {
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
        if (*(s8 *)(e + 4) > 0) {
            *(s16 *)(e + 0x2E) = 4;
        } else {
            *(s8 *)(e + 0x34) = -1;
            *(s16 *)(e + 0x2E) = 1;
        }
        func_0886AEEC(arg0, arg1);
        func_0886AF2C(arg0, *(u8 *)(arg1 + 0x1E8));
        if (*(u8 *)(arg1 + 0x6DB) != 0) {
            func_08870A2C(arg0, e, arg1);
        }
    }
}
