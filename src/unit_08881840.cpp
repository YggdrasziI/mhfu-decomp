/* unit_08881840: 0x08881840-0x08881970 (ULES01213)
 *
 * func_08881840: unless the 0x40 virtual method of D_089CC434 (argument 2)
 * returns true, dispatches on the state word at +0x8B94 (1, 6); then,
 * unless the 0x38 virtual method returns true, dispatches on it again
 * (2 to 5).
 *
 * C++: two virtual calls returning an s32 tested as u8.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct V40 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); virtual void vfunc_3C(); virtual s32 vfunc_40(s32); } V40;

extern "C" {

extern V40 *D_089CC434;

extern void func_088825FC(char *);
extern void func_08882750(char *);
extern void func_08881A30(char *);
extern void func_08881CE0(char *);
extern void func_08882014(char *);
extern void func_088823B0(char *);

void func_08881840(char *arg0) {
    if ((u8)D_089CC434->vfunc_40(2) == 0) {
        switch (*(s32 *)(arg0 + 0x8B94)) {
        case 1:
            func_088825FC(arg0);
            break;
        case 6:
            func_08882750(arg0);
            break;
        }
    }
    if ((u8)D_089CC434->vfunc_38() == 0) {
        switch (*(s32 *)(arg0 + 0x8B94)) {
        case 2:
            func_08881A30(arg0);
            break;
        case 3:
            func_08881CE0(arg0);
            break;
        case 4:
            func_08882014(arg0);
            break;
        case 5:
            func_088823B0(arg0);
            break;
        case 0:
            break;
        }
    }
}

}
