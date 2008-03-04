TOP=../..

include $(TOP)/configure/CONFIG

# -------------------------------
# Build an Diamond Support Module
# -------------------------------

LIBRARY_IOC += OXCS700

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxx.h

# xxxRecord.dbd will be installed into <top>/dbd
DBD += OXCS700vdct.dbd
DBD += OXCS700Support.dbd

OXCS700vdct_DBD += base.dbd
OXCS700vdct_DBD += stream.dbd
OXCS700vdct_DBD += asyn.dbd
OXCS700vdct_DBD += genSubRecord.dbd
OXCS700vdct_DBD += alarmlookup.dbd

OXCS700Support_DBD += alarmlookup.dbd

# The following are compiled and added to the support library
OXCS700_SRCS += alarmlookup.c

# We need to link against the EPICS Base libraries
#xxx_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
