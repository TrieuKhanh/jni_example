#include <string>
#include <iostream>
#include <jni.h>

//jstring Java_the_package_MainActivity_getJniString( JNIEnv* env, jobject obj){

//    jstring jstr = (*env)->NewStringUTF(env, "This comes from jni.");
//    jclass clazz = (*env)->FindClass(env, "MainActivity");
//    jmethodID messageMe = (*env)->GetMethodID(env, clazz, "messageMe", "(Ljava/lang/String;)Ljava/lang/String;");
//    jobject result = (*env)->CallObjectMethod(env, obj, messageMe, jstr);

//    const char* str = (*env)->GetStringUTFChars(env,(jstring) result, NULL); // should be released but what a heck, it's a tutorial :)
//    printf("%s\n", str);

//    return (*env)->NewStringUTF(env, str);
//}

int main()
{
       using namespace std;
       JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
       JNIEnv *env;                      // Pointer to native interface
           //================== prepare loading of Java VM ============================
       JavaVMInitArgs vm_args;                        // Initialization arguments
       JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
       options[0].optionString = (char*)(std::string("-Djava.class.path=.").c_str());   // where to find java .class
       vm_args.version = JNI_VERSION_1_6;             // minimum Java version
       vm_args.nOptions = 0;                          // number of options
       vm_args.options = options;
       vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
           //=============== load and initialize Java VM and JNI interface =============
       jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
       delete options;    // we then no longer need the initialisation options. 
       if (rc != JNI_OK) {
              // TO DO: error processing... 
             cin.get();
             exit(EXIT_FAILURE);
       }
          //=============== Display JVM version =======================================
       cout << "JVM load succeeded: Version ";
       jint ver = env->GetVersion();
       cout << ((ver>>16)&0x0f) << "."<<(ver&0x0f) << endl;

       // TO DO: add the code that will use JVM <============  (see next steps)
       
       jclass cls2 = env->FindClass("MainActivity");  // try to find the class
        if(cls2 == nullptr) {
            cerr << "ERROR: class not found !";
        }
        else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "main", "([Ljava/lang/String;)V");  // find method
        if(mid == nullptr)
        {
                cerr << "ERROR: method void main() not found !" << endl;
        }
        else {
                //env->CallStaticVoidMethod(cls2, mid);                      // call method
                //cout << endl;
                
                        jobjectArray arr = env->NewObjectArray(5,      // constructs java array of 5
                                                                env->FindClass("java/lang/String"),    // Strings
                                                                env->NewStringUTF("str"));   // each initialized with value "str"
                        env->SetObjectArrayElement( arr, 1, env->NewStringUTF("MYOWNSTRING"));  // change an element
                        env->CallStaticVoidMethod(cls2, mid, arr);   // call the method with the arr as argument.
                        env->DeleteLocalRef(arr);     // release the object
                    
            }
        }

       ////////////////////////

       jvm->DestroyJavaVM();
       cin.get();
}
