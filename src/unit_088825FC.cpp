/* unit_088825FC: 0x088825FC-0x08882750 (ULES01213)
 *
 * func_088825FC: two-step state at +0x8B98 on the record at +0x8B2C
 * (u16 id, s16 index, u8 flag).
 *
 * C++: virtual calls (vtable slots 0x18, 0x34) on the object at D_089CC434.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, u8, s32, s32); } V34;

typedef struct Rec {
    u16 id;
    s16 index;
    u8 flag;
} Rec;

extern "C" {

extern V34 *D_089CC434;
extern s32 D_09A4F0D0;
extern s32 D_08A62D94;

extern s32 func_088DE014(s32, u16);
extern s32 func_08886664(s32, s32);
extern void func_088DDD9C(s32, s32, s32, s32);
extern void func_08886638(s32, s32, u16, s32);
extern void func_08881824(char *);

void func_088825FC(char *arg0) {
    Rec *rec = (Rec *)(arg0 + 0x8B2C);
    s32 slot;

    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        if (rec->id != 0xFFFF) {
            slot = func_088DE014(D_09A4F0D0, rec->id);
            if (slot == -1) {
                D_089CC434->vfunc_34(rec->id, func_08886664(D_08A62D94, rec->index), -1, rec->flag, 0, 1);
            } else {
                func_088DDD9C(D_09A4F0D0, func_08886664(D_08A62D94, rec->index), slot, -1);
            }
            *(s32 *)(arg0 + 0x8B98) += 1;
        } else {
            func_08881824(arg0);
        }
        break;
    case 1:
        func_08886638(D_08A62D94, rec->index, rec->id, D_089CC434->vfunc_18(rec->id));
        func_08881824(arg0);
        break;
    }
}

}
