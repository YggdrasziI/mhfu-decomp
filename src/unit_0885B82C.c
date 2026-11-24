/* unit_0885B82C: 0x0885B82C-0x0885B9E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B82C */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A0;
extern u8 D_089A5B50[];
extern u8 *D_089A5B34[];

extern char *func_0885B5B8(char *, s32, s32, s32, s32, s32);
extern s8 func_0885BDAC(char *, s32, s32, s32);
extern u16 func_088900C4(char *, s32);
extern u8 func_088D6A1C(char *, s32);
extern s32 func_088D72A4(char *, u16, s16, s32);

s16 func_0885B82C(char *arg0, u8 *arg1, char *arg2, s32 arg3, s32 arg4, s32 arg5) {
    char *e;
    s16 r;
    u8 *p;
    s32 rnd;

    e = func_0885B5B8(arg0, arg3, arg4, 0, arg5 == 1, 0);
    if (e == 0) {
        return -1;
    }
    r = func_0885BDAC(arg0, arg3, arg4, arg5);
    if (func_088900C4(D_08A631A0, 1) % 100 < r) {
        r = *(s16 *)(e + 2);
        if (func_088D6A1C(arg2, 0x9F) == 1) {
            *arg1 = D_089A5B50[*(u8 *)(e + 5)];
        } else {
            p = D_089A5B34[*(u8 *)(e + 5)];
            *arg1 = *p;
            p++;
            rnd = func_088900C4(D_08A631A0, 1) % 100;
        loop:
            if (rnd < *p) {
                goto done;
            }
            (*arg1)++;
            rnd -= *p;
            p++;
            goto loop;
        done:;
        }
    } else {
        *arg1 = 0;
        r = -1;
    }
    if (arg5 == 0) {
        func_088D72A4(arg2, arg3, -1, 0);
        func_088D72A4(arg2, arg4, -1, 0);
    }
    return r;
}
