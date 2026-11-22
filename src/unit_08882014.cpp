/* unit_08882014: 0x08882014-0x088823B0 (ULES01213)
 *
 * func_08882014: three-step state machine on the word at +0x8B98, walking
 * the u16 slot tables of the block at +0x8B64 (count at +0x24).
 *
 * C++: virtual call through D_089CC434 (method at 0x34).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); } V34;

extern "C" {

extern V34 *D_089CC434;
extern char *D_08A62C7C;
extern s32 D_08A62D84;
extern s32 D_09A4F0D0;

extern s32 func_088DE014(s32, s32);
extern void func_088DDD9C(s32, s32, s32, s32);
extern s32 func_0887FDAC(s32, s16);
extern s32 func_0887FDC4(s32, s16);
extern s32 func_0887FDDC(s32, s16);
extern void func_0887FCBC(s32, s16, u16);
extern void func_0887FCD4(s32, s16, u16);
extern void func_0887FCEC(s32, s16, u16);
extern s32 func_0887FFE0(s32, s32);
extern void func_08881824(char *);

void func_08882014(char *arg0) {
    char *blk = arg0 + 0x8B64;
    s32 i = 0;
    u16 *e;
    s32 r;
    s32 v;

    if (*(s32 *)(blk + 0x28) != 0) {
        i = *(s16 *)(D_08A62C7C + 0x5C0);
    }
    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        for (; i < *(s32 *)(blk + 0x24); i++) {
            e = (u16 *)(blk + i * 2);
            if (e[0] != 0xFFFF) {
                r = func_088DE014(D_09A4F0D0, e[0]);
                if (r == -1) {
                    D_089CC434->vfunc_34(e[0], func_0887FDAC(D_08A62D84, e[0xC]), -1, 0, 0, 1);
                } else {
                    func_088DDD9C(D_09A4F0D0, func_0887FDAC(D_08A62D84, e[0xC]), r, -1);
                }
            }
            if (e[8] != 0xFFFF) {
                r = func_088DE014(D_09A4F0D0, e[8]);
                if (r == -1) {
                    D_089CC434->vfunc_34(e[8], func_0887FDC4(D_08A62D84, e[0xC]), -1, 0, 0, 1);
                } else {
                    func_088DDD9C(D_09A4F0D0, func_0887FDC4(D_08A62D84, e[0xC]), r, -1);
                }
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 1:
        for (; i < *(s32 *)(blk + 0x24); i++) {
            e = (u16 *)(blk + i * 2);
            if (e[0] != 0xFFFF) {
                func_0887FCBC(D_08A62D84, e[0xC], e[0]);
            }
            if (e[8] != 0xFFFF) {
                func_0887FCD4(D_08A62D84, e[0xC], e[8]);
            }
            v = func_0887FFE0(D_08A62D84, func_0887FDAC(D_08A62D84, e[0xC]));
            if (e[4] != 0xFFFF) {
                r = func_088DE014(D_09A4F0D0, e[4]);
                if (r == -1) {
                    D_089CC434->vfunc_34(e[4], func_0887FDDC(D_08A62D84, e[0xC]), v, 0, 0, 1);
                } else {
                    func_088DDD9C(D_09A4F0D0, func_0887FDDC(D_08A62D84, e[0xC]), r, v);
                }
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 2:
        for (; i < *(s32 *)(blk + 0x24); i++) {
            e = (u16 *)(blk + i * 2);
            if (e[4] != 0xFFFF) {
                func_0887FCEC(D_08A62D84, e[0xC], e[4]);
            }
        }
        func_08881824(arg0);
        break;
    }
}

}
