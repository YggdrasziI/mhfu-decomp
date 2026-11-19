/* unit_088CD964: 0x088CD964-0x088CDA74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function of the former text_088CD964 asm piece
 * (0x088CD964-0x088CDCB0), split around the NonMatching func_088CDA74.
 *
 * Finds the object (of the 20 at D_09C121B0 + 0x1220) whose kind matches
 * a request and passes it on.
 *
 * C++: the flag tests are bool conversions.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_089CBBE4;
extern char *D_09C121B0;
extern void func_08813DAC(char *);
extern void func_08813560(char *, s32, char *, s32);
extern u8 func_0884FC74(char *, u8);

static inline char *get_obj(s32 i) {
    char *base = D_09C121B0;

    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_088CD964(char *arg0, u8 *arg1) {
    s32 i;
    char *p;

    if (arg1[5] == 0) {
        func_08813DAC(D_089CBBE4);
        func_08813560(D_089CBBE4, arg1[4], 0, 0);
        return;
    }
    i = 0;
    do {
        p = get_obj(i);
        if (p != 0 && (bool) (*(u32 *)(p + 4) & 1) != 0 && arg1[5] == func_0884FC74(D_089CC438, *(u8 *)(p + 0x1E8))) {
            func_08813DAC(D_089CBBE4);
            func_08813560(D_089CBBE4, arg1[4], p, 0);
            return;
        }
        i++;
    } while ((u32) i < 20);
}

}
