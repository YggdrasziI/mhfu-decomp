/* unit_0887CA4C: 0x0887CA4C-0x0887CAFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[3];
    u8 id;
    u8 pad4[2];
    s16 need;
    u8 pad8[6];
} Entry;

extern Entry D_08930BDC[];
extern char *D_08A62C7C;
extern char *D_089CC438;

extern s32 func_0886D644(char *, u16);
extern u16 func_08850520(char *, u8);
extern u16 func_0885028C(char *, u8, u8 *);

s32 func_0887CA4C(char *unused) {
    s32 i;
    Entry *e;
    u8 buf;

    i = 0;
    e = D_08930BDC;
    for (; i < 0x3E; i++, e++) {
        if ((u8)func_0886D644(D_08A62C7C, e->id)) {
            if (func_08850520(D_089CC438, e->id) == 0) {
                return 0;
            }
            if ((s16)func_0885028C(D_089CC438, e->id, &buf) < e->need) {
                return 0;
            }
        }
    }
    return 1;
}
