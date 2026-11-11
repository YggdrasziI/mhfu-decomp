/* unit_0887CCAC: 0x0887CCAC-0x0887CD04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;

extern char *D_089CC438;
extern s8 func_0884FCB0(char *);
extern int func_08876574(char *);

void func_0887CCAC(char *arg0) {
    *(s16 *)(arg0 + 0xA4) = 0;
    *(s16 *)(arg0 + 0xA6) = 0;
    *(s16 *)(arg0 + 0xAA) = 0x384;
    *(s16 *)(arg0 + 0xA8) = 0xA;
    *(s8 *)(D_089CC438 + 0x44BC) = func_0884FCB0(D_089CC438);
    func_08876574(arg0);
}
