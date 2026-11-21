/* unit_088FC4F4: 0x088FC4F4-0x088FC5F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Two-step loader: state 0 asks the resource manager for the size of
 * resource 0x4F, allocates it and starts the load; state 1 waits for the
 * load to finish, then registers the buffer. Returns 0 after a step, 1 for any
 * other state.
 *
 * C++: virtual calls.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Mgr {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual s32 vfunc_18(u16);
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34(u16, s32, s32, s32, s32 *, s32);
    virtual s32 vfunc_38();
    virtual s32 vfunc_3C(u16);
};

extern "C" {

extern Mgr *D_089CC434;
extern s32 D_089CBBE0;
extern s32 D_09A0B540;

extern s32 func_08898694(s32, s32, s32);
extern int func_0881263C(s32, s32, s32, s32, s32, s32);

struct Work { s32 unk0; s32 state; s32 buf; u8 unkC; };

s32 func_088FC4F4(Work *arg0) {
    s32 buf;

    switch (arg0->state) {
    case 0:
        buf = func_08898694(D_09A0B540, 0xD, D_089CC434->vfunc_18(0x4F));
        arg0->buf = buf;
        D_089CC434->vfunc_34(0x4F, buf, -1, 0, 0, 1);
        arg0->state++;
        break;
    case 1:
        if (D_089CC434->vfunc_38() == 0) {
            arg0->unkC = func_0881263C(D_089CBBE0, 0xFF, arg0->buf, 0, 0, 0);
            arg0->state++;
            break;
        }
        return 0;
    default:
        return 1;
    }
    return 0;
}

}
