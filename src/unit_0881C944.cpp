/* unit_0881C944: 0x0881C944-0x0881CA34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C944 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s32 func_088239FC(char *);
extern s32 func_088268E0(char *, u16 *);
extern s32 func_09A6E5A8(s32);
extern void func_08826688(char *);

s32 func_0881C944(char *arg0) {
    u16 sp1E;

    if ((u8)func_088239FC(arg0) != 1) {
        return -1;
    }
    sp1E = 0xFFFF;
    if ((u8)func_088268E0(arg0, &sp1E) == 0) {
        return -1;
    }
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
        if ((u8)func_09A6E5A8(*(s32 *)(arg0 + 0x530)) == 1) {
            return -1;
        }
    }
    func_08826688(arg0);
    *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) & ~0x10);
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) | 0x200);
    *(s8 *)(arg0 + 0x5FE) = 1;
    *(s16 *)(arg0 + 0x5FC) = 0;
    *(s8 *)(arg0 + 0x5FF) = -1;
    return 0;
}

}
