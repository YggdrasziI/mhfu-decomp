/* unit_088290A4: 0x088290A4-0x088291B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Position from func_0882900C, scaled by a table, or the
 * centre of a D_09CDEF40 entry when its third output is zero.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 x;      /* 0x00 */
    f32 y;      /* 0x04 */
    char pad08[0x8];
    f32 w;      /* 0x10 */
    f32 h;      /* 0x14 */
    char pad18[0x8];
} Ent;

extern char *D_089CC438;
extern f32 D_0893887C[];
extern f32 D_08938880[];
extern Ent D_09CDEF40[];

extern void func_0882900C(char *, f32 *, f32 *, f32 *, u16);

s32 func_088290A4(char *arg0, f32 *x, f32 *y, u16 idx) {
    f32 z;
    s32 k;
    Ent *e;

    func_0882900C(arg0, x, y, &z, idx);
    if (z != 0.0f) {
        k = *(u8 *)(D_089CC438 + 0x6AF10);
        k = k + k;
        *x = 0.0065789474f * *x * D_0893887C[k];
        *y = 0.0065789474f * *y * D_08938880[k];
        return 1;
    }
    e = &D_09CDEF40[idx];
    *x = e->x + 0.5f * e->w;
    *y = e->y + 0.5f * e->h;
    return 0;
}
