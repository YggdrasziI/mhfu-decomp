/* unit_088AF6EC: 0x088AF6EC-0x088AF75C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF5E4 and unit_088AF75C.
 *
 * Handler of the D_089B28C4 table: for the 8-byte key read by
 * func_088AEF64 that func_088AF7E0 does not find, runs func_088AF978 and,
 * when D_09A1FDE0 is not 2, func_088B1584.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A1FDE0;

extern s32 func_088AFE84(void);
extern s32 func_088AFE78(void);
extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(char *);
extern s32 func_088AF7E0(char *);
extern s32 func_088AF978(char *);
extern void func_088B1584(char *);

void func_088AF6EC(void) {
    char key[8];

    func_088AFE84();
    func_088AFE78();
    func_0880C464(key, 0, sizeof(key));
    func_088AEF64(key);
    if (func_088AF7E0(key) == 0) {
        func_088AF978(key);
        if (D_09A1FDE0 != 2) {
            func_088B1584(key);
        }
    }
}
