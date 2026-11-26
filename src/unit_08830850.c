/* unit_08830850: 0x08830850-0x0883095C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08830850 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { char b[36]; } E36;

extern char *D_089CC438;
extern s32 D_089CBBE8;

extern s32 func_088169FC(s32, char *);
extern char *func_08859B44(void *, s32, s32);
extern void memcpy(void *, void *, s32);

u8 func_08830850(char *arg0, char *arg1) {
    s32 n;
    char *buf;
    s32 idx;

    if (*(s8 *)(arg0 + 0x10F8) >= 0x13) {
        return 0xFFU;
    }
    n = func_088169FC(D_089CBBE8, arg1) + 1;
    buf = func_08859B44(arg0 + 0x500, n, 0x10);
    if (buf == 0) {
        return 0xFFU;
    }
    *(u8 *)(D_089CC438 + 0x380) = (u8) ((*(u8 *)(D_089CC438 + 0x380) + 1) & 0x7F);
    idx = (s8) ((s32) (*(s8 *)(arg0 + 0x10F9) + *(s8 *)(arg0 + 0x10F8)) % 20);
    *(u8 *) &((E36 *) (arg0 + 0xE43))[idx] = *(u8 *)(D_089CC438 + 0x380);
    *(u8 *) &((E36 *) (arg0 + 0xE42))[idx] = 0xFE;
    memcpy(buf, arg1, n);
    *(char **) &((E36 *) (arg0 + 0xE48))[idx] = buf;
    *(s8 *)(arg0 + 0x10F8) = (s8) (*(s8 *)(arg0 + 0x10F8) + 1);
    return *(u8 *)(D_089CC438 + 0x380);
}
