#ifndef MACROHELPER_H
#define MACROHELPER_H

#include <QMutex>
#include <QScopedPointer>

//begin of SINGLETON
//quote from http://qtdebug.com/qtbook-singleton-3-auto-pointer-macro/
#define SINGLETON(Class)                                \
    public:                                             \
        static Class& instance() {                      \
            if (instancePtr.isNull()) {                 \
                mutex.lock();                           \
                if (instancePtr.isNull()) {             \
                    instancePtr.reset(new Class());     \
                }                                       \
                mutex.unlock();                         \
            }                                           \
                                                        \
            return *instancePtr.data();                 \
        }                                               \
                                                        \
    private:                                            \
        Class();                                        \
        ~Class();                                       \
        Class(const Class &other);                      \
        Class& operator=(const Class &other);           \
        static QMutex mutex;                            \
        static QScopedPointer<Class> instancePtr;       \
        friend class QScopedPointer<Class>;             \
        friend struct QScopedPointerDeleter<Class>;
//end of SINGLETON


//begin of SINGLETON_STATIC_INITIALIZE
#define SINGLETON_STATIC_INITIALIZE(Class)              \
    QMutex Class::mutex;                                \
    QScopedPointer<Class> Class::instancePtr;
//end of SINGLETON_STATIC_INITIALIZE


//begin of SINGLETON_IDLER
#define SINGLETON_IDLER(Class)                      \
    public:                                         \
        static Class &instance() {                  \
            static Class _instance;                 \
            return _instance;                       \
        }                                           \
    private:                                        \
        Class();                                    \
        ~Class();                                   \
        Class(Class &) = delete;                    \
        Class &operator=(Class &) = delete;
//end of SINGLETON_IDLER


//begin of MAIN_APP_INSTANCE_RUN
#define MAIN_APP_INSTANCE_RUN()                     \
    int main(int argc, char *argv[]){               \
        return AppInstance::run(argc,argv);         \
    }
//end of MAIN_APP_INSTANCE_RUN

#endif // MACROHELPER_H
