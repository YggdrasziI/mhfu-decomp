/* unit_088AFC34: 0x088AFC34-0x088AFE78 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFC28 and unit_088AFE78.
 * Its initialised array (0x089B2A24-0x089B2A2A, in .data) is linked from this
 * unit.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad[0x838];
    s32 words[1];
} G1FDE0;

extern u32 D_09A28518;
extern u8 D_09A20618[];
extern G1FDE0 D_09A1FDE0;
extern char D_09A201F0;
extern char D_09A202C0;

extern int func_0880BFF0(void *, void *, int);
extern int memcpy(void *, void *, s32);
extern int func_0880C1A8(void *, void *, s32);
extern s32 func_088AD87C(void *, char *, u16 *, void *, s16);

u8 *func_088AFC34(void *arg0, s32 arg1, s32 *arg2) {
    u16 type;
    char from[0x12];
    s8 any[6] = {-1, -1, -1, -1, -1, -1};
    s32 n;
    u32 len;
    u8 *buf;

    buf = D_09A20618;
    if (D_09A28518 != 0) {
        len = (u16) (((buf[4] << 8) | buf[5]) + 0x14);
        if (D_09A28518 < len) {
            *arg2 = -1;
            return 0;
        }
        D_09A28518 -= len;
        if (D_09A28518 != 0) {
            func_0880C1A8(buf, &D_09A1FDE0.words[len], D_09A28518);
            if (D_09A28518 < ((buf[4] << 8) | buf[5]) + 0x14) {
                *arg2 = -1;
                return 0;
            }
            *arg2 = 0;
            return buf;
        }
    }
    for (;;) {
        n = func_088AD87C(arg0, from, &type, &D_09A1FDE0.words[D_09A28518], 0x7F00 - D_09A28518);
        if (n == 0) {
            *arg2 = 0;
            return 0;
        }
        if (n < 0) {
            *arg2 = n;
            return 0;
        }
        if (func_0880BFF0(&D_09A201F0, from, 6) == 0) {
            continue;
        }
        if (func_0880BFF0(buf + 0xA, any, 6) != 0 &&
            func_0880BFF0(&D_09A201F0, buf + 0xA, 6) != 0) {
            continue;
        }
        if (type != arg1) {
            continue;
        }
        D_09A28518 += n;
        if (D_09A28518 < ((buf[4] << 8) | buf[5]) + 0x14) {
            *arg2 = -1;
            return 0;
        }
        *arg2 = 0;
        memcpy(&D_09A202C0, from, 6);
        return D_09A20618;
    }
}
