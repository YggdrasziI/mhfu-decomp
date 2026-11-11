/* unit_088FC5F8: 0x088FC5F8-0x088FC62C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern int func_08812264(s32, u8);
extern int func_08898748(s32, s32);

void func_088FC5F8(char *arg0) {
    func_08812264(D_089CBBE0, *(u8 *)(arg0 + 0xC));
    func_08898748(D_09A0B540, 0xD);
}
