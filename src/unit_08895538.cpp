/* unit_08895538: 0x08895538-0x0889560C (ULES01213) */

typedef int s32;
typedef unsigned char u8;

typedef struct Obj {
    virtual void vfunc_08(s32);
    virtual void vfunc_0C();
    char pad04[0xD];
    u8 unk11;
    char pad12[6];
    struct Obj *unk18;
} Obj;

extern "C" {

extern int func_08859C40(void *, Obj *);
extern void func_08895644(char *, u8, Obj *);

void func_08895538(char *arg0) {
    s32 i;
    Obj **p;
    Obj *obj;

    for (i = 0, p = (Obj **)arg0; i < 4; i++, p++) {
        obj = *p;
        if (obj == 0) {
            continue;
        }
        if (obj->unk11 != 1) {
            obj->vfunc_0C();
        }
        if (obj->unk11 == 1) {
            obj = obj->unk18;
            if (*p != 0) {
                (*p)->vfunc_08(1);
            }
            func_08859C40(arg0 + 0x14010, *p);
            *p = 0;
            if (obj != 0) {
                func_08895644(arg0, i, obj);
            }
        }
    }
}

}
