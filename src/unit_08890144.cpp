/* unit_08890144: 0x08890144-0x088901E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_08890144: looks up an entry of the D_089CBA70 table by index; if
 * func_088DE014 finds a slot for it, hands it to func_088DDD9C and writes
 * the data cache back, otherwise forwards it to the 0x34 virtual method of
 * D_089CC434.
 *
 * C++: one virtual call.
 */

typedef int s32;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(s32, s32, s32, s32, s32, s32); } V34;

extern "C" {

extern s32 D_089CBA70[];
extern s32 D_09A4F0D0;
extern V34 *D_089CC434;

extern s32 func_088DE014(s32, s32);
extern void func_088DDD9C(s32, s32, s32, s32);
extern void sceKernelDcacheWritebackAll(void);

void func_08890144(s32 arg0, s32 arg1, s32 arg2) {
    s32 entry;
    s32 slot;

    entry = D_089CBA70[arg2];
    slot = func_088DE014(D_09A4F0D0, arg1);
    if (slot != -1) {
        func_088DDD9C(D_09A4F0D0, entry, slot, -1);
        sceKernelDcacheWritebackAll();
    } else {
        D_089CC434->vfunc_34(arg1, entry, -1, 0, 0, 1);
    }
}

}
