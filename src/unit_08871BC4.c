/* unit_08871BC4: 0x08871BC4-0x08871DCC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09C121B0;
extern u16 D_09BC8400[][3];
extern s32 D_089ABD18[][2];

extern char *func_08869774(char *, s32);
extern char *func_09AB2958(char *, char *);
extern void func_09AB35F0(char *);

void func_08871BC4(char *arg0) {
    char *p;
    char *obj;
    s32 count;
    s32 prev5F4;
    s32 prev1E8;
    s32 prev274;
    s32 x;

    p = func_08869774(arg0, 1);
    prev274 = 0;
    prev1E8 = 0;
    prev5F4 = 0;
    count = 0;
    if (p != 0) {
        for (;;) {
            if (*(s16 *)p < 0) {
                break;
            }
            obj = func_09AB2958(D_09C121B0, p);
            if (obj != 0 && *(s8 *)(p + 0x35) != 0) {
                *(char **)(arg0 + 0x720) = obj;
                if (D_09BC8400[*(u8 *)(obj + 0x1E8)][0] == D_09BC8400[prev1E8][0]) {
                    x = *(s16 *)(obj + 0x5F4);
                    prev5F4 = x - prev5F4;
                    if (prev5F4 < 0) {
                        prev5F4 = -prev5F4;
                    }
                    if (prev5F4 < 200) {
                        if (prev274 < *(u16 *)(obj + 0x274)) {
                            *(s16 *)(obj + 0x5F4) = x - 200;
                            if (*(s16 *)(obj + 0x5F4) < D_089ABD18[prev1E8][0]) {
                                *(s16 *)(obj + 0x5F4) += 200;
                            }
                        } else if (*(u16 *)(obj + 0x274) < prev274) {
                            *(s16 *)(obj + 0x5F4) = x + 200;
                            if (*(s16 *)(obj + 0x5F4) > D_089ABD18[prev1E8][1]) {
                                *(s16 *)(obj + 0x5F4) -= 200;
                            }
                        } else {
                            *(s16 *)(obj + 0x5F4) = x - 200;
                            if (*(s16 *)(obj + 0x5F4) >= D_089ABD18[prev1E8][0]) {
                                break;
                            }
                            *(s16 *)(obj + 0x5F4) += 200;
                            *(s16 *)(obj + 0x5F4) += 200;
                            if (*(s16 *)(obj + 0x5F4) > D_089ABD18[prev1E8][1]) {
                                *(s16 *)(obj + 0x5F4) -= 200;
                            }
                        }
                    }
                }
            }
            if (count == 0) {
                prev5F4 = *(s16 *)(obj + 0x5F4);
                prev1E8 = *(u8 *)(obj + 0x1E8);
                prev274 = *(u16 *)(obj + 0x274);
                count++;
            }
            p += 0x3C;
        }
    }
    func_09AB35F0(D_09C121B0);
}
