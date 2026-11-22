/* unit_0889FB94: 0x0889FB94-0x0889FD08 (ULES01213) */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Inner {
    u32 unk0;
    u16 unk4;
    u16 pad6;
    u32 unk8;
} Inner;

typedef struct Obj {
    s32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 padD[3];
    Inner *unk10;
} Obj;

extern Obj *func_0889F4BC(void);
extern Obj *func_0889F4F0(void);
extern void func_088A0A9C(void *);
extern u32 func_088A3554(void);
extern void func_0889FD08(Obj *);
extern void func_088A42F0(Inner *);
extern u32 func_088A3560(void);
extern void func_088A00B0(Obj *);
extern void func_088A00D0(void);

s32 func_0889FB94(void) {
    Obj *obj;
    u32 v;

    for (obj = func_0889F4BC(); obj != 0; obj = func_0889F4F0()) {
        obj->unk4++;
        obj->unkC = (obj->unkC > 16) ? obj->unkC - 16 : 0;
        func_088A0A9C((char *)obj + 0x38);
        func_088A0A9C((char *)obj + 0x40);
        if (obj->unk0 == 1 && obj->unk10->unk4 == 0) {
            v = obj->unk10->unk0;
            if (v != func_088A3554()) {
                obj->unk0 = 2;
                obj->unk10->unk4 = 1;
            }
            continue;
        }
        if (obj->unk0 != 0 && obj->unk0 != 7) {
            func_0889FD08(obj);
        }
        if (obj->unk8 != 0 && obj->unk8 < obj->unk4) {
            obj->unk0 = 3;
        }
        if (obj->unk0 == 4) {
            obj->unk0 = 3;
        }
        if (obj->unk0 == 3) {
            func_088A42F0(obj->unk10);
            obj->unk0 = 5;
        }
        if (obj->unk10->unk8 & func_088A3560()) {
            func_088A00B0(obj);
            obj->unk0 = 7;
        }
    }
    func_088A00D0();
    return 0;
}
