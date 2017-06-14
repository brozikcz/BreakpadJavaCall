#include <jni.h>
#include <android/log.h>
#include <stdio.h>

#include "google_breakpad/src/client/linux/handler/exception_handler.h"
#include "google_breakpad/src/client/linux/handler/minidump_descriptor.h"

#include "google_breakpad.hpp"

MinidumpCallback callback_;

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded) {

    __android_log_print(ANDROID_LOG_ERROR, "GoogleBreakpad", "Dump path: %s, %s", descriptor.path(), succeeded ? "true" : "false");

    callback_(stderr, "Dump path: %s, %s", descriptor.path());

    return succeeded;
}

void crash2() {
     char a[1];
     a[2] = 2;
}

void crash() {
    crash2();
}

void initCrashDumpPath(const char *path, MinidumpCallback callback) {

    callback_ = callback;

    callback_(stdout, "Init google breakpad to: %s", path);

    google_breakpad::MinidumpDescriptor descriptor(path);
    new google_breakpad::ExceptionHandler(descriptor, NULL, DumpCallback, NULL, true, -1);
}
