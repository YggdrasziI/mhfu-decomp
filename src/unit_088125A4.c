/* unit_088125A4: 0x088125A4-0x08812610 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Copies one 24-byte record out of a table if its byte 1 is set.
 * Field layout from the loads and stores only (hypothesis).
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    Vec4 v;
    f32 f14;
} Rec;

s32 func_088125A4(Rec *tbl, u8 idx, Rec *out) {
    Rec *e = (Rec *)((char *)(idx * sizeof(Rec)) + (s32)tbl);

    if (e->b1 != 0) {
        out->b0 = e->b0;
        out->b1 = e->b1;
        out->h2 = e->h2;
        out->v = e->v;
        out->f14 = e->f14;
        return 1;
    }
    return 0;
}
