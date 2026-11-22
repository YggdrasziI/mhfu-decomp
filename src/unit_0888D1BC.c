/* unit_0888D1BC: 0x0888D1BC-0x0888D2B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern s32 func_09C3DE10(char *, char *, char *, char *);
extern float func_09C3DA00(char *, char *);

float func_0888D1BC(char *arg0) {
    char buf[0x10];
    char *p = arg0 + 0xA0;

    if (func_09C3DE10(D_09D1A060, p, *(char **)(*(char **)(D_089CBBE4 + 0xA84) + 0x190) + 0x2F40, buf) != 0 &&
        func_09C3DA00(D_09D1A060, p) - func_09C3DA00(D_09D1A060, p + 0x10) > 150.0f) {
        *(float *)(p + 0x38) += 20.0f;
        if (*(float *)(p + 0x38) > 300.0f) {
            *(float *)(p + 0x38) = 300.0f;
        }
        return *(float *)(p + 0x38);
    }
    *(float *)(p + 0x38) -= 20.0f;
    if (*(float *)(p + 0x38) < 0.0f) {
        *(float *)(p + 0x38) = 0.0f;
    }
    return *(float *)(p + 0x38);
}
