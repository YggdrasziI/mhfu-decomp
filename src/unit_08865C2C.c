/* unit_08865C2C: 0x08865C2C-0x08865C88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef float f32;

typedef struct Ent {
    f32 unk0;
    f32 unk4;
    char pad8[0x10];
    f32 unk18;
    f32 unk1C;
} Ent;

extern Ent D_09CDEF40[];

void func_08865C2C(void *arg0, f32 *out, u16 idx, f32 *base) {
    Ent *e = &D_09CDEF40[idx];
    out[0] = base[0] + e->unk0;
    out[1] = base[1] + (e->unk18 + e->unk1C) / 2.0f;
    out[2] = base[2] + e->unk4;
}
