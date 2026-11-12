/* unit_08840BC0: 0x08840BC0-0x08840C24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s16 func_09A6DEC0(char *);
extern s32 func_09A6FA20(char *);

s32 func_08840BC0(char *arg0) {
    char *temp_s0;

    temp_s0 = *(char **)(arg0 + 0x530);
    if (func_09A6DEC0(temp_s0) > 0) {
        return 1;
    }
    if (!(*(u16 *)(temp_s0 + 0x424) & 1)) {
        return (func_09A6FA20(temp_s0) & 0xFF) == 1;
    }
    return 1;
}
