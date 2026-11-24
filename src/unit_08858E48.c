/* unit_08858E48: 0x08858E48-0x08858F1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08858E48 */

typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern s32 D_08A62C54;

extern u8 func_0885CD18(s32, u8, u16);
extern void func_088588BC(char *, char *, s16, s16);
extern void func_08858904(char *, char *);

void func_08858E48(char *arg0, char *arg1) {
    char buf[0x88];
    u32 id;
    u32 *p;
    u32 n;

    id = func_0885CD18(D_08A62C54, *(u8 *)(arg1 + 1), *(u16 *)(arg1 + 2));
    p = (u32 *)((char *)(id * 4) + (s32)D_089CC438 + 0x6AD7C);
    n = *p;
    if (n != (u32)-1) {
        *p = n + 1;
        if (*(u32 *)((char *)(id * 4) + (s32)D_089CC438 + 0x6AD7C) % 10 == 0) {
            func_088588BC(D_089CC438, buf, 5, 0);
            *(u32 *)(buf + 0xC) = id;
            *(u32 *)(buf + 0x18) = *(u32 *)((char *)(id * 4) + (s32)D_089CC438 + 0x6AD7C);
            func_08858904(D_089CC438, buf);
        }
    }
}
