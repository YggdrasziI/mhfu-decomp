/* unit_088180CC: 0x088180CC-0x08818264 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088180CC: dispatch on the two state bytes at 0x57E / 0x57F. */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    u16 x;
    s16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AD118;
extern char D_0893AFB4;

extern void func_08818C94(char *, s32);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F9A8(char *, char *, char *, s32, s32, s32);
extern void func_0881A30C(char *);
extern void func_08819E10(char *);
extern char *func_08857C38(char *);
extern void func_08833290(char *, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_088180CC(char *arg0) {
    Box box;

    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        func_08818C94(arg0, 1);
        func_0882FA24(&box, &D_0893AFB4, 0, 0, 0);
        func_0882F9A8(arg0, &D_0893AFB4, 0, *(u8 *)(arg0 + 0x57F), 0xFF, 0);
        break;
    case 1:
        switch (*(u8 *)(arg0 + 0x57F)) {
        case 0:
            func_0881A30C(arg0);
            break;
        case 1:
            func_08819E10(arg0);
            break;
        case 2:
            if (func_08857C38(D_089CC438) != 0) {
                func_08833290(arg0, 0x10, 2, (s32)func_08857C38(D_089CC438), 0);
            } else {
                func_08890E38(D_08A631A8, 0);
                func_08890DE8(D_08A631A8, 0xE, 0xE);
                func_0882DCB0(arg0, 0x10, 2, 0xE0, 0xBE, 0xFF, 0x1D5);
                func_0882DCB0(arg0, 0x10, 0xC0, 0xE0, 0x4D, 0xFF, 0x1D5);
                func_08891474(D_08A631A8, 0x22, 0x5C, func_0885151C(D_089CC438, D_089AD118));
            }
            break;
        }
        break;
    }
}
