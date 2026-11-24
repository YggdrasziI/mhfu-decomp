/* unit_08858904: 0x08858904-0x08858BD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Pushes a 0x88-byte record onto a 10-entry history at 0x67D98 (oldest
 * dropped). Each field is copied by its own structure assignment: the
 * one-float wrapper gives the full-address `lwc1 0(reg)` copy, the s8
 * array wrappers give the compiler's own count-down copy loops (2 bytes,
 * then 1 byte per pass).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct { f32 v; } F;
typedef struct { u8 c[3]; } Rgb;
typedef struct { f32 x, y, z; } Vec;
typedef struct { s8 b[27][2]; } Pairs;
typedef struct { s8 b[43]; } Bytes;

typedef struct {
    F f0;
    s16 h4;
    u16 h6;
    Rgb c8;
    Vec vC;
    Vec v18;
    Pairs p24;
    Bytes b5A;
} Entry;

typedef struct {
    char pad[0x67D98];
    Entry hist[10];
} Work;

extern u8 func_08858BD8(Work *, Entry *);

void func_08858904(Work *arg0, Entry *arg1) {
    u8 i;

    if (*(s32 *)&arg0->hist[0].f0 == *(s32 *)&arg1->f0) {
        if (func_08858BD8(arg0, arg1) == 0) {
            return;
        }
    }
    for (i = 9; i > 0; i--) {
        arg0->hist[i].f0 = arg0->hist[i - 1].f0;
        arg0->hist[i].h4 = arg0->hist[i - 1].h4;
        arg0->hist[i].h6 = arg0->hist[i - 1].h6;
        arg0->hist[i].c8 = arg0->hist[i - 1].c8;
        arg0->hist[i].vC = arg0->hist[i - 1].vC;
        arg0->hist[i].v18 = arg0->hist[i - 1].v18;
        arg0->hist[i].p24 = arg0->hist[i - 1].p24;
        arg0->hist[i].b5A = arg0->hist[i - 1].b5A;
    }
    arg0->hist[0].f0 = arg1->f0;
    arg0->hist[0].h4 = arg1->h4;
    arg0->hist[0].h6 = arg1->h6;
    arg0->hist[0].c8 = arg1->c8;
    arg0->hist[0].vC = arg1->vC;
    arg0->hist[0].v18 = arg1->v18;
    arg0->hist[0].p24 = arg1->p24;
    arg0->hist[0].b5A = arg1->b5A;
}
