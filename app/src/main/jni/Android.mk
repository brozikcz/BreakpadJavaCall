LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_DEFAULT_CPP_EXTENSION := cpp

LOCAL_MODULE := google_breakpad
LOCAL_SRC_FILES := google_breakpad.cpp
LOCAL_STATIC_LIBRARIES += breakpad_client
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
APP_CXXFLAGS := -std=c++11 -D__STDC_LIMIT_MACROS

include $(BUILD_SHARED_LIBRARY)

# If NDK_MODULE_PATH is defined, import the module, otherwise do a direct
# includes. This allows us to build in all scenarios easily.
ifneq ($(NDK_MODULE_PATH),)
  $(call import-module,google_breakpad)
else
  include $(LOCAL_PATH)/google_breakpad/Android.mk
endif
