/* unit_088AF454: 0x088AF454-0x088AF500 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF364 and unit_088AF500.
 *
 * Handler of the D_089B28C4 table: builds a 0xC8-byte record (key read by
 * func_088AEF64, header func_088B0324, body func_088B0370), runs
 * func_088AF7E0, func_088AF848 and func_088AFAD0 on it, and calls
 * func_088B1350 when the first two returned non-zero and D_09A1FDE0 is
 * not 2.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern u8 D_09A1FDE0;

extern s32 func_088AFE84(void);
extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AEF64(char *);
extern s32 func_088B0324(char *, s32);
extern void func_088B0370(char *, s32);
extern s32 func_088AF7E0(char *);
extern s32 func_088AF848(char *);
extern void func_088AFAD0(char *);
extern void func_088B1350(char *);

void func_088AF454(void) {
    char rec[0xC8];
    s32 n;
    s32 a;
    s32 b;

    n = func_088AFE84();
    func_088AFE78();
    memset(rec, 0, sizeof(rec));
    func_088AEF64(rec);
    n = func_088B0324(rec + 8, n);
    func_088B0370(rec + 0x20, n);
    a = func_088AF7E0(rec);
    b = func_088AF848(rec);
    func_088AFAD0(rec);
    if (a && b && D_09A1FDE0 != 2) {
        func_088B1350(rec);
    }
}
