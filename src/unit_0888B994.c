/* unit_0888B994: 0x0888B994-0x0888BB40 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    s32 w0;
    char pad4[4];
    u8 b8;
} Unk;

typedef struct {
    char pad[0x10];
} Entry;

typedef struct {
    char pad[0x100];
    Entry e[0x16];
    u8 b260;
    u8 b261;
} Ctx;

typedef struct {
    char pad[0x40];
} Tbl;

extern Tbl D_08A62DA0[];

extern void func_0888C3AC(char *, Entry *, s32);
extern s32 func_0888BC40(char *, void *, Tbl *, s32, s32);
extern s32 func_0888BB40(char *, Unk *, Entry *, void *, s32);

s32 func_0888B994(char *arg0, Unk *arg1, Ctx *arg2, s32 arg3) {
    char buf[0x14];
    s32 r;
    s32 v;

    func_0888C3AC(arg0, arg2->e, arg2->b260);
    v = func_0888BC40(arg0, buf, &D_08A62DA0[arg1->b8], arg3, arg2->b261);
    if (v == 0) {
        arg1->w0 = 0;
        return 0;
    }
    r = func_0888BB40(arg0, arg1, &arg2->e[arg1->b8], buf, v);
    if (r > 0) {
        if (arg1->b8 < arg2->b260 - 2) {
            v = func_0888BC40(arg0, buf, &D_08A62DA0[arg1->b8 + 1], arg3, arg2->b261);
            if (v != 0) {
                arg1->b8++;
                func_0888BB40(arg0, arg1, &arg2->e[arg1->b8], buf, v);
            }
        }
    } else if (r < 0) {
        if (arg1->b8 > 0) {
            v = func_0888BC40(arg0, buf, &D_08A62DA0[arg1->b8 - 1], arg3, arg2->b261);
            if (v != 0) {
                arg1->b8--;
                func_0888BB40(arg0, arg1, &arg2->e[arg1->b8], buf, v);
            }
        }
    }
    return 1;
}
