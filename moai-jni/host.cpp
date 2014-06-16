#include <moai-core/host.h>

#ifdef BUILD_ANDROID
#include <jni.h>
#include "JniDefs.h"

JNIEXPORT jlong JNICALL Java_org_keplerproject_luajava_LuaStateFactory_getAkuState(JNIEnv *, jclass)
{
	return (jlong)AKUGetLuaState();
}

extern "C" int forceLinkLuaJava();
#endif

void MOAIJniAppInitialize()
{
#ifdef BUILD_ANDROID
	forceLinkLuaJava();
#endif
}

void MOAIJniContextInitialize()
{
}

void MOAIJniAppFinalize()
{
}
