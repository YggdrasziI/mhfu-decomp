/* unit_08812A08: 0x08812A08-0x08812B1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The 16-byte local is cleared by a byte loop written in place: the
 * include/unk_msg.h clear() helper schedules the count load one slot earlier.
 */

typedef signed char s8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x;
    f32 y;
} V2;

typedef struct {
    V2 a;
    V2 b;
} V4;

extern V2 D_08933A70;
extern V2 D_08933A78;
extern V2 D_08933A80;
extern V2 D_08933A88;
extern f32 *D_08A62C40;

extern void func_08816264(char *arg0);
extern void func_08814268(char *, V4 *, char *, V4 *);
extern void func_08812B9C(char *);

void func_08812A08(char *arg0) {
    V4 a;
    char b[16];
    V4 c;

    a.a = D_08933A70;
    a.b = D_08933A78;
    {
        char *q = b;
        u32 n = 16;
        if (q != 0) {
            do {
                *q = 0;
                n--;
                q++;
            } while (n != 0);
        }
    }
    c.a = D_08933A80;
    c.b = D_08933A88;
    *D_08A62C40 = 1.0f;
    *(s32 *)(arg0 + 0x0) = 0x41F00000;
    *(s32 *)(arg0 + 0x4) = 0x477DE800;
    *(s32 *)(arg0 + 0xC) = 0x3F5F49F5;
    *(s32 *)(arg0 + 0x8) = 0x3FE1E1E2;
    func_08816264(arg0);
    func_08814268(arg0, &a, b, &c);
    *(s32 *)(arg0 + 0xDC0) = 0;
    *(s8 *)(arg0 + 0xAA9) = 0;
    func_08812B9C(arg0);
    *(s8 *)(arg0 + 0x14) = 3;
    *(s8 *)(arg0 + 0xA80) = 0;
    *(s32 *)(arg0 + 0xA7C) = 0;
}
