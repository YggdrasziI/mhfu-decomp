/* unit_088AF500: 0x088AF500-0x088AF5E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF454 and unit_088AF5E4.
 *
 * Handler of the D_089B28C4 table: builds a 0xC8-byte record as
 * func_088AF454 does; unless func_088AFBC0 returns 4 or more (status
 * 0x8072), runs func_088AF848 on it, and func_088B12E8 when func_088AF7E0
 * returned non-zero and D_09A1FDE0 is not 2. Then answers with request 6
 * and the status (func_088AF5E4, reply dropped).
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
extern u8 func_088AFBC0(void);
extern void func_088B12E8(char *);
extern void func_088AF5E4(Id *, char *, u16);

void func_088AF500(void) {
    char rec[0xC8];
    Id id;
    u16 status;
    s32 n;

    status = 0;
    n = func_088AFE84();
    func_088AFE78();
    memset(rec, 0, sizeof(rec));
    func_088AEF64(rec);
    n = func_088B0324(rec + 8, n);
    func_088B0370(rec + 0x20, n);
    if (func_088AFBC0() >= 4) {
        status = 0x8072;
    }
    if (status == 0) {
        if (func_088AF7E0(rec)) {
            func_088AF848(rec);
            if (D_09A1FDE0 != 2) {
                func_088B12E8(rec);
            }
        } else {
            func_088AF848(rec);
        }
    }
    func_088AF5E4(&id, rec, status);
}
