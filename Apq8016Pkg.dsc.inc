##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

[Defines]
  #
  # Timer
  #
  USE_PHYSICAL_TIMER                         = 0

  #
  # KEP
  #
  HAS_ACTLR_EL1_UNIMPLEMENTED_ERRATA         = 0
  HAS_AMCNTENSET0_EL0_UNIMPLEMENTED_ERRATA   = 0
  HAS_GIC_V3_WITHOUT_IRM_FLAG_SUPPORT_ERRATA = 0
  HAS_PSCI_MEMPROTECT_FAILING_ERRATA         = 0

!include QcomPkg/QcomPkg.dsc.inc

[BuildOptions]
  *_*_AARCH64_CC_FLAGS = -march=armv8-a+crypto

[PcdsFixedAtBuild]
  #
  # CPU
  #
  gArmPlatformTokenSpaceGuid.PcdCoreCount|4
  gArmPlatformTokenSpaceGuid.PcdClusterCount|1

  #
  # GIC
  #
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x0B000000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0x0B002000

  #
  # Timer
  #
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|10
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|8
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|7

  #
  # SMBIOS
  #
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Snapdragon (TM) 410"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorPartNumber|"APQ8016"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMaxCpuFreq|1200
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1InstCacheSize|0x10
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1DataCacheSize|0x10
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel2CacheSize|0x100
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemorySpeed|533
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemoryType|30

[LibraryClasses]
  #
  # SEC Libraries
  #
  PlatformSecLib|Apq8016Pkg/Library/PlatformSecLib/PlatformSecLib.inf
