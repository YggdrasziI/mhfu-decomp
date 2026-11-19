/* unit_088B1BF8: 0x088B1BF8-0x088B1C28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1BC4 and unit_088B1C28.
 *
 * Sets D_09A28870 to 1 when D_09A28878 is non-zero, 0 otherwise, then
 * calls func_088B7078(arg0, 0, 0).
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A28878;
extern s32 D_09A28870;

extern void func_088B7078(char *, s32, s32);

void func_088B1BF8(char *arg0) {
    if (D_09A28878 == 0) {
        D_09A28870 = 0;
    } else {
        D_09A28870 = 1;
    }
    func_088B7078(arg0, 0, 0);
}
