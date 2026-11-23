/* unit_088673CC: 0x088673CC-0x088675BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(s32); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual s32 vfunc_34(s32, s32, s32, s32, s32, s32); virtual u8 vfunc_38(); } V38_0;

typedef struct Ent {
    u8 type;
    s32 id;
} Ent;

extern "C" {

extern V38_0 *D_089CC434;

extern s32 func_08866B5C(char *, s32);
extern s32 func_08866BD4(char *, s32);

s32 func_088673CC(char *arg0, s32 arg1, u16 arg2) {
    Ent *ent;
    u8 *st;

    if ((u16)arg1 == 0xFFFF) {
        return 1;
    }
    ent = (Ent *)(arg0 + arg2 * 8 + 0x800A8);
    st = &((u8 *)(arg0 + 0x803D8))[arg2];
    switch (*st) {
    case 0:
        arg1 = D_089CC434->vfunc_18(arg1);
        if (ent->id == -1) {
            switch (ent->type) {
            case 1:
                ((s32 *)(arg0 + 0x80258))[arg2] = func_08866B5C(arg0, arg1);
                break;
            case 2:
                ((s32 *)(arg0 + 0x80258))[arg2] = func_08866BD4(arg0, arg1);
                break;
            }
            ((s32 *)(arg0 + 0x80318))[arg2] = arg1;
        }
        (*st)++;
        break;
    case 1:
        if (D_089CC434->vfunc_34(arg1, ((s32 *)(arg0 + 0x80258))[arg2], -1, 0, 0, 1) == 0) {
            break;
        }
        *st = 2;
    case 2:
        if (D_089CC434->vfunc_38() == 0) {
            *st = 3;
            ((u16 *)(arg0 + 0x80408))[arg2] = arg1;
            return 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}

}
