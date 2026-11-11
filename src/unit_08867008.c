/* unit_08867008: 0x08867008-0x08867058 (ULES01213)
 *
 * Bounds (hypothesis): four forwarders to func_088675BC that build a byte index
 * from a group number (8 per group) and a slot; the code around is unrelated.
 */

typedef unsigned char u8;

extern void func_088675BC(void *p, u8 index);

void func_08867008(void *p, u8 group, u8 slot) { func_088675BC(p, slot + group * 8); }
void func_08867020(void *p, u8 group) { func_088675BC(p, group * 8 + 7); }
void func_08867034(void *p, u8 group) { func_088675BC(p, group * 8 + 6); }
void func_08867048(void *p, u8 group) { func_088675BC(p, group * 8); }
