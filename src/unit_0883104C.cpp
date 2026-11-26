/* unit_0883104C: 0x0883104C-0x08831188 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_0883104C: 0x0883104C-0x08831188 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual calls.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); virtual s32 vfunc_38(); } V38_0;

extern "C" {

extern u16 D_0893B208[];
extern V38_0 *D_089CC434;
extern char *D_08A631A0;
extern s32 D_09A0B540;
extern s32 func_08898694(s32, s32, s32);

s32 func_0883104C(char *arg0) {
    u16 id;

    if (*(s32 *)(arg0 + 0x528) & 0x1000) {
        return 1;
    }
    switch (*(s32 *)(arg0 + 0x1198)) {
    case 0:
        id = D_0893B208[*(s32 *)(D_08A631A0 + 0xF7A574)];
        D_089CC434->vfunc_34(id, func_08898694(D_09A0B540, 0xB, D_089CC434->vfunc_18(id)), -1, 0, 0, 1);
        (*(s32 *)(arg0 + 0x1198))++;
        break;
    case 1:
        if ((u8) D_089CC434->vfunc_38() == 0) {
            (*(s32 *)(arg0 + 0x1198))++;
        }
        break;
    case 2:
        *(s32 *)(arg0 + 0x1198) = 0;
        *(s32 *)(arg0 + 0x528) |= 0x1000;
        return 1;
    }
    return 0;
}

}

