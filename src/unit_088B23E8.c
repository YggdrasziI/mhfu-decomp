/* unit_088B23E8: 0x088B23E8-0x088B2424 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2300 and unit_088B2424.
 *
 * Passes the sender address of the current message to func_088B3594.
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
extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern void func_088B3594(Addr8 *);

void func_088B23E8(void) {
    Addr8 own;

    func_088AFE84();
    func_0880C464(&own, 0, 8);
    func_088AEF64(&own);
    func_088B3594(&own);
}
