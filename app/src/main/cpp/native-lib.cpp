#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_yk_itg_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring  JNICALL
Java_com_yk_itg_MainActivity_getStringFromJNI(JNIEnv *env, jobject) {
    std::string hello = "Hello from --- ";
    return env->NewStringUTF(hello.c_str());
}



extern "C" JNIEXPORT jstring JNICALL
Java_com_yk_itg_MainActivity_getUserName(JNIEnv *env, jobject obj1, jobject objUser) {
    jclass user = env->FindClass("com/yk/itg/User");
    __android_log_print(ANDROID_LOG_ERROR,"getUserName","获得方法ID");
   jmethodID  jmethodId = env->GetMethodID(user,"getName","()Ljava/lang/String;");
   jstring  result = (jstring) env->CallObjectMethod(objUser, jmethodId);
   const char* ch = (char *)env->GetStringUTFChars(result, NULL);
   jstring jstring = env->NewStringUTF(ch);
   jmethodID mid = env->GetMethodID(user,"setName","(Ljava/lang/String;)V");
   env->CallVoidMethod(objUser,mid,jstring);
   return env->NewStringUTF("ddd");
}




