/* unit_08844304: 0x08844304-0x08844390 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08844304 */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern void func_08832B98(char *, s32);
extern void func_08845384(char *, s32, s32, s32, f32, f32);

void func_08844304(char *arg0) {
    if (*(u8 *)(arg0 + 0x577) != 0) {
        func_08832B98(arg0, 1);
        func_08845384(arg0, 0x190, 0x70, 0xFFFFFF, 75.6f, (f32)(u32)*(u8 *)(arg0 + 0x577));
        func_08832B98(arg0, 0);
    }
}
