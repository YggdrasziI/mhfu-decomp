/* unit_088B269C: 0x088B269C-0x088B2704 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B25B4 and unit_088B2704.
 *
 * Reads the sender address and a 16-bit value of the current message; when
 * func_088B7A10 and func_088B7A38 both reject them, calls func_088B7A50(4)
 * and func_088B6A80(0xE).
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

extern char *func_088AFE84(void);
extern void func_088AEF64(Addr8 *);
extern char *func_088B03CC(u16 *, char *);
extern s32 func_088B7A10(Addr8 *);
extern s32 func_088B7A38(u16);
extern s32 func_088B6A80(s32);
extern void func_088B7A50(s32);

void func_088B269C(void) {
    u16 port;
    Addr8 own;
    char *src;

    src = func_088AFE84();
    func_088AEF64(&own);
    func_088B03CC(&port, src);
    if (func_088B7A10(&own) == 0 && func_088B7A38(port) == 0) {
        func_088B7A50(4);
        func_088B6A80(0xE);
    }
}
