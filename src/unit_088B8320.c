/* unit_088B8320: 0x088B8320-0x088B8374 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;

extern int func_088B8164(f32);
extern s32 func_088B81F8(f32);

void func_088B8320(f32 fparg0, char *arg0) {
    *(s32 *)arg0 = (s32) (*(s32 *)arg0 | 0x1100);
    *(s32 *)(arg0 + 0x34) = (s32) (func_088B8164(fparg0) & 0xFF);
    *(s32 *)(arg0 + 0x24) = (s32) (func_088B81F8(fparg0) + 0x40);
}
