/* unit_088CC190: 0x088CC190-0x088CC478 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern int func_0880C084(void *, void *, s32);

char *func_088CC190(s32 arg0, char *arg1) {
    func_0880C084((void *) (arg0 + 0x334), arg1, 0xC);
    func_0880C084((void *) (arg0 + 0x358), arg1 + 0xC, 0xC);
    func_0880C084((void *) (arg0 + 0x37C), arg1 + 0x18, 0xC);
    func_0880C084((void *) (arg0 + 0x340), arg1 + 0x24, 0xC);
    func_0880C084((void *) (arg0 + 0x364), arg1 + 0x30, 0xC);
    func_0880C084((void *) (arg0 + 0x388), arg1 + 0x3C, 0xC);
    func_0880C084((void *) (arg0 + 0x34C), arg1 + 0x48, 0xC);
    func_0880C084((void *) (arg0 + 0x370), arg1 + 0x54, 0xC);
    func_0880C084((void *) (arg0 + 0x394), arg1 + 0x60, 0xC);
    return arg1 + 0x6C;
}

char *func_088CC24C(char *arg0, char *arg1) {
    u8 sp1C[4];

    func_0880C084(arg0 + 0x3A4, arg1, 0xC);
    func_0880C084(arg0 + 0x3B0, arg1 + 0xC, 4);
    func_0880C084(sp1C, arg1 + 0x10, 4);
    *(s32 *)(arg0 + 0x3B4) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x14, 4);
    *(s32 *)(arg0 + 0x3B8) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x18, 4);
    *(s32 *)(arg0 + 0x3BC) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x1C, 4);
    *(s32 *)(arg0 + 0x3C0) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x20, 4);
    *(s32 *)(arg0 + 0x3C4) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x24, 4);
    *(s32 *)(arg0 + 0x3C8) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x28, 4);
    *(s32 *)(arg0 + 0x3CC) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    func_0880C084(sp1C, arg1 + 0x2C, 4);
    *(s32 *)(arg0 + 0x3D0) = (s32) (sp1C[2] | ((sp1C[1] << 8) | ((sp1C[3] << 0x18) | (sp1C[0] << 0x10))));
    return arg1 + 0x30;
}
