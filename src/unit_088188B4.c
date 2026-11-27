/* unit_088188B4: 0x088188B4-0x08818950 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088188B4: draws a Box, then a label from a record. */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box Box;

extern char *D_089CC438;
extern u16 D_089AC860;
extern Box D_0893B068;

extern char *func_0885151C(char *, u16);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0881B408(char *, s32, s32);
extern char *func_0881ED64(char *, char *, u8, s32);
extern s32 func_08830078(char *, char *, s16, s16, s32, char *, s32);

void func_088188B4(char *arg0) {
    char buf[12];

    func_0882F580(arg0, &D_0893B068, func_0885151C(D_089CC438, D_089AC860),
                  *(u8 *)(arg0 + 0x57F), 0xFF, 0);
    func_0881B408(arg0, *(s32 *)(arg0 + 0x530), 1);
    func_08830078(arg0, func_0881ED64(arg0, buf, *(u8 *)(arg0 + 0x57F), *(s32 *)(arg0 + 0x530)),
                  8, 0x28, *(u8 *)(arg0 + 0x582) | 0x100, 0, 1);
}
