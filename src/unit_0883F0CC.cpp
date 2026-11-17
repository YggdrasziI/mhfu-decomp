/* unit_0883F0CC: 0x0883F0CC-0x0883F270 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08931144-0x0893115C) is linked from this unit.
 *
 * C++: virtual calls.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); virtual s32 vfunc_38(); } V38_0;

extern "C" {

extern s32 D_0893B49C[];
extern s32 D_089CBBE0;
extern V38_0 *D_089CC434;
extern char *D_089CC438;
extern s32 D_09A0B540;
extern int func_0881263C(s32, s32, s32, s32, s32, s32);
extern s32 func_08898694(s32, s32, s32);
extern int func_08898748(s32, s32);
extern s32 func_08898898(s32, s32);

s32 func_0883F0CC(char *arg0) {
    s32 id;

    switch (*(s32 *)(arg0 + 0x1198)) {
    case 0:
        switch (*(u16 *)(D_089CC438 + 0x6AF12)) {
        case 0x4E21:
        case 0x4E22:
            id = 0x14FB;
            break;
        case 0x4E23:
        case 0x4E24:
        case 0x4E25:
        case 0x4E26:
            id = 0x14FC;
            break;
        default:
            id = D_0893B49C[*(u8 *)(D_089CC438 + 0x6AF10)];
            break;
        }
        D_089CC434->vfunc_34(id, func_08898694(D_09A0B540, 0x19, D_089CC434->vfunc_18(id)), -1, 0, 0, 1);
        (*(s32 *)(arg0 + 0x1198))++;
        break;
    case 1:
        if ((u8) D_089CC434->vfunc_38() == 0) {
            func_0881263C(D_089CBBE0, 0x2B, func_08898898(D_09A0B540, 0x19), 0, 0, 0);
            (*(s32 *)(arg0 + 0x1198))++;
        }
        break;
    case 2:
        func_08898748(D_09A0B540, 0x19);
        *(s32 *)(arg0 + 0x1198) = 0;
        return 1;
    }
    return 0;
}

}
