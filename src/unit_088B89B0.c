/* unit_088B89B0: 0x088B89B0-0x088B8A0C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088B89A8(void *);

char *func_088B89B0(char *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 >= func_088B89A8(arg0)) {
        return 0;
    }
    temp_v0 = *(s32 *)((char *)((arg0 + (arg1 * 8))) + 4);
    if (temp_v0 != 0) {
        return arg0 + temp_v0;
    }
    return 0;
}
