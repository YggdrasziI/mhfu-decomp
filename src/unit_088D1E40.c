/* unit_088D1E40: 0x088D1E40-0x088D2674 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D1DD0 and unit_088D2674.
 *
 * Timed events of an animation, by the id at +0x684: each event tests the
 * frame given as a float (func_08864348 on the sub-object at +0x80, directly
 * or through func_088D2674) and starts an effect.
 *
 * Optimized for speed: the float constants that are not a 16-bit pattern are
 * built with `lui` / `ori` instead of being read from the data.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern char *D_08A631A0;

extern s32 func_08864348(float, char *, s32);
extern s32 func_08864408(float, char *, s32);
extern s32 func_088900C4(char *, s32);
extern void func_088D2674(char *, float, s32, s32);
extern void func_09C6EF18(char *, s32, s32);
extern void func_09C6F068(float, char *, s32, s32, s32, s32);
extern void func_09C91548(char *, s32);

void func_088D1E40(char *arg0) {
    u16 kind;
    float t;

    kind = *(u16 *)(arg0 + 0x684);
    switch (kind) {
    case 2:
        func_088D2674(arg0, 20.0f, 8, 8);
        func_088D2674(arg0, 54.0f, 5, 8);
        func_088D2674(arg0, 88.0f, 8, 8);
        break;
    case 3:
        func_088D2674(arg0, 12.0f, 8, 0);
        func_088D2674(arg0, 16.0f, 5, 0);
        func_088D2674(arg0, 32.0f, 8, 0);
        func_088D2674(arg0, 56.0f, 5, 0);
        break;
    case 4:
        func_088D2674(arg0, 12.0f, 5, 1);
        func_088D2674(arg0, 30.0f, 8, 1);
        func_088D2674(arg0, 50.0f, 5, 1);
        break;
    case 5:
        if ((u8) func_08864348(2.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.7f, arg0, 8, 3, 0, 0);
        }
        if ((u8) func_08864348(20.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.7f, arg0, 5, 3, 0, 0);
        }
        func_088D2674(arg0, 30.0f, 8, 3);
        break;
    case 0xD:
        func_088D2674(arg0, 2.0f, 0xA, 6);
        break;
    case 0xF:
        func_088D2674(arg0, 2.0f, 8, 1);
        break;
    case 0x13:
        func_088D2674(arg0, 2.0f, 8, 7);
        break;
    case 0x14:
        func_088D2674(arg0, 2.0f, 8, 7);
        break;
    case 0x1C:
        if ((u8) func_08864348(22.0f, arg0 + 0x80, 0) != 0) {
            func_09C6EF18(arg0, 0xA, 0xB);
        }
        func_088D2674(arg0, 4.0f, 0xA, 0);
        break;
    case 0x1E:
        func_088D2674(arg0, 4.0f, 8, 2);
        break;
    case 0x1F:
        func_088D2674(arg0, 16.0f, 2, 4);
        func_088D2674(arg0, 20.0f, 2, 4);
        break;
    case 0x20:
        if (*(s32 *)(arg0 + 0x3F4) % 3 == 0) {
            func_09C6EF18(arg0, 2, 5);
        }
        break;
    case 0x25:
        func_088D2674(arg0, 12.0f, 8, 8);
        func_088D2674(arg0, 32.0f, 5, 8);
        break;
    case 0x26:
        if ((u8) func_08864348(4.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(1.5f, arg0, 8, 0, 0, 0);
        }
        if ((u8) func_08864348(20.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(1.5f, arg0, 5, 0, 0, 0);
        }
        break;
    case 0x27:
        if ((u8) func_08864348(2.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.8f, arg0, 5, 3, 0, 0);
        }
        if ((u8) func_08864348(26.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.8f, arg0, 8, 3, 0, 0);
        }
        if ((u8) func_08864348(54.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.8f, arg0, 5, 3, 0, 0);
        }
        if ((u8) func_08864348(78.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.8f, arg0, 8, 3, 0, 0);
        }
        break;
    case 0x2A:
        func_088D2674(arg0, 26.0f, 8, 1);
        func_088D2674(arg0, 18.0f, 8, 1);
        func_088D2674(arg0, 46.0f, 8, 1);
        break;
    case 0x2C:
    case 0x2D:
        if (kind == 0x2C) {
            t = 30.0f;
            func_088D2674(arg0, t, 5, 3);
        } else {
            t = 30.0f;
            func_088D2674(arg0, t, 8, 3);
        }
        if (func_08864348(t, arg0 + 0x80, 0) != 0 && ((u16) func_088900C4(D_08A631A0, 1) & 3) == 0) {
            func_09C91548(arg0, 0);
        }
        break;
    case 0x32:
        func_088D2674(arg0, 30.0f, 8, 3);
        break;
    case 0x3C:
        if (func_08864408(18.0f, arg0 + 0x80, 0) != 0 && (*(u16 *)(D_089CC438 + 0x1C) & 0x1F) == 0) {
            func_09C6F068(0.4f, arg0, 0xE, 0x1A, 0, 0);
        }
        break;
    case 0x3E:
        if (func_08864348(2.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.6f, arg0, 0xA, 7, 0, 0);
        }
        break;
    case 0x19D:
        if (func_08864348(274.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(1.0f, arg0, 0xE, 0x15, 0, 0);
        }
        break;
    case 0x1AA:
        if (func_08864348(190.0f, arg0 + 0x80, 0) != 0) {
            func_09C6F068(0.6f, arg0, 2, 0x17, 0, 0);
        }
        break;
    case 0x1AF:
        if ((*(u16 *)(D_089CC438 + 0x1C) & 0x1F) == 0) {
            func_09C6F068(1.0f, arg0, 0x14, 0x16, 0, 0);
        }
        break;
    case 0x1B0:
        func_088D2674(arg0, 78.0f, 1, 6);
        break;
    }
}
