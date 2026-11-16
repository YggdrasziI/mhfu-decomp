/* unit_088A0AFC: 0x088A0AFC-0x088A0BE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089B2170;

s16 func_088A0AFC(s32 arg0) {
    s32 temp_v1;

    temp_v1 = arg0 % 1024;
    if (temp_v1 < 0x100) {
        return ((s16 *)&D_089B2170)[(temp_v1 % 256)];
    }
    if (temp_v1 < 0x200) {
        return ((s16 *)&D_089B2170)[(0x200 - temp_v1)];
    }
    if (temp_v1 < 0x300) {
        return (s16) -((s16 *)&D_089B2170)[(temp_v1 % 256)];
    }
    if (temp_v1 < 0x400) {
        return (s16) -((s16 *)&D_089B2170)[(0x400 - temp_v1)];
    }
    return 0;
}
