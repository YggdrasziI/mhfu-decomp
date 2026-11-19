/* unit_088B13B8: 0x088B13B8-0x088B14C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1350 and unit_088B14C0.
 *
 * When D_09A4403C is clear and func_088AEFE4(0) is non-zero, runs
 * func_088B14C0 and func_088B6A80(0x14). Otherwise, while D_09A28875 is
 * clear: when func_088AEFE4(0) is non-zero, sets D_09A28875 and runs
 * func_088B14C0; else builds a 0xC8-byte record (as func_088AF454) and
 * runs func_088AF7E0 and func_088AF848 on it, then func_088B6A80(7) when
 * func_088AF7E0 returned non-zero.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern u8 D_09A4403C;
extern u8 D_09A28875;

extern s32 func_088AFE84(void);
extern s32 func_088AFE78(void);
extern void func_0880C464(void *, s32, s32);
extern int func_088AEFE4(s8);
extern void func_088AEF64(char *);
extern s32 func_088B0324(char *, s32);
extern void func_088B0370(char *, s32);
extern s32 func_088AF7E0(char *);
extern s32 func_088AF848(char *);
extern void func_088B14C0(Id *);
extern s32 func_088B6A80(s32);

void func_088B13B8(void) {
    char rec[0xC8];
    Id a;
    Id b;
    s32 n;

    n = func_088AFE84();
    func_088AFE78();
    if (D_09A4403C == 0 && func_088AEFE4(0)) {
        func_088B14C0(&a);
        func_088B6A80(0x14);
        return;
    }
    func_0880C464(rec, 0, sizeof(rec));
    if (func_088AEFE4(0) == 0) {
        if (D_09A28875 == 0) {
            func_088AEF64(rec);
            n = func_088B0324(rec + 8, n);
            func_088B0370(rec + 0x20, n);
            if (func_088AF7E0(rec)) {
                func_088AF848(rec);
                func_088B6A80(7);
            } else {
                func_088AF848(rec);
            }
        }
    } else if (D_09A28875 == 0) {
        D_09A28875 = 1;
        func_088B14C0(&b);
    }
}
