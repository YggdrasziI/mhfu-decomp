/* unit_0886A648: 0x0886A648-0x0886A73C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A648 */
#pragma optimize_for_size off
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern char *D_09C121B0;
extern s32 D_09A4F0D0;
extern void func_09AB46A8(char *, u8);
extern void func_088DE3D4(s32, u8);
extern void func_09AB2B40(char *, u8);

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_0886A648(char *arg0) {
    s32 i;
    u8 a;
    u8 b;

    for (i = 0; i < 2; i++) {
        if (get_entry(D_09C121B0, i) == 0) {
            s8 n = *(s8 *)(arg0 + i * 0x2C + 0x786);
            if (n > 0 && *(s8 *)(arg0 + i * 0x2C + 0x787) < n) {
                char *q = arg0 + i * 0x2C + *(s8 *)(arg0 + i * 0x2C + 0x787);
                if (*(u8 *)(q + 0x78D) == 0) {
                    a = *(u8 *)(q + 0x77C);
                    b = *(u8 *)(q + 0x77B);
                    func_09AB46A8(D_09C121B0, b);
                    func_088DE3D4(D_09A4F0D0, b);
                    func_09AB2B40(D_09C121B0, a);
                    *(u8 *)(arg0 + i * 0x2C + *(s8 *)(arg0 + i * 0x2C + 0x787) + 0x78D) = 1;
                }
            }
        }
    }
}
