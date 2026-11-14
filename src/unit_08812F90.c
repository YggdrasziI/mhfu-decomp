/* unit_08812F90: 0x08812F90-0x08813158 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

extern char D_08933A98;
extern s32 func_08865BAC(void *);

void func_08812F90(char *arg0, s32 arg1, char *arg2) {
    if (func_08865BAC(arg2) & 0xFF) {
        *(s8 *)(arg0 + 0xAC0) = 1;
        *(s8 *)(arg0 + 0xAC1) = arg1;
        *(s16 *)(arg0 + 0xAC2) = (s16) ((s16 *)&D_08933A98)[arg1];
        *(f32 *)(arg0 + 0xAB0) = *(f32 *)(arg2 + 0x200);
        *(f32 *)(arg0 + 0xAB4) = *(f32 *)(arg2 + 0x204);
        *(f32 *)(arg0 + 0xAB8) = *(f32 *)(arg2 + 0x208);
        *(f32 *)(arg0 + 0xABC) = *(f32 *)(arg2 + 0x20C);
        *(s8 *)(arg0 + 0xAC4) = 0;
    }
}

void func_08813024(char *arg0, s32 arg1, char *arg2, s8 arg3) {
    if (func_08865BAC(arg2) & 0xFF) {
        *(s8 *)(arg0 + 0xAC0) = 1;
        *(s8 *)(arg0 + 0xAC1) = arg1;
        *(s16 *)(arg0 + 0xAC2) = (s16) ((s16 *)&D_08933A98)[arg1];
        *(f32 *)(arg0 + 0xAB0) = *(f32 *)(arg2 + 0x200);
        *(f32 *)(arg0 + 0xAB4) = *(f32 *)(arg2 + 0x204);
        *(f32 *)(arg0 + 0xAB8) = *(f32 *)(arg2 + 0x208);
        *(f32 *)(arg0 + 0xABC) = *(f32 *)(arg2 + 0x20C);
        *(s8 *)(arg0 + 0xAC4) = arg3;
    }
}

void func_088130C4(char *arg0, s32 arg1, char *arg2) {
    if (func_08865BAC(arg2) & 0xFF) {
        *(s8 *)(arg0 + 0xAE0) = 1;
        *(s8 *)(arg0 + 0xAE1) = arg1;
        *(s16 *)(arg0 + 0xAE2) = (s16) ((s16 *)&D_08933A98)[arg1];
        *(f32 *)(arg0 + 0xAD0) = *(f32 *)(arg2 + 0x200);
        *(f32 *)(arg0 + 0xAD4) = *(f32 *)(arg2 + 0x204);
        *(f32 *)(arg0 + 0xAD8) = *(f32 *)(arg2 + 0x208);
        *(f32 *)(arg0 + 0xADC) = *(f32 *)(arg2 + 0x20C);
        *(s8 *)(arg0 + 0xAE4) = 0;
    }
}
