/* Decompiled C code from SKULL.EXE using Ghidra */
/* Generated automatically - may contain errors */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

/* Function: FUN_1000_0010 @ 1000:0010 */

void __cdecl16near FUN_1000_0010(void)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  undefined2 *local_22;
  undefined2 local_1e;
  
  FUN_1000_3e4e();
  iVar7 = 0;
  local_22 = (undefined2 *)0x6602;
  FUN_1000_569c();
  uVar1 = *(uint *)0xbc;
  *(uint *)0x5dbc = uVar1 & 0xff | (uint)(byte)((char)(uVar1 >> 8) + 0xc) << 8;
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x1080 = uVar5;
  FUN_1000_3aee();
  FUN_1000_4dec();
  *(int *)0x12ea = *(int *)0x5dbc + 0x924;
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x10e6 = uVar5;
  while( true ) {
    iVar6 = FUN_1000_3aee();
    if ((iVar6 < 1) || (*(int *)(iVar7 * 4 + *(int *)0x12ea) == -1)) break;
    iVar7 = iVar7 + 1;
  }
  *(int *)0xcc = iVar7;
  FUN_1000_4dec();
  iVar7 = 0;
  *(int *)0x10e8 = *(int *)0xcc * 4 + *(int *)0x12ea + 4;
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x65fe = uVar5;
  while( true ) {
    iVar6 = FUN_1000_3aee();
    if ((iVar6 < 1) || (*(int *)(iVar7 * 4 + *(int *)0x10e8) == -1)) break;
    iVar7 = iVar7 + 1;
  }
  *(int *)0xce = iVar7;
  FUN_1000_4dec();
  *(int *)0x65c0 = *(int *)0xce * 4 + *(int *)0x10e8 + 4;
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x680e = uVar5;
  iVar7 = FUN_1000_3aee();
  if (0 < iVar7) {
    *(undefined2 *)0xd0 = local_1e;
    FUN_1000_3aee();
  }
  FUN_1000_4dec();
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x65be = uVar5;
  uVar5 = FUN_1000_3b24();
  *(undefined2 *)0x6600 = uVar5;
  puVar8 = (undefined2 *)*(undefined2 *)0xbc;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    puVar3 = local_22;
    local_22 = local_22 + 1;
    puVar2 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar3 = *puVar2;
  }
  FUN_1570_000a();
  FUN_1570_05d4();
  cVar4 = FUN_1000_55a6();
  if ((cVar4 == 'n') || (cVar4 == 'N')) {
    *(undefined2 *)0xe6 = 0;
    FUN_1570_000a();
  }
  iVar7 = 0;
  do {
    FUN_1000_3740();
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  if (*(int *)0xe6 != 0) {
    FUN_1000_55be();
  }
  FUN_1000_3740();
  FUN_1570_062a();
  FUN_1570_05d4();
  FUN_1570_062a();
  FUN_1570_05d4();
  FUN_1570_062a();
  FUN_1570_05d4();
  FUN_1000_3740();
  FUN_1570_062a();
  FUN_1570_05d4();
  FUN_1000_3444();
  FUN_1000_358c();
  FUN_1000_3082();
  FUN_1000_35c6();
  do {
    iVar7 = FUN_1000_03a6();
    if (iVar7 == 0) break;
    iVar7 = FUN_1000_0312();
  } while (iVar7 != -1);
  FUN_1000_33b8();
  do {
    iVar7 = FUN_1000_5592();
  } while (iVar7 == 0);
  FUN_1570_000a();
  return;
}



/* Function: FUN_1000_0312 @ 1000:0312 */

int __cdecl16near FUN_1000_0312(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  int iVar3;
  
  FUN_1000_3e4e();
  do {
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      if (*(int *)(iVar3 * 4 + param_1) == *(int *)0xec) {
        iVar3 = iVar3 + 1;
        iVar2 = iVar3;
      }
      while ((iVar1 = *(int *)(iVar3 * 4 + param_1), iVar1 != 0 && (iVar1 != *(int *)0xec))) {
        iVar3 = iVar3 + 1;
      }
      iVar1 = iVar3 - iVar2;
      if (iVar1 < 1) {
        iVar2 = 1;
      }
      else {
        iVar2 = FUN_1000_0654(iVar2 * 4 + param_1,iVar1,param_2,iVar1);
        iVar3 = iVar1;
      }
    } while (iVar2 == 2);
  } while (iVar2 == 0);
  return iVar2;
}



/* Function: FUN_1000_03a6 @ 1000:03a6 */

int __cdecl16near FUN_1000_03a6(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  int local_5a;
  int local_58;
  int local_56;
  undefined local_52 [72];
  undefined2 uStack10;
  int iStack8;
  undefined *puStack6;
  
  FUN_1000_3e4e();
  local_5a = 0;
  do {
    puStack6 = (undefined *)0x50;
    iStack8 = param_2;
    uStack10 = 0x3c4;
    iVar2 = FUN_1000_04aa();
    local_56 = 0;
    while (local_56 < iVar2) {
      for (; (iVar1 = local_56, *(char *)(local_56 + param_2) == ' ' && (local_56 < iVar2));
          local_56 = local_56 + 1) {
      }
      local_58 = 0;
      while ((*(char *)(local_56 + param_2) != ' ' && (local_56 < iVar2))) {
        local_52[local_58] = *(undefined *)(local_56 + param_2);
        local_58 = local_58 + 1;
        local_56 = local_56 + 1;
      }
      if (local_56 - iVar1 < 10) {
        *(undefined *)(local_56 + param_2) = 0;
        local_56 = local_56 + 1;
      }
      else {
        *(undefined *)(iVar1 + param_2 + 9) = 0;
      }
      local_52[local_58] = 0;
      puStack6 = local_52;
      iStack8 = 0x443;
      iVar3 = FUN_1000_05b6();
      *(int *)(local_5a * 4 + param_1) = iVar3;
      if (iVar3 == 0) {
        local_56 = iVar2 + 10;
        local_5a = 0;
      }
      else if (*(int *)(local_5a * 4 + param_1) != *(int *)0xee) {
        *(int *)(local_5a * 4 + param_1 + 2) = iVar1;
        local_5a = local_5a + 1;
      }
    }
  } while (local_5a == 0);
  *(undefined2 *)(local_5a * 4 + param_1) = 0;
  return local_5a;
}



/* Function: FUN_1000_04aa @ 1000:04aa */

undefined2 __cdecl16near FUN_1000_04aa(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 unaff_DS;
  int local_a;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  
  FUN_1000_3e4e();
  iVar6 = 0;
  FUN_1000_3740(4,0);
  *(undefined2 *)0x26a = 0;
  uVar3 = 0x7a;
  local_a = 0x1000;
  FUN_1570_05d4(0x7a);
  while ((local_a < param_2 && (iVar6 != 0xd))) {
    iVar4 = 0x4f2;
    iVar6 = FUN_1000_55a6();
    if (iVar6 == 0) {
      iVar6 = FUN_1000_55a6();
    }
    else if (iVar6 != 0xd) {
      param_1[local_a] = (byte)iVar6;
      param_1[local_a + 1] = 0;
      if (iVar6 == 8) {
        if (local_a != 0) {
          FUN_1570_062a(uVar3,iVar4 + -1);
          uVar3 = 0x7e;
          uVar5 = unaff_DS;
          FUN_1570_05d4();
          local_a = 0x1570;
          FUN_1570_062a(uVar3,uVar5);
        }
      }
      else {
        pbVar2 = param_1 + local_a;
        local_a = 0x1570;
        FUN_1570_05d4(pbVar2);
        uVar3 = FUN_1570_064d();
      }
    }
  }
  while( true ) {
    bVar1 = *param_1;
    if ((*(byte *)(bVar1 + 0x7a5) & 1) == 0) {
      bVar1 = *param_1;
    }
    else {
      bVar1 = bVar1 + 0x20;
    }
    *param_1 = bVar1;
    if (bVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  FUN_1570_05d4(0x80);
  FUN_1000_3710(4);
  return 0x1570;
}



/* Function: FUN_1000_05b6 @ 1000:05b6 */

int __cdecl16near FUN_1000_05b6(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined2 unaff_DS;
  int local_c;
  int iVar5;
  
  FUN_1000_3e4e();
  iVar4 = 0;
  local_c = 0;
  iVar5 = 0;
  while (local_c < *(int *)0xd0) {
    iVar1 = FUN_1000_54f2(*(int *)0x65c0 + iVar4);
    iVar2 = FUN_1000_550e(param_1,*(int *)0x65c0 + iVar4,6);
    if (iVar2 == 0) {
      puVar3 = (undefined *)(iVar1 + 1 + *(int *)0x65c0 + iVar4);
      iVar5 = CONCAT11(puVar3[1],*puVar3);
      local_c = *(int *)0xd0;
    }
    else {
      iVar4 = iVar4 + iVar1 + 3;
      local_c = 0x5f1;
    }
  }
  if (iVar5 == 0) {
    FUN_1000_33b8(0xd001,param_1);
  }
  return iVar5;
}



/* Function: FUN_1000_0654 @ 1000:0654 */

undefined2 __cdecl16near FUN_1000_0654(uint *param_1,int param_2)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_1c;
  undefined2 local_16;
  undefined2 local_14 [3];
  undefined2 uStack14;
  uint *puStack12;
  
  FUN_1000_3e4e();
  uVar4 = *(uint *)0x660c;
  iVar8 = *(int *)0x5dbc;
  if (((*param_1 & 0x400) == 0) || (param_2 != 1)) {
    puStack12 = param_1;
    uStack14 = 0x6a0;
    iVar7 = FUN_1000_0892();
    if (iVar7 == 0) {
      local_16 = 1;
    }
    else {
      local_16 = FUN_1000_0ea0();
    }
  }
  else {
    local_16 = FUN_1000_07ee();
  }
  uVar5 = (uint)*(byte *)0x6602;
  if (((*(int *)0xfa == 0) &&
      (puVar6 = (undefined2 *)(uVar5 * 0x12 + iVar8), (*(byte *)(puVar6 + 1) & 0x80) != 0)) &&
     ((*(byte *)(puVar6 + 10) & 0x80) != 0)) {
    puVar10 = local_14;
    puVar9 = puVar6;
    for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar3 = puVar10;
      puVar10 = puVar10 + 1;
      puVar2 = puVar9;
      puVar9 = puVar9 + 1;
      *puVar3 = *puVar2;
    }
    puVar10 = puVar6 + 9;
    for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar3 = puVar6;
      puVar6 = puVar6 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    puVar10 = (undefined2 *)(uVar5 * 0x12 + iVar8 + 0x12);
    puVar6 = local_14;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      puVar3 = puVar10;
      puVar10 = puVar10 + 1;
      puVar2 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar3 = *puVar2;
    }
    FUN_1000_33b8();
    FUN_1000_3444();
  }
  for (local_1c = 0; local_1c < 6; local_1c = local_1c + 1) {
    if ((uint)*(byte *)(local_1c + 0x370) == (uVar4 & 0x7f)) {
      if ((*(byte *)(uVar5 * 0x12 + *(int *)0x5dbc + 2) & 1) == 0) {
        FUN_1000_33b8();
      }
      if (local_1c == 3) {
        pbVar1 = (byte *)0x6605;
        *pbVar1 = *pbVar1 | 8;
      }
      else {
        pbVar1 = (byte *)0x6605;
        *pbVar1 = *pbVar1 & 0xf7;
      }
    }
  }
  FUN_1000_35c6();
  FUN_1000_3740();
  puStack12 = (uint *)0x7c1;
  FUN_1570_062a();
  puStack12 = (uint *)0x7d5;
  FUN_1000_5548();
  puStack12 = (uint *)0x7e2;
  FUN_1570_05d4();
  return local_16;
}



/* Function: FUN_1000_07ee @ 1000:07ee */

undefined2 __cdecl16near FUN_1000_07ee(undefined2 param_1)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined uVar2;
  
  FUN_1000_3e4e();
  uVar1 = 2;
  uVar2 = 0;
  switch(param_1) {
  case 0x403:
    FUN_1000_314a();
    break;
  case 0x405:
    FUN_1570_000a(0xffff);
    FUN_1000_3d7c(0);
    break;
  case 0x406:
    FUN_1000_33b8(0xd079);
    *(undefined2 *)0xf8 = 0;
    break;
  case 0x407:
    FUN_1000_33b8(0xd07a);
    *(undefined2 *)0xf8 = 1;
    break;
  case 0x408:
    uVar2 = 1;
  case 0x409:
    FUN_1000_380e(uVar2);
    break;
  case 0x40b:
    uVar1 = FUN_1000_0ea0(0x5b64);
  }
  return uVar1;
}



/* Function: FUN_1000_0892 @ 1000:0892 */

uint * __cdecl16near FUN_1000_0892(uint *param_1,int param_2,int param_3,uint *param_4)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined2 unaff_DS;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  FUN_1000_3e4e();
  uVar6 = 0;
  for (iVar5 = 0; iVar5 < *(int *)0xc2; iVar5 = iVar5 + 1) {
    *(undefined *)(iVar5 + (int)param_4) = 0;
  }
  if ((param_2 == 0) || (uVar2 = *param_1, *param_4 = uVar2, (uVar2 & 0x4000) == 0)) {
    if ((*param_1 & 0x8000) == 0) {
      param_2 = 0;
      *param_4 = 0;
      puVar3 = (uint *)0xd011;
      FUN_1000_33b8();
    }
    else {
      *param_4 = 0x4018;
      puVar3 = (uint *)0x376;
      uVar6 = 0x92a;
      FUN_1000_54c0(param_4 + 1);
    }
  }
  else {
    puVar3 = (uint *)(param_1[1] + param_3);
    uVar6 = 0x903;
    FUN_1000_54c0(param_4 + 1);
    param_2 = param_2 + -1;
  }
  if (*(int *)0xe8 != 0) {
    puVar3 = (uint *)param_4[0x26];
    uVar6 = param_4[0x19];
    FUN_1000_419e(0x379,uVar6,param_4[0x20]);
  }
  if (param_1[uVar6 * 2] == *(uint *)0xf4) {
    puVar4 = param_4 + 0x19;
  }
  else {
    puVar4 = param_4 + 6;
  }
  puVar7 = puVar4;
  if (param_2 != 0) {
    iVar5 = FUN_1000_0a70(param_1 + param_2 * 2,param_2,param_3,puVar4,puVar4);
    param_2 = param_2 - iVar5;
    puVar3 = puVar4;
  }
  if (*param_4 == 0x401d) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    puVar3 = param_4 + 0x19;
    iVar5 = FUN_1000_0a70(param_1 + param_2 * 2,param_2,param_3,puVar3,puVar7);
    param_2 = param_2 - iVar5;
  }
  if (*(int *)0xe8 != 0) {
    puVar3 = (uint *)param_4[0x26];
    FUN_1000_419e(0x3ad,param_4[0x19],param_4[0x20]);
  }
  bVar1 = *(byte *)((uint)*(byte *)param_4 * 6 + 0x100);
  if ((((0 < param_2) || (((bVar1 & 2) != 0 && (param_4[0x1a] != 0)))) ||
      (((bVar1 & 0x80) != 0 && (param_4[7] == 0)))) ||
     (((((bVar1 & 0x20) != 0 && (param_4[7] != 0)) ||
       (((bVar1 & 0x10) != 0 && (param_4[0x13] != 0)))) ||
      (((bVar1 & 1) != 0 && (param_4[0x26] != 0)))))) {
    puVar3 = (uint *)0xd023;
    FUN_1000_33b8();
  }
  return puVar3;
}



/* Function: FUN_1000_0a70 @ 1000:0a70 */

int __cdecl16near FUN_1000_0a70(uint *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined2 unaff_DS;
  int local_c;
  int local_a;
  int in_stack_0000fff8;
  int local_6;
  
  FUN_1000_3e4e();
  local_c = param_2;
  local_6 = 0;
  uVar1 = *param_1;
  if ((param_2 != 0) && ((uVar1 & 0x1000) != 0)) {
    *(uint *)(param_4 + 2) = uVar1;
    local_6 = param_1[1] + param_3;
    in_stack_0000fff8 = param_4 + 4;
    local_a = 0xab4;
    FUN_1000_54c0();
    local_c = param_2 + -1;
    param_1 = param_1 + 2;
  }
  if ((local_c < 3) || (param_1[2] != 0x100f)) {
    if ((local_c == 1) &&
       ((*(int *)(param_4 + 0x1a) != 0 && (uVar1 = param_1[local_6 * 2], (uVar1 & 0x800) != 0)))) {
      *(uint *)(param_4 + 0xe) = uVar1;
      in_stack_0000fff8 = local_6;
      local_6 = local_6 + 1;
      goto LAB_1000_0b0a;
    }
    if (local_c == 0) goto LAB_1000_0b0a;
    if ((1 < local_c) && ((param_1[2] & 0x2000) != 0)) {
      uVar1 = param_1[local_6 * 2];
      *(uint *)(param_4 + 0xe) = uVar1;
      if ((uVar1 & 0x800) == 0) {
        *(undefined2 *)(param_4 + 0xe) = 0xffff;
      }
      else {
        in_stack_0000fff8 = local_6;
        local_6 = local_6 + 1;
      }
    }
    uVar1 = param_1[local_6 * 2];
    *(uint *)(param_4 + 0x1a) = uVar1;
    if ((uVar1 & 0x2000) != 0) {
      local_a = local_6;
      local_6 = local_6 + 1;
      goto LAB_1000_0b0a;
    }
  }
  else {
    local_6 = 3;
    uVar1 = param_1[4];
    *(uint *)(param_4 + 0xe) = uVar1;
    if ((uVar1 & 0x800) == 0) {
      *(undefined2 *)(param_4 + 0xe) = 0xffff;
    }
    else {
      in_stack_0000fff8 = 2;
    }
    uVar1 = *param_1;
    *(uint *)(param_4 + 0x1a) = uVar1;
    if ((uVar1 & 0x2000) != 0) {
      local_a = 0;
      goto LAB_1000_0b0a;
    }
  }
  *(undefined2 *)(param_4 + 0x1a) = 0xffff;
LAB_1000_0b0a:
  if ((*(int *)(param_4 + 0xe) == -1) || (*(int *)(param_4 + 0x1a) == -1)) {
    local_6 = 0;
    *(undefined2 *)(param_4 + 0x1a) = 0;
    *(undefined2 *)(param_4 + 0xe) = 0;
  }
  else {
    if (*(int *)(param_4 + 0xe) != 0) {
      local_6 = param_1[in_stack_0000fff8 * 2 + 1] + param_3;
      local_a = 0xbe0;
      FUN_1000_54c0(param_4 + 0x10);
    }
    if (*(int *)(param_4 + 0x1a) != 0) {
      local_6 = param_1[local_a * 2 + 1] + param_3;
      FUN_1000_54c0(param_4 + 0x1c);
    }
    if (*(int *)(param_4 + 2) != 0) {
      local_6 = local_6 + 1;
    }
  }
  return local_6;
}



/* Function: FUN_1000_0c1c @ 1000:0c1c */

undefined2 __cdecl16near FUN_1000_0c1c(uint *param_1,uint *param_2,char *param_3)

{
  int iVar1;
  undefined2 unaff_DS;
  int iVar2;
  uint *puVar3;
  undefined2 uVar4;
  
  FUN_1000_3e4e();
  uVar4 = 2;
  puVar3 = (uint *)0x0;
  iVar2 = 0;
  if (param_1[0xd] == 0) {
    if (*param_3 == '\0') {
      puVar3 = (uint *)0xd002;
      goto LAB_1000_0c56;
    }
    iVar2 = -0x2ffd;
    FUN_1000_33b8(0xd003,param_2,param_3);
    puVar3 = param_2;
  }
  while (iVar2 == 0) {
    if (puVar3 != (uint *)0x0) {
      uVar4 = 1;
      puVar3 = (uint *)0x5b14;
      iVar2 = FUN_1000_03a6(0x5abc,0x5b14,0x5b14,param_1);
      iVar1 = FUN_1000_0a70(0x5abc);
      if (iVar1 == 0) {
        uVar4 = 0;
        iVar2 = 1;
      }
    }
    if (iVar2 == 0) {
      iVar2 = FUN_1000_0d36((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc,param_1,0x65c2);
      iVar2 = iVar2 + 0x65c2;
      puVar3 = param_1;
      iVar1 = FUN_1000_0d36(0x6606);
      if (((iVar2 + iVar1 == 0) && (param_1[0xd] != *(uint *)0xf0)) &&
         ((param_1[0xd] & 0x8000) == 0)) {
        puVar3 = (uint *)0xcf2;
        FUN_1000_33b8(0xd005);
        iVar2 = 1;
        uVar4 = 3;
      }
      else if (iVar2 + iVar1 < 2) {
        iVar2 = 1;
        *param_1 = (uint)*(byte *)0x65c2;
      }
      else {
        param_2 = param_1 + 0xe;
        puVar3 = (uint *)0xd004;
LAB_1000_0c56:
        iVar2 = 0xc5a;
        FUN_1000_33b8(puVar3,param_2);
      }
    }
  }
  return uVar4;
}



/* Function: FUN_1000_0d36 @ 1000:0d36 */

/* WARNING: Could not reconcile some variable overlaps */

uint __cdecl16near FUN_1000_0d36(byte *param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined2 unaff_DS;
  uint local_a;
  uint uVar3;
  uint uVar4;
  uint local_6;
  uint uVar5;
  
  FUN_1000_3e4e();
  bVar1 = *param_1;
  local_6 = 0;
  local_a = (uint)*(byte *)(param_2 + 0xe);
  uVar5 = (uint)*(byte *)(param_2 + 0x1a);
  do {
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) {
      if (*(int *)0xe8 != 0) {
        FUN_1000_419e(0x3f8);
      }
      return local_6;
    }
    uVar4 = uVar3;
    if (*(int *)0xe8 != 0) {
      iVar2 = uVar3 * 0xc + *(int *)0xbc;
      local_6 = (uint)*(byte *)(iVar2 + 5);
      uVar4 = (uint)*(byte *)(iVar2 + 4);
      FUN_1000_419e(0x3e1);
      local_a = uVar3;
    }
    if ((char)local_a == '\0') {
      if (((*(uint *)(param_2 + 0x1a) & 0x800) == 0) ||
         (*(char *)(uVar4 * 0xc + *(int *)0xbc + 5) != (char)uVar5)) {
        iVar2 = uVar4 * 0xc + *(int *)0xbc;
        goto LAB_1000_0deb;
      }
LAB_1000_0df3:
      *(undefined *)(local_6 + param_3) = (char)uVar4;
      local_6 = local_6 + 1;
    }
    else {
      iVar2 = uVar4 * 0xc + *(int *)0xbc;
      if (*(char *)(iVar2 + 5) == (char)local_a) {
LAB_1000_0deb:
        if (*(char *)(iVar2 + 4) == (char)uVar5) goto LAB_1000_0df3;
      }
    }
    iVar2 = uVar4 * 0xc + *(int *)0xbc;
    if ((((*(uint *)(iVar2 + 6) & 0x400) != 0) && ((*(uint *)(iVar2 + 10) & 0x4000) != 0)) ||
       ((*(uint *)(uVar4 * 0xc + *(int *)0xbc + 6) & 0x380) != 0)) {
      local_a = param_2 * 0xc + *(int *)0xbc + 1;
      uVar4 = param_2;
      iVar2 = FUN_1000_0d36();
      local_6 = local_6 + param_3 + iVar2;
    }
    bVar1 = *(byte *)(uVar4 * 0xc + *(int *)0xbc);
  } while( true );
}



/* Function: FUN_1000_0ea0 @ 1000:0ea0 */

int * __cdecl16near FUN_1000_0ea0(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_DS;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  
  FUN_1000_3e4e();
  uVar6 = (uint)*(byte *)param_1;
  iVar7 = uVar6 * 6;
  piVar9 = (int *)(uint)*(byte *)(iVar7 + 0x101);
  bVar3 = *(byte *)(iVar7 + 0x100);
  uVar13 = (uint)bVar3;
  piVar8 = *(int **)(iVar7 + 0xfe);
  iVar7 = 2;
  if (((bVar3 & 0x40) != 0) || (param_1[0x13] != 0)) {
    piVar9 = param_1 + 1;
    piVar8 = param_1 + 6;
    iVar7 = FUN_1000_0c1c(piVar8,piVar9,param_1 + 8);
  }
  if ((iVar7 != 0) && (iVar7 != 3)) {
    if (((uint)piVar9 & 0x10) != 0) {
      param_1[0x1a] = 0x1007;
      iVar7 = 0x40c;
      piVar9 = param_1 + 0x1b;
      piVar8 = (int *)0xf20;
      FUN_1000_54c0();
    }
    if (*(int *)0xe8 != 0) {
      iVar7 = param_1[0x26];
      piVar9 = (int *)param_1[0x20];
      piVar8 = (int *)0x411;
      FUN_1000_419e();
    }
    if (((uVar13 & 4) != 0) || (param_1[0x26] != 0)) {
      piVar9 = param_1 + 1;
      piVar8 = param_1 + 0x19;
      iVar7 = FUN_1000_0c1c(piVar8,piVar9,param_1 + 0x1b);
    }
  }
  if (iVar7 == 0) {
    return (int *)0x0;
  }
  if (iVar7 == 3) {
    return (int *)0x3;
  }
  piVar12 = (int *)0xf70;
  iVar7 = FUN_1000_2e28();
  if ((iVar7 == 0) &&
     (((*(byte *)((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc + 2) & 1) != 0 ||
      ((*(byte *)0x6605 & 8) != 0)))) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if (bVar5) {
    pbVar1 = (byte *)0x6605;
    *pbVar1 = *pbVar1 | 1;
    if (*param_1 == 0x4018) goto LAB_1000_0fb6;
    piVar12 = (int *)0xd081;
  }
  else {
    pbVar1 = (byte *)0x6605;
    *pbVar1 = *pbVar1 & 0xfe;
LAB_1000_0fb6:
    piVar2 = (int *)0x660c;
    *piVar2 = *piVar2 + 1;
    piVar11 = (int *)param_1[0x19];
    if ((((uint)piVar9 & 4) == 0) ||
       ((*(uint *)((int)piVar11 * 0xc + *(int *)0xbc + 6) & 0x2000) != 0)) {
      if ((((uint)piVar9 & 0x80) != 0) && (piVar10 = (int *)param_1[6], piVar10 != (int *)0x0)) {
        piVar9 = (int *)0xff6;
        piVar12 = piVar10;
        iVar7 = FUN_1000_2dd0();
        if (iVar7 != 0) goto LAB_1000_1011;
        piVar12 = (int *)((uint)piVar9 & 8);
        piVar8 = (int *)0x100a;
        iVar7 = FUN_1000_2c1e();
        piVar9 = piVar10;
        if (iVar7 != 0) goto LAB_1000_1011;
LAB_1000_103a:
        piVar12 = (int *)0x3;
        goto LAB_1000_109e;
      }
LAB_1000_1011:
      if ((((uint)piVar9 & 0x40) != 0) && (piVar11 != (int *)0x0)) {
        piVar9 = (int *)0x1023;
        piVar12 = piVar11;
        iVar7 = FUN_1000_2dd0();
        if (iVar7 == 0) {
          piVar12 = (int *)0x0;
          piVar8 = (int *)0x1033;
          iVar7 = FUN_1000_2c1e();
          piVar9 = piVar11;
          if (iVar7 == 0) goto LAB_1000_103a;
        }
      }
      if ((((uint)piVar9 & 0x20) != 0) || (param_1[0x13] != *(int *)0xf0)) {
        pcVar4 = *(code **)(uVar6 * 6 + 0xfc);
        if (pcVar4 != (code *)0x0) {
          if (piVar8 == (int *)0x0) {
            piVar12 = (int *)(**(code **)(uVar6 * 6 + 0xfc))(param_1,piVar12);
          }
          else {
            (*pcVar4)();
            piVar12 = piVar8;
          }
        }
        goto LAB_1000_109e;
      }
      piVar12 = (int *)0xd025;
    }
    else {
      piVar12 = (int *)0xd0a0;
    }
  }
  FUN_1000_33b8();
LAB_1000_109e:
  if (piVar12 != (int *)0xffff) {
    piVar12 = (int *)FUN_1000_10ba(piVar12);
  }
  return piVar12;
}



/* Function: FUN_1000_10ba @ 1000:10ba */

undefined2 __cdecl16near FUN_1000_10ba(undefined2 param_1)

{
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  char *pcVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  undefined uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 unaff_DS;
  uint local_12;
  uint local_10;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  FUN_1000_3e4e();
  uVar9 = (uint)*(byte *)0x6602;
  uVar10 = FUN_1000_56ae();
  uVar10 = uVar10 & 0xf;
  uVar15 = (uint)*(byte *)(uVar9 * 0x12 + *(int *)0x5dbc + 2);
  local_12 = (uint)*(byte *)0x6609;
  local_10 = (uint)*(byte *)0x6608;
  uVar7 = (uint)*(byte *)0x6603;
  if ((*(byte *)0x6605 & 4) != 0) {
    if (uVar7 == 4) {
      pbVar1 = (byte *)0x6605;
      *pbVar1 = *pbVar1 & 0xfb;
      *(undefined *)(*(int *)0xbc + 0x19a) = 5;
    }
    else {
      *(undefined *)(*(int *)0xbc + 0x19a) = 7;
      iVar12 = uVar7 * 2;
      uVar9 = (uint)*(byte *)(iVar12 + 0x459);
      bVar5 = *(byte *)(iVar12 + 0x458);
      pcVar4 = (char *)0x6603;
      *pcVar4 = *pcVar4 + '\x01';
      uVar10 = 0;
      local_10 = 0x1154;
      param_1 = FUN_1000_22da(uVar9,uVar9,bVar5 | 0xd000,0,param_1);
    }
  }
  if ((uVar15 & 0x10) == 0) {
    if (local_10 != 0) {
      *(undefined *)0x6608 = 0;
      uVar10 = local_10;
    }
  }
  else {
    pbVar1 = (byte *)(uVar9 * 0x12 + *(int *)0x5dbc + 2);
    *pbVar1 = *pbVar1 & 0xef;
    uVar10 = 0;
  }
  if (uVar10 == 0) {
    iVar12 = FUN_1000_2e70(uVar9 * 0x12 + *(int *)0x5dbc,0x8000,0x4000,0x65c2);
    if (iVar12 != 0) {
      iVar13 = 0;
      while (iVar13 < iVar12) {
        iVar12 = 0;
        iVar14 = 0x11ed;
        FUN_1000_1406(*(undefined *)(iVar13 + 0x65c2),0,param_1);
        iVar13 = iVar14 + 1;
      }
    }
    if (uVar9 == 0x5a) {
      param_1 = FUN_1000_22da(0x5a,0x24,0xd12d,1,param_1);
    }
    if ((*(byte *)0x6605 & 8) == 0) {
      *(undefined *)0x6608 = 1;
    }
    else {
      *(undefined *)0x6608 = 4;
    }
    goto LAB_1000_1229;
  }
  if (uVar10 == 1) {
    if ((uVar15 & 2) != 0) {
      FUN_1000_33b8(0xb082);
    }
    if ((uVar15 & 4) == 0) goto LAB_1000_1229;
    uVar11 = 0xb086;
  }
  else {
    if (uVar10 == 2) {
      if ((uVar15 & 4) != 0) {
        FUN_1000_33b8(*(int *)0xf6 + 0xb8U | 0xd000);
      }
      piVar2 = (int *)0xf6;
      *piVar2 = *piVar2 + 1;
      puVar3 = (uint *)0xf6;
      *puVar3 = *puVar3 & 3;
      goto LAB_1000_1229;
    }
    if (uVar10 == 3) {
      if ((uVar15 & 8) == 0) goto LAB_1000_1229;
      *(undefined *)0x660a = 1;
      uVar11 = 0xd090;
      goto LAB_1000_13e4;
    }
    if ((((uVar10 == 4) && (local_12 == 0)) && (*(char *)0x660a == '\0')) &&
       (iVar12 = FUN_1000_2e70(uVar9 * 0x12 + *(int *)0x5dbc,1,0,0x65c2), iVar12 != 0)) {
      bVar5 = *(byte *)0x65c2;
      local_12 = (uint)bVar5;
      *(byte *)0x6609 = bVar5;
      *(undefined *)0x6603 = 0;
      *(undefined *)(local_12 * 0xc + *(int *)0xbc + 3) = 8;
      *(undefined *)(local_12 * 0xc + *(int *)0xbc + 2) = 4;
      *(uint *)0x43a = uVar9;
    }
    if ((local_12 != 0) && (*(uint *)0x43a == uVar9)) {
      *(undefined *)0x6607 = 0;
      iVar12 = (*(uint *)(local_12 * 0xc + *(int *)0xbc + 10) & 0x3f) * 4;
      if (*(char *)0x6603 == '\x02') {
        if ((*(int *)0xfa != 0) || (cVar6 = *(char *)(iVar12 + 0x43e), cVar6 == '\0')) {
          uVar8 = *(undefined *)(iVar12 + 0x43f);
          goto LAB_1000_13a7;
        }
        param_1 = FUN_1000_1ee8(CONCAT11(0xd0,cVar6),local_12);
      }
      else {
        uVar8 = *(undefined *)(iVar12 + (uint)*(byte *)0x6603 + 0x43c);
LAB_1000_13a7:
        FUN_1000_3376(CONCAT11(0xd0,uVar8),local_12);
      }
      pcVar4 = (char *)0x6603;
      *pcVar4 = *pcVar4 + '\x01';
    }
    if (*(char *)0x660a == '\0') goto LAB_1000_1229;
    if (((uVar15 & 8) == 0) || (*(int *)0xfa == 0)) {
      *(undefined *)0x660a = 0;
      uVar11 = 0xd092;
    }
    else {
      cVar6 = *(char *)0x660a;
      pcVar4 = (char *)0x660a;
      *pcVar4 = *pcVar4 + '\x01';
      if (cVar6 != '\x01') {
        *(undefined *)0x660a = 0;
        param_1 = FUN_1000_1ee8(0xd093,0);
        goto LAB_1000_1229;
      }
      uVar11 = 0xd091;
    }
  }
LAB_1000_13e4:
  FUN_1000_33b8(uVar11);
LAB_1000_1229:
  if (uVar9 == 7) {
    param_1 = 0xffff;
    FUN_1000_33b8(0xd136);
  }
  if ((*(char *)0x6609 != '\0') && ((*(uint *)0x43a != uVar9 || (2 < *(byte *)0x6603)))) {
    *(undefined *)0x6609 = 0;
    *(undefined *)(local_12 * 0xc + *(int *)0xbc + 3) = 6;
  }
  return param_1;
}



/* Function: FUN_1000_1406 @ 1000:1406 */

undefined2 __cdecl16near FUN_1000_1406(int param_1,int param_2,undefined2 param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  uint uVar7;
  
  FUN_1000_3e4e();
  iVar4 = param_1 * 0xc + *(int *)0xbc;
  iVar5 = (uint)*(byte *)(param_1 * 0xc + *(int *)0xbe + 1) * 0xc + *(int *)0xbc;
  uVar7 = (uint)*(byte *)(iVar4 + 1);
  uVar2 = *(uint *)(iVar4 + 6);
  uVar3 = *(uint *)(iVar4 + 10);
  if (param_2 == 0) {
    if ((uVar3 & 0x4000) == 0) {
      uVar6 = 0xd04d;
    }
    else {
      pbVar1 = (byte *)(iVar4 + 0xb);
      *pbVar1 = *pbVar1 & 0xbf;
      if ((uVar2 & 0x8000) == 0) {
        uVar6 = 0xd04f;
      }
      else {
        pbVar1 = (byte *)(iVar5 + 0xb);
        *pbVar1 = *pbVar1 & 0xbf;
        *(undefined *)(iVar5 + 2) = 4;
        *(undefined *)(iVar4 + 2) = 4;
        uVar6 = 0xd04e;
      }
    }
  }
  else if ((uVar3 & 0x1000) == 0) {
    if ((uVar3 & 0x4000) == 0) {
      pbVar1 = (byte *)(iVar4 + 0xb);
      *pbVar1 = *pbVar1 | 0x40;
      if ((uVar2 & 0x8000) == 0) {
        if ((uVar7 != 0) && ((uVar2 & 0x80) == 0)) {
          FUN_1000_3376(0xd049,param_1);
          FUN_1000_32fa(uVar7);
          return param_3;
        }
        uVar6 = 0xd04a;
      }
      else {
        pbVar1 = (byte *)(iVar5 + 0xb);
        *pbVar1 = *pbVar1 | 0x40;
        *(undefined *)(iVar5 + 2) = 5;
        *(undefined *)(iVar4 + 2) = 5;
        uVar6 = 0xd04b;
      }
    }
    else {
      uVar6 = 0xd048;
    }
  }
  else {
    uVar6 = 0xd046;
  }
  FUN_1000_3376(uVar6,param_1);
  return param_3;
}



/* Function: FUN_1000_1520 @ 1000:1520 */

undefined2 __cdecl16near FUN_1000_1520(int *param_1,undefined2 param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  bool bVar7;
  uint uVar8;
  int iVar9;
  
  FUN_1000_3e4e();
  uVar2 = param_1[6];
  uVar8 = param_1[0x19];
  iVar4 = uVar2 * 0xc + *(int *)0xbc;
  iVar5 = (uint)*(byte *)(uVar2 * 0xc + *(int *)0xbe + 1) * 0xc + *(int *)0xbc;
  uVar3 = *(uint *)(iVar4 + 10);
  bVar7 = *param_1 == 0x4023;
  if ((uVar3 & 0x2000) == 0) {
    uVar6 = 0xd050;
    uVar8 = uVar2;
  }
  else if (((uVar3 & 0x1000) == 0) || (!bVar7)) {
    if (((uVar3 & 0x1000) != 0) || (bVar7)) {
      if ((*(uint *)(iVar4 + 6) & 0x8000) == 0) {
        if (*(byte *)(uVar8 * 0xc + *(int *)0xbc + 1) == uVar2) {
          iVar9 = -0x2fad;
          iVar5 = iVar4;
          FUN_1000_33b8();
          if (iVar9 == 0) goto LAB_1000_165b;
          goto LAB_1000_1616;
        }
      }
      else if (*(byte *)(uVar2 * 0xc + *(int *)0xbe + 9) == uVar8) {
        iVar9 = -0x2fad;
        FUN_1000_33b8();
        if (iVar9 == 0) {
          pbVar1 = (byte *)(iVar4 + 0xb);
          *pbVar1 = *pbVar1 & 0xef;
LAB_1000_165b:
          pbVar1 = (byte *)(iVar5 + 0xb);
          *pbVar1 = *pbVar1 & 0xef;
          return param_2;
        }
        pbVar1 = (byte *)(iVar4 + 0xb);
        *pbVar1 = *pbVar1 | 0x10;
LAB_1000_1616:
        pbVar1 = (byte *)(iVar5 + 0xb);
        *pbVar1 = *pbVar1 | 0x10;
        return param_2;
      }
      uVar6 = 0xd052;
    }
    else {
      uVar6 = 0xd054;
      uVar8 = uVar2;
    }
  }
  else {
    uVar6 = 0xd051;
    uVar8 = uVar2;
  }
  FUN_1000_3376(uVar6,uVar8);
  return param_2;
}



/* Function: FUN_1000_1668 @ 1000:1668 */

undefined2 __cdecl16near FUN_1000_1668(int param_1,undefined2 param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  int iVar7;
  
  FUN_1000_3e4e();
  iVar7 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(param_1 + 0x32);
  iVar5 = iVar7 * 0xc + *(int *)0xbc;
  bVar3 = *(byte *)(iVar5 + 3);
  if ((*(byte *)(iVar5 + 6) & 0x10) == 0) {
    uVar6 = 0xd05a;
  }
  else if ((*(uint *)(iVar4 * 0xc + *(int *)0xbc + 10) & 0x400) == 0) {
    uVar6 = 0xd05c;
    iVar7 = iVar4;
  }
  else {
    if (7 < bVar3) {
      FUN_1000_33b8(0xd05d);
      return param_2;
    }
    pcVar1 = (char *)(iVar5 + 3);
    *pcVar1 = *pcVar1 + '\x01';
    *(undefined *)(iVar5 + 2) = *(undefined *)(iVar5 + 3);
    if (bVar3 != 6) {
      FUN_1000_3376(0xd05f,iVar7);
      pbVar2 = (byte *)(iVar5 + 0xb);
      *pbVar2 = *pbVar2 | 0x40;
      FUN_1000_32fa(*(undefined *)(iVar5 + 1));
      return param_2;
    }
    uVar6 = 0xd05e;
  }
  FUN_1000_3376(uVar6,iVar7);
  return param_2;
}



/* Function: FUN_1000_172c @ 1000:172c */

undefined2 __cdecl16near FUN_1000_172c(int param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  int iVar6;
  
  FUN_1000_3e4e();
  iVar6 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x32);
  iVar3 = iVar6 * 0xc + *(int *)0xbc;
  uVar2 = (uint)*(byte *)(iVar3 + 1);
  iVar4 = uVar2 * 0xc + *(int *)0xbc;
  if ((*(uint *)(iVar1 * 0xc + *(int *)0xbc + 10) & 0x800) == 0) {
    uVar5 = 0xd063;
    iVar6 = iVar1;
  }
  else {
    if (((*(uint *)(iVar4 + 6) & 0x100) == 0) || (uVar2 == 0)) {
      uVar5 = FUN_1000_1fca(param_1,param_2);
      return uVar5;
    }
    *(undefined *)(iVar4 + 1) = 0;
    *(undefined *)(iVar3 + 1) = 0;
    *(undefined *)(iVar3 + 3) = 7;
    *(undefined *)(iVar3 + 8) = 5;
    FUN_1000_3024((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc,iVar6);
    uVar5 = 0xd061;
  }
  FUN_1000_3376(uVar5,iVar6);
  return param_2;
}



/* Function: FUN_1000_17f8 @ 1000:17f8 */

undefined2 __cdecl16near FUN_1000_17f8(undefined2 param_1_00,undefined2 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  char cVar5;
  
  FUN_1000_3e4e();
  uVar2 = (uint)*(byte *)0x6602;
  cVar1 = *(char *)0x6607;
  iVar3 = uVar2 * 0x12 + *(int *)0x5dbc;
  if (cVar1 == '\0') {
    uVar4 = 0xd095;
  }
  else if ((*(byte *)(uVar2 * 0x12 + *(int *)0x5dbc + 2) & 0x40) == 0) {
    cVar5 = -0x69;
    FUN_1000_3376(0xd097,cVar1,iVar3);
    *(undefined *)0x6607 = 0;
    if (cVar5 != '\"') {
      return param_1;
    }
    FUN_1000_2f64(iVar3,0x22);
    FUN_1000_2f64(iVar3,0x55);
    uVar4 = 0xd0c2;
  }
  else {
    uVar4 = 0xd099;
  }
  FUN_1000_33b8(uVar4);
  return param_1;
}



/* Function: FUN_1000_1888 @ 1000:1888 */

undefined2 __cdecl16near FUN_1000_1888(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  int iVar5;
  
  FUN_1000_3e4e();
  iVar5 = *(int *)(param_1 + 0xc);
  iVar3 = iVar5 * 0xc + *(int *)0xbc;
  if (((*(uint *)(iVar3 + 6) & 0x600) == 0) || ((*(uint *)(iVar3 + 10) & 0x800) == 0)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  if ((bVar2 | *(byte *)0x6607) == 0) {
    FUN_1000_3376();
    *(undefined *)0x6607 = (char)iVar5;
    if (iVar5 != 0x22) {
      return param_2;
    }
    pbVar1 = (byte *)0xd0a1;
    *pbVar1 = *pbVar1 | 1;
    *(undefined *)0xd099 = 7;
    *(undefined *)0xd098 = 7;
    uVar4 = 0xd0bf;
  }
  else {
    uVar4 = 0xb017;
  }
  FUN_1000_33b8(uVar4);
  return param_2;
}



/* Function: FUN_1000_1922 @ 1000:1922 */

undefined2 __cdecl16near FUN_1000_1922(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  int iVar6;
  
  FUN_1000_3e4e();
  iVar2 = *(int *)(param_1 + 0xc);
  iVar6 = *(int *)(param_1 + 0x32);
  iVar4 = iVar6 * 0xc + *(int *)0xbc;
  uVar3 = *(uint *)(iVar4 + 10);
  if (*(int *)(param_1 + 0x34) == 0x1006) {
    if (((iVar6 == 0x55) && ((uVar3 & 0x100) != 0)) &&
       ((*(byte *)(iVar2 * 0xc + *(int *)0xbc + 10) & 4) != 0)) {
      *(undefined *)0x6603 = 0;
      pbVar1 = (byte *)0x6605;
      *pbVar1 = *pbVar1 | 4;
      *(undefined *)(iVar4 + 3) = 6;
      *(undefined *)(iVar4 + 2) = 6;
      FUN_1000_2f64(0x6606,iVar2);
      iVar6 = 0x19b4;
      uVar5 = 0xd0c0;
    }
    else {
      if (((*(byte *)(iVar4 + 6) & 8) == 0) || ((uVar3 & 0x400) != 0)) {
        uVar5 = 0xb017;
        goto LAB_1000_19e1;
      }
      uVar5 = 0xd0c1;
    }
    FUN_1000_3376(uVar5,iVar6);
  }
  else {
    uVar5 = 0xd023;
LAB_1000_19e1:
    FUN_1000_33b8(uVar5);
  }
  return param_2;
}



/* Function: FUN_1000_19f0 @ 1000:19f0 */

undefined2 __cdecl16near FUN_1000_19f0(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = *(int *)(param_1 + 0xc);
  if ((*(uint *)(iVar1 * 0xc + *(int *)0xbc + 6) & 8) == 0) {
    FUN_1000_33b8(0xd07d);
  }
  else {
    FUN_1000_3376(0xd077,iVar1);
  }
  return param_2;
}



/* Function: FUN_1000_1a42 @ 1000:1a42 */

undefined2 __cdecl16near FUN_1000_1a42(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  int iVar6;
  
  FUN_1000_3e4e();
  iVar3 = *(int *)(param_1 + 0xc);
  iVar6 = *(int *)(param_1 + 0x32);
  iVar4 = iVar3 * 0xc + *(int *)0xbc;
  bVar2 = *(byte *)(iVar4 + 1);
  if ((*(byte *)(iVar4 + 6) & 2) == 0) {
    uVar5 = 0xd064;
    iVar6 = iVar3;
  }
  else {
    if ((*(byte *)(iVar6 * 0xc + *(int *)0xbc + 10) & 0x80) != 0) {
      pbVar1 = (byte *)(iVar4 + 6);
      *pbVar1 = *pbVar1 & 0xfd;
      pbVar1 = (byte *)((uint)bVar2 * 0xc + *(int *)0xbc + 0xb);
      *pbVar1 = *pbVar1 | 0x40;
      *(undefined *)(iVar4 + 3) = 7;
      *(undefined *)(iVar4 + 2) = 5;
      FUN_1000_3376(0xd066,iVar3);
      FUN_1000_325c(0x1ae2);
      return param_2;
    }
    uVar5 = 0xd065;
  }
  FUN_1000_3376(uVar5,iVar6);
  return param_2;
}



/* Function: FUN_1000_1af6 @ 1000:1af6 */

undefined2 __cdecl16near FUN_1000_1af6(int param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = *(int *)(param_1 + 0xc);
  iVar3 = iVar1 * 0xc + *(int *)0xbc;
  uVar2 = *(uint *)(iVar3 + 6);
  if ((uVar2 & 0x8000) == 0) {
    if ((uVar2 & 9) != 0) {
      uVar4 = FUN_1000_1fca(param_1,param_2,iVar3);
      return uVar4;
    }
    uVar4 = 0xd0a5;
  }
  else {
    if (((*(uint *)(iVar3 + 10) & 0x4000) == 0) && (*(int *)(param_1 + 0x32) == 0)) {
      FUN_1000_33b8(0xb0fa);
      return param_2;
    }
    uVar4 = 0xd0a4;
  }
  FUN_1000_3376(uVar4,iVar1);
  return param_2;
}



/* Function: FUN_1000_1b80 @ 1000:1b80 */

/* WARNING: Removing unreachable block (ram,0x00011c83) */

undefined2 __cdecl16near FUN_1000_1b80(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = *(int *)(param_1 + 0xc) * 0xc + *(int *)0xbc;
  iVar2 = (uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc;
  if (((*(uint *)(iVar1 + 6) & 0x2000) == 0) ||
     ((*(byte *)(iVar1 + 10) & *(byte *)(*(int *)(param_1 + 0x32) * 0xc + *(int *)0xbc + 10) & 8) ==
      0)) {
    FUN_1000_33b8(0xd067);
  }
  else {
    FUN_1000_33b8(0xd06a,iVar2);
    iVar1 = FUN_1000_2e70(iVar2,0x4000,0x200,0x65c2);
    if (iVar1 != 0) {
      puVar3 = (undefined *)((uint)*(byte *)0x65c2 * 0xc + *(int *)0xbc + 1);
      iVar1 = FUN_1000_2e70(puVar3,0x4000,0x80,0x65c2);
      if ((iVar1 != 0) && (iVar1 = FUN_1000_2e70(puVar3,0x4000,0x100,0x65c2), iVar1 != 0)) {
        FUN_1000_3376(0xd06b,*(undefined *)0x65c2);
        *puVar3 = 0xe3;
      }
    }
  }
  return param_2;
}



/* Function: FUN_1000_1c9a @ 1000:1c9a */

undefined2 __cdecl16near FUN_1000_1c9a(int param_1,undefined2 param_2)

{
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  if ((*(byte *)(*(int *)(param_1 + 0xc) * 0xc + *(int *)0xbc + 6) & 0x20) == 0) {
    FUN_1000_33b8(0xd04c,param_1 + 2);
  }
  else {
    param_2 = FUN_1000_25dc(param_1,param_2,*(undefined2 *)(param_1 + 0xc));
  }
  return param_2;
}



/* Function: FUN_1000_1cea @ 1000:1cea */

undefined2 __cdecl16near FUN_1000_1cea(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x32);
  iVar4 = iVar2 * 0xc + *(int *)0xbc;
  iVar5 = iVar3 * 0xc + *(int *)0xbc;
  if (((*(uint *)(iVar4 + 6) & 0x4000) == 0) || ((*(uint *)(iVar4 + 10) & 0x800) == 0)) {
    FUN_1000_33b8(0xd04c,param_1 + 2);
  }
  else if ((*(uint *)(iVar4 + 10) & 0x400) == 0) {
    if (((*(uint *)(iVar5 + 6) & 0x4000) == 0) || ((*(uint *)(iVar5 + 10) & 0x400) == 0)) {
      FUN_1000_3376(0xd074,iVar3);
    }
    else {
      FUN_1000_3376(0xd075,iVar2);
      pbVar1 = (byte *)(iVar4 + 0xb);
      *pbVar1 = *pbVar1 | 4;
      *(undefined *)(iVar4 + 3) = 7;
    }
  }
  else {
    FUN_1000_33b8(0xd06c);
  }
  return param_2;
}



/* Function: FUN_1000_1da8 @ 1000:1da8 */

undefined2 __cdecl16near FUN_1000_1da8(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar3 = *(int *)(param_1 + 0xc) * 0xc + *(int *)0xbc;
  uVar2 = *(uint *)(iVar3 + 10);
  if ((((*(uint *)(iVar3 + 6) & 0x4000) == 0) || ((uVar2 & 0x800) == 0)) || ((uVar2 & 0x400) == 0))
  {
    FUN_1000_33b8(0xd057);
  }
  else {
    FUN_1000_33b8(0xd03d);
    pbVar1 = (byte *)(iVar3 + 0xb);
    *pbVar1 = *pbVar1 & 0xfb;
    *(undefined *)(iVar3 + 3) = 6;
  }
  return param_2;
}



/* Function: FUN_1000_1e1a @ 1000:1e1a */

undefined2 __cdecl16near FUN_1000_1e1a(int *param_1,undefined2 param_2)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  int iVar7;
  
  FUN_1000_3e4e();
  iVar2 = param_1[6];
  iVar5 = iVar2 * 0xc + *(int *)0xbc;
  uVar3 = *(uint *)(iVar5 + 6);
  uVar4 = *(uint *)(iVar5 + 10);
  bVar6 = *param_1 == 0x4025;
  if ((((uVar3 & 0x40) != 0) && (bVar6)) || (((uVar3 & 0x20) != 0 && (!bVar6)))) {
    iVar7 = 0x6606;
    FUN_1000_2f64(0x6606,iVar2,iVar5);
    pcVar1 = (char *)0x6604;
    *pcVar1 = *pcVar1 - *(char *)(iVar7 * 0xc + *(int *)0xbc + 9);
    FUN_1000_33b8(0xd070);
    if ((uVar4 & 0x800) == 0) {
      if ((uVar4 & 0x80) != 0) {
        FUN_1000_33b8(0xb0aa);
      }
    }
    else {
      param_2 = FUN_1000_1ee8(0xd073,0);
    }
  }
  else {
    FUN_1000_33b8(0xd04c,param_1 + 1);
  }
  return param_2;
}



/* Function: FUN_1000_1ee8 @ 1000:1ee8 */

undefined2 __cdecl16near FUN_1000_1ee8(undefined2 param_1,undefined2 param_2)

{
  byte *pbVar1;
  undefined2 uVar2;
  undefined2 unaff_SI;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  *(undefined *)0x660a = 0;
  FUN_1000_3376(param_1,param_2);
  if ((*(byte *)0x6605 & 0x10) == 0) {
    pbVar1 = (byte *)0x6605;
    *pbVar1 = *pbVar1 | 0x10;
    uVar2 = FUN_1000_22da(*(undefined *)0x6602,0x79,0xd12c,1,unaff_SI);
  }
  else {
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* Function: FUN_1000_1f40 @ 1000:1f40 */

undefined2 __cdecl16near FUN_1000_1f40(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = iVar1 * 0xc + *(int *)0xbc;
  if ((iVar1 == 6) && (*(char *)(iVar2 + 3) != '\a')) {
    FUN_1000_33b8(0xd0a1);
    *(undefined *)((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc + 0xc) = 6;
    *(undefined *)(iVar2 + 2) = 7;
    *(undefined *)(iVar2 + 3) = 7;
  }
  else if (*(char *)(iVar2 + 8) == -1) {
    FUN_1000_33b8(0xb017);
  }
  else {
    FUN_1000_33b8(0xd04c,param_1 + 2);
  }
  return param_2;
}



/* Function: FUN_1000_1fca @ 1000:1fca */

undefined2 __cdecl16near FUN_1000_1fca(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x32);
  iVar5 = iVar2 * 0xc + *(int *)0xbc;
  iVar1 = *(int *)0xbc;
  uVar4 = *(uint *)(iVar5 + 10);
  if ((*(byte *)(iVar5 + 6) & 8) == 0) {
    if (iVar2 == 0xf5) {
      param_2 = FUN_1000_1ee8(0xd026,0);
      goto LAB_1000_20ac;
    }
    uVar6 = 0xb017;
  }
  else if (((iVar2 == 0x16) && ((*(uint *)(iVar3 * 0xc + *(int *)0xbc + 10) & 0x100) != 0)) &&
          (*(char *)0x6609 == '\0')) {
    *(undefined *)(iVar1 + 0x109) = 0x15;
    *(undefined *)(iVar1 + 0x10b) = 7;
    *(undefined2 *)(iVar1 + 0x10e) = 0x200;
    uVar6 = 0xd069;
  }
  else {
    if (((uVar4 & 0x200) != 0) || (iVar2 == 0x16)) {
      FUN_1000_3376(0xd0ae,iVar3);
      goto LAB_1000_20ac;
    }
    if ((uVar4 & 0x400) == 0) {
      FUN_1000_33b8(0xd0a7,param_1 + 2);
      goto LAB_1000_20ac;
    }
    uVar6 = 0xd0a2;
  }
  FUN_1000_33b8(uVar6);
LAB_1000_20ac:
  *(undefined *)0x6608 = 4;
  return param_2;
}



/* Function: FUN_1000_20ba @ 1000:20ba */

undefined2 __cdecl16near FUN_1000_20ba(int param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  uVar1 = *(uint *)(param_1 + 0xc);
  iVar2 = FUN_1000_358c(uVar1 | 0xc000,uVar1);
  if (iVar2 == 0) {
    FUN_1000_33b8(0xd016);
  }
  return param_2;
}



/* Function: FUN_1000_20f2 @ 1000:20f2 */

undefined2 __cdecl16near FUN_1000_20f2(int *param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  uint local_a;
  undefined2 uVar5;
  uint uVar6;
  
  FUN_1000_3e4e();
  iVar1 = param_1[6];
  uVar6 = param_1[7];
  uVar2 = param_1[0x13];
  uVar3 = *(uint *)(iVar1 * 0xc + *(int *)0xbc + 6);
  uVar5 = 0;
  local_a = 0;
  if ((*param_1 == 0x401f) && (uVar6 == 0)) {
    uVar6 = 0x9009;
  }
  uVar4 = uVar6;
  if ((uVar6 == 0x9009) || (uVar6 == 0x900a)) {
    if ((uVar2 != 0) && ((uVar3 & 0x1000) == 0)) {
      uVar5 = 0xd056;
      uVar4 = local_a;
    }
  }
  else if ((uVar6 == 0x900b) || (uVar6 == 0x900c)) {
    if ((uVar2 != 0) && ((uVar3 & 0x800) == 0)) {
      uVar5 = 0xd057;
      uVar4 = local_a;
    }
  }
  else {
    if (uVar6 == 0x1008) {
      if (uVar2 != 0) {
        uVar5 = 0xd055;
        uVar4 = local_a;
        goto LAB_1000_21ad;
      }
    }
    else {
      if (uVar6 != 0) {
        uVar6 = 0x1006;
      }
      uVar4 = uVar2;
      if ((uVar2 & 0x8000) != 0) goto LAB_1000_21ad;
    }
    uVar5 = 0xb017;
    uVar4 = local_a;
  }
LAB_1000_21ad:
  local_a = uVar4;
  if (local_a == 0) {
    FUN_1000_3376(uVar5,iVar1,uVar6);
  }
  else {
    param_2 = FUN_1000_21ee(local_a,param_2);
  }
  return param_2;
}



/* Function: FUN_1000_21ee @ 1000:21ee */

uint __cdecl16near FUN_1000_21ee(byte param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined2 unaff_DS;
  byte bVar4;
  
  FUN_1000_3e4e();
  bVar4 = (byte)(0x1000 >> (param_1 & 0x1f));
  iVar3 = FUN_1000_2e70(*(int *)0x5dbc + 0xda4,0x8400);
  if ((iVar3 == 0) || ((*(uint *)((uint)*(byte *)0x65c2 * 0xc + *(int *)0xbe + 10) & 0x4000) != 0))
  {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  bVar1 = *(byte *)0x6605;
  if (((bVar1 & 1) == 0) && (bVar2)) {
    FUN_1000_3376(0xd055,*(undefined *)0x65c2);
  }
  else {
    if ((bVar2) && ((bVar1 & 1) != 0)) {
      bVar4 = 0xff;
    }
    if ((*(char *)0x6607 != '\0') && (bVar4 < 200)) {
      FUN_1000_17f8(0x5b64,param_2);
    }
    param_2 = FUN_1000_22da(param_2 & 0xff,0,0);
  }
  return param_2;
}



/* Function: FUN_1000_22da @ 1000:22da */

undefined2 __cdecl16near
FUN_1000_22da(byte param_1,byte param_2,uint param_3,char param_4,undefined2 param_5)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 unaff_DS;
  byte bVar6;
  uint uVar7;
  uint in_stack_0000fffa;
  uint uVar8;
  
  FUN_1000_3e4e();
  uVar7 = (uint)param_1;
  uVar8 = (uint)*(byte *)((uint)param_2 * 0x12 + *(int *)0x5dbc + 2);
  bVar3 = *(byte *)0x6605;
  if (param_3 != 0) {
    uVar7 = 0x2310;
    FUN_1000_33b8(param_3);
    in_stack_0000fffa = param_3;
  }
  if (param_4 != '\0') {
    param_5 = 1;
    *(undefined2 *)0x5b8a = 0xffff;
    in_stack_0000fffa = 1;
    uVar7 = 0x5b64;
    bVar3 = 0x2c;
    FUN_1000_2a5e(0x5b64,1);
  }
  if (param_2 < 200) {
    uVar7 = (uint)param_2;
    *(byte *)0x6602 = param_2;
    iVar5 = (uint)param_2 * 0x12 + *(int *)0x5dbc;
    bVar6 = *(byte *)(iVar5 + 1);
    pcVar1 = (char *)(iVar5 + 1);
    *pcVar1 = *pcVar1 + '\x01';
    if (((bVar6 & 3) == 0) || (*(int *)0xf8 == 0)) {
      in_stack_0000fffa = 1;
    }
    else {
      in_stack_0000fffa = 0;
    }
  }
  bVar6 = (byte)uVar7;
  if (((*(byte *)((uVar7 & 0xff) * 0x12 + *(int *)0x5dbc + 2) & 1) != 0) || ((bVar3 & 8) != 0)) {
    in_stack_0000fffa = 0x237f;
    iVar5 = FUN_1000_2e28();
    if (iVar5 == 0) {
      if ((bVar3 & 1) != 0) {
        uVar4 = FUN_1000_1ee8(0xd080,0);
        return uVar4;
      }
      uVar4 = 0xd07f;
      goto LAB_1000_243b;
    }
  }
  if (bVar6 == param_2) {
    if (((*(byte *)((uint)param_1 * 0x12 + *(int *)0x5dbc + 2) & 1) != 0) && ((uVar8 & 1) == 0)) {
      if ((bVar3 & 8) == 0) {
        in_stack_0000fffa = 0xd0e6;
      }
      else {
        in_stack_0000fffa = 0xd0e5;
      }
      FUN_1000_33b8(in_stack_0000fffa);
    }
    if (((*(byte *)((uint)param_1 * 0x12 + *(int *)0x5dbc + 2) & 4) == 0) && ((uVar8 & 4) != 0)) {
      in_stack_0000fffa = *(int *)0xf6 + 0xb4U | 0xd000;
      FUN_1000_33b8(in_stack_0000fffa);
    }
    FUN_1000_3082(in_stack_0000fffa);
    FUN_1000_3444((uint)param_2 * 0x12 + *(int *)0x5dbc);
    if ((uVar8 & 0x20) == 0) {
      return param_5;
    }
    pcVar1 = (char *)0x660b;
    *pcVar1 = *pcVar1 + '\x01';
    pbVar2 = (byte *)((uint)param_2 * 0x12 + *(int *)0x5dbc + 2);
    *pbVar2 = *pbVar2 & 0xdf;
    return param_5;
  }
  uVar4 = CONCAT11(0xe0,param_2);
LAB_1000_243b:
  FUN_1000_33b8(uVar4);
  return param_5;
}



/* Function: FUN_1000_244a @ 1000:244a */

int __cdecl16near FUN_1000_244a(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  FUN_1000_3e4e();
  piVar7 = (int *)param_1[7];
  piVar4 = (int *)0x0;
  if (*param_1 == 0x4002) {
    piVar7 = (int *)0x100d;
  }
  if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)0x9009)) || (piVar7 == (int *)0x900a)) ||
     (piVar7 == (int *)0x1011)) {
    FUN_1000_3082(1);
    return param_2;
  }
  if (param_1[0x13] == 0) {
    piVar7 = param_1 + 8;
    piVar4 = param_1 + 6;
    param_2 = FUN_1000_0c1c(piVar4,param_1 + 1);
  }
  if (param_2 == 0) {
    return 0;
  }
  if (param_2 == 3) {
    return 3;
  }
  uVar6 = param_1[6];
  iVar2 = uVar6 * 0xc + *(int *)0xbc;
  uVar1 = *(uint *)(iVar2 + 6);
  uVar8 = *(uint *)(iVar2 + 10);
  uVar3 = (uint)*(byte *)(iVar2 + 3) << 0xc;
  uVar5 = uVar6;
  if (piVar7 == (int *)0x900b) {
    if ((uVar1 & 0x400) == 0) {
      piVar4 = (int *)0x9;
      goto LAB_1000_254a;
    }
    if (((uVar1 & 0x80) != 0) || ((uVar8 & 0x4000) != 0)) {
      uVar5 = 0x253e;
      iVar2 = FUN_1000_325c(uVar6);
      if (iVar2 == 0) {
        piVar4 = (int *)0x8;
      }
      goto LAB_1000_254a;
    }
  }
  else {
    if (piVar7 == (int *)0x1004) {
      uVar5 = 0x256e;
      iVar2 = FUN_1000_325c(uVar6);
      if (iVar2 == 0) {
        piVar4 = (int *)0x10;
      }
      goto LAB_1000_254a;
    }
    if (piVar7 == (int *)0x1008) {
      if (param_1[0x13] == *(int *)0xf2) {
        uVar5 = 0x258e;
        FUN_1000_358c(uVar3 | uVar6);
      }
      else if ((uVar1 & 0x80) == 0) {
        piVar4 = (int *)0xd;
      }
      else {
        piVar4 = (int *)0xe;
      }
      goto LAB_1000_254a;
    }
    if (piVar7 != (int *)0x100d) {
      piVar4 = (int *)0x3c;
      goto LAB_1000_254a;
    }
    uVar3 = uVar3 | uVar6;
    uVar6 = 0x25b4;
    iVar2 = FUN_1000_358c(uVar3);
    uVar5 = uVar6;
    if (iVar2 != 0) goto LAB_1000_254a;
    if ((uVar8 & 0x8000) == 0) {
      piVar4 = (int *)0xa;
      goto LAB_1000_254a;
    }
    if ((uVar8 & 0x4000) != 0) {
      piVar4 = (int *)0x58;
      goto LAB_1000_254a;
    }
  }
  piVar4 = (int *)0x59;
  uVar5 = uVar6;
LAB_1000_254a:
  if (piVar4 != (int *)0x0) {
    FUN_1000_3376((uint)piVar4 | 0xd000,uVar5);
  }
  return param_2;
}



/* Function: FUN_1000_25dc @ 1000:25dc */

undefined2 __cdecl16near FUN_1000_25dc(int param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_DS;
  uint local_e;
  
  FUN_1000_3e4e();
  uVar1 = *(uint *)(param_1 + 0xe);
  uVar2 = *(uint *)(param_1 + 0x34);
  uVar3 = *(undefined2 *)(param_1 + 0xc);
  uVar4 = *(uint *)(param_1 + 0x32);
  iVar5 = uVar4 * 0xc + *(int *)0xbc;
  if (((*(uint *)(param_1 + 0x4c) | uVar2 | uVar1) == 0x900a) && ((uVar2 & uVar1) == 0)) {
    param_2 = FUN_1000_2a5e(param_1,param_2);
  }
  else if (uVar1 == 0x900c) {
    param_2 = FUN_1000_1da8(param_1,param_2);
  }
  else if ((((uVar1 == 0) && (uVar2 != 0)) && ((uVar2 == 0x900b || (uVar2 == 0x1004)))) &&
          (*(int *)(param_1 + 0x4c) != 0)) {
    if (*(int *)(param_1 + 0x26) == *(int *)0xf0) {
      uVar1 = (uint)*(byte *)0x6606;
      if (uVar1 == 0xf5) {
        FUN_1000_33b8(0xd03b);
      }
      else {
        while (local_e = uVar1, local_e != 0xf5) {
          uVar1 = (uint)*(byte *)(local_e * 0xc + *(int *)0xbc);
          if (local_e != uVar4) {
            iVar5 = 0x26d0;
            FUN_1000_2748(local_e,uVar4);
            uVar1 = local_e;
          }
        }
      }
    }
    else {
      iVar5 = 0x26fa;
      FUN_1000_2748(uVar3,uVar4,uVar2 == 0x900b);
    }
    iVar5 = iVar5 + 1;
    iVar6 = FUN_1000_2e70(iVar5,0x60,0x200,0x65c2);
    if (((iVar6 == 9) && (uVar4 == 0x2f)) && (*(char *)(iVar5 + 3) == '\a')) {
      FUN_1000_3376(0xd08e,0x2f);
      *(undefined *)(iVar5 + 1) = 0xa0;
    }
  }
  else {
    param_2 = 1;
    FUN_1000_3376(0xd03c,uVar3);
  }
  return param_2;
}



/* Function: FUN_1000_2748 @ 1000:2748 */

void __cdecl16near FUN_1000_2748(uint param_1,int param_2,int param_3)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  uint uVar7;
  
  FUN_1000_3e4e();
  iVar4 = param_2 * 0xc + *(int *)0xbc;
  uVar3 = *(uint *)(iVar4 + 6);
  uVar7 = 0;
  if (param_3 == 0) {
    uVar7 = uVar3 & 0x200;
    if (uVar7 != 0) goto LAB_1000_2800;
    uVar6 = 0xd041;
  }
  else {
    if ((uVar3 & 0x400) == 0) {
      FUN_1000_3376(0xd03f,param_2);
      goto LAB_1000_2800;
    }
    if ((*(uint *)(iVar4 + 10) & 0x4000) != 0) {
      uVar7 = 1;
      if (param_1 == 0x89) {
        pcVar1 = (char *)0x6604;
        *pcVar1 = *pcVar1 + '\x01';
        param_1 = 0xde;
        FUN_1000_3024(0x6606,0xde);
      }
      goto LAB_1000_2800;
    }
    uVar6 = 0xd040;
  }
  FUN_1000_33b8(uVar6);
LAB_1000_2800:
  if (uVar7 == 0) {
    return;
  }
  uVar7 = 0x280d;
  iVar5 = FUN_1000_2dd0(param_1);
  if ((iVar5 == 0) && (uVar7 = param_1, iVar5 = FUN_1000_2c1e(param_1,1), iVar5 == 0)) {
    return;
  }
  if (*(byte *)(uVar7 + 8) < *(byte *)(iVar4 + 8)) {
    iVar5 = 0x6606;
    uVar7 = param_1;
    FUN_1000_2f64();
    if ((*(byte *)(iVar5 + 6) & 0x20) != 0) {
      FUN_1000_3376(0xd08c,param_2);
      if (param_1 != 0xa0) {
        return;
      }
      if (param_2 == 4) {
        *(undefined *)(iVar4 + 3) = 7;
        FUN_1000_33b8(0xd08d);
        FUN_1000_3024(0x6606,2);
        return;
      }
      return;
    }
    if ((((uVar3 & 0x4000) == 0) || ((uVar7 & 0x200) == 0)) || (*(char *)(iVar4 + 1) != -0x1d)) {
      iVar5 = -0x2fd0;
      FUN_1000_3376(0xd030,param_1);
      pcVar1 = (char *)0x6604;
      *pcVar1 = *pcVar1 - *(char *)(iVar5 + 9);
      if ((param_1 == 0x1f) && (param_2 == 0x17)) {
        FUN_1000_33b8(0xd0be);
        param_1 = 0x80;
      }
      FUN_1000_3024(iVar4 + 1,param_1);
      if (param_1 != 4) {
        return;
      }
      if (param_2 != 0x1b) {
        return;
      }
      iVar4 = 0x2901;
      FUN_1000_33b8(0xd0a6);
      pbVar2 = (byte *)(*(int *)0xbc + 0x7af);
      *pbVar2 = *pbVar2 & 0xef;
      *(undefined *)(iVar4 + 8) = 0xfa;
      return;
    }
    uVar6 = 0xd08f;
  }
  else {
    uVar6 = 0xd03e;
  }
  FUN_1000_3376(uVar6,param_1);
  return;
}



/* Function: FUN_1000_291a @ 1000:291a */

undefined2 __cdecl16near FUN_1000_291a(int param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  uVar1 = *(uint *)(param_1 + 0xe);
  uVar2 = *(uint *)(param_1 + 0x34);
  if (((uVar2 | uVar1) == 0x9009) && ((uVar2 & uVar1) == 0)) {
    param_2 = FUN_1000_2960(param_1,param_2);
  }
  else {
    FUN_1000_33b8(0xd023);
  }
  return param_2;
}



/* Function: FUN_1000_2960 @ 1000:2960 */

undefined2 __cdecl16near FUN_1000_2960(int param_1,undefined2 param_2)

{
  uint uVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  undefined2 unaff_DS;
  uint local_a;
  
  FUN_1000_3e4e();
  bVar2 = false;
  if (*(int *)(param_1 + 0x26) == *(int *)0xf0) {
    uVar4 = (uint)*(byte *)((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc);
    while (uVar4 != 0) {
      pbVar3 = (byte *)(uVar4 * 0xc + *(int *)0xbc);
      uVar1 = (uint)*pbVar3;
      if (pbVar3[8] < 200) {
        FUN_1000_2c1e(uVar4,0);
        uVar4 = uVar1;
        bVar2 = true;
      }
      else {
        uVar4 = uVar1;
        if (((*(uint *)(pbVar3 + 6) & 0x200) != 0) ||
           (((*(uint *)(pbVar3 + 6) & 0x400) != 0 && ((*(uint *)(pbVar3 + 10) & 0x4000) != 0)))) {
          local_a = (uint)pbVar3[1];
          while (local_a != 0) {
            uVar1 = 0;
            FUN_1000_2c1e(local_a);
            local_a = uVar1;
            bVar2 = true;
          }
        }
      }
    }
    if (!bVar2) {
      FUN_1000_33b8(0xd03a);
    }
  }
  else {
    FUN_1000_2c1e(*(undefined2 *)(param_1 + 0xc),0);
  }
  return param_2;
}



/* Function: FUN_1000_2a5e @ 1000:2a5e */

undefined2 __cdecl16near FUN_1000_2a5e(int param_1,undefined2 param_2)

{
  uint uVar1;
  undefined2 unaff_DS;
  bool bVar2;
  uint local_a;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_1000_3e4e();
  iVar5 = *(int *)(param_1 + 0x26);
  bVar2 = iVar5 == -1;
  if (bVar2) {
    iVar5 = *(int *)0xf0;
  }
  uVar4 = (uint)bVar2;
  if (iVar5 == *(int *)0xf0) {
    local_a = (uint)*(byte *)0x6606;
    if (local_a == 0xf5) {
      if (uVar4 == 0) {
        FUN_1000_33b8(0xd03b);
      }
    }
    else {
      while (local_a != 0xf5) {
        uVar3 = local_a;
        uVar1 = (uint)*(byte *)(local_a * 0xc + *(int *)0xbc);
        FUN_1000_2d34(local_a,uVar4);
        local_a = uVar1;
        uVar4 = uVar3;
      }
    }
  }
  else {
    FUN_1000_2d34(*(undefined2 *)(param_1 + 0xc),uVar4);
  }
  return param_2;
}



/* Function: FUN_1000_2b00 @ 1000:2b00 */

undefined2 __cdecl16near FUN_1000_2b00(int *param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  FUN_1000_3e4e();
  iVar1 = param_1[6];
  bVar2 = *param_1 == 0x4016;
  if ((*(uint *)(iVar1 * 0xc + *(int *)0xbc + 10) & 0x8000) == 0) {
    FUN_1000_3376(0xd047,iVar1,bVar2);
  }
  else {
    param_2 = FUN_1000_1406(param_2,bVar2);
  }
  return param_2;
}



/* Function: FUN_1000_2b68 @ 1000:2b68 */

undefined2 __cdecl16near FUN_1000_2b68(int *param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  FUN_1000_3e4e();
  iVar1 = param_1[6];
  iVar4 = iVar1 * 0xc + *(int *)0xbc;
  uVar2 = *(uint *)(iVar4 + 10);
  iVar3 = *param_1;
  if (((*(uint *)(iVar4 + 6) & 0x2000) == 0) ||
     (((iVar3 != 0x401a || ((uVar2 & 0x20) == 0)) && ((iVar3 != 0x400a || ((uVar2 & 0x40) == 0))))))
  {
    FUN_1000_33b8(0xd04c,param_1 + 1);
  }
  else {
    bVar5 = (*(uint *)((uint)*(byte *)(iVar1 * 0xc + *(int *)0xbc + 1) * 0xc + *(int *)0xbc + 10) &
            0x4000) == 0;
    param_2 = FUN_1000_1406(param_2,bVar5,param_2,bVar5);
  }
  return param_2;
}



/* Function: FUN_1000_2c1e @ 1000:2c1e */

undefined2 __cdecl16near FUN_1000_2c1e(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  uint uVar4;
  undefined2 uVar5;
  
  FUN_1000_3e4e();
  uVar5 = 0;
  uVar4 = param_1;
  iVar2 = FUN_1000_2dd0();
  if (iVar2 == 0) {
    if ((*(byte *)(param_1 * 0xc + *(int *)0xbc + 8) < 200) &&
       (((uVar4 & 0x20) == 0 || (param_2 != 0)))) {
      if ((uint)*(byte *)(param_1 * 0xc + *(int *)0xbc + 9) + (uint)*(byte *)0x6604 < 0x65) {
        iVar2 = FUN_1000_2f64((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc,param_1);
        if ((iVar2 == 0) && (iVar2 = FUN_1000_2f64(0x6606,param_1), iVar2 == 0)) {
          uVar3 = 0xd035;
        }
        else {
          FUN_1000_3024(0x6606,param_1);
          *(undefined *)(param_1 * 0xc + *(int *)0xbc + 2) = 4;
          pcVar1 = (char *)0x6604;
          *pcVar1 = *pcVar1 + *(char *)(param_1 * 0xc + *(int *)0xbc + 9);
          uVar5 = 1;
          if (param_2 != 0) {
            return 1;
          }
          uVar3 = 0xd033;
        }
      }
      else {
        uVar3 = 0xd037;
      }
    }
    else {
      uVar3 = 0xd034;
    }
  }
  else {
    uVar3 = 0xd036;
  }
  FUN_1000_3376(uVar3,param_1);
  return uVar5;
}



/* Function: FUN_1000_2d34 @ 1000:2d34 */

undefined2 __cdecl16near FUN_1000_2d34(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined2 uVar4;
  
  FUN_1000_3e4e();
  uVar4 = 0;
  iVar2 = FUN_1000_2dd0(param_1);
  if (iVar2 == 0) {
    uVar3 = 0xd038;
  }
  else {
    if (199 < *(byte *)(param_1 * 0xc + *(int *)0xbc + 8)) {
      FUN_1000_33b8(0xb017);
      return uVar4;
    }
    FUN_1000_2f64(0x6606,param_1);
    FUN_1000_3024((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc,param_1);
    pcVar1 = (char *)0x6604;
    *pcVar1 = *pcVar1 - *(char *)(param_1 * 0xc + *(int *)0xbc + 9);
    uVar4 = 1;
    if (param_2 != 0) {
      return 1;
    }
    uVar3 = 0xd039;
  }
  FUN_1000_3376(uVar3,param_1);
  return uVar4;
}



/* Function: FUN_1000_2dd0 @ 1000:2dd0 */

bool __cdecl16near FUN_1000_2dd0(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  FUN_1000_3e4e();
  bVar3 = true;
  bVar1 = *(byte *)0x6606;
  while ((uVar2 = (uint)bVar1, uVar2 != 0 && (bVar3 = uVar2 != param_1, bVar3))) {
    bVar1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc);
  }
  return !bVar3;
}



/* Function: FUN_1000_2e28 @ 1000:2e28 */

int __cdecl16near FUN_1000_2e28(void)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = FUN_1000_2e70((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc,0x4000,0x400,0x65c2);
  iVar2 = FUN_1000_2e70(0x6606,0x4000,0x400,0x65c2);
  return iVar1 + iVar2;
}



/* Function: FUN_1000_2e70 @ 1000:2e70 */

int __cdecl16near FUN_1000_2e70(byte *param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined2 unaff_DS;
  uint local_6;
  int iVar3;
  
  FUN_1000_3e4e();
  iVar3 = 0;
  bVar1 = *param_1;
  while (local_6 = (uint)bVar1, local_6 != 0) {
    if (((param_2 == 0) || ((*(uint *)(local_6 * 0xc + *(int *)0xbc + 6) & param_2) != 0)) &&
       ((param_3 == 0 || ((*(uint *)(local_6 * 0xc + *(int *)0xbc + 10) & param_3) != 0)))) {
      *(byte *)(iVar3 + param_4) = bVar1;
      iVar3 = iVar3 + 1;
    }
    iVar2 = local_6 * 0xc + *(int *)0xbc;
    if ((((*(uint *)(iVar2 + 6) & 0x400) != 0) && ((*(uint *)(iVar2 + 10) & 0x4000) != 0)) ||
       ((*(uint *)(local_6 * 0xc + *(int *)0xbc + 6) & 0x380) != 0)) {
      local_6 = iVar3 + param_4;
      iVar2 = FUN_1000_2e70(local_6 * 0xc + *(int *)0xbc + 1,param_2,param_3);
      iVar3 = iVar3 + iVar2;
    }
    bVar1 = *(byte *)(local_6 * 0xc + *(int *)0xbc);
  }
  return iVar3;
}



/* Function: FUN_1000_2f64 @ 1000:2f64 */

int __cdecl16near FUN_1000_2f64(byte *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  bVar1 = *param_1;
  while( true ) {
    uVar2 = (uint)bVar1;
    if (bVar1 == 0) {
      return 0;
    }
    if (param_2 == uVar2) break;
    iVar3 = uVar2 * 0xc + *(int *)0xbc;
    if (((((*(uint *)(iVar3 + 10) & 0x4000) != 0) || ((*(uint *)(iVar3 + 6) & 0x200) != 0)) &&
        (iVar3 = uVar2 * 0xc + *(int *)0xbc, (*(uint *)(iVar3 + 6) & 0x8000) == 0)) &&
       (iVar3 = FUN_1000_2f64(iVar3 + 1,param_2), iVar3 != 0)) {
      return iVar3;
    }
    param_1 = (byte *)(uVar2 * 0xc + *(int *)0xbc);
    bVar1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc);
  }
  *param_1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc);
  return 1;
}



/* Function: FUN_1000_3024 @ 1000:3024 */

undefined2 __cdecl16near FUN_1000_3024(byte *param_1,byte param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  bVar3 = *param_1;
  pbVar4 = (byte *)((uint)param_2 * 0xc + *(int *)0xbc + 6);
  if ((*pbVar4 & 4) != 0) {
    pcVar1 = (char *)0x660b;
    *pcVar1 = *pcVar1 + '\x01';
    pbVar2 = pbVar4;
    *pbVar2 = *pbVar2 & 0xfb;
  }
  *(byte *)((uint)param_2 * 0xc + *(int *)0xbc) = bVar3;
  *param_1 = param_2;
  return 1;
}



/* Function: FUN_1000_3082 @ 1000:3082 */

void __cdecl16near FUN_1000_3082(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint unaff_DS;
  
  FUN_1000_3e4e();
  uVar1 = (uint)*(byte *)0x6602;
  FUN_1000_3908(uVar1,0x5f4e);
  FUN_1000_3740(0,0);
  FUN_1570_062a(1,1);
  FUN_1570_05d4(0x460);
  FUN_1570_062a(1,1);
  uVar2 = unaff_DS;
  FUN_1570_05d4();
  if (*(char *)0x6607 != '\0') {
    uVar2 = (uint)*(byte *)0x6607;
    FUN_1000_3376(0xd098,uVar2);
  }
  if (param_1 == 0) {
    FUN_1000_33b8(0xd024,uVar2);
  }
  else {
    FUN_1000_358c((uint)*(byte *)(uVar1 * 0x12 + *(int *)0x5dbc + 3) << 0xc | uVar1);
  }
  FUN_1000_31ae(uVar1 * 0x12 + *(int *)0x5dbc);
  return;
}



/* Function: FUN_1000_314a @ 1000:314a */

void __cdecl16near FUN_1000_314a(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  uVar1 = (uint)*(byte *)0x6606;
  FUN_1000_33b8(0xd032);
  if (uVar1 == 0xf5) {
    FUN_1000_33b8(0xd031);
    return;
  }
  FUN_1000_32fa(uVar1);
  for (; uVar1 != 0; uVar1 = (uint)*(byte *)(uVar1 * 0xc + *(int *)0xbc)) {
    FUN_1000_325c(uVar1);
  }
  return;
}



/* Function: FUN_1000_31ae @ 1000:31ae */

void __cdecl16near FUN_1000_31ae(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  bVar1 = *param_1;
  while (uVar2 = (uint)bVar1, uVar2 != 0) {
    bVar1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc + 2);
    if (bVar1 != 4) {
      FUN_1000_358c((uint)bVar1 << 0xc | uVar2);
    }
    bVar1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc);
  }
  bVar1 = *param_1;
  while (uVar2 = (uint)bVar1, bVar1 != 0) {
    iVar3 = uVar2 * 0xc + *(int *)0xbc;
    if ((*(char *)(iVar3 + 8) != -1) && (*(char *)(iVar3 + 2) == '\x04')) {
      FUN_1000_3376(0xd012,uVar2);
    }
    FUN_1000_325c(uVar2);
    bVar1 = *(byte *)(uVar2 * 0xc + *(int *)0xbc);
  }
  return;
}



/* Function: FUN_1000_325c @ 1000:325c */

uint __cdecl16near FUN_1000_325c(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  uint local_8;
  uint local_6;
  
  FUN_1000_3e4e();
  iVar3 = param_1 * 0xc + *(int *)0xbc;
  uVar2 = *(uint *)(iVar3 + 6);
  local_6 = 0;
  bVar1 = *(byte *)(iVar3 + 1);
  local_8 = (uint)bVar1;
  if (bVar1 != 0) {
    if ((uVar2 & 0x200) == 0) {
      if (((uVar2 & 0x400) == 0) ||
         (((*(uint *)(param_1 * 0xc + *(int *)0xbc + 10) & 0x4000) == 0 && ((uVar2 & 0x80) == 0))))
      {
        local_6 = 0;
      }
      else {
        local_6 = 1;
      }
      if (local_6 == 0) goto LAB_1000_32e2;
      local_8 = 0xd00b;
    }
    else {
      local_8 = 0xd013;
    }
    local_6 = param_1;
    FUN_1000_3376();
  }
LAB_1000_32e2:
  if (local_6 != 0) {
    local_6 = local_8;
    FUN_1000_32fa();
  }
  return local_6;
}



/* Function: FUN_1000_32fa @ 1000:32fa */

void __cdecl16near FUN_1000_32fa(uint param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  for (; param_1 != 0; param_1 = (uint)*(byte *)(param_1 * 0xc + *(int *)0xbc)) {
    iVar1 = param_1 * 0xc + *(int *)0xbc;
    if (*(char *)(iVar1 + 8) != -1) {
      if (*(char *)(iVar1 + 2) == '\x04') {
        FUN_1000_3376(0xd00c,param_1);
      }
      else {
        FUN_1000_358c((uint)*(byte *)(*(int *)0xbc + param_1 * 0xc + 2) << 0xc | param_1);
      }
    }
  }
  return;
}



/* Function: FUN_1000_3376 @ 1000:3376 */

void __cdecl16near FUN_1000_3376(undefined2 param_1,uint param_2)

{
  FUN_1000_3e4e();
  if ((int)param_2 < 0) {
    param_2 = param_2 & 0x7fff;
  }
  else {
    param_2 = param_2 | 0x4000;
  }
  FUN_1000_3908(param_2,0xa74);
  FUN_1000_33b8(param_1,0xa74);
  return;
}



/* Function: FUN_1000_33b8 @ 1000:33b8 */

int __cdecl16near FUN_1000_33b8(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  uint *puVar3;
  int iVar4;
  
  FUN_1000_3e4e();
  puVar3 = (uint *)0x5dbe;
  uVar1 = FUN_1000_56ae();
  *(uint *)0xfa = uVar1 & 3;
  if ((param_1 & 0xf000) == 0xb000) {
    param_1 = param_1 + *(int *)0xfa;
  }
  if (*puVar3 == param_1) {
    iVar2 = FUN_1000_54f2(24000);
  }
  else {
    puVar3 = (uint *)0x33fa;
    iVar2 = FUN_1000_3908(param_1,24000);
    if (0 < iVar2) {
      *puVar3 = param_1;
    }
  }
  if (0 < iVar2) {
    iVar4 = iVar2 + 0x5dc1;
    FUN_1000_3b94(iVar4,24000,&stack0x0004,iVar4);
    FUN_1000_35c6(iVar4);
  }
  return iVar2;
}



/* Function: FUN_1000_3444 @ 1000:3444 */

undefined2 __cdecl16near FUN_1000_3444(int param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  undefined2 unaff_DS;
  int local_34;
  undefined local_2c [32];
  undefined2 uStack12;
  undefined2 uStack10;
  undefined *puStack8;
  
  FUN_1000_3e4e();
  uVar7 = *(byte *)(param_1 + 4) | 0xa000;
  iVar4 = *(byte *)(param_1 + 5) + 5;
  uVar5 = (*(byte *)(param_1 + 5) - 1) / 3;
  bVar2 = *(byte *)(param_1 + 5);
  if (*(uint *)0x47c != uVar7) {
    uStack10 = 0x3491;
    puStack8 = (undefined *)uVar7;
    uVar6 = FUN_1000_39d0();
    *(undefined2 *)0x47a = uVar6;
    *(uint *)0x47c = uVar7;
  }
  if (0 < *(int *)0x47a) {
    puStack8 = (undefined *)0x2;
    uStack10 = 0x34af;
    FUN_1000_3740();
    puStack8 = (undefined *)0x1;
    uStack10 = 0x1000;
    uStack12 = 0x34bc;
    FUN_1570_062a();
    puStack8 = (undefined *)0xa9c;
    uStack10 = 0x1570;
    uStack12 = 0x34c9;
    FUN_1570_05d4();
    puStack8 = (undefined *)0x34d3;
    FUN_1000_3710();
    if (*(int *)0xe6 == 0) {
      *(undefined2 *)(iVar4 * 0x10 + 0x226) = 7;
      *(undefined2 *)(iVar4 * 0x10 + 0x228) = 0;
    }
    uStack10 = 0x3502;
    puStack8 = (undefined *)iVar4;
    FUN_1000_3740();
    for (iVar8 = 0; piVar1 = (int *)(iVar4 * 0x10 + 0x222), *piVar1 != iVar8 && iVar8 <= *piVar1;
        iVar8 = iVar8 + 1) {
      local_34 = 0;
      iVar3 = local_34;
      do {
        local_34 = iVar3;
        local_2c[local_34] =
             *(undefined *)
              (uVar5 * 0x90 + ((bVar2 - 1) % 3) * 0xc + local_34 + iVar8 * 0x24 + 0xa9c);
        iVar3 = local_34 + 1;
      } while (local_34 + 1 < 0xc);
      local_2c[local_34 + 1] = 0;
      puStack8 = (undefined *)(iVar8 + 1);
      uStack10 = 0x1570;
      uStack12 = 0x355b;
      FUN_1570_062a();
      puStack8 = local_2c;
      uStack10 = 0x1570;
      uStack12 = 0x3568;
      FUN_1570_05d4();
    }
    puStack8 = (undefined *)0x357f;
    FUN_1000_3710();
  }
  return *(undefined2 *)0x47a;
}



/* Function: FUN_1000_358c @ 1000:358c */

int __cdecl16near FUN_1000_358c(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_1000_3e4e();
  uVar2 = 4;
  iVar1 = FUN_1000_3908(param_1,0x5dbe,4);
  if (0 < iVar1) {
    FUN_1000_35c6(uVar2,0x5dbe);
  }
  return iVar1;
}



/* Function: FUN_1000_35c6 @ 1000:35c6 */

void __cdecl16near FUN_1000_35c6(int param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_DS;
  char local_6e [98];
  undefined2 uStack12;
  int local_a;
  char *pcStack8;
  
  uVar7 = 0x1000;
  FUN_1000_3e4e();
  pcStack8 = (char *)param_1;
  local_a = 0x35de;
  FUN_1000_3740();
  for (; *param_2 != '\0'; param_2 = param_2 + iVar4) {
    local_a = 0x35f2;
    pcStack8 = param_2;
    iVar4 = FUN_1000_36ae();
    if (iVar4 == 0) break;
    iVar5 = param_1 * 0x10;
    iVar2 = *(int *)(iVar5 + 0x222);
    iVar3 = *(int *)(iVar5 + 0x22a);
    piVar1 = (int *)(iVar5 + 0x22a);
    *piVar1 = *piVar1 + 1;
    uVar6 = uVar7;
    if (iVar2 + -2 < iVar3) {
      pcStack8 = (char *)0x3621;
      FUN_1000_3710();
      pcStack8 = (char *)0x47e;
      uVar6 = 0x1570;
      uStack12 = 0x362e;
      local_a = uVar7;
      FUN_1570_05d4();
      FUN_1000_55a6();
      *(undefined2 *)(param_1 * 0x10 + 0x22a) = 0;
      pcStack8 = (char *)param_1;
      local_a = 0x364a;
      FUN_1000_3740();
    }
    for (local_a = 0; local_a < iVar4; local_a = local_a + 1) {
      local_6e[local_a] = param_2[local_a];
    }
    local_6e[local_a] = '\0';
    pcStack8 = local_6e;
    uVar7 = 0x1570;
    uStack12 = 0x367c;
    local_a = uVar6;
    FUN_1570_05d4();
  }
  pcStack8 = (char *)0x487;
  uStack12 = 0x3694;
  local_a = uVar7;
  FUN_1570_05d4();
  piVar1 = (int *)(param_1 * 0x10 + 0x22a);
  *piVar1 = *piVar1 + 1;
  pcStack8 = (char *)0x36a5;
  FUN_1000_3710();
  return;
}



/* Function: FUN_1000_36ae @ 1000:36ae */

int __cdecl16near FUN_1000_36ae(int param_1,int param_2)

{
  undefined2 unaff_DS;
  int local_8;
  uint local_6;
  int iVar1;
  int iVar2;
  
  FUN_1000_3e4e();
  local_8 = 0;
  iVar1 = 0;
  while (((iVar2 = iVar1, local_8 < param_2 &&
          (local_6 = (uint)*(byte *)(local_8 + param_1), iVar2 = local_8, local_6 != 0)) &&
         (local_6 != 0x40))) {
    if (local_6 == 0x20) {
      iVar1 = local_8;
    }
    local_8 = local_8 + 1;
  }
  iVar1 = iVar2;
  if (local_6 != 0) {
    iVar1 = iVar2 + 1;
    *(undefined *)(iVar2 + param_1) = 10;
  }
  return iVar1;
}



/* Function: FUN_1000_3710 @ 1000:3710 */

void __cdecl16near FUN_1000_3710(int param_1)

{
  undefined2 uVar1;
  undefined2 extraout_DX;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  uVar2 = extraout_DX;
  uVar1 = FUN_1570_064d();
  *(undefined2 *)(param_1 * 4 + 0x1082) = uVar1;
  *(undefined2 *)(param_1 * 4 + 0x1084) = uVar2;
  return;
}



/* Function: FUN_1000_3740 @ 1000:3740 */

void __cdecl16near FUN_1000_3740(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  iVar1 = param_1 * 0x10;
  iVar2 = iVar1 + 0x21e;
  iVar3 = *(int *)(iVar1 + 0x220) + *(int *)(iVar1 + 0x224) + -1;
  FUN_1570_0677(iVar3,*(undefined2 *)(iVar1 + 0x220),*(int *)(iVar1 + 0x222) + iVar3 + -1);
  iVar1 = *(int *)(iVar2 + 8);
  FUN_1570_0301(iVar1,iVar1 >> 0xf);
  FUN_1570_0660(*(undefined2 *)(iVar2 + 10));
  FUN_1570_06cb(*(int *)(iVar2 + 0xe) != 0);
  if (param_2 != 0) {
    FUN_1570_0414(2);
    *(undefined2 *)(param_1 * 4 + 0x1082) = 1;
    *(undefined2 *)(param_1 * 4 + 0x1084) = 1;
    return;
  }
  FUN_1570_062a(*(undefined2 *)(param_1 * 4 + 0x1082),*(undefined2 *)(param_1 * 4 + 0x1084));
  return;
}



/* Function: FUN_1000_380e @ 1000:380e */

void __cdecl16near FUN_1000_380e(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  undefined2 uVar7;
  
  FUN_1000_3e4e();
  iVar4 = *(int *)0xd4 + *(int *)0xd2;
  uVar7 = 0x4c1;
  FUN_1000_4dec(*(undefined2 *)0x65be,0x4c1);
  if (param_1 == 0) {
    iVar3 = FUN_1000_4e86(*(undefined2 *)0xe2,0x8000);
    if (iVar3 < 0) {
      uVar7 = 0x4a8;
    }
    else {
      FUN_1000_3aee(iVar3,*(undefined2 *)0xbc,iVar4);
      puVar6 = (undefined2 *)0x38a9;
      puVar5 = (undefined2 *)*(undefined2 *)0xbc;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      uVar7 = 0x4d5;
    }
  }
  else {
    puVar6 = *(undefined2 **)0xbc;
    puVar5 = (undefined2 *)0x6602;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar6;
      puVar6 = puVar6 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    iVar3 = FUN_1000_4e86(*(undefined2 *)0xe2,0x8302,0x180);
    FUN_1000_3a98(iVar3,*(undefined2 *)0xbc,iVar4);
  }
  FUN_1000_35c6(4,uVar7);
  if (-1 < iVar3) {
    FUN_1000_4dec(iVar3);
  }
  uVar7 = FUN_1000_3b24(*(undefined2 *)0xd8);
  *(undefined2 *)0x65be = uVar7;
  FUN_1000_3444((uint)*(byte *)0x6602 * 0x12 + *(int *)0x5dbc);
  FUN_1000_3082(1);
  return;
}



/* Function: FUN_1000_3908 @ 1000:3908 */

int __cdecl16near FUN_1000_3908(int param_1,int param_2)

{
  byte *pbVar1;
  undefined2 unaff_DS;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_1000_3e4e();
  iVar3 = *(int *)0x12ea;
  iVar2 = 0;
  iVar4 = 0;
  while ((iVar2 < *(int *)0xcc && (*(int *)(iVar2 * 4 + iVar3) != param_1))) {
    iVar2 = iVar2 + 1;
  }
  if (iVar2 < *(int *)0xcc) {
    FUN_1000_4e0c(*(undefined2 *)0x65be,*(undefined2 *)(iVar2 * 4 + iVar3 + 2),0,0);
    iVar4 = FUN_1000_3aee(*(undefined2 *)0x65be,param_2,0x397e);
    *(undefined *)(iVar4 + param_2 + -1) = 0;
    for (iVar3 = 0; iVar3 < iVar4 + -1; iVar3 = iVar3 + 1) {
      pbVar1 = (byte *)(iVar3 + param_2);
      *pbVar1 = *pbVar1 ^ 0xff;
    }
  }
  else if (*(int *)0xe8 != 0) {
    FUN_1000_419e(0x4ec,param_1);
  }
  return iVar4;
}



/* Function: FUN_1000_39d0 @ 1000:39d0 */

int __cdecl16near FUN_1000_39d0(int param_1,int param_2)

{
  byte *pbVar1;
  undefined2 unaff_DS;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_1000_3e4e();
  iVar3 = *(int *)0x10e8;
  iVar2 = 0;
  iVar4 = 0;
  while ((iVar2 < *(int *)0xce && (*(int *)(iVar2 * 4 + iVar3) != param_1))) {
    iVar2 = iVar2 + 1;
  }
  if (iVar2 < *(int *)0xce) {
    FUN_1000_4e0c(*(undefined2 *)0x6600,*(undefined2 *)(iVar2 * 4 + iVar3 + 2),0,0);
    iVar4 = FUN_1000_3aee(*(undefined2 *)0x6600,param_2,0x3a46);
    *(undefined *)(iVar4 + param_2 + -1) = 0;
    for (iVar3 = 0; iVar3 < iVar4 + -1; iVar3 = iVar3 + 1) {
      pbVar1 = (byte *)(iVar3 + param_2);
      *pbVar1 = *pbVar1 ^ 0xff;
    }
  }
  else if (*(int *)0xe8 != 0) {
    FUN_1000_419e(0x50a,param_1);
  }
  return iVar4;
}



/* Function: FUN_1000_3a98 @ 1000:3a98 */

int __cdecl16near FUN_1000_3a98(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_1000_3e4e();
  iVar1 = FUN_1000_5108(param_1,param_2,param_3);
  if ((iVar1 < 0) || (iVar1 != param_3)) {
    FUN_1000_419e(0x528,param_1);
    uVar2 = 0x550;
    FUN_1000_419e(0x550,param_3);
    iVar1 = 0x562;
    FUN_1000_419e(0x562,uVar2);
  }
  return iVar1;
}



/* Function: FUN_1000_3aee @ 1000:3aee */

int __cdecl16near FUN_1000_3aee(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  FUN_1000_3e4e();
  iVar1 = FUN_1000_502a(param_1,param_2,param_3);
  if (iVar1 < 0) {
    FUN_1000_3b60(9);
  }
  return iVar1;
}



/* Function: FUN_1000_3b24 @ 1000:3b24 */

int __cdecl16near FUN_1000_3b24(undefined2 param_1)

{
  int iVar1;
  
  FUN_1000_3e4e();
  iVar1 = FUN_1000_4e86(param_1,0x8002);
  if (iVar1 < 0) {
    FUN_1000_419e(0x56f,param_1);
    FUN_1000_3b60(8);
  }
  return iVar1;
}



/* Function: FUN_1000_3b60 @ 1000:3b60 */

void __cdecl16near FUN_1000_3b60(char param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_3e4e();
  *(char *)0x588 = param_1 + '0';
  FUN_1000_35c6(4,0x582);
  FUN_1000_3d7c(0);
  return;
}



/* Function: FUN_1000_3b94 @ 1000:3b94 */

char * __cdecl16near FUN_1000_3b94(char *param_1,char *param_2,char **param_3)

{
  char **ppcVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  char *local_8;
  
  FUN_1000_3e4e();
  bVar2 = false;
  pcVar3 = param_1;
  while (pcVar4 = param_2, !bVar2) {
    for (; (*pcVar4 != '%' && (*pcVar4 != '\0')); pcVar4 = pcVar4 + 1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
    }
    param_2 = pcVar4 + 1;
    if (*pcVar4 == '\0') {
      bVar2 = true;
    }
    else {
      param_2 = pcVar4 + 2;
      ppcVar1 = param_3 + 1;
      local_8 = *param_3;
      while (param_3 = ppcVar1, *local_8 != '\0') {
        *pcVar3 = *local_8;
        pcVar3 = pcVar3 + 1;
        local_8 = local_8 + 1;
      }
    }
  }
  *pcVar3 = '\0';
  return pcVar3 + (1 - (int)param_1);
}



/* Function: entry @ 1000:3c06 */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

void entry(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  undefined *puVar4;
  char *pcVar5;
  code *pcVar6;
  code **ppcVar7;
  code *pcVar8;
  code *pcVar9;
  byte bVar10;
  char cVar11;
  int iVar12;
  uint extraout_DX;
  int iVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined *puVar18;
  undefined *puVar19;
  uint uVar20;
  char *pcVar21;
  undefined *puVar22;
  char *pcVar23;
  int unaff_ES;
  undefined2 uVar24;
  undefined2 unaff_DS;
  undefined2 uVar25;
  undefined2 uVar26;
  bool bVar27;
  
  puVar14 = (undefined *)0x800;
  pcVar9 = (code *)swi(0x21);
  bVar10 = (*pcVar9)();
  if (bVar10 < 2) {
    pcVar9 = (code *)swi(0x20);
    (*pcVar9)();
  }
  uVar20 = *(int *)0x2 + 0xe755;
  if (0xfff < uVar20) {
    uVar20 = 0x1000;
  }
  puVar15 = puVar14 + 0x680e;
  puVar22 = puVar14 + 0x680e;
  if ((undefined *)0x97f1 < puVar14) {
    *(undefined2 *)(puVar14 + 0x680c) = 0x18ab;
    unaff_DS = *(undefined2 *)(puVar14 + 0x680c);
    *(undefined2 *)(puVar14 + 0x680c) = 0x3c31;
    FUN_1000_3e28();
    *(undefined2 *)(puVar14 + 0x680c) = 0;
    *(undefined2 *)(puVar14 + 0x680a) = 0x3c37;
    FUN_1000_40ad();
    pcVar9 = (code *)swi(0x21);
    (*pcVar9)();
    puVar22 = puVar15;
  }
  puVar16 = (undefined *)((uint)puVar22 & 0xfffe);
  DAT_18af_054a = uVar20 * 0x10 + -1;
  DAT_18af_054c = puVar16;
  DAT_18af_0550 = puVar16;
  *(int *)0x2 = uVar20 + 0x18ab;
  iVar13 = -(unaff_ES - (uVar20 + 0x18ab));
  pcVar9 = (code *)swi(0x21);
  (*pcVar9)();
  DAT_18af_05c1 = unaff_DS;
  *(undefined2 *)(puVar16 + -2) = 0x18ab;
  uVar24 = *(undefined2 *)(puVar16 + -2);
  puVar22 = (undefined *)0xa74;
  for (iVar12 = 0x5d9c; iVar12 != 0; iVar12 = iVar12 + -1) {
    puVar4 = puVar22;
    puVar22 = puVar22 + 1;
    *puVar4 = 0;
  }
  *(undefined2 *)(puVar16 + -2) = 0x18ab;
  *(undefined2 *)(puVar16 + -2) = 0x3c7d;
  FUN_1000_3cb8();
  *(undefined2 *)(puVar16 + -2) = 0x18ab;
  uVar25 = *(undefined2 *)(puVar16 + -2);
  *(undefined2 *)(puVar16 + -2) = 0x3c82;
  FUN_1000_4014();
  puVar17 = puVar16 + -2;
  *(undefined2 *)(puVar16 + -2) = 0x3c85;
  FUN_1000_3e86();
  *(undefined2 *)(puVar17 + -2) = *(undefined2 *)0x622;
  *(undefined2 *)(puVar17 + -4) = *(undefined2 *)0x620;
  *(undefined2 *)(puVar17 + -6) = *(undefined2 *)0x61e;
  *(undefined2 *)(puVar17 + -8) = 0x3c96;
  uVar25 = FUN_1000_0010();
  *(undefined2 *)(puVar17 + -8) = uVar25;
  puVar18 = puVar17 + -10;
  *(undefined2 *)(puVar17 + -10) = 0x3c9a;
  FUN_1000_3d7c();
  uVar26 = 0x18ab;
  uVar25 = 3;
  DAT_18af_054e = 0x3d7c;
  while( true ) {
    *(undefined2 *)(puVar18 + -2) = uVar25;
    *(undefined2 *)(puVar18 + -4) = 0x3cad;
    FUN_1000_3e28();
    *(undefined2 *)(puVar18 + -4) = 0x3cb0;
    FUN_1000_40ad();
    *(undefined2 *)(puVar18 + -2) = 0xff;
    pcVar6 = *(code **)0x58e;
    puVar19 = puVar18 + -4;
    *(undefined2 *)(puVar18 + -4) = 0x3cb8;
    (*pcVar6)();
    pcVar9 = (code *)swi(0x21);
    uVar25 = (*pcVar9)();
    *(undefined2 *)0x603 = uVar25;
    pcVar9 = (code *)swi(0x21);
    (*pcVar9)();
    *(int *)0x5ef = iVar13;
    *(undefined2 *)0x5f1 = uVar24;
    *(undefined2 *)(puVar19 + -2) = 0x1000;
    pcVar9 = (code *)swi(0x21);
    (*pcVar9)();
    *(undefined2 *)(puVar19 + -2) = 0x18ab;
    uVar25 = *(undefined2 *)(puVar19 + -2);
    if (*(int *)0x97e == 0) break;
    uVar24 = *(undefined2 *)0x601;
    bVar27 = false;
    iVar13 = 0;
    ppcVar7 = (code **)0x97c;
    pcVar6 = ppcVar7[1];
    pcVar8 = *ppcVar7;
    *(undefined2 *)(puVar19 + -2) = 0x1000;
    puVar18 = puVar19 + -4;
    *(undefined2 *)(puVar19 + -4) = 0x3cf4;
    (*pcVar8)();
    if (!bVar27) {
      ppcVar7 = (code **)0x97c;
      pcVar6 = ppcVar7[1];
      pcVar8 = *ppcVar7;
      *(undefined2 *)(puVar18 + -2) = 0x1000;
      puVar19 = puVar18 + -4;
      *(undefined2 *)(puVar18 + -4) = 0x3d0a;
      (*pcVar8)();
      *(undefined2 *)(puVar19 + -2) = 0x18ab;
      uVar25 = *(undefined2 *)(puVar19 + -2);
      break;
    }
    *(undefined2 *)(puVar18 + -2) = 0x18ab;
    uVar26 = *(undefined2 *)(puVar18 + -2);
    uVar25 = 2;
  }
  iVar12 = *(int *)0x2c;
  if (iVar12 != 0) {
    pcVar23 = (char *)0x0;
    do {
      bVar27 = *pcVar23 == '\0';
      if (bVar27) break;
      iVar13 = 0xc;
      pcVar21 = (char *)0x5e2;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pcVar5 = pcVar23;
        pcVar23 = pcVar23 + 1;
        pcVar2 = pcVar21;
        pcVar21 = pcVar21 + 1;
        bVar27 = *pcVar2 == *pcVar5;
      } while (bVar27);
      if (bVar27) {
        *(int *)(puVar19 + -2) = iVar12;
        *(undefined2 *)(puVar19 + -4) = uVar25;
        uVar24 = *(undefined2 *)(puVar19 + -4);
        uVar25 = *(undefined2 *)(puVar19 + -2);
        pcVar21 = (char *)0x60a;
        iVar12 = (int)*pcVar23;
        do {
          pcVar23 = pcVar23 + 1;
          cVar3 = *pcVar23;
          cVar11 = cVar3 + '\x01';
          if (cVar11 != '\0') {
            cVar11 = cVar3;
          }
          pcVar2 = pcVar21;
          pcVar21 = pcVar21 + 1;
          *pcVar2 = cVar11;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *(undefined2 *)(puVar19 + -2) = 0x18ab;
        uVar25 = *(undefined2 *)(puVar19 + -2);
        break;
      }
      iVar13 = 0x7fff;
      bVar27 = true;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pcVar2 = pcVar23;
        pcVar23 = pcVar23 + 1;
        bVar27 = *pcVar2 == '\0';
      } while (!bVar27);
    } while (bVar27);
  }
  iVar12 = 4;
  do {
    pbVar1 = (byte *)(iVar12 + 0x60a);
    bVar27 = false;
    *pbVar1 = *pbVar1 & 0xbf;
    pcVar9 = (code *)swi(0x21);
    (*pcVar9)();
    if ((!bVar27) && ((extraout_DX & 0x80) != 0)) {
      pbVar1 = (byte *)(iVar12 + 0x60a);
      *pbVar1 = *pbVar1 | 0x40;
    }
    iVar12 = iVar12 + -1;
  } while (-1 < iVar12);
  *(undefined2 *)(puVar19 + -2) = 0x3d72;
  FUN_1000_3e14();
  *(undefined2 *)(puVar19 + -2) = 0x3d7b;
  FUN_1000_3e05();
  return;
}



/* Function: FUN_1000_3cb8 @ 1000:3cb8 */

void __cdecl16near FUN_1000_3cb8(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  code **ppcVar5;
  code *pcVar6;
  char cVar7;
  undefined2 uVar8;
  int iVar9;
  uint extraout_DX;
  undefined2 in_BX;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar13;
  
  while( true ) {
    pcVar6 = (code *)swi(0x21);
    uVar8 = (*pcVar6)();
    *(undefined2 *)0x603 = uVar8;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    *(undefined2 *)0x5ef = in_BX;
    *(undefined2 *)0x5f1 = unaff_ES;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    if (*(int *)0x97e == 0) break;
    unaff_ES = *(undefined2 *)0x601;
    bVar13 = false;
    in_BX = 0;
    ppcVar5 = (code **)0x97c;
    (**ppcVar5)();
    if (!bVar13) {
      ppcVar5 = (code **)0x97c;
      (**ppcVar5)(0x1000);
      break;
    }
    FUN_1000_3e28(2);
    FUN_1000_40ad();
    (**(code **)0x58e)(0xff);
    unaff_DS = unaff_SS;
  }
  iVar10 = *(int *)0x2c;
  if (iVar10 != 0) {
    pcVar12 = (char *)0x0;
    do {
      bVar13 = *pcVar12 == '\0';
      if (bVar13) break;
      iVar9 = 0xc;
      pcVar11 = (char *)0x5e2;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        pcVar4 = pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar2 = pcVar11;
        pcVar11 = pcVar11 + 1;
        bVar13 = *pcVar2 == *pcVar4;
      } while (bVar13);
      if (bVar13) {
        pcVar11 = (char *)0x60a;
        iVar9 = (int)*pcVar12;
        do {
          pcVar12 = pcVar12 + 1;
          cVar3 = *pcVar12;
          cVar7 = cVar3 + '\x01';
          if (cVar7 != '\0') {
            cVar7 = cVar3;
          }
          pcVar2 = pcVar11;
          pcVar11 = pcVar11 + 1;
          *pcVar2 = cVar7;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        break;
      }
      iVar9 = 0x7fff;
      bVar13 = true;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        pcVar2 = pcVar12;
        pcVar12 = pcVar12 + 1;
        bVar13 = *pcVar2 == '\0';
      } while (!bVar13);
    } while (bVar13);
  }
  iVar10 = 4;
  do {
    pbVar1 = (byte *)(iVar10 + 0x60a);
    bVar13 = false;
    *pbVar1 = *pbVar1 & 0xbf;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    if ((!bVar13) && ((extraout_DX & 0x80) != 0)) {
      pbVar1 = (byte *)(iVar10 + 0x60a);
      *pbVar1 = *pbVar1 | 0x40;
    }
    iVar10 = iVar10 + -1;
  } while (-1 < iVar10);
  FUN_1000_3e14();
  FUN_1000_3e05();
  return;
}



/* Function: FUN_1000_3d7c @ 1000:3d7c */

void FUN_1000_3d7c(undefined2 param_1,undefined2 param_2)

{
  code **ppcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_3e05();
  FUN_1000_3e05();
  FUN_1000_3e05();
  FUN_1000_3e14();
  FUN_1000_3e64();
  iVar3 = 0xf;
  iVar4 = 5;
  do {
    if ((*(byte *)(iVar4 + 0x60a) & 1) != 0) {
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)();
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_3dd8();
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  if (*(int *)0x97e != 0) {
    ppcVar1 = (code **)0x97c;
    (**ppcVar1)();
  }
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  if (*(char *)0x62c != '\0') {
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  return;
}



/* Function: FUN_1000_3dd8 @ 1000:3dd8 */

void __cdecl16near FUN_1000_3dd8(undefined2 param_1)

{
  code **ppcVar1;
  code *pcVar2;
  undefined2 unaff_DS;
  
  if (*(int *)0x97e != 0) {
    ppcVar1 = (code **)0x97c;
    (**ppcVar1)(0x1000);
  }
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  if (*(char *)0x62c != '\0') {
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  return;
}



/* Function: FUN_1000_3e05 @ 1000:3e05 */

void __cdecl16near FUN_1000_3e05(void)

{
  code *pcVar1;
  code **unaff_SI;
  code **unaff_DI;
  undefined2 unaff_DS;
  
  do {
    if (unaff_DI <= unaff_SI) {
      return;
    }
    unaff_DI = unaff_DI + -1;
    pcVar1 = *unaff_DI;
  } while (pcVar1 == (code *)0x0);
  (*pcVar1)();
  FUN_1000_3e05();
  return;
}



/* Function: FUN_1000_3e14 @ 1000:3e14 */

void __cdecl16near FUN_1000_3e14(void)

{
  code **ppcVar1;
  code **ppcVar2;
  code **unaff_SI;
  code **unaff_DI;
  code **ppcVar3;
  undefined2 unaff_DS;
  
  do {
    if (unaff_DI <= unaff_SI) {
      return;
    }
    ppcVar3 = unaff_DI + -2;
    ppcVar1 = unaff_DI + -1;
    unaff_DI = ppcVar3;
  } while (((uint)*ppcVar3 | (uint)*ppcVar1) == 0);
  ppcVar2 = ppcVar3;
  (**ppcVar2)(0x1000);
  FUN_1000_3e14();
  return;
}



/* Function: FUN_1000_3e28 @ 1000:3e28 */

void __cdecl16near FUN_1000_3e28(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_40ad(0xfc);
  if (*(int *)0x632 != 0) {
    (**(code **)0x632)();
  }
  FUN_1000_40ad(0xff);
  return;
}



/* Function: FUN_1000_3e4e @ 1000:3e4e */

void FUN_1000_3e4e(undefined param_1,undefined2 param_2,undefined param_3,undefined2 param_4,
                  undefined2 param_5)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  code **ppcVar5;
  code *pcVar6;
  char cVar7;
  undefined2 uVar8;
  undefined *in_AX;
  int iVar9;
  uint extraout_DX;
  undefined *puVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  code *in_stack_00000000;
  
  puVar10 = &param_1 + -(int)in_AX;
  if ((in_AX <= &param_1) && ((undefined *)*(uint *)0x634 <= puVar10)) {
                    /* WARNING: Could not recover jumptable at 0x00013e5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*in_stack_00000000)();
    return;
  }
  do {
    FUN_1000_3e28();
    FUN_1000_40ad();
    (**(code **)0x58e)();
    pcVar6 = (code *)swi(0x21);
    uVar8 = (*pcVar6)();
    *(undefined2 *)0x603 = uVar8;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    *(uint *)0x5ef = (uint)puVar10;
    *(undefined2 *)0x5f1 = unaff_ES;
    param_4 = 0x1000;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    if (*(int *)0x97e == 0) goto LAB_1000_3d0c;
    unaff_ES = *(undefined2 *)0x601;
    bVar14 = false;
    puVar10 = (undefined *)0x0;
    ppcVar5 = (code **)0x97c;
    param_5 = 0x3cf4;
    (**ppcVar5)();
    unaff_DS = unaff_SS;
  } while (bVar14);
  ppcVar5 = (code **)0x97c;
  (**ppcVar5)();
LAB_1000_3d0c:
  iVar11 = *(int *)0x2c;
  if (iVar11 != 0) {
    pcVar13 = (char *)0x0;
    do {
      bVar14 = *pcVar13 == '\0';
      if (bVar14) break;
      iVar9 = 0xc;
      pcVar12 = (char *)0x5e2;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        pcVar4 = pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar2 = pcVar12;
        pcVar12 = pcVar12 + 1;
        bVar14 = *pcVar2 == *pcVar4;
      } while (bVar14);
      if (bVar14) {
        pcVar12 = (char *)0x60a;
        iVar9 = (int)*pcVar13;
        do {
          pcVar13 = pcVar13 + 1;
          cVar3 = *pcVar13;
          cVar7 = cVar3 + '\x01';
          if (cVar7 != '\0') {
            cVar7 = cVar3;
          }
          pcVar2 = pcVar12;
          pcVar12 = pcVar12 + 1;
          *pcVar2 = cVar7;
          iVar9 = iVar9 + -1;
          param_5 = unaff_SS;
        } while (iVar9 != 0);
        break;
      }
      iVar9 = 0x7fff;
      bVar14 = true;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        pcVar2 = pcVar13;
        pcVar13 = pcVar13 + 1;
        bVar14 = *pcVar2 == '\0';
      } while (!bVar14);
    } while (bVar14);
  }
  iVar11 = 4;
  do {
    pbVar1 = (byte *)(iVar11 + 0x60a);
    bVar14 = false;
    *pbVar1 = *pbVar1 & 0xbf;
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    if ((!bVar14) && ((extraout_DX & 0x80) != 0)) {
      pbVar1 = (byte *)(iVar11 + 0x60a);
      *pbVar1 = *pbVar1 | 0x40;
    }
    iVar11 = iVar11 + -1;
  } while (-1 < iVar11);
  FUN_1000_3e14();
  FUN_1000_3e05();
  return;
}



/* Function: FUN_1000_3e64 @ 1000:3e64 */

uint __cdecl16near FUN_1000_3e64(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar4;
  uint uVar3;
  int iVar5;
  byte *pbVar6;
  undefined2 unaff_DS;
  
  pbVar6 = (byte *)0x0;
  iVar5 = 0x42;
  uVar3 = 0;
  do {
    pbVar1 = pbVar6;
    pbVar6 = pbVar6 + 1;
    bVar2 = *pbVar1;
    bVar4 = (byte)(uVar3 >> 8) ^ bVar2;
    uVar3 = CONCAT11(bVar4,bVar2);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar3 = uVar3 ^ 0x5500;
  if (bVar4 != 0x55) {
    FUN_1000_3e28();
    FUN_1000_40ad(1);
    uVar3 = 1;
  }
  return uVar3;
}



/* Function: FUN_1000_3e86 @ 1000:3e86 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_3e86(void)

{
  char cVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char **ppcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  undefined2 uVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *(undefined2 *)0x636 = in_stack_00000000;
  uVar7 = 2;
  if (*(char *)0x603 != '\x02') {
    uVar13 = *(undefined2 *)0x2c;
    *(undefined2 *)0x626 = uVar13;
    iVar5 = -0x8000;
    pcVar10 = (char *)0x0;
LAB_1000_3ea8:
    do {
      pcVar11 = pcVar10;
      if (iVar5 != 0) {
        iVar5 = iVar5 + -1;
        pcVar2 = pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar11 = pcVar10;
        if (*pcVar2 != '\0') goto LAB_1000_3ea8;
      }
      pcVar10 = pcVar11 + 1;
    } while (*pcVar11 != '\0');
    pcVar11 = pcVar11 + 3;
    *(char **)0x624 = pcVar11;
    uVar7 = 0xffff;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar2 != '\0');
    uVar7 = ~uVar7;
  }
  iVar5 = 1;
  pcVar10 = (char *)0x81;
  uVar13 = *(undefined2 *)0x601;
LAB_1000_3ec6:
  do {
    do {
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 == ' ');
  } while (cVar1 == '\t');
  if ((cVar1 != '\r') && (cVar1 != '\0')) {
    iVar5 = iVar5 + 1;
    do {
      pcVar10 = pcVar10 + -1;
LAB_1000_3ed9:
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      cVar1 = *pcVar2;
      if ((cVar1 == ' ') || (cVar1 == '\t')) goto LAB_1000_3ec6;
      if ((cVar1 == '\r') || (cVar1 == '\0')) break;
      if (cVar1 == '\"') {
LAB_1000_3f12:
        do {
          while( true ) {
            while( true ) {
              pcVar2 = pcVar10;
              pcVar10 = pcVar10 + 1;
              cVar1 = *pcVar2;
              if ((cVar1 == '\r') || (cVar1 == '\0')) goto LAB_1000_3f42;
              if (cVar1 == '\"') goto LAB_1000_3ed9;
              if (cVar1 == '\\') break;
              uVar7 = uVar7 + 1;
            }
            uVar6 = 0;
            do {
              pcVar11 = pcVar10;
              uVar6 = uVar6 + 1;
              pcVar10 = pcVar11 + 1;
              cVar1 = *pcVar11;
            } while (cVar1 == '\\');
            if (cVar1 == '\"') break;
            uVar7 = uVar7 + uVar6;
            pcVar10 = pcVar11;
          }
          uVar7 = uVar7 + (uVar6 >> 1) + (uint)((uVar6 & 1) != 0);
        } while ((uVar6 & 1) != 0);
        goto LAB_1000_3ed9;
      }
      if (cVar1 != '\\') {
        uVar7 = uVar7 + 1;
        goto LAB_1000_3ed9;
      }
      uVar6 = 0;
      do {
        uVar6 = uVar6 + 1;
        pcVar2 = pcVar10;
        pcVar10 = pcVar10 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 == '\\');
      if (cVar1 == '\"') {
        uVar7 = uVar7 + (uVar6 >> 1) + (uint)((uVar6 & 1) != 0);
        if ((uVar6 & 1) == 0) goto LAB_1000_3f12;
        goto LAB_1000_3ed9;
      }
      uVar7 = uVar7 + uVar6;
    } while( true );
  }
LAB_1000_3f42:
  *(int *)0x61e = iVar5;
  iVar12 = (iVar5 + 1) * 2;
  iVar5 = -(uVar7 + iVar5 + iVar12 & 0xfffe);
  *(undefined **)0x620 = &stack0x0002 + iVar5;
  pcVar11 = &stack0x0002 + iVar12 + iVar5;
  *(undefined2 *)(&stack0x0000 + iVar5) = unaff_SS;
  uVar13 = *(undefined2 *)(&stack0x0000 + iVar5);
  *(char **)(&stack0x0002 + iVar5) = pcVar11;
  ppcVar8 = (char **)(&stack0x0004 + iVar5);
  uVar4 = *(undefined4 *)0x624;
  pcVar10 = (char *)uVar4;
  do {
    pcVar2 = pcVar10;
    pcVar10 = pcVar10 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar11;
    pcVar11 = pcVar11 + 1;
    *pcVar2 = cVar1;
  } while (cVar1 != '\0');
  pcVar10 = (char *)0x81;
  uVar3 = *(undefined2 *)0x601;
LAB_1000_3f7b:
  do {
    do {
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 == ' ');
  } while (cVar1 == '\t');
  if ((cVar1 == '\r') || (cVar1 == '\0')) {
LAB_1000_400a:
    *(undefined2 *)(&stack0x0000 + iVar5) = unaff_SS;
    uVar13 = *(undefined2 *)(&stack0x0000 + iVar5);
    *ppcVar8 = (char *)0x0;
                    /* WARNING: Could not recover jumptable at 0x00014010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)0x636)();
    return;
  }
  *ppcVar8 = pcVar11;
  ppcVar8 = ppcVar8 + 1;
  do {
    pcVar10 = pcVar10 + -1;
LAB_1000_3f98:
    pcVar2 = pcVar10;
    pcVar10 = pcVar10 + 1;
    cVar1 = *pcVar2;
    if ((cVar1 == ' ') || (cVar1 == '\t')) {
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar2 = '\0';
      goto LAB_1000_3f7b;
    }
    if ((cVar1 == '\r') || (cVar1 == '\0')) {
LAB_1000_4007:
      *pcVar11 = '\0';
      goto LAB_1000_400a;
    }
    pcVar9 = pcVar10;
    if (cVar1 == '\"') {
LAB_1000_3fd4:
      while( true ) {
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        if ((cVar1 == '\r') || (cVar1 == '\0')) goto LAB_1000_4007;
        if (cVar1 == '\"') break;
        if (cVar1 == '\\') {
          uVar7 = 0;
          do {
            pcVar9 = pcVar10;
            uVar7 = uVar7 + 1;
            pcVar10 = pcVar9 + 1;
            cVar1 = *pcVar9;
          } while (cVar1 == '\\');
          if (cVar1 == '\"') {
            for (uVar6 = uVar7 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
              pcVar2 = pcVar11;
              pcVar11 = pcVar11 + 1;
              *pcVar2 = '\\';
            }
            if ((uVar7 & 1) == 0) break;
            pcVar2 = pcVar11;
            pcVar11 = pcVar11 + 1;
            *pcVar2 = '\"';
            pcVar9 = pcVar10;
          }
          else {
            for (; uVar7 != 0; uVar7 = uVar7 - 1) {
              pcVar2 = pcVar11;
              pcVar11 = pcVar11 + 1;
              *pcVar2 = '\\';
            }
          }
        }
        else {
          pcVar2 = pcVar11;
          pcVar11 = pcVar11 + 1;
          *pcVar2 = cVar1;
          pcVar9 = pcVar10;
        }
      }
      goto LAB_1000_3f98;
    }
    if (cVar1 != '\\') {
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar2 = cVar1;
      goto LAB_1000_3f98;
    }
    uVar7 = 0;
    do {
      uVar7 = uVar7 + 1;
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 == '\\');
    if (cVar1 == '\"') {
      for (uVar6 = uVar7 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
        pcVar2 = pcVar11;
        pcVar11 = pcVar11 + 1;
        *pcVar2 = '\\';
      }
      pcVar9 = pcVar10;
      if ((uVar7 & 1) == 0) goto LAB_1000_3fd4;
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar2 = '\"';
      goto LAB_1000_3f98;
    }
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar2 = '\\';
    }
  } while( true );
}



/* Function: FUN_1000_4014 @ 1000:4014 */

void __cdecl16near FUN_1000_4014(void)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  int *piVar8;
  char *pcVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar6 = 0;
  pcVar9 = (char *)0x0;
  iVar5 = -1;
  iVar4 = *(int *)0x2c;
  if (iVar4 != 0) {
    cVar3 = *(char *)0x0;
    while (cVar3 != '\0') {
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (*pcVar2 != '\0');
      iVar6 = iVar6 + 1;
      pcVar2 = pcVar9;
      pcVar9 = pcVar9 + 1;
      cVar3 = *pcVar2;
    }
  }
  iVar6 = iVar6 + 1;
  ppcVar7 = (char **)(iVar6 * 2);
  iVar5 = FUN_1000_40d6(iVar6,&stack0xfffe);
  pcVar9 = (char *)((int)ppcVar7 + iVar5);
  *(undefined2 *)0x622 = ppcVar7;
  piVar8 = (int *)0x0;
  while (iVar6 = iVar6 + -1, iVar6 != 0) {
    if (*piVar8 != 0x433b) {
      *ppcVar7 = pcVar9;
      ppcVar7 = ppcVar7 + 1;
    }
    do {
      piVar1 = piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
      cVar3 = *(char *)piVar1;
      pcVar2 = pcVar9;
      pcVar9 = pcVar9 + 1;
      *pcVar2 = cVar3;
    } while (cVar3 != '\0');
  }
  *ppcVar7 = (char *)0x0;
  return;
}



/* Function: FUN_1000_4082 @ 1000:4082 */

int * FUN_1000_4082(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined2 unaff_DS;
  
  piVar4 = (int *)0x9a2;
  do {
    piVar1 = piVar4;
    piVar4 = piVar4 + 1;
    iVar3 = *piVar1;
    piVar2 = piVar4;
    if ((iVar3 == param_1) || (piVar2 = (int *)(iVar3 + 1), piVar2 == (int *)0x0)) {
      return piVar2;
    }
    iVar3 = -1;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      piVar1 = piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (*(char *)piVar1 != '\0');
  } while( true );
}



/* Function: FUN_1000_40ad @ 1000:40ad */

void FUN_1000_40ad(undefined2 param_1)

{
  char *pcVar1;
  code *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 unaff_ES;
  
  pcVar3 = (char *)FUN_1000_4082(param_1);
  if (pcVar3 != (char *)0x0) {
    iVar4 = -1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar1 = pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar1 != '\0');
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  return;
}



/* Function: FUN_1000_40d6 @ 1000:40d6 */

void __cdecl16near FUN_1000_40d6(void)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  code **ppcVar7;
  code *pcVar8;
  char cVar9;
  undefined2 uVar10;
  uint in_AX;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint extraout_DX;
  uint extraout_DX_00;
  int iVar14;
  int in_BX;
  char *pcVar15;
  char *pcVar16;
  undefined2 unaff_DI;
  int unaff_ES;
  int unaff_SS;
  int unaff_DS;
  bool bVar17;
  
  puVar2 = (uint *)0x590;
  uVar11 = in_AX + *puVar2;
  if (CARRY2(in_AX,*puVar2)) {
LAB_1000_3ca9:
    while( true ) {
      FUN_1000_3e28(unaff_DI);
      FUN_1000_40ad();
      (**(code **)0x58e)(0xff);
      pcVar8 = (code *)swi(0x21);
      uVar10 = (*pcVar8)();
      *(undefined2 *)0x603 = uVar10;
      pcVar8 = (code *)swi(0x21);
      (*pcVar8)();
      *(int *)0x5ef = in_BX;
      *(int *)0x5f1 = unaff_ES;
      pcVar8 = (code *)swi(0x21);
      (*pcVar8)();
      if (*(int *)0x97e == 0) break;
      unaff_ES = *(int *)0x601;
      bVar17 = false;
      in_BX = 0;
      ppcVar7 = (code **)0x97c;
      (**ppcVar7)();
      if (!bVar17) {
        ppcVar7 = (code **)0x97c;
        (**ppcVar7)(0x1000);
        break;
      }
      unaff_DI = 2;
      unaff_DS = unaff_SS;
    }
    iVar14 = *(int *)0x2c;
    if (iVar14 != 0) {
      pcVar16 = (char *)0x0;
      do {
        bVar17 = *pcVar16 == '\0';
        if (bVar17) break;
        iVar13 = 0xc;
        pcVar15 = (char *)0x5e2;
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          pcVar6 = pcVar16;
          pcVar16 = pcVar16 + 1;
          pcVar4 = pcVar15;
          pcVar15 = pcVar15 + 1;
          bVar17 = *pcVar4 == *pcVar6;
        } while (bVar17);
        if (bVar17) {
          pcVar15 = (char *)0x60a;
          iVar13 = (int)*pcVar16;
          do {
            pcVar16 = pcVar16 + 1;
            cVar5 = *pcVar16;
            cVar9 = cVar5 + '\x01';
            if (cVar9 != '\0') {
              cVar9 = cVar5;
            }
            pcVar4 = pcVar15;
            pcVar15 = pcVar15 + 1;
            *pcVar4 = cVar9;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          break;
        }
        iVar13 = 0x7fff;
        bVar17 = true;
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          pcVar4 = pcVar16;
          pcVar16 = pcVar16 + 1;
          bVar17 = *pcVar4 == '\0';
        } while (!bVar17);
      } while (bVar17);
    }
    iVar14 = 4;
    do {
      pbVar1 = (byte *)(iVar14 + 0x60a);
      bVar17 = false;
      *pbVar1 = *pbVar1 & 0xbf;
      pcVar8 = (code *)swi(0x21);
      (*pcVar8)();
      if ((!bVar17) && ((extraout_DX & 0x80) != 0)) {
        pbVar1 = (byte *)(iVar14 + 0x60a);
        *pbVar1 = *pbVar1 | 0x40;
      }
      iVar14 = iVar14 + -1;
    } while (-1 < iVar14);
    FUN_1000_3e14();
    FUN_1000_3e05();
    return;
  }
  if (*(uint *)0x58a < uVar11) {
    uVar12 = uVar11 + 0xf;
    uVar11 = (uVar12 >> 1 | (uint)(0xfff0 < uVar11) << 0xf) >> 3;
    unaff_ES = *(int *)0x601;
    bVar17 = CARRY2(uVar11,unaff_DS - unaff_ES);
    in_BX = uVar11 + (unaff_DS - unaff_ES);
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)();
    if (bVar17) goto LAB_1000_3ca9;
    *(int *)0x58a = (uVar12 & 0xfff0) - 1;
    in_AX = extraout_DX_00;
  }
  piVar3 = (int *)0x590;
  *piVar3 = *piVar3 + in_AX;
  return;
}



/* Function: FUN_1000_4138 @ 1000:4138 */

void __cdecl16near FUN_1000_4138(void)

{
  FUN_1000_413e();
  return;
}



/* Function: FUN_1000_413e @ 1000:413e */

void __cdecl16near FUN_1000_413e(void)

{
  byte bVar1;
  char cVar2;
  uint in_AX;
  undefined2 unaff_DS;
  
  bVar1 = (byte)in_AX;
  *(byte *)0x606 = bVar1;
  cVar2 = (char)(in_AX >> 8);
  if (cVar2 != '\0') goto LAB_1000_4163;
  if (*(byte *)0x603 < 3) {
LAB_1000_4159:
    if (0x13 < bVar1) {
LAB_1000_415d:
      in_AX = 0x13;
    }
  }
  else {
    if (0x21 < bVar1) goto LAB_1000_415d;
    if (bVar1 < 0x20) goto LAB_1000_4159;
    in_AX = 5;
  }
  cVar2 = *(char *)(ulong)((in_AX & 0xff) + 0x638);
LAB_1000_4163:
  *(int *)0x5fb = (int)cVar2;
  return;
}



/* Function: FUN_1000_419e @ 1000:419e */

undefined2 __cdecl16near FUN_1000_419e(undefined2 param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_1000_439c(0x656);
  uVar2 = FUN_1000_4524(0x656,param_1,&stack0x0004);
  FUN_1000_4420(uVar1,0x656);
  return uVar2;
}



/* Function: FUN_1000_41da @ 1000:41da */

uint __cdecl16near FUN_1000_41da(byte param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  int local_6;
  
  piVar3 = param_2;
  iVar4 = (int)*(char *)((int)param_2 + 7);
  iVar2 = ((int)(param_2 + -0x327) >> 3) * 6;
  if ((((*(byte *)(param_2 + 3) & 0x83) != 0) && ((*(byte *)(param_2 + 3) & 0x40) == 0)) &&
     ((*(byte *)(param_2 + 3) & 1) == 0)) {
    piVar1 = param_2 + 3;
    *(byte *)piVar1 = *(byte *)piVar1 | 2;
    piVar1 = param_2 + 3;
    *(byte *)piVar1 = *(byte *)piVar1 & 0xef;
    param_2[1] = 0;
    local_6 = 0;
    if (((*(byte *)(param_2 + 3) & 0xc) == 0) &&
       ((*(byte *)(((int)(param_2 + -0x327) >> 3) * 6 + 0x6ee) & 1) == 0)) {
      if ((param_2 == (int *)0x656) || (param_2 == (int *)0x65e)) {
        iVar5 = FUN_1000_556e(iVar4);
        if (iVar5 == 0) {
          piVar1 = (int *)0x64c;
          *piVar1 = *piVar1 + 1;
          if (piVar3 == (int *)0x656) {
            iVar5 = 0x10ea;
          }
          else {
            iVar5 = 0x660e;
          }
          piVar3[2] = iVar5;
          *piVar3 = iVar5;
          *(undefined2 *)(iVar2 + 0x6f0) = 0x200;
          *(undefined *)(iVar2 + 0x6ee) = 1;
        }
      }
      else {
        FUN_1000_4330(param_2);
      }
    }
    if (((*(byte *)(piVar3 + 3) & 8) == 0) &&
       ((*(byte *)(((int)(piVar3 + -0x327) >> 3) * 6 + 0x6ee) & 1) == 0)) {
      iVar5 = 1;
      local_6 = FUN_1000_5108(iVar4,&param_1,1);
    }
    else {
      iVar5 = *piVar3 - piVar3[2];
      *piVar3 = piVar3[2] + 1;
      piVar3[1] = *(int *)(iVar2 + 0x6f0) + -1;
      if (iVar5 < 1) {
        if ((*(byte *)(iVar4 + 0x60a) & 0x20) != 0) {
          FUN_1000_4e0c(iVar4,0,0,2);
        }
      }
      else {
        local_6 = FUN_1000_5108(iVar4,piVar3[2],iVar5);
      }
      *(byte *)piVar3[2] = param_1;
    }
    if (local_6 == iVar5) {
      return (uint)param_1;
    }
  }
  piVar1 = piVar3 + 3;
  *(byte *)piVar1 = *(byte *)piVar1 | 0x20;
  return 0xffff;
}



/* Function: FUN_1000_4330 @ 1000:4330 */

void __cdecl16near FUN_1000_4330(undefined2 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar2 = ((int)(param_1 + -0x327) >> 3) * 6;
  iVar3 = FUN_1000_5254(0x200);
  param_1[2] = iVar3;
  if (iVar3 == 0) {
    puVar1 = param_1 + 3;
    *(byte *)puVar1 = *(byte *)puVar1 | 4;
    param_1[2] = iVar2 + 0x6ef;
    *(undefined2 *)(iVar2 + 0x6f0) = 1;
  }
  else {
    puVar1 = param_1 + 3;
    *(byte *)puVar1 = *(byte *)puVar1 | 8;
    *(undefined2 *)(iVar2 + 0x6f0) = 0x200;
  }
  *param_1 = param_1[2];
  param_1[1] = 0;
  return;
}



/* Function: FUN_1000_439c @ 1000:439c */

undefined2 __cdecl16near FUN_1000_439c(undefined2 *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  piVar1 = (int *)0x64c;
  *piVar1 = *piVar1 + 1;
  if (param_1 == (undefined2 *)0x656) {
    local_4 = 0x10ea;
  }
  else {
    if (param_1 != (undefined2 *)0x65e) {
      return 0;
    }
    local_4 = 0x660e;
  }
  if (((*(byte *)(param_1 + 3) & 0xc) == 0) &&
     ((*(byte *)(((int)(param_1 + -0x327) >> 3) * 6 + 0x6ee) & 1) == 0)) {
    iVar3 = ((int)(param_1 + -0x327) >> 3) * 6;
    param_1[2] = local_4;
    *param_1 = local_4;
    *(undefined2 *)(iVar3 + 0x6f0) = 0x200;
    param_1[1] = 0x200;
    *(undefined *)(iVar3 + 0x6ee) = 1;
    puVar2 = param_1 + 3;
    *(byte *)puVar2 = *(byte *)puVar2 | 2;
    return 1;
  }
  return 0;
}



/* Function: FUN_1000_4420 @ 1000:4420 */

void __cdecl16near FUN_1000_4420(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  if (param_1 == 0) {
    if ((param_2[2] == 0x10ea) || (param_2[2] == 0x660e)) {
      iVar1 = FUN_1000_556e((int)*(char *)((int)param_2 + 7));
      if (iVar1 != 0) {
        FUN_1000_44b6(param_2);
      }
    }
  }
  else if ((param_2 == (undefined2 *)0x656) || (param_2 == (undefined2 *)0x65e)) {
    iVar1 = FUN_1000_556e((int)*(char *)((int)param_2 + 7));
    if (iVar1 != 0) {
      iVar1 = ((int)(param_2 + -0x327) >> 3) * 6;
      FUN_1000_44b6(param_2);
      *(undefined *)(iVar1 + 0x6ee) = 0;
      *(undefined2 *)(iVar1 + 0x6f0) = 0;
      *param_2 = 0;
      param_2[2] = 0;
    }
  }
  return;
}



/* Function: FUN_1000_44b6 @ 1000:44b6 */

undefined2 __cdecl16near FUN_1000_44b6(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = 0;
  if (((*(byte *)(param_1 + 3) & 3) == 2) &&
     (((*(byte *)(param_1 + 3) & 8) != 0 ||
      ((*(byte *)(((int)(param_1 + -0x327) >> 3) * 6 + 0x6ee) & 1) != 0)))) {
    iVar2 = *param_1 - param_1[2];
    if (0 < iVar2) {
      iVar3 = FUN_1000_5108((int)*(char *)((int)param_1 + 7),param_1[2],iVar2);
      if (iVar3 != iVar2) {
        piVar1 = param_1 + 3;
        *(byte *)piVar1 = *(byte *)piVar1 | 0x20;
        uVar4 = 0xffff;
      }
    }
  }
  *param_1 = param_1[2];
  param_1[1] = 0;
  return uVar4;
}



/* Function: FUN_1000_4524 @ 1000:4524 */

/* WARNING: Removing unreachable block (ram,0x0001476a) */

undefined2 __cdecl16near FUN_1000_4524(undefined2 param_1,char *param_2,undefined2 param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  undefined2 unaff_DS;
  int local_166;
  undefined local_164 [344];
  undefined2 uStack12;
  char *pcStack10;
  
  FUN_1000_3e4e();
  *(int *)0xea2 = (int)local_164;
  *(undefined2 *)0xe92 = param_3;
  *(undefined2 *)0xe86 = param_1;
  *(undefined2 *)0xe9c = 0;
  *(undefined2 *)0xe9a = 0;
LAB_1000_47d0:
  if (*param_2 == '\0') {
LAB_1000_47d8:
    if (*(int *)0xe9a == 0) {
      bVar3 = *(byte *)(*(int *)0xe86 + 6);
joined_r0x000147e7:
      if ((bVar3 & 0x20) != 0) {
        return 0xffff;
      }
    }
LAB_1000_4838:
    return *(undefined2 *)0xe9a;
  }
  pcVar4 = param_2;
  if (*param_2 != '%') goto LAB_1000_47b6;
  *(undefined2 *)0xe9e = 1;
  *(undefined2 *)0xe8e = 0;
  *(undefined2 *)0xe8a = 0;
  *(undefined2 *)0xe98 = 0;
  *(undefined2 *)0xe8c = 0;
  *(undefined2 *)0xe96 = 0;
  *(undefined2 *)0xe94 = 0;
  *(undefined2 *)0xe88 = 0;
  *(undefined2 *)0xe84 = 0;
  *(undefined2 *)0xe90 = 0;
  *(undefined2 *)0xea8 = 0x20;
  if (param_2[1] == '0') {
    param_2 = param_2 + 1;
    *(undefined2 *)0xea8 = 0x30;
  }
  while( true ) {
    param_2 = param_2 + 1;
    iVar5 = FUN_1000_4dc4();
    if (iVar5 == 0) break;
    if (*param_2 == '-') {
      piVar1 = (int *)0xe90;
      *piVar1 = *piVar1 + 1;
    }
    else if (*param_2 == '+') {
      piVar1 = (int *)0xe8e;
      *piVar1 = *piVar1 + 1;
      *(undefined2 *)0xe94 = 0;
    }
    else if (*param_2 == ' ') {
      if (*(int *)0xe8e == 0) {
        piVar1 = (int *)0xe94;
        *piVar1 = *piVar1 + 1;
      }
    }
    else {
      piVar1 = (int *)0xe84;
      *piVar1 = *piVar1 + 1;
    }
  }
  pcStack10 = (char *)0x45de;
  param_2 = (char *)FUN_1000_4d44();
  if (*(int *)0xea4 < 0) {
    piVar1 = (int *)0xe90;
    *piVar1 = *piVar1 + 1;
    *(int *)0xea4 = -*(int *)0xea4;
  }
  if (*param_2 == '.') {
    piVar1 = (int *)0xe96;
    *piVar1 = *piVar1 + 1;
    pcStack10 = (char *)0x4608;
    param_2 = (char *)FUN_1000_4d44();
    if (*(int *)0xe9e < 0) {
      *(undefined2 *)0xe9e = 1;
      piVar1 = (int *)0xe96;
      *piVar1 = *piVar1 + -1;
    }
  }
  cVar2 = *param_2;
  if (cVar2 == 'F') {
    *(undefined2 *)0xe8c = 0x10;
  }
  else if (cVar2 == 'N') {
    *(undefined2 *)0xe8c = 8;
  }
  else if (cVar2 == 'h') {
    *(undefined2 *)0xe8c = 1;
  }
  else if (cVar2 == 'l') {
    *(undefined2 *)0xe8c = 2;
  }
  if ((*(int *)0xe8c != 0) || (*param_2 == 'L')) {
    param_2 = param_2 + 1;
  }
  if (*param_2 == '\0') goto LAB_1000_47d8;
  local_166 = (int)*param_2;
  if (((local_166 == 0x45) || (local_166 == 0x47)) || (local_166 == 0x58)) {
    piVar1 = (int *)0xe8a;
    *piVar1 = *piVar1 + 1;
    local_166 = local_166 + 0x20;
  }
  switch(local_166) {
  case 99:
    goto LAB_1000_4792;
  case 100:
  case 0x69:
    goto switchD_1000_4699_caseD_64;
  case 0x65:
  case 0x66:
  case 0x67:
    FUN_1000_4a60();
    goto LAB_1000_481a;
  default:
    pcVar4 = param_2;
    if (*(int *)0xe8c != 0) {
      param_2 = param_2 + -1;
      pcVar4 = param_2;
    }
    goto LAB_1000_47b6;
  case 0x6e:
    **(undefined2 **)*(undefined2 *)0xe92 = *(undefined2 *)0xe9a;
LAB_1000_46a9:
    piVar1 = (int *)0xe92;
    *piVar1 = *piVar1 + 2;
    goto LAB_1000_481a;
  case 0x6f:
    break;
  case 0x70:
    piVar1 = (int *)0xe88;
    *piVar1 = *piVar1 + 1;
    piVar1 = (int *)0xe8a;
    *piVar1 = *piVar1 + 1;
    if (*(int *)0xe96 == 0) {
      *(undefined2 *)0xea0 = 1;
    }
    else {
      *(undefined2 *)0xea0 = 0;
    }
    piVar1 = (int *)0xe96;
    *piVar1 = *piVar1 + 1;
    *(undefined2 *)0xe9e = 4;
    if (*(int *)0xe8c != 8) {
      *(undefined2 *)0xe8c = 0;
      if (*(int *)0xea4 != 0) {
        if (*(int *)0xe90 == 0) {
          piVar1 = (int *)0xea4;
          *piVar1 = *piVar1 + -5;
          iVar5 = *(int *)0xea4;
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          *(int *)0xea4 = iVar5;
        }
        else {
          *(undefined2 *)0xea4 = 0;
        }
      }
      piVar1 = (int *)0xe92;
      *piVar1 = *piVar1 + 2;
      FUN_1000_4842();
      FUN_1000_4b1c();
      if (*(int *)0xe90 == 0) {
        *(undefined2 *)0xea4 = 0;
      }
      else {
        *(undefined2 *)0xea4 = 0x35;
        *(undefined2 *)0xea4 = 0x35;
      }
      piVar1 = (int *)0xe92;
      *piVar1 = *piVar1 + -4;
      FUN_1000_4842();
      goto LAB_1000_46a9;
    }
    break;
  case 0x73:
LAB_1000_4792:
    FUN_1000_4978();
    goto LAB_1000_481a;
  case 0x75:
    piVar1 = (int *)0xe98;
    *piVar1 = *piVar1 + 1;
    goto switchD_1000_4699_caseD_64;
  case 0x78:
    break;
  }
LAB_1000_46bf:
  FUN_1000_4842();
LAB_1000_481a:
  if (*(int *)0xe9c != 0) {
    if (*(int *)0xe9a != 0) goto LAB_1000_4838;
    bVar3 = *(byte *)(*(int *)0xe86 + 6);
    goto joined_r0x000147e7;
  }
  param_2 = param_2 + 1;
  goto LAB_1000_47d0;
LAB_1000_47b6:
  do {
    pcStack10 = pcVar4;
    param_2 = param_2 + 1;
    if (*param_2 == '\0') break;
    pcVar4 = pcStack10;
  } while (*param_2 != '%');
  uStack12 = 0x47cb;
  FUN_1000_4bb8();
  goto LAB_1000_47d0;
switchD_1000_4699_caseD_64:
  *(undefined2 *)0xe84 = 0;
  goto LAB_1000_46bf;
}



/* Function: FUN_1000_4842 @ 1000:4842 */

void __cdecl16near FUN_1000_4842(int param_1)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  uint *puVar4;
  int iVar5;
  undefined2 uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined2 unaff_DS;
  bool bVar9;
  char local_1a [12];
  int local_e;
  int local_a;
  uint local_6;
  uint local_4;
  
  if (param_1 != 10) {
    piVar1 = (int *)0xe98;
    *piVar1 = *piVar1 + 1;
  }
  if ((*(int *)0xe8c == 2) || (*(int *)0xe8c == 0x10)) {
    puVar4 = *(uint **)0xe92;
    local_6 = *puVar4;
    local_4 = puVar4[1];
    piVar1 = (int *)0xe92;
    *piVar1 = *piVar1 + 4;
  }
  else {
    if (*(int *)0xe98 == 0) {
      local_6 = **(uint **)0xe92;
      local_4 = (int)local_6 >> 0xf;
    }
    else {
      local_6 = **(uint **)0xe92;
      local_4 = 0;
    }
    piVar1 = (int *)0xe92;
    *piVar1 = *piVar1 + 2;
  }
  if ((*(int *)0xe84 == 0) || (iVar5 = param_1, (local_6 | local_4) == 0)) {
    iVar5 = 0;
  }
  *(int *)0xea6 = iVar5;
  pcVar7 = *(char **)0xea2;
  if ((*(int *)0xe98 == 0) && ((int)local_4 < 0)) {
    if (param_1 == 10) {
      *pcVar7 = '-';
      pcVar7 = pcVar7 + 1;
      bVar9 = local_6 != 0;
      local_6 = -local_6;
      local_4 = -(local_4 + bVar9);
    }
    local_a = 1;
  }
  else {
    local_a = 0;
  }
  FUN_1000_5564(local_6,local_4,local_1a,param_1);
  if (*(int *)0xe96 != 0) {
    iVar5 = FUN_1000_54f2(local_1a);
    iVar5 = *(int *)0xe9e - iVar5;
    while (local_e = iVar5 + -1, 0 < iVar5) {
      *pcVar7 = '0';
      pcVar7 = pcVar7 + 1;
      iVar5 = local_e;
    }
  }
  iVar5 = *(int *)0xe8a;
  pcVar8 = local_1a;
  do {
    cVar3 = *pcVar8;
    *pcVar7 = cVar3;
    if ((iVar5 != 0) && ('`' < cVar3)) {
      pcVar2 = pcVar7;
      *pcVar2 = *pcVar2 + -0x20;
    }
    pcVar7 = pcVar7 + 1;
    pcVar2 = pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar2 != '\0');
  if (((*(int *)0xe98 == 0) && ((*(uint *)0xe8e | *(uint *)0xe94) != 0)) && (local_a == 0)) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  FUN_1000_4c20(uVar6);
  return;
}



/* Function: FUN_1000_4978 @ 1000:4978 */

/* WARNING: Could not reconcile some variable overlaps */

void __cdecl16near FUN_1000_4978(int param_1)

{
  int *piVar1;
  uint *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint unaff_DS;
  char *local_10;
  uint local_a;
  uint uVar6;
  uint local_6;
  
  uVar6 = unaff_DS;
  if (param_1 == 0) {
    if (*(int *)0xe8c == 0x10) {
      puVar2 = *(uint **)0xe92;
      local_a = *puVar2;
      uVar6 = puVar2[1];
      piVar1 = (int *)0xe92;
      *piVar1 = *piVar1 + 4;
    }
    else {
      local_a = **(uint **)0xe92;
      piVar1 = (int *)0xe92;
      *piVar1 = *piVar1 + 2;
      local_6 = local_a;
    }
    if (*(int *)0xe8c == 0x10) {
      if ((local_a | uVar6) == 0) {
        local_a = 0x768;
        uVar6 = unaff_DS;
      }
    }
    else if (local_6 == 0) {
      local_a = 0x76f;
      uVar6 = unaff_DS;
    }
    local_10 = (char *)CONCAT22(uVar6,local_a);
    iVar4 = 0;
    if (*(int *)0xe96 == 0) {
      while( true ) {
        pcVar3 = local_10;
        local_10 = (char *)((ulong)local_10 & 0xffff0000 | (ulong)((int)local_10 + 1));
        if (*pcVar3 == '\0') break;
        iVar4 = iVar4 + 1;
      }
    }
    else {
      for (; pcVar3 = local_10, iVar4 < *(int *)0xe9e; iVar4 = iVar4 + 1) {
        local_10 = (char *)((ulong)local_10 & 0xffff0000 | (ulong)((int)local_10 + 1));
        if (*pcVar3 == '\0') break;
      }
    }
  }
  else {
    iVar4 = 1;
    local_a = *(uint *)0xe92;
    piVar1 = (int *)0xe92;
    *piVar1 = *piVar1 + 2;
  }
  iVar5 = *(int *)0xea4 - iVar4;
  if (*(int *)0xe90 == 0) {
    FUN_1000_4b5a(iVar5);
  }
  FUN_1000_4bb8(local_a,uVar6,iVar4);
  if (*(int *)0xe90 != 0) {
    FUN_1000_4b5a(iVar5);
  }
  return;
}



/* Function: FUN_1000_4a60 @ 1000:4a60 */

void __cdecl16near FUN_1000_4a60(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = *(undefined2 *)0xe92;
  if ((param_1 == 0x67) || (param_1 == 0x47)) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  if (*(int *)0xe96 == 0) {
    *(undefined2 *)0xe9e = 6;
  }
  if ((cVar2 != '\0') && (*(int *)0xe9e == 0)) {
    *(undefined2 *)0xe9e = 1;
  }
  (**(code **)0x794)(uVar4,*(undefined2 *)0xea2,param_1,*(undefined2 *)0xe9e,*(undefined2 *)0xe8a);
  if ((cVar2 != '\0') && (*(int *)0xe84 == 0)) {
    (**(code **)0x796)(*(undefined2 *)0xea2);
  }
  if ((*(int *)0xe84 != 0) && (*(int *)0xe9e == 0)) {
    (**(code **)0x79a)(*(undefined2 *)0xea2);
  }
  piVar1 = (int *)0xe92;
  *piVar1 = *piVar1 + 8;
  *(undefined2 *)0xea6 = 0;
  if ((*(uint *)0xe8e | *(uint *)0xe94) != 0) {
    iVar3 = (**(code **)0x79c)(uVar4);
    if (iVar3 != 0) {
      uVar4 = 1;
      goto LAB_1000_4b14;
    }
  }
  uVar4 = 0;
LAB_1000_4b14:
  FUN_1000_4c20(uVar4);
  return;
}



/* Function: FUN_1000_4b1c @ 1000:4b1c */

void __cdecl16near FUN_1000_4b1c(uint param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined2 unaff_DS;
  
  if (*(int *)0xe9c == 0) {
    piVar2 = *(int **)0xe86;
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      param_1 = FUN_1000_41da(param_1,piVar2);
    }
    else {
      param_1 = param_1 & 0xff;
      puVar3 = (undefined *)*piVar2;
      piVar1 = piVar2;
      *piVar1 = *piVar1 + 1;
      *puVar3 = (char)param_1;
    }
    if (param_1 == 0xffff) {
      piVar1 = (int *)0xe9c;
      *piVar1 = *piVar1 + 1;
    }
    else {
      piVar1 = (int *)0xe9a;
      *piVar1 = *piVar1 + 1;
    }
  }
  return;
}



/* Function: FUN_1000_4b5a @ 1000:4b5a */

void __cdecl16near FUN_1000_4b5a(int param_1)

{
  int *piVar1;
  byte **ppbVar2;
  byte bVar3;
  byte **ppbVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined2 unaff_DS;
  
  if ((*(int *)0xe9c == 0) && (iVar7 = param_1, 0 < param_1)) {
    while (iVar8 = iVar7 + -1, 0 < iVar7) {
      ppbVar4 = (byte **)*(undefined2 *)0xe86;
      ppbVar2 = ppbVar4 + 1;
      *ppbVar2 = *ppbVar2 + -1;
      if ((int)*ppbVar2 < 0) {
        uVar6 = FUN_1000_41da(*(undefined2 *)0xea8,*(undefined2 *)0xe86);
      }
      else {
        bVar3 = *(byte *)0xea8;
        pbVar5 = *ppbVar4;
        ppbVar2 = ppbVar4;
        *ppbVar2 = *ppbVar2 + 1;
        *pbVar5 = bVar3;
        uVar6 = (uint)bVar3;
      }
      iVar7 = iVar8;
      if (uVar6 == 0xffff) {
        piVar1 = (int *)0xe9c;
        *piVar1 = *piVar1 + 1;
      }
    }
    if (*(int *)0xe9c == 0) {
      piVar1 = (int *)0xe9a;
      *piVar1 = *piVar1 + param_1;
    }
  }
  return;
}



/* Function: FUN_1000_4bb8 @ 1000:4bb8 */

void __cdecl16near FUN_1000_4bb8(byte *param_1,int param_2)

{
  int *piVar1;
  byte **ppbVar2;
  byte bVar3;
  byte **ppbVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_DS;
  
  iVar7 = param_2;
  if (*(int *)0xe9c == 0) {
    while (iVar7 != 0) {
      piVar1 = (int *)(*(int *)0xe86 + 2);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        uVar6 = FUN_1000_41da((int)(char)*param_1,*(undefined2 *)0xe86);
      }
      else {
        bVar3 = *param_1;
        ppbVar4 = (byte **)*(undefined2 *)0xe86;
        pbVar5 = *ppbVar4;
        ppbVar2 = ppbVar4;
        *ppbVar2 = *ppbVar2 + 1;
        *pbVar5 = bVar3;
        uVar6 = (uint)bVar3;
      }
      if (uVar6 == 0xffff) {
        piVar1 = (int *)0xe9c;
        *piVar1 = *piVar1 + 1;
      }
      param_1 = (byte *)((ulong)param_1 & 0xffff0000 | (ulong)((int)param_1 + 1));
      iVar7 = iVar7 + -1;
    }
    if (*(int *)0xe9c == 0) {
      piVar1 = (int *)0xe9a;
      *piVar1 = *piVar1 + param_2;
    }
  }
  return;
}



/* Function: FUN_1000_4c20 @ 1000:4c20 */

void __cdecl16near FUN_1000_4c20(int param_1)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  pcVar4 = *(char **)0xea2;
  bVar2 = false;
  bVar6 = false;
  if (((*(int *)0xea8 == 0x30) && (*(int *)0xe96 != 0)) &&
     ((*(int *)0xe88 == 0 || (*(int *)0xea0 == 0)))) {
    *(undefined2 *)0xea8 = 0x20;
  }
  iVar5 = *(int *)0xea4;
  iVar3 = FUN_1000_54f2(pcVar4);
  iVar5 = (iVar5 - iVar3) - param_1;
  if (((*(int *)0xe90 == 0) && (*pcVar4 == '-')) && (*(int *)0xea8 == 0x30)) {
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
    FUN_1000_4b1c((int)*pcVar1);
  }
  if (((*(int *)0xea8 == 0x30) || (iVar5 < 1)) || (*(int *)0xe90 != 0)) {
    bVar6 = param_1 != 0;
    if (bVar6) {
      FUN_1000_4d02();
    }
    if (*(int *)0xea6 != 0) {
      bVar2 = true;
      FUN_1000_4d1a();
    }
  }
  if (*(int *)0xe90 == 0) {
    FUN_1000_4b5a(iVar5);
    if ((param_1 != 0) && (!bVar6)) {
      FUN_1000_4d02();
    }
    if ((*(int *)0xea6 != 0) && (!bVar2)) {
      FUN_1000_4d1a();
    }
  }
  FUN_1000_4bb8(pcVar4);
  if (*(int *)0xe90 != 0) {
    *(undefined2 *)0xea8 = 0x20;
    FUN_1000_4b5a(iVar5);
  }
  return;
}



/* Function: FUN_1000_4d02 @ 1000:4d02 */

void __cdecl16near FUN_1000_4d02(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  if (*(int *)0xe8e == 0) {
    uVar1 = 0x20;
  }
  else {
    uVar1 = 0x2b;
  }
  FUN_1000_4b1c(uVar1);
  return;
}



/* Function: FUN_1000_4d1a @ 1000:4d1a */

void __cdecl16near FUN_1000_4d1a(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_4b1c(0x30);
  if (*(int *)0xea6 == 0x10) {
    if (*(int *)0xe8a == 0) {
      uVar1 = 0x78;
    }
    else {
      uVar1 = 0x58;
    }
    FUN_1000_4b1c(uVar1);
  }
  return;
}



/* Function: FUN_1000_4d44 @ 1000:4d44 */

ulong __cdecl16near FUN_1000_4d44(undefined2 *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 unaff_DS;
  int local_4;
  
  local_4 = 1;
  if (*param_2 == '*') {
    iVar2 = **(int **)0xe92;
    piVar1 = (int *)0xe92;
    *piVar1 = *piVar1 + 2;
    param_2 = param_2 + 1;
  }
  else {
    if (*param_2 == '-') {
      local_4 = -1;
      param_2 = param_2 + 1;
    }
    iVar2 = 0;
    if (('/' < *param_2) && (*param_2 < ':')) {
      if ((*(int *)0xe96 == 0) && (*param_2 == '0')) {
        *(undefined2 *)0xea8 = 0x30;
      }
      do {
        iVar2 = iVar2 * 10 + (int)*param_2 + -0x30;
        param_2 = param_2 + 1;
        if (*param_2 < '0') break;
      } while (*param_2 < ':');
    }
  }
  *param_1 = (int)((long)local_4 * (long)iVar2);
  return (long)local_4 * (long)iVar2 & 0xffff0000U | ZEXT24(param_2);
}



/* Function: FUN_1000_4dc4 @ 1000:4dc4 */

undefined2 __cdecl16near FUN_1000_4dc4(char param_1)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  pcVar1 = (char *)0x776;
  while( true ) {
    if (*pcVar1 == '\0') {
      return 0;
    }
    if (param_1 == *pcVar1) break;
    pcVar1 = pcVar1 + 1;
  }
  return 1;
}



/* Function: FUN_1000_4dec @ 1000:4dec */

long __cdecl16near FUN_1000_4dec(uint param_1)

{
  code *pcVar1;
  uint in_DX;
  uint extraout_DX;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = param_1 < *(uint *)0x608;
  if (bVar2) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    in_DX = extraout_DX;
    if (!bVar2) {
      *(undefined *)(param_1 + 0x60a) = 0;
    }
  }
  else {
    bVar2 = true;
  }
  if (!bVar2) {
    return (ulong)in_DX << 0x10;
  }
  FUN_1000_413e();
  return -1;
}



/* Function: FUN_1000_4e0c @ 1000:4e0c */

uint __cdecl16near FUN_1000_4e0c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 unaff_DS;
  bool bVar6;
  undefined4 uVar7;
  
  if (param_1 < *(uint *)0x608) {
    bVar6 = false;
    if ((param_3 & 0x8000) == 0) goto LAB_1000_4e6f;
    if (param_4 == 0) goto LAB_1000_4e47;
    bVar6 = false;
    pcVar2 = (code *)swi(0x21);
    uVar7 = (*pcVar2)();
    uVar4 = (uint)((ulong)uVar7 >> 0x10);
    uVar3 = (uint)uVar7;
    if (bVar6) goto LAB_1000_4e83;
    if ((param_4 & 2) == 0) {
      bVar6 = CARRY2(uVar4,param_3) || CARRY2(uVar4 + param_3,(uint)CARRY2(uVar3,param_2));
      if (-1 < (int)(uVar4 + param_3 + (uint)CARRY2(uVar3,param_2))) {
LAB_1000_4e6f:
        pcVar2 = (code *)swi(0x21);
        uVar3 = (*pcVar2)();
        if (!bVar6) {
          pbVar1 = (byte *)(param_1 + 0x60a);
          bVar6 = false;
          *pbVar1 = *pbVar1 & 0xfd;
        }
        goto LAB_1000_4e83;
      }
    }
    else {
      pcVar2 = (code *)swi(0x21);
      uVar7 = (*pcVar2)(uVar4);
      uVar5 = (uint)((ulong)uVar7 >> 0x10);
      uVar3 = (uint)CARRY2((uint)uVar7,param_2);
      uVar4 = uVar5 + param_3;
      bVar6 = CARRY2(uVar5,param_3) || CARRY2(uVar4,uVar3);
      if (-1 < (int)(uVar4 + uVar3)) goto LAB_1000_4e6f;
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)();
    }
LAB_1000_4e47:
    uVar3 = 0x1600;
  }
  else {
    uVar3 = 0x900;
  }
  bVar6 = true;
LAB_1000_4e83:
  if (bVar6) {
    FUN_1000_413e();
    uVar3 = 0xffff;
  }
  return uVar3;
}



/* Function: FUN_1000_4e86 @ 1000:4e86 */

/* WARNING: Removing unreachable block (ram,0x00014f7e) */
/* WARNING: Could not reconcile some variable overlaps */

uint __cdecl16near FUN_1000_4e86(undefined2 param_1,uint param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint extraout_DX;
  uint uVar6;
  undefined2 unaff_DS;
  bool bVar7;
  undefined uVar8;
  byte local_6;
  undefined2 local_4;
  
  local_4._0_1_ = '\0';
  local_6 = 0;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || ((*(byte *)0x77d & 0x80) == 0)))) {
    local_6 = 0x80;
  }
  bVar7 = false;
  pcVar1 = (code *)swi(0x21);
  uVar5 = param_2;
  uVar2 = (*pcVar1)();
  if (bVar7) {
    if ((uVar2 == 2) && ((uVar5 & 0x100) != 0)) {
      bVar7 = false;
      local_4._0_1_ = 'u';
      FUN_1000_5019();
      uVar8 = 0;
      uVar5 = 0;
LAB_1000_4f88:
      pcVar1 = (code *)swi(0x21);
      uVar2 = (*pcVar1)();
      if ((bool)uVar8) goto LAB_1000_412b;
      if (((char)local_4 != '\0') || (uVar6 = uVar2, (param_2 & 2) == 0)) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        uVar8 = false;
        pcVar1 = (code *)swi(0x21);
        uVar2 = (*pcVar1)();
        if ((bool)uVar8) goto LAB_1000_412b;
        uVar6 = uVar2;
        if ((!bVar7) && ((param_3 & 1) != 0)) {
          uVar8 = false;
          uVar5 = (uint)(byte)((byte)uVar5 | 1);
          pcVar1 = (code *)swi(0x21);
          uVar2 = (*pcVar1)();
          if ((bool)uVar8) goto LAB_1000_412b;
        }
      }
LAB_1000_4fd2:
      if ((local_6 & 0x40) == 0) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        bVar4 = 0;
        if ((uVar5 & 1) != 0) {
          bVar4 = 0x10;
        }
        if ((param_2 & 8) != 0) {
          bVar4 = bVar4 | 0x20;
        }
      }
      else {
        bVar4 = 0;
      }
      if (uVar6 < *(uint *)0x608) {
        *(byte *)(uVar6 + 0x60a) = bVar4 | local_6 | 1;
        return uVar6;
      }
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      uVar2 = 0x1800;
    }
  }
  else {
    if ((uVar5 & 0x500) != 0x500) {
      bVar7 = true;
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      if ((extraout_DX & 0x80) != 0) {
        local_6 = local_6 | 0x40;
      }
      uVar6 = uVar2;
      if ((local_6 & 0x40) == 0) {
        if ((param_2 & 0x200) == 0) {
          if (((local_6 & 0x80) != 0) && ((param_2 & 2) != 0)) {
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
            pcVar1 = (code *)swi(0x21);
            iVar3 = (*pcVar1)();
            if ((iVar3 != 0) && (local_4._1_1_ == '\x1a')) {
              pcVar1 = (code *)swi(0x21);
              (*pcVar1)();
              pcVar1 = (code *)swi(0x21);
              (*pcVar1)();
            }
            uVar5 = 0;
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
            uVar6 = uVar2;
          }
        }
        else {
          uVar8 = 0;
          if ((param_2 & 3) == 0) {
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
            goto LAB_1000_4f88;
          }
          uVar5 = 0;
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          uVar6 = uVar2;
        }
      }
      goto LAB_1000_4fd2;
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    uVar2 = 0x1100;
  }
  uVar8 = true;
LAB_1000_412b:
  if ((bool)uVar8) {
    FUN_1000_413e();
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* Function: FUN_1000_5019 @ 1000:5019 */

void __cdecl16near FUN_1000_5019(void)

{
  return;
}



/* Function: FUN_1000_502a @ 1000:502a */

/* WARNING: Removing unreachable block (ram,0x00015105) */
/* WARNING: Removing unreachable block (ram,0x000150fa) */

int __cdecl16near FUN_1000_502a(uint param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined2 unaff_DS;
  bool bVar11;
  ulong uVar12;
  
  if (*(uint *)0x608 <= param_1) {
    bVar11 = true;
    iVar4 = 0x900;
    goto LAB_1000_509b;
  }
  bVar11 = false;
  iVar4 = 0;
  if ((param_3 == 0) || (bVar11 = false, (*(byte *)(param_1 + 0x60a) & 2) != 0)) goto LAB_1000_509b;
  pcVar3 = (code *)swi(0x21);
  uVar12 = (*pcVar3)();
  pbVar9 = (byte *)(uVar12 >> 0x10);
  iVar4 = (int)uVar12;
  if (bVar11) {
    iVar4 = CONCAT11(9,(char)uVar12);
    goto LAB_1000_509b;
  }
  bVar11 = false;
  if ((*(byte *)(param_1 + 0x60a) & 0x80) == 0) goto LAB_1000_509b;
  pbVar1 = (byte *)(param_1 + 0x60a);
  bVar11 = false;
  *pbVar1 = *pbVar1 & 0xfb;
  if (iVar4 == 0) goto LAB_1000_509b;
  uVar5 = 0xd00;
  pbVar10 = pbVar9;
  if (*pbVar9 == 10) {
    pbVar1 = (byte *)(param_1 + 0x60a);
    *pbVar1 = *pbVar1 | 4;
  }
LAB_1000_5080:
  pbVar8 = (byte *)(uVar12 >> 0x10);
  iVar7 = (int)uVar12;
  pbVar1 = pbVar9;
  pbVar9 = pbVar9 + 1;
  bVar2 = *pbVar1;
  uVar6 = uVar5 & 0xff00;
  uVar5 = uVar6 | bVar2;
  if (bVar2 == (byte)(uVar6 >> 8)) {
    if (iVar7 != 1) {
      if (*pbVar9 != 10) goto LAB_1000_5090;
      goto LAB_1000_5093;
    }
    bVar11 = false;
    pbVar8 = param_2;
    if ((*(byte *)(param_1 + 0x60a) & 0x40) == 0) {
      pcVar3 = (code *)swi(0x21);
      iVar4 = (*pcVar3)();
      if (!bVar11) {
        if (iVar4 != 0) {
          pcVar3 = (code *)swi(0x21);
          iVar4 = (*pcVar3)();
          iVar7 = 1;
        }
        uVar5 = CONCAT11((char)((uint)iVar4 >> 8),0xd);
        goto LAB_1000_5090;
      }
      goto LAB_1000_509b;
    }
    pcVar3 = (code *)swi(0x21);
    uVar12 = (*pcVar3)();
    iVar4 = (int)uVar12;
    bVar11 = false;
    if ((uVar12 & 0x200000) == 0) {
      pcVar3 = (code *)swi(0x21);
      iVar4 = (*pcVar3)();
      if (bVar11) goto LAB_1000_509b;
    }
    uVar5 = CONCAT11((char)((uint)iVar4 >> 8),10);
  }
  else if (bVar2 == 0x1a) {
    pbVar1 = (byte *)(param_1 + 0x60a);
    *pbVar1 = *pbVar1 | 2;
    goto LAB_1000_5095;
  }
LAB_1000_5090:
  uVar12 = CONCAT22(pbVar8,iVar7);
  *pbVar10 = (byte)uVar5;
  pbVar10 = pbVar10 + 1;
LAB_1000_5093:
  pbVar8 = (byte *)(uVar12 >> 0x10);
  uVar6 = (int)uVar12 - 1;
  uVar12 = uVar12 & 0xffff0000 | (ulong)uVar6;
  if (uVar6 == 0) goto LAB_1000_5095;
  goto LAB_1000_5080;
LAB_1000_5095:
  bVar11 = pbVar10 < pbVar8;
  iVar4 = (int)pbVar10 - (int)pbVar8;
LAB_1000_509b:
  if (bVar11) {
    FUN_1000_413e();
    iVar4 = -1;
  }
  return iVar4;
}



/* Function: FUN_1000_5108 @ 1000:5108 */

/* WARNING: Unable to track spacebase fully for stack */

int __cdecl16near FUN_1000_5108(uint param_1,char *param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  code **ppcVar4;
  code *pcVar5;
  char cVar6;
  char cVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  uint extraout_DX;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  undefined2 uVar14;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar15;
  undefined4 uVar16;
  undefined2 uStack16;
  int local_6;
  
  if (*(uint *)0x608 <= param_1) {
    bVar15 = true;
    local_6 = 0x900;
    goto LAB_1000_412b;
  }
  if ((*(byte *)(param_1 + 0x60a) & 0x20) != 0) {
    bVar15 = false;
    pcVar5 = (code *)swi(0x21);
    local_6 = (*pcVar5)();
    if (bVar15) goto LAB_1000_412b;
  }
  if ((*(byte *)(param_1 + 0x60a) & 0x80) == 0) {
LAB_1000_51fc:
    bVar15 = false;
    local_6 = param_3;
    if (param_3 != 0) {
      pcVar5 = (code *)swi(0x21);
      uVar16 = (*pcVar5)();
      local_6 = (int)uVar16;
      if (bVar15) {
        local_6 = CONCAT11(9,(char)uVar16);
      }
      else {
        bVar15 = false;
        if (local_6 == 0) {
          if (((*(byte *)(param_1 + 0x60a) & 0x40) == 0) ||
             (*(char *)((ulong)uVar16 >> 0x10) != '\x1a')) {
            bVar15 = true;
            local_6 = 0x1c00;
          }
          else {
            bVar15 = false;
          }
        }
      }
    }
  }
  else {
    bVar15 = true;
    local_6 = 0;
    iVar11 = param_3;
    pcVar13 = param_2;
    if (param_3 != 0) {
      do {
        if (iVar11 == 0) break;
        bVar15 = *pcVar13 == '\n';
        iVar11 = iVar11 + -1;
        pcVar13 = pcVar13 + 1;
      } while (!bVar15);
      if (!bVar15) goto LAB_1000_51fc;
      uStack16 = 0x515c;
      uVar9 = FUN_1000_5230();
      uVar14 = unaff_DS;
      if (uVar9 < 0xa9) {
        do {
          uStack16 = 0x3cad;
          FUN_1000_3e28();
          uStack16 = 0x3cb0;
          FUN_1000_40ad();
          uStack16 = 0x3cb8;
          (**(code **)0x58e)();
          pcVar5 = (code *)swi(0x21);
          uVar8 = (*pcVar5)();
          *(undefined2 *)0x603 = uVar8;
          pcVar5 = (code *)swi(0x21);
          (*pcVar5)();
          *(uint *)0x5ef = param_1;
          *(undefined2 *)0x5f1 = unaff_DS;
          pcVar5 = (code *)swi(0x21);
          (*pcVar5)();
          if (*(int *)0x97e == 0) goto LAB_1000_3d0c;
          unaff_DS = *(undefined2 *)0x601;
          bVar15 = false;
          param_1 = 0;
          ppcVar4 = (code **)0x97c;
          (**ppcVar4)();
          uVar14 = unaff_SS;
        } while (bVar15);
        ppcVar4 = (code **)0x97c;
        uStack16 = 0x3d0a;
        (**ppcVar4)();
LAB_1000_3d0c:
        iVar11 = *(int *)0x2c;
        if (iVar11 != 0) {
          pcVar13 = (char *)0x0;
          do {
            bVar15 = *pcVar13 == '\0';
            if (bVar15) break;
            iVar10 = 0xc;
            pcVar12 = (char *)0x5e2;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              pcVar3 = pcVar13;
              pcVar13 = pcVar13 + 1;
              pcVar2 = pcVar12;
              pcVar12 = pcVar12 + 1;
              bVar15 = *pcVar2 == *pcVar3;
            } while (bVar15);
            if (bVar15) {
              pcVar12 = (char *)0x60a;
              iVar10 = (int)*pcVar13;
              do {
                pcVar13 = pcVar13 + 1;
                cVar7 = *pcVar13;
                cVar6 = cVar7 + '\x01';
                if (cVar6 != '\0') {
                  cVar6 = cVar7;
                }
                pcVar2 = pcVar12;
                pcVar12 = pcVar12 + 1;
                *pcVar2 = cVar6;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
              break;
            }
            iVar10 = 0x7fff;
            bVar15 = true;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              pcVar2 = pcVar13;
              pcVar13 = pcVar13 + 1;
              bVar15 = *pcVar2 == '\0';
            } while (!bVar15);
          } while (bVar15);
        }
        iVar11 = 4;
        do {
          pbVar1 = (byte *)(iVar11 + 0x60a);
          bVar15 = false;
          *pbVar1 = *pbVar1 & 0xbf;
          pcVar5 = (code *)swi(0x21);
          (*pcVar5)();
          if ((!bVar15) && ((extraout_DX & 0x80) != 0)) {
            pbVar1 = (byte *)(iVar11 + 0x60a);
            *pbVar1 = *pbVar1 | 0x40;
          }
          iVar11 = iVar11 + -1;
        } while (-1 < iVar11);
        FUN_1000_3e14();
        iVar11 = FUN_1000_3e05();
        return iVar11;
      }
      pcVar13 = &stack0xfff2;
      iVar11 = 0x200;
      if (uVar9 < 0x228) {
        iVar11 = 0x80;
      }
      iVar11 = -iVar11;
      pcVar12 = &stack0xfff2 + iVar11;
      *(undefined2 *)((int)&uStack16 + iVar11) = unaff_SS;
      uVar14 = *(undefined2 *)((int)&uStack16 + iVar11);
      do {
        pcVar2 = param_2;
        param_2 = param_2 + 1;
        cVar7 = *pcVar2;
        if (cVar7 == '\n') {
          cVar7 = '\r';
          if (pcVar12 == pcVar13) {
            *(undefined2 *)((int)&uStack16 + iVar11) = 0x5196;
            cVar7 = FUN_1000_51ae();
          }
          pcVar2 = pcVar12;
          pcVar12 = pcVar12 + 1;
          *pcVar2 = cVar7;
          cVar7 = '\n';
          local_6 = local_6 + 1;
        }
        if (pcVar12 == pcVar13) {
          *(undefined2 *)((int)&uStack16 + iVar11) = 0x51a1;
          cVar7 = FUN_1000_51ae();
        }
        pcVar2 = pcVar12;
        pcVar12 = pcVar12 + 1;
        *pcVar2 = cVar7;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      *(undefined2 *)((int)&uStack16 + iVar11) = 0x518b;
      FUN_1000_51ae();
    }
    bVar15 = local_6 != 0;
    local_6 = -local_6;
  }
LAB_1000_412b:
  if (bVar15) {
    FUN_1000_413e();
    local_6 = -1;
  }
  return local_6;
}



/* Function: FUN_1000_51ae @ 1000:51ae */

/* WARNING: Unable to track spacebase fully for stack */

int __cdecl16near FUN_1000_51ae(void)

{
  int *piVar1;
  code *pcVar2;
  int in_AX;
  int iVar3;
  uint in_DX;
  int iVar4;
  int unaff_BP;
  uint unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  undefined auStack6 [4];
  int iStack2;
  
  bVar5 = unaff_DI < in_DX;
  iStack2 = in_AX;
  if (unaff_DI != in_DX) {
    iVar4 = *(int *)(unaff_BP + 4);
    pcVar2 = (code *)swi(0x21);
    iVar3 = (*pcVar2)();
    if ((bVar5) || (piVar1 = (int *)(unaff_BP + -2), *piVar1 = *piVar1 + iVar3, iVar3 == 0)) {
      bVar5 = (undefined *)0xfff7 < auStack6;
      if (bVar5) {
        iVar3 = CONCAT11(9,(char)iVar3);
      }
      else if (((*(byte *)(iVar4 + 0x60a) & 0x40) == 0) || (**(char **)(unaff_BP + 6) != '\x1a')) {
        bVar5 = true;
        iVar3 = 0x1c00;
      }
      else {
        bVar5 = false;
      }
      if (bVar5) {
        *(undefined2 *)(*(int *)(unaff_BP + -8) + 2) = 0x4130;
        FUN_1000_413e();
        iVar3 = -1;
      }
      return iVar3;
    }
  }
  return iStack2;
}



/* Function: FUN_1000_5230 @ 1000:5230 */

void FUN_1000_5230(void)

{
  code *in_stack_00000000;
  
                    /* WARNING: Could not recover jumptable at 0x0001523c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*in_stack_00000000)();
  return;
}



/* Function: FUN_1000_5254 @ 1000:5254 */

void __cdecl16near FUN_1000_5254(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = *(int *)0x77e == 0;
  if (bVar3) {
    iVar1 = FUN_1000_53dc();
    if (bVar3) {
      return;
    }
    puVar2 = (undefined2 *)(iVar1 + 1U & 0xfffe);
    *(undefined2 **)0x77e = puVar2;
    *(undefined2 **)0x780 = puVar2;
    *puVar2 = 1;
    puVar2[1] = 0xfffe;
    *(undefined2 **)0x784 = puVar2 + 2;
  }
  FUN_1000_529d();
  return;
}



/* Function: FUN_1000_529d @ 1000:529d */

undefined4 __cdecl16near FUN_1000_529d(void)

{
  uint *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int in_CX;
  uint uVar7;
  uint **in_BX;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined2 unaff_ES;
  uint *unaff_SS;
  uint *unaff_DS;
  bool bVar11;
  
  if ((in_CX + 1U != 0) && (uVar7 = in_CX + 1U & 0xfffe, uVar7 < 0xffee)) {
    puVar10 = in_BX[1];
    puVar8 = puVar10 + 1;
    uVar4 = *puVar10;
    puVar5 = puVar8;
    if ((uVar4 & 1) != 0) {
      do {
        uVar3 = uVar4 - 1;
        bVar11 = uVar3 == uVar7;
        if (uVar7 <= uVar3) {
LAB_1000_52cd:
          if (bVar11) {
            puVar1 = puVar8 + -1;
            *(char *)puVar1 = *(char *)puVar1 + -1;
          }
          else {
            puVar8[-1] = uVar7;
            *(int *)((int)puVar8 + uVar7) = (uVar3 - uVar7) + -1;
          }
          if (unaff_DS != unaff_SS) {
            *(uint **)0x78c = unaff_DS;
          }
          in_BX[1] = (uint *)((int)puVar8 + uVar7);
          return CONCAT22(unaff_DS,puVar8);
        }
        puVar5 = (uint *)((int)puVar8 + uVar3) + 1;
        uVar4 = *(uint *)((int)puVar8 + uVar3);
        if ((uVar4 & 1) == 0) break;
        uVar4 = uVar4 + uVar3 + 2;
        *puVar10 = uVar4;
      } while( true );
    }
    *(undefined *)0x792 = 2;
    puVar10 = puVar8;
    do {
      if (uVar4 == 0xfffe) {
        puVar8 = in_BX[4];
        if (puVar8 == (uint *)0x0) {
          pcVar2 = (char *)0x792;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            puVar8 = in_BX[3];
            puVar5 = (uint *)FUN_1000_53ba();
            bVar11 = puVar5 == puVar8;
            if (!bVar11) {
              bVar11 = ((uint)puVar5 & 0xff01) == 0xfffe;
              FUN_1000_53ba();
              if (bVar11) break;
              puVar1 = puVar10 + -1;
              *(char *)puVar1 = *(char *)puVar1 + -1;
              bVar11 = *(char *)puVar1 == '\0';
            }
            iVar6 = FUN_1000_5380();
            if (!bVar11) {
              puVar9 = (uint *)(iVar6 + -2);
              goto LAB_1000_5304;
            }
            break;
          }
          puVar10 = unaff_SS;
          puVar8 = unaff_DS;
          if (unaff_DS != unaff_SS) {
            puVar8 = *(uint **)0x788;
          }
        }
        puVar9 = *in_BX;
        unaff_DS = puVar8;
      }
      else {
        puVar9 = (uint *)((int)puVar5 + uVar4);
        puVar10 = puVar5;
      }
LAB_1000_5304:
      puVar8 = puVar9 + 1;
      uVar4 = *puVar9;
      puVar5 = puVar8;
      if ((uVar4 & 1) != 0) {
        while( true ) {
          uVar3 = uVar4 - 1;
          bVar11 = uVar3 == uVar7;
          if (uVar7 <= uVar3) goto LAB_1000_52cd;
          puVar5 = (uint *)((int)puVar8 + uVar3) + 1;
          uVar4 = *(uint *)((int)puVar8 + uVar3);
          puVar10 = puVar8;
          if ((uVar4 & 1) == 0) break;
          uVar4 = uVar4 + uVar3 + 2;
          *puVar9 = uVar4;
        }
      }
    } while( true );
  }
  if (unaff_DS != unaff_SS) {
    *(uint **)0x78c = unaff_DS;
  }
  in_BX[1] = *in_BX;
  return 0;
}



/* Function: FUN_1000_5380 @ 1000:5380 */

undefined2 __cdecl16near FUN_1000_5380(void)

{
  uint *puVar1;
  int in_CX;
  uint uVar2;
  uint uVar3;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar4;
  undefined4 uVar5;
  
  uVar2 = *(uint *)(unaff_DI + -2);
  if ((uVar2 & 1) != 0) {
    in_CX = (in_CX - uVar2) + -1;
  }
  uVar2 = in_CX + 2;
  uVar3 = 0x7fff;
  do {
    puVar1 = (uint *)0x78e;
    if (uVar3 < *puVar1 || uVar3 == *puVar1) break;
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  do {
    if (CARRY2(uVar2,unaff_SI)) {
      return 0;
    }
    if (!CARRY2(uVar2 + unaff_SI,uVar3)) {
      bVar4 = (uVar2 + unaff_SI + uVar3 & ~uVar3) == unaff_SI;
      uVar5 = FUN_1000_53ba();
      if (!bVar4) {
        return (int)uVar5;
      }
      uVar3 = ~(uint)((ulong)uVar5 >> 0x10);
    }
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  return 0;
}



/* Function: FUN_1000_53ba @ 1000:53ba */

undefined4 __cdecl16near FUN_1000_53ba(void)

{
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  int iVar1;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined in_ZF;
  undefined4 uVar2;
  
  uVar2 = FUN_1000_53dc();
  iVar1 = (int)uVar2;
  if (!(bool)in_ZF) {
    iVar1 = (int)uVar2 + (int)((ulong)uVar2 >> 0x10);
    *(undefined2 *)(iVar1 + -2) = 0xfffe;
    *(int *)(in_BX + 6) = iVar1;
    *(int *)(unaff_SI + -2) = (iVar1 - unaff_SI) + -1;
    iVar1 = unaff_DI;
  }
  return CONCAT22(in_DX,iVar1);
}



/* Function: FUN_1000_53dc @ 1000:53dc */

void __cdecl16near FUN_1000_53dc(void)

{
  FUN_1000_53fc(1);
  return;
}



/* Function: FUN_1000_53fc @ 1000:53fc */

undefined2 __cdecl16near FUN_1000_53fc(int param_1,int param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  bool bVar5;
  undefined4 uVar6;
  
  bVar5 = false;
  if (param_3 == 0) {
    if (param_1 == 1) {
      uVar3 = FUN_1000_546a();
      if (!bVar5) {
        return uVar3;
      }
    }
    else {
      uVar1 = *(uint *)0x5e0;
      if ((param_1 != 2) && (bVar5 = uVar1 < 0x590, uVar1 != 0x590)) {
        uVar6 = FUN_1000_546a();
        param_2 = (int)((ulong)uVar6 >> 0x10);
        if (!bVar5) {
          return (int)uVar6;
        }
      }
      puVar4 = (undefined2 *)(uVar1 + 4);
      if ((puVar4 < (undefined2 *)0x5e0) && (param_2 != 0)) {
        bVar5 = (param_2 + 0xfU >> 1 & 4) != 0;
        pcVar2 = (code *)swi(0x21);
        uVar6 = (*pcVar2)();
        if (!bVar5) {
          *puVar4 = (int)((ulong)uVar6 >> 0x10);
          *(undefined2 *)(uVar1 + 6) = (int)uVar6;
          *(undefined2 **)0x5e0 = puVar4;
          return 0;
        }
      }
    }
  }
  return 0xffff;
}



/* Function: FUN_1000_546a @ 1000:546a */

void __cdecl16near FUN_1000_546a(void)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  uint in_DX;
  uint extraout_DX;
  uint uVar4;
  int unaff_BP;
  uint *puVar5;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  
  uVar2 = *(uint *)(unaff_BP + 0xc);
  puVar5 = unaff_DI;
  while (puVar5[1] != uVar2) {
    puVar5 = puVar5 + 2;
    if (puVar5 == (uint *)0x5e0) {
      return;
    }
  }
  puVar1 = puVar5;
  uVar4 = in_DX + *puVar1;
  if (CARRY2(in_DX,*puVar1)) {
    return;
  }
  if ((puVar5 != unaff_DI) || (*(uint *)0x58a < uVar4)) {
    bVar6 = puVar5 < unaff_DI;
    if (puVar5 == unaff_DI) {
      bVar6 = ((uVar4 + 0xf >> 1 | (uint)(0xfff0 < uVar4) << 0xf) >> 3) + uVar2 < *(uint *)0x601;
    }
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
    if (bVar6) {
      return;
    }
    uVar4 = extraout_DX;
    if (puVar5 == unaff_DI) {
      *(uint *)0x58a = extraout_DX;
    }
  }
  *puVar5 = uVar4;
  return;
}



/* Function: FUN_1000_54c0 @ 1000:54c0 */

void __cdecl16near FUN_1000_54c0(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  uVar3 = 0xffff;
  puVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    puVar1 = puVar5;
    puVar5 = (undefined2 *)((int)puVar5 + 1);
  } while (*(char *)puVar1 != '\0');
  uVar3 = ~uVar3;
  if (((uint)param_1 & 1) != 0) {
    puVar2 = param_1;
    param_1 = (undefined2 *)((int)param_1 + 1);
    puVar1 = param_2;
    param_2 = (undefined2 *)((int)param_2 + 1);
    *(undefined *)puVar2 = *(undefined *)puVar1;
    uVar3 = uVar3 - 1;
  }
  for (uVar4 = uVar3 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar2 = param_1;
    param_1 = param_1 + 1;
    puVar1 = param_2;
    param_2 = param_2 + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = param_1;
    param_1 = (undefined2 *)((int)param_1 + 1);
    puVar1 = param_2;
    param_2 = (undefined2 *)((int)param_2 + 1);
    *(undefined *)puVar2 = *(undefined *)puVar1;
  }
  return;
}



/* Function: FUN_1000_54f2 @ 1000:54f2 */

int __cdecl16near FUN_1000_54f2(char *param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0xffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar1 = param_1;
    param_1 = param_1 + 1;
  } while (*pcVar1 != '\0');
  return ~uVar2 - 1;
}



/* Function: FUN_1000_550e @ 1000:550e */

uint __cdecl16near FUN_1000_550e(char *param_1,char *param_2,uint param_3)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined2 unaff_DS;
  bool bVar8;
  
  uVar5 = param_3;
  pcVar7 = param_1;
  if (param_3 != 0) {
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar2 = pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar2 != '\0');
    iVar6 = param_3 - uVar5;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar3 = param_1;
      param_1 = param_1 + 1;
      pcVar2 = param_2;
      param_2 = param_2 + 1;
    } while (*pcVar2 == *pcVar3);
    bVar4 = param_2[-1];
    param_3 = 0;
    pbVar1 = (byte *)(param_1 + -1);
    bVar8 = bVar4 == *pbVar1;
    if (bVar4 < *pbVar1 || bVar8) {
      if (bVar8) {
        return 0;
      }
      param_3 = 0xfffe;
    }
    param_3 = ~param_3;
  }
  return param_3;
}



/* Function: FUN_1000_5548 @ 1000:5548 */

byte * __cdecl16near FUN_1000_5548(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  ulong uVar2;
  byte bVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined2 unaff_DS;
  bool bVar11;
  char cVar4;
  
  uVar6 = 0;
  pbVar9 = param_2;
  pbVar8 = param_2;
  if ((param_3 == 10) && (uVar6 = (int)param_1 >> 0xf, (int)uVar6 < 0)) {
    pbVar9 = param_2 + 1;
    *param_2 = 0x2d;
    bVar11 = param_1 != 0;
    param_1 = -param_1;
    uVar6 = -(uVar6 + bVar11);
    pbVar8 = pbVar9;
  }
  do {
    uVar7 = 0;
    uVar5 = uVar6;
    if (uVar6 != 0) {
      uVar5 = uVar6 / param_3;
      uVar7 = uVar6 % param_3;
    }
    uVar2 = CONCAT22(uVar7,param_1);
    param_1 = (uint)(uVar2 / param_3);
    cVar4 = (char)(uVar2 % (ulong)param_3);
    bVar3 = cVar4 + 0x30;
    if (0x39 < bVar3) {
      bVar3 = cVar4 + 0x57;
    }
    pbVar10 = pbVar9 + 1;
    *pbVar9 = bVar3;
    uVar6 = uVar5;
    pbVar9 = pbVar10;
  } while ((uVar5 | param_1) != 0);
  *pbVar10 = 0;
  do {
    pbVar10 = pbVar10 + -1;
    pbVar1 = pbVar10;
    bVar3 = *pbVar1;
    *pbVar1 = *pbVar8;
    *pbVar8 = bVar3;
    pbVar9 = pbVar8 + 2;
    pbVar8 = pbVar8 + 1;
  } while (pbVar9 < pbVar10);
  return param_2;
}



/* Function: FUN_1000_5564 @ 1000:5564 */

/* WARNING: Removing unreachable block (ram,0x00015651) */
/* WARNING: Removing unreachable block (ram,0x00015656) */
/* WARNING: Removing unreachable block (ram,0x0001565a) */

byte * __cdecl16near FUN_1000_5564(uint param_1,uint param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  ulong uVar3;
  byte bVar4;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined2 unaff_DS;
  char cVar5;
  
  pbVar9 = param_3;
  do {
    uVar7 = 0;
    uVar6 = param_2;
    if (param_2 != 0) {
      uVar6 = param_2 / param_4;
      uVar7 = param_2 % param_4;
    }
    uVar3 = CONCAT22(uVar7,param_1);
    param_1 = (uint)(uVar3 / param_4);
    cVar5 = (char)(uVar3 % (ulong)param_4);
    bVar4 = cVar5 + 0x30;
    if (0x39 < bVar4) {
      bVar4 = cVar5 + 0x57;
    }
    pbVar2 = pbVar9;
    pbVar9 = pbVar9 + 1;
    *pbVar2 = bVar4;
    param_2 = uVar6;
  } while ((uVar6 | param_1) != 0);
  *pbVar9 = 0;
  pbVar8 = param_3;
  do {
    pbVar9 = pbVar9 + -1;
    pbVar2 = pbVar9;
    bVar4 = *pbVar2;
    *pbVar2 = *pbVar8;
    *pbVar8 = bVar4;
    pbVar1 = pbVar8 + 2;
    pbVar8 = pbVar8 + 1;
  } while (pbVar1 < pbVar9);
  return param_3;
}



/* Function: FUN_1000_556e @ 1000:556e */

undefined2 __cdecl16near FUN_1000_556e(int param_1)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  if (((param_1 < *(int *)0x608) && (-1 < param_1)) && ((*(byte *)(param_1 + 0x60a) & 0x40) != 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* Function: FUN_1000_5592 @ 1000:5592 */

uint __cdecl16near FUN_1000_5592(void)

{
  uint uVar1;
  code *pcVar2;
  byte bVar3;
  uint uVar4;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)0x8a6;
  uVar4 = uVar1 & 0xff00 | 0xff;
  if ((char)(uVar1 >> 8) != '\0') {
    pcVar2 = (code *)swi(0x21);
    bVar3 = (*pcVar2)();
    uVar4 = (uint)bVar3;
  }
  return uVar4;
}



/* Function: FUN_1000_55a6 @ 1000:55a6 */

uint __cdecl16near FUN_1000_55a6(void)

{
  code *pcVar1;
  byte bVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  uVar3 = *(uint *)0x8a6;
  if ((char)(uVar3 >> 8) == '\0') {
    *(undefined2 *)0x8a6 = 0xffff;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    bVar2 = (*pcVar1)();
    uVar3 = (uint)bVar2;
  }
  return uVar3;
}



/* Function: FUN_1000_55be @ 1000:55be */

undefined2 __cdecl16near FUN_1000_55be(byte param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  bool bVar6;
  undefined4 uVar7;
  undefined local_c;
  byte local_b;
  undefined local_a;
  undefined local_9;
  undefined local_8;
  
  local_c = (code)0xcd;
  local_b = param_1;
  bVar6 = param_1 < 0x25;
  if ((param_1 == 0x25) || (bVar6 = param_1 < 0x26, param_1 == 0x26)) {
    local_8 = 0xcb;
    local_9 = 0x44;
    local_a = 0x44;
  }
  else {
    local_a = 0xcb;
  }
  uVar5 = *(undefined2 *)(param_2 + 2);
  uVar4 = *(undefined2 *)(param_2 + 4);
  uVar1 = *(undefined2 *)(param_2 + 8);
  uVar2 = *(undefined2 *)(param_2 + 10);
  uVar7 = (*(code *)&local_c)(0x1000);
  uVar3 = (undefined2)uVar7;
  *param_3 = uVar3;
  param_3[1] = uVar5;
  param_3[2] = uVar4;
  param_3[3] = (int)((ulong)uVar7 >> 0x10);
  param_3[4] = uVar1;
  param_3[5] = uVar2;
  if (bVar6) {
    FUN_1000_4138();
    uVar3 = *param_3;
  }
  param_3[6] = (uint)bVar6;
  return uVar3;
}



/* Function: FUN_1000_569c @ 1000:569c */

void __cdecl16near FUN_1000_569c(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8a8 = param_1;
  *(undefined2 *)0x8aa = 0;
  return;
}



/* Function: FUN_1000_56ae @ 1000:56ae */

uint __cdecl16near FUN_1000_56ae(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  long lVar2;
  
  lVar2 = FUN_1000_56d4(*(undefined2 *)0x8a8,*(undefined2 *)0x8aa,0x43fd,3);
  uVar1 = (uint)((ulong)(lVar2 + 0x269ec3) >> 0x10);
  *(undefined2 *)0x8a8 = (int)(lVar2 + 0x269ec3);
  *(uint *)0x8aa = uVar1;
  return uVar1 & 0x7fff;
}



/* Function: FUN_1000_56d4 @ 1000:56d4 */

ulong FUN_1000_56d4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if ((param_4 | param_2) == 0) {
    return (ulong)param_1 * (ulong)param_3;
  }
  return (ulong)param_1 * (ulong)param_3 & 0xffff |
         (ulong)((int)((ulong)param_1 * (ulong)param_3 >> 0x10) +
                param_2 * param_3 + param_1 * param_4) << 0x10;
}



/* Function: FUN_1570_000a @ 1570:000a */

void __cdecl16far FUN_1570_000a(uint param_1)

{
  undefined2 unaff_DS;
  bool bVar1;
  undefined2 uVar2;
  
  FUN_1570_081a();
  if (param_1 == 0xffff) {
    *(undefined *)0x8e8 = *(undefined *)0x8fe;
    param_1 = (uint)*(byte *)0x8fa;
    *(undefined *)0xf00 = 0;
  }
  if (param_1 < 0x14) {
    bVar1 = (int)param_1 < 0;
    (**(code **)(param_1 * 2 + 0x8ac))();
    if (!bVar1) {
      FUN_1570_00ad();
      FUN_1570_00dc();
      FUN_1570_0e29();
      (**(code **)0x91b)();
      FUN_1570_00ad();
      FUN_1570_012f();
      uVar2 = 0x5755;
      (**(code **)0x91f)();
      (**(code **)0x91d)();
      FUN_1570_021b(uVar2);
      FUN_1570_08f1();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0066 @ 1570:0066 */

void FUN_1570_0066(undefined2 param_1_00,uint param_2,undefined param_1)

{
  undefined2 unaff_DS;
  bool bVar1;
  undefined2 uVar2;
  
  *(undefined *)0x8e8 = param_1;
  FUN_1570_081a();
  if (param_2 == 0xffff) {
    *(undefined *)0x8e8 = *(undefined *)0x8fe;
    param_2 = (uint)*(byte *)0x8fa;
    *(undefined *)0xf00 = 0;
  }
  if (param_2 < 0x14) {
    bVar1 = (int)param_2 < 0;
    (**(code **)(param_2 * 2 + 0x8ac))();
    if (!bVar1) {
      FUN_1570_00ad();
      FUN_1570_00dc();
      FUN_1570_0e29();
      (**(code **)0x91b)();
      FUN_1570_00ad();
      FUN_1570_012f();
      uVar2 = 0x5755;
      (**(code **)0x91f)();
      (**(code **)0x91d)();
      FUN_1570_021b(uVar2);
      FUN_1570_08f1();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_00ad @ 1570:00ad */

void __cdecl16near FUN_1570_00ad(void)

{
  char *pcVar1;
  code *pcVar2;
  char cVar3;
  char extraout_DL;
  char extraout_DL_00;
  char cVar4;
  undefined2 unaff_DS;
  
  pcVar1 = (char *)0x8e8;
  cVar4 = *pcVar1;
  *pcVar1 = '\0';
  if (cVar4 != '\0') {
    *(char *)0x904 = cVar4;
    cVar3 = FUN_1570_00dc();
    cVar4 = extraout_DL;
    if (extraout_DL == cVar3) goto LAB_1570_00d7;
  }
  pcVar2 = (code *)swi(0x10);
  (*pcVar2)();
  cVar4 = extraout_DL_00 + '\x01';
LAB_1570_00d7:
  *(char *)0x904 = cVar4;
  return;
}



/* Function: FUN_1570_00dc @ 1570:00dc */

void __cdecl16near FUN_1570_00dc(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)0x1016;
  if ((uVar1 & 0x1c) != 0) {
    bVar2 = *(byte *)(ulong)(*(byte *)0x901 + 0x8d4);
    cVar3 = *(char *)0x904;
    if ((uVar1 & 0x18) != 0) {
      if (cVar3 == '<') {
        if ((bVar2 & 0x10) != 0) goto LAB_1570_012b;
        cVar3 = '\x1e';
      }
      if (cVar3 == '\x1e') {
        if ((bVar2 & 2) != 0) goto LAB_1570_012b;
        cVar3 = '2';
      }
      if ((uVar1 & 8) == 0) goto LAB_1570_0129;
      if (cVar3 == '2') {
        if ((bVar2 & 8) != 0) goto LAB_1570_012b;
        cVar3 = '+';
      }
    }
    if (((cVar3 == '+') && ((bVar2 & 4) != 0)) && ((uVar1 & 0x200) == 0)) goto LAB_1570_012b;
  }
LAB_1570_0129:
  cVar3 = '\x19';
LAB_1570_012b:
  *(char *)0x904 = cVar3;
  return;
}



/* Function: FUN_1570_012f @ 1570:012f */

void __cdecl16near FUN_1570_012f(void)

{
  byte bVar1;
  undefined2 unaff_DS;
  
  if ((((*(byte *)0x1016 & 0xc) != 0) && ((*(byte *)(ulong)(*(byte *)0x901 + 0x8d4) & 0x80) != 0))
     && (bVar1 = *(byte *)0x904, bVar1 != 0x19)) {
    bVar1 = bVar1 & 1 | 6;
    if (*(char *)0x903 != '(') {
      bVar1 = 3;
    }
    if (((*(byte *)0x1016 & 4) != 0) && (*(uint *)0x1018 < 0x41)) {
      bVar1 = bVar1 >> 1;
    }
    *(byte *)0x910 = bVar1;
  }
  return;
}



/* Function: FUN_1570_0169 @ 1570:0169 */

void __cdecl16far FUN_1570_0169(undefined2 param_1)

{
  byte *pbVar1;
  undefined2 in_BX;
  undefined uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (undefined)((uint)in_BX >> 8);
  FUN_1570_081a();
  if (((char)((uint)param_1 >> 8) == '\0') &&
     (pbVar1 = (byte *)0x910, (byte)param_1 < *pbVar1 || (byte)param_1 == *pbVar1)) {
    (**(code **)0x91d)(CONCAT11(uVar2,*(undefined *)0x967));
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0194 @ 1570:0194 */

void __cdecl16far FUN_1570_0194(undefined2 param_1)

{
  byte *pbVar1;
  undefined2 in_BX;
  undefined uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (undefined)((uint)in_BX >> 8);
  FUN_1570_081a();
  if (((char)((uint)param_1 >> 8) == '\0') &&
     (pbVar1 = (byte *)0x910, (byte)param_1 < *pbVar1 || (byte)param_1 == *pbVar1)) {
    (**(code **)0x91d)(CONCAT11(uVar2,*(undefined *)0x968));
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_01c0 @ 1570:01c0 */

int __cdecl16far FUN_1570_01c0(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  uVar1 = 0;
  uVar4 = 0;
  uVar3 = 0;
  iVar2 = 0x20;
  if (*(char *)0x900 != '\0') {
    uVar3 = (uint)*(byte *)0x927 * (uint)*(byte *)0x928;
    uVar1 = *(undefined2 *)0x905;
    uVar4 = *(undefined2 *)0x907;
    iVar2 = *(byte *)0x90b + 1;
  }
  *param_1 = uVar1;
  *(undefined2 *)(iVar5 + 2) = uVar4;
  *(uint *)(iVar5 + 4) = (uint)*(byte *)0x903;
  *(uint *)(iVar5 + 6) = (uint)*(byte *)0x904;
  *(int *)(iVar5 + 8) = iVar2;
  *(uint *)(iVar5 + 10) = uVar3;
  uVar3 = (uVar3 & 0xff00 | (uint)*(byte *)0x910) + 1;
  *(uint *)(iVar5 + 0xc) = uVar3;
  uVar3 = uVar3 & 0xff00;
  *(uint *)(iVar5 + 0xe) = uVar3 | *(byte *)0x901;
  *(uint *)(iVar5 + 0x10) = uVar3 | *(byte *)0x1016;
  *(uint *)(iVar5 + 0x12) = uVar3 | *(byte *)0x1017;
  *(undefined2 *)(iVar5 + 0x14) = *(undefined2 *)0x1018;
  return iVar5;
}



/* Function: FUN_1570_021b @ 1570:021b */

void __cdecl16near FUN_1570_021b(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x900 != '\0') {
    *(undefined2 *)0xfee = 0;
    *(undefined2 *)0xff0 = 0;
    *(undefined2 *)0xfe6 = 0;
    *(undefined2 *)0xfea = 0;
    *(int *)0xfe8 = *(int *)0x905 + -1;
    *(int *)0xfec = *(int *)0x907 + -1;
    FUN_1570_0ce8();
    *(int *)0xeac = *(int *)0x905 >> 1;
    *(int *)0xeae = *(int *)0x907 >> 1;
    *(undefined2 *)0xeb6 = 0xffff;
    FUN_1570_0a05();
  }
  *(undefined2 *)0xef7 = 0;
  *(undefined2 *)0xef5 = 0;
  *(uint *)0xefb = (uint)(byte)(*(char *)0x903 - 1);
  *(uint *)0xef9 = (uint)(byte)(*(char *)0x904 - 1);
  FUN_1570_09a7();
  *(undefined *)0xec0 = 0;
  *(undefined2 *)0xeb0 = 0;
  *(undefined2 *)0xeb2 = 0;
  *(undefined *)0xefe = 1;
  *(undefined *)0xeff = 0;
  return;
}



/* Function: FUN_1570_0301 @ 1570:0301 */

void __cdecl16far FUN_1570_0301(void)

{
  FUN_1570_0931();
  return;
}



/* Function: FUN_1570_03e8 @ 1570:03e8 */

int __cdecl16far FUN_1570_03e8(void)

{
  undefined2 unaff_DS;
  byte in_CF;
  
  FUN_1570_0abc();
  (**(code **)0x925)();
  return in_CF - 1;
}



/* Function: FUN_1570_0403 @ 1570:0403 */

void __cdecl16far FUN_1570_0403(void)

{
  FUN_1570_0abc();
  FUN_1570_0a05();
  return;
}



/* Function: FUN_1570_0414 @ 1570:0414 */

void __cdecl16far FUN_1570_0414(uint param_1)

{
  undefined2 unaff_DS;
  
  FUN_1570_081a();
  if (param_1 < 3) {
    if ((char)param_1 == '\x01') {
      if (*(char *)0x900 != '\0') {
        FUN_1570_0e3e();
      }
    }
    else {
      FUN_1570_0aaf();
      FUN_1570_08f1();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0473 @ 1570:0473 */

undefined2 __cdecl16far FUN_1570_0473(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  if (*(char *)0x900 != '\0') {
    puVar1 = (undefined2 *)0xeac;
    uVar2 = *puVar1;
    *puVar1 = param_1;
    *(undefined2 *)0xeae = param_2;
  }
  return uVar2;
}



/* Function: FUN_1570_04f3 @ 1570:04f3 */

void __cdecl16far
FUN_1570_04f3(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 unaff_DS;
  bool bVar1;
  
  bVar1 = true;
  FUN_1570_081a();
  if (!bVar1) {
    *(undefined *)0xf88 = 0;
    (**(code **)0x942)();
    param_4 = *(int *)0xfee + param_4;
    *(int *)0xf98 = param_4;
    *(int *)0xf90 = param_4;
    param_5 = *(int *)0xff0 + param_5;
    *(int *)0xf9a = param_5;
    *(int *)0xf92 = param_5;
    *(undefined2 *)0xfa4 = *(undefined2 *)0xeb6;
    if (param_1 == 3) {
      if (*(char *)0xec0 != '\0') {
        *(undefined *)0x1021 = 0xff;
      }
      FUN_1570_0e5c();
      *(undefined *)0x1021 = 0;
    }
    else if (param_1 == 2) {
      FUN_1570_0abe();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0568 @ 1570:0568 */

void __cdecl16far FUN_1570_0568(undefined2 param_1,uint param_2)

{
  undefined2 unaff_DS;
  bool bVar1;
  undefined in_ZF;
  
  FUN_1570_081a();
  if (!(bool)in_ZF) {
    bVar1 = CARRY2(param_2,*(uint *)0xff0);
    FUN_1570_0c44();
    if (bVar1) {
      (**(code **)0x936)();
      (**(code **)0x944)();
      (**(code **)0x942)();
      (**(code **)0x946)();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_05a4 @ 1570:05a4 */

void __cdecl16far FUN_1570_05a4(undefined2 param_1,uint param_2)

{
  undefined2 unaff_DS;
  bool bVar1;
  undefined in_ZF;
  
  FUN_1570_081a();
  if (!(bool)in_ZF) {
    bVar1 = CARRY2(*(uint *)0xff0,param_2);
    FUN_1570_0c44();
    if (bVar1) {
      (**(code **)0x936)();
      (**(code **)0x944)();
    }
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_05d4 @ 1570:05d4 */

void __cdecl16far FUN_1570_05d4(char *param_1)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  FUN_1570_081a();
  while( true ) {
    pcVar3 = param_1;
    param_1 = (char *)((ulong)param_1 & 0xffff0000 | (ulong)((int)param_1 + 1));
    cVar2 = *pcVar3;
    if (cVar2 == '\0') break;
    FUN_1570_0753();
    if (cVar2 == '\n') {
      *(undefined2 *)0xef3 = 0;
      *(undefined *)0xefd = 0;
      piVar1 = (int *)0xef1;
      *piVar1 = *piVar1 + 1;
    }
    else if (cVar2 == '\r') {
      *(undefined2 *)0xef3 = 0;
      *(undefined *)0xefd = 0;
    }
    else if (*(char *)0xefd == '\0') {
      FUN_1570_0714();
      piVar1 = (int *)0xef3;
      *piVar1 = *piVar1 + 1;
    }
  }
  FUN_1570_0753();
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_062a @ 1570:062a */

void __cdecl16far FUN_1570_062a(void)

{
  undefined2 unaff_DS;
  
  FUN_1570_081a();
  FUN_1570_072a(*(int *)0xef3 + 1,*(int *)0xef1 + 1);
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_064d @ 1570:064d */

void __cdecl16far FUN_1570_064d(void)

{
  FUN_1570_081a();
  FUN_1570_0753();
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0660 @ 1570:0660 */

void __cdecl16far FUN_1570_0660(void)

{
  FUN_1570_081a();
  FUN_1570_09a7();
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0677 @ 1570:0677 */

void __cdecl16far FUN_1570_0677(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1570_081a();
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xef5 = uVar1;
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xef9 = uVar1;
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xef7 = uVar1;
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xefb = uVar1;
  FUN_1570_072a();
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_06cb @ 1570:06cb */

void __cdecl16far FUN_1570_06cb(undefined2 param_1)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  undefined2 unaff_DS;
  
  FUN_1570_081a();
  bVar4 = (byte)param_1 | (byte)((uint)param_1 >> 8);
  pbVar1 = (byte *)0xefe;
  bVar3 = *pbVar1;
  *pbVar1 = bVar4;
  if ((bVar4 != 0) && (*(char *)0xefd != '\0')) {
    *(undefined *)0xefd = 0;
    piVar2 = (int *)0xef3;
    *piVar2 = *piVar2 + 1;
    FUN_1570_0753(bVar3);
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_06f9 @ 1570:06f9 */

void __cdecl16far FUN_1570_06f9(undefined2 param_1)

{
  undefined2 unaff_DS;
  undefined in_ZF;
  
  FUN_1570_081a();
  if (!(bool)in_ZF) {
    *(byte *)0xf00 = (byte)param_1 | (byte)((uint)param_1 >> 8);
  }
  FUN_1570_0838();
  return;
}



/* Function: FUN_1570_0714 @ 1570:0714 */

void __cdecl16near FUN_1570_0714(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* Function: FUN_1570_072a @ 1570:072a */

void __cdecl16near FUN_1570_072a(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xef1 = uVar1;
  uVar1 = FUN_1570_0a83();
  *(undefined2 *)0xef3 = uVar1;
  *(undefined *)0xefd = 0;
  FUN_1570_0753();
  return;
}



/* Function: FUN_1570_0753 @ 1570:0753 */

int __cdecl16near FUN_1570_0753(void)

{
  int *piVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)0xefb - *(int *)0xef7;
  if (*(int *)0xef3 < 0) {
    *(undefined2 *)0xef3 = 0;
  }
  else {
    piVar1 = (int *)0xef3;
    if (*piVar1 != iVar2 && iVar2 <= *piVar1) {
      if (*(char *)0xefe == '\0') {
        *(int *)0xef3 = iVar2;
        *(undefined *)0xefd = 1;
      }
      else {
        *(undefined2 *)0xef3 = 0;
        piVar1 = (int *)0xef1;
        *piVar1 = *piVar1 + 1;
      }
    }
  }
  iVar2 = *(int *)0xef9 - *(int *)0xef5;
  if (*(int *)0xef1 < 0) {
    *(undefined2 *)0xef1 = 0;
  }
  else {
    piVar1 = (int *)0xef1;
    if (*piVar1 != iVar2 && iVar2 <= *piVar1) {
      *(int *)0xef1 = iVar2;
      FUN_1570_0aaf();
    }
  }
  FUN_1570_08fd();
  return (int)*(char *)0xefd;
}



/* Function: FUN_1570_081a @ 1570:081a */

void __cdecl16near FUN_1570_081a(void)

{
  undefined2 unaff_DS;
  
  FUN_1570_0abc();
  if ((*(char *)0x900 != '\0') && (*(char *)0xeff != '\0')) {
    FUN_1570_0859();
    *(undefined *)0xeff = 0;
  }
  return;
}



/* Function: FUN_1570_0838 @ 1570:0838 */

void __cdecl16near FUN_1570_0838(void)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  if (((*(char *)0x900 != '\0') && (*(char *)0xf00 != '\0')) && (*(char *)0xeff == '\0')) {
    FUN_1570_0859();
    pcVar1 = (char *)0xeff;
    *pcVar1 = *pcVar1 + '\x01';
  }
  return;
}



/* Function: FUN_1570_0859 @ 1570:0859 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1570_0859(void)

{
  uint *puVar1;
  undefined uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  undefined2 *puStack6;
  undefined2 uStack4;
  
  uStack4 = 0x5f5d;
  FUN_1570_08fd();
  if (*(byte *)0x900 < 3) {
    uStack4 = _DAT_0000_007e;
    puStack6 = _DAT_0000_007c;
    _DAT_0000_007c = (undefined2 *)0x8ea;
    _DAT_0000_007e = unaff_DS;
  }
  else if (*(int *)0x901 == 0x13) {
    (**(code **)0x936)();
    uVar2 = *(undefined *)0xeb5;
    uVar4 = *(undefined4 *)0x101c;
    puVar7 = (uint *)uVar4;
    iVar5 = 8;
    do {
      iVar6 = 4;
      do {
        puVar8 = puVar7;
        puVar1 = puVar8;
        *puVar1 = *puVar1 ^ CONCAT11(uVar2,uVar2);
        iVar6 = iVar6 + -1;
        puVar7 = puVar8 + 1;
      } while (iVar6 != 0);
      puVar7 = puVar8 + 0x9d;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return;
  }
  pcVar3 = (code *)swi(0x10);
  (*pcVar3)();
  if (*(byte *)0x900 < 3) {
    *puStack6 = unaff_ES;
    puStack6[1] = in_stack_00000000;
  }
  return;
}



/* Function: FUN_1570_08f1 @ 1570:08f1 */

void __cdecl16near FUN_1570_08f1(void)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0xef3 = 0;
  *(undefined2 *)0xef1 = 0;
  FUN_1570_08fd();
  return;
}



/* Function: FUN_1570_08fd @ 1570:08fd */

void __cdecl16near FUN_1570_08fd(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* Function: FUN_1570_0931 @ 1570:0931 */

undefined4 __cdecl16near FUN_1570_0931(void)

{
  undefined2 uVar1;
  code *pcVar2;
  uint in_AX;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 in_DX;
  undefined2 uVar5;
  undefined2 unaff_DI;
  undefined2 unaff_DS;
  undefined uVar6;
  
  uVar1 = *(undefined2 *)0xeb0;
  uVar5 = *(undefined2 *)0xeb2;
  if (*(int *)0x901 != 6) {
    uVar4 = uVar1;
    if (*(char *)0x900 == '\0') {
      *(uint *)0xeb0 = in_AX & 7;
      *(undefined2 *)0xeb2 = 0;
      FUN_1570_09cb();
      goto LAB_1570_09a4;
    }
    uVar3 = FUN_1570_0abc();
    if ((*(char *)0x900 == '\x01') && ((*(byte *)0x1016 & 0x1c) == 0)) {
      uVar6 = false;
      (**(code **)0x923)();
      if (!(bool)uVar6) {
        pcVar2 = (code *)swi(0x10);
        (*pcVar2)();
        uVar6 = false;
      }
    }
    else {
      uVar6 = 0;
      (**(code **)0x921)(in_DX);
    }
    if (!(bool)uVar6) {
      *(undefined2 *)0xeb0 = unaff_DI;
      *(undefined2 *)0xeb2 = uVar3;
      goto LAB_1570_09a4;
    }
  }
  uVar4 = 0xffff;
  uVar5 = uVar1;
LAB_1570_09a4:
  return CONCAT22(uVar5,uVar4);
}



/* Function: FUN_1570_09a7 @ 1570:09a7 */

uint __cdecl16near FUN_1570_09a7(void)

{
  byte *pbVar1;
  byte bVar2;
  uint in_AX;
  byte bVar3;
  undefined2 unaff_DS;
  
  bVar2 = *(byte *)0x90b;
  if ((char)(in_AX >> 8) == '\0') {
    bVar3 = bVar2;
    if (*(char *)0x900 == '\0') {
      bVar3 = 0x1f;
    }
    if ((byte)in_AX <= bVar3) goto LAB_1570_09c1;
  }
  in_AX = (uint)bVar2;
LAB_1570_09c1:
  pbVar1 = (byte *)0xeb4;
  bVar2 = *pbVar1;
  *pbVar1 = (byte)in_AX;
  FUN_1570_09cb();
  return in_AX & 0xff00 | (uint)bVar2;
}



/* Function: FUN_1570_09cb @ 1570:09cb */

void __cdecl16near FUN_1570_09cb(void)

{
  byte bVar1;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0xeb4;
  if (*(char *)0x900 == '\0') {
    bVar1 = bVar1 & 0xf | (*(byte *)0xeb4 & 0x10) << 3 | (*(byte *)0xeb0 & 7) << 4;
  }
  else if (*(char *)0x928 == '\x02') {
    (**(code **)0x942)();
    bVar1 = *(byte *)0x101b;
  }
  *(byte *)0xeb5 = bVar1;
  return;
}



/* Function: FUN_1570_0a05 @ 1570:0a05 */

uint __cdecl16near FUN_1570_0a05(undefined2 param_1)

{
  byte *pbVar1;
  code *pcVar2;
  uint in_AX;
  uint uVar3;
  byte bVar4;
  undefined2 unaff_SI;
  uint unaff_ES;
  undefined2 unaff_DS;
  
  if ((*(char *)0x900 == '\x01') && (in_AX < 4)) {
    if ((*(byte *)0x1016 & 0x1c) == 0) {
      uVar3 = in_AX & 0xff | (uint)DAT_0000_0466 << 8;
      pcVar2 = (code *)swi(0x10);
      (*pcVar2)();
      pcVar2 = (code *)swi(0x10);
      (*pcVar2)(uVar3,unaff_ES,unaff_SI);
      bVar4 = (byte)((int)param_1 >> 0xc);
      uVar3 = (uint)(char)((bVar4 & 1) << 1 | (bVar4 & 2) >> 1);
    }
    else {
      (**(code **)0x925)();
      pbVar1 = (byte *)0xeaa;
      bVar4 = *pbVar1;
      *pbVar1 = (byte)unaff_ES;
      uVar3 = unaff_ES & 0xff00 | (uint)bVar4;
    }
  }
  else {
    uVar3 = 0xffff;
  }
  return uVar3;
}



/* Function: FUN_1570_0a83 @ 1570:0a83 */

int __cdecl16near FUN_1570_0a83(void)

{
  int in_AX;
  int in_BX;
  
  if (in_AX < 0) {
    in_AX = 0;
  }
  if (in_BX <= in_AX) {
    in_AX = in_BX + -1;
  }
  return in_AX;
}



/* Function: FUN_1570_0aaf @ 1570:0aaf */

void __cdecl16near FUN_1570_0aaf(void)

{
  FUN_1570_3266();
  FUN_1570_3258();
  FUN_1570_3261();
  return;
}



/* Function: FUN_1570_0abc @ 1570:0abc */

void __cdecl16far FUN_1570_0abc(void)

{
  return;
}



/* Function: FUN_1570_0abe @ 1570:0abe */

void FUN_1570_0abe(void)

{
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 unaff_DS;
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)0xf9a;
  FUN_1570_0ae9();
  *(undefined2 *)0xf9a = in_DX;
  FUN_1570_0ae9();
  *(undefined2 *)0xf9a = uVar1;
  FUN_1570_0ae9();
  *(undefined2 *)0xf98 = in_CX;
  FUN_1570_0b20(extraout_DX,in_CX);
  *(undefined2 *)0xf98 = *(undefined2 *)0xf90;
  *(undefined2 *)0xf9a = *(undefined2 *)0xf92;
  return;
}



/* Function: FUN_1570_0ae9 @ 1570:0ae9 */

void __cdecl16near FUN_1570_0ae9(void)

{
  undefined2 unaff_DS;
  
  FUN_1570_0b20();
  *(undefined2 *)0xf98 = *(undefined2 *)0xf90;
  *(undefined2 *)0xf9a = *(undefined2 *)0xf92;
  return;
}



/* Function: FUN_1570_0b20 @ 1570:0b20 */

void __cdecl16near FUN_1570_0b20(uint param_1)

{
  undefined2 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 in_CX;
  uint extraout_DX;
  int in_BX;
  undefined2 unaff_DS;
  bool bVar5;
  byte bVar6;
  byte in_AF;
  undefined in_ZF;
  byte bVar7;
  byte bVar8;
  byte in_TF;
  byte in_IF;
  byte bVar9;
  byte in_NT;
  undefined2 in_stack_00000000;
  
  FUN_1570_0b4e();
  if (!(bool)in_ZF) {
    return;
  }
  puVar1 = (undefined2 *)0xf98;
  uVar4 = *puVar1;
  *puVar1 = in_CX;
  puVar2 = (uint *)0xf9a;
  uVar3 = *puVar2;
  *puVar2 = extraout_DX;
  if (*(int *)0xfa4 == -1) {
    puVar2 = (uint *)0xf9a;
    bVar5 = uVar3 < *puVar2;
    bVar9 = SBORROW2(uVar3,*puVar2);
    uVar3 = uVar3 - *puVar2;
    bVar8 = (int)uVar3 < 0;
    bVar7 = uVar3 == 0;
    bVar6 = (POPCOUNT(uVar3 & 0xff) & 1U) == 0;
    if ((bool)bVar7) {
      FUN_1570_0f55();
      if (bVar5) {
        *(undefined2 *)0xf98 = uVar4;
      }
      (**(code **)0x936)(in_BX + 1,uVar4,
                         (uint)(in_NT & 1) * 0x4000 | (uint)(bVar9 & 1) * 0x800 |
                         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                         (uint)(bVar8 & 1) * 0x80 | (uint)(bVar7 & 1) * 0x40 |
                         (uint)(in_AF & 1) * 0x10 | (uint)(bVar6 & 1) * 4 | (uint)(bVar5 & 1));
      (**(code **)0x95a)();
      if ((param_1 & 1) != 0) {
        *(undefined2 *)0xf98 = in_stack_00000000;
      }
      return;
    }
  }
  uVar4 = *(undefined2 *)0xfa4;
  FUN_1570_0f9d();
  *(undefined2 *)0xfa4 = uVar4;
  return;
}



/* Function: FUN_1570_0b4e @ 1570:0b4e */

void __cdecl16near FUN_1570_0b4e(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  byte bVar3;
  uint uVar4;
  undefined2 in_CX;
  undefined2 unaff_DS;
  undefined4 uVar5;
  
  uVar5 = FUN_1570_0b94();
  while( true ) {
    uVar4 = (uint)uVar5;
    if ((uVar4 == 0) || ((byte)((byte)((ulong)uVar5 >> 8) & (byte)uVar5) != 0)) break;
    if ((byte)uVar5 == 0) {
      puVar1 = (undefined2 *)0xf98;
      uVar2 = *puVar1;
      *puVar1 = in_CX;
      *(undefined2 *)0xf9a = (int)((ulong)uVar5 >> 0x10);
      uVar4 = uVar4 >> 8;
      in_CX = uVar2;
    }
    bVar3 = (byte)uVar4;
    if (((bool)(bVar3 & 1)) || ((bool)((char)bVar3 >> 1 & 1))) {
      FUN_1570_0bab();
    }
    else if (((bool)((char)bVar3 >> 2 & 1)) || ((bool)((char)bVar3 >> 3 & 1))) {
      FUN_1570_0c1c();
    }
    uVar5 = FUN_1570_0f00();
  }
  return;
}



/* Function: FUN_1570_0b94 @ 1570:0b94 */

undefined4 __cdecl16near FUN_1570_0b94(void)

{
  undefined uVar1;
  undefined extraout_AH;
  undefined2 in_DX;
  
  FUN_1570_0f00();
  uVar1 = FUN_1570_0f00();
  return CONCAT22(in_DX,CONCAT11(uVar1,extraout_AH));
}



/* Function: FUN_1570_0bab @ 1570:0bab */

undefined4 __cdecl16near FUN_1570_0bab(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  int in_CX;
  int in_DX;
  int in_BX;
  int iVar3;
  
  iVar3 = in_BX - in_CX;
  iVar1 = FUN_1570_0be1();
  iVar2 = FUN_1570_0be1();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
  }
  return CONCAT22((iVar2 >> 1) + in_DX + iVar1 * iVar3,in_AX);
}



/* Function: FUN_1570_0be1 @ 1570:0be1 */

uint __cdecl16near FUN_1570_0be1(void)

{
  uint in_AX;
  uint uVar1;
  uint in_DX;
  uint uVar2;
  uint in_BX;
  uint uVar3;
  
  if ((in_AX | in_DX) != 0) {
    uVar3 = in_BX;
    if ((int)in_BX < 0) {
      uVar3 = -in_BX;
    }
    uVar1 = in_AX;
    uVar2 = in_DX;
    if ((int)in_DX < 0) {
      uVar1 = ~in_AX + 1;
      uVar2 = ~in_DX + (uint)(0xfffe < ~in_AX);
    }
    do {
      uVar3 = uVar3 >> 1;
    } while (uVar3 != 0);
    if (uVar2 != 0) {
      uVar1 = uVar2;
    }
    do {
      uVar1 = uVar1 >> 1;
    } while (uVar1 != 0);
    in_AX = (uint)(CONCAT22(in_DX,in_AX) / (long)(int)in_BX);
  }
  return in_AX;
}



/* Function: FUN_1570_0c1c @ 1570:0c1c */

void FUN_1570_0c1c(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1570_0c22();
  FUN_1570_0bab();
  uVar1 = *(undefined2 *)0xf98;
  *(undefined2 *)0xf98 = *(undefined2 *)0xf9a;
  *(undefined2 *)0xf9a = uVar1;
  return;
}



/* Function: FUN_1570_0c22 @ 1570:0c22 */

void __cdecl16near FUN_1570_0c22(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0xf98;
  *(undefined2 *)0xf98 = *(undefined2 *)0xf9a;
  *(undefined2 *)0xf9a = uVar1;
  return;
}



/* Function: FUN_1570_0c44 @ 1570:0c44 */

void __cdecl16near FUN_1570_0c44(void)

{
  int in_CX;
  int in_DX;
  undefined2 unaff_DS;
  
  if ((((*(int *)0xfe6 <= in_CX) && (in_CX <= *(int *)0xfe8)) && (*(int *)0xfea <= in_DX)) &&
     (in_DX <= *(int *)0xfec)) {
    return;
  }
  return;
}



/* Function: FUN_1570_0c60 @ 1570:0c60 */

undefined4 __cdecl16near FUN_1570_0c60(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  iVar2 = 0;
  iVar1 = *(int *)0x1002;
  if (*(char *)0xff5 == '\0') {
    iVar2 = *(int *)0xfe6;
    iVar1 = *(int *)0xfe8;
  }
  *(int *)0xf90 = iVar2 + ((iVar1 - iVar2) + 1U >> 1);
  iVar2 = 0;
  iVar1 = *(int *)0x1004;
  if (*(char *)0xff5 == '\0') {
    iVar2 = *(int *)0xfea;
    iVar1 = *(int *)0xfec;
  }
  *(int *)0xf92 = iVar2 + ((iVar1 - iVar2) + 1U >> 1);
  return CONCAT22(in_DX,in_AX);
}



/* Function: FUN_1570_0ce8 @ 1570:0ce8 */

void __cdecl16near FUN_1570_0ce8(void)

{
  undefined2 unaff_DS;
  
  FUN_1570_1036();
  FUN_1570_0c60();
  (**(code **)0x936)();
  return;
}



/* Function: FUN_1570_0e29 @ 1570:0e29 */

void __cdecl16near FUN_1570_0e29(void)

{
  return;
}



/* Function: FUN_1570_0e3e @ 1570:0e3e */

void FUN_1570_0e3e(void)

{
  undefined2 unaff_DS;
  
  (**(code **)0x942)();
  *(undefined2 *)0xf98 = *(undefined2 *)0xfe8;
  *(undefined2 *)0xf9a = *(undefined2 *)0xfec;
  FUN_1570_0e5c();
  FUN_1570_0ce8();
  return;
}



/* Function: FUN_1570_0e5c @ 1570:0e5c */

void __cdecl16near FUN_1570_0e5c(void)

{
  undefined2 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined2 in_CX;
  undefined2 uVar4;
  byte extraout_DL;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int unaff_BP;
  undefined2 unaff_DS;
  undefined in_CF;
  int iVar5;
  
  FUN_1570_0eb2();
  if (!(bool)in_CF) {
    FUN_1570_0f22();
    puVar1 = (undefined2 *)0xf98;
    uVar4 = *puVar1;
    *puVar1 = in_CX;
    *(undefined2 *)0xf9a = extraout_DX;
    FUN_1570_0f22();
    FUN_1570_0f60();
    if ((bool)in_CF) {
      *(undefined2 *)0xf9a = extraout_DX_00;
    }
    in_BX = in_BX + 1;
    iVar5 = in_BX;
    FUN_1570_0f55(in_BX);
    if ((bool)in_CF) {
      *(undefined2 *)0xf98 = uVar4;
    }
    *(byte *)0xfd4 = extraout_DL & 7;
    (**(code **)0x936)(in_BX + 1);
    do {
      (**(code **)0x95a)(iVar5);
      iVar5 = 0x659d;
      (**(code **)0x940)();
      pcVar2 = (char *)0xfd4;
      *pcVar2 = *pcVar2 + '\x01';
      pbVar3 = (byte *)0xfd4;
      *pbVar3 = *pbVar3 & 7;
      unaff_BP = unaff_BP + -1;
    } while (unaff_BP != 0);
  }
  *(undefined2 *)0xfa4 = 0xffff;
  return;
}



/* Function: FUN_1570_0eb2 @ 1570:0eb2 */

void __cdecl16near FUN_1570_0eb2(void)

{
  int iVar1;
  int iVar2;
  int in_CX;
  int in_DX;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0xf98;
  iVar2 = iVar1;
  if (iVar1 < in_CX) {
    iVar2 = in_CX;
    in_CX = iVar1;
  }
  *(int *)0x1006 = iVar2;
  *(int *)0x1008 = in_CX;
  iVar1 = *(int *)0xf9a;
  iVar2 = iVar1;
  if (iVar1 < in_DX) {
    iVar2 = in_DX;
    in_DX = iVar1;
  }
  *(int *)0x100a = iVar2;
  *(int *)0x100c = in_DX;
  FUN_1570_0eda();
  return;
}



/* Function: FUN_1570_0eda @ 1570:0eda */

void __cdecl16near FUN_1570_0eda(void)

{
  undefined2 unaff_DS;
  
  if ((((*(int *)0xfe6 <= *(int *)0x1006) && (*(int *)0x1008 <= *(int *)0xfe8)) &&
      (*(int *)0xfea <= *(int *)0x100a)) && (*(int *)0x100c <= *(int *)0xfec)) {
    return;
  }
  return;
}



/* Function: FUN_1570_0f00 @ 1570:0f00 */

uint __cdecl16near FUN_1570_0f00(void)

{
  int *piVar1;
  uint in_AX;
  uint uVar2;
  int in_CX;
  int in_DX;
  undefined2 unaff_DS;
  
  uVar2 = in_AX & 0xff00;
  piVar1 = (int *)0xfe6;
  if (*piVar1 != in_CX && in_CX <= *piVar1) {
    uVar2 = uVar2 + 1;
  }
  if (*(int *)0xfe8 < in_CX) {
    uVar2 = uVar2 | 2;
  }
  piVar1 = (int *)0xfea;
  if (*piVar1 != in_DX && in_DX <= *piVar1) {
    uVar2 = uVar2 | 4;
  }
  if (*(int *)0xfec < in_DX) {
    uVar2 = uVar2 | 8;
  }
  return uVar2;
}



/* Function: FUN_1570_0f22 @ 1570:0f22 */

void __cdecl16near FUN_1570_0f22(void)

{
  FUN_1570_0f00();
  return;
}



/* Function: FUN_1570_0f55 @ 1570:0f55 */

void __cdecl16near FUN_1570_0f55(void)

{
  return;
}



/* Function: FUN_1570_0f60 @ 1570:0f60 */

void __cdecl16near FUN_1570_0f60(void)

{
  return;
}



/* Function: FUN_1570_0f9d @ 1570:0f9d */

void __cdecl16near FUN_1570_0f9d(void)

{
  int in_AX;
  int in_CX;
  int in_DX;
  int iVar1;
  int iVar2;
  int iVar3;
  int in_BX;
  int unaff_BP;
  int iVar4;
  int unaff_ES;
  undefined2 unaff_DS;
  
  *(undefined *)0xf88 = 1;
  iVar3 = in_AX;
  iVar1 = in_DX;
  if (in_CX < in_AX) {
    iVar3 = in_CX;
    in_CX = in_AX;
    iVar1 = in_BX;
    in_BX = in_DX;
  }
  iVar2 = iVar1 - in_BX;
  iVar4 = iVar2;
  if (iVar1 < in_BX) {
    iVar4 = -iVar2;
  }
  (**(code **)0x936)(iVar2,in_CX - iVar3);
  (**(code **)0x94a)();
  iVar3 = *(int *)0x929;
  if (unaff_BP < 0) {
    iVar3 = -iVar3;
  }
  *(int *)0x102a = iVar3;
  if (iVar4 < unaff_ES) {
    *(int *)0x1026 = iVar4 << 2;
    *(int *)0x1028 = (iVar4 - unaff_ES) * 4;
    (**(code **)0x94e)();
  }
  else if (unaff_ES == 0) {
    (**(code **)0x952)();
  }
  else {
    *(int *)0x1026 = unaff_ES << 2;
    *(int *)0x1028 = (unaff_ES - iVar4) * 4;
    (**(code **)0x950)();
  }
  (**(code **)0x94c)();
  return;
}



/* Function: FUN_1570_1036 @ 1570:1036 */

void __cdecl16near FUN_1570_1036(undefined2 param_1,undefined2 param_2)

{
  undefined uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined *)0x101a;
  (**(code **)0x936)();
  *(int *)0x102c = *(int *)0x101c + *(int *)0x929;
  (**(code **)0x936)();
  *(undefined2 *)0x102e = *(undefined2 *)0x101c;
  (**(code **)0x936)();
  *(undefined2 *)0x1030 = *(undefined2 *)0x101c;
  *(undefined *)0x1034 = *(undefined *)0x101a;
  (**(code **)0x936)();
  *(undefined2 *)0x1032 = *(undefined2 *)0x101c;
  *(undefined *)0x1035 = *(undefined *)0x101a;
  *(undefined *)0x101a = uVar1;
  *(undefined2 *)0x101c = param_2;
  return;
}



/* Function: FUN_1570_3258 @ 1570:3258 */

void __cdecl16near FUN_1570_3258(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* Function: FUN_1570_3261 @ 1570:3261 */

void __cdecl16near FUN_1570_3261(void)

{
  byte bVar1;
  long lVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0x968;
  lVar2 = (ulong)bVar1 * (ulong)(uint)(*(int *)0x90e << 4);
  uVar3 = (undefined2)((ulong)lVar2 >> 0x10);
  *(undefined2 *)0x44e = (int)lVar2;
  *(byte *)0x462 = bVar1;
  return;
}



/* Function: FUN_1570_3266 @ 1570:3266 */

void __cdecl16near FUN_1570_3266(void)

{
  byte bVar1;
  long lVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0x967;
  lVar2 = (ulong)bVar1 * (ulong)(uint)(*(int *)0x90e << 4);
  uVar3 = (undefined2)((ulong)lVar2 >> 0x10);
  *(undefined2 *)0x44e = (int)lVar2;
  *(byte *)0x462 = bVar1;
  return;
}



