/* unit_088AE2C0: 0x088AE2C0-0x088AE354 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u32 D_09A1FE04;
extern char D_09A1FE08;
extern int func_0880C464(char *, s32, s32);
extern int func_088B0604(char *, u32 *);

void func_088AE2C0(char *arg0) {
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 0xC) - 1;
    *(s32 *)(arg0 + 0xC) = temp_v1;
    if (temp_v1 < 0) {
        *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
        func_0880C464(&D_09A1FE08, 0, 0x90);
        D_09A1FE04 = 0;
        func_088B0604(&D_09A1FE08, &D_09A1FE04);
        if ((u32) D_09A1FE04 >= 4U) {
            *(u8 *)(arg0 + 0x21) = 3;
            *(u8 *)(arg0 + 0x22) = 0U;
            *(u16 *)(arg0 + 0x26) = 0x8052;
        }
    }
}
