/* unit_08860848: 0x08860848-0x08860A04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08860848: copies three vectors for an entry, from the live table or
 * from the default tables. */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 a[3]; /* 0x00 */
    f32 b[3]; /* 0x0C */
    f32 c[3]; /* 0x18 */
} Entry; /* size 0x24 */

typedef struct {
    char pad[0x334];
    Entry ent[1]; /* 0x334 */
} Table;

extern char *D_09A4F060;
extern f32 D_089A5B90[];
extern f32 D_089A5B94[];
extern f32 D_089A5B98[];
extern f32 D_089A5BB4[];
extern f32 D_089A5BB8[];
extern f32 D_089A5BBC[];
extern f32 D_089A5BE4[];
extern f32 D_089A5BE8[];
extern f32 D_089A5BEC[];

void func_08860848(char *arg0, f32 *out, s16 idx, u16 mode) {
    Table *p;

    if (*(u16 *)(arg0 + 0x15C) != 0) {
        p = *(Table **)D_09A4F060;
        switch (mode) {
        case 0:
            out[8] = -1.0f * p->ent[idx].a[0];
            out[9] = -1.0f * p->ent[idx].a[1];
            out[10] = -1.0f * p->ent[idx].a[2];
            out[3] = p->ent[idx].c[0];
            out[4] = p->ent[idx].c[1];
            out[5] = p->ent[idx].c[2];
        case 1:
            out[0] = p->ent[idx].b[0];
            out[1] = p->ent[idx].b[1];
            out[2] = p->ent[idx].b[2];
            break;
        }
    } else {
        switch (mode) {
        case 0:
            out[8] = -1.0f * D_089A5B90[idx * 3];
            out[9] = -1.0f * D_089A5B94[idx * 3];
            out[10] = -1.0f * D_089A5B98[idx * 3];
            out[3] = D_089A5BE4[idx * 4];
            out[4] = D_089A5BE8[idx * 4];
            out[5] = D_089A5BEC[idx * 4];
        case 1:
            out[0] = D_089A5BB4[idx * 4];
            out[1] = D_089A5BB8[idx * 4];
            out[2] = D_089A5BBC[idx * 4];
            break;
        }
    }
}
