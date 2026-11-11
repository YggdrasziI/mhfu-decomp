/* unit_088867F4: 0x088867F4-0x08886834 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088A2204(s32);
extern s32 func_088A2338(s32);

void func_088867F4(s32 arg0, s32 arg1) {
    char *temp_s0;

    temp_s0 = (char *) (arg0 + (arg1 * 0x18));
    func_088A2204(*(s32 *)temp_s0);
    *(s32 *)(temp_s0 + 8) = func_088A2338(*(s32 *)temp_s0);
}
