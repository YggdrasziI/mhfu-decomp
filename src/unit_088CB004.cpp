/* unit_088CB004: 0x088CB004-0x088CB32C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CB004 asm piece, 1 function
 * before unit_088CB32C.
 *
 * C++: virtual calls through $t9. Steps the timer state at 0x3A0/0x3A2,
 * walks the entry list returned by func_08869570 (ended by x == -1.0f)
 * and, for each active entry, packs two vectors with VFPU `lv.s`/`sv.q`
 * (notes/COMPILER.md, "VFPU in asm blocks") and passes them to
 * func_088C5764.
 */

typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct Info {
    char pad0[0x26];
    s16 unk26;
} Info;

typedef struct Mgr {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual Info *vfunc_28();
} Mgr;

typedef struct Entry {
    float x;
    float y;
    float z;
    char padC[6];
    u16 unk12;
    u16 unk14;
    char pad16[2];
} Entry;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C();
    virtual void vfunc_20();

    char pad4[0x1BC];
    u16 unk1C0;
    u16 unk1C2;
    char pad1C4[0x1DC];
    s16 unk3A0;
    s16 unk3A2;
} Obj;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C7C;
extern Mgr **D_09A4F060;
extern Entry *func_08869570(char *, s32);
extern void func_088C5764(Mgr **, s32, s32, float *, float *);
extern void func_088CB364(Obj *);

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

void func_088CB004(Obj *arg0) {
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    Entry *e;

    if (arg0->unk3A0 != 0) {
        if (arg0->unk3A0 == 1) {
            if (--arg0->unk3A2 <= 0) {
                arg0->unk3A0 = 2;
                arg0->unk3A2 = 2;
            }
        } else if (arg0->unk3A0 == 2) {
            if (--arg0->unk3A2 <= 0) {
                arg0->unk3A0 = 3;
                arg0->unk3A2 = 0x5A;
            }
        } else {
            if (--arg0->unk3A2 <= 0) {
                arg0->unk3A0 = 0;
                arg0->unk3A2 = 0;
            }
        }
    }

    e = 0;
    if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) != 1) {
        e = func_08869570(D_08A62C7C, *(u16 *)(D_089CC438 + 0x6AF0E));
    }
    if (e != 0) {
        if (e->x != -1.0f) do {
            if (e->unk12 > 0 && e->unk14 == 4 && (*D_09A4F060)->vfunc_28()->unk26 != -1 &&
                (arg0->unk1C0 & 0x7F) == 0) {
                vec_set(a, e->x, e->y + 65.0f, e->z, 0.0f);
                vec_set(b, 64.0f, 64.0f, 64.0f, 0.0f);
                switch (*(u16 *)(D_089CC438 + 0x6AF0E)) {
                case 0x82:
                case 0x103:
                    func_088C5764(D_09A4F060, 4, (*D_09A4F060)->vfunc_28()->unk26, a, b);
                    break;
                default:
                    func_088C5764(D_09A4F060, 5, (*D_09A4F060)->vfunc_28()->unk26, a, b);
                    break;
                }
            }
            e++;
        } while (e->x != -1.0f);
    }
    func_088CB364(arg0);
    arg0->vfunc_20();
    arg0->unk1C0++;
    arg0->unk1C2 += 0x2E;
}

}
