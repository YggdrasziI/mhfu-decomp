/* unit_08906744: 0x08906744-0x0890682C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions of a Metrowerks object between the VFPU
 * code and the start-up code; func_0890682C (next) is still in assembly.
 */

typedef short s16;
typedef int s32;

typedef struct {
    float a, b, c;
} T;

extern char D_089B9218;
extern float D_089B9220;
extern float D_089B9224;
extern char D_089BAB98;
extern char D_089BAEC8;
extern s32 __ptmf_test(void *);
extern void func_08897298(s32);

char *func_08906744(char *arg0) {
    T t;
    *(char **)arg0 = &D_089BAB98;
    t.a = ((float *)&D_089B9218)[1];
    t.b = D_089B9220;
    t.c = D_089B9224;
    if (__ptmf_test(&t)) {
        *(T *)(arg0 + 4) = t;
    }
    *(char **)arg0 = &D_089BAEC8;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}

char **func_089067D0(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAEC8;
        if (arg0 != 0) {
            *arg0 = &D_089BAB98;
        }
        if (arg1 > 0) {
            func_08897298((s32) arg0);
        }
    }
    return arg0;
}
