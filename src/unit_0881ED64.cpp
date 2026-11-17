/* unit_0881ED64: 0x0881ED64-0x0881EE84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x089309BC-0x089309D4) is linked from this unit.
 *
 * C++: the code only matches when compiled as C++ (structure copied member
 * by member).
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    Vec3s unk6;
} Rec;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} Ent;

extern "C" {

Rec *func_0881ED64(s32 arg0, Rec *arg1, u8 arg2, char *arg3) {
    Ent *e;

    arg1->unk0 = arg1->unk4 = 0;
    switch (arg2) {
    case 0:
        *arg1 = *(Rec *)(arg3 + 0x4E8);
        arg1->unk0 = 1;
        return arg1;
    case 1:
        arg1->unk1 = 1;
        break;
    case 2:
        arg1->unk1 = 2;
        break;
    case 3:
        arg1->unk1 = 3;
        break;
    case 4:
        arg1->unk1 = 4;
        break;
    case 5:
        arg1->unk1 = 0;
        break;
    default:
        return 0;
    }
    e = (Ent *)(arg3 + 0x4F4 + arg1->unk1 * sizeof(Ent));
    if (e->unk2 == 0) {
        return 0;
    }
    arg1->unk0 = 1;
    arg1->unk2 = e->unk2;
    arg1->unk4 = e->unk4;
    arg1->unk6.x = e->unk6;
    arg1->unk6.y = e->unk8;
    arg1->unk6.z = e->unkA;
    return arg1;
}

}
