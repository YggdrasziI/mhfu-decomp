/* unit_0888C318: 0x0888C318-0x0888C344 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    char pad[0x200];
    float f[1];
} Unk;

float func_0888C318(char *arg0, Unk *arg1, s32 arg2, float arg3) {
    return arg1->f[arg2] * (1.0f - arg3) + arg1->f[arg2 + 1] * arg3;
}
