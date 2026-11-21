/* unit_088B2424: 0x088B2424-0x088B24E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B23E8 and unit_088B24E4.
 *
 * In state 2, reads the sender address and a 16-bit value of the current
 * message; when func_088B7A10 and func_088B7A38 reject them and
 * D_09A28870 is set, replies with func_088B24E4 and calls
 * func_088B6A80(1), else calls func_088B7A50(4) and func_088B6A80(0xE).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} Addr6;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 D_09A2886C;
extern s32 D_09A28870;

extern char *func_088AFE84(void);
extern void func_088AEF64(Addr8 *);
extern char *func_088B03CC(u16 *, char *);
extern s32 func_088B7A10(Addr8 *);
extern s32 func_088B7A38(u16);
extern void func_088B24E4(Id *, Addr8 *);
extern s32 func_088B6A80(s32);
extern void func_088B7A50(s32);

void func_088B2424(void) {
    u16 port;
    Addr8 own;
    Id b;
    char *src;
    s32 bad;

    src = func_088AFE84();
    func_088AEF64(&own);
    func_088B03CC(&port, src);
    if (D_09A2886C == 2) {
        bad = 0;
        if (func_088B7A10(&own) != 0 || func_088B7A38(port) != 0) {
            bad = 1;
        } else if (D_09A28870 == 0) {
            bad = 1;
        }
        if (bad == 0) {
            func_088B24E4(&b, &own);
            func_088B6A80(1);
        } else {
            func_088B7A50(4);
            func_088B6A80(0xE);
        }
    }
}
