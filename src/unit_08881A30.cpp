/* unit_08881A30: 0x08881A30-0x08881CE0 (ULES01213)
 *
 * func_08881A30: three-step sequence on the sub-state word at +0x8B98,
 * using the u16 ids at +0x8B2C..+0x8B30 and the s16 index at +0x8B32.
 *
 * C++: virtual call 0x34 on D_089CC434.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(s32, s32, s32, s32, s32, s32); } V34;

typedef struct Ids {
    u16 a;
    u16 b;
    u16 c;
    s16 d;
} Ids;

extern "C" {

extern V34 *D_089CC434;
extern s32 D_08A62D84;
extern s32 D_09A4F0D0;

extern s32 func_0887FDAC(s32, s32);
extern s32 func_0887FDC4(s32, s32);
extern s32 func_0887FDDC(s32, s32);
extern s32 func_0887FFE0(s32, s32);
extern void func_0887FCBC(s32, s32, s32);
extern void func_0887FCD4(s32, s32, s32);
extern void func_0887FCEC(s32, s32, s32);
extern s32 func_088DE014(s32, u16);
extern void func_088DDD9C(s32, s32, s32, s32);
extern void func_08881824(char *);

void func_08881A30(char *arg0) {
    Ids *p = (Ids *)(arg0 + 0x8B2C);
    s32 r;
    s32 x;

    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        if (p->a != 0xFFFF) {
            r = func_088DE014(D_09A4F0D0, p->a);
            if (r == -1) {
                D_089CC434->vfunc_34(p->a, func_0887FDAC(D_08A62D84, p->d), -1, 0, 0, 1);
            } else {
                func_088DDD9C(D_09A4F0D0, func_0887FDAC(D_08A62D84, p->d), r, -1);
            }
        }
        if (p->c != 0xFFFF) {
            D_089CC434->vfunc_34(p->c, func_0887FDC4(D_08A62D84, p->d), -1, 0, 0, 1);
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 1:
        if (p->a != 0xFFFF) {
            func_0887FCBC(D_08A62D84, p->d, p->a);
        }
        if (p->c != 0xFFFF) {
            func_0887FCD4(D_08A62D84, p->d, p->c);
        }
        if (p->b != 0xFFFF) {
            x = func_0887FFE0(D_08A62D84, func_0887FDAC(D_08A62D84, p->d));
            r = func_088DE014(D_09A4F0D0, p->b);
            if (r == -1) {
                D_089CC434->vfunc_34(p->b, func_0887FDDC(D_08A62D84, p->d), x, 0, 0, 1);
            } else {
                func_088DDD9C(D_09A4F0D0, func_0887FDDC(D_08A62D84, p->d), r, x);
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 2:
        if (p->b != 0xFFFF) {
            func_0887FCEC(D_08A62D84, p->d, p->b);
        }
        func_08881824(arg0);
        break;
    }
}

}
