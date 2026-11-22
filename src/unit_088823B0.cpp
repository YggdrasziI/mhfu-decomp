/* unit_088823B0: 0x088823B0-0x088825FC (ULES01213)
 *
 * C++: virtual call.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); } V34;

typedef struct Sub { u16 a[4]; u16 b[4]; u16 c[4]; s16 d[4]; char pad20[0xC]; s32 idx; } Sub;

extern "C" {

extern s32 D_08A62D84;
extern V34 *D_089CC434;
extern s32 func_0887FDAC(s32, s32);
extern s32 func_0887FDC4(s32, s32);
extern s32 func_0887FDDC(s32, s32);
extern void func_0887FCBC(s32, s32, u16);
extern void func_0887FCD4(s32, s32, u16);
extern void func_0887FCEC(s32, s32, u16);
extern s32 func_0887FFE0(s32, s32);
extern void func_08881824(char *);

void func_088823B0(char *arg0) {
    Sub *base;
    s32 i;
    s32 v;

    base = (Sub *)(arg0 + 0xB6C + 0x7FF8);
    i = base->idx;
    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        if (base->a[i] != 0xFFFF) {
            D_089CC434->vfunc_34(base->a[i], func_0887FDAC(D_08A62D84, base->d[i]), -1, 0, 0, 1);
        }
        if (base->c[i] != 0xFFFF) {
            D_089CC434->vfunc_34(base->c[i], func_0887FDC4(D_08A62D84, base->d[i]), -1, 0, 0, 1);
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 1:
        if (base->a[i] != 0xFFFF) {
            func_0887FCBC(D_08A62D84, base->d[i], base->a[i]);
        }
        if (base->c[i] != 0xFFFF) {
            func_0887FCD4(D_08A62D84, base->d[i], base->c[i]);
        }
        v = func_0887FFE0(D_08A62D84, func_0887FDAC(D_08A62D84, base->d[i]));
        if (base->b[i] != 0xFFFF) {
            D_089CC434->vfunc_34(base->b[i], func_0887FDDC(D_08A62D84, base->d[i]), v, 0, 0, 1);
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 2:
        if (base->b[i] != 0xFFFF) {
            func_0887FCEC(D_08A62D84, base->d[i], base->b[i]);
        }
        func_08881824(arg0);
        break;
    }
}

}
