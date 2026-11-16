/* unit_088B72CC: 0x088B72CC-0x088B7350 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern s16 D_09A29182;
extern u8 D_09A291B8;
extern int func_088B6A80(s32);
extern void func_088B7958(void);
extern void func_088B7A50(s32);

void func_088B72CC(void) {
    s16 temp_a0;

    if ((D_09A28876 == 0) && (D_09A2886C == 2)) {
        temp_a0 = D_09A29182 - 1;
        D_09A29182 = temp_a0;
        if (temp_a0 < 0) {
            func_088B7A50(4);
            func_088B6A80(0xE);
        } else {
            if (D_09A291B8 != 0) {
                func_088B7958();
            }
        }
    }
}
