/* unit_088AB35C: 0x088AB35C-0x088AB490 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088AB490. Its jump table (0x08932010-0x0893203C) is linked from this
 * unit.
 *
 * C++: virtual call.
 */

typedef int s32;
typedef unsigned char u8;
typedef struct V58 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(s32, s32); } V58;

extern "C" {

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09C121B0;
extern V58 *func_088DCEBC(s32, u8);
extern void func_088AB500(u8 *arg0, u8 *arg1, char *arg2);
extern void func_088AB7D8(s32, s32, s32);
extern void func_088AB980(s32, s32, s32);
extern void func_09AB3540(s32, s32, s32);

s32 func_088AB35C(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp1F;
    u8 sp1E;
    V58 *obj;

    if (func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) == 0) {
        return 0;
    }
    func_088AB500(&sp1F, &sp1E, (char *) arg1);
    if (sp1F == 7) {
        func_088AB980(arg2, arg0, arg1);
    } else if ((u8) arg0 != *(u8 *)(D_089CC438 + 0x28)) {
        switch (sp1F) {
        case 1:
        case 2:
        case 3:
        case 4:
            obj = func_088DCEBC(D_09A4F0C4, (u8) arg0);
            if (obj != 0) {
                obj->vfunc_58(arg1, arg0);
            }
            break;
        case 8:
            func_09AB3540(D_09C121B0, arg0, arg1);
            break;
        case 10:
            func_088AB7D8(arg2, arg0, arg1);
            break;
        case 0:
        case 5:
        case 6:
        case 7:
        case 9:
            break;
        }
    }
    return 0;
}

}
