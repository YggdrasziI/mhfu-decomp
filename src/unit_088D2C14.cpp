/* unit_088D2C14: 0x088D2C14-0x088D2E04 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088D2C14 asm piece, 1 function between
 * unit_088D2BEC and unit_088D2E04.
 *
 * Clears the four 0x40-byte slots at +0x6F0 and fills the list of up to four
 * 0x12-byte records of D_089B73DC at +0x6D4 (count at +0x6D0) from the table
 * of the kind at +0x4E0, searched by the id at +0x53A.
 *
 * C++. Optimized for speed. The vectors are cleared with a VFPU `asm` block
 * (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    s32 key;
    s16 *val;
} Pair;

typedef struct Obj {
    char pad0[0x6D0];
    s32 unk6D0;
    char *unk6D4[4];
} Obj;

extern "C" {

extern char *D_089CC438;
extern Pair *D_089B70AC[];
extern Pair *D_089B70B4[];
extern char D_089B73DC[];

extern s32 func_08851C3C(char *, s32, s32);

static inline void vec_set(float *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

void func_088D2C14(char *arg0) {
    s16 i;
    s16 j;
    s32 id;
    s16 *p;
    Pair *tbl;
    s32 v;

    *(s32 *)(arg0 + 0x410) &= ~0x200;
    *(s32 *)(arg0 + 0x6D0) = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            vec_set((float *)(arg0 + i * 0x40 + j * 0x10 + 0x700), 0.0f, 0.0f, 0.0f, 0.0f);
        }
        *(u8 *)(arg0 + i * 0x40 + 0x6F0) = 0;
        *(u8 *)(arg0 + i * 0x40 + 0x6F1) = 0;
        *(u8 *)(arg0 + i * 0x40 + 0x6F2) = 0;
        *(u8 *)(arg0 + i * 0x40 + 0x6F3) = 0;
    }
    if (*(u32 *)(arg0 + 0xB34) <= 4) {
        return;
    }
    id = *(u16 *)(arg0 + 0x53A);
    p = 0;
    if ((u8) func_08851C3C(D_089CC438, *(u16 *)(arg0 + 0x1E6), 2) == 1) {
        tbl = D_089B70B4[*(u8 *)(arg0 + 0x4E0)];
    } else {
        tbl = D_089B70AC[*(u8 *)(arg0 + 0x4E0)];
    }
    for (; tbl->key != -1; tbl++) {
        if (tbl->key == (u16) id) {
            p = tbl->val;
            break;
        }
    }
    if (p != 0) {
        for (i = 0; i < 4; i++) {
            v = *p;
            if (v == -1) {
                break;
            }
            ((Obj *) arg0)->unk6D4[i] = D_089B73DC + (s16) v * 0x12;
            (*(s32 *)(arg0 + 0x6D0))++;
            p++;
        }
        if (*(s32 *)(arg0 + 0x6D0) != 0) {
            *(s32 *)(arg0 + 0x410) |= 0x200;
        }
    }
}

}
