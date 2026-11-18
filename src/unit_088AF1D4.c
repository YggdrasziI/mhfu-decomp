/* unit_088AF1D4: 0x088AF1D4-0x088AF25C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF110 and unit_088AF25C.
 *
 * Handler of the D_089B28C4 table: reads the 8-byte key (func_088AEF64)
 * and, when the list at D_09A1FE08 is not empty and func_088AEDA0 returns
 * 0 for it, either runs func_088AFAD0 on it (func_088AF7E0 returns 0) or
 * request 3 for it (func_088AF25C, reply dropped).
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 D_09A1FE04;
extern char D_09A1FE08[];

extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(char *);
extern s32 func_088AEDA0(char *, char *);
extern s32 func_088AF7E0(char *);
extern void func_088AFAD0(char *);
extern void func_088AF25C(Id *, char *);

void func_088AF1D4(void) {
    char key[8];
    Id id;
    s32 lost;

    func_0880C464(key, 0, sizeof(key));
    func_088AEF64(key);
    lost = D_09A1FE04 != 0 && func_088AEDA0(key, D_09A1FE08) == 0;
    if (lost) {
        if (func_088AF7E0(key) == 0) {
            func_088AFAD0(key);
        } else {
            func_088AF25C(&id, key);
        }
    }
}
