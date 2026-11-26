/* func_08821890: copies six 12-byte records (one, then five in a loop). */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

struct Vec {
    s16 x, y, z;
};

struct Rec {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    Vec v;
};

struct Src {
    char pad[0x4E8];
    Rec first;
    Rec list[5];
};

struct Dst {
    char pad[0x11BE];
    Rec first;
    Rec list[5];
    u8 flag;
};

extern "C" void func_08821890(Dst *dst, Src *src) {
    s32 i;

    dst->first = src->first;
    for (i = 0; i < 5; i++) {
        dst->list[i] = src->list[i];
    }
    dst->flag = 0;
}
