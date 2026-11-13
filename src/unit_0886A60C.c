/* unit_0886A60C: 0x0886A60C-0x0886A648 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[44]; } E44;

void func_0886A60C(char *arg0, char *arg1) {
    u16 temp_a1;
    s32 temp_a0_i;

    temp_a1 = *(u16 *)(arg1 + 0x1E6);
    if ((s32) temp_a1 < 2) {
        temp_a0_i = temp_a1;
        *(s8 *) &((E44 *) (arg0 + 0x787))[temp_a0_i] = (s8) (*(s8 *) &((E44 *) (arg0 + 0x787))[temp_a0_i] + 1);
    }
}
