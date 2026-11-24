/* unit_088574A4: 0x088574A4-0x08857558 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;

s32 func_088574A4(char *arg0, s32 arg1) {
    char *a;
    char *b;
    s32 i;
    s32 j;
    char *d;
    char *c;

    if (arg1 & 1) {
        a = arg0 + 0x6ADD8;
        b = arg0 + 0x6AF1C;
        a++;
        b++;
        for (i = 1; i < 14; i++, a++, b++) {
            if (*a != *b) {
                return 0;
            }
        }
    }
    if (arg1 & 2) {
        c = arg0 + 0x6ADE8;
        d = arg0 + 0x6AF2C;
        for (j = 0; j < 20; j++, c++, d++) {
            if (*c != *d) {
                return 0;
            }
        }
    }
    return 1;
}
