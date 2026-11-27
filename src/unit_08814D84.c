/* unit_08814D84: 0x08814D84-0x08814E18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08814D84: copies four 16-bit values from the D_08A62C68 block to
 * +0xA70..+0xA78 of arg0, or clears them (and +0xA74) when
 * func_0884FA5C(D_089CC438, 1) returns 1 or the byte at +0x552 of the
 * record at +0xA84 is set (hypothesis on the purpose). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62C68;
extern s32 D_08A62C6C;
extern u16 D_08A62C78;
extern u16 D_08A62C7A;
extern s32 func_0884FA5C(char *, s32);

void func_08814D84(char *arg0) {
    if ((u8)func_0884FA5C(D_089CC438, 1) == 1 || *(u8 *)(*(char **)(arg0 + 0xA84) + 0x552) != 0) {
        *(u16 *)(arg0 + 0xA74) = 0;
        *(u16 *)(arg0 + 0xA72) = 0;
        *(u16 *)(arg0 + 0xA70) = 0;
        *(u16 *)(arg0 + 0xA78) = 0;
        *(u16 *)(arg0 + 0xA76) = 0;
    } else {
        *(u16 *)(arg0 + 0xA70) = D_08A62C68;
        *(u16 *)(arg0 + 0xA72) = D_08A62C6C;
        *(u16 *)(arg0 + 0xA76) = D_08A62C78;
        *(u16 *)(arg0 + 0xA78) = D_08A62C7A;
    }
}
