#ifndef INCLUDE_GOOGLE_BREAKPAD_H_
#define INCLUDE_GOOGLE_BREAKPAD_H_

typedef void (*MinidumpCallback)(void *type, const char *fmt, ...);

void initCrashDumpPath(const char *path, MinidumpCallback callback);
void crash();

#endif //INCLUDE_GOOGLE_BREAKPAD_H_