/* unit_088B1708: 0x088B1708-0x088B1888 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1668 and unit_088B1888.
 *
 * Depending on the state D_09A2886C: event 0x8031 in state 5, event 0x8021
 * in states 0, 1, 3 and 4. Otherwise, when D_09A28876 is set, adds arg0 to
 * D_09A2887C if missing (func_088B33BC / func_088B3328), stores
 * func_088B32B8() in D_09A299A8, calls func_088B21D0, func_088B6A80(3) and
 * sends event 0. When it is clear: event 0x8007 when func_088AFB48 accepts
 * D_09A28B98, else stores arg0 in D_09A28878 and registers func_088B1A18 as
 * handler 10 (event 0x8005 on failure). Returns 0.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern u8 D_09A28878;
extern char D_09A2887C[];
extern char D_09A28B98[];
extern u8 D_09A299A8;

extern void func_088B1A18(void);
extern void func_088B6A08(s32, s32, s32);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern s32 func_088B6A80(s32);
extern u16 func_088B33BC(char *, u8);
extern void func_088B3328(char *, u8);
extern u8 func_088B32B8(void);
extern void func_088B21D0(Id *, u8);
extern s32 func_088AFB48(char *);

s32 func_088B1708(u8 arg0, s32 arg1, s32 arg2) {
    Id id;

    switch (D_09A2886C) {
    case 5:
        func_088B6A08(0x8031, arg1, arg2);
        return 0;
    case 0:
    case 1:
    case 3:
    case 4:
        func_088B6A08(0x8021, arg1, arg2);
        return 0;
    }
    if (D_09A28876) {
        if (func_088B33BC(D_09A2887C, arg0) == 0) {
            func_088B3328(D_09A2887C, arg0);
        }
        D_09A299A8 = func_088B32B8();
        func_088B21D0(&id, D_09A299A8);
        func_088B6A80(3);
        func_088B6A08(0, arg1, arg2);
        return 0;
    }
    if (func_088AFB48(D_09A28B98)) {
        func_088B6A08(0x8007, arg1, arg2);
        return 0;
    }
    D_09A28878 = arg0;
    if (!func_088B6F64(10, func_088B1A18, arg1, arg2)) {
        return 0;
    }
    func_088B6A08(0x8005, arg1, arg2);
    return 0;
}
