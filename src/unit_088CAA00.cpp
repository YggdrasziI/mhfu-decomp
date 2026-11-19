/* unit_088CAA00: 0x088CAA00-0x088CAB2C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CAA00 asm piece, 1 function
 * between unit_088CA944 and unit_088CAB2C.
 *
 * C++: virtual calls. Resets the matrix at 0x10 to the identity (VFPU
 * `vmidt.q` in an `asm` block, notes/COMPILER.md, "VFPU in asm blocks";
 * the original encodes the transposed name E000, not M000),
 * runs the two optional parts (func_088C7914, func_088C7CDC), then writes
 * three GE commands.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct Parts {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Parts;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual Parts *vfunc_48();

    char pad4[0xC];
    float mtx[16];
} Obj;

extern "C" {

extern char *D_089CC438;
extern s32 *D_089CC000;
extern s32 D_08A62C58;
extern void func_088C7914(Obj *);
extern void func_088C7CDC(Obj *);
extern void func_08860C54(s32);
extern void func_08861184(s32, s32);

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_088CAA00(Obj *arg0) {
    if (*(u16 *)(D_089CC438 + 0x6AF0E) == 0) {
        return;
    }
    if (arg0->vfunc_48() != 0) {
        mtx_identity(arg0->mtx);
        if (arg0->vfunc_48()->unk4 != 0) {
            func_088C7914(arg0);
        }
        if (arg0->vfunc_48()->unk8 != 0) {
            func_088C7CDC(arg0);
        }
    }
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
    *D_089CC000 = 0xDBFF0006;
    D_089CC000++;
    func_08860C54(D_08A62C58);
    func_08861184(D_08A62C58, 1);
}

}
