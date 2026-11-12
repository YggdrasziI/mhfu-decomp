/* unit_088493A4: 0x088493A4-0x08849404 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern void func_0885683C(void *);

s32 func_088493A4(char *arg0, u16 arg1) {
    if (!(*(u8 *)(D_089CC438 + 0x2A) & 0xF) && (arg1 & 0x6008)) {
        func_0885683C(D_089CC438);
        *(s8 *)(arg0 + 0x11AB) = 0;
        return 8;
    }
    return 0;
}
