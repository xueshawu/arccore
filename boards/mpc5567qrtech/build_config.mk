
# ARCH defines
ARCH=mpc55xx
ARCH_FAM=ppc
ARCH_MCU=mpc5567

# CFG (y/n) macros
CFG=PPC BOOKE E200Z6 MPC55XX MPC5567 BRD_MPC5567QRTECH SPE

# What buildable modules does this board have, 
# default or private
MOD_AVAIL=KERNEL RAMLOG MCU WDG WDGM PORT DIO WDG WDGM T32_TERM WINIDEA_TERM PWM CAN CANIF COM ADC DMA SIMPLE_PRINTF PDUR IOHWAB

# Needed by us
MOD_USE=KERNEL MCU


