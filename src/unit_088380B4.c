/* unit_088380B4: 0x088380B4-0x08838458 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08838004 and text_08838458).
 *
 * .data: the initializers of the two local char[4] arrays (UTF-8 full-width
 * parentheses).
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A62C50;
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_0893B2A0;
extern u16 D_0893B2A2;
extern s16 D_0893B2A4;
extern u8 D_0899D19B[][24];
extern char D_0893B2A8[];
extern char D_0893B2B0[];
extern char D_0893B2D0[];
extern char D_0893B2E8[];
extern char D_0893B300[];
extern char D_0893B310[];

extern s32 func_0885AED0(char *, u16);
extern s32 func_0885C33C(char *, u16);
extern s32 func_0885C3DC(char *, u16);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern void func_08892004(char *, char *, ...);
extern char *func_08851528(char *, u16);

void func_088380B4(char *arg0, s16 x, s16 y, s16 id, s16 max) {
    char open[4] = "\xEF\xBC\x88";
    char close[4] = "\xEF\xBC\x89";
    s16 n;
    s32 m;

    if (id == 0) {
        return;
    }
    n = func_0885AED0(D_08A62C50, id);
    m = func_0885C33C(D_08A62C50, id);
    if (m > 999) {
        m = 999;
    }
    func_0882E2C0(arg0, id, x, y - 1, D_0893B2A0, D_0893B2A2, 1, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08890DFC(D_08A631A8, x + D_0893B2A4, y);
    if (!(max > n + m)) {
        if (n >= D_0899D19B[id][0]) {
            func_08892004(D_08A631A8, D_0893B2A8, func_08851528(D_089CC438, id));
            func_08890DFC(D_08A631A8, x + D_0893B2A4 + 0x70, y);
            if (func_0885C3DC(D_08A62C50, id) == 0) {
                func_08892004(D_08A631A8, D_0893B2B0, n, open, m, close, max);
            } else {
                func_08892004(D_08A631A8, D_0893B2D0, n, open, m, close, max);
            }
        } else {
            func_08892004(D_08A631A8, D_0893B2A8, func_08851528(D_089CC438, id));
            func_08890DFC(D_08A631A8, x + D_0893B2A4 + 0x70, y);
            if (func_0885C3DC(D_08A62C50, id) == 0) {
                func_08892004(D_08A631A8, D_0893B2E8, n, open, m, close, max);
            } else {
                func_08892004(D_08A631A8, D_0893B300, n, open, m, close, max);
            }
        }
    } else {
        func_08892004(D_08A631A8, D_0893B310, func_08851528(D_089CC438, id));
        func_08890DFC(D_08A631A8, x + D_0893B2A4 + 0x70, y);
        func_08892004(D_08A631A8, D_0893B300, n, open, m, close, max);
    }
}
