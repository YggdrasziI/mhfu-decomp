/* unit_088C3290: 0x088C3290-0x088C32E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern int func_08812264(s32, s32);
extern int func_08898748(s32, s32);

void func_088C3290(char *arg0) {
    func_08898748(D_09A0B540, 1);
    *(s32 *)(arg0 + 0xA2B8) = 0;
    func_08812264(D_089CBBE0, 6);
    *(s32 *)(arg0 + 0xA2C0) = 0;
}
