#include <moai-core/host.h>
#include <jni.h>
#include "JniDefs.h"

JNIEXPORT jlong JNICALL Java_org_keplerproject_luajava_LuaStateFactory_getAkuState(JNIEnv *, jclass)
{
	return (jlong)AKUGetLuaState();
}

extern "C" int forceLinkLuaJava();

void MOAIJniAppInitialize()
{
	forceLinkLuaJava();
}

void MOAIJniContextInitialize()
{
}

void MOAIJniAppFinalize()
{
}
