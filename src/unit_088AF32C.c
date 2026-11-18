/* unit_088AF32C: 0x088AF32C-0x088AF364 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF25C and unit_088AF364.
 *
 * Handler of the D_089B28C4 table: request 4 (func_088AF364) for the
 * 8-byte key read by func_088AEF64, reply dropped.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(char *);
extern void func_088AF364(Id *, char *);

void func_088AF32C(void) {
    char key[8];
    Id id;

    func_0880C464(key, 0, sizeof(key));
    func_088AEF64(key);
    func_088AF364(&id, key);
}
