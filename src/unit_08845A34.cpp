/* unit_08845A34: 0x08845A34-0x08845C68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: `(bool) (x & 1) == 0` keeps the `sltu` before the flag tests.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair { u16 key; s16 val; } Pair;

extern "C" {

extern char *D_08A631A8;
extern char *D_089CC438;
extern u8 D_0899D19B[][24];
extern u16 D_0893B644;
extern s16 D_0893B646;
extern s16 D_0893B648;
extern s16 D_0893B64A;
extern char D_0893B64C[];
extern char D_0893B650[];

extern void func_08845C68(char *);
extern void func_08845EA8(char *);
extern void func_08832B98(char *, s32);
extern s32 func_0882693C(char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern Pair *func_08856884(char *, s32);
extern void func_08891474(char *, s32, s32, char *, ...);
extern char *func_08851528(char *, u16);
extern s32 func_08890E48(char *, char *);

void func_08845A34(char *arg0) {
    char *s1;
    Pair *p;
    u16 key;
    s16 n;
    u16 x;

    if (*(u32 *)(arg0 + 0x1194) & 8) {
        return;
    }
    s1 = *(char **)(arg0 + 0x530);
    if ((bool)(*(u32 *)(s1 + 4) & 1) == 0) {
        return;
    }
    if (*(u8 *)(arg0 + 0x5DB) != 0) {
        return;
    }
    if ((bool)(*(u32 *)(s1 + 0x614) & 1) == 0) {
        func_08845C68(arg0);
    } else {
        func_08845EA8(arg0);
    }
    func_08832B98(arg0, 0);
    if ((u8)func_0882693C(arg0, *(u16 *)(s1 + 0x648)) == 1) {
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_08890E38(D_08A631A8, 0);
        p = func_08856884(D_089CC438, 0);
        n = p[*(u16 *)(s1 + 0x648)].val;
        key = p[*(u16 *)(s1 + 0x648)].key;
        if (n > 0 && D_0899D19B[key][0] > 1) {
            if (n >= D_0899D19B[key][0]) {
                func_08890E38(D_08A631A8, 2);
            }
            func_08891474(D_08A631A8, D_0893B648, D_0893B64A, D_0893B64C, p[*(u16 *)(s1 + 0x648)].val);
        }
        x = D_0893B644 - ((func_08890E48(D_08A631A8, func_08851528(D_089CC438, key)) * 14) >> 2);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (s16)x, D_0893B646, D_0893B650, func_08851528(D_089CC438, key));
    }
    if (*(s8 *)(arg0 + 0x598) > 0) {
        (*(s8 *)(arg0 + 0x598))--;
    }
    if (*(s8 *)(arg0 + 0x59A) > 0) {
        (*(s8 *)(arg0 + 0x59A))--;
    }
}

}
