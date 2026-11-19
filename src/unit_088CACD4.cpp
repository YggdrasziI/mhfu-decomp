/* unit_088CACD4: 0x088CACD4-0x088CAF4C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CACD4 asm piece, 2 functions
 * between unit_088CACCC and unit_088CAF4C.
 *
 * C++: virtual call. func_088CACD4 wraps a draw (vtable offset 0x9C and
 * func_088CBD20) in fixed GE commands when the flag at 0x3D4 is set;
 * func_088CAEC8 reads a kind (1 or 2) and the parts that follow it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98();
    virtual void vfunc_9C();

    char pad4[0x32C];
    u8 unk330;
    char pad331[0xA3];
    u8 unk3D4;
} Obj;

extern "C" {

extern s32 *D_089CC000;
extern s32 D_089CBFFC;
extern void func_0884C7C0(s32, s32);
extern void func_088CBD20(Obj *);
extern u16 *func_088CC128(Obj *, u16 *);
extern u16 *func_088CC190(Obj *, u16 *);
extern void func_088CC24C(Obj *, u16 *);

void func_088CACD4(Obj *arg0) {
    if (arg0->unk3D4 == 0) {
        return;
    }
    *D_089CC000 = 0x20000001;
    D_089CC000++;
    func_0884C7C0(D_089CBFFC, 0);
    *D_089CC000 = 0x22000000;
    D_089CC000++;
    *D_089CC000 = 0x17000000;
    D_089CC000++;
    *D_089CC000 = 0x21000001;
    D_089CC000++;
    *D_089CC000 = 0xDF000032;
    D_089CC000++;
    *D_089CC000 = 0x23000000;
    D_089CC000++;
    *D_089CC000 = 0xDE000000;
    D_089CC000++;
    *D_089CC000 = 0x1E000000;
    D_089CC000++;
    *D_089CC000 = 0x50000001;
    D_089CC000++;
    arg0->vfunc_9C();
    func_088CBD20(arg0);
    *D_089CC000 = 0xDE000005;
    D_089CC000++;
    *D_089CC000 = 0x23000001;
    D_089CC000++;
    *D_089CC000 = 0x22000001;
    D_089CC000++;
    *D_089CC000 = 0x20000000;
    D_089CC000++;
    arg0->unk3D4 = 0;
}

void func_088CAEC8(Obj *arg0, u16 *arg1) {
    u16 *p;

    arg0->unk330 = *arg1;
    switch (arg0->unk330) {
    case 1:
        func_088CC190(arg0, func_088CC128(arg0, arg1 + 1));
        break;
    case 2:
        p = func_088CC128(arg0, arg1 + 1);
        p = func_088CC190(arg0, p);
        func_088CC24C(arg0, p);
        break;
    default:
        arg0->unk330 = 0;
        break;
    }
}

}
