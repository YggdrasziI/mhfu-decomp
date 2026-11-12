/* unit_0886AEEC: 0x0886AEEC-0x0886AF2C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_08870264(s32, s32);

void func_0886AEEC(s32 arg0, char *arg1) {
    if (func_08870264(arg0, (s32) *(u8 *)(arg1 + 0x1E8)) != 0) {
        *(char **)(arg0 + 0x24) = arg1;
    }
}
