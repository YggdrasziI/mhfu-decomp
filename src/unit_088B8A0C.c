/* unit_088B8A0C: 0x088B8A0C-0x088B8A58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088B89A8(void *);

s32 func_088B8A0C(char *arg0, s32 arg1) {
    if (arg1 >= func_088B89A8(arg0)) {
        return -1;
    }
    return *(s32 *)((char *)((arg0 + (arg1 * 8))) + 8);
}
