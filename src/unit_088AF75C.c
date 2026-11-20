/* unit_088AF75C: 0x088AF75C-0x088AF7E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF6EC and unit_088AF7E0.
 *
 * Handler of the D_089B28C4 table: reads the 8-byte key (func_088AEF64)
 * and a 0xA4-byte body (func_088B0370); for a key that func_088AF7E0 does
 * not find, runs func_088AFA2C and, when D_09A1FDE0 is not 2,
 * func_088B1668 on both.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A1FDE0;

extern s32 func_088AFE84(void);
extern void memset(void *, s32, s32);
extern void func_088AEF64(char *);
extern void func_088B0370(char *, s32);
extern s32 func_088AF7E0(char *);
extern void func_088AFA2C(char *, char *);
extern void func_088B1668(char *, char *);

void func_088AF75C(void) {
    char key[8];
    char body[0xA4];
    s32 n;

    n = func_088AFE84();
    memset(body, 0, sizeof(body));
    func_088AEF64(key);
    func_088B0370(body, n);
    if (func_088AF7E0(key) == 0) {
        func_088AFA2C(key, body);
        if (D_09A1FDE0 != 2) {
            func_088B1668(key, body);
        }
    }
}
