/* unit_088B22AC: 0x088B22AC-0x088B2300 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B21D0 and unit_088B2300.
 *
 * Unless func_088B7A10 rejects the sender address of the current message,
 * reads a byte of the message into D_09A299A8 and calls func_088B6B14(3).
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

extern u8 D_09A299A8;

extern char *func_088AFE84(void);
extern void func_088AEF64(Addr8 *);
extern s32 func_088B7A10(Addr8 *);
extern void func_088B03BC(u8 *, char *);
extern void func_088B6B14(s32);

void func_088B22AC(void) {
    Addr8 own;
    char *src;

    src = func_088AFE84();
    func_088AEF64(&own);
    if (func_088B7A10(&own) == 0) {
        func_088B03BC(&D_09A299A8, src);
        func_088B6B14(3);
    }
}
