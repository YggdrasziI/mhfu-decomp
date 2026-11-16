/* unit_08869424: 0x08869424-0x08869504 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x0893165C-0x089316DC) is linked from this unit.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char unk0[0x6A53C];
    u8 unk6A53C[14];
} G;

extern G *D_089CC438;

typedef struct {
    char unk0[0x1C];
    s8 unk1C;
} Sub;

typedef struct {
    char unk0[0x68];
    Sub *unk68;
} T;

void func_08869424(T *arg0) {
    s32 idx;

    switch (arg0->unk68->unk1C) {
    case 2:
    case 16:
        idx = 0;
        break;
    case 6:
    case 20:
        idx = 1;
        break;
    case 3:
    case 17:
        idx = 2;
        break;
    case 4:
    case 18:
        idx = 3;
        break;
    case 5:
    case 19:
        idx = 4;
        break;
    case 11:
    case 21:
        idx = 5;
        break;
    case 13:
    case 14:
    case 15:
        idx = 6;
        break;
    case 30:
    case 31:
        idx = 7;
        break;
    case 26:
        idx = 8;
        break;
    case 29:
        idx = 9;
        break;
    case 27:
        idx = 10;
        break;
    case 28:
        idx = 11;
        break;
    case 12:
        idx = 13;
        break;
    case 1:
        idx = 12;
        break;
    case 0:
    case 7:
    case 8:
    case 9:
    case 10:
    case 22:
    case 23:
    case 24:
    case 25:
    default:
        return;
    }
    if (D_089CC438->unk6A53C[idx] < 0xFF) {
        D_089CC438->unk6A53C[idx]++;
    }
}
