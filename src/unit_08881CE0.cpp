/* unit_08881CE0: 0x08881CE0-0x08882014 (ULES01213)
 *
 * func_08881CE0: dispatches on the step word at +0x8B98 (0 to 3) of the
 * block at +0x8B2C, then advances it (steps 0 to 2).
 *
 * C++: virtual calls on D_089CC434.
 */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Block {
    u16 ids[4];
    u16 ids2[4];
    u16 id;
    s16 slot;
    s32 count;
    s32 pos[1];
} Block;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); } V34;

extern "C" {

extern s32 D_08A62D84;
extern s32 D_09A4F0D0;
extern V34 *D_089CC434;

extern s32 func_0887FDDC(s32, s32);
extern s32 func_088DE014(s32, u16);
extern s32 func_088DDD9C(s32, s32, s32, s32);
extern s32 func_0887FF74(s32, s32, s32 *, u32);
extern void func_0887FCBC(s32, s32, u16);
extern s32 func_0887FFE0(s32, s32);
extern void func_0887FCEC(s32, s32, u16);
extern s32 func_0887FDC4(s32, s32);
extern void func_0887FCD4(s32, s32, u16);
extern void func_08881824(char *);

void func_08881CE0(char *arg0) {
    Block *base;
    s32 i;
    s32 pos;
    s32 size;
    s32 v;

    base = (Block *)(arg0 + 0xB34 + 0x7FF8);
    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        pos = func_0887FDDC(D_08A62D84, base->slot);
        for (i = 0; i < base->count; i++) {
            v = func_088DE014(D_09A4F0D0, base->ids[i]);
            if (v == -1) {
                D_089CC434->vfunc_34(base->ids[i], pos, -1, 0, 0, 1);
                base->pos[i] = pos;
                pos += D_089CC434->vfunc_18(base->ids[i]);
            } else {
                base->pos[i] = pos;
                pos += func_088DDD9C(D_09A4F0D0, pos, v, -1);
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 1:
        func_0887FF74(D_08A62D84, base->slot, base->pos, base->count);
        func_0887FCBC(D_08A62D84, base->slot, base->ids[0]);
        pos = base->pos[0];
        for (i = 0; i < base->count; i++) {
            size = func_0887FFE0(D_08A62D84, base->pos[i]);
            v = func_088DE014(D_09A4F0D0, base->ids2[i]);
            if (v == -1) {
                D_089CC434->vfunc_34(base->ids2[i], pos, size, 0, 0, 1);
                pos += size;
            } else {
                pos += func_088DDD9C(D_09A4F0D0, pos, v, -1);
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 2:
        func_0887FCEC(D_08A62D84, base->slot, base->ids2[0]);
        v = func_088DE014(D_09A4F0D0, base->id);
        if (v == -1) {
            D_089CC434->vfunc_34(base->id, func_0887FDC4(D_08A62D84, base->slot), -1, 0, 0, 1);
        } else {
            func_088DDD9C(D_09A4F0D0, func_0887FDC4(D_08A62D84, base->slot), v, -1);
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 3:
        func_0887FCD4(D_08A62D84, base->slot, base->id);
        func_08881824(arg0);
        break;
    }
}

}
